#define VK_ENCAPSULATION_ALLOW_PASSING_TEMPORARY_ADDRESS_TO_SETTER
#define VK_ENCAPSULATION_RESULT_THROW
#include "WindowSystem/Glfw.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "Plus/AppBasePlus.h"
#include "Timer.h"
#include <iostream>
#include <chrono>
#include <thread>

VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN
auto& swapchainImageExtent = VkeApp::Base().SwapchainCreateInfo().imageExtent;

void BootScreen(const char* imagePath, VK_ENCAPSULATION_NAMESPACE::Format imageFormat) {
	using namespace VK_ENCAPSULATION_NAMESPACE;
	using namespace VK_ENCAPSULATION_NAMESPACE::ext;

	Extent2D imageExtent;
	std::unique_ptr pImageData = Texture2D::LoadFile(imagePath, imageExtent, FormatInfo(imageFormat));
	if (!pImageData)
		return;
	StagingBuffer::Buffer_MainThread().BufferData({ FormatInfo(imageFormat).sizePerPixel * imageExtent.width * imageExtent.height, pImageData.get() });

	oop::Semaphore semaphore_imageIsAvailable({});
	oop::Fence fence({});

	VkeApp::Base().SwapImage(semaphore_imageIsAvailable);
	VkeApp::Plus().CommandBuffer().Begin(FLAGS(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT));
	Extent2D swapchainImageExtent = VkeApp::Base().SwapchainCreateInfo().imageExtent;
	bool blit =
		imageExtent.width != swapchainImageExtent.width ||
		imageExtent.height != swapchainImageExtent.height ||
		imageFormat != VkeApp::Base().SwapchainCreateInfo().imageFormat;
	oop::ImageMemory imageMemory;
	if (blit) {
		Image image = StagingBuffer::Buffer_MainThread().AliasedImage2D(imageFormat, imageExtent);
		if (image)
			CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_TRANSFER_READ_BIT).
				OldLayout(VK_IMAGE_LAYOUT_PREINITIALIZED).
				NewLayout(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL).
				Image(image).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }));
		else {
			imageMemory.Create(ImageCreateInfo{}.
				ImageType(VK_IMAGE_TYPE_2D).
				Format(imageFormat).
				Extent({ imageExtent.width, imageExtent.height, 1 }).
				Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT),
				VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
			ImageOperation::CmdCopyBufferToImage(StagingBuffer::Buffer_MainThread(), imageMemory, BufferImageCopy{}.
				ImageSubresource({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 }).
				ImageExtent({ imageExtent.width, imageExtent.height, 1 }),
				{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
				{ VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL });
			image = imageMemory;
		}
		ImageOperation::CmdBlitImage(image, VkeApp::Base().SwapchainImage(), {
			{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 },
			{ {}, { int32_t(imageExtent.width), int32_t(imageExtent.height), 1 } },
			{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 },
			{ {}, { int32_t(swapchainImageExtent.width), int32_t(swapchainImageExtent.height), 1 } } },
			{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
			{ VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR }, VK_FILTER_LINEAR);
	}
	else
		ImageOperation::CmdCopyBufferToImage(StagingBuffer::Buffer_MainThread(), VkeApp::Base().SwapchainImage(), BufferImageCopy{}.
			ImageSubresource({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 }).
			ImageExtent({ imageExtent.width, imageExtent.height, 1 }),
			{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
			{ VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR });
	VkeApp::Plus().CommandBuffer().End();
	VkeApp::Base().SubmitCommandBuffers(semaphore_imageIsAvailable, VK_PIPELINE_STAGE_TRANSFER_BIT, VkeApp::Plus().CommandBuffer(), {}, fence);
	fence.WaitAndReset();
	VkeApp::Base().PresentImage();
}

struct ToScreen {
	static inline oop::PipelineLayout pipelineLayout;
	static inline oop::Pipeline pipeline;
	static void Initialize() {
		// Create layout
		pipelineLayout.Create();

		// Create pipeline
		static oop::ShaderModule vert("shader/Triangle/FirstTriangle.vert.spv");
		static oop::ShaderModule frag("shader/Triangle/FirstTriangle.frag.spv");
		static auto shaderStageCreateInfos = {
			vert.StageCreateInfo(VK_SHADER_STAGE_VERTEX_BIT),
			frag.StageCreateInfo(VK_SHADER_STAGE_FRAGMENT_BIT)
		};
		static Format swapchainImageFormat;

		auto CreatePipeline = [] {
			if (swapchainImageFormat == VkeApp::Base().SwapchainCreateInfo().imageFormat)
				return;
			auto pipelineRenderingCreateInfo = PipelineRenderingCreateInfoKHR{};
			ext::GraphicsPipelineCreateInfoPack pipelineCiPack;
			pipelineCiPack.inputAssemblyStateCi.Topology(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
			pipelineCiPack.colorBlendAttachmentStates.resize(1); // Default-initialized
			pipelineCiPack.dynamicStates.push_back(VK_DYNAMIC_STATE_VIEWPORT);
			pipelineCiPack.dynamicStates.push_back(VK_DYNAMIC_STATE_SCISSOR);
			pipelineCiPack.UpdateAllArrays();
			pipelineCiPack.createInfo.
				Layout(pipelineLayout).
				Stages(shaderStageCreateInfos).
				AddNextStructure(pipelineRenderingCreateInfo.
					ColorAttachmentFormats(VkeApp::Base().SwapchainCreateInfo().imageFormat));
			pipeline = pipelineCiPack;
		};
		auto DestroyPipeline = [] {
			if (swapchainImageFormat == VkeApp::Base().SwapchainCreateInfo().imageFormat)
				return;
			pipeline.~Object();
		};
		VkeApp::Base().AddCallback_CreateSwapchain(CreatePipeline);
		VkeApp::Base().AddCallback_DestroySwapchain(DestroyPipeline);
		CreatePipeline();
	}
	static void CmdBeginRendering() {
		// Transition image layout before rendering
		CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {}, ImageMemoryBarrier{}.
			DstAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
			NewLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
			Image(VkeApp::Base().SwapchainImage()).
			SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }));

		vke::CmdBeginRendering(RenderingInfo{}.
			RenderArea({ {}, swapchainImageExtent }).
			ColorAttachments(RenderingAttachmentInfo{}.
				ImageView(VkeApp::Base().SwapchainImageView()).
				ImageLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
				ClearValue({})));
	}
	static void CmdEndRendering() {
		vke::CmdEndRendering();

		// Transition image layout after rendering
		CmdPipelineBarrier(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {}, ImageMemoryBarrier{}.
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
	{
		Timer t;
		PreInitialization_SetApiVersionRequirement();
		PreInitialization_EnableSrgb();
		InitializeWindow({ 640, 640 });
		t.Print();
		BootScreen("resource/TestImage.bmp", VK_FORMAT_R8G8B8A8_SRGB);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	ToScreen::Initialize();

	oop::Fence fence({});
	oop::Semaphore semaphore_imageIsAvailable({});
	oop::Semaphore semaphore_renderingIsOver({});

	oop::CommandBuffer commandBuffer;
	oop::CommandPool commandPool({ FLAGS(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT) });
	commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBuffer);

	while (!WindowShouldClose()) {
		TitleFps();

		VkeApp::Base().SwapImage(semaphore_imageIsAvailable);
		commandBuffer.Begin(FLAGS(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT));
		ToScreen::CmdBeginRendering();

		CmdSetViewport(0, Viewport{ 0.f, 0.f, float(swapchainImageExtent.width), float(swapchainImageExtent.height), 0.f, 1.f });
		CmdSetScissor(0, Rect2D{ {}, swapchainImageExtent });
		CmdBindPipeline(VK_PIPELINE_BIND_POINT_GRAPHICS, ToScreen::pipeline);
		CmdDraw(3, 1, 0, 0);

		ToScreen::CmdEndRendering();
		commandBuffer.End();
		VkeApp::Base().SubmitCommandBuffers(semaphore_imageIsAvailable, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, commandBuffer, semaphore_renderingIsOver, fence);
		VkeApp::Base().PresentImage(semaphore_renderingIsOver);

		PollEvents();
		fence.WaitAndReset();
	}
	TerminateWindow();
	return 0;
}