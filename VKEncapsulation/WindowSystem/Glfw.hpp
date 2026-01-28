#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#define NOMINMAX
#endif
#define VOLK_IMPLEMENTATION
#include "Core/VKEncapsulation.h"
#define GLFW_INCLUDE_VULKAN
#include M_GlfwHeader(GLFW/glfw3.h)
#include <sstream>
#pragma comment(lib, M_GlfwLibrary(glfw3.lib))

#define M_Main main

#define VK_ENCAPSULATION_WS_BEGIN namespace VK_ENCAPSULATION_NAMESPACE::ws {

VK_ENCAPSULATION_WS_BEGIN

/* Variable */
GLFWmonitor* pMonitor;
GLFWwindow* pWindow;

/* Function */
auto PreInitialization_SetWindowTitle(ArrayRef<const char> windowTitle) {
	static const char* _windowTitle = "Vulkan Application"; // Constant-initialized since C++20
	_windowTitle = windowTitle;
	return [] { return _windowTitle; };
}
auto PreInitialization_SetWindowCreationCallback(void(*callback)()) {
	static void(*function)();
	function = callback;
	return [] { return function; };
}
auto PreInitialization_SetApiVersionRequirement(uint32_t minimumVersion = VK_API_VERSION_1_0, uint32_t maximumVersion = VK_HEADER_VERSION_COMPLETE) {
	static std::pair<uint32_t, uint32_t> versionRange; // Static object will be zero-initialized at launch
	versionRange = { std::min(minimumVersion, maximumVersion), std::max(minimumVersion, maximumVersion) };
	return [] { return versionRange; };
}
auto PreInitialization_EnableSrgb() {
	static bool enableSrgb; // Static object will be zero-initialized at launch
	enableSrgb = true;
	return [] { return enableSrgb; };
}
auto PreInitialization_TrySetColorSpaceByOrder(ArrayRef<const ColorSpaceKHR> colorSpaces) {
	static std::unique_ptr<ColorSpaceKHR[]> _colorSpaces;
	_colorSpaces = std::make_unique<ColorSpaceKHR[]>(colorSpaces.size() + 1);                 // Value-initialization
	std::memcpy(_colorSpaces.get(), colorSpaces, sizeof(ColorSpaceKHR) * colorSpaces.size()); // The last element remains zero
	return []()->const ColorSpaceKHR* { return _colorSpaces.get(); };
}
bool InitializeWindow(Extent2D size, bool fullScreen = false, bool isResizable = true, bool limitFrameRate = true) {
	// Initialize Volk
	Initialize();
	// Initialize GLFW
	if (glfwInit() == GLFW_FALSE) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to initialize GLFW!\n");
		return false;
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, isResizable);
	// Get the monitor and the video mode
	pMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
	// Create glfw window
	pWindow =
		fullScreen ?
		glfwCreateWindow(pMode->width, pMode->height, decltype(PreInitialization_SetWindowTitle({})){}(), pMonitor, nullptr) :
		glfwCreateWindow(size.width, size.height, decltype(PreInitialization_SetWindowTitle({})){}(), nullptr, nullptr); // Returns 0 if FAIL
	if (!pWindow) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to create a glfw window!\n");
		glfwTerminate();
		return false;
	}
	if (void(*function)() = decltype(PreInitialization_SetWindowCreationCallback({})){}())
		function();
	// Add extensions
#ifdef _WIN32
	VkeApp::Base().AddInstanceExtension(VK_KHR_SURFACE_EXTENSION_NAME);
	VkeApp::Base().AddInstanceExtension(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#else
	uint32_t extensionCount = 0;
	const char** extensionNames;
	extensionNames = glfwGetRequiredInstanceExtensions(&extensionCount);
	if (!extensionNames) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nVulkan is not available on this machine!\n");
		glfwTerminate();
		return false;
	}
	for (size_t i = 0; i < extensionCount; i++)
		VkeApp::Base().AddInstanceExtension(extensionNames[i]);
