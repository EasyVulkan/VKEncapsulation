#ifndef VK_ENCAPSULATION_CALLBACK_TYPE
#define VK_ENCAPSULATION_CALLBACK_TYPE void(*)()
#endif

#ifndef VK_ENCAPSULATION_DEFAULT_SWAPCHAIN_EXTENT
#define VK_ENCAPSULATION_DEFAULT_SWAPCHAIN_EXTENT 1280, 720
#endif

VK_ENCAPSULATION_NAMESPACE_BEGIN

template<typename... Ts>
void OutputMessage(const std::format_string<Ts...> format, Ts&&... arguments) {
	std::cout << std::format(format, std::forward<Ts>(arguments)...);
}

class ApplicationBasePlus;

class ApplicationBase {
protected:
	using Callback = VK_ENCAPSULATION_CALLBACK_TYPE;
	using STypeStructureRef = STypeStructureRef<false>;
	class PhysicalDeviceDetails {
		friend class ApplicationBase;
		PhysicalDevice_ physicalDevice = VK_NULL_HANDLE;
		PhysicalDeviceFeatures2 features;
		PhysicalDeviceVulkan11Features vulkan11Features;     // Provided by VK_API_VERSION_1_2
		PhysicalDeviceVulkan12Features vulkan12Features;
		PhysicalDeviceVulkan13Features vulkan13Features;
		PhysicalDeviceVulkan14Features vulkan14Features;
		PhysicalDeviceProperties2 properties;
		PhysicalDeviceVulkan11Properties vulkan11Properties; // Provided by VK_API_VERSION_1_2
		PhysicalDeviceVulkan12Properties vulkan12Properties;
		PhysicalDeviceVulkan13Properties vulkan13Properties;
		PhysicalDeviceVulkan14Properties vulkan14Properties;
		PhysicalDeviceMemoryProperties2 memoryProperties;
		VkImageLayout copySrcLayouts[32] = {};
		VkImageLayout copyDstLayouts[32] = {};
		uint32_t queueFamilyCount = 0;
		void* pNext_features = nullptr;
		void* pNext_properties = nullptr;
	public:
		operator Ref<const PhysicalDevice_>() const { return physicalDevice; }
		Ref<const PhysicalDeviceFeatures> Features() const { return features.features; }
		Ref<const PhysicalDeviceVulkan11Features> Vulkan11Features() const { return vulkan11Features; }
		Ref<const PhysicalDeviceVulkan12Features> Vulkan12Features() const { return vulkan12Features; }
		Ref<const PhysicalDeviceVulkan13Features> Vulkan13Features() const { return vulkan13Features; }
		Ref<const PhysicalDeviceVulkan14Features> Vulkan14Features() const { return vulkan14Features; }
		Ref<const PhysicalDeviceProperties> Properties() const { return properties.properties; }
		Ref<const PhysicalDeviceVulkan11Properties> Vulkan11Properties() const { return vulkan11Properties; }
		Ref<const PhysicalDeviceVulkan12Properties> Vulkan12Properties() const { return vulkan12Properties; }
		Ref<const PhysicalDeviceVulkan13Properties> Vulkan13Properties() const { return vulkan13Properties; }
		Ref<const PhysicalDeviceVulkan14Properties> Vulkan14Properties() const { return vulkan14Properties; }
		Ref<const PhysicalDeviceMemoryProperties> MemoryProperties() const { return memoryProperties.memoryProperties; }
		uint32_t QueueFamilyCount() const { return queueFamilyCount; }
	};
	class DeviceQueueDetails {
		friend class ApplicationBase;
		Queue_ queue = VK_NULL_HANDLE;
		uint32_t familyIndex = 0;
		float priority = 0.f;
	public:
		operator Ref<const Queue_>() const { return queue; }
		const uint32_t& FamilyIndex() const { return familyIndex; }
		const float& Priority() const { return priority; }
	};
#ifndef NDEBUG
	static constexpr bool enableDebugMessenger = true;
#else
	static constexpr bool enableDebugMessenger = false;
#endif

	uint32_t apiVersion = VK_API_VERSION_1_0;
	raii::Instance instance;
	raii::DebugUtilsMessengerEXT debugMessenger;

	std::vector<PhysicalDeviceDetails> physicalDevices;
	uint32_t selectedPhysicalDeviceIndex = 0;

	std::vector<QueueFamilyProperties2> queueFamilyProperties;
	raii::Device device;
	std::vector<DeviceQueueDetails> queues;
	uint32_t presentationQueueIndex = 0;

	raii::SurfaceKHR surface;
	std::vector<SurfaceFormatKHR> surfaceFormats;

	SwapchainCreateInfoKHR swapchainCreateInfo;
	raii::SwapchainKHR swapchain;
	raii::SwapchainKHR oldSwapchain;
	std::vector<Image> swapchainImages;
	std::vector<raii::ImageView> swapchainImageViews;
	uint32_t currentSwapchainImageIndex = 0;

	std::vector<const char*> instanceLayers;
	std::vector<const char*> instanceExtensions;
	std::vector<const char*> deviceExtensions;

	void* pNext_instanceCreateInfo = nullptr;
	void* pNext_deviceCreateInfo = nullptr;

	std::vector<Callback> callbacks_enumeratePhysicalDevices;
	std::vector<Callback> callbacks_selectPhysicalDevice;
	std::vector<Callback> callbacks_createDevice;
	std::vector<Callback> callbacks_destroyDevice;
	std::vector<Callback> callbacks_createSwapchain;
	std::vector<Callback> callbacks_destroySwapchain;

