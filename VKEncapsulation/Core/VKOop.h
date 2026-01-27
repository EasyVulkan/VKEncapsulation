#pragma once
#include <fstream>

#define VK_ENCAPSULATION_OOP_NAMESPACE_BEGIN   namespace VK_ENCAPSULATION_NAMESPACE::oop {
#define VK_ENCAPSULATION_OOP_OBJECT_BEGIN(T)   template<> class Object<Vk##T> : public raii::Object<Vk##T>
#define VK_ENCAPSULATION_OOP_EXTENDED_BEGIN(T) template<> struct VK_ENCAPSULATION_NAMESPACE::oop::Extended<VK_ENCAPSULATION_NAMESPACE::oop::T> : public VK_ENCAPSULATION_NAMESPACE::oop::T

#define ParameterList(...) , __VA_ARGS__
#define DefineFunctionRaiiClass(ObjT, F, InfoT, Pars, Set, ...)                                   using PT = decltype(this); class _ : Structure<Vk##InfoT, true> { PT pObj; public: _(PT pObj Pars) : pObj(pObj) { Set; } ~_() { pObj->F(reinterpret_cast<InfoT&&>(*this)); } using Structure::AddNextStructure; DefineSetter_Copy(PNext, decltype(_::pNext), pNext) __VA_ARGS__ };
#define DefineFunctionRaiiClass_L(ObjT, F, InfoT, Pars, ArgT, arg, Set, ...)                      using PT = decltype(this); class _ : Structure<Vk##InfoT, true> { PT pObj; ArgT arg; public: _(PT pObj Pars, ArgT arg) : pObj(pObj), arg(arg) { Set; } ~_() { pObj->F(reinterpret_cast<InfoT&&>(*this), arg); } using Structure::AddNextStructure; DefineSetter_Copy(PNext, decltype(_::pNext), pNext) __VA_ARGS__ };
#define DefineFunctionRaiiClass_TwoStruct(ObjT, F, T0, T1, Pars, Set, ...)                        using PT = decltype(this); class _ : Structure<Vk##T0, true>, Structure<Vk##T1, true> { PT pObj; public: using T0 = Structure<Vk##T0, true>; using T1 = Structure<Vk##T1, true>; using T0::ArrayRef; using T0::OptionalRef; _(PT pObj Pars) : pObj(pObj) { Set; }\
auto& PNextOf##T0(decltype(T0::pNext) pNext) { T0::pNext = pNext; return *this; } auto& AddNextStructureTo##T0(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) { T0::AddNextStructure(next, allowDuplicate, ppBack); return *this; }\
auto& PNextOf##T1(decltype(T1::pNext) pNext) { T1::pNext = pNext; return *this; } auto& AddNextStructureTo##T1(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) { T1::AddNextStructure(next, allowDuplicate, ppBack); return *this; }\
~_() { pObj->F(reinterpret_cast<Structure<Vk##T0, false>&&>(static_cast<T0&>(*this)), reinterpret_cast<Structure<Vk##T1, false>&&>(static_cast<T1&>(*this))); } __VA_ARGS__ }
#define DefineFunctionRaiiClass_Result(ObjT, ResultT, F, InfoT, Pars, Set, ...)                   using PT = decltype(this); class _ : Structure<Vk##InfoT, true> { PT pObj; public: _(PT pObj Pars) : pObj(pObj) { Set; } ~_() { ResultT(*this); } using Structure::AddNextStructure; DefineSetter_Copy(PNext, decltype(_::pNext), pNext) __VA_ARGS__ \
operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; Native_T<ResultT> result = pObj->F(reinterpret_cast<InfoT&&>(*this)); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } };
#define DefineFunctionRaiiClass_ResultL(ObjT, ResultT, F, InfoT, Pars, ArgT, arg, Set, ...)       using PT = decltype(this); class _ : Structure<Vk##InfoT, true> { PT pObj; ArgT arg; public: _(PT pObj Pars, ArgT arg) : pObj(pObj), arg(arg) { Set; } ~_() { ResultT(*this); } using Structure::AddNextStructure; DefineSetter_Copy(PNext, decltype(_::pNext), pNext) __VA_ARGS__ \
operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; Native_T<ResultT> result = pObj->F(reinterpret_cast<InfoT&&>(*this), arg); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } };
#define DefineFunctionRaiiClass_ResultR(ObjT, ResultT, F, ArgT, arg, InfoT, Pars, Set, ...)       using PT = decltype(this); class _ : Structure<Vk##InfoT, true> { PT pObj; ArgT arg; public: _(PT pObj, ArgT arg Pars) : pObj(pObj), arg(arg) { Set; } ~_() { ResultT(*this); } using Structure::AddNextStructure; DefineSetter_Copy(PNext, decltype(_::pNext), pNext) __VA_ARGS__ \
operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; Native_T<ResultT> result = pObj->F(arg, reinterpret_cast<InfoT&&>(*this)); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } };
#define DefineFunctionRaiiClass_ResultPublic(ObjT, ResultT, F, InfoT)                             using PT = decltype(this); class _ : public Structure<Vk##InfoT, true> { PT pObj; public: _(PT pObj) : pObj(pObj) {} ~_() { ResultT(*this); }\
operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; Native_T<ResultT> result = pObj->F(reinterpret_cast<InfoT&&>(*this)); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } };
#define DefineFunctionRaiiClass_ResultPublicR(ObjT, ResultT, F, ArgT, arg, InfoT, Pars, Set, ...) using PT = decltype(this); class _ : public Structure<Vk##InfoT, true> { PT pObj; ArgT arg; public: _(PT pObj, ArgT arg Pars) : pObj(pObj), arg(arg) { Set; } ~_() { ResultT(*this); }\
operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; Native_T<ResultT> result = pObj->F(arg, reinterpret_cast<InfoT&&>(*this)); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } };
#define DefineSetter_Copy(F, T, var)            auto& F(Ref<const T> var) { this->var = var; return *this; }
#define DefineSetter_ArrayRef(F, T, var, count) auto& F(ArrayRef<T> var) { count = var.size(); p##F = var; return *this; }
#define ObjectClassHeader(T) using Base_T = raii::Object<Vk##T>; public: Object() = default; Extended<T>* operator->() { return reinterpret_cast<Extended<T>*>(this); } const Extended<T>* operator->() const { return reinterpret_cast<const Extended<T>*>(this); }

VK_ENCAPSULATION_OOP_NAMESPACE_BEGIN

