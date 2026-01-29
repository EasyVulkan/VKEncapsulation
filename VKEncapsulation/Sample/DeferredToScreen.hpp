#define VK_ENCAPSULATION_RESULT_THROW
#include "WindowSystem/Glfw.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "Plus/AppBasePlus.h"
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include M_VulkanSdkHeader(glm/glm.hpp)
#include M_VulkanSdkHeader(glm/gtc/matrix_transform.hpp)
#include M_VulkanSdkHeader(glm/gtc/quaternion.hpp)
#include <iostream>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 albedoSpecular;
};

// Different with OpenGL, in Vulkan NDC system, y-axis is downward
glm::mat4 FlipVertical(const glm::mat4& projection) {
	glm::mat4 _projection = projection;
	for (uint32_t i = 0; i < 4; i++)
		_projection[i][1] *= -1;
	return _projection;
}

VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN
auto& swapchainImageExtent = VkeApp::Base().SwapchainCreateInfo().imageExtent;

struct DeferredToScreen {
	static constexpr Format format_normalZ = VK_FORMAT_R16G16B16A16_SFLOAT;
	static constexpr Format format_albedoSpecular = VK_FORMAT_R8G8B8A8_UNORM;
	static constexpr Format format_depth = VK_FORMAT_D24_UNORM_S8_UINT;
	static constexpr ImageLayout inputAttachmentLayout = VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ;

	static inline oop::DescriptorSetLayout descriptorSetLayout_gBuffer;
	static inline oop::PipelineLayout pipelineLayout_gBuffer;
	static inline oop::Pipeline pipeline_gBuffer;
	static inline oop::DescriptorSetLayout descriptorSetLayout_composition;
	static inline oop::PipelineLayout pipelineLayout_composition;
	static inline oop::Pipeline pipeline_composition;
	static inline ext::ColorAttachment attachment_normalZ;
	static inline ext::ColorAttachment attachment_albedoSpecular;
	static inline ext::DepthStencilAttachment attachment_depth;