	ApplicationBasePlus* pPlus = nullptr;

	/* Static */
	static ApplicationBase singleton;

	/* Constructor & Destructor */
	ApplicationBase() = default;
	ApplicationBase(ApplicationBase&&) = delete;
	~ApplicationBase() {
		if (device) {
			DeviceWaitIdle();
			if (swapchain) {
				ExecuteCallbacks(callbacks_destroySwapchain);
				swapchainImageViews.~vector();
				swapchain.~Object();
			}
			ExecuteCallbacks(callbacks_destroyDevice);
			device.~Object();
		}
		surface.~Object();
		debugMessenger.~Object();
		instance.~Object();
	}

	/* Const Function */
	AUTO   SubmitCommandBuffers_Internal(ArrayRef<const Semaphore> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer> commandBuffers, ArrayRef<const Semaphore> signalSemaphores, Fence fence) const {
		class _ : Structure<VkSubmitInfo, true> {
			Fence fence;
		public:
			_(ArrayRef<const Semaphore> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer> commandBuffers, ArrayRef<const Semaphore> signalSemaphores, Fence fence) :
				fence(fence) {
				WaitSemaphores(waitSemaphores);
				WaitDstStageMask(waitDstStageMasks);
				CommandBuffers(commandBuffers);
				SignalSemaphores(signalSemaphores);
			}
			~_() { RESULT(*this); }
			using Structure::AddNextStructure;
			using Structure::PNext;
			operator RESULT() {
				if (sType == VK_STRUCTURE_TYPE_MAX_ENUM)
					return VK_SUCCESS;
				Result result = singleton.SubmitCommandBuffers(reinterpret_cast<const SubmitInfo&>(*this), fence);
				sType = VK_STRUCTURE_TYPE_MAX_ENUM;
				return result;
			}
		};
		return _{ waitSemaphores, waitDstStageMasks, commandBuffers, signalSemaphores, fence };
	}
	AUTO   SubmitCommandBuffers_Internal(ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos, Fence fence) const {
		class _ : Structure<VkSubmitInfo2, true> {
			Fence fence;
		public:
			_(ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos, Fence fence) :
				fence(fence) {
				WaitSemaphoreInfos(waitSemaphoreInfos);
				CommandBufferInfos(commandBufferInfos);
				SignalSemaphoreInfos(signalSemaphoreInfos);
			}
			~_() { RESULT(*this); }
			using Structure::AddNextStructure;
			using Structure::PNext;
			using Structure::Flags;
			operator RESULT() {
				if (sType == VK_STRUCTURE_TYPE_MAX_ENUM)
					return VK_SUCCESS;
				Result result = singleton.SubmitCommandBuffers(reinterpret_cast<const SubmitInfo2&>(*this), fence);
				sType = VK_STRUCTURE_TYPE_MAX_ENUM;
				return result;
			}
		};
		return _{ waitSemaphoreInfos, commandBufferInfos, signalSemaphoreInfos, fence };
	}