template<typename T>
class Object;
template<typename T>
class Extended;

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Buffer) {
	ObjectClassHeader(Buffer);
	Object(const VkBufferCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkBufferCreateInfo{}) {}
	Object(DeviceSize size, BufferUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices = {}) :
		Object(BufferCreateInfo{}.Size(size).Usage(usage).QueueFamilyIndices(queueFamilyIndices)) {}
	/* Const Function */
	RESULT BindMemory(DeviceMemory_ memory, DeviceSize memoryOffset = 0) const {
		Result result = BindBufferMemory(handle, memory, memoryOffset);
		if (result)
			OutputMessage("[ vke::oop::Buffer ] ERROR\nFailed to attach the memory!\nError code: {}\n", int32_t(result));
		return result;
	}
	void GetMemoryRequirements(Ref<MemoryRequirements> memoryRequirements) const {
		GetBufferMemoryRequirements(handle, memoryRequirements);
	}
	void CmdBindIndex(DeviceSize offset = 0, IndexType indexType = VK_INDEX_TYPE_UINT16) const {
		CmdBindIndexBuffer(handle, offset, indexType);
	}
	void CmdBindVertex(uint32_t firstBinding, DeviceSize offset = 0) const {
		CmdBindVertexBuffers(firstBinding, handle, offset);
	}	
	void CmdCopyToBuffer(Buffer_ dstBuffer, ArrayRef<const BufferCopy> regions) const {
		CmdCopyBuffer(handle, dstBuffer, regions);
	}
	void CmdCopyToBuffer(Buffer_ dstBuffer, DeviceSize srcOffset, DeviceSize dstOffset, DeviceSize size) const {
		CmdCopyBuffer(handle, dstBuffer, BufferCopy{ srcOffset, dstOffset, size });
	}
	void CmdCopyToImage(Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const BufferImageCopy> regions) const {
		CmdCopyBufferToImage(handle, dstImage, dstImageLayout, regions);
	}
	void CmdCopyToImage(Image_ dstImage, ImageLayout dstImageLayout, DeviceSize bufferOffset, uint32_t bufferRowLength, uint32_t bufferImageHeight, Ref<const ImageSubresourceLayers> imageSubresource, Ref<const Offset3D> imageOffset, Ref<const Extent3D> imageExtent) const {
		CmdCopyBufferToImage(handle, dstImage, dstImageLayout, BufferImageCopy{ bufferOffset, bufferRowLength, bufferImageHeight, imageSubresource, imageOffset, imageExtent });
	}
	void CmdUpdate(DeviceSize offset, ArrayRef<const void> data) const {
		CmdUpdateBuffer(handle, offset, data);
	}
	void CmdUpdate(DeviceSize offset, const IsNotRangeOrPointer auto& data) const {
		CmdUpdateBuffer(handle, offset, data);
	}
	void CmdFill(DeviceSize offset, DeviceSize size, uint32_t data) const {
		CmdFillBuffer(handle, offset, size, data);
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_bind_memory2
	RESULT BindMemory2(const BindBufferMemoryInfo& bindInfo) const {
		auto info = BindBufferMemoryInfo{ bindInfo }.
			Buffer(handle);
		Result result = M_ConditionalDispatch(BindBufferMemory2, KHR, info);
		if (result)
			OutputMessage("[ vke::oop::Buffer ] ERROR\nFailed to attach the memory!\nError code: {}\n", int32_t(result));
		return result;
	}
	AUTO   BindMemory2(DeviceMemory_ memory, DeviceSize memoryOffset = 0) const {
		DefineFunctionRaiiClass_Result(Buffer, RESULT, BindMemory2,
			BindBufferMemoryInfo, ParameterList(DeviceMemory_ memory, DeviceSize memoryOffset),
			Memory(memory).
			MemoryOffset(memoryOffset));
		return _{ this, memory, memoryOffset };
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_get_memory_requirements2
	void GetMemoryRequirements2(const BufferMemoryRequirementsInfo2& info, Ref<MemoryRequirements2> memoryRequirements) const {
		auto _info = BufferMemoryRequirementsInfo2{ info }.
			Buffer(handle);
		M_ConditionalDispatch(GetBufferMemoryRequirements2, KHR, _info, memoryRequirements);
	}
	AUTO GetMemoryRequirements2(Ref<MemoryRequirements2> memoryRequirements) const {
		DefineFunctionRaiiClass_L(Buffer, GetMemoryRequirements2, BufferMemoryRequirementsInfo2, , Ref<MemoryRequirements2>, memoryRequirements, );
		return _{ this, memoryRequirements };
	}
	// Provided by VK_API_VERSION_1_2 or VK_KHR_buffer_device_address or VK_EXT_buffer_device_address
	DeviceAddress GetDeviceAddress(const BufferDeviceAddressInfo& info) const {
		auto _info = BufferDeviceAddressInfo{ info }.
			Buffer(handle);
		return vkGetBufferDeviceAddress ?
			VK_ENCAPSULATION_NAMESPACE::GetBufferDeviceAddress(_info) : (
				vkGetBufferDeviceAddressKHR ?
				VK_ENCAPSULATION_NAMESPACE::GetBufferDeviceAddressKHR(_info) :
				VK_ENCAPSULATION_NAMESPACE::GetBufferDeviceAddressEXT(_info));
	}
	AUTO          GetDeviceAddress() const {
		DefineFunctionRaiiClass_Result(Buffer, DeviceAddress, GetDeviceAddress, BufferDeviceAddressInfo, , );
		return _{ this };
	}
	// Provided by VK_API_VERSION_1_2 or VK_KHR_buffer_device_address
	uint64_t GetOpaqueCaptureAddress(const BufferDeviceAddressInfo& info) const {
		auto _info = BufferDeviceAddressInfo{ info }.
			Buffer(handle);
		return M_ConditionalDispatch(GetBufferOpaqueCaptureAddress, KHR, _info);
	}
	AUTO     GetOpaqueCaptureAddress() const {
		DefineFunctionRaiiClass_Result(Buffer, uint64_t, GetOpaqueCaptureAddress, BufferDeviceAddressInfo, , );
		return _{ this };
	}
	// Provided by VK_API_VERSION_1_3 or VK_KHR_copy_commands2
	void CmdCopyToBuffer2(const CopyBufferInfo2& copyBufferInfo) const {
		auto info = CopyBufferInfo2{ copyBufferInfo }.
			SrcBuffer(handle);
		M_ConditionalDispatch(CmdCopyBuffer2, KHR, info);
	}
	AUTO CmdCopyToBuffer2(Buffer_ dstBuffer, ArrayRef<const BufferCopy2> regions) const {
		DefineFunctionRaiiClass(Buffer, CmdCopyToBuffer2,
			CopyBufferInfo2, ParameterList(Buffer_ dstBuffer, ArrayRef<const BufferCopy2> regions),
			DstBuffer(dstBuffer).
			Regions(regions));
		return _{ this, dstBuffer, regions };
	}
	void CmdCopyToImage2(const CopyBufferToImageInfo2& copyBufferToImageInfo) const {
		auto info = CopyBufferToImageInfo2{ copyBufferToImageInfo }.
			SrcBuffer(handle);
		M_ConditionalDispatch(CmdCopyBufferToImage2, KHR, info);
	}
	AUTO CmdCopyToImage2(Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const BufferImageCopy2> regions) const {
		DefineFunctionRaiiClass(Buffer, CmdCopyToImage2,
			CopyBufferToImageInfo2, ParameterList(Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const BufferImageCopy2> regions),
			DstImage(dstImage).
			DstImageLayout(dstImageLayout).
			Regions(regions));
		return _{ this, dstImage, dstImageLayout, regions };
	}
	// Provided by VK_API_VERSION_1_3 or VK_EXT_extended_dynamic_state or VK_EXT_shader_object
	void CmdBindVertex2(uint32_t firstBinding, DeviceSize offset = 0, OptionalValue<DeviceSize> size = {}, OptionalValue<DeviceSize> stride = {}) const {
		M_ConditionalDispatch(CmdBindVertexBuffers2, EXT, firstBinding, handle, offset, { 0, &size }, { 0, &stride });
	}
	// Provided by VK_API_VERSION_1_4 or VK_KHR_maintenance5
	void CmdBindIndex2(DeviceSize offset = 0, DeviceSize size = VK_WHOLE_SIZE, IndexType indexType = VK_INDEX_TYPE_UINT16) const {
		M_ConditionalDispatch(CmdBindIndexBuffer2, KHR, handle, offset, size, indexType);
	}
	// ======== Encapsulation for common usage
	MemoryAllocateInfo MemoryAllocateInfo(MemoryPropertyFlags desiredMemoryProperties) const {
		MemoryRequirements memoryRequirements;
		GetMemoryRequirements(memoryRequirements);
		auto GetMemoryTypeIndex = [](uint32_t memoryTypeBits, MemoryPropertyFlags desiredMemoryProperties) {
			auto& physicalDeviceMemoryProperties = VkeApp::Base().PhysicalDevice().MemoryProperties();
			for (uint32_t i = 0; i < physicalDeviceMemoryProperties.memoryTypeCount; i++)
				if (memoryTypeBits & 1 << i &&
					(physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & desiredMemoryProperties) == desiredMemoryProperties)
					return i;
			return UINT32_MAX;
		};
		return MemoryAllocateInfo_{}.
			AllocationSize(memoryRequirements.size).
			MemoryTypeIndex(GetMemoryTypeIndex(memoryRequirements.memoryTypeBits, desiredMemoryProperties));
	}
	/* Non-const Function */
	RESULT Create(const BufferCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Buffer ] ERROR\nFailed to create a buffer!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(DeviceSize size, BufferUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices = {}) {
		DefineFunctionRaiiClass_Result(Buffer, RESULT, Create,
			BufferCreateInfo, ParameterList(DeviceSize size, BufferUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices),
			Size(size).
			Usage(usage).
			QueueFamilyIndices(queueFamilyIndices),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, size, usage, queueFamilyIndices };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(Buffer, RESULT, Create, BufferCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Image) {
	ObjectClassHeader(Image);
	Object(const VkImageCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkImageCreateInfo{}) {}
	Object(ImageType imageType, Format format, Ref<const Extent3D> extent, uint32_t mipLevels, uint32_t arrayLayers, SampleCountFlagBits samples, ImageTiling tiling, ImageUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices = {}, ImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED) :
		Object(ImageCreateInfo{}.ImageType(imageType).Format(format).Extent(extent).MipLevels(mipLevels).ArrayLayers(arrayLayers).Samples(samples).Tiling(tiling).Usage(usage).QueueFamilyIndices(queueFamilyIndices).InitialLayout(initialLayout)) {}
	/* Const Function */
	RESULT BindMemory(DeviceMemory_ memory, DeviceSize memoryOffset = 0) const {
		Result result = BindImageMemory(handle, memory, memoryOffset);
		if (result)
			OutputMessage("[ vke::oop::Image ] ERROR\nFailed to attach the memory!\nError code: {}\n", int32_t(result));
		return result;
	}
	void GetMemoryRequirements(Ref<MemoryRequirements> memoryRequirements) const {
		GetImageMemoryRequirements(handle, memoryRequirements);
	}
	void GetSparseMemoryRequirements(IsDynamicArray<SparseImageMemoryRequirements> auto& sparseMemoryRequirements) const {
		GetImageSparseMemoryRequirements(handle, sparseMemoryRequirements);
	}
	void GetSubresourceLayout(Ref<const ImageSubresource> subresource, Ref<SubresourceLayout> layout) const {
		GetImageSubresourceLayout(handle, subresource, layout);
	}
	void GetSubresourceLayout(ImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t arrayLayer, Ref<SubresourceLayout> layout) const {
		GetImageSubresourceLayout(handle, ImageSubresource{}.AspectMask(aspectMask).MipLevel(mipLevel).ArrayLayer(arrayLayer), layout);
	}
	void CmdCopyToImage(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageCopy> regions) const {
		CmdCopyImage(handle, srcImageLayout, dstImage, dstImageLayout, regions);
	}
	void CmdCopyToImage(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, Ref<const ImageSubresourceLayers> srcSubresource, Ref<const Offset3D> srcOffset, Ref<const ImageSubresourceLayers> dstSubresource, Ref<const Offset3D> dstOffset, Ref<const Extent3D> extent) const {
		CmdCopyImage(handle, srcImageLayout, dstImage, dstImageLayout, ImageCopy{ srcSubresource, srcOffset, dstSubresource, dstOffset, extent });
	}
	void CmdBlitToImage(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageBlit> regions, Filter filter) const {
		CmdBlitImage(handle, srcImageLayout, dstImage, dstImageLayout, regions, filter);
	}
	void CmdBlitToImage(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, Ref<const ImageSubresourceLayers> srcSubresource, ArrayRef<const Offset3D> srcOffsets, Ref<const ImageSubresourceLayers> dstSubresource, ArrayRef<const Offset3D> dstOffsets, Filter filter) const {
		CmdBlitImage(handle, srcImageLayout, dstImage, dstImageLayout, ImageBlit{}.SrcSubresource(srcSubresource).SrcOffsets(srcOffsets).DstSubresource(dstSubresource).DstOffsets(dstOffsets), filter);
	}
	void CmdCopyToBuffer(ImageLayout srcImageLayout, Buffer_ dstBuffer, ArrayRef<const BufferImageCopy> regions) const {
		CmdCopyImageToBuffer(handle, srcImageLayout, dstBuffer, regions);
	}
	void CmdCopyToBuffer(ImageLayout srcImageLayout, Buffer_ dstBuffer, DeviceSize bufferOffset, uint32_t bufferRowLength, uint32_t bufferImageHeight, Ref<const ImageSubresourceLayers> imageSubresource, Ref<const Offset3D> imageOffset, Ref<const Extent3D> imageExtent) const {
		CmdCopyImageToBuffer(handle, srcImageLayout, dstBuffer, BufferImageCopy{ bufferOffset, bufferRowLength, bufferImageHeight, imageSubresource, imageOffset, imageExtent });
	}
	void CmdClearColor(ImageLayout imageLayout, Ref<const ClearColorValue> color, ArrayRef<const ImageSubresourceRange> ranges) const {
		CmdClearColorImage(handle, imageLayout, color, ranges);
	}
	void CmdClearDepthStencil(ImageLayout imageLayout, const ClearDepthStencilValue& depthStencil, ArrayRef<const ImageSubresourceRange> ranges) const {
		CmdClearDepthStencilImage(handle, imageLayout, depthStencil, ranges);
	}
	void CmdResolve(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageResolve> regions) const {
		CmdResolveImage(handle, srcImageLayout, dstImage, dstImageLayout, regions);
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_bind_memory2
	RESULT BindMemory2(const BindImageMemoryInfo& bindInfo) const {
		auto info = BindImageMemoryInfo{ bindInfo }.
			Image(handle);
		Result result = M_ConditionalDispatch(BindImageMemory2, KHR, info);
		if (result)
			OutputMessage("[ vke::oop::Image ] ERROR\nFailed to attach the memory!\nError code: {}\n", int32_t(result));
		return result;
	}
	AUTO   BindMemory2(DeviceMemory_ memory, DeviceSize memoryOffset = 0) const {
		DefineFunctionRaiiClass_Result(Image, RESULT, BindMemory2,
			BindImageMemoryInfo, ParameterList(DeviceMemory_ memory, DeviceSize memoryOffset),
			Memory(memory).
			MemoryOffset(memoryOffset));
		return _{ this, memory, memoryOffset };
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_get_memory_requirements2
	void GetMemoryRequirements2(const ImageMemoryRequirementsInfo2& info, Ref<MemoryRequirements2> memoryRequirements) const {
		auto _info = ImageMemoryRequirementsInfo2{ info }.
			Image(handle);
		M_ConditionalDispatch(GetImageMemoryRequirements2, KHR, _info, memoryRequirements);
	}
	AUTO GetMemoryRequirements2(Ref<MemoryRequirements2> memoryRequirements) const {
		DefineFunctionRaiiClass_L(Image, GetMemoryRequirements2, ImageMemoryRequirementsInfo2, , Ref<MemoryRequirements2>, memoryRequirements, );
		return _{ this, memoryRequirements };
	}
	void GetSparseMemoryRequirements2(const ImageSparseMemoryRequirementsInfo2& info, IsDynamicArray<SparseImageMemoryRequirements2> auto& sparseMemoryRequirements) const {
		auto _info = ImageSparseMemoryRequirementsInfo2{ info }.
			Image(handle);
		M_ConditionalDispatch(GetImageSparseMemoryRequirements2, KHR, _info, sparseMemoryRequirements);
	}
	AUTO GetSparseMemoryRequirements2(IsDynamicArray<SparseImageMemoryRequirements2> auto& sparseMemoryRequirements) const {
		using ArgT = decltype(sparseMemoryRequirements);
		DefineFunctionRaiiClass_L(Image, GetSparseMemoryRequirements2, ImageSparseMemoryRequirementsInfo2, , ArgT, sparseMemoryRequirements, );
		return _{ this, sparseMemoryRequirements };
	}
	// Provided by VK_API_VERSION_1_3 or VK_KHR_copy_commands2
	void CmdCopyToImage2(const CopyImageInfo2& copyImageInfo) const {
		auto info = CopyImageInfo2{ copyImageInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CmdCopyImage2, KHR, info);
	}
	AUTO CmdCopyToImage2(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageCopy2> regions) const {
		DefineFunctionRaiiClass(Image, CmdCopyToImage2,
			CopyImageInfo2, ParameterList(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageCopy2> regions),
			SrcImageLayout(srcImageLayout).
			DstImage(dstImage).
			DstImageLayout(dstImageLayout).
			Regions(regions));
		return _{ this, srcImageLayout, dstImage, dstImageLayout, regions };
	}
	void CmdCopyToBuffer2(const CopyImageToBufferInfo2& copyImageToBufferInfo) const {
		auto info = CopyImageToBufferInfo2{ copyImageToBufferInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CmdCopyImageToBuffer2, KHR, info);
	}
	AUTO CmdCopyToBuffer2(ImageLayout srcImageLayout, Buffer_ dstBuffer, ArrayRef<const BufferImageCopy2> regions) const {
		DefineFunctionRaiiClass(Image, CmdCopyToBuffer2,
			CopyImageToBufferInfo2, ParameterList(ImageLayout srcImageLayout, Buffer_ dstBuffer, ArrayRef<const BufferImageCopy2> regions),
			SrcImageLayout(srcImageLayout).
			DstBuffer(dstBuffer).
			Regions(regions));
		return _{ this, srcImageLayout, dstBuffer, regions };
	}
	void CmdBlitToImage2(const BlitImageInfo2& blitImageInfo) const {
		auto info = BlitImageInfo2{ blitImageInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CmdBlitImage2, KHR, info);
	}
	AUTO CmdBlitToImage2(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageBlit2> regions, Filter filter) const {
		DefineFunctionRaiiClass(Image, CmdBlitToImage2,
			BlitImageInfo2, ParameterList(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageBlit2> regions, Filter_ filter),
			SrcImageLayout(srcImageLayout).
			DstImage(dstImage).
			DstImageLayout(dstImageLayout).
			Regions(regions).
			Filter(filter));
		return _{ this, srcImageLayout, dstImage, dstImageLayout, regions, filter };
	}
	void CmdResolve2(const ResolveImageInfo2& resolveImageInfo) const {
		auto info = ResolveImageInfo2{ resolveImageInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CmdResolveImage2, KHR, info);
	}
	AUTO CmdResolve2(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageResolve2> regions) const {
		DefineFunctionRaiiClass(Image, CmdResolve2,
			ResolveImageInfo2, ParameterList(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageResolve2> regions),
			SrcImageLayout(srcImageLayout).
			DstImage(dstImage).
			DstImageLayout(dstImageLayout).
			Regions(regions));
		return _{ this, srcImageLayout, dstImage, dstImageLayout, regions };
	}
	// Provided by VK_API_VERSION_1_4 or VK_KHR_maintenance5 or VK_EXT_host_image_copy or VK_EXT_image_compression_control
	void GetSubresourceLayout2(const ImageSubresource2& subresource, Ref<SubresourceLayout2> layout) const {
		return vkGetImageSubresourceLayout2 ?
			VK_ENCAPSULATION_NAMESPACE::GetImageSubresourceLayout2(handle, subresource, layout) : (
				vkGetImageSubresourceLayout2KHR ?
				VK_ENCAPSULATION_NAMESPACE::GetImageSubresourceLayout2KHR(handle, subresource, layout) :
				VK_ENCAPSULATION_NAMESPACE::GetImageSubresourceLayout2EXT(handle, subresource, layout));
	}
	AUTO GetSubresourceLayout2(ImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t arrayLayer, Ref<SubresourceLayout2> layout) const {
		DefineFunctionRaiiClass_L(Image, GetSubresourceLayout2,
			ImageSubresource2, ParameterList(ImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t arrayLayer),
			Ref<SubresourceLayout2>, layout,
			ImageSubresource({ aspectMask, mipLevel, arrayLayer }));
		return _{ this, aspectMask, mipLevel, arrayLayer, layout };
	}
	// Provided by VK_API_VERSION_1_4 or VK_EXT_host_image_copy
	RESULT CopyToImage(const CopyImageToImageInfo& copyImageToImageInfo) const {
		auto info = CopyImageToImageInfo{ copyImageToImageInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CopyImageToImage, EXT, info);
	}
	AUTO   CopyToImage(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageCopy2> regions) const {
		DefineFunctionRaiiClass(Image, CopyToImage,
			CopyImageToImageInfo, ParameterList(ImageLayout srcImageLayout, Image_ dstImage, ImageLayout dstImageLayout, ArrayRef<const ImageCopy2> regions),
			SrcImageLayout(srcImageLayout).
			DstImage(dstImage).
			DstImageLayout(dstImageLayout).
			Regions(regions),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, srcImageLayout, dstImage, dstImageLayout, regions };
	}
	RESULT CopyToMemory(const CopyImageToMemoryInfo& copyImageToMemoryInfo) const {
		auto info = CopyImageToMemoryInfo{ copyImageToMemoryInfo }.
			SrcImage(handle);
		M_ConditionalDispatch(CopyImageToMemory, EXT, info);
	}
	AUTO   CopyToMemory(ImageLayout srcImageLayout, ArrayRef<const ImageToMemoryCopy> regions) const {
		DefineFunctionRaiiClass(Image, CopyToMemory,
			CopyImageToMemoryInfo, ParameterList(ImageLayout srcImageLayout, ArrayRef<const ImageToMemoryCopy> regions),
			SrcImageLayout(srcImageLayout).
			Regions(regions),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, srcImageLayout, regions };
	}
	RESULT CopyFromMemory(const CopyMemoryToImageInfo& copyMemoryToImageInfo) const {
		auto info = CopyMemoryToImageInfo{ copyMemoryToImageInfo }.
			DstImage(handle);
		M_ConditionalDispatch(CopyMemoryToImage, EXT, info);
	}
	AUTO   CopyFromMemory(ImageLayout dstImageLayout, ArrayRef<const MemoryToImageCopy> regions) const {
		DefineFunctionRaiiClass(Image, CopyFromMemory,
			CopyMemoryToImageInfo, ParameterList(ImageLayout dstImageLayout, ArrayRef<const MemoryToImageCopy> regions),
			DstImageLayout(dstImageLayout).
			Regions(regions),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, dstImageLayout, regions };
	}
	RESULT TransitionLayout(const HostImageLayoutTransitionInfo& transition) const {
		auto info = HostImageLayoutTransitionInfo{ transition }.
			Image(handle);
		Result result = M_ConditionalDispatch(TransitionImageLayout, EXT, info);
		if (result)
			OutputMessage("[ vke::oop::Image ] ERROR\nFailed to transition the layout of the image!\nError code: {}\n", int32_t(result));
		return result;
	}
	AUTO   TransitionLayout(ImageLayout oldLayout, ImageLayout newLayout, Ref<const ImageSubresourceRange> subresourceRange) const {
		DefineFunctionRaiiClass_Result(Image, RESULT, TransitionLayout,
			HostImageLayoutTransitionInfo, ParameterList(ImageLayout oldLayout, ImageLayout newLayout, Ref<const ImageSubresourceRange> subresourceRange),
			OldLayout(oldLayout).
			NewLayout(newLayout).
			SubresourceRange(subresourceRange));
		return _{ this, oldLayout, newLayout, subresourceRange };
	}
	// ======== Encapsulation for common usage
	MemoryAllocateInfo MemoryAllocateInfo(MemoryPropertyFlags desiredMemoryProperties) const {
		MemoryRequirements memoryRequirements;
		GetMemoryRequirements(memoryRequirements);
		auto GetMemoryTypeIndex = [](uint32_t memoryTypeBits, MemoryPropertyFlags desiredMemoryProperties) {
			auto& physicalDeviceMemoryProperties = VkeApp::Base().PhysicalDevice().MemoryProperties();
			for (uint32_t i = 0; i < physicalDeviceMemoryProperties.memoryTypeCount; i++)
				if (memoryTypeBits & 1 << i &&
					(physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & desiredMemoryProperties) == desiredMemoryProperties)
					return i;
			return UINT32_MAX;
		};
		uint32_t memoryTypeIndex = GetMemoryTypeIndex(memoryRequirements.memoryTypeBits, desiredMemoryProperties);
		// The GPU and its driver may not support lazy allocation.
		if (memoryTypeIndex == UINT32_MAX &&
			desiredMemoryProperties & VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT)
			memoryTypeIndex = GetMemoryTypeIndex(memoryRequirements.memoryTypeBits, desiredMemoryProperties & ~VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
		return MemoryAllocateInfo_{}.
			AllocationSize(memoryRequirements.size).
			MemoryTypeIndex(memoryTypeIndex);
	}
	/* Non-const Function */
	RESULT Create(const ImageCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Image ] ERROR\nFailed to create an image!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ImageType imageType, Format format, Ref<const Extent3D> extent, uint32_t mipLevels, uint32_t arrayLayers, SampleCountFlagBits samples, ImageTiling tiling, ImageUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices = {}, ImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED) {
		DefineFunctionRaiiClass_Result(Image, RESULT, Create,
			ImageCreateInfo, ParameterList(ImageType_ imageType, Format_ format, Ref<const Extent3D> extent, uint32_t mipLevels, uint32_t arrayLayers, SampleCountFlagBits samples, ImageTiling tiling, ImageUsageFlags usage, ArrayRef<const uint32_t> queueFamilyIndices, ImageLayout initialLayout),
			ImageType(imageType).
			Format(format).
			Extent(extent).
			MipLevels(mipLevels).
			ArrayLayers(arrayLayers).
			Samples(samples).
			Tiling(tiling).
			Usage(usage).
			QueueFamilyIndices(queueFamilyIndices).
			InitialLayout(initialLayout),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, imageType, format, extent, mipLevels, arrayLayers, samples, tiling, usage, queueFamilyIndices, initialLayout };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(Image, RESULT, Create, ImageCreateInfo);
		return _{ this };
	}
};

//VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Instance) {};

//VK_ENCAPSULATION_OOP_OBJECT_BEGIN(PhysicalDevice) {};

//VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Device) {};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Queue) {
	ObjectClassHeader(Queue);
	Object(uint32_t queueFamilyIndex, uint32_t queueIndex) {
		Get(queueFamilyIndex, queueIndex);
	}
	Object(EmptyList) :
		Object(0, 0) {}
	Object(const VkDeviceQueueInfo2& queueInfo) {
		Get2(queueInfo);
	}
	/* Const Function */
	RESULT Submit(ArrayRef<const SubmitInfo> submits, Fence_ fence = VK_NULL_HANDLE) const {
		Result result = QueueSubmit(handle, submits, fence);
		if (result)
			OutputMessage("[ vke::oop::Queue ] ERROR\nFailed to submit command buffers!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Submit(ArrayRef<const Semaphore_> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer_> commandBuffers, ArrayRef<const Semaphore_> signalSemaphores, Fence_ fence = VK_NULL_HANDLE) const {
		DefineFunctionRaiiClass_ResultL(Queue, RESULT, Submit,
			SubmitInfo, ParameterList(ArrayRef<const Semaphore_> waitSemaphores, ArrayRef<const PipelineStageFlags> waitDstStageMasks, ArrayRef<const CommandBuffer_> commandBuffers, ArrayRef<const Semaphore_> signalSemaphores),
			Fence_, fence,
			WaitSemaphores(waitSemaphores).
			WaitDstStageMask(waitDstStageMasks).
			CommandBuffers(commandBuffers).
			SignalSemaphores(signalSemaphores));
		return _{ this, waitSemaphores, waitDstStageMasks, commandBuffers, signalSemaphores, fence };
	}
	RESULT WaitIdle() const {
		Result result = QueueWaitIdle(handle);
		if (result)
			OutputMessage("[ vke::oop::Queue ] ERROR\nFailed to wait for the queue to be idle!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT BindSparse(ArrayRef<const BindSparseInfo> bindInfos, Fence_ fence = VK_NULL_HANDLE) const {
		Result result = QueueBindSparse(handle, bindInfos, fence);
		if (result)
			OutputMessage("[ vke::oop::Queue ] ERROR\nFailed to submit sparse binding operations!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   BindSparse(ArrayRef<const Semaphore_> waitSemaphores, ArrayRef<const SparseBufferMemoryBindInfo> bufferBinds, ArrayRef<const SparseImageOpaqueMemoryBindInfo> imageOpaqueBinds, ArrayRef<const SparseImageMemoryBindInfo> imageBinds, ArrayRef<const Semaphore_> signalSemaphores, Fence_ fence = VK_NULL_HANDLE) const {
		DefineFunctionRaiiClass_ResultL(Queue, RESULT, BindSparse,
			BindSparseInfo, ParameterList(ArrayRef<const Semaphore_> waitSemaphores, ArrayRef<const SparseBufferMemoryBindInfo> bufferBinds, ArrayRef<const SparseImageOpaqueMemoryBindInfo> imageOpaqueBinds, ArrayRef<const SparseImageMemoryBindInfo> imageBinds, ArrayRef<const Semaphore_> signalSemaphores),
			Fence_, fence,
			WaitSemaphores(waitSemaphores).
			BufferBinds(bufferBinds).
			ImageOpaqueBinds(imageOpaqueBinds).
			ImageBinds(imageBinds).
			SignalSemaphores(signalSemaphores));
		return _{ this, waitSemaphores, bufferBinds, imageOpaqueBinds, imageBinds, signalSemaphores, fence };
	}
	// Provided by VK_API_VERSION_1_3 or VK_KHR_synchronization2
	RESULT Submit2(ArrayRef<const SubmitInfo2> submits, Fence_ fence = VK_NULL_HANDLE) const {
		Result result = QueueSubmit2(handle, submits, fence);
		if (result)
			OutputMessage("[ vke::oop::Queue ] ERROR\nFailed to submit command buffers!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Submit2(ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos, Fence_ fence = VK_NULL_HANDLE) const {
		DefineFunctionRaiiClass_ResultL(Queue, RESULT, Submit2,
			SubmitInfo2, ParameterList(ArrayRef<const SemaphoreSubmitInfo> waitSemaphoreInfos, ArrayRef<const CommandBufferSubmitInfo> commandBufferInfos, ArrayRef<const SemaphoreSubmitInfo> signalSemaphoreInfos),
			Fence_, fence,
			WaitSemaphoreInfos(waitSemaphoreInfos).
			CommandBufferInfos(commandBufferInfos).
			SignalSemaphoreInfos(signalSemaphoreInfos),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, waitSemaphoreInfos, commandBufferInfos, signalSemaphoreInfos, fence };
	}
	/* Non-const Function */
	void Get(uint32_t queueFamilyIndex, uint32_t queueIndex) {
		Base_T::Get(queueFamilyIndex, queueIndex);
	}
	// Provided by VK_API_VERSION_1_1
	void Get2(const DeviceQueueInfo2& queueInfo) {
		Base_T::Get2(queueInfo);
	}
	AUTO Get2(uint32_t queueFamilyIndex, uint32_t queueIndex) {
		DefineFunctionRaiiClass(Queue, Get2,
			DeviceQueueInfo2, ParameterList(uint32_t queueFamilyIndex, uint32_t queueIndex),
			QueueFamilyIndex(queueFamilyIndex).
			QueueIndex(queueFamilyIndex),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, queueFamilyIndex, queueFamilyIndex };
	}
	AUTO Get2() {
		DefineFunctionRaiiClass(Queue, Get2, DeviceQueueInfo2, , ,
			DefineSetter_Copy(Flags, decltype(_::flags), flags)
			DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex)
			DefineSetter_Copy(QueueIndex, uint32_t, queueIndex));
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Semaphore) {
	ObjectClassHeader(Semaphore);
	Object(const VkSemaphoreCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkSemaphoreCreateInfo{}) {}
	// ======== For timeline semaphore
	// Provided by VK_API_VERSION_1_2 or VK_KHR_timeline_semaphore
	Object(const VkSemaphoreTypeCreateInfo& typeCreateInfo) {
		Create(typeCreateInfo);
	}
	Object(uint64_t initialValue) :
		Object(SemaphoreTypeCreateInfo{}.SemaphoreType(VK_SEMAPHORE_TYPE_TIMELINE).InitialValue(initialValue)) {}
	/* Const Function */
	// ======== For timeline semaphore
	// Provided by VK_API_VERSION_1_2 or VK_KHR_timeline_semaphore
	RESULT GetCounterValue(uint64_t& value) const {
		Result result = M_ConditionalDispatch(GetSemaphoreCounterValue, KHR, handle, value);
		if (result)
			OutputMessage("[ vke::oop::Semaphore ] ERROR\nFailed to query the counter value!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Wait(const SemaphoreWaitInfo& waitInfo, uint64_t timeout = UINT64_MAX) {
		auto info = SemaphoreWaitInfo{ waitInfo }.
			Semaphores(handle);
		Result result = M_ConditionalDispatch(WaitSemaphores, KHR, info, timeout);
		if (result)
			OutputMessage("[ vke::oop::Semaphore ] ERROR\nFailed to wait for the semaphore!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Wait(uint64_t value, uint64_t timeout = UINT64_MAX) {
		DefineFunctionRaiiClass_ResultL(Semaphore, RESULT, Wait,
			SemaphoreWaitInfo, ParameterList(uint64_t value),
			uint64_t, timeout,
			Values(value),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, value, timeout };
	}
	RESULT Signal(const SemaphoreSignalInfo& signalInfo) {
		auto info = SemaphoreSignalInfo{ signalInfo }.
			Semaphore(handle);
		Result result = M_ConditionalDispatch(SignalSemaphore, KHR, info);
		if (result)
			OutputMessage("[ vke::oop::Semaphore ] ERROR\nFailed to signal the semaphore!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Signal(uint64_t value) {
		DefineFunctionRaiiClass_Result(Semaphore, RESULT, Signal,
			SemaphoreSignalInfo, ParameterList(uint64_t value),
			Value(value));
		return _{ this, value };
	}
	/* Non-const Function */
	RESULT Create(const SemaphoreCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Semaphore ] ERROR\nFailed to create a semaphore!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_Result(Semaphore, RESULT, Create, SemaphoreCreateInfo, , ,
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this };
	}
	// ======== For timeline semaphore
	// Provided by VK_API_VERSION_1_2 or VK_KHR_timeline_semaphore
	RESULT Create(const SemaphoreTypeCreateInfo& typeCreateInfo) {
		return Create(SemaphoreCreateInfo{}.PNext(&typeCreateInfo));
	}
	AUTO   Create(uint64_t initialValue) {
		DefineFunctionRaiiClass_Result(Semaphore, RESULT, Create,
			SemaphoreTypeCreateInfo, ParameterList(uint64_t initialValue),
			SemaphoreType(VK_SEMAPHORE_TYPE_TIMELINE).
			InitialValue(initialValue));
		return _{ this, initialValue };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(CommandBuffer) {
	ObjectClassHeader(CommandBuffer);
	/* Const Function */
	RESULT Begin(const CommandBufferBeginInfo& beginInfo) const {
		Result result = BeginCommandBuffer(handle, beginInfo);
		if (result)
			OutputMessage("[ vke::oop::CommandBuffer ] ERROR\nFailed to begin recording the command buffer!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Begin(OptionalRef<const CommandBufferInheritanceInfo> inheritanceInfo = {}) const {
		DefineFunctionRaiiClass_Result(CommandBuffer, RESULT, Begin,
			CommandBufferBeginInfo, ParameterList(OptionalRef<const CommandBufferInheritanceInfo> inheritanceInfo),
			InheritanceInfo(inheritanceInfo),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, inheritanceInfo };
	}
	RESULT End() const {
		Result result = vkEndCommandBuffer(handle);
		if (result)
			OutputMessage("[ vke::oop::CommandBuffer ] ERROR\nFailed to end recording the command buffer!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Reset(CommandBufferResetFlags flags = 0) const {
		Result result = ResetCommandBuffer(handle, flags);
		if (result)
			OutputMessage("[ vke::oop::CommandBuffer ] ERROR\nFailed to reset the command buffer!\nError code: {}\n", string_VkResult(result));
		return result;
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Fence) {
	ObjectClassHeader(Fence);
	Object(const VkFenceCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkFenceCreateInfo{}) {}
	/* Const Function */
	RESULT Reset() const {
		Result result = ResetFences(handle);
		if (result)
			OutputMessage("[ vke::oop::Fence ] ERROR\nFailed to reset the fence!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Status() const {
		Result result = GetFenceStatus(handle);
		if (result < 0)
			OutputMessage("[ vke::oop::Fence ] ERROR\nFailed to query the status!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Wait(uint64_t timeout = UINT64_MAX) const {
		Result result = WaitForFences(handle, false, timeout);
		if (result)
			OutputMessage("[ vke::oop::Fence ] ERROR\nFailed to wait for the fence!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	// ======== Encapsulation for common usage
	RESULT WaitAndReset(uint64_t timeout = UINT64_MAX) const {
		Result result = Wait(timeout);
		result || (result = Reset());
		return result;
	}
	/* Non-const Function */
	RESULT Create(const FenceCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Fence ] ERROR\nFailed to create a fence!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_Result(Fence, RESULT, Create, FenceCreateInfo, , ,
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(DeviceMemory) {
	ObjectClassHeader(DeviceMemory);
	Object(const VkMemoryAllocateInfo& allocateInfo) {
		Allocate(allocateInfo);
	}
	Object(EmptyList) :
		Object(VkMemoryAllocateInfo{}) {}
	Object(DeviceSize allocationSize, uint32_t memoryTypeIndex) :
		Object(MemoryAllocateInfo{}.AllocationSize(allocationSize).MemoryTypeIndex(memoryTypeIndex)) {}
	Object(Object&& other) noexcept {
		Move_Internal(std::move(other));
	}
	~Object() { allocationSize = 0; memoryProperties = 0; }
	/* Getter */
	const DeviceSize& AllocationSize() const { return allocationSize; }
	const MemoryPropertyFlags& MemoryProperties() const { return memoryProperties; }
	/* Const Function */
	// ======== For host-visible memory
	RESULT Map(DeviceSize offset, DeviceSize size, MemoryMapFlags flags, void*& pData) const {
		DeviceSize inverseDeltaOffset;
		if (!(memoryProperties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
			inverseDeltaOffset = AdjustNonCoherentMemoryRange(size, offset);
		if (Result result = MapMemory(handle, offset, size, flags, pData)) {
			OutputMessage("[ vke::oop::DeviceMemory ] ERROR\nFailed to map the memory!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		if (!(memoryProperties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) {
			pData = static_cast<uint8_t*>(pData) + inverseDeltaOffset;
			if (Result result = InvalidateMappedMemoryRanges(MappedMemoryRange{}.Memory(handle).Offset(offset).Size(size))) {
				OutputMessage("[ vke::oop::DeviceMemory ] ERROR\nFailed to flush the memory!\nError code: {}\n", string_VkResult(result));
				return result;
			}
		}
		return VK_SUCCESS;
	}
	RESULT Unmap(DeviceSize offset, DeviceSize size) const {
		if (!(memoryProperties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) {
			AdjustNonCoherentMemoryRange(offset, size);
			if (Result result = FlushMappedMemoryRanges(MappedMemoryRange{}.Memory(handle).Offset(offset).Size(size))) {
				OutputMessage("[ vke::oop::DeviceMemory ] ERROR\nFailed to flush the memory!\nError code: {}\n", string_VkResult(result));
				return result;
			}
		}
		UnmapMemory(handle);
		return VK_SUCCESS;
	}
	// Provided by VK_API_VERSION_1_4 or VK_KHR_map_memory2
	RESULT Map2(const MemoryMapInfo& memoryMapInfo, void*& pData) const {
		auto info = MemoryMapInfo{ memoryMapInfo }.
			Memory(handle);
		return M_ConditionalDispatch(MapMemory2, KHR, info, pData);
	}
	AUTO   Map2(DeviceSize offset, DeviceSize size, void*& pData) const {
		DefineFunctionRaiiClass_ResultL(DeviceMemory, RESULT, Map2,
			MemoryMapInfo, ParameterList(DeviceSize offset, DeviceSize size),
			void*&, pData,
			Offset(offset).
			Size(size),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, offset, size, pData };
	}
	RESULT Unmap2(const MemoryUnmapInfo& memoryUnmapInfo) const {
		auto info = MemoryUnmapInfo{ memoryUnmapInfo }.
			Memory(handle);
		return M_ConditionalDispatch(UnmapMemory2, KHR, info);
	}
	AUTO   Unmap2() const {
		DefineFunctionRaiiClass_Result(DeviceMemory, RESULT, Unmap2, MemoryUnmapInfo, , ,
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this };
	}
	// ======== Encapsulation for common usage
	RESULT BufferData(ArrayRef<const void> data, DeviceSize offset = 0, MemoryMapFlags flags = 0) const {
		void* pDst;
		if (Result result = Map(offset, data.size(), flags, pDst))
			return result;
		std::memcpy(pDst, data, data.size());
		return Unmap(data.size(), offset);
	}
	RESULT BufferData(const IsNotRangeOrPointer auto& data, DeviceSize offset = 0, MemoryMapFlags flags = 0) const {
		return BufferData({ sizeof *&data, &data }, offset, flags);
	}
	RESULT RetrieveData(ArrayRef<void> data, DeviceSize offset = 0, MemoryMapFlags flags = 0) const {
		void* pSrc;
		if (Result result = Map(offset, data.size(), flags, pSrc))
			return result;
		std::memcpy(data, pSrc, data.size());
		return Unmap(data.size(), offset);
	}
	RESULT RetrieveData(IsNotRangeOrPointer auto& data, DeviceSize offset = 0, MemoryMapFlags flags = 0) const {
		return RetrieveData({ sizeof *&data, &data }, offset, flags);
	}
	// ======== For lazily-allocated memory
	DeviceSize Commitment() {
		DeviceSize committedMemoryInBytes;
		GetDeviceMemoryCommitment(handle, committedMemoryInBytes);
		return committedMemoryInBytes;
	}
	/* Non-const Function */
	Object& operator=(Object&& other) noexcept {
		this->~Object();
		Move_Internal(std::move(other));
		return *this;
	}
	RESULT Allocate(const MemoryAllocateInfo& allocateInfo) {
		if (allocateInfo.memoryTypeIndex >= VkeApp::Base().PhysicalDevice().MemoryProperties().memoryTypeCount) {
			OutputMessage("[ vke::oop::DeviceMemory ] ERROR\nInvalid memory type index!\n");
			return VK_RESULT_MAX_ENUM; // No proper VkResult enum value
		}
		if (Result result = Base_T::Allocate(allocateInfo)) {
			OutputMessage("[ vke::oop::DeviceMemory ] ERROR\nFailed to allocate memory!\nError code: {}\n", string_VkResult(result));
			return result;
		}
		allocationSize = allocateInfo.allocationSize;
		memoryProperties = VkeApp::Base().PhysicalDevice().MemoryProperties().memoryTypes[allocateInfo.memoryTypeIndex].propertyFlags;
		return VK_SUCCESS;
	}
	AUTO   Allocate(DeviceSize allocationSize, uint32_t memoryTypeIndex) {
		DefineFunctionRaiiClass_Result(DeviceMemory, RESULT, Allocate,
			MemoryAllocateInfo, ParameterList(DeviceSize allocationSize, uint32_t memoryTypeIndex),
			AllocationSize(allocationSize).
			MemoryTypeIndex(memoryTypeIndex));
		return _{ this, allocationSize, memoryTypeIndex };
	}
	AUTO   Allocate() {
		DefineFunctionRaiiClass_ResultPublic(DeviceMemory, RESULT, Allocate, MemoryAllocateInfo);
		return _{ this };
	}
protected:
	DeviceSize allocationSize = 0;
	MemoryPropertyFlags memoryProperties = 0;
	struct { uint8_t bytes[4]; } padding = {}; // Padding bytes of this class, for later use
	/* Non-const Function */
	void Move_Internal(Object&& other) {
		static_cast<Base_T&>(*this) = std::move(other);
		allocationSize = other.allocationSize;
		memoryProperties = other.memoryProperties;
		padding = other.padding;
		other.allocationSize = 0;
		other.memoryProperties = 0;
		other.padding = {};
	}
	/* Const Function */
	DeviceSize AdjustNonCoherentMemoryRange(DeviceSize& offset, DeviceSize& size) const {
		// Adjust mapped memory range if memory is not host-coherent
		const DeviceSize& nonCoherentAtomSize = VkeApp::Base().PhysicalDevice().Properties().limits.nonCoherentAtomSize;
		DeviceSize _offset = offset;
		offset = offset / nonCoherentAtomSize * nonCoherentAtomSize;
		size = std::min((size + _offset + nonCoherentAtomSize - 1) / nonCoherentAtomSize * nonCoherentAtomSize, allocationSize) - offset;
		return _offset - offset;
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Event) {
	ObjectClassHeader(Event);
	Object(const VkEventCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkEventCreateInfo{}) {}
	/* Const Function */
	RESULT Status() const {
		Result result = GetEventStatus(handle);
		if (result < 0)
			OutputMessage("[ vke::oop::Event ] ERROR\nFailed to query the state!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Set() const {
		Result result = SetEvent(handle);
		if (result)
			OutputMessage("[ vke::oop::Event ] ERROR\nFailed to singal the event!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Reset() const {
		Result result = ResetEvent(handle);
		if (result)
			OutputMessage("[ vke::oop::Event ] ERROR\nFailed to unsingal the event!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	void CmdSet(PipelineStageFlags stageMask) const {
		CmdSetEvent(handle, stageMask);
	}
	void CmdReset(PipelineStageFlags stageMask) const {
		CmdResetEvent(handle, stageMask);
	}
	void CmdWait(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, ArrayRef<const MemoryBarrier> memoryBarriers = {}, ArrayRef<const BufferMemoryBarrier> bufferMemoryBarriers = {}, ArrayRef<const ImageMemoryBarrier> imageMemoryBarriers = {}) const {
		CmdWaitEvents(handle, srcStageMask, dstStageMask, memoryBarriers, bufferMemoryBarriers, imageMemoryBarriers);
	}
	// Provided by VK_API_VERSION_1_3 or VK_KHR_synchronization2
	void CmdSet2(const DependencyInfo& dependencyInfo) const {
		M_ConditionalDispatch(CmdSetEvent2, KHR, handle, dependencyInfo);
	}
	AUTO CmdSet2(ArrayRef<const MemoryBarrier2> memoryBarriers = {}, ArrayRef<const BufferMemoryBarrier2> bufferMemoryBarriers = {}, ArrayRef<const ImageMemoryBarrier2> imageMemoryBarriers = {}) const {
		DefineFunctionRaiiClass(Event, CmdSet2,
			DependencyInfo, ParameterList(ArrayRef<const MemoryBarrier2> memoryBarriers, ArrayRef<const BufferMemoryBarrier2> bufferMemoryBarriers, ArrayRef<const ImageMemoryBarrier2> imageMemoryBarriers),
			MemoryBarriers(memoryBarriers).
			BufferMemoryBarriers(bufferMemoryBarriers).
			ImageMemoryBarriers(imageMemoryBarriers),
			DefineSetter_Copy(DependencyFlags, decltype(_::dependencyFlags), dependencyFlags));
		return _{ this, memoryBarriers, bufferMemoryBarriers, imageMemoryBarriers };
	}
	void CmdReset2(PipelineStageFlags2 stageMask) const {
		M_ConditionalDispatch(CmdResetEvent2, KHR, handle, stageMask);
	}
	void CmdWait2(const DependencyInfo& dependencyInfo) const {
		M_ConditionalDispatch(CmdWaitEvents2, KHR, handle, dependencyInfo);
	}
	AUTO CmdWait2(ArrayRef<const MemoryBarrier2> memoryBarriers = {}, ArrayRef<const BufferMemoryBarrier2> bufferMemoryBarriers = {}, ArrayRef<const ImageMemoryBarrier2> imageMemoryBarriers = {}) const {
		DefineFunctionRaiiClass(Event, CmdWait2,
			DependencyInfo, ParameterList(ArrayRef<const MemoryBarrier2> memoryBarriers, ArrayRef<const BufferMemoryBarrier2> bufferMemoryBarriers, ArrayRef<const ImageMemoryBarrier2> imageMemoryBarriers),
			MemoryBarriers(memoryBarriers).
			BufferMemoryBarriers(bufferMemoryBarriers).
			ImageMemoryBarriers(imageMemoryBarriers),
			DefineSetter_Copy(DependencyFlags, decltype(_::dependencyFlags), dependencyFlags));
		return _{ this, memoryBarriers, bufferMemoryBarriers, imageMemoryBarriers };
	}
	/* Non-const Function */
	RESULT Create(const EventCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Event ] ERROR\nFailed to create an event!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_Result(Event, RESULT, Create, EventCreateInfo, , , DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(QueryPool) {
	ObjectClassHeader(QueryPool);
	Object(const VkQueryPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkQueryPoolCreateInfo{}) {}
	Object(QueryType queryType, uint32_t queryCount, QueryPipelineStatisticFlags pipelineStatistics = 0) :
		Object(QueryPoolCreateInfo{}.QueryType(queryType).QueryCount(queryCount).PipelineStatistics(pipelineStatistics)) {}
	/* Const Function */
	RESULT GetResults(uint32_t firstQuery, uint32_t queryCount, ArrayRef<void> data, DeviceSize stride = 0, QueryResultFlags flags = 0) const {
		Result result = GetQueryPoolResults(handle, firstQuery, queryCount, { data.size(), data }, stride, flags);
		if (result)
			result > 0 ?
			OutputMessage("[ vke::oop::QueryPool ] WARNING\nNot all queries are available!\nError code: {}\n", string_VkResult(result)) :
			OutputMessage("[ vke::oop::QueryPool ] ERROR\nFailed to get query pool results!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT GetResults(uint32_t firstQuery, uint32_t queryCount, IsNotRangeOrPointer auto& data, DeviceSize stride = 0, QueryResultFlags flags = 0) const {
		return GetResults(firstQuery, queryCount, { sizeof *&data, &data }, stride, flags);
	}
	void CmdBegin(uint32_t query, QueryControlFlags flags = 0) const {
		CmdBeginQuery(handle, query, flags);
	}
	void CmdEnd(uint32_t query) const {
		CmdEndQuery(handle, query);
	}
	void CmdReset(uint32_t firstQuery, uint32_t queryCount) const {
		CmdResetQueryPool(handle, firstQuery, queryCount);
	}
	void CmdWriteTimestamp(PipelineStageFlagBits pipelineStage, uint32_t query) const {
		VK_ENCAPSULATION_NAMESPACE::CmdWriteTimestamp(pipelineStage, handle, query);
	}
	void CmdCopyResults(uint32_t firstQuery, uint32_t queryCount, Buffer_ dstBuffer, DeviceSize dstOffset = 0, DeviceSize stride = 0, QueryResultFlags flags = 0) const {
		CmdCopyQueryPoolResults(handle, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
	}
	// Provided by VK_API_VERSION_1_2 or VK_EXT_host_query_reset
	void Reset(uint32_t firstQuery, uint32_t queryCount) const {
		M_ConditionalDispatch(ResetQueryPool, EXT, handle, firstQuery, queryCount);
	}
	// Provided by VK_API_VERSION_1_3 or VK_KHR_synchronization2
	void CmdWriteTimestamp2(PipelineStageFlags2 stage, uint32_t query) const {
		M_ConditionalDispatch(CmdWriteTimestamp2, KHR, stage, handle, query);
	}
	/* Non-const Function */
	RESULT Create(const QueryPoolCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::QueryPool ] ERROR\nFailed to create a query pool!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(QueryType queryType, uint32_t queryCount, QueryPipelineStatisticFlags pipelineStatistics = 0) {
		DefineFunctionRaiiClass_Result(QueryPool, RESULT, Create,
			QueryPoolCreateInfo, ParameterList(QueryType_ queryType, uint32_t queryCount, QueryPipelineStatisticFlags pipelineStatistics),
			QueryType(queryType).
			QueryCount(queryCount).
			PipelineStatistics(pipelineStatistics),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, queryType, queryCount, pipelineStatistics };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(QueryPool, RESULT, Create, QueryPoolCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(BufferView) {
	ObjectClassHeader(BufferView);
	Object(const VkBufferViewCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkBufferViewCreateInfo{}) {}
	Object(Buffer_ buffer, Format format, DeviceSize offset = 0, DeviceSize range = VK_WHOLE_SIZE) :
		Object(BufferViewCreateInfo{}.Buffer(buffer).Format(format).Offset(offset).Range(range)) {}
	/* Non-const Function */
	RESULT Create(const BufferViewCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::BufferView ] ERROR\nFailed to create a buffer view!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(Buffer_ buffer, Format format, DeviceSize offset = 0, DeviceSize range = VK_WHOLE_SIZE) {
		DefineFunctionRaiiClass_Result(BufferView, RESULT, Create,
			BufferViewCreateInfo, ParameterList(Buffer_ buffer, Format_ format, DeviceSize offset, DeviceSize range),
			Buffer(buffer).
			Format(format).
			Offset(offset).
			Range(range),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, buffer, format, offset, range };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(BufferView, RESULT, Create, BufferViewCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(ImageView) {
	ObjectClassHeader(ImageView);
	Object(const VkImageViewCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkImageViewCreateInfo{}) {}
	Object(Image_ image, ImageViewType viewType, Format format, Ref<const ComponentMapping> components, Ref<const ImageSubresourceRange> subresourceRange) :
		Object(ImageViewCreateInfo{}.Image(image).ViewType(viewType).Format(format).Components(components).SubresourceRange(subresourceRange)) {}
	/* Non-const Function */
	RESULT Create(const ImageViewCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::ImageView ] ERROR\nFailed to create an image view!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(Image_ image, ImageViewType viewType, Format format, Ref<const ComponentMapping> components, Ref<const ImageSubresourceRange> subresourceRange) {
		DefineFunctionRaiiClass_Result(ImageView, RESULT, Create,
			ImageViewCreateInfo, ParameterList(Image_ image, ImageViewType viewType, Format_ format, Ref<const ComponentMapping> components, Ref<const ImageSubresourceRange> subresourceRange),
			Image(image).
			ViewType(viewType).
			Format(format).
			Components(components).
			SubresourceRange(subresourceRange),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, image, viewType, format, components, subresourceRange };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(ImageView, RESULT, Create, ImageViewCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(ShaderModule) {
	ObjectClassHeader(ShaderModule);
	Object(const VkShaderModuleCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkShaderModuleCreateInfo{}) {}
	Object(ArrayRef<const uint32_t> code) :
		Object(ShaderModuleCreateInfo{}.Code(code)) {}
	Object(const char* filepath) {
		Create_Internal(ShaderModuleCreateInfo{}, filepath);
	}
	/* Const Function */
	PipelineShaderStageCreateInfo StageCreateInfo(ShaderStageFlagBits stage) const {
		return PipelineShaderStageCreateInfo{}.
			Stage(stage).
			Module(handle);
	}
	/* Non-const Function */
	RESULT Create(const ShaderModuleCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::ShaderModule ] ERROR\nFailed to create a shader module!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const uint32_t> code) {
		DefineFunctionRaiiClass_Result(ShaderModule, RESULT, Create,
			ShaderModuleCreateInfo, ParameterList(ArrayRef<const uint32_t> code),
			Code(code),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, code };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(ShaderModule, RESULT, Create, ShaderModuleCreateInfo);
		return _{ this };
	}
	AUTO   Create(const char* filepath) {
		DefineFunctionRaiiClass_ResultL(ShaderModule, RESULT, Create_Internal, ShaderModuleCreateInfo, , const char*, filepath, , DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, filepath };
	}
protected:
	RESULT Create_Internal(ShaderModuleCreateInfo&& createInfo, const char* filepath) {
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);
		if (!file) {
			OutputMessage("[ vke::oop::ShaderModule ] ERROR\nFailed to open the file: {}\n", filepath);
			return VK_RESULT_MAX_ENUM; // No proper VkResult enum value
		}
		size_t fileSize = size_t(file.tellg());
		std::vector<uint32_t> binaries(fileSize / 4);
		file.seekg(0);
		file.read(reinterpret_cast<char*>(binaries.data()), fileSize);
		file.close();
		createInfo.Code(binaries);
		return Create(createInfo);
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(PipelineCache) {
	ObjectClassHeader(PipelineCache);
	Object(const VkPipelineCacheCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkPipelineCacheCreateInfo{}) {}
	Object(ArrayRef<const void> initialData) :
		Object(PipelineCacheCreateInfo{}.InitialData(initialData)) {}
	Object(const IsNotRangeOrPointer auto& initialData) requires(!std::convertible_to<decltype(initialData), PipelineCacheCreateInfo>) :
		Object(PipelineCacheCreateInfo{}.InitialData(initialData)) {}
	/* Const Function */
	RESULT GetData(IsDynamicByteArray auto& data) const {
		Result result = GetPipelineCacheData(handle, data);
		if (result)
			OutputMessage("[ vke::oop::PipelineCache ] ERROR\nFailed to retrieve the pipeline cache data!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT Merge(ArrayRef<const PipelineCache> srcCaches) const {
		Result result = MergePipelineCaches(handle, srcCaches);
		if (result)
			OutputMessage("[ vke::oop::PipelineCache ] ERROR\nFailed to merge pipeline caches!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	/* Non-const Function */
	RESULT Create(const PipelineCacheCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::PipelineCache ] ERROR\nFailed to create a pipeline cache!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const void> initialData = {}) {
		DefineFunctionRaiiClass_Result(PipelineCache, RESULT, Create,
			PipelineCacheCreateInfo, ParameterList(ArrayRef<const void> initialData),
			InitialData(initialData),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, initialData };
	}
	AUTO   Create(const IsNotRangeOrPointer auto& initialData) requires(!std::convertible_to<decltype(initialData), PipelineCacheCreateInfo>) {
		return Create({ sizeof *&initialData, &initialData });
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(PipelineCache, RESULT, Create, PipelineCacheCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(PipelineLayout) {
	ObjectClassHeader(PipelineLayout);
	Object(const VkPipelineLayoutCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkPipelineLayoutCreateInfo{}) {}
	Object(ArrayRef<const DescriptorSetLayout_> setLayouts, ArrayRef<const PushConstantRange> pushConstantRanges = {}) :
		Object(PipelineLayoutCreateInfo{}.SetLayouts(setLayouts).PushConstantRanges(pushConstantRanges)) {}
	/* Non-const Function */
	RESULT Create(const PipelineLayoutCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::PipelineLayout ] ERROR\nFailed to create a pipeline layout!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const DescriptorSetLayout_> setLayouts, ArrayRef<const PushConstantRange> pushConstantRanges = {}) {
		DefineFunctionRaiiClass_Result(PipelineLayout, RESULT, Create,
			PipelineLayoutCreateInfo, ParameterList(ArrayRef<const DescriptorSetLayout_> setLayouts, ArrayRef<const PushConstantRange> pushConstantRanges),
			SetLayouts(setLayouts).
			PushConstantRanges(pushConstantRanges),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, setLayouts, pushConstantRanges };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(PipelineLayout, RESULT, Create, PipelineLayoutCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Pipeline) {
	ObjectClassHeader(Pipeline);
	Object(PipelineCache_ pipelineCache, const VkGraphicsPipelineCreateInfo& createInfo) {
		CreateGraphics(pipelineCache, createInfo);
	}
	Object(EmptyList) :
		Object(VK_NULL_HANDLE, VkGraphicsPipelineCreateInfo{}) {}
	Object(PipelineCache_ pipelineCache, ArrayRef<const PipelineShaderStageCreateInfo> stages, const PipelineVertexInputStateCreateInfo& vertexInputState, const PipelineInputAssemblyStateCreateInfo& inputAssemblyState, const PipelineTessellationStateCreateInfo& tessellationState, const PipelineViewportStateCreateInfo& viewportState,
		const PipelineRasterizationStateCreateInfo& rasterizationState, const PipelineMultisampleStateCreateInfo& multisampleState, const PipelineDepthStencilStateCreateInfo& depthStencilState, const PipelineColorBlendStateCreateInfo& colorBlendState, const PipelineDynamicStateCreateInfo& dynamicState,
		PipelineLayout_ layout, RenderPass_ renderPass, uint32_t subpass = 0, Pipeline_ basePipelineHandle = VK_NULL_HANDLE, int32_t basePipelineIndex = -1) :
		Object(pipelineCache, GraphicsPipelineCreateInfo().Stages(stages).VertexInputState(vertexInputState).InputAssemblyState(inputAssemblyState).TessellationState(tessellationState).ViewportState(viewportState).
			RasterizationState(rasterizationState).MultisampleState(multisampleState).DepthStencilState(depthStencilState).ColorBlendState(colorBlendState).DynamicState(dynamicState).
			Layout(layout).RenderPass(renderPass).Subpass(subpass).BasePipelineHandle(basePipelineHandle).BasePipelineIndex(basePipelineIndex)) {}
	Object(PipelineCache_ pipelineCache, const VkComputePipelineCreateInfo& createInfo) {
		CreateCompute(pipelineCache, createInfo);
	}
	Object(PipelineCache_ pipelineCache, const PipelineShaderStageCreateInfo& stage, PipelineLayout_ layout, Pipeline_ basePipelineHandle = VK_NULL_HANDLE, int32_t basePipelineIndex = -1) :
		Object(pipelineCache, ComputePipelineCreateInfo{}.Stage(stage).Layout(layout).BasePipelineHandle(basePipelineHandle).BasePipelineIndex(basePipelineIndex)) {}
	/* Const Function */
	void CmdBind(PipelineBindPoint pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS) const {
		CmdBindPipeline(pipelineBindPoint, handle);
	}
	/* Non-const Function */
	RESULT CreateGraphics(PipelineCache_ pipelineCache, const GraphicsPipelineCreateInfo& createInfo) {
		Result result = Base_T::CreateGraphics(pipelineCache, createInfo);
		if (result)
			OutputMessage("[ vke::oop::Pipeline ] ERROR\nFailed to create a graphics pipeline!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   CreateGraphics(PipelineCache_ pipelineCache, ArrayRef<const PipelineShaderStageCreateInfo> stages, const PipelineVertexInputStateCreateInfo& vertexInputState, const PipelineInputAssemblyStateCreateInfo& inputAssemblyState, const PipelineTessellationStateCreateInfo& tessellationState, const PipelineViewportStateCreateInfo& viewportState,
		const PipelineRasterizationStateCreateInfo& rasterizationState, const PipelineMultisampleStateCreateInfo& multisampleState, const PipelineDepthStencilStateCreateInfo& depthStencilState, const PipelineColorBlendStateCreateInfo& colorBlendState, const PipelineDynamicStateCreateInfo& dynamicState,
		PipelineLayout_ layout, RenderPass_ renderPass, uint32_t subpass = 0, Pipeline_ basePipelineHandle = VK_NULL_HANDLE, int32_t basePipelineIndex = -1) {
		DefineFunctionRaiiClass_ResultR(Pipeline, RESULT, CreateGraphics, PipelineCache_, pipelineCache,
			GraphicsPipelineCreateInfo, ParameterList(ArrayRef<const PipelineShaderStageCreateInfo> stages, const PipelineVertexInputStateCreateInfo & vertexInputState, const PipelineInputAssemblyStateCreateInfo & inputAssemblyState, const PipelineTessellationStateCreateInfo & tessellationState, const PipelineViewportStateCreateInfo & viewportState,
				const PipelineRasterizationStateCreateInfo & rasterizationState, const PipelineMultisampleStateCreateInfo & multisampleState, const PipelineDepthStencilStateCreateInfo & depthStencilState, const PipelineColorBlendStateCreateInfo & colorBlendState, const PipelineDynamicStateCreateInfo & dynamicState,
				PipelineLayout_ layout, RenderPass_ renderPass, uint32_t subpass, Pipeline_ basePipelineHandle, int32_t basePipelineIndex),
			Stages(stages).
			VertexInputState(vertexInputState).
			InputAssemblyState(inputAssemblyState).
			TessellationState(tessellationState).
			ViewportState(viewportState).
			RasterizationState(rasterizationState).
			MultisampleState(multisampleState).
			DepthStencilState(depthStencilState).
			ColorBlendState(colorBlendState).
			DynamicState(dynamicState).
			Layout(layout).
			RenderPass(renderPass).
			Subpass(subpass).
			BasePipelineHandle(basePipelineHandle).
			BasePipelineIndex(basePipelineIndex),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, pipelineCache, stages, vertexInputState, inputAssemblyState, tessellationState, viewportState, rasterizationState, multisampleState, depthStencilState, colorBlendState, dynamicState, layout, renderPass, subpass, basePipelineHandle, basePipelineIndex };
	}
	AUTO   CreateGraphics(PipelineCache_ pipelineCache = VK_NULL_HANDLE) {
		DefineFunctionRaiiClass_ResultPublicR(Pipeline, RESULT, CreateGraphics, PipelineCache_, pipelineCache, GraphicsPipelineCreateInfo, , );
		return _{ this, pipelineCache };
	}
	RESULT CreateCompute(PipelineCache_ pipelineCache, const ComputePipelineCreateInfo& createInfo) {
		Result result = Base_T::CreateCompute(pipelineCache, createInfo);
		if (result)
			OutputMessage("[ vke::oop::Pipeline ] ERROR\nFailed to create a compute pipeline!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   CreateCompute(PipelineCache_ pipelineCache, const PipelineShaderStageCreateInfo& stage, PipelineLayout_ layout, Pipeline_ basePipelineHandle = VK_NULL_HANDLE, int32_t basePipelineIndex = -1) {
		DefineFunctionRaiiClass_ResultR(Pipeline, RESULT, CreateCompute, PipelineCache_, pipelineCache,
			ComputePipelineCreateInfo, ParameterList(const PipelineShaderStageCreateInfo& stage, PipelineLayout_ layout, Pipeline_ basePipelineHandle, int32_t basePipelineIndex),
			Stage(stage).
			Layout(layout).
			BasePipelineHandle(basePipelineHandle).
			BasePipelineIndex(basePipelineIndex),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, pipelineCache, stage, layout, basePipelineHandle, basePipelineIndex };
	}
	AUTO   CreateCompute(PipelineCache_ pipelineCache = VK_NULL_HANDLE) {
		DefineFunctionRaiiClass_ResultPublicR(Pipeline, RESULT, CreateCompute, PipelineCache_, pipelineCache, ComputePipelineCreateInfo, , );
		return _{ this, pipelineCache };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(RenderPass) {
	ObjectClassHeader(RenderPass);
	Object(const VkRenderPassCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkRenderPassCreateInfo{}) {}
	Object(const VkRenderPassCreateInfo2& createInfo) {
		Create2(createInfo);
	}
	Object(ArrayRef<const AttachmentDescription> attachments, ArrayRef<const SubpassDescription> subpasses, ArrayRef<const SubpassDependency> dependencies = {}) :
		Object(RenderPassCreateInfo{}.Attachments(attachments).Subpasses(subpasses).Dependencies(dependencies)) {}
	Object(ArrayRef<const AttachmentDescription2> attachments, ArrayRef<const SubpassDescription2> subpasses, ArrayRef<const SubpassDependency2> dependencies = {}, ArrayRef<const uint32_t> CorrelatedViewMasks = {}) :
		Object(RenderPassCreateInfo2{}.Attachments(attachments).Subpasses(subpasses).Dependencies(dependencies).CorrelatedViewMasks(CorrelatedViewMasks)) {}
	/* Const Function */
	void GetRenderAreaGranularity(Ref<Extent2D> granularity) const {
		VK_ENCAPSULATION_NAMESPACE::GetRenderAreaGranularity(handle, granularity);
	}
	void CmdBegin(const RenderPassBeginInfo& renderPassBegin, SubpassContents contents = VK_SUBPASS_CONTENTS_INLINE) const {
		auto info = RenderPassBeginInfo{ renderPassBegin }.
			RenderPass(handle);
		CmdBeginRenderPass(info, contents);
	}
	AUTO CmdBegin(Framebuffer_ framebuffer, Ref<const Rect2D> renderArea, ArrayRef<const ClearValue> clearValues = {}, SubpassContents contents = VK_SUBPASS_CONTENTS_INLINE) const {
		DefineFunctionRaiiClass_L(RenderPass, CmdBegin,
			RenderPassBeginInfo, ParameterList(Framebuffer_ framebuffer, Ref<const Rect2D> renderArea, ArrayRef<const ClearValue> clearValues),
			SubpassContents, contents,
			Framebuffer(framebuffer).
			RenderArea(renderArea).
			ClearValues(clearValues));
		return _{ this, framebuffer, renderArea, clearValues, contents };
	}
	// Provided by VK_API_VERSION_1_2 or VK_KHR_create_renderpass2
	void CmdBegin2(const RenderPassBeginInfo& renderPassBegin, const SubpassBeginInfo& subpassBeginInfo) const {
		auto info = RenderPassBeginInfo{ renderPassBegin }.
			RenderPass(handle);
		M_ConditionalDispatch(CmdBeginRenderPass2, KHR, info, subpassBeginInfo);
	}
	AUTO CmdBegin2(Framebuffer_ framebuffer, Ref<const Rect2D> renderArea, ArrayRef<const ClearValue> clearValues = {}, SubpassContents contents = VK_SUBPASS_CONTENTS_INLINE) const {
		DefineFunctionRaiiClass_TwoStruct(RenderPass, CmdBegin2,
			RenderPassBeginInfo, SubpassBeginInfo, ParameterList(Framebuffer_ framebuffer, Ref<const Rect2D> renderArea, RenderPassBeginInfo::ArrayRef<const ClearValue> clearValues, SubpassContents contents),
			Framebuffer(framebuffer).
			RenderArea(renderArea).
			ClearValues(clearValues);
			Contents(contents));
		return _{ this, framebuffer, renderArea, clearValues, contents };
	}
	/* Non-const Function */
	RESULT Create(const RenderPassCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::RenderPass ] ERROR\nFailed to create a render pass!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const AttachmentDescription> attachments, ArrayRef<const SubpassDescription> subpasses, ArrayRef<const SubpassDependency> dependencies = {}) {
		DefineFunctionRaiiClass_Result(RenderPass, RESULT, Create,
			RenderPassCreateInfo, ParameterList(ArrayRef<const AttachmentDescription> attachments, ArrayRef<const SubpassDescription> subpasses, ArrayRef<const SubpassDependency> dependencies),
			Attachments(attachments).
			Subpasses(subpasses).
			Dependencies(dependencies),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, attachments, subpasses, dependencies };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(RenderPass, RESULT, Create, RenderPassCreateInfo);
		return _{ this };
	}
	// Provided by VK_API_VERSION_1_2 or VK_KHR_create_renderpass2
	RESULT Create2(const RenderPassCreateInfo2& createInfo) {
		Result result = Base_T::Create2(createInfo);
		if (result)
			OutputMessage("[ vke::oop::RenderPass ] ERROR\nFailed to create a render pass!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create2(ArrayRef<const AttachmentDescription2> attachments, ArrayRef<const SubpassDescription2> subpasses, ArrayRef<const SubpassDependency2> dependencies = {}, ArrayRef<const uint32_t> CorrelatedViewMasks = {}) {
		DefineFunctionRaiiClass_Result(RenderPass, RESULT, Create2,
			RenderPassCreateInfo2, ParameterList(ArrayRef<const AttachmentDescription2> attachments, ArrayRef<const SubpassDescription2> subpasses, ArrayRef<const SubpassDependency2> dependencies, ArrayRef<const uint32_t> CorrelatedViewMasks),
			Attachments(attachments).
			Subpasses(subpasses).
			Dependencies(dependencies).
			CorrelatedViewMasks(CorrelatedViewMasks),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, attachments, subpasses, dependencies, CorrelatedViewMasks };
	}
	AUTO   Create2() {
		DefineFunctionRaiiClass_ResultPublic(RenderPass, RESULT, Create2, RenderPassCreateInfo2);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(DescriptorSetLayout) {
	ObjectClassHeader(DescriptorSetLayout);
	Object(const VkDescriptorSetLayoutCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkDescriptorSetLayoutCreateInfo{}) {}
	Object(ArrayRef<const DescriptorSetLayoutBinding> bindings) :
		Object(DescriptorSetLayoutCreateInfo{}.Bindings(bindings)) {}
	/* Non-const Function */
	RESULT Create(const DescriptorSetLayoutCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::DescriptorSetLayout ] ERROR\nFailed to create a descriptor set layout!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const DescriptorSetLayoutBinding> bindings) {
		DefineFunctionRaiiClass_Result(DescriptorSetLayout, RESULT, Create,
			DescriptorSetLayoutCreateInfo, ParameterList(ArrayRef<const DescriptorSetLayoutBinding> bindings),
			Bindings(bindings),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, bindings };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(DescriptorSetLayout, RESULT, Create, DescriptorSetLayoutCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Sampler) {
	ObjectClassHeader(Sampler);
	Object(const VkSamplerCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkSamplerCreateInfo{}) {}
	Object(Filter magFilter, Filter minFilter, SamplerMipmapMode mipmapMode, SamplerAddressMode addressModeU, SamplerAddressMode addressModeV, SamplerAddressMode addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT,
		float mipLodBias = 0, OptionalValue<float> maxAnisotropy = {}, OptionalValue<CompareOp> compareOp = {}, float minLod = 0, float maxLod = VK_LOD_CLAMP_NONE, BorderColor borderColor = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK, Bool32 unnormalizedCoordinates = false) :
		Object(SamplerCreateInfo{}.MagFilter(magFilter).MinFilter(minFilter).MipmapMode(mipmapMode).AddressModeU(addressModeU).AddressModeV(addressModeV).AddressModeW(addressModeW).MipLodBias(mipLodBias).MaxAnisotropy(maxAnisotropy).CompareOp(compareOp).MinLod(minLod).MaxLod(maxLod).BorderColor(borderColor).UnnormalizedCoordinates(unnormalizedCoordinates)) {}
	/* Non-const Function */
	RESULT Create(const SamplerCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Sampler ] ERROR\nFailed to create a sampler!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(Filter magFilter, Filter minFilter, SamplerMipmapMode mipmapMode, SamplerAddressMode addressModeU, SamplerAddressMode addressModeV, SamplerAddressMode addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT,
		float mipLodBias = 0, OptionalValue<float> maxAnisotropy = {}, OptionalValue<CompareOp> compareOp = {}, float minLod = 0, float maxLod = VK_LOD_CLAMP_NONE, BorderColor borderColor = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK, Bool32 unnormalizedCoordinates = false) {
		DefineFunctionRaiiClass_Result(Sampler, RESULT, Create,
			SamplerCreateInfo, ParameterList(Filter magFilter, Filter minFilter, SamplerMipmapMode mipmapMode, SamplerAddressMode addressModeU, SamplerAddressMode addressModeV, SamplerAddressMode addressModeW,
				float mipLodBias, OptionalValue<float> maxAnisotropy, OptionalValue<CompareOp_> compareOp, float minLod, float maxLod, BorderColor_ borderColor, Bool32 unnormalizedCoordinates),
			MagFilter(magFilter).
			MinFilter(minFilter).
			MipmapMode(mipmapMode).
			AddressModeU(addressModeU).
			AddressModeV(addressModeV).
			AddressModeW(addressModeW).
			MipLodBias(mipLodBias).
			MaxAnisotropy(maxAnisotropy).
			CompareOp(compareOp).
			MinLod(minLod).
			MaxLod(maxLod).
			BorderColor(borderColor).
			UnnormalizedCoordinates(unnormalizedCoordinates),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, magFilter, minFilter, mipmapMode, addressModeU, addressModeV, addressModeW, mipLodBias, maxAnisotropy, compareOp, minLod, maxLod, borderColor, unnormalizedCoordinates };
	};
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(Sampler, RESULT, Create, SamplerCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(DescriptorSet) {
	ObjectClassHeader(DescriptorSet);
	/* Const Function */
	void Write(ArrayRef<const WriteDescriptorSet> writes) const {
		std::vector<WriteDescriptorSet> _writes(writes.size());
		std::memcpy(_writes.data(), writes, sizeof(WriteDescriptorSet) * writes.size());
		for (auto& i : _writes)
			i.DstSet(handle);
		UpdateDescriptorSets(_writes, {});
	}
	AUTO Write(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType descriptorType, ArrayRef<const DescriptorImageInfo> imageInfos) const {
		DefineFunctionRaiiClass(DescriptorSet, Write,
			WriteDescriptorSet, ParameterList(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType_ descriptorType, ArrayRef<const DescriptorImageInfo> imageInfos),
			DstBinding(dstBinding).
			DstArrayElement(dstArrayElement).
			DescriptorType(descriptorType).
			ImageInfo(imageInfos));
		return _{ this, dstBinding, dstArrayElement, descriptorType, imageInfos };
	}
	AUTO Write(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType descriptorType, ArrayRef<const DescriptorBufferInfo> bufferInfos) const {
		DefineFunctionRaiiClass(DescriptorSet, Write,
			WriteDescriptorSet, ParameterList(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType_ descriptorType, ArrayRef<const DescriptorBufferInfo> bufferInfos),
			DstBinding(dstBinding).
			DstArrayElement(dstArrayElement).
			DescriptorType(descriptorType).
			BufferInfo(bufferInfos));
		return _{ this, dstBinding, dstArrayElement, descriptorType, bufferInfos };
	}
	AUTO Write(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType descriptorType, ArrayRef<const BufferView_> texelBufferViews) const {
		DefineFunctionRaiiClass(DescriptorSet, Write,
			WriteDescriptorSet, ParameterList(uint32_t dstBinding, uint32_t dstArrayElement, DescriptorType_ descriptorType, ArrayRef<const BufferView_> texelBufferViews),
			DstBinding(dstBinding).
			DstArrayElement(dstArrayElement).
			DescriptorType(descriptorType).
			TexelBufferView(texelBufferViews));
		return _{ this, dstBinding, dstArrayElement, descriptorType, texelBufferViews };
	}
	void CmdBind(PipelineBindPoint pipelineBindPoint, PipelineLayout_ layout, uint32_t firstSet, uint32_t dynamicOffset = 0) const {
		CmdBindDescriptorSets(pipelineBindPoint, layout, firstSet, handle, dynamicOffset);
	}
	// Provided by VK_API_VERSION_1_3 or VK_EXT_inline_uniform_block
	AUTO Write(uint32_t dstBinding, uint32_t dstArrayElement, ArrayRef<const void> inlineUniformBlockData) const {
		DefineFunctionRaiiClass_L(DescriptorSet, Write_Internal,
			WriteDescriptorSet, ParameterList(uint32_t dstBinding, uint32_t dstArrayElement),
			ArrayRef<const void>, inlineUniformBlockData,
			DstBinding(dstBinding).
			DstArrayElement(dstArrayElement));
		return _{ this, dstBinding, dstArrayElement, inlineUniformBlockData };
	}
	AUTO Write(uint32_t dstBinding, uint32_t dstArrayElement, const IsNotRangeOrPointer auto& inlineUniformBlockData) const {
		return Write(dstBinding, dstArrayElement, { sizeof *&inlineUniformBlockData, &inlineUniformBlockData });
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_descriptor_update_template
	void UpdateWithTemplate(DescriptorUpdateTemplate_ descriptorUpdateTemplate, ArrayRef<const void> data) const {
		UpdateDescriptorSetWithTemplate(handle, descriptorUpdateTemplate, data);
	}
	void UpdateWithTemplate(DescriptorUpdateTemplate_ descriptorUpdateTemplate, const IsNotRangeOrPointer auto& data) const {
		UpdateDescriptorSetWithTemplate(handle, descriptorUpdateTemplate, data);
	}
	// Provided by VK_API_VERSION_1_4 or VK_KHR_maintenance6
	void CmdBind2(const BindDescriptorSetsInfo& bindDescriptorSetsInfo) const {
		auto info = BindDescriptorSetsInfo{ bindDescriptorSetsInfo }.
			DescriptorSets(handle);
		CmdBindDescriptorSets2(info);
	}
	AUTO CmdBind2(ShaderStageFlags stageFlags, PipelineLayout_ layout, uint32_t firstSet, uint32_t dynamicOffset = 0) const {
		DefineFunctionRaiiClass(DescriptorSet, CmdBind2,
			BindDescriptorSetsInfo, ParameterList(ShaderStageFlags stageFlags, PipelineLayout_ layout, uint32_t firstSet, uint32_t dynamicOffset),
			StageFlags(stageFlags).
			Layout(layout).
			FirstSet(firstSet).
			DynamicOffsets(dynamicOffset));
		return _{ this, stageFlags, layout, firstSet, dynamicOffset };
	}
protected:
	void Write_Internal(WriteDescriptorSet&& write, ArrayRef<const void> inlineUniformBlockData) const {
		auto writeInlineUniformBlock = WriteDescriptorSetInlineUniformBlock{}.
			PNext(write.pNext).
			Data(inlineUniformBlockData);
		write.
			PNext(&writeInlineUniformBlock).
			DescriptorType(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK).
			DescriptorCount(inlineUniformBlockData.size());
		Write(write);
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(DescriptorPool) {
	ObjectClassHeader(DescriptorPool);
	Object(const VkDescriptorPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkDescriptorPoolCreateInfo{}) {}
	Object(uint32_t maxSets, ArrayRef<const DescriptorPoolSize> poolSizes) :
		Object(DescriptorPoolCreateInfo{}.MaxSets(maxSets).PoolSizes(poolSizes)) {}
	/* Const Function */
	RESULT Reset(DescriptorPoolResetFlags flags = 0) {
		Result result = ResetDescriptorPool(handle, flags);
		if (result)
			OutputMessage("[ vke::oop::DescriptorPool ] ERROR\nFailed to reset the descriptor pool!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT AllocateSets(const DescriptorSetAllocateInfo& allocateInfo, HandleArrayRef<DescriptorSet_> descriptorSets) const {
		auto info = DescriptorSetAllocateInfo{ allocateInfo }.
			DescriptorPool(handle);
		Result result = AllocateDescriptorSets(info, descriptorSets);
		if (result)
			OutputMessage("[ vke::oop::DescriptorPool ] ERROR\nFailed to allocate descriptor sets!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   AllocateSets(ArrayRef<const DescriptorSetLayout_> setLayouts, HandleArrayRef<DescriptorSet_> descriptorSets) const {
		DefineFunctionRaiiClass_ResultL(DescriptorPool, RESULT, AllocateSets,
			DescriptorSetAllocateInfo, ParameterList(ArrayRef<const DescriptorSetLayout_> setLayouts),
			HandleArrayRef<DescriptorSet_>, descriptorSets,
			SetLayouts({ std::min(setLayouts.size(), descriptorSets.size()), setLayouts }));
		return _{ this, setLayouts, descriptorSets };
	}
	RESULT FreeSets(HandleArrayRef<DescriptorSet_> descriptorSets) const {
		Result result = FreeDescriptorSets(handle, descriptorSets);
		if (result)
			OutputMessage("[ vke::oop::DescriptorPool ] ERROR\nFailed to free descriptor sets!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	/* Non-const Function */
	RESULT Create(const DescriptorPoolCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::DescriptorPool ] ERROR\nFailed to create a descriptor pool!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(uint32_t maxSets, ArrayRef<const DescriptorPoolSize> poolSizes) {
		DefineFunctionRaiiClass_Result(DescriptorPool, RESULT, Create,
			DescriptorPoolCreateInfo, ParameterList(uint32_t maxSets, ArrayRef<const DescriptorPoolSize> poolSizes),
			MaxSets(maxSets).
			PoolSizes(poolSizes),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, maxSets, poolSizes };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(DescriptorPool, RESULT, Create, DescriptorPoolCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(Framebuffer) {
	ObjectClassHeader(Framebuffer);
	Object(const VkFramebufferCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkFramebufferCreateInfo{}) {}
	Object(RenderPass_ renderPass, ArrayRef<const ImageView_> attachments, uint32_t width, uint32_t height, uint32_t layers = 1) :
		Object(FramebufferCreateInfo{}.RenderPass(renderPass).Attachments(attachments).Width(width).Height(height).Layers(layers)) {}
	/* Non-const Function */
	RESULT Create(const FramebufferCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::Framebuffer ] ERROR\nFailed to create a framebuffer!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(RenderPass_ renderPass, ArrayRef<const ImageView_> attachments, uint32_t width, uint32_t height, uint32_t layers = 1) {
		DefineFunctionRaiiClass_Result(Framebuffer, RESULT, Create,
			FramebufferCreateInfo, ParameterList(RenderPass_ renderPass, ArrayRef<const ImageView_> attachments, uint32_t width, uint32_t height, uint32_t layers),
			RenderPass(renderPass).
			Attachments(attachments).
			Width(width).
			Height(height).
			Layers(layers),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, renderPass, attachments, width, height, layers };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(Framebuffer, RESULT, Create, FramebufferCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(CommandPool) {
	ObjectClassHeader(CommandPool);
	Object(const VkCommandPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkCommandPoolCreateInfo{}) {}
	Object(uint32_t queueFamilyIndex) :
		Object(CommandPoolCreateInfo{}.QueueFamilyIndex(queueFamilyIndex)) {}
	/* Const Function */
	RESULT Reset(CommandPoolResetFlags flags = 0) const {
		Result result = ResetCommandPool(handle, flags);
		if (result)
			OutputMessage("[ vke::oop::CommandPool ] ERROR\nFailed to reset the command pool!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	RESULT AllocateBuffers(const CommandBufferAllocateInfo& allocateInfo, HandleArrayRef<CommandBuffer_> commandBuffers) const {
		auto info = CommandBufferAllocateInfo{ allocateInfo }.
			CommandPool(handle).
			CommandBufferCount(commandBuffers.size());
		Result result = AllocateCommandBuffers(info, commandBuffers);
		if (result)
			OutputMessage("[ vke::oop::CommandPool ] ERROR\nFailed to allocate command buffers!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   AllocateBuffers(CommandBufferLevel level, HandleArrayRef<CommandBuffer_> commandBuffers) const {
		DefineFunctionRaiiClass_ResultL(CommandPool, RESULT, AllocateBuffers,
			CommandBufferAllocateInfo, ParameterList(CommandBufferLevel level),
			HandleArrayRef<CommandBuffer_>, commandBuffers,
			Level(level));
		return _{ this, level, commandBuffers };
	}
	void FreeBuffers(HandleArrayRef<CommandBuffer_> commandBuffers) const {
		FreeCommandBuffers(handle, commandBuffers);
	}
	// Provided by VK_API_VERSION_1_1 or VK_KHR_maintenance1
	void Trim(CommandPoolTrimFlags flags = 0) const {
		M_ConditionalDispatch(TrimCommandPool, KHR, handle, flags);
	}
	/* Non-const Function */
	RESULT Create(const CommandPoolCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::CommandPool ] ERROR\nFailed to create a command pool!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(uint32_t queueFamilyIndex) {
		DefineFunctionRaiiClass_Result(CommandPool, RESULT, Create,
			CommandPoolCreateInfo, ParameterList(uint32_t queueFamilyIndex),
			QueueFamilyIndex(queueFamilyIndex),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, queueFamilyIndex };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(CommandPool, RESULT, Create, CommandPoolCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(SamplerYcbcrConversion) {
	ObjectClassHeader(SamplerYcbcrConversion);
	Object(const VkSamplerYcbcrConversionCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkSamplerYcbcrConversionCreateInfo{}) {}
	Object(Format format, SamplerYcbcrModelConversion ycbcrModel, SamplerYcbcrRange ycbcrRange, Ref<const ComponentMapping> components, ChromaLocation xChromaOffset, ChromaLocation yChromaOffset, Filter chromaFilter, Bool32 forceExplicitReconstruction = false) :
		Object(SamplerYcbcrConversionCreateInfo{}.Format(format).YcbcrModel(ycbcrModel).YcbcrRange(ycbcrRange).Components(components).XChromaOffset(xChromaOffset).YChromaOffset(yChromaOffset).ChromaFilter(chromaFilter).ForceExplicitReconstruction(forceExplicitReconstruction)) {}
	/* Non-const Function */
	// Provided by VK_API_VERSION_1_1 or VK_KHR_sampler_ycbcr_conversion
	RESULT Create(const SamplerYcbcrConversionCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::SamplerYcbcrConversion ] ERROR\nFailed to create a sampler with Y'CbCr conversion enabled!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(Format format, SamplerYcbcrModelConversion ycbcrModel, SamplerYcbcrRange ycbcrRange, Ref<const ComponentMapping> components, ChromaLocation xChromaOffset, ChromaLocation yChromaOffset, Filter chromaFilter, Bool32 forceExplicitReconstruction = false) {
		DefineFunctionRaiiClass_Result(SamplerYcbcrConversion, RESULT, Create,
			SamplerYcbcrConversionCreateInfo, ParameterList(Format_ format, SamplerYcbcrModelConversion ycbcrModel, SamplerYcbcrRange ycbcrRange, Ref<const ComponentMapping> components, ChromaLocation xChromaOffset, ChromaLocation yChromaOffset, Filter chromaFilter, Bool32 forceExplicitReconstruction),
			Format(format).
			YcbcrModel(ycbcrModel).
			YcbcrRange(ycbcrRange).
			Components(components).
			XChromaOffset(xChromaOffset).
			YChromaOffset(yChromaOffset).
			ChromaFilter(chromaFilter).
			ForceExplicitReconstruction(forceExplicitReconstruction));
		return _{ this, format, ycbcrModel, ycbcrRange, components, xChromaOffset, yChromaOffset, chromaFilter, forceExplicitReconstruction };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(SamplerYcbcrConversion, RESULT, Create, SamplerYcbcrConversionCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(DescriptorUpdateTemplate) {
	ObjectClassHeader(DescriptorUpdateTemplate);
	Object(const VkDescriptorUpdateTemplateCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkDescriptorUpdateTemplateCreateInfo{}) {}
	Object(ArrayRef<const DescriptorUpdateTemplateEntry> descriptorUpdateEntries, DescriptorUpdateTemplateType templateType, DescriptorSetLayout_ descriptorSetLayout, PipelineBindPoint pipelineBindPoint, PipelineLayout_ pipelineLayout, uint32_t set) :
		Object(DescriptorUpdateTemplateCreateInfo{}.DescriptorUpdateEntries(descriptorUpdateEntries).TemplateType(templateType).DescriptorSetLayout(descriptorSetLayout).PipelineBindPoint(pipelineBindPoint).PipelineLayout(pipelineLayout).Set(set)) {}
	/* Const Function */
	// Provided by VK_API_VERSION_1_4 or VK_KHR_push_descriptor with (VK_API_VERSION_1_1 or VK_KHR_descriptor_update_template)
	void CmdPushDescriptorSet(PipelineLayout_ layout, uint32_t set, ArrayRef<const void> data) const {
		M_ConditionalDispatch(CmdPushDescriptorSetWithTemplate, KHR, handle, layout, set, data);
	}
	void CmdPushDescriptorSet(PipelineLayout_ layout, uint32_t set, const IsNotRangeOrPointer auto& data) const {
		M_ConditionalDispatch(CmdPushDescriptorSetWithTemplate, KHR, handle, layout, set, data);
	}
	// Provided by VK_API_VERSION_1_4 or VK_KHR_push_descriptor with VK_KHR_maintenance6
	void CmdPushDescriptorSet2(const PushDescriptorSetWithTemplateInfo& pushDescriptorSetWithTemplateInfo) const {
		auto info = PushDescriptorSetWithTemplateInfo{ pushDescriptorSetWithTemplateInfo }.
			DescriptorUpdateTemplate(handle);
		M_ConditionalDispatch(CmdPushDescriptorSetWithTemplate2, KHR, info);
	}
	AUTO CmdPushDescriptorSet2(PipelineLayout_ layout, uint32_t set, ArrayRef<const void> data) const {
		DefineFunctionRaiiClass(DescriptorUpdateTemplate, CmdPushDescriptorSet2,
			PushDescriptorSetWithTemplateInfo, ParameterList(PipelineLayout_ layout, uint32_t set, ArrayRef<const void> data),
			Layout(layout).
			Set(set).
			Data(data));
		return _{ this, layout, set, data };
	}
	AUTO CmdPushDescriptorSet2(PipelineLayout_ layout, uint32_t set, const IsNotRangeOrPointer auto& data) const {
		return CmdPushDescriptorSet2(layout, set, { sizeof *&data, &data });
	}
	/* Non-const Function */
	// Provided by VK_API_VERSION_1_1 or VK_KHR_descriptor_update_template
	RESULT Create(const DescriptorUpdateTemplateCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::DescriptorUpdateTemplate ] ERROR\nFailed to create a descriptor update template!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create(ArrayRef<const DescriptorUpdateTemplateEntry> descriptorUpdateEntries, DescriptorUpdateTemplateType templateType, DescriptorSetLayout_ descriptorSetLayout, PipelineBindPoint pipelineBindPoint, PipelineLayout_ pipelineLayout, uint32_t set) {
		DefineFunctionRaiiClass_Result(DescriptorUpdateTemplate, RESULT, Create,
			DescriptorUpdateTemplateCreateInfo, ParameterList(ArrayRef<const DescriptorUpdateTemplateEntry> descriptorUpdateEntries, DescriptorUpdateTemplateType templateType, DescriptorSetLayout_ descriptorSetLayout, PipelineBindPoint_ pipelineBindPoint, PipelineLayout_ pipelineLayout, uint32_t set),
			DescriptorUpdateEntries(descriptorUpdateEntries).
			TemplateType(templateType).
			DescriptorSetLayout(descriptorSetLayout).
			PipelineBindPoint(pipelineBindPoint).
			PipelineLayout(pipelineLayout).
			Set(set),
			DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this, descriptorUpdateEntries, templateType, descriptorSetLayout, pipelineBindPoint, pipelineLayout, set };
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_ResultPublic(DescriptorUpdateTemplate, RESULT, Create, DescriptorUpdateTemplateCreateInfo);
		return _{ this };
	}
};

VK_ENCAPSULATION_OOP_OBJECT_BEGIN(PrivateDataSlot) {
	ObjectClassHeader(PrivateDataSlot);
	Object(const VkPrivateDataSlotCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(EmptyList) :
		Object(VkPrivateDataSlotCreateInfo{}) {}
	/* Const Function */
	// Provided by VK_API_VERSION_1_3 or VK_EXT_private_data
	RESULT SetData(ObjectType objectType, uint64_t objectHandle, uint64_t data) const {
		return M_ConditionalDispatch(SetPrivateData, EXT, objectType, objectHandle, handle, data);
	}
	void GetData(ObjectType objectType, uint64_t objectHandle, uint64_t& data) const {
		M_ConditionalDispatch(GetPrivateData, EXT, objectType, objectHandle, handle, data);
	}
	/* Non-const Function */
	// Provided by VK_API_VERSION_1_3 or VK_EXT_private_data
	RESULT Create(const PrivateDataSlotCreateInfo& createInfo) {
		Result result = Base_T::Create(createInfo);
		if (result)
			OutputMessage("[ vke::oop::PrivateDataSlot ] ERROR\nFailed to create a private data slot!\nError code: {}\n", string_VkResult(result));
		return result;
	}
	AUTO   Create() {
		DefineFunctionRaiiClass_Result(PrivateDataSlot, RESULT, Create, PrivateDataSlotCreateInfo, , , DefineSetter_Copy(Flags, decltype(_::flags), flags));
		return _{ this };
	}
};

class BufferMemory : public Object<VkBuffer>, public Object<VkDeviceMemory> {
protected:
	using Buffer = Buffer_;
	using DeviceMemory = DeviceMemory_;
	using Object<Buffer>::Create;
	using Object<DeviceMemory>::Allocate;
	void AreBound(bool areBound) { padding.bytes[0] = areBound; }
public:
	BufferMemory() = default;
	BufferMemory(const BufferCreateInfo& createInfo, MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next_allocateInfo = {}) {
		Create(createInfo, desiredMemoryProperties, next_allocateInfo);
	}
	/* Getter */
	operator const Buffer&() const { return Object<Buffer>::operator const VkBuffer&(); }
	const Buffer* AddressOfBuffer() const { return Object<Buffer>::operator&(); }
	operator const DeviceMemory&() const { return Object<DeviceMemory>::operator const VkDeviceMemory&(); }
	const DeviceMemory* AddressOfMemory() const { return Object<DeviceMemory>::operator&(); }
	bool AreBound() const { return padding.bytes[0]; }
	/* Non-const Function */
	auto   CreateBuffer(auto... arguments) {
		return Object<Buffer>::Create(arguments...);
	}
	RESULT AllocateMemory(MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next = {}, bool mayAlias = false) {
		auto allocateInfo = MemoryAllocateInfo(desiredMemoryProperties);
		if (allocateInfo.memoryTypeIndex >= VkeApp::Base().PhysicalDevice().MemoryProperties().memoryTypeCount) {
			OutputMessage("[ vke::oop::BufferMemory ] ERROR\nFailed to find any memory type satisfies all desired memory properties!\n");
			return VK_RESULT_MAX_ENUM; // No proper VkResult enum value
		}
		auto dedicatedAllocateInfo = MemoryDedicatedAllocateInfo{}.Buffer(*this);
		if (!mayAlias &&
			VkeApp::Base().ApiVersion() >= VK_API_VERSION_1_1)
			allocateInfo.PNext(&dedicatedAllocateInfo),
			dedicatedAllocateInfo.PNext(&next);
		else
			allocateInfo.PNext(&next);
		return Allocate(allocateInfo);
	}
	RESULT BindMemory() {
		if (Result result = Object<Buffer>::BindMemory(*this))
			return result;
		AreBound(true);
		return VK_SUCCESS;
	}
	// Creat buffer, allocate memory, then attach memory to the buffer.
	RESULT Create(const BufferCreateInfo& createInfo, MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next_allocateInfo = {}, bool mayAlias = false) {
		Result result;
		false || // Auto formatting alignment
			(result = CreateBuffer(createInfo)) ||
			(result = AllocateMemory(desiredMemoryProperties, next_allocateInfo, mayAlias)) ||
			(result = BindMemory());
		return result;
	}
};

class ImageMemory : public Object<VkImage>, public Object<VkDeviceMemory> {
protected:
	using Image = Image_;
	using DeviceMemory = DeviceMemory_;
	using Object<Image>::Create;
	using Object<DeviceMemory>::Allocate;
	void AreBound(bool areBound) { padding.bytes[0] = areBound; }
public:
	ImageMemory() = default;
	ImageMemory(const ImageCreateInfo& createInfo, MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next_allocateInfo = {}) {
		Create(createInfo, desiredMemoryProperties, next_allocateInfo);
	}
	/* Getter */
	operator const Image&() const { return Object<Image>::operator const VkImage&(); }
	const Image* AddressOfImage() const { return Object<Image>::operator&(); }
	operator const DeviceMemory&() const { return Object<DeviceMemory>::operator const VkDeviceMemory&(); }
	const DeviceMemory* AddressOfMemory() const { return Object<DeviceMemory>::operator&(); }
	bool AreBound() const { return padding.bytes[0]; }
	/* Non-const Function */
	auto   CreateImage(auto... arguments) {
		return Object<Image>::Create(arguments...);
	}
	RESULT AllocateMemory(MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next = {}, bool mayAlias = false) {
		auto allocateInfo = MemoryAllocateInfo(desiredMemoryProperties);
		if (allocateInfo.memoryTypeIndex >= VkeApp::Base().PhysicalDevice().MemoryProperties().memoryTypeCount) {
			OutputMessage("[ vke::oop::ImageMemory ] ERROR\nFailed to find any memory type satisfies all desired memory properties!\n");
			return VK_RESULT_MAX_ENUM; // No proper VkResult enum value
		}
		auto dedicatedAllocateInfo = MemoryDedicatedAllocateInfo{}.Image(*this);
		if (!mayAlias &&
			VkeApp::Base().ApiVersion() >= VK_API_VERSION_1_1)
			allocateInfo.PNext(&dedicatedAllocateInfo),
			dedicatedAllocateInfo.PNext(&next);
		else
			allocateInfo.PNext(&next);
		return Allocate(allocateInfo);
	}
	RESULT BindMemory() {
		if (Result result = Object<Image>::BindMemory(*this))
			return result;
		AreBound(true);
		return VK_SUCCESS;
	}
	// Creat image, allocate memory, then attach memory to the image.
	RESULT Create(const ImageCreateInfo& createInfo, MemoryPropertyFlags desiredMemoryProperties, STypeStructureRef<true> next_allocateInfo = {}, bool mayAlias = false) {
		Result result;
		false || // Auto formatting alignment
			(result = CreateImage(createInfo)) ||
			(result = AllocateMemory(desiredMemoryProperties, next_allocateInfo, mayAlias)) ||
			(result = BindMemory());
		return result;
	}
};

using Buffer = Object<Buffer>;
using Image = Object<Image>;
using Queue = Object<Queue>;
using Semaphore = Object<Semaphore>;
using CommandBuffer = Object<CommandBuffer>;
using Fence = Object<Fence>;
using DeviceMemory = Object<DeviceMemory>;
using Event = Object<Event>;
using QueryPool = Object<QueryPool>;
using BufferView = Object<BufferView>;
using ImageView = Object<ImageView>;
using ShaderModule = Object<ShaderModule>;
using PipelineCache = Object<PipelineCache>;
using PipelineLayout = Object<PipelineLayout>;
using Pipeline = Object<Pipeline>;
using RenderPass = Object<RenderPass>;
using DescriptorSetLayout = Object<DescriptorSetLayout>;
using Sampler = Object<Sampler>;
using DescriptorSet = Object<DescriptorSet>;
using DescriptorPool = Object<DescriptorPool>;
using Framebuffer = Object<Framebuffer>;
using CommandPool = Object<CommandPool>;
using SamplerYcbcrConversion = Object<SamplerYcbcrConversion>;
using DescriptorUpdateTemplate = Object<DescriptorUpdateTemplate>;
using PrivateDataSlot = Object<PrivateDataSlot>;

VK_ENCAPSULATION_NAMESPACE_END

VK_ENCAPSULATION_NAMESPACE_BEGIN
#ifndef VK_ENCAPSULATION_OOP_NO_UPPER_CASE_TYPE_NAME
using BUFFER                   = oop::Object<Buffer>;
using IMAGE                    = oop::Object<Image>;
using QUEUE                    = oop::Object<Queue>;
using SEMAPHORE                = oop::Object<Semaphore>;
using COMMANDBUFFER            = oop::Object<CommandBuffer>;
using FENCE                    = oop::Object<Fence>;
using DEVICEMEMORY             = oop::Object<DeviceMemory>;
using EVENT                    = oop::Object<Event>;
using QUERYPOOL                = oop::Object<QueryPool>;
using BUFFERVIEW               = oop::Object<BufferView>;
using IMAGEVIEW                = oop::Object<ImageView>;
using SHADERMODULE             = oop::Object<ShaderModule>;
using PIPELINECACHE            = oop::Object<PipelineCache>;
using PIPELINELAYOUT           = oop::Object<PipelineLayout>;
using PIPELINE                 = oop::Object<Pipeline>;
using RENDERPASS               = oop::Object<RenderPass>;
using DESCRIPTORSETLAYOUT      = oop::Object<DescriptorSetLayout>;
using SAMPLER                  = oop::Object<Sampler>;
using DESCRIPTORSET            = oop::Object<DescriptorSet>;
using DESCRIPTORPOOL           = oop::Object<DescriptorPool>;
using FRAMEBUFFER              = oop::Object<Framebuffer>;
using COMMANDPOOL              = oop::Object<CommandPool>;
using SAMPLERYCBCRCONVERSION   = oop::Object<SamplerYcbcrConversion>;
using DESCRIPTORUPDATETEMPLATE = oop::Object<DescriptorUpdateTemplate>;
using PRIVATEDATASLOT          = oop::Object<PrivateDataSlot>;
using BUFFERMEMORY             = oop::BufferMemory;
using IMAGEMEMORY              = oop::ImageMemory;
#endif
VK_ENCAPSULATION_NAMESPACE_END

#undef ParameterList
#undef DefineFunctionRaiiClass
#undef DefineFunctionRaiiClass_L
#undef DefineFunctionRaiiClass_TwoStruct
#undef DefineFunctionRaiiClass_Result
#undef DefineFunctionRaiiClass_ResultL
#undef DefineFunctionRaiiClass_ResultR
#undef DefineFunctionRaiiClass_ResultPublic
#undef DefineFunctionRaiiClass_ResultPublicR
#undef DefineSetter_Copy
#undef DefineSetter_ArrayRef
#undef ObjectClassHeader