	static void Initialize() {
		// Create layouts
		/* G-buffer */
		auto descriptorSetLayoutBinding_gBuffer = DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT };
		descriptorSetLayout_gBuffer.Create(DescriptorSetLayoutCreateInfo{}.
			Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
			Bindings(descriptorSetLayoutBinding_gBuffer));
		pipelineLayout_gBuffer.Create(PipelineLayoutCreateInfo{}.
			SetLayouts(descriptorSetLayout_gBuffer));
		/* Composition */
		auto descriptorSetLayoutBindings_composition = {
			DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_FRAGMENT_BIT },
			DescriptorSetLayoutBinding{ 1, VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 2, VK_SHADER_STAGE_FRAGMENT_BIT }
		};
		descriptorSetLayout_composition.Create(DescriptorSetLayoutCreateInfo{}.
			Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
			Bindings(descriptorSetLayoutBindings_composition));
		pipelineLayout_composition.Create(PipelineLayoutCreateInfo{}.
			SetLayouts(descriptorSetLayout_composition));

		// Create pipelines
		static constexpr int32_t shininess = 64;
		static auto mapEntry = SpecializationMapEntry{ 1, 0, sizeof shininess };
		static auto specializationInfo = SpecializationInfo{}.MapEntries(mapEntry).Data(shininess);

		static oop::ShaderModule vert_gBuffer("shader/DeferredToScreen/GBuffer.vert.spv");
		static oop::ShaderModule frag_gBuffer("shader/DeferredToScreen/GBuffer.frag.spv");
		static auto shaderStageCreateInfos_gBuffer = {
			vert_gBuffer.StageCreateInfo(VK_SHADER_STAGE_VERTEX_BIT),
			frag_gBuffer.StageCreateInfo(VK_SHADER_STAGE_FRAGMENT_BIT)
		};
		static oop::ShaderModule vert_composition("shader/DeferredToScreen/Composition.vert.spv");
		static oop::ShaderModule frag_composition("shader/DeferredToScreen/Composition.frag.spv");
		static auto shaderStageCreateInfos_composition = {
			vert_composition.StageCreateInfo(VK_SHADER_STAGE_VERTEX_BIT),
			frag_composition.StageCreateInfo(VK_SHADER_STAGE_FRAGMENT_BIT).SpecializationInfo(specializationInfo)
		};
		static Format swapchainImageFormat;

		auto CreatePipelines = [] {
			if (swapchainImageFormat == VkeApp::Base().SwapchainCreateInfo().imageFormat)
				return;
			auto colorAttachmentFormats_gBuffer = {
				VkeApp::Base().SwapchainCreateInfo().imageFormat,
				format_normalZ,
				format_albedoSpecular
			};
			auto colorAttachmentLocations_gBuffer = { VK_ATTACHMENT_UNUSED, 0u, 1u };
			auto colorAttachmentLocations_composition = { 0u, VK_ATTACHMENT_UNUSED, VK_ATTACHMENT_UNUSED };
			auto pipelineRenderingCreateInfo = PipelineRenderingCreateInfoKHR{};
			auto renderingAttachmentLocationInfo = RenderingAttachmentLocationInfo{};
			auto renderingInputAttachmentIndexInfo = RenderingInputAttachmentIndexInfo{};

			/* G-buffer */
			ext::GraphicsPipelineCreateInfoPack pipelineCiPack;
			pipelineCiPack.vertexInputBindings.emplace_back(0, sizeof(Vertex), VK_VERTEX_INPUT_RATE_VERTEX);
			pipelineCiPack.vertexInputBindings.emplace_back(1, sizeof(glm::vec3), VK_VERTEX_INPUT_RATE_INSTANCE);
			pipelineCiPack.vertexInputAttributes.emplace_back(0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, position));
			pipelineCiPack.vertexInputAttributes.emplace_back(1, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, normal));
			pipelineCiPack.vertexInputAttributes.emplace_back(2, 0, VK_FORMAT_R32G32B32A32_SFLOAT, offsetof(Vertex, albedoSpecular));
			pipelineCiPack.vertexInputAttributes.emplace_back(3, 1, VK_FORMAT_R32G32B32_SFLOAT, 0);
			pipelineCiPack.inputAssemblyStateCi.Topology(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
			pipelineCiPack.rasterizationStateCi.CullMode(VK_CULL_MODE_BACK_BIT);
			pipelineCiPack.rasterizationStateCi.FrontFace(VK_FRONT_FACE_COUNTER_CLOCKWISE);
			pipelineCiPack.depthStencilStateCi.DepthWriteEnable(VK_TRUE);
			pipelineCiPack.depthStencilStateCi.DepthCompareOp(VK_COMPARE_OP_LESS);
			pipelineCiPack.colorBlendAttachmentStates.resize(3); // Default-initialized
			pipelineCiPack.dynamicStates.push_back(VK_DYNAMIC_STATE_VIEWPORT);
			pipelineCiPack.dynamicStates.push_back(VK_DYNAMIC_STATE_SCISSOR);
			pipelineCiPack.UpdateAllArrays();
			pipelineCiPack.createInfo.
				Layout(pipelineLayout_gBuffer).
				Stages(shaderStageCreateInfos_gBuffer).
				AddNextStructure(pipelineRenderingCreateInfo).
				AddNextStructure(renderingAttachmentLocationInfo);
			pipelineRenderingCreateInfo.
				ColorAttachmentFormats(colorAttachmentFormats_gBuffer).
				DepthAttachmentFormat(format_depth);
			renderingAttachmentLocationInfo.ColorAttachmentLocations(colorAttachmentLocations_gBuffer);
			pipeline_gBuffer = pipelineCiPack;
			/* Composition */
			pipelineCiPack.vertexInputStateCi.VertexBindingDescriptions({});
			pipelineCiPack.vertexInputStateCi.VertexAttributeDescriptions({});
			pipelineCiPack.inputAssemblyStateCi.Topology(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP);
			pipelineCiPack.depthStencilStateCi.DepthTestEnable(VK_FALSE);
			pipelineCiPack.colorBlendStateCi.AttachmentCount(3);
			pipelineCiPack.createInfo.
				Layout(pipelineLayout_composition).
				Stages(shaderStageCreateInfos_composition).
				AddNextStructure(renderingInputAttachmentIndexInfo);
			renderingAttachmentLocationInfo.ColorAttachmentLocations(colorAttachmentLocations_composition);
			renderingInputAttachmentIndexInfo.ColorAttachmentInputIndices(colorAttachmentLocations_gBuffer);
			pipeline_composition = pipelineCiPack;
		};
		auto DestroyPipelines = [] {
			if (swapchainImageFormat == VkeApp::Base().SwapchainCreateInfo().imageFormat)
				return;
			pipeline_gBuffer.~Object();
			pipeline_composition.~Object();
		};
		VkeApp::Base().AddCallback_CreateSwapchain(CreatePipelines);
		VkeApp::Base().AddCallback_DestroySwapchain(DestroyPipelines);
		CreatePipelines();

		// Create attachments
		static Extent2D attachmentExtent;
		auto CreateAttachments = [] {
			if (attachmentExtent.width == swapchainImageExtent.width &&
				attachmentExtent.height == swapchainImageExtent.height)
				return;
			attachment_normalZ.Create(format_normalZ, swapchainImageExtent, 1, VK_SAMPLE_COUNT_1_BIT, VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT);
			attachment_albedoSpecular.Create(format_albedoSpecular, swapchainImageExtent, 1, VK_SAMPLE_COUNT_1_BIT, VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT);
			attachment_depth.Create(format_depth, swapchainImageExtent, 1, VK_SAMPLE_COUNT_1_BIT, VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT);
		};
		auto DestroyAttachments = [] {
			if (attachmentExtent.width == swapchainImageExtent.width &&
				attachmentExtent.height == swapchainImageExtent.height)
				return;
			attachment_normalZ.~ColorAttachment();
			attachment_albedoSpecular.~ColorAttachment();
			attachment_depth.~DepthStencilAttachment();
		};
		VkeApp::Base().AddCallback_CreateSwapchain(CreateAttachments);
		VkeApp::Base().AddCallback_DestroySwapchain(DestroyAttachments);
		CreateAttachments();
	}
	static void CmdBeginRendering() {
		CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {},
			ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				NewLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
				Image(VkeApp::Base().SwapchainImage()).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }));
		CmdPipelineBarrier(VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {}, {
			ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				NewLayout(inputAttachmentLayout).
				Image(attachment_normalZ).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }),
			ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				NewLayout(inputAttachmentLayout).
				Image(attachment_albedoSpecular).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }) });
		CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {},
			ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT).
				NewLayout(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL).
				Image(attachment_depth).
				SubresourceRange({ VK_IMAGE_ASPECT_DEPTH_BIT, 0, 1, 0, 1 }));

		auto renderingAttachmentInfos = {
			RenderingAttachmentInfo{}.
				ImageView(VkeApp::Base().SwapchainImageView()).
				ImageLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
				ClearValue({}),
			RenderingAttachmentInfo{}.
				ImageView(attachment_normalZ).
				ImageLayout(inputAttachmentLayout).
				ClearValue({}),
			RenderingAttachmentInfo{}.
				ImageView(attachment_albedoSpecular).
				ImageLayout(inputAttachmentLayout).
				ClearValue({})
		};
		auto depthAttachmentInfo = RenderingAttachmentInfo{}.
			ImageView(attachment_depth).
			ImageLayout(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL).
			ClearValue({ 1.f, 0 });
		vke::CmdBeginRendering(RenderingInfo{}.
			RenderArea({ {}, swapchainImageExtent }).
			ColorAttachments(renderingAttachmentInfos).
			DepthAttachment(depthAttachmentInfo));

		auto colorAttachmentLocations = { VK_ATTACHMENT_UNUSED, 0u, 1u };
		CmdSetRenderingAttachmentLocations(RenderingAttachmentLocationInfo{}.ColorAttachmentLocations(colorAttachmentLocations));
	}
	static void CmdSetRenderingInputAttachmentIndices() {
		CmdPipelineBarrier(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {}, {
			ImageMemoryBarrier{}.
				SrcAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				DstAccessMask(VK_ACCESS_SHADER_READ_BIT).
				OldLayout(inputAttachmentLayout).
				NewLayout(inputAttachmentLayout).
				Image(attachment_normalZ).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }),
			ImageMemoryBarrier{}.
				SrcAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				DstAccessMask(VK_ACCESS_SHADER_READ_BIT).
				OldLayout(inputAttachmentLayout).
				NewLayout(inputAttachmentLayout).
				Image(attachment_albedoSpecular).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }) });

		auto colorAttachmentInputIndices = { VK_ATTACHMENT_UNUSED, 0u, 1u };
		vke::CmdSetRenderingInputAttachmentIndices(RenderingInputAttachmentIndexInfo{}.ColorAttachmentInputIndices(colorAttachmentInputIndices));

		auto colorAttachmentLocations = { 0u, VK_ATTACHMENT_UNUSED, VK_ATTACHMENT_UNUSED };
		CmdSetRenderingAttachmentLocations(RenderingAttachmentLocationInfo{}.ColorAttachmentLocations(colorAttachmentLocations));
	}
	static void CmdEndRendering() {
		vke::CmdEndRendering();

		CmdPipelineBarrier(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {},
			ImageMemoryBarrier{}.
				SrcAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				OldLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
				NewLayout(VK_IMAGE_LAYOUT_PRESENT_SRC_KHR).
				Image(VkeApp::Base().SwapchainImage()).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }));
	}
};
VK_ENCAPSULATION_NAMESPACE_END