	/* Non-const Function */
	RESULT CreateDebugMessenger() {
		if (!vkCreateDebugUtilsMessengerEXT) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get the function pointer of vkCreateDebugUtilsMessengerEXT!\n");
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
		static constexpr PFN_vkDebugUtilsMessengerCallbackEXT DebugUtilsMessengerCallback = [](
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageTypes,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData)->VkBool32 {
			OutputMessage("{}\n\n", pCallbackData->pMessage);
			return false;
		};
		auto debugUtilsMessengerCreateInfo = DebugUtilsMessengerCreateInfoEXT{}.
			MessageSeverity(
				VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
				VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT).
			MessageType(
				VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
				VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
				VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT).
			FnUserCallback(DebugUtilsMessengerCallback);
		Result result = debugMessenger.Create(debugUtilsMessengerCreateInfo);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to create a debug messenger!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT CreateDevice_Internal(ArrayRef<const DeviceQueueCreateInfo> queueCreateInfos, DeviceCreateFlags flags) {
		// Create logical device
		auto deviceCreateInfo = DeviceCreateInfo{}.
			Flags(flags).
			QueueCreateInfos(queueCreateInfos).
			EnabledExtensions(deviceExtensions);
		BaseOutStructure** ppNext = nullptr;
		if (apiVersion >= VK_API_VERSION_1_1)
			ppNext = SetPNext(pNext_deviceCreateInfo, &physicalDevices[selectedPhysicalDeviceIndex].features);
		else
			deviceCreateInfo.EnabledFeatures(PhysicalDevice().Features());
		deviceCreateInfo.PNext(pNext_deviceCreateInfo);
		Result result = device.Create(PhysicalDevice(), deviceCreateInfo);
		if (ppNext)
			*ppNext = nullptr; // Unset &physicalDevice.features
		if (result) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to create a logical device!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		// Get queues
		uint32_t queueCount = 0;
		for (auto& i : queueCreateInfos)
			queueCount += i.queueCount;
		queues.resize(queueCount);
		if (apiVersion >= VK_API_VERSION_1_1)
			for (auto p = queues.data(); auto& i : queueCreateInfos)
				for (size_t j = 0; j < i.queueCount; j++)
					GetDeviceQueue2(DeviceQueueInfo2{}.
						Flags(i.flags).
						QueueFamilyIndex(p->familyIndex = i.queueFamilyIndex).
						QueueIndex(j),
						p->queue),
					p->priority = i.pQueuePriorities[j], p++;
		else
			for (auto p = queues.data(); auto& i : queueCreateInfos)
				for (size_t j = 0; j < i.queueCount; j++)
					GetDeviceQueue(p->familyIndex = i.queueFamilyIndex, j, p->queue), p->priority = i.pQueuePriorities[j], p++;
		ThreadContext::Queue(queues[0]);
		OutputMessage("Renderer: {}\n", PhysicalDevice().Properties().deviceName);
		ExecuteCallbacks(callbacks_createDevice);
		return VK_SUCCESS;
	}
	RESULT CreateSwapchain_Internal() {
		// Create new swapchain
		if (Result result = swapchain.Create(swapchainCreateInfo)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to create a swapchain!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		// Destruction of the retired old swapchain is written inside SwapImage(...).
		// The old swapchain must be destroyed after next invocation of vkQueueSubmit(...).
		// Otherwise, error may occur if the application is running with Intel's integrated GPU.

		// Get swapchain images
		if (Result result = GetSwapchainImagesKHR(swapchain, swapchainImages)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get swapchain images!\nError code: {}\n", string_VkResult(result));
			return result;
		}

		// Create new swapchain image views
		swapchainImageViews.resize(swapchainImages.size());
		auto imageViewCreateInfo = ImageViewCreateInfo{}.
			ViewType(VK_IMAGE_VIEW_TYPE_2D).
			Format(swapchainCreateInfo.imageFormat).
			SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 });
		for (auto p = swapchainImageViews.data(); auto& i : swapchainImages) {
			imageViewCreateInfo.Image(i);
			if (Result result = p->Create(imageViewCreateInfo)) {
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to create a swapchain image view!\nError code: {}\n", string_VkResult(result));
				return result;
			}
			p++;
		}
		return VK_SUCCESS;
	}
	AUTO   PresentImage_Internal(ArrayRef<const Semaphore> waitSemaphores) {
		class _ : Structure<VkPresentInfoKHR, true> {
		public:
			_(ArrayRef<const Semaphore> waitSemaphores) {
				WaitSemaphores(waitSemaphores);
			}
			~_() { RESULT(*this); }
			using Structure::AddNextStructure;
			using Structure::PNext;
			operator RESULT() {
				if (sType == VK_STRUCTURE_TYPE_MAX_ENUM)
					return VK_SUCCESS;
				Result result = singleton.PresentImage(reinterpret_cast<const PresentInfoKHR&>(*this));
				sType = VK_STRUCTURE_TYPE_MAX_ENUM;
				return result;
			}
		};
		return _{ waitSemaphores };
	}

	/* Static Function */
	static BaseOutStructure** SetPNext(void*& pBegin, void* pNext, bool allowDuplicate = false) {
		struct _ : StructureBase<false, true> {
			using StructureBase<false, true>::SetPNext;
		};
		return _::SetPNext(reinterpret_cast<BaseOutStructure*&>(pBegin), reinterpret_cast<BaseOutStructure*&>(pNext), allowDuplicate);
	}
	static void AddLayerOrExtension(std::vector<const char*>& container, const char* name) {
		for (auto& i : container)
			if (!strcmp(name, i))
				return;
		container.push_back(name);
	}
	static void ExecuteCallbacks(std::vector<Callback>& callbacks) {
		for (size_t size = callbacks.size(), i = 0; i < size; i++)
			callbacks[i]();
	}
	static EmptyList SingleQueueCreateInfo() { return {}; }
public:
	/* Getter */
	const uint32_t& ApiVersion() const {
		return apiVersion;
	}
	Ref<const Instance_> Instance() const {
		return instance;
	}

	uint32_t PhysicalDeviceCount() const {
		return uint32_t(physicalDevices.size());
	}
	const PhysicalDeviceDetails& PhysicalDevice(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return physicalDevices[std::get<0>(std::tie(index...))];
		return physicalDevices[selectedPhysicalDeviceIndex];
	}
	const uint32_t& SelectedPhysicalDeviceIndex() const {
		return selectedPhysicalDeviceIndex;
	}

	uint32_t QueueFamilyCount() const {
		return uint32_t(queueFamilyProperties.size());
	}
	Ref<const QueueFamilyProperties> QueueFamilyProperties(uint32_t index) const {
		return queueFamilyProperties[index].queueFamilyProperties;
	}
	Ref<const Device_> Device() const {
		return device;
	}
	uint32_t QueueCount() const {
		return uint32_t(queues.size());
	}
	const DeviceQueueDetails& Queue(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return queues[std::get<0>(std::tie(index...))];
		return queues[0];
	}

	Ref<const SurfaceKHR> Surface() const { return surface; }
	uint32_t SurfaceFormatCount() const {
		return uint32_t(surfaceFormats.size());
	}
	Ref<const Format> SurfaceFormat(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return surfaceFormats[std::get<0>(std::tie(index...))].format;
		return swapchainCreateInfo.imageFormat;
	}
	Ref<const ColorSpaceKHR> SurfaceColorSpace(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return surfaceFormats[std::get<0>(std::tie(index...))].colorSpace;
		return swapchainCreateInfo.imageColorSpace;
	}