#endif
	const ColorSpaceKHR* colorSpaces = decltype(PreInitialization_TrySetColorSpaceByOrder({})){}();
	if (colorSpaces)
		VkeApp::Base().AddInstanceExtension(VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME);
	VkeApp::Base().AddDeviceExtension(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
	// Determine API version
	if (auto [minimumVersion, maximumVersion] = decltype(PreInitialization_SetApiVersionRequirement()){}();
		minimumVersion) {
		VkeApp::Base().UseLatestApiVersion();
		if (VkeApp::Base().ApiVersion() < minimumVersion) {
			OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to satisfy the requirement of API version!\n");
			return false;
		}
		if (VkeApp::Base().ApiVersion() > maximumVersion)
			VkeApp::Base().ApiVersion(maximumVersion);
	}
	// Create vulkan instance
	if (VkeApp::Base().CreateInstance())
		return false;
	// Create surface
	raii::SurfaceKHR surface;
	if (Result result = glfwCreateWindowSurface(VkeApp::Base().Instance(), pWindow, ThreadContext::PAllocator(), reinterpret_cast<SurfaceKHR*>(&surface))) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to create a window surface!\nError code: {}\n", string_VkResult(result));
		glfwTerminate();
		return false;
	}
	VkeApp::Base().Surface(surface);
	// Get physical device
	if (VkeApp::Base().EnumeratePhysicalDevices())
		return false;
	VkeApp::Base().SelectPhysicalDevice();
	// Create logical device
	if (VkeApp::Base().CreateDevice())
		return false;
	// Set surface format if necessary
	if (colorSpaces) {
		Result result = VK_SUCCESS;
		while (*colorSpaces)
			if (result = VkeApp::Base().SetSurfaceFormat({ VK_FORMAT_UNDEFINED, *colorSpaces++ });
				result == VK_SUCCESS)
				break;
		if (result)
			OutputMessage("[ vke::ws::InitializeWindow ] WARNING\nFailed to satisfy the requirement of color space!\n");
	}
	if (!VkeApp::Base().SwapchainCreateInfo().imageFormat &&
		decltype(PreInitialization_EnableSrgb()){}())
		if (VkeApp::Base().SetSurfaceFormat({ VK_FORMAT_R8G8B8A8_SRGB, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR }) &&
			VkeApp::Base().SetSurfaceFormat({ VK_FORMAT_B8G8R8A8_SRGB, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR }))
			OutputMessage("[ vke::ws::InitializeWindow ] WARNING\nFailed to enable sRGB!\n");
	// Create swapchain
	if (VkeApp::Base().CreateSwapchain(limitFrameRate ? VK_PRESENT_MODE_FIFO_KHR : VK_PRESENT_MODE_MAILBOX_KHR))
		return false;
	return true;
}
void TerminateWindow() {
	VkeApp::Base().DeviceWaitIdle();
	glfwTerminate();
}
void MakeWindowFullScreen() {
	const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
	glfwSetWindowMonitor(pWindow, pMonitor, 0, 0, pMode->width, pMode->height, pMode->refreshRate);
}
void MakeWindowWindowed(Offset2D position, Extent2D size) {
	const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
	glfwSetWindowMonitor(pWindow, nullptr, position.x, position.y, size.width, size.height, pMode->refreshRate);
}
void SwitchWindowMode(Offset2D& position_windowed, Extent2D& size_windowed) {
	// Be aware that if the window is initialized in full screen mode,
	// you must initialize size_windowed to be non-zero,
	// and should initialize position_windowed to be non-zero if you want to move the window by dragging the title bar.
	if (glfwGetWindowMonitor(pWindow))
		MakeWindowWindowed(position_windowed, size_windowed);
	else
		glfwGetWindowPos(pWindow, &position_windowed.x, &position_windowed.y),
		glfwGetWindowSize(pWindow, reinterpret_cast<int*>(&size_windowed.width), reinterpret_cast<int*>(&size_windowed.height)),
		MakeWindowFullScreen();
}
bool WindowShouldClose() {
	return glfwWindowShouldClose(pWindow);
}
void PollEvents() {
	glfwPollEvents();
	while (glfwGetWindowAttrib(pWindow, GLFW_ICONIFIED))
		glfwWaitEvents();
}
void TitleFps() {
	static double time0 = glfwGetTime();
	static double time1;
	static double dt;
	static int dframe = -1;
	static std::stringstream info;
	time1 = glfwGetTime();
	dframe++;
	if ((dt = time1 - time0) >= 1) {
		info.precision(1);
		info << decltype(PreInitialization_SetWindowTitle({})){}() << "    " << std::fixed << dframe / dt << " FPS";
		glfwSetWindowTitle(pWindow, info.str().c_str());
		info.str("");
		time0 = time1;
		dframe = 0;
	}
}

VK_ENCAPSULATION_NAMESPACE_END