int main() {
	using namespace vke;
	using namespace vke::raii;
	using namespace vke::ws;
	using namespace vke::ext;

	PreInitialization_SetApiVersionRequirement();
	PreInitialization_EnableSrgb();
	InitializeWindow({ 1280, 720 });

	DeferredToScreen::Initialize();

	oop::Fence fence({});
	oop::Semaphore semaphore_imageIsAvailable({});
	oop::Semaphore semaphore_renderingIsOver({});

	oop::CommandBuffer commandBuffer;
	oop::CommandPool commandPool({ FLAGS(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT) });
	commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBuffer);

	Vertex vertices[] = {
		//x+
		{ {  1,  1, -1 }, {  1,  0,  0 }, { 1, 1, 1, 1 } },
		{ {  1, -1, -1 }, {  1,  0,  0 }, { 1, 1, 1, 1 } },
		{ {  1,  1,  1 }, {  1,  0,  0 }, { 1, 1, 1, 1 } },
		{ {  1, -1,  1 }, {  1,  0,  0 }, { 1, 1, 1, 1 } },
		//x-
		{ { -1,  1,  1 }, { -1,  0,  0 }, { 1, 1, 1, 1 } },
		{ { -1, -1,  1 }, { -1,  0,  0 }, { 1, 1, 1, 1 } },
		{ { -1,  1, -1 }, { -1,  0,  0 }, { 1, 1, 1, 1 } },
		{ { -1, -1, -1 }, { -1,  0,  0 }, { 1, 1, 1, 1 } },
		//y+
		{ {  1,  1, -1 }, {  0,  1,  0 }, { 1, 1, 1, 1 } },
		{ {  1,  1,  1 }, {  0,  1,  0 }, { 1, 1, 1, 1 } },
		{ { -1,  1, -1 }, {  0,  1,  0 }, { 1, 1, 1, 1 } },
		{ { -1,  1,  1 }, {  0,  1,  0 }, { 1, 1, 1, 1 } },
		//y-
		{ {  1, -1, -1 }, {  0, -1,  0 }, { 1, 1, 1, 1 } },
		{ { -1, -1, -1 }, {  0, -1,  0 }, { 1, 1, 1, 1 } },
		{ {  1, -1,  1 }, {  0, -1,  0 }, { 1, 1, 1, 1 } },
		{ { -1, -1,  1 }, {  0, -1,  0 }, { 1, 1, 1, 1 } },
		//z+
		{ {  1,  1,  1 }, {  0,  0,  1 }, { 1, 1, 1, 1 } },
		{ {  1, -1,  1 }, {  0,  0,  1 }, { 1, 1, 1, 1 } },
		{ { -1,  1,  1 }, {  0,  0,  1 }, { 1, 1, 1, 1 } },
		{ { -1, -1,  1 }, {  0,  0,  1 }, { 1, 1, 1, 1 } },
		//z-
		{ { -1,  1, -1 }, {  0,  0, -1 }, { 1, 1, 1, 1 } },
		{ { -1, -1, -1 }, {  0,  0, -1 }, { 1, 1, 1, 1 } },
		{ {  1,  1, -1 }, {  0,  0, -1 }, { 1, 1, 1, 1 } },
		{ {  1, -1, -1 }, {  0,  0, -1 }, { 1, 1, 1, 1 } }
	};
	ext::DeviceLocalBuffer vertexBuffer_perVertex(sizeof vertices, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
	vertexBuffer_perVertex.TransferData(vertices);

	float offsets[][3] = {
        { -4, -4,  6 }, {  4, -4,  6 },
        { -4,  4, 10 }, {  4,  4, 10 },
        { -4, -4, 14 }, {  4, -4, 14 },
        { -4,  4, 18 }, {  4,  4, 18 },
        { -4, -4, 22 }, {  4, -4, 22 },
        { -4,  4, 26 }, {  4,  4, 26 }
	};
	ext::DeviceLocalBuffer vertexBuffer_perInstance(sizeof offsets, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
	vertexBuffer_perInstance.TransferData(offsets);

	uint16_t indices[36] = { 0, 1, 2, 2, 1, 3 };
	for (size_t i = 1; i < 6; i++)
		for (size_t j = 0; j < 6; j++)
			indices[i * 6 + j] = indices[j] + i * 4;
	ext::DeviceLocalBuffer indexBuffer(sizeof indices, VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
	indexBuffer.TransferData(indices);

	struct {
		glm::mat4 proj;
		glm::mat4 view;
		int32_t lightCount;
		struct {
			alignas(16) glm::vec3 position;
			alignas(16) glm::vec3 color;
			float strength;
		} lights[8];
	} descriptorConstants;
	descriptorConstants.proj = FlipVertical(glm::infinitePerspectiveLH_ZO(glm::radians(60.f), swapchainImageExtent.width * 1.f / swapchainImageExtent.height, 0.1f));
	descriptorConstants.view = glm::lookAtLH(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(-1, 0, 0));
	descriptorConstants.lightCount = 3;
	descriptorConstants.lights[0] = { { 0.f,  4.f,  6.f }, { 1.f, 0.f, 0.f }, 100.f };
	descriptorConstants.lights[1] = { { 0.f,  0.f, 16.f }, { 0.f, 1.f, 0.f }, 100.f };
	descriptorConstants.lights[2] = { { 0.f, -4.f,  6.f }, { 0.f, 0.f, 1.f }, 100.f };
	ext::DeviceLocalBuffer uniformBuffer(sizeof descriptorConstants, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
	uniformBuffer.TransferData(descriptorConstants);

	while (!WindowShouldClose()) {
		TitleFps();

		VkeApp::Base().SwapImage(semaphore_imageIsAvailable);
		commandBuffer.Begin(FLAGS(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT));
		DeferredToScreen::CmdBeginRendering();

		CmdSetViewport(0, Viewport{ 0.f, 0.f, float(swapchainImageExtent.width), float(swapchainImageExtent.height), 0.f, 1.f });
		CmdSetScissor(0, Rect2D{ {}, swapchainImageExtent });

		// G-buffer
		auto bufferInfo = DescriptorBufferInfo{}.Buffer(uniformBuffer).Range(sizeof(glm::mat4) * 2);
		CmdPushDescriptorSet(VK_PIPELINE_BIND_POINT_GRAPHICS, DeferredToScreen::pipelineLayout_gBuffer, 0, WriteDescriptorSet{}.
			DescriptorType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER).
			BufferInfo(bufferInfo));
		CmdBindPipeline(VK_PIPELINE_BIND_POINT_GRAPHICS, DeferredToScreen::pipeline_gBuffer);
		CmdBindVertexBuffers(0, { vertexBuffer_perVertex, vertexBuffer_perInstance }, { 0, 0 });
		CmdBindIndexBuffer(indexBuffer, 0, VK_INDEX_TYPE_UINT16);
		CmdDrawIndexed(36, 12, 0, 0, 0);

		// Set input attachment, transition layout
		DeferredToScreen::CmdSetRenderingInputAttachmentIndices();

		// Composition
		auto imageInfos = {
			DescriptorImageInfo{ VK_NULL_HANDLE, DeferredToScreen::attachment_normalZ, DeferredToScreen::inputAttachmentLayout },
			DescriptorImageInfo{ VK_NULL_HANDLE, DeferredToScreen::attachment_albedoSpecular, DeferredToScreen::inputAttachmentLayout } };
		CmdPushDescriptorSet(VK_PIPELINE_BIND_POINT_GRAPHICS, DeferredToScreen::pipelineLayout_composition, 0, {
			WriteDescriptorSet{}.
				DescriptorType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER).
				BufferInfo(bufferInfo.Range(VK_WHOLE_SIZE)),
			WriteDescriptorSet{}.
				DstBinding(1).
				DescriptorType(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT).
				ImageInfo(imageInfos) });
		CmdBindPipeline(VK_PIPELINE_BIND_POINT_GRAPHICS, DeferredToScreen::pipeline_composition);
		CmdDraw(4, 1, 0, 0);

		DeferredToScreen::CmdEndRendering();
		commandBuffer.End();
		VkeApp::Base().SubmitCommandBuffers(semaphore_imageIsAvailable, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, commandBuffer, semaphore_renderingIsOver, fence);
		VkeApp::Base().PresentImage(semaphore_renderingIsOver);

		PollEvents();
		fence.WaitAndReset();
	}
	TerminateWindow();
	return 0;
}