	Ref<const SwapchainCreateInfoKHR> SwapchainCreateInfo() const {
		return swapchainCreateInfo;
	}
	Ref<const SwapchainKHR> Swapchain() const {
		return swapchain;
	}
	uint32_t SwapchainImageCount() const {
		return uint32_t(swapchainImages.size());
	}
	Ref<const Image> SwapchainImage(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return swapchainImages[std::get<0>(std::tie(index...))];
		return swapchainImages[currentSwapchainImageIndex];
	}
	Ref<const ImageView> SwapchainImageView(std::integral auto... index) const {
		if constexpr (sizeof...(index))
			return swapchainImageViews[std::get<0>(std::tie(index...))];
		return swapchainImageViews[currentSwapchainImageIndex];
	}
	const uint32_t& CurrentSwapchainImageIndex() const {
		return currentSwapchainImageIndex;
	}

	const std::vector<const char*>& InstanceLayers() const {
		return instanceLayers;
	}
	const std::vector<const char*>& InstanceExtensions() const {
		return instanceExtensions;
	}
	const std::vector<const char*>& DeviceExtensions() const {
		return deviceExtensions;
	}

	/* Const Function */
	// ======== If CreateInstance(...) fails
	RESULT CheckInstanceLayers(ArrayRef<const char*> layersToCheck) const {
		std::vector<LayerProperties> availableLayers;
		if (Result result = EnumerateInstanceLayerProperties(availableLayers)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to enumerate instance layer properties!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		for (auto& i : layersToCheck) {
			bool found = false;
			for (auto& j : availableLayers)
				if (!strcmp(i, j.layerName)) {
					found = true;
					break;
				}
			if (!found)
				i = nullptr; // If a required layer isn't available, set it to nullptr
		}
		return VK_SUCCESS;
	}
	// If layerName is nullptr, extensions should be provided by the Vulkan implementation or by those implicitly enabled layers.
	RESULT CheckInstanceExtensions(ArrayRef<const char*> extensionsToCheck, ArrayRef<const char> layerName = {}) const {
		std::vector<ExtensionProperties> availableExtensions;
		if (Result result = EnumerateInstanceExtensionProperties(layerName, availableExtensions)) {
			layerName ?
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to enumerate instance extension properties!\nLayer name: {}\nError code: {}\n", layerName.data(), string_VkResult(result)) :
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to enumerate instance extension properties!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		for (auto& i : extensionsToCheck) {
			bool found = false;
			for (auto& j : availableExtensions)
				if (!strcmp(i, j.extensionName)) {
					found = true;
					break;
				}
			if (!found)
				i = nullptr; // If a required extension isn't available, set it to nullptr
		}
		return VK_SUCCESS;
	}
	// ======== If CreateDevice(...) fails
	Result CheckDeviceExtensions(ArrayRef<const char*> extensionsToCheck, ArrayRef<const char> layerName = {}) const {
		std::vector<ExtensionProperties> availableExtensions;
		if (Result result = EnumerateDeviceExtensionProperties(layerName, availableExtensions)) {
			layerName ?
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get the count of device extensions!\nLayer name: {}\nError code: {}\n", layerName.data(), string_VkResult(result)) :
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get the count of device extensions!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		for (auto& i : extensionsToCheck) {
			bool found = false;
			for (auto& j : availableExtensions)
				if (!strcmp(i, j.extensionName)) {
					found = true;
					break;
				}
			if (!found)
				i = nullptr; // If a required extension isn't available, set it to nullptr
		}
		return VK_SUCCESS;
	}
	// ======== After initialization
	RESULT DeviceWaitIdle() const {
		Result result = VK_ENCAPSULATION_NAMESPACE::DeviceWaitIdle();
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to wait for the device to be idle!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT QueueWaitIdle(uint32_t queueIndex) const {
		Result result = VK_ENCAPSULATION_NAMESPACE::QueueWaitIdle(queues[queueIndex]);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to wait for the queue to be idle!\nError code: {}\n", string_VkResult(result));
		return result;
	}

	/* Non-const Function */
	void AddCallback_EnumeratePhysicalDevices(const Callback& function) {
		callbacks_enumeratePhysicalDevices.push_back(function);
	}
	void AddCallback_SelectPhysicalDevice(const Callback& function) {
		callbacks_selectPhysicalDevice.push_back(function);
	}
	void AddCallback_CreateDevice(const Callback& function) {
		callbacks_createDevice.push_back(function);
	}
	void AddCallback_DestroyDevice(const Callback& function) {
		callbacks_destroyDevice.push_back(function);
	}
	void AddCallback_CreateSwapchain(const Callback& function) {
		callbacks_createSwapchain.push_back(function);
	}
	void AddCallback_DestroySwapchain(const Callback& function) {
		callbacks_destroySwapchain.push_back(function);
	}

	// ======== For instance creation
	void AddNextStructure_InstanceCreateInfo(STypeStructureRef next, bool allowDuplicate = false) {
		SetPNext(pNext_instanceCreateInfo, &next, allowDuplicate);
	}
	void AddInstanceLayer(const char* layer) {
		AddLayerOrExtension(instanceLayers, layer);
	}
	void AddInstanceExtension(const char* extension) {
		AddLayerOrExtension(instanceExtensions, extension);
	}
	void InstanceLayers(const std::vector<const char*>& layers) {
		instanceLayers = layers;
	}
	void InstanceExtensions(const std::vector<const char*>& extensions) {
		instanceExtensions = extensions;
	}
	RESULT UseLatestApiVersion() {
		if (vkEnumerateInstanceVersion)
			return EnumerateInstanceVersion(apiVersion);
		return VK_SUCCESS;
	}
	void ApiVersion(uint32_t apiVersion) {
		this->apiVersion = apiVersion;
	}
	RESULT CreateInstance(InstanceCreateFlags flags = 0) {
		if constexpr (enableDebugMessenger)
			AddInstanceLayer("VK_LAYER_KHRONOS_validation"),
			AddInstanceExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		auto applicationInfo = ApplicationInfo{}.
			ApiVersion(apiVersion);
		auto instanceCreateInfo = InstanceCreateInfo{}.
			PNext(pNext_instanceCreateInfo).
			Flags(flags).
			ApplicationInfo(applicationInfo).
			EnabledLayers(instanceLayers).
			EnabledExtensions(instanceExtensions);
		if (Result result = instance.Create(instanceCreateInfo)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to create a Vulkan instance!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		OutputMessage(
			"Vulkan API Version: {}.{}.{}\n",
			VK_API_VERSION_MAJOR(apiVersion),
			VK_API_VERSION_MINOR(apiVersion),
			VK_API_VERSION_PATCH(apiVersion));
		if constexpr (enableDebugMessenger)
			CreateDebugMessenger();
		return VK_SUCCESS;
	}

	// ======== For physical device selection
	RESULT EnumeratePhysicalDevices() {
		std::vector<PhysicalDevice_> _;
		Result result = VK_ENCAPSULATION_NAMESPACE::EnumeratePhysicalDevices(_);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to enumerate physical devices!\nError code: {}\n", string_VkResult(result));
		else {
			physicalDevices.resize(_.size());
			for (auto p = physicalDevices.data(); auto& i : _)
				p->physicalDevice = i, p++;
			ExecuteCallbacks(callbacks_enumeratePhysicalDevices);
		}
		return result;
	}
	void AddNextStructure_PhysicalDeviceFeatures(STypeStructureRef next, uint32_t physicalDeviceIndex) {
		SetPNext(physicalDevices[physicalDeviceIndex].pNext_features, &next);
	}
	void AddNextStructure_PhysicalDeviceProperties(STypeStructureRef next, uint32_t physicalDeviceIndex) {
		SetPNext(physicalDevices[physicalDeviceIndex].pNext_properties, &next);
	}
	void AddNextStructure_PhysicalDeviceMemoryProperties(STypeStructureRef next, uint32_t physicalDeviceIndex) {
		SetPNext(physicalDevices[physicalDeviceIndex].memoryProperties.pNext, &next);
	}
	void GetPhysicalDeviceFeaturesAndProperties() {
		if (physicalDevices[0].queueFamilyCount)
			return;
		for (auto& i : physicalDevices)
			if (apiVersion >= VK_API_VERSION_1_1 &&
				vkGetPhysicalDeviceFeatures2 ||
				vkGetPhysicalDeviceFeatures2KHR) {
				if (apiVersion >= VK_API_VERSION_1_2) {
					i.features.PNext(&i.vulkan11Features);
					i.properties.PNext(&i.vulkan11Properties);
					i.vulkan11Features.PNext(&i.vulkan12Features);
					i.vulkan11Properties.PNext(&i.vulkan12Properties);
					if (apiVersion >= VK_API_VERSION_1_3) {
						i.vulkan12Features.PNext(&i.vulkan13Features);
						i.vulkan12Properties.PNext(&i.vulkan13Properties);
						if (apiVersion >= VK_API_VERSION_1_4)
							i.vulkan13Features.PNext(&i.vulkan14Features),
							i.vulkan13Properties.PNext(&i.vulkan14Properties);
					}
				}
				SetPNext(i.features.pNext, i.pNext_features);
				M_ConditionalDispatch(GetPhysicalDeviceFeatures2, KHR, i.physicalDevice, i.features);
				SetPNext(i.properties.pNext, i.pNext_properties);
				M_ConditionalDispatch(GetPhysicalDeviceProperties2, KHR, i.physicalDevice, i.properties);
				if (i.vulkan14Features.hostImageCopy)
					i.vulkan14Properties.pCopySrcLayouts = i.copySrcLayouts,
					i.vulkan14Properties.pCopyDstLayouts = i.copyDstLayouts,
					M_ConditionalDispatch(GetPhysicalDeviceProperties2, KHR, i.physicalDevice, i.properties);
				M_ConditionalDispatch(GetPhysicalDeviceMemoryProperties2, KHR, i.physicalDevice, i.memoryProperties);
				M_ConditionalDispatch(GetPhysicalDeviceQueueFamilyProperties2, KHR, i.physicalDevice, i.queueFamilyCount);
			}
			else
				GetPhysicalDeviceFeatures(i.physicalDevice, i.features.features),
				GetPhysicalDeviceProperties(i.physicalDevice, i.properties.properties),
				GetPhysicalDeviceMemoryProperties(i.physicalDevice, i.memoryProperties.memoryProperties),
				GetPhysicalDeviceQueueFamilyProperties(i.physicalDevice, i.queueFamilyCount);
	}
	void SelectPhysicalDevice(std::integral auto... physicalDeviceIndex) {
		static bool recursionGuard;
		GetPhysicalDeviceFeaturesAndProperties();
		if constexpr (sizeof...(physicalDeviceIndex))
			selectedPhysicalDeviceIndex = std::get<0>(std::tie(physicalDeviceIndex...));
		else { // Select first discrete GPU
			selectedPhysicalDeviceIndex = 0;
			for (size_t i = 0; i < physicalDevices.size(); i++)
				if (physicalDevices[i].Properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
					selectedPhysicalDeviceIndex = i;
		}
		if (recursionGuard)
			return;
		recursionGuard = true;
		ExecuteCallbacks(callbacks_selectPhysicalDevice);
		recursionGuard = false;
		queueFamilyProperties.clear();
		queueFamilyProperties.resize(PhysicalDevice().queueFamilyCount);
	}

	// ======== For logical device creation
	void AddNextStructure_DeviceCreateInfo(STypeStructureRef next, bool allowDuplicate = false) {
		SetPNext(pNext_deviceCreateInfo, &next, allowDuplicate);
	}
	void AddNextStructure_QueueFamilyProperties(STypeStructureRef next, uint32_t queueFamilyIndex) {
		SetPNext(queueFamilyProperties[queueFamilyIndex].pNext, &next);
	}
	void AddDeviceExtension(const char* extension) {
		AddLayerOrExtension(deviceExtensions, extension);
	}
	void DeviceExtensions(const std::vector<const char*>& extensions) {
		instanceExtensions = extensions;
	}
	void GetQueueFamilyProperties() {
		if (QueueFamilyProperties(0).queueCount)
			return;
		uint32_t queueFamilyCount = queueFamilyProperties.size();
		if (apiVersion >= VK_API_VERSION_1_1 &&
			vkGetPhysicalDeviceQueueFamilyProperties2 ||
			vkGetPhysicalDeviceQueueFamilyProperties2KHR)
			M_ConditionalDispatch(GetPhysicalDeviceQueueFamilyProperties2, KHR, PhysicalDevice(), queueFamilyCount, queueFamilyProperties);
		else {
			std::vector<QueueFamilyProperties_> _(queueFamilyProperties.size());
			GetPhysicalDeviceQueueFamilyProperties(PhysicalDevice(), queueFamilyCount, _);
			for (auto p = queueFamilyProperties.data(); auto& i : _)
				p->queueFamilyProperties = i, p++;
		}
	}
	void Surface(raii::SurfaceKHR& surface) {
		if (!this->surface)
			surface.Allocator(),
			this->surface = std::move(surface);
	}
	// CreateDevice(...) only supports single-device context.
	M_InstantiationGuard_MayCreateMultipleDevice
	RESULT CreateDevice(ArrayRef<const DeviceQueueCreateInfo> queueCreateInfos = SingleQueueCreateInfo(), DeviceCreateFlags flags = 0) {
		static constexpr QueueFlags defaultQueueFlags = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT;
		static constexpr float defaultQueuePriority = 1.f;
		GetQueueFamilyProperties();
		if (queueCreateInfos)
			return CreateDevice_Internal(queueCreateInfos, flags);
		for (size_t i = 0; i < queueFamilyProperties.size(); i++)
			if ((QueueFamilyProperties(i).queueFlags & defaultQueueFlags) == defaultQueueFlags) {
				if (surface) {
					Bool32 supported = false;
					GetPhysicalDeviceSurfaceSupportKHR(PhysicalDevice(), i, surface, supported);
					if (!supported)
						continue;
				}
				auto deviceQueueCreateInfo = DeviceQueueCreateInfo{}.
					QueueFamilyIndex(i).
					QueuePriorities(defaultQueuePriority);
				return CreateDevice_Internal(deviceQueueCreateInfo, flags);
			}
		return CreateDevice_Internal({}, flags);
	}

	// ======== For swapchain creation
	void AddNextStructure_SwapchainCreateInfo(STypeStructureRef next) {
		SetPNext(const_cast<void*&>(swapchainCreateInfo.pNext), &next);
	}
	RESULT GetSurfaceFormats() {
		Result result = GetPhysicalDeviceSurfaceFormatsKHR(surface, surfaceFormats);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get surface formats!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	// Will call RecreateSwapchain() if the swapchain already exists.
	RESULT SetSurfaceFormat(SurfaceFormatKHR surfaceFormat) {
		if (!surfaceFormats.size())
			if (Result result = GetSurfaceFormats())
				return result;
		bool formatIsAvailable = false;
		if (!surfaceFormat.format) {
			for (auto& i : surfaceFormats)
				if (i.colorSpace == surfaceFormat.colorSpace) {
					swapchainCreateInfo.ImageFormat(i.format);
					swapchainCreateInfo.ImageColorSpace(i.colorSpace);
					formatIsAvailable = true;
					break;
				}
		}
		else
			for (auto& i : surfaceFormats)
				if (i.format == surfaceFormat.format &&
					i.colorSpace == surfaceFormat.colorSpace) {
					swapchainCreateInfo.ImageFormat(i.format);
					swapchainCreateInfo.ImageColorSpace(i.colorSpace);
					formatIsAvailable = true;
					break;
				}
		if (!formatIsAvailable)
			return VK_ERROR_FORMAT_NOT_SUPPORTED;
		if (swapchain)
			return RecreateSwapchain();
		return VK_SUCCESS;
	}
	RESULT CreateSwapchain(ArrayRef<const PresentModeKHR> desiredPresentModes = VK_PRESENT_MODE_FIFO_KHR, SwapchainCreateFlagsKHR flags = 0) {
		// Get surface capabilities
		SurfaceCapabilitiesKHR surfaceCapabilities;
		if (Result result = GetPhysicalDeviceSurfaceCapabilitiesKHR(surface, surfaceCapabilities)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get physical device surface capabilities!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		// Set image count
		swapchainCreateInfo.MinImageCount(surfaceCapabilities.minImageCount + (surfaceCapabilities.maxImageCount > surfaceCapabilities.minImageCount));
		// Set image extent
		swapchainCreateInfo.ImageExtent(
			surfaceCapabilities.currentExtent.width == UINT32_MAX ?
			Extent2D{ VK_ENCAPSULATION_DEFAULT_SWAPCHAIN_EXTENT } :
			surfaceCapabilities.currentExtent);
		// Set transformation
		swapchainCreateInfo.PreTransform(surfaceCapabilities.currentTransform);
		// Set alpha compositing mode
		if (surfaceCapabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR)
			swapchainCreateInfo.CompositeAlpha(VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR);
		else
			for (size_t i = 0; i < 3; i++)
				if (surfaceCapabilities.supportedCompositeAlpha & 1 << i) {
					swapchainCreateInfo.CompositeAlpha(CompositeAlphaFlagBitsKHR(surfaceCapabilities.supportedCompositeAlpha & 1 << i));
					break;
				}
		// Set image usage
		swapchainCreateInfo.ImageUsage(VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
		if (surfaceCapabilities.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_SRC_BIT)
			swapchainCreateInfo.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
		if (surfaceCapabilities.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_DST_BIT)
			swapchainCreateInfo.imageUsage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
		else
			OutputMessage("[ vke::ApplicationBase ] WARNING\nVK_IMAGE_USAGE_TRANSFER_DST_BIT is not supported by the surface!\n");

		// Get surface formats
		if (!surfaceFormats.size())
			if (Result result = GetSurfaceFormats())
				return result;
		// Select a four-component UNORM format if surface format is not determined
		if (!swapchainCreateInfo.imageFormat)
			if (SetSurfaceFormat({ VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR }) &&
				SetSurfaceFormat({ VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR })) {
				swapchainCreateInfo.ImageFormat(surfaceFormats[0].format);
				swapchainCreateInfo.ImageColorSpace(surfaceFormats[0].colorSpace);
				OutputMessage("[ vke::ApplicationBase ] WARNING\nFailed to select a four-component UNORM surface format!\n");
			}

		// Get surface present modes
		std::vector<PresentModeKHR> surfacePresentModes;
		if (Result result = GetPhysicalDeviceSurfacePresentModesKHR(surface, surfacePresentModes)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get surface present modes!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		// Set present mode
		swapchainCreateInfo.PresentMode(VK_PRESENT_MODE_FIFO_KHR);
		for (auto& i : desiredPresentModes) {
			for (auto& j : surfacePresentModes)
				if (i == j) {
					swapchainCreateInfo.PresentMode(i);
					break;
				}
			if (swapchainCreateInfo.presentMode == i)
				break;
		}

		// Create swapchain
		swapchainCreateInfo.Flags(flags);
		swapchainCreateInfo.Surface(surface);
		swapchainCreateInfo.Clipped(VK_TRUE);
		if (Result result = CreateSwapchain_Internal())
			return result;

		// Create related objects
		ExecuteCallbacks(callbacks_createSwapchain);
		return VK_SUCCESS;
	}

	// ======== For rendering loop
	RESULT SwapImage(Semaphore signalSemaphore, Fence fence = VK_NULL_HANDLE) {
		// Destroy retired old swapchain and its associated images
		if (oldSwapchain &&
			oldSwapchain != swapchain) // Prevent the destruction of oldSwapchain if RecreateSwapchain() fails
			oldSwapchain.~Object(),
			swapchainCreateInfo.OldSwapchain(VK_NULL_HANDLE);
		while (Result result = AcquireNextImageKHR(swapchain, UINT64_MAX, signalSemaphore, fence, currentSwapchainImageIndex))
			switch (result) {
			case VK_SUBOPTIMAL_KHR:
			case VK_ERROR_OUT_OF_DATE_KHR:
				if (Result result = RecreateSwapchain())
					return result;
				break;
			default:
				OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to acquire the next image!\nError code: {}\n", string_VkResult(result));
				return result;
			}
		return VK_SUCCESS;
	}
	RESULT PresentImage(Ref<const PresentInfoKHR> presentInfo) {
		auto info = PresentInfoKHR{ presentInfo }.
			Swapchains(swapchain).
			ImageIndices(currentSwapchainImageIndex);
		switch (Result result = QueuePresentKHR(queues[presentationQueueIndex], info)) {
		case VK_SUCCESS:
			return VK_SUCCESS;
		case VK_SUBOPTIMAL_KHR:
		case VK_ERROR_OUT_OF_DATE_KHR:
			return RecreateSwapchain();
		default:
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to queue the image for presentation!\nError code: {}\n", string_VkResult(result));
			return result;
		}
	}
	AUTO   PresentImage(uint32_t queueIndex, ArrayRef<const Semaphore> waitSemaphores = {}) {
		presentationQueueIndex = queueIndex;
		return PresentImage_Internal(waitSemaphores);
	}
	AUTO   PresentImage(ArrayRef<const Semaphore> waitSemaphores = {}) {
		return PresentImage_Internal(waitSemaphores);
	}

	// ======== For commmand buffer submission
	RESULT SubmitCommandBuffers(uint32_t queueIndex, ArrayRef<const SubmitInfo> submitInfos, Fence fence = VK_NULL_HANDLE) const {
		ThreadContext::Queue(queues[queueIndex]);
		return SubmitCommandBuffers(submitInfos, fence);
	}
	RESULT SubmitCommandBuffers(ArrayRef<const SubmitInfo> submitInfos, Fence fence = VK_NULL_HANDLE) const {
		Result result = QueueSubmit(ThreadContext::Queue(), submitInfos, fence);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to submit command buffers!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   SubmitCommandBuffers(uint32_t queueIndex, ArrayRef<const Semaphore> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer> commandBuffers, ArrayRef<const Semaphore> signalSemaphores, Fence fence = VK_NULL_HANDLE) const {
		ThreadContext::Queue(queues[queueIndex]);
		return SubmitCommandBuffers_Internal(waitSemaphores, waitDstStageMasks, commandBuffers, signalSemaphores, fence);
	}
	AUTO   SubmitCommandBuffers(ArrayRef<const Semaphore> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer> commandBuffers, ArrayRef<const Semaphore> signalSemaphores, Fence fence = VK_NULL_HANDLE) const {
		return SubmitCommandBuffers_Internal(waitSemaphores, waitDstStageMasks, commandBuffers, signalSemaphores, fence);
	}
	RESULT SubmitCommandBuffers(uint32_t queueIndex, ArrayRef<const SubmitInfo2> submitInfos, Fence fence = VK_NULL_HANDLE) const {
		ThreadContext::Queue(queues[queueIndex]);
		return SubmitCommandBuffers(submitInfos, fence);
	}
	RESULT SubmitCommandBuffers(ArrayRef<const SubmitInfo2> submitInfos, Fence fence = VK_NULL_HANDLE) const {
		Result result = M_ConditionalDispatch(QueueSubmit2, KHR, ThreadContext::Queue(), submitInfos, fence);
		if (result)
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to submit command buffers!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   SubmitCommandBuffers(uint32_t queueIndex, ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos, Fence fence = VK_NULL_HANDLE) const {
		ThreadContext::Queue(queues[queueIndex]);
		return SubmitCommandBuffers_Internal(waitSemaphoreInfos, commandBufferInfos, signalSemaphoreInfos, fence);
	}
	AUTO   SubmitCommandBuffers(ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos, Fence fence = VK_NULL_HANDLE) const {
		return SubmitCommandBuffers_Internal(waitSemaphoreInfos, commandBufferInfos, signalSemaphoreInfos, fence);
	}

	// ======== After initialization
	// Call RecreateDevice(...) and CreateSwapchain(...) after SelectPhysicalDevice(...) if you want to switch physical device at runtime.
	M_InstantiationGuard_MayCreateMultipleDevice
	RESULT RecreateDevice(ArrayRef<const DeviceQueueCreateInfo> queueCreateInfos = SingleQueueCreateInfo(), DeviceCreateFlags flags = 0) {
		if (device) {
			if (Result result = DeviceWaitIdle();
				result != VK_SUCCESS &&
				result != VK_ERROR_DEVICE_LOST)
				return result;
			if (swapchain) {
				ExecuteCallbacks(callbacks_destroySwapchain);
				swapchainImageViews.~vector();
				swapchain.~Object();
				swapchainCreateInfo.OldSwapchain(VK_NULL_HANDLE);
				presentationQueueIndex = 0;
			}
			ExecuteCallbacks(callbacks_destroyDevice);
			device.~Object();
		}
		return CreateDevice(queueCreateInfos, flags);
	}
	RESULT RecreateSwapchain() {
		SurfaceCapabilitiesKHR surfaceCapabilities;
		if (Result result = GetPhysicalDeviceSurfaceCapabilitiesKHR(surface, surfaceCapabilities)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to get physical device surface capabilities!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		if (surfaceCapabilities.currentExtent.width == 0 ||
			surfaceCapabilities.currentExtent.height == 0)
			return VK_SUBOPTIMAL_KHR;
		swapchainCreateInfo.ImageExtent(surfaceCapabilities.currentExtent);
		swapchainCreateInfo.OldSwapchain(swapchain);
		if (oldSwapchain != swapchain)
			oldSwapchain = std::move(swapchain); // Will call oldSwapchain.~Object()

		// Wait for presentation queue to be idle
		if (Result result = QueueWaitIdle(presentationQueueIndex)) {
			OutputMessage("[ vke::ApplicationBase ] ERROR\nFailed to wait for the queue to be idle!\nError code: {}\n", string_VkResult(result));
			return result;
		};

		// Destroy old swapchain related objects
		ExecuteCallbacks(callbacks_destroySwapchain);
		swapchainImageViews.~vector();
		// Create swapchain
		if (Result result = CreateSwapchain_Internal())
			return result;
		ExecuteCallbacks(callbacks_createSwapchain);
		return VK_SUCCESS;
	}
	// Call Terminate() if you need to terminate Vulkan before program exits.
	void Terminate() {
		this->~ApplicationBase();
		apiVersion = VK_API_VERSION_1_0;
		selectedPhysicalDeviceIndex = 0;
		presentationQueueIndex = 0;
		swapchainCreateInfo = SwapchainCreateInfoKHR{};
		currentSwapchainImageIndex = 0;
		pNext_instanceCreateInfo = nullptr;
		pNext_deviceCreateInfo = nullptr;
	}

	/* Static Function */
	static constexpr ApplicationBase& Base() {
		return singleton;
	}
	static void Plus(ApplicationBasePlus& plus) {
		singleton.pPlus = &plus;
	}
	static ApplicationBasePlus& Plus() {
		return *singleton.pPlus;
	}
};
M_DefineStaticDataMember(ApplicationBase::singleton);

VK_ENCAPSULATION_NAMESPACE_END

using VkeApp = VK_ENCAPSULATION_NAMESPACE::ApplicationBase;