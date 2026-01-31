#define VK_USE_PLATFORM_WIN32_KHR
#define NOMINMAX
#define VOLK_IMPLEMENTATION
#include "Core/VKEncapsulation.h"
#include <chrono>
#include <sstream>
#ifndef NDEBUG
#pragma comment(linker, "/subsystem:console")
#define M_Main main() { WinMain(GetModuleHandle(0), 0, nullptr, 0); } int WinMain
#else
#pragma comment(linker, "/subsystem:windows")
#define M_Main _stdcall WinMain
#endif

#define VK_ENCAPSULATION_WS_BEGIN namespace VK_ENCAPSULATION_NAMESPACE::ws {

VK_ENCAPSULATION_WS_BEGIN

/* Class */
class Window {
	struct WindowClass : WNDCLASSEX {
		WindowClass() {
			//ZeroMemory(this, sizeof(WNDCLASSEX)); // Static object will be zero-initialized at launch
			cbSize = sizeof(WNDCLASSEX);
			style = CS_OWNDC;
			lpfnWndProc = WindowProcedureSetup;
			hInstance = GetModuleHandle(0);
			hCursor = LoadCursor(NULL, IDC_ARROW);
			lpszClassName = L"Main WindowClass";
			RegisterClassEx(this);
		}
	};
	HWND hWindow = nullptr;
	MSG message = {};
	bool isMinimized = false;
	bool shouldClose = true;
	LRESULT(*fHandleMessage)(HWND, UINT, WPARAM, LPARAM) = nullptr;
	/* -------------------- */
	static LRESULT CALLBACK WindowProcedureSetup(HWND hWindow, UINT message, WPARAM wParam, LPARAM lParam) {
		// WM_NCCREATE is sent before WM_CREATE. NC means non-client area (e.g. title bar, system menu).
		if (message != WM_NCCREATE)
			return DefWindowProc(hWindow, message, wParam, lParam); // Def means default
		Window* pWindow = reinterpret_cast<Window*>(reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams);
		// Store a pointer of the user-defined window object, in case you want to acces the object in the WNDPROC function.
		SetWindowLongPtr(hWindow, GWLP_USERDATA, (LONG_PTR)pWindow);
		// WindowProcedureSetup(...) should be called only once, reset WNDPROC to a static function which calls fHandleMessage(...) directly.
		SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)WindowProcedureThunk);
		return WindowProcedureThunk(hWindow, message, wParam, lParam);
	}
	static LRESULT CALLBACK WindowProcedureThunk(HWND hWindow, UINT message, WPARAM wParam, LPARAM lParam) {
		Window* pWindow = reinterpret_cast<Window*>(GetWindowLongPtr(hWindow, GWLP_USERDATA));
		switch (message) {
		case WM_SIZE:
			pWindow->isMinimized = wParam == SIZE_MINIMIZED;
			break;
			// If the program is running with a console, you should terminate the program by clicking the console's closebox.
		case WM_CLOSE:
			pWindow->shouldClose = true;
			return 0; // When quiting, DestroyWindow(...) is called in ~window(), no need to return DefWindowProc(...)
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
		return (
			pWindow->fHandleMessage ?
			pWindow->fHandleMessage :
			DefWindowProc)(hWindow, message, wParam, lParam);
	}
public:
	Window() = default;
	Window(const wchar_t* name, SIZE size, DWORD style, DWORD exStyle = 0, const WNDCLASSEX& windowClass = MainWindowClass()) {
		Create(name, size, style, exStyle, windowClass);
	}
	Window(Window&&) = delete;
	~Window() {
		if (DestroyWindow(hWindow)) // Returns 0 if FAIL
			hWindow = nullptr;
	}
	/* Getter */
	operator const HWND&() const { return hWindow; }
	const MSG& Message() const { return message; }
	const bool& IsMinimized() const { return isMinimized; }
	const bool& ShouldClose() const { return shouldClose; }
	/* Setter */
	void FHandleMessage(LRESULT(*fHandleMessage)(HWND, UINT, WPARAM, LPARAM)) { this->fHandleMessage = fHandleMessage; }
	/* Non-const Function */
	void Create(const wchar_t* name, SIZE size, DWORD style, DWORD exStyle = 0, const WNDCLASSEX& windowClass = MainWindowClass()) {
		RECT area = { 0, 0, size.cx, size.cy };
		AdjustWindowRect(&area, style, false);
		size.cx = area.right - area.left;
		size.cy = area.bottom - area.top;
		int left = (GetSystemMetrics(SM_CXSCREEN) - size.cx) / 2;
		int top = (GetSystemMetrics(SM_CYSCREEN) - size.cy) / 2;
		hWindow = CreateWindowEx(exStyle, windowClass.lpszClassName, name, style,
			left, top, size.cx, size.cy,
			nullptr, nullptr, windowClass.hInstance, this);
		if (hWindow)
			ShowWindow(hWindow, SW_SHOWDEFAULT),
			shouldClose = false;
	}
	void PollEvents() {
		while (PeekMessage(&message, hWindow, 0, 0, PM_REMOVE))
			TranslateMessage(&message),
			DispatchMessage(&message);
	}
	void WaitEvent() {
		if (GetMessage(&message, hWindow, 0, 0))
			TranslateMessage(&message),
			DispatchMessage(&message);
	}
	/* Static Function */
	static const WNDCLASSEX& MainWindowClass() {
		static WindowClass mainWindowClass;
		return mainWindowClass;
	}
};

/* Variable */
Window mainWindow;
DWORD style_windowed;

/* Function */
auto PreInitialization_SetWindowTitle(ArrayRef<const wchar_t> windowTitle) {
	static const wchar_t* _windowTitle = L"Vulkan Application"; // Constant-initialized since C++20
	_windowTitle = windowTitle;
	return [] { return _windowTitle; };
}
auto PreInitialization_SetWindowCreationCallback(std::type_identity_t<VK_ENCAPSULATION_CALLBACK_TYPE> callback) {
	static std::type_identity_t<VK_ENCAPSULATION_CALLBACK_TYPE> function;
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
	// Create window
	style_windowed = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	if (isResizable)
		style_windowed |= WS_SIZEBOX | WS_MAXIMIZEBOX;
	fullScreen ?
		mainWindow.Create(decltype(PreInitialization_SetWindowTitle({})){}(), { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) }, WS_POPUP) :
		mainWindow.Create(decltype(PreInitialization_SetWindowTitle({})){}(), { long(size.width), long(size.height) }, style_windowed);
	if (!mainWindow) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to create a win32 window!\n");
		return false;
	}
	if (void(*function)() = decltype(PreInitialization_SetWindowCreationCallback({})){}())
		function();
	// Add extensions
	VkeApp::Base().AddInstanceExtension(VK_KHR_SURFACE_EXTENSION_NAME);
	VkeApp::Base().AddInstanceExtension(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
	const VkColorSpaceKHR* colorSpaces = decltype(PreInitialization_TrySetColorSpaceByOrder({})){}();
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
	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {
		.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
		.hinstance = Window::MainWindowClass().hInstance,
		.hwnd = mainWindow
	};
	if (Result result = vkCreateWin32SurfaceKHR(VkeApp::Base().Instance(), &surfaceCreateInfo, ThreadContext::PAllocator(), reinterpret_cast<SurfaceKHR*>(&surface))) {
		OutputMessage("[ vke::ws::InitializeWindow ] ERROR\nFailed to create a window surface!\nError code: {}\n", string_VkResult(result));
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
	mainWindow.~Window();
}
void MakeWindowFullScreen() {
	SetWindowLongPtr(mainWindow, GWL_STYLE, WS_POPUP | WS_VISIBLE);
	SetWindowPos(mainWindow, nullptr, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
}
void MakeWindowWindowed(Offset2D position, Extent2D size) {
	SetWindowLongPtr(mainWindow, GWL_STYLE, style_windowed | WS_VISIBLE);
	RECT area = { position.x, position.y, long(position.x + size.width), long(position.y + size.height) };
	AdjustWindowRect(&area, style_windowed, false);
	size.width = area.right - area.left;
	size.height = area.bottom - area.top;
	SetWindowPos(mainWindow, nullptr, area.left, area.top, size.width, size.height, 0);
}
void MakeWindowWindowed(const WINDOWPLACEMENT& windowPlacement) {
	SetWindowLongPtr(mainWindow, GWL_STYLE, style_windowed | WS_VISIBLE | WS_MAXIMIZE * (windowPlacement.showCmd == SW_MAXIMIZE));
	SetWindowPlacement(mainWindow, &windowPlacement);
}
void SwitchWindowMode(WINDOWPLACEMENT& windowPlacement) {
	// Be aware that if the window is initialized in full screen mode,
	// you must initialize windowPlacement. Example:
	// WINDOWPLACEMENT windowPlacement = { sizeof(WINDOWPLACEMENT), 0, 1, { -1, -1 }, { -1, -1 }, area };
	if (GetWindowLongPtr(mainWindow, GWL_STYLE) & WS_POPUP)
		MakeWindowWindowed(windowPlacement);
	else
		GetWindowPlacement(mainWindow, &windowPlacement),
		MakeWindowFullScreen();
}
bool WindowShouldClose() {
	return mainWindow.ShouldClose();
}
void PollEvents() {
	mainWindow.PollEvents();
	while (mainWindow.IsMinimized())
		mainWindow.WaitEvent();
}
void TitleFps() {
	using namespace std::chrono;
	static steady_clock::time_point time0 = steady_clock::now();
	static steady_clock::time_point time1;
	static double dt;
	static int dframe = -1;
	static std::wstringstream info;
	time1 = steady_clock::now();
	dframe++;
	if ((dt = duration<double>(time1 - time0).count()) >= 1) {
		info.precision(1);
		info << decltype(PreInitialization_SetWindowTitle({})){}() << L"   " << std::fixed << dframe / dt << " FPS";
		SetWindowText(mainWindow, info.str().c_str());
		info.str(L"");
		time0 = time1;
		dframe = 0;
	}
}

VK_ENCAPSULATION_NAMESPACE_END