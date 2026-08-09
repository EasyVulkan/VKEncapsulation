#define VK_ENCAPSULATION_RESULT_THROW
#include "WindowSystem/Glfw.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "Plus/AppBasePlus.h"

VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN
auto& swapchainImageExtent = VkeApp::Base().SwapchainCreateInfo().imageExtent;

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
			Destroy(pipeline);
		};
		VkeApp::Base().AddCallback_CreateSwapchain(CreatePipeline);
		VkeApp::Base().AddCallback_DestroySwapchain(DestroyPipeline);
		CreatePipeline();
	}
	static void CmdBeginRendering() {
		// Transition image layout before rendering
		CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_DEPENDENCY_BY_REGION_BIT, {}, {},
			ImageMemoryBarrier{}.
				DstAccessMask(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT).
				NewLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
				Image(VkeApp::Base().SwapchainImage()).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 }));

		auto colorAttachmentInfo = RenderingAttachmentInfo{}.
			ImageView(VkeApp::Base().SwapchainImageView()).
			ImageLayout(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL).
			ClearValue({});
		vke::CmdBeginRendering(RenderingInfo{}.
			RenderArea({ {}, swapchainImageExtent }).
			ColorAttachments(colorAttachmentInfo));
	}
	static void CmdEndRendering() {
		vke::CmdEndRendering();

		// Transition image layout after rendering
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
	InitializeWindow({ 640, 640 });

	ToScreen::Initialize();

	RenderingLoopSynchronization sync;

	std::vector<oop::CommandBuffer> commandBuffers(VkeApp::Base().SwapchainImageCount());
	oop::CommandPool commandPool(FLAGS{ VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT });
	commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBuffers);

	while (!WindowShouldClose()) {
		TitleFps();

		sync.SwapImage();
		sync.Fence().WaitAndReset();
		commandBuffers[sync].Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });
		ToScreen::CmdBeginRendering();

		CmdSetViewport(0, Viewport{ 0.f, 0.f, float(swapchainImageExtent.width), float(swapchainImageExtent.height), 0.f, 1.f });
		CmdSetScissor(0, Rect2D{ {}, swapchainImageExtent });
		CmdBindPipeline(VK_PIPELINE_BIND_POINT_GRAPHICS, ToScreen::pipeline);
		CmdDraw(3, 1, 0, 0);

		ToScreen::CmdEndRendering();
		commandBuffers[sync].End();
		VkeApp::Base().SubmitCommandBuffers(sync.Semaphore_ImageIsAvailable(), VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, commandBuffers[sync], sync.Semaphore_RenderingIsOver(), sync.Fence());
		VkeApp::Base().PresentImage(sync.Semaphore_RenderingIsOver());

		PollEvents();
	}
	TerminateWindow();
	return 0;
}