#pragma once
#include "Core/VKEncapsulation.h"
#ifndef M_StbHeader
#include "stb_image.h"
#else
#include M_StbHeader(stb_image.h)
#endif

#define VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN namespace VK_ENCAPSULATION_NAMESPACE::ext {

VK_ENCAPSULATION_NAMESPACE_BEGIN

template<std::signed_integral T>
constexpr bool Between_Open(T min, T num, T max) {
	return ((min - num) & (num - max)) < 0;
}
template<std::signed_integral T>
constexpr bool Between_Closed(T min, T num, T max) {
	return ((num - min) | (max - num)) >= 0;
}

class ApplicationBasePlus {
	static constexpr uint32_t formatCount_v1_0 = 185;

	FormatProperties_ formatProperties[formatCount_v1_0] = {};
	oop::CommandPool commandPool;
	oop::CommandBuffer commandBuffer;

	/* Static */
	static ApplicationBasePlus singleton;

	/* Constructor */
	ApplicationBasePlus() {
		auto Initialize = [] {
			static constexpr QueueFlags queueFlags = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT;
			for (size_t i = 0; i < VkeApp::Base().QueueFamilyCount(); i++)
				if ((VkeApp::Base().QueueFamilyProperties(i).queueFlags & queueFlags) == queueFlags)
					singleton.commandPool.Create(CommandPoolCreateInfo{}.QueueFamilyIndex(i).Flags(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT)),
					singleton.commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, singleton.commandBuffer);
			for (size_t i = 0; i < std::size(singleton.formatProperties); i++)
				GetPhysicalDeviceFormatProperties(Format(i), singleton.formatProperties[i]);
		};
		auto CleanUp = [] {
			singleton.commandPool.~Object();
		};
		VkeApp::Plus(singleton);
		VkeApp::Base().AddCallback_CreateDevice(Initialize);
		VkeApp::Base().AddCallback_DestroyDevice(CleanUp);
	}
	ApplicationBasePlus(ApplicationBasePlus&&) = delete;
public:
	/* Getter */
	const FormatProperties_& FormatProperties(Format format) const {
		return formatProperties[format];
	}
	const oop::CommandPool& CommandPool() const { return commandPool; }
	const oop::CommandBuffer& CommandBuffer() const { return commandBuffer; }
	/* Const Function */
	RESULT ExecuteCommandBuffer(CommandBuffer_ commandBuffer = ThreadContext::CommandBuffer()) const {
		if (ThreadContext::CommandBuffer())
			EndCommandBuffer();
		oop::Fence fence({});
		Result result = VkeApp::Base().SubmitCommandBuffers(SubmitInfo{}.CommandBuffers(commandBuffer), fence);
		if (!result)
			fence.Wait();
		return result;
	}
};
M_DefineStaticDataMember(ApplicationBasePlus::singleton);

VK_ENCAPSULATION_NAMESPACE_END

VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN

struct GraphicsPipelineCreateInfoPack{
	GraphicsPipelineCreateInfo createInfo;
	// Shader
	std::vector<PipelineShaderStageCreateInfo> shaderStageCis;
	// Vertex Input
	PipelineVertexInputStateCreateInfo vertexInputStateCi;
	std::vector<VertexInputBindingDescription> vertexInputBindings;
	std::vector<VertexInputAttributeDescription> vertexInputAttributes;
	// Input Assembly
	PipelineInputAssemblyStateCreateInfo inputAssemblyStateCi;
	// Tessellation
	PipelineTessellationStateCreateInfo tessellationStateCi;
	// Viewport
	PipelineViewportStateCreateInfo viewportStateCi;
	std::vector<Viewport> viewports;
	std::vector<Rect2D> scissors;
	uint32_t dynamicViewportCount = 1;
	uint32_t dynamicScissorCount = 1;
	// Rasterization
	PipelineRasterizationStateCreateInfo rasterizationStateCi;
	// Multisample
	PipelineMultisampleStateCreateInfo multisampleStateCi;
	// Depth & Stencil
	PipelineDepthStencilStateCreateInfo depthStencilStateCi;
	PipelineColorBlendStateCreateInfo colorBlendStateCi;
	std::vector<PipelineColorBlendAttachmentState> colorBlendAttachmentStates;
	// Dynamic
	PipelineDynamicStateCreateInfo dynamicStateCi;
	std::vector<DynamicState> dynamicStates;

	/* Constructor */
	GraphicsPipelineCreateInfoPack() {
		SetCreateInfos();
	}
	GraphicsPipelineCreateInfoPack(const GraphicsPipelineCreateInfoPack& other) noexcept {
		createInfo = other.createInfo;
		SetCreateInfos();

		vertexInputStateCi = other.vertexInputStateCi;
		inputAssemblyStateCi = other.inputAssemblyStateCi;
		tessellationStateCi = other.tessellationStateCi;
		viewportStateCi = other.viewportStateCi;
		rasterizationStateCi = other.rasterizationStateCi;
		multisampleStateCi = other.multisampleStateCi;
		depthStencilStateCi = other.depthStencilStateCi;
		colorBlendStateCi = other.colorBlendStateCi;
		dynamicStateCi = other.dynamicStateCi;

		shaderStageCis = other.shaderStageCis;
		vertexInputBindings = other.vertexInputBindings;
		vertexInputAttributes = other.vertexInputAttributes;
		viewports = other.viewports;
		scissors = other.scissors;
		colorBlendAttachmentStates = other.colorBlendAttachmentStates;
		dynamicStates = other.dynamicStates;
		UpdateAllArrayAddresses();
	}
	/* Const Function */
	operator const GraphicsPipelineCreateInfo&() const { return createInfo; }
	const GraphicsPipelineCreateInfo* operator&() const { return &createInfo; }
	operator oop::Pipeline() const { return oop::Pipeline{ VK_NULL_HANDLE, createInfo }; }
	/* Non-const Function */
	void UpdateAllArrays() {
		createInfo.stageCount = shaderStageCis.size();
		vertexInputStateCi.vertexBindingDescriptionCount = vertexInputBindings.size();
		vertexInputStateCi.vertexAttributeDescriptionCount = vertexInputAttributes.size();
		viewportStateCi.viewportCount = viewports.size() ? uint32_t(viewports.size()) : dynamicViewportCount;
		viewportStateCi.scissorCount = scissors.size() ? uint32_t(scissors.size()) : dynamicScissorCount;
		colorBlendStateCi.attachmentCount = colorBlendAttachmentStates.size();
		dynamicStateCi.dynamicStateCount = dynamicStates.size();
		UpdateAllArrayAddresses();
	}
protected:
	void SetCreateInfos() {
		createInfo.pVertexInputState = &vertexInputStateCi;
		createInfo.pInputAssemblyState = &inputAssemblyStateCi;
		createInfo.pTessellationState = &tessellationStateCi;
		createInfo.pViewportState = &viewportStateCi;
		createInfo.pRasterizationState = &rasterizationStateCi;
		createInfo.pMultisampleState = &multisampleStateCi;
		createInfo.pDepthStencilState = &depthStencilStateCi;
		createInfo.pColorBlendState = &colorBlendStateCi;
		createInfo.pDynamicState = &dynamicStateCi;
	}
	void UpdateAllArrayAddresses() {
		createInfo.pStages = shaderStageCis.data();
		vertexInputStateCi.pVertexBindingDescriptions = vertexInputBindings.data();
		vertexInputStateCi.pVertexAttributeDescriptions = vertexInputAttributes.data();
		viewportStateCi.pViewports = viewports.data();
		viewportStateCi.pScissors = scissors.data();
		colorBlendStateCi.pAttachments = colorBlendAttachmentStates.data();
		dynamicStateCi.pDynamicStates = dynamicStates.data();
	}
};

#pragma region Synchronization
class RenderingLoopSynchronization {
protected:
	std::vector<oop::Fence> fences;
	std::vector<oop::Semaphore> semaphores_imageIsAvailable;
	std::vector<oop::Semaphore> semaphores_renderingIsOver;
	uint32_t index_swapImage = 0;
public:
	RenderingLoopSynchronization() :
		fences(VkeApp::Base().SwapchainImageCount()),
		semaphores_imageIsAvailable(VkeApp::Base().SwapchainImageCount() + 1),
		semaphores_renderingIsOver(VkeApp::Base().SwapchainImageCount()) {
		for (auto& i : fences)
			i.Create(FLAGS{ VK_FENCE_CREATE_SIGNALED_BIT });
		for (auto& i : semaphores_imageIsAvailable)
			i.Create();
		for (auto& i : semaphores_renderingIsOver)
			i.Create();
	}
	/* Getter */
	const oop::Fence& Fence() const { return fences[*this]; }
	Semaphore Semaphore_ImageIsAvailable() const { return semaphores_imageIsAvailable[index_swapImage]; }
	Semaphore Semaphore_RenderingIsOver() const { return semaphores_renderingIsOver[*this]; }
	/* Const Function */
	operator uint32_t() const { return VkeApp::Base().CurrentSwapchainImageIndex(); }
	/* Non-const Function */
	RESULT SwapImage() {
		index_swapImage = (index_swapImage + 1) % semaphores_imageIsAvailable.size();
		return VkeApp::Base().SwapImage(Semaphore_ImageIsAvailable());
	}
};
#pragma endregion

#pragma region Format
#include "Format.h"

inline const FormatProperties_& FormatProperties(Format format) {
#ifndef NDEBUG
	if (!Between_Open<int32_t>(0, format, std::size(FormatInfo::formatInfos_v1_0)))
		OutputMessage("[ vke::ext::FormatProperties ] ERROR\nThis function only supports definite formats provided by VK_API_VERSION_1_0.\n"),
		abort();
#endif
	return VkeApp::Plus().FormatProperties(format);
}
#pragma endregion

#pragma region Buffer
class StagingBuffer {
	static inline class StagingBuffer_MainThread_T {
		StagingBuffer* pointer; // Pimpl, it's not allowed to define a enclosing class object as a non-static data member of the nested class
		StagingBuffer* Create() {
			static StagingBuffer stagingBuffer;
			// Following code is the purpose of this class,
			// the callback lambda will set StagingBuffer.bufferMemory.allocationSize to 0, it's not necessary if you don't need to recreate logical device.
			VkeApp::Base().AddCallback_DestroyDevice([] { stagingBuffer.~StagingBuffer(); });
			return std::addressof(stagingBuffer);
		}
	public:
		StagingBuffer_MainThread_T() : pointer(Create()) {}
		StagingBuffer& Get() const { return *pointer; }
	} stagingBuffer_mainThread;
protected:
	oop::BufferMemory bufferMemory;
	DeviceSize memoryUsage = 0;
	oop::Image aliasedImage;
public:
	StagingBuffer() = default;
	StagingBuffer(DeviceSize size) {
		Expand(size);
	}
	/* Getter */
	const oop::Buffer& Buffer() const { return bufferMemory; }
	operator const Buffer_&() const { return bufferMemory; }
	const Buffer_* operator&() const { return bufferMemory.AddressOfBuffer(); }
	DeviceSize AllocationSize() const { return bufferMemory.AllocationSize(); }
	const oop::Image& AliasedImage() const { return aliasedImage; }
	/* Const Function */
	void RetrieveData(ArrayRef<void> data) const {
		bufferMemory.RetrieveData(data);
	}
	void RetrieveData(IsNotRangeOrPointer auto& data) const {
		bufferMemory.RetrieveData(data);
	}
	/* Non-const Function */
	void Expand(DeviceSize size) {
		if (size <= AllocationSize())
			return;
		Release();
		bufferMemory.Create(BufferCreateInfo{}.
			Size(size).
			Usage(VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT),
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
			{}, true);
	}
	void Release() {
		bufferMemory.~BufferMemory();
	}
	void* MapMemory(DeviceSize size) {
		Expand(size);
		void* pData = nullptr;
		bufferMemory.Map(0, size, 0, pData);
		memoryUsage = size;
		return pData;
	}
	void UnmapMemory() {
		bufferMemory.Unmap(0, memoryUsage);
		memoryUsage = 0;
	}
	void BufferData(ArrayRef<const void> data) {
		Expand(data.size());
		bufferMemory.BufferData(data);
	}
	void BufferData(const IsNotRangeOrPointer auto& data) {
		Expand(sizeof *&data);
		bufferMemory.BufferData(data);
	}
	// Create single 2d image of linear tiling.
	[[nodiscard]]
	Image AliasedImage2D(Format format, Extent2D extent) {
		return AliasedImage(VK_IMAGE_TYPE_2D, format, { extent.width, extent.height, 1 }, 1);
	}
	// Almost useless, drivers barely support linear 2d image array or linear 3d image.
	[[nodiscard]]
	Image AliasedImage(ImageType imageType, Format format, Ref<const Extent3D> extent, uint32_t layerCount) {
		// Highly possible that the implementation may have strict limits on images of linear tiling.
		if (!(FormatProperties(format).linearTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT))
			return VK_NULL_HANDLE;
		// Check allocation size
		DeviceSize dataSizePerImage = DeviceSize(FormatInfo(format).sizePerPixel) * extent.width * extent.height * extent.depth;
		DeviceSize imageDataSize = dataSizePerImage * layerCount;
		if (imageDataSize > AllocationSize())
			return VK_NULL_HANDLE;
		// Check format properties
		ImageFormatProperties imageFormatProperties;
		GetPhysicalDeviceImageFormatProperties(format, imageType, VK_IMAGE_TILING_LINEAR, VK_IMAGE_USAGE_TRANSFER_SRC_BIT, 0, imageFormatProperties);
		if (extent.width > imageFormatProperties.maxExtent.width ||
			extent.height > imageFormatProperties.maxExtent.height ||
			extent.depth > imageFormatProperties.maxExtent.depth ||
			layerCount > imageFormatProperties.maxArrayLayers ||
			imageDataSize > imageFormatProperties.maxResourceSize)
			return VK_NULL_HANDLE;
		aliasedImage.~Object();
		aliasedImage.Create(ImageCreateInfo{}.
			ImageType(imageType).
			Format(format).
			Extent(extent).
			ArrayLayers(layerCount).
			Tiling(VK_IMAGE_TILING_LINEAR).
			Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT).
			InitialLayout(VK_IMAGE_LAYOUT_PREINITIALIZED));
		// No padding bytes
		SubresourceLayout subresourceLayout;
		GetImageSubresourceLayout(aliasedImage, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0 }, subresourceLayout);
		if (subresourceLayout.size != dataSizePerImage || (
			layerCount > 1 &&
			subresourceLayout.arrayPitch != dataSizePerImage))
			return VK_NULL_HANDLE;
		aliasedImage.BindMemory(bufferMemory);
		return aliasedImage;
	}
	/* Static Function */
	static StagingBuffer& Buffer_MainThread() {
		return stagingBuffer_mainThread.Get();
	}
};

class DeviceLocalBuffer {
protected:
	oop::BufferMemory bufferMemory;
public:
	DeviceLocalBuffer() = default;
	DeviceLocalBuffer(DeviceSize size, BufferUsageFlags desiredUsages_Without_transfer_dst, STypeStructureRef<true> next_allocateInfo = {}) {
		Create(size, desiredUsages_Without_transfer_dst, next_allocateInfo);
	}
	/* Getter */
	const oop::Buffer& Buffer() const { return bufferMemory; }
	operator const Buffer_&() const { return bufferMemory; }
	const Buffer_* operator&() const { return bufferMemory.AddressOfBuffer(); }
	DeviceSize AllocationSize() const { return bufferMemory.AllocationSize(); }
	/* Const Function */
	void TransferData(ArrayRef<const void> data, DeviceSize offset = 0) const {
		if (bufferMemory.MemoryProperties() & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) {
			bufferMemory.BufferData(data, offset);
			return;
		}
		StagingBuffer::Buffer_MainThread().BufferData(data);
		VkeApp::Plus().CommandBuffer().Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });
		CmdCopyBuffer(StagingBuffer::Buffer_MainThread(), bufferMemory, BufferCopy{ 0, offset, data.size() });
		VkeApp::Plus().ExecuteCommandBuffer();
	}
	void TransferData(const IsNotRangeOrPointer auto& data, DeviceSize offset = 0) const {
		TransferData({ sizeof *&data, &data }, offset);
	}
	void TransferData(const void* pSrc, uint32_t elementCount, DeviceSize elementSize, DeviceSize srcStride, DeviceSize dstStride, DeviceSize offset = 0) const {
		if (bufferMemory.MemoryProperties() & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) {
			void* pDst = nullptr;
			bufferMemory.Map(offset, dstStride * elementCount, 0, pDst);
			for (size_t i = 0; i < elementCount; i++)
				std::memcpy(dstStride * i + static_cast<uint8_t*>(pDst), srcStride * i + static_cast<const uint8_t*>(pSrc), elementSize);
			bufferMemory.Unmap(offset, dstStride * elementCount);
			return;
		}
		StagingBuffer::Buffer_MainThread().BufferData({ srcStride * elementCount, pSrc });
		VkeApp::Plus().CommandBuffer().Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });
		std::unique_ptr regions = std::make_unique<BufferCopy[]>(elementCount);
		for (size_t i = 0; i < elementCount; i++)
			regions[i] = { srcStride * i, dstStride * i + offset, elementSize };
		CmdCopyBuffer(StagingBuffer::Buffer_MainThread(), bufferMemory, { elementCount, regions.get() });
		VkeApp::Plus().ExecuteCommandBuffer();
	}
	void CmdUpdate(ArrayRef<const void> data, DeviceSize offset = 0) const {
		bufferMemory.CmdUpdate(offset, data);
	}
	void CmdUpdate(const IsNotRangeOrPointer auto& data, DeviceSize offset = 0) const {
		bufferMemory.CmdUpdate(offset, data);
	}
	// Provided by VK_API_VERSION_1_2
	// Buffer must be created with VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT.
	DeviceAddress DeviceAddress() const {
		return GetBufferDeviceAddress(BufferDeviceAddressInfo{}.Buffer(bufferMemory));
	}
	/* Nno-const Function */
	void Create(DeviceSize size, BufferUsageFlags desiredUsages_Without_transfer_dst, STypeStructureRef<true> next_allocateInfo = {}) {
		Result result;
		false ||
			(result = bufferMemory.CreateBuffer(BufferCreateInfo{}.Size(size).Usage(desiredUsages_Without_transfer_dst | VK_BUFFER_USAGE_TRANSFER_DST_BIT))) ||
			(result = bufferMemory.AllocateMemory(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, next_allocateInfo)) && // Try allocating host-visible memory
			(result = bufferMemory.AllocateMemory(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, next_allocateInfo)) ||
			(result = bufferMemory.BindMemory());
		RESULT{ result }; // To throw
	}
	void Recreate(DeviceSize size, BufferUsageFlags desiredUsages_Without_transfer_dst, STypeStructureRef<true> next_allocateInfo = {}) {
		bufferMemory.~BufferMemory();
		Create(size, desiredUsages_Without_transfer_dst, next_allocateInfo);
	}
};

inline DeviceSize AlignedSizeOfUniformBuffer(DeviceSize dataSize) {
	const DeviceSize& alignment = VkeApp::Base().PhysicalDevice().Properties().limits.minUniformBufferOffsetAlignment;
	return dataSize + alignment - 1 & ~(alignment - 1);
}

inline DeviceSize AlignedSizeOfStorageBuffer(DeviceSize dataSize) {
	const DeviceSize& alignment = VkeApp::Base().PhysicalDevice().Properties().limits.minStorageBufferOffsetAlignment;
	return dataSize + alignment - 1 & ~(alignment - 1);
}
#pragma endregion

#pragma region Attachment
class Attachment {
protected:
	oop::ImageView imageView;
	oop::ImageMemory imageMemory;
	Attachment() = default;
public:
	/* Getter */
	operator const ImageView&() const { return imageView; }
	const ImageView* AddressOfImageView() const { return &imageView; }
	operator const Image&() const { return imageMemory; }
	const Image* AddressOfImage() const { return imageMemory.AddressOfImage(); }
	/* Const Function */
	DescriptorImageInfo DescriptorImageInfo(Sampler sampler) const {
		return { sampler, imageView, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL };
	}
};

class ColorAttachment : public Attachment {
public:
	ColorAttachment() = default;
	ColorAttachment(Format format, Extent2D extent, uint32_t layerCount = 1, SampleCountFlagBits sampleCount = VK_SAMPLE_COUNT_1_BIT, ImageUsageFlags otherUsages = 0) {
		Create(format, extent, layerCount, sampleCount, otherUsages);
	}
	/* Non-const Function */
	void Create(Format format, Extent2D extent, uint32_t layerCount = 1, SampleCountFlagBits sampleCount = VK_SAMPLE_COUNT_1_BIT, ImageUsageFlags otherUsages = 0) {
		imageMemory.Create(ImageCreateInfo{}.
			ImageType(VK_IMAGE_TYPE_2D).
			Format(format).
			Extent({ extent.width, extent.height, 1 }).
			ArrayLayers(layerCount).
			Samples(sampleCount).
			Usage(VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | otherUsages),
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | bool(otherUsages & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) * VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
		imageView.Create(ImageViewCreateInfo{}.
			Image(imageMemory).
			ViewType(layerCount > 1 ? VK_IMAGE_VIEW_TYPE_2D_ARRAY : VK_IMAGE_VIEW_TYPE_2D).
			Format(format).
			SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, layerCount }));
	}
	/* Static Function */
	static bool FormatAvailability(Format format, bool supportBlending = true) {
		return FormatProperties(format).optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT << uint32_t(supportBlending);
	}
};

class DepthStencilAttachment : public Attachment {
public:
	DepthStencilAttachment() = default;
	DepthStencilAttachment(Format format, Extent2D extent, uint32_t layerCount = 1, SampleCountFlagBits sampleCount = VK_SAMPLE_COUNT_1_BIT, ImageUsageFlags otherUsages = 0, bool stencilOnly = false) {
		Create(format, extent, layerCount, sampleCount, otherUsages, stencilOnly);
	}
	/* Non-const Function */
	void Create(Format format, Extent2D extent, uint32_t layerCount = 1, SampleCountFlagBits sampleCount = VK_SAMPLE_COUNT_1_BIT, ImageUsageFlags otherUsages = 0, bool stencilOnly = false) {
		imageMemory.Create(ImageCreateInfo{}.
			ImageType(VK_IMAGE_TYPE_2D).
			Format(format).
			Extent({ extent.width, extent.height, 1 }).
			ArrayLayers(layerCount).
			Samples(sampleCount).
			Usage(VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | otherUsages),
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | bool(otherUsages & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) * VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
		ImageAspectFlags aspectMask = (!stencilOnly) * VK_IMAGE_ASPECT_DEPTH_BIT;
		if (format > VK_FORMAT_S8_UINT)
			aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;
		else if (format == VK_FORMAT_S8_UINT)
			aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT;
		imageView.Create(ImageViewCreateInfo{}.
			Image(imageMemory).
			ViewType(layerCount > 1 ? VK_IMAGE_VIEW_TYPE_2D_ARRAY : VK_IMAGE_VIEW_TYPE_2D).
			Format(format).
			SubresourceRange({ aspectMask, 0, 1, 0, layerCount }));
	}
	/* Static Function */
	static bool FormatAvailability(Format format) {
		return FormatProperties(format).optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT;
	}
};
#pragma endregion

#pragma region Texture
struct ImageOperation {
	struct ImageMemoryBarrierParameterPack {
		const bool isNeeded = false;
		const PipelineStageFlags stage = 0;
		const AccessFlags access = 0;
		const ImageLayout layout = VK_IMAGE_LAYOUT_UNDEFINED;
		constexpr ImageMemoryBarrierParameterPack() = default;
		constexpr ImageMemoryBarrierParameterPack(PipelineStageFlags stage, AccessFlags access, ImageLayout layout) :
			isNeeded(true), stage(stage), access(access), layout(layout) {}
	};
	static void CmdCopyBufferToImage(Buffer buffer, Image image, Ref<const BufferImageCopy> region, const ImageMemoryBarrierParameterPack& imb_from, const ImageMemoryBarrierParameterPack& imb_to) {
		// Pre-copy barrier
		if (imb_from.isNeeded)
			CmdPipelineBarrier(imb_from.stage, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
				SrcAccessMask(imb_from.access).
				DstAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
				OldLayout(imb_from.layout).
				NewLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
				Image(image).
				SubresourceRange({
					region.imageSubresource.aspectMask,
					region.imageSubresource.mipLevel,
					1,
					region.imageSubresource.baseArrayLayer,
					region.imageSubresource.layerCount }));
		// Copy
		VK_ENCAPSULATION_NAMESPACE::CmdCopyBufferToImage(buffer, image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, region);
		// Post-copy barrier
		if (imb_to.isNeeded)
			CmdPipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, imb_to.stage, 0, {}, {}, ImageMemoryBarrier{}.
				SrcAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
				DstAccessMask(imb_to.access).
				OldLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
				NewLayout(imb_to.layout).
				Image(image).
				SubresourceRange({
					region.imageSubresource.aspectMask,
					region.imageSubresource.mipLevel,
					1,
					region.imageSubresource.baseArrayLayer,
					region.imageSubresource.layerCount }));
	}
	static void CmdBlitImage(Image image_src, Image image_dst, Ref<const ImageBlit> region, const ImageMemoryBarrierParameterPack& imb_dst_from, const ImageMemoryBarrierParameterPack& imb_dst_to, Filter filter = VK_FILTER_LINEAR) {
		// Pre-blit barrier
		if (imb_dst_from.isNeeded)
			CmdPipelineBarrier(imb_dst_from.stage, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
				SrcAccessMask(imb_dst_from.access).
				DstAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
				OldLayout(imb_dst_from.layout).
				NewLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
				Image(image_dst).
				SubresourceRange({
					region.dstSubresource.aspectMask,
					region.dstSubresource.mipLevel,
					1,
					region.dstSubresource.baseArrayLayer,
					region.dstSubresource.layerCount }));
		// Blit
		VK_ENCAPSULATION_NAMESPACE::CmdBlitImage(
			image_src, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
			image_dst, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
			region, filter);
		// Post-blit barrier
		if (imb_dst_to.isNeeded)
			CmdPipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, imb_dst_to.stage, 0, {}, {}, ImageMemoryBarrier{}.
				SrcAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
				DstAccessMask(imb_dst_to.access).
				OldLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
				NewLayout(imb_dst_to.layout).
				Image(image_dst).
				SubresourceRange({
					region.dstSubresource.aspectMask,
					region.dstSubresource.mipLevel,
					1,
					region.dstSubresource.baseArrayLayer,
					region.dstSubresource.layerCount }));
	}
	static void CmdGenerateMipmap2D(Image image, Extent2D imageExtent, uint32_t mipLevelCount, uint32_t layerCount, const ImageMemoryBarrierParameterPack& imb_to, Filter minFilter = VK_FILTER_LINEAR) {
		auto MipmapExtent = [](Extent2D imageExtent, uint32_t mipLevel) {
			Offset3D extent = { int32_t(imageExtent.width >> mipLevel), int32_t(imageExtent.height >> mipLevel), 1 };
			extent.x += !extent.x;
			extent.y += !extent.y;
			return extent;
		};
		auto IsNotPowerOfTwo = [](uint32_t value) {
			return bool(value & value - 1);
		};
		// Blit
		if (layerCount > 1 &&
			(IsNotPowerOfTwo(imageExtent.width) || IsNotPowerOfTwo(imageExtent.height)) &&
			VkeApp::Base().PhysicalDevice().Properties().vendorID == 0x10de) { // Blame Nvidia
			std::unique_ptr regions = std::make_unique<ImageBlit[]>(layerCount);
			for (uint32_t i = 1; i < mipLevelCount; i++) {
				for (uint32_t j = 0; j < layerCount; j++)
					regions[j] = ImageBlit{}.
						SrcSubresource({ VK_IMAGE_ASPECT_COLOR_BIT, i - 1, j, 1 }).
						SrcOffsets({ {}, MipmapExtent(imageExtent, i - 1) }).
						DstSubresource({ VK_IMAGE_ASPECT_COLOR_BIT, i, j, 1 }).
						DstOffsets({ {}, MipmapExtent(imageExtent, i) });
				// Pre-blit barrier
				CmdPipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
					DstAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
					NewLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
					Image(image).
					SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, i, 1, 0, layerCount }));
				// Blit
				VK_ENCAPSULATION_NAMESPACE::CmdBlitImage(
					image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
					image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
					{ layerCount, regions.get() }, minFilter);
				// Post-blit barrier
				CmdPipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
					SrcAccessMask(VK_ACCESS_TRANSFER_WRITE_BIT).
					DstAccessMask(VK_ACCESS_TRANSFER_READ_BIT).
					OldLayout(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL).
					NewLayout(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL).
					Image(image).
					SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, i, 1, 0, layerCount }));
			}
		}
		else
			for (uint32_t i = 1; i < mipLevelCount; i++)
				CmdBlitImage(image, image, {
					{ VK_IMAGE_ASPECT_COLOR_BIT, i - 1, 0, layerCount }, // srcSubresource
					{ {}, MipmapExtent(imageExtent, i - 1) },            // srcOffsets
					{ VK_IMAGE_ASPECT_COLOR_BIT, i, 0, layerCount },     // dstSubresource
					{ {}, MipmapExtent(imageExtent, i) } },              // dstOffsets
					{ VK_PIPELINE_STAGE_TRANSFER_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
					{ VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL }, minFilter);
		// Post-blit barrier
		if (imb_to.isNeeded)
			CmdPipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, imb_to.stage, 0, {}, {}, ImageMemoryBarrier{}.
				DstAccessMask(imb_to.access).
				OldLayout(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL).
				NewLayout(imb_to.layout).
				Image(image).
				SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, mipLevelCount, 0, layerCount }));
	}
};

class Texture {
protected:
	oop::ImageView imageView;
	oop::ImageMemory imageMemory;
	Texture() = default;
	/* Non-const Function */
	void CreateImageMemory(ImageType imageType, Format format, Ref<const Extent3D> extent, uint32_t mipLevelCount, uint32_t arrayLayerCount, ImageCreateFlags flags = 0) {
		imageMemory.Create(ImageCreateInfo{}.
			Flags(flags).
			ImageType(imageType).
			Format(format).
			Extent(extent).
			MipLevels(mipLevelCount).
			ArrayLayers(arrayLayerCount).
			Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT),
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
	}
	void CreateImageView(ImageViewType viewType, Format format, uint32_t mipLevelCount, uint32_t arrayLayerCount, ImageViewCreateFlags flags = 0) {
		imageView.Create(ImageViewCreateInfo{}.
			Flags(flags).
			Image(imageMemory).
			ViewType(viewType).
			Format(format).
			SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, mipLevelCount, 0, arrayLayerCount }));
	}
	/* Static Function */
	static std::unique_ptr<uint8_t[]> LoadFile_Internal(const auto* address, size_t fileSize, Ref<Extent2D> extent, FormatInfo requiredFormatInfo) {
	#ifndef NDEBUG
		if (!(requiredFormatInfo.rawDataType == FormatInfo::FloatingPoint && requiredFormatInfo.sizePerComponent == 4) &&
			!(requiredFormatInfo.rawDataType == FormatInfo::Integer && Between_Closed<int32_t>(1, requiredFormatInfo.sizePerComponent, 2)))
			OutputMessage("[ vke::ext::Texture ] ERROR\nRequired format is not available for source image data!\n"),
			abort();
	#endif
		int& width = reinterpret_cast<int&>(extent.width);
		int& height = reinterpret_cast<int&>(extent.height);
		int channelCount;
		void* pImageData = nullptr;
		if constexpr (std::same_as<decltype(address), const char*>) {
			if (requiredFormatInfo.rawDataType == FormatInfo::Integer)
				if (requiredFormatInfo.sizePerComponent == 1)
					pImageData = stbi_load(address, &width, &height, &channelCount, requiredFormatInfo.componentCount);
				else
					pImageData = stbi_load_16(address, &width, &height, &channelCount, requiredFormatInfo.componentCount);
			else
				pImageData = stbi_loadf(address, &width, &height, &channelCount, requiredFormatInfo.componentCount);
			if (!pImageData)
				OutputMessage("[ vke::ext::Texture ] ERROR\nFailed to load the file: {}\n", address);
		}
		if constexpr (std::same_as<decltype(address), const uint8_t*>) {
			if (fileSize > INT32_MAX) {
				OutputMessage("[ vke::ext::Texture ] ERROR\nFailed to load image data from the given address! Data size must be less than 2G!\n");
				return {};
			}
			if (requiredFormatInfo.rawDataType == FormatInfo::Integer)
				if (requiredFormatInfo.sizePerComponent == 1)
					pImageData = stbi_load_from_memory(address, fileSize, &width, &height, &channelCount, requiredFormatInfo.componentCount);
				else
					pImageData = stbi_load_16_from_memory(address, fileSize, &width, &height, &channelCount, requiredFormatInfo.componentCount);
			else
				pImageData = stbi_loadf_from_memory(address, fileSize, &width, &height, &channelCount, requiredFormatInfo.componentCount);
			if (!pImageData)
				OutputMessage("[ vke::ext::Texture ] ERROR\nFailed to load image data from the given address!\n");
		}
		return std::unique_ptr<uint8_t[]>(static_cast<uint8_t*>(pImageData));
	}
public:
	/* Getter */
	operator const ImageView&() const { return imageView; }
	operator const Image&() const { return imageMemory; }
	const ImageView* AddressOfImageView() const { return &imageView; }
	const Image* AddressOfImage() const { return imageMemory.AddressOfImage(); }
	/* Const Function */
	DescriptorImageInfo DescriptorImageInfo(Sampler sampler) const {
		return { sampler, imageView, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL };
	}
	/* Static Function */
	// CheckArguments(...) should only be called in tests.
	static bool CheckArguments(ImageType imageType, Ref<const Extent3D> extent, uint32_t arrayLayerCount, Format format_initial, Format format_final, bool generateMipmap) {
		auto AliasedImageAvailability = [](ImageType imageType, Format format, Ref<const Extent3D> extent, uint32_t arrayLayerCount, ImageUsageFlags usage) {
			if (!(FormatProperties(format).linearTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT))
				return false;
			ImageFormatProperties imageFormatProperties;
			GetPhysicalDeviceImageFormatProperties(format, imageType, VK_IMAGE_TILING_LINEAR, usage, 0, imageFormatProperties);
			DeviceSize imageDataSize = DeviceSize(FormatInfo(format).sizePerPixel) * extent.width * extent.height * extent.depth;
			return
				extent.width <= imageFormatProperties.maxExtent.width &&
				extent.height <= imageFormatProperties.maxExtent.height &&
				extent.depth <= imageFormatProperties.maxExtent.depth &&
				arrayLayerCount <= imageFormatProperties.maxArrayLayers &&
				imageDataSize <= imageFormatProperties.maxResourceSize;
		};
		if (FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT) {
			// Case: Copy data from pre-initialized image to final image
			if (FormatProperties(format_initial).linearTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT)
				if (AliasedImageAvailability(imageType, format_initial, extent, arrayLayerCount, VK_IMAGE_USAGE_TRANSFER_SRC_BIT))
					if (FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT &&
						generateMipmap * (FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT))
						return true;
			// Case: Copy data from staging buffer to final image
			if (format_initial == format_final)
				return
				FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_TRANSFER_DST_BIT &&
				generateMipmap * (FormatProperties(format_final).optimalTilingFeatures & (VK_FORMAT_FEATURE_BLIT_SRC_BIT | VK_FORMAT_FEATURE_BLIT_DST_BIT));
			// Case: Copy data from staging buffer to initial image, then blit initial image to final image
			else
				return
				FormatProperties(format_initial).optimalTilingFeatures & (VK_FORMAT_FEATURE_BLIT_SRC_BIT | VK_FORMAT_FEATURE_TRANSFER_DST_BIT) &&
				FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT &&
				generateMipmap * (FormatProperties(format_final).optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT);
		}
		return false;
	}
	[[nodiscard]]
	static std::unique_ptr<uint8_t[]> LoadFile(const char* filepath, Ref<Extent2D> extent, FormatInfo requiredFormatInfo) {
		return LoadFile_Internal(filepath, 0, extent, requiredFormatInfo);
	}
	[[nodiscard]]
	static std::unique_ptr<uint8_t[]> LoadFile(const uint8_t* fileBinaries, size_t fileSize, Ref<Extent2D> extent, FormatInfo requiredFormatInfo) {
		return LoadFile_Internal(fileBinaries, fileSize, extent, requiredFormatInfo);
	}
	static uint32_t CalculateMipLevelCount(Extent2D extent) {
		return uint32_t(std::floor(std::log2(std::max(extent.width, extent.height)))) + 1;
	}
	static void CopyBlitAndGenerateMipmap2D(Buffer buffer_copyFrom, Image image_copyTo, Image image_blitTo, Extent2D imageExtent, uint32_t mipLevelCount, uint32_t layerCount, Filter minFilter = VK_FILTER_LINEAR) {
		static constexpr ImageOperation::ImageMemoryBarrierParameterPack imbs[2] = {
			{ VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_ACCESS_SHADER_READ_BIT, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
			{ VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL }
		};
		bool generateMipmap = mipLevelCount > 1;
		bool blitMipLevel0 = image_copyTo != image_blitTo;
		VkeApp::Plus().CommandBuffer().Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });
		ImageOperation::CmdCopyBufferToImage(buffer_copyFrom, image_copyTo, BufferImageCopy{}.
			ImageSubresource({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, layerCount }).
			ImageExtent({ imageExtent.width, imageExtent.height, 1 }),
			{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
			imbs[generateMipmap || blitMipLevel0]);
		if (blitMipLevel0)
			ImageOperation::CmdBlitImage(image_copyTo, image_blitTo, {
				{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, layerCount },
				{ {}, { int32_t(imageExtent.width), int32_t(imageExtent.height), 1 } },
				{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, layerCount },
				{ {}, { int32_t(imageExtent.width), int32_t(imageExtent.height), 1 } } },
				{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
				imbs[generateMipmap], minFilter);
		if (generateMipmap)
			ImageOperation::CmdGenerateMipmap2D(image_blitTo, imageExtent, mipLevelCount, layerCount, imbs[0], minFilter);
		VkeApp::Plus().ExecuteCommandBuffer();
	}
	static void BlitAndGenerateMipmap2D(Image image_preinitialized, Image image_final, Extent2D imageExtent, uint32_t mipLevelCount, uint32_t layerCount, Filter minFilter = VK_FILTER_LINEAR) {
		static constexpr ImageOperation::ImageMemoryBarrierParameterPack imbs[2] = {
			{ VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_ACCESS_SHADER_READ_BIT, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
			{ VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL }
		};
		bool generateMipmap = mipLevelCount > 1;
		bool blitMipLevel0 = image_preinitialized != image_final;
		if (generateMipmap || blitMipLevel0) {
			VkeApp::Plus().CommandBuffer().Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });
			if (blitMipLevel0)
				CmdPipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, {}, {}, ImageMemoryBarrier{}.
					DstAccessMask(VK_ACCESS_TRANSFER_READ_BIT).
					OldLayout(VK_IMAGE_LAYOUT_PREINITIALIZED).
					NewLayout(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL).
					Image(image_preinitialized).
					SubresourceRange({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, layerCount })),
				ImageOperation::CmdBlitImage(image_preinitialized, image_final, {
					{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, layerCount },
					{ {}, { int32_t(imageExtent.width), int32_t(imageExtent.height), 1 } },
					{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, layerCount },
					{ {}, { int32_t(imageExtent.width), int32_t(imageExtent.height), 1 } } },
					{ VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_IMAGE_LAYOUT_UNDEFINED },
					imbs[generateMipmap], minFilter);
			if (generateMipmap)
				ImageOperation::CmdGenerateMipmap2D(image_final, imageExtent, mipLevelCount, layerCount, imbs[0], minFilter);
			VkeApp::Plus().ExecuteCommandBuffer();
		}
	}
	static SamplerCreateInfo SamplerCreateInfo() {
		return SamplerCreateInfo_{}.
			MagFilter(VK_FILTER_LINEAR).
			MinFilter(VK_FILTER_LINEAR).
			MipmapMode(VK_SAMPLER_MIPMAP_MODE_LINEAR).
			AddressModeU(VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE).
			AddressModeV(VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE).
			AddressModeW(VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE).
			MaxAnisotropy(VkeApp::Base().PhysicalDevice().Properties().limits.maxSamplerAnisotropy);
	}
};

class Texture2D : public Texture {
protected:
	Extent2D extent = {};
	/* Non-const Function */
	void Create_Internal(Format format_initial, Format format_final, bool generateMipmap) {
		uint32_t mipLevelCount = generateMipmap ? CalculateMipLevelCount(extent) : 1;
		CreateImageMemory(VK_IMAGE_TYPE_2D, format_final, { extent.width, extent.height, 1 }, mipLevelCount, 1);
		CreateImageView(VK_IMAGE_VIEW_TYPE_2D, format_final, mipLevelCount, 1);
		if (format_initial == format_final)
			CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory, imageMemory, extent, mipLevelCount, 1);
		else
			if (Image image_conversion = StagingBuffer::Buffer_MainThread().AliasedImage2D(format_initial, extent))
				BlitAndGenerateMipmap2D(image_conversion, imageMemory, extent, mipLevelCount, 1);
			else {
				oop::ImageMemory imageMemory_conversion(ImageCreateInfo{}.
					ImageType(VK_IMAGE_TYPE_2D).
					Format(format_initial).
					Extent({ extent.width, extent.height, 1 }).
					Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT),
					VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
				CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory_conversion, imageMemory, extent, mipLevelCount, 1);
			}
	}
public:
	Texture2D() = default;
	Texture2D(const char* filepath, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(filepath, format_initial, format_final, generateMipmap);
	}
	Texture2D(const uint8_t* pImageData, Extent2D extent, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(pImageData, extent, format_initial, format_final, generateMipmap);
	}
	/* Getter */
	const Extent2D& Extent() const { return extent; }
	const uint32_t& Width() const { return extent.width; }
	const uint32_t& Height() const { return extent.height; }
	/* Non-const Function */
	void Create(const char* filepath, Format format_initial, Format format_final, bool generateMipmap = true) {
		Extent2D extent;
		std::unique_ptr pImageData = LoadFile(filepath, extent, FormatInfo(format_initial));
		if (pImageData)
			Create(pImageData.get(), extent, format_initial, format_final, generateMipmap);
	}
	void Create(const uint8_t* pImageData, Extent2D extent, Format format_initial, Format format_final, bool generateMipmap = true) {
		this->extent = extent;
		size_t imageDataSize = size_t(FormatInfo(format_initial).sizePerPixel) * extent.width * extent.height;
		StagingBuffer::Buffer_MainThread().BufferData({ imageDataSize, pImageData });
		Create_Internal(format_initial, format_final, generateMipmap);
	}
};
class Texture2DArray : public Texture {
protected:
	Extent2D extent = {};
	uint32_t layerCount = 0;
	/* Non-const Function */
	void Create_Internal(Format format_initial, Format format_final, bool generateMipmap) {
		uint32_t mipLevelCount = generateMipmap ? CalculateMipLevelCount(extent) : 1;
		CreateImageMemory(VK_IMAGE_TYPE_2D, format_final, { extent.width, extent.height, 1 }, mipLevelCount, layerCount);
		CreateImageView(VK_IMAGE_VIEW_TYPE_2D_ARRAY, format_final, mipLevelCount, layerCount);
		if (format_initial == format_final)
			CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory, imageMemory, extent, mipLevelCount, layerCount);
		else {
			oop::ImageMemory imageMemory_conversion(ImageCreateInfo{}.
				ImageType(VK_IMAGE_TYPE_2D).
				Format(format_initial).
				Extent({ extent.width, extent.height, 1 }).
				ArrayLayers(layerCount).
				Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT),
				VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
			CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory_conversion, imageMemory, extent, mipLevelCount, layerCount);
		}
	}
public:
	Texture2DArray() = default;
	Texture2DArray(const char* filepath, Extent2D extentInTiles, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(filepath, extentInTiles, format_initial, format_final, generateMipmap);
	}
	Texture2DArray(const uint8_t* pImageData, Extent2D fullExtent, Extent2D extentInTiles, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(pImageData, fullExtent, extentInTiles, format_initial, format_final, generateMipmap);
	}
	Texture2DArray(ArrayRef<const char* const> filepaths, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(filepaths, format_initial, format_final, generateMipmap);
	}
	Texture2DArray(ArrayRef<const uint8_t* const> psImageData, Extent2D extent, Format format_initial, Format format_final, bool generateMipmap = true) {
		Create(psImageData, extent, format_initial, format_final, generateMipmap);
	}
	/* Getter */
	const Extent2D& Extent() const { return extent; }
	const uint32_t& Width() const { return extent.width; }
	const uint32_t& Height() const { return extent.height; }
	const uint32_t& LayerCount() const { return layerCount; }
	/* Non-const Function */
	void Create(const char* filepath, Extent2D extentInTiles, Format format_initial, Format format_final, bool generateMipmap = true) {
		if (extentInTiles.width * extentInTiles.height > VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers) {
			OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nLayer count is out of limit! Must be less than: {}\nFile: {}\n", VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers, filepath);
			return;
		}
		Extent2D fullExtent;
		std::unique_ptr pImageData = LoadFile(filepath, fullExtent, FormatInfo(format_initial));
		if (pImageData)
			if (fullExtent.width % extentInTiles.width ||
				fullExtent.height % extentInTiles.height)
				OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nImage not available!\nFile: {}\nImage width should be in multiples of: {}\nImage height should be in multiples of: {}\n", filepath, extentInTiles.width, extentInTiles.height);
			else
				Create(pImageData.get(), fullExtent, extentInTiles, format_initial, format_final, generateMipmap);
	}
	void Create(const uint8_t* pImageData, Extent2D fullExtent, Extent2D extentInTiles, Format format_initial, Format format_final, bool generateMipmap = true) {
		layerCount = extentInTiles.width * extentInTiles.height;
		if (layerCount > VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers) {
			OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nLayer count is out of limit! Must be less than: {}\n", VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers);
			return;
		}
		if (fullExtent.width % extentInTiles.width ||
			fullExtent.height % extentInTiles.height) {
			OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nImage not available!\nImage width should be in multiples of: {}\nImage height should be in multiples of: {}\n", extentInTiles.width, extentInTiles.height);
			return;
		}
		extent.width = fullExtent.width / extentInTiles.width;
		extent.height = fullExtent.height / extentInTiles.height;
		size_t dataSizePerPixel = FormatInfo(format_initial).sizePerPixel;
		size_t imageDataSize = dataSizePerPixel * fullExtent.width * fullExtent.height;
		// Data rearrangement can also be peformed by using tiled regions in vkCmdCopyBufferToImage(...).
		if (extentInTiles.width == 1)
			StagingBuffer::Buffer_MainThread().BufferData({ imageDataSize, pImageData });
		else {
			uint8_t* pDst = static_cast<uint8_t*>(StagingBuffer::Buffer_MainThread().MapMemory(imageDataSize));
			size_t dataSizePerRow = dataSizePerPixel * extent.width;
			for (size_t j = 0; j < extentInTiles.height; j++)
				for (size_t i = 0; i < extentInTiles.width; i++)
					for (size_t k = 0; k < extent.height; k++)
						std::memcpy(pDst, pImageData + (i * extent.width + (k + j * extent.height) * fullExtent.width) * dataSizePerPixel, dataSizePerRow),
						pDst += dataSizePerRow;
			StagingBuffer::Buffer_MainThread().UnmapMemory();
		}
		Create_Internal(format_initial, format_final, generateMipmap);
	}
	void Create(ArrayRef<const char* const> filepaths, Format format_initial, Format format_final, bool generateMipmap = true) {
		if (filepaths.size() > VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers) {
			OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nLayer count is out of limit! Must be less than: {}\n", VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers);
			return;
		}
		std::unique_ptr psImageData = std::make_unique<std::unique_ptr<uint8_t[]>[]>(filepaths.size());
		for (size_t i = 0; i < filepaths.size(); i++) {
			Extent2D extent_currentLayer;
			psImageData[i] = LoadFile(filepaths[i], extent_currentLayer, FormatInfo(format_initial));
			if (psImageData[i]) {
				if (i == 0)
					extent = extent_currentLayer;
				if (extent.width == extent_currentLayer.width &&
					extent.height == extent_currentLayer.height)
					continue;
				else
					OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nImage not available!\nFile: {}\nAll the images must be of same extent!\n", filepaths[i]);
			}
			return;
		}
		Create({ reinterpret_cast<const uint8_t* const*>(psImageData.get()), filepaths.size() }, extent, format_initial, format_final, generateMipmap);
	}
	void Create(ArrayRef<const uint8_t* const> psImageData, Extent2D extent, Format format_initial, Format format_final, bool generateMipmap = true) {
		layerCount = psImageData.size();
		if (layerCount > VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers) {
			OutputMessage("[ vke::ext::Texture2DArray ] ERROR\nLayer count is out of limit! Must be less than: {}\n", VkeApp::Base().PhysicalDevice().Properties().limits.maxImageArrayLayers);
			return;
		}
		this->extent = extent;
		size_t dataSizePerImage = size_t(FormatInfo(format_initial).sizePerPixel) * extent.width * extent.height;
		size_t imageDataSize = dataSizePerImage * layerCount;
		uint8_t* pDst = static_cast<uint8_t*>(StagingBuffer::Buffer_MainThread().MapMemory(imageDataSize));
		for (size_t i = 0; i < layerCount; i++)
			std::memcpy(pDst, psImageData[i], dataSizePerImage),
			pDst += dataSizePerImage;
		StagingBuffer::Buffer_MainThread().UnmapMemory();
		Create_Internal(format_initial, format_final, generateMipmap);
	}
};

class TextureCube : public Texture {
protected:
	Extent2D extent = {};
	/* Non-const Function */
	Extent2D ExtentInTiles(const Offset2D*& facePositions, bool lookFromOutside, bool loadPreviousResult = false) {
		static constexpr Offset2D facePositions_default[][6] = {
			{ { 2, 1 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 1, 1 }, { 3, 1 } },
			{ { 2, 1 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 3, 1 }, { 1, 1 } }
		};
		static Extent2D extentInTiles;
		if (loadPreviousResult)
			return extentInTiles;
		extentInTiles = { 1, 1 };
		if (!facePositions)
			facePositions = facePositions_default[lookFromOutside],
			extentInTiles = { 4, 3 };
		else
			for (size_t i = 0; i < 6; i++) {
				if (extentInTiles.width <= facePositions[i].x + 1u)
					extentInTiles.width = facePositions[i].x + 1;
				if (extentInTiles.height <= facePositions[i].y + 1u)
					extentInTiles.height = facePositions[i].y + 1;
			}
		return extentInTiles;
	}
	void Create_Internal(Format format_initial, Format format_final, bool generateMipmap) {
		uint32_t mipLevelCount = generateMipmap ? CalculateMipLevelCount(extent) : 1;
		CreateImageMemory(VK_IMAGE_TYPE_2D, format_final, { extent.width, extent.height, 1 }, mipLevelCount, 6, VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT);
		CreateImageView(VK_IMAGE_VIEW_TYPE_CUBE, format_final, mipLevelCount, 6);
		if (format_initial == format_final)
			CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory, imageMemory, extent, mipLevelCount, 6);
		else {
			oop::ImageMemory imageMemory_conversion(ImageCreateInfo{}.
				Flags(VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT).
				ImageType(VK_IMAGE_TYPE_2D).
				Format(format_initial).
				Extent({ extent.width, extent.height, 1 }).
				ArrayLayers(6).
				Usage(VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT),
				VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
			CopyBlitAndGenerateMipmap2D(StagingBuffer::Buffer_MainThread(), imageMemory_conversion, imageMemory, extent, mipLevelCount, 6);
		}
	}
public:
	TextureCube() = default;
	/*
	  Order of facePositions[6], in left handed coordinate, looking from inside:
	  right(+x) left(-x) top(+y) bottom(-y) front(+z) back(-z)
	  Not related to NDC.
	  If lookFromOutside is true, the order is the same.
	  --------------------
	  Default face positions, looking from inside, is:
	  [      ][ top  ][      ][      ]
	  [ left ][front ][right ][ back ]
	  [      ][bottom][      ][      ]
	  If lookFromOutside is true, front and back is swapped.
	  What ever the facePositions are, make sure the image matches the looking which a cube is unwrapped as above.
	*/
	TextureCube(const char* filepath, const Offset2D facePositions[6], Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Create(filepath, facePositions, format_initial, format_final, lookFromOutside, generateMipmap);
	}
	TextureCube(const uint8_t* pImageData, Extent2D fullExtent, const Offset2D facePositions[6], Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Create(pImageData, fullExtent, facePositions, format_initial, format_final, lookFromOutside, generateMipmap);
	}
	TextureCube(const char* const* filepaths, Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Create(filepaths, format_initial, format_final, lookFromOutside, generateMipmap);
	}
	TextureCube(const uint8_t* const* psImageData, Extent2D extent, Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Create(psImageData, extent, format_initial, format_final, lookFromOutside, generateMipmap);
	}
	/* Getter */
	const Extent2D& Extent() const { return extent; }
	const uint32_t& Width() const { return extent.width; }
	const uint32_t& Height() const { return extent.height; }
	/* Non-const Function */
	void Create(const char* filepath, const Offset2D facePositions[6], Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Extent2D fullExtent;
		std::unique_ptr pImageData = LoadFile(filepath, fullExtent, FormatInfo(format_initial));
		if (pImageData)
			if (Extent2D extentInTiles = ExtentInTiles(facePositions, lookFromOutside);
				fullExtent.width % extentInTiles.width ||
				fullExtent.height % extentInTiles.height)
				OutputMessage("[ vke::ext::TextureCube ] ERROR\nImage not available!\nFile: {}\nImage width should be in multiples of: {}\nImage height should be in multiples of: {}\n", filepath, extentInTiles.width, extentInTiles.height);
			else {
				extent.width = fullExtent.width / extentInTiles.width;
				extent.height = fullExtent.height / extentInTiles.height;
				Create(pImageData.get(), { fullExtent.width, UINT32_MAX }, facePositions, format_initial, format_final, lookFromOutside, generateMipmap);
			}
	}
	void Create(const uint8_t* pImageData, Extent2D fullExtent, const Offset2D facePositions[6], Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		Extent2D extentInTiles;
		if (fullExtent.height == UINT32_MAX) // See previous Create(...), value of fullExtent.height doesn't matter after this if statement
			extentInTiles = ExtentInTiles(facePositions, lookFromOutside, true);
		else {
			extentInTiles = ExtentInTiles(facePositions, lookFromOutside);
			if (fullExtent.width % extentInTiles.width ||
				fullExtent.height % extentInTiles.height) {
				OutputMessage("[ vke::ext::TextureCube ] ERROR\nImage not available!\nImage width should be in multiples of: {}\nImage height should be in multiples of: {}\n", extentInTiles.width, extentInTiles.height);
				return;
			}
			extent.width = fullExtent.width / extentInTiles.width;
			extent.height = fullExtent.height / extentInTiles.height;
		}
		size_t dataSizePerPixel = FormatInfo(format_initial).sizePerPixel;
		size_t dataSizePerRow = dataSizePerPixel * extent.width;
		size_t imageDataSize = dataSizePerRow * extent.height * 6;
		uint8_t* pDst = static_cast<uint8_t*>(StagingBuffer::Buffer_MainThread().MapMemory(imageDataSize));
		if (lookFromOutside)
			for (size_t face = 0; face < 6; face++)
				if (face != 2 && face != 3)
					for (uint32_t i = 0; i < extent.height; i++)
						for (uint32_t j = 0; j < extent.width; j++)
							std::memcpy(pDst, pImageData + dataSizePerPixel * (extent.width - 1 - j + facePositions[face].x * extent.width + (i + facePositions[face].y * extent.height) * fullExtent.width), dataSizePerPixel),
							pDst += dataSizePerPixel;
				else
					for (uint32_t j = 0; j < extent.height; j++)
						for (uint32_t k = 0; k < extent.width; k++)
							std::memcpy(pDst, pImageData + dataSizePerPixel * (k + facePositions[face].x * extent.width + ((extent.height - 1 - j) + facePositions[face].y * extent.height) * fullExtent.width), dataSizePerPixel),
							pDst += dataSizePerPixel;
		else
			if (extentInTiles.width == 1 && extentInTiles.height == 6 &&
				facePositions[0].y == 0 && facePositions[1].y == 1 &&
				facePositions[2].y == 2 && facePositions[3].y == 3 &&
				facePositions[4].y == 4 && facePositions[5].y == 5)
				std::memcpy(pDst, pImageData, imageDataSize);
			else
				for (size_t face = 0; face < 6; face++)
					for (uint32_t j = 0; j < extent.height; j++)
						std::memcpy(pDst, pImageData + dataSizePerPixel * (facePositions[face].x * extent.width + (j + facePositions[face].y * extent.height) * fullExtent.width), dataSizePerRow),
						pDst += dataSizePerRow;
		StagingBuffer::Buffer_MainThread().UnmapMemory();
		Create_Internal(format_initial, format_final, generateMipmap);
	}
	void Create(const char* const filepaths[6], Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		std::unique_ptr<uint8_t[]> psImageData[6] = {};
		for (size_t i = 0; i < 6; i++) {
			Extent2D extent_currentLayer;
			psImageData[i] = LoadFile(filepaths[i], extent_currentLayer, FormatInfo(format_initial));
			if (psImageData[i]) {
				if (i == 0)
					extent = extent_currentLayer;
				if (extent.width == extent_currentLayer.width ||
					extent.height == extent_currentLayer.height)
					continue;
				else
					OutputMessage("[ vke::ext::TextureCube ] ERROR\nImage not available!\nFile: {}\nAll the images must be of same extent!\n", filepaths[i]);
			}
			return;
		}
		Create(reinterpret_cast<const uint8_t* const*>(psImageData), extent, format_initial, format_final, lookFromOutside, generateMipmap);
	}
	void Create(const uint8_t* const psImageData[6], Extent2D extent, Format format_initial, Format format_final, bool lookFromOutside = false, bool generateMipmap = true) {
		this->extent = extent;
		size_t dataSizePerPixel = FormatInfo(format_initial).sizePerPixel;
		size_t dataSizePerImage = dataSizePerPixel * extent.width * extent.height;
		size_t imageDataSize = dataSizePerImage * 6;
		uint8_t* pDst = static_cast<uint8_t*>(StagingBuffer::Buffer_MainThread().MapMemory(imageDataSize));
		if (lookFromOutside)
			for (size_t face = 0; face < 6; face++)
				if (face != 2 && face != 3)
					for (uint32_t j = 0; j < extent.height; j++)
						for (uint32_t i = 0; i < extent.width; i++)
							std::memcpy(pDst, psImageData[face] + dataSizePerPixel * ((j + 1) * extent.width - 1 - i), dataSizePerPixel),
							pDst += dataSizePerPixel;
				else
					for (uint32_t j = 0; j < extent.height; j++)
						for (uint32_t i = 0; i < extent.width; i++)
							std::memcpy(pDst, psImageData[face] + dataSizePerPixel * ((extent.height - 1 - j) * extent.width + i), dataSizePerPixel),
							pDst += dataSizePerPixel;
		else
			for (size_t i = 0; i < 6; i++)
				std::memcpy(pDst + dataSizePerImage * i, psImageData[i], dataSizePerImage);
		StagingBuffer::Buffer_MainThread().UnmapMemory();
		Create_Internal(format_initial, format_final, generateMipmap);
	}
};
#pragma endregion

#pragma region Query
class OcclusionQueries {
protected:
	oop::QueryPool queryPool;
	std::vector<uint32_t> passingSampleCounts;
public:
	OcclusionQueries() = default;
	OcclusionQueries(uint32_t capacity) {
		Create(capacity);
	}
	/* Getter */
	operator const QueryPool&() const { return queryPool; }
	const QueryPool* operator&() const { return &queryPool; }
	uint32_t Capacity() const { return passingSampleCounts.size(); }
	uint32_t PassingSampleCount(uint32_t index) const { return passingSampleCounts[index]; }
	/* Const Function */
	void CmdBegin(uint32_t queryIndex, bool isPrecise = false) const {
		queryPool.CmdBegin(queryIndex, isPrecise);
	}
	void CmdEnd(uint32_t queryIndex) const {
		queryPool.CmdEnd(queryIndex);
	}
	void CmdReset() const {
		queryPool.CmdReset(0, Capacity());
	}
	// ======== For GPU-driven occlusion culling
	void CmdCopyResults(uint32_t firstQueryIndex, uint32_t queryCount, Buffer dstBuffer, DeviceSize dstOffset, DeviceSize stride) const {
		queryPool.CmdCopyResults(firstQueryIndex, queryCount, dstBuffer, dstOffset, stride, VK_QUERY_RESULT_WAIT_BIT);
	}
	// Provided by VK_API_VERSION_1_2 or VK_EXT_host_query_reset
	void Reset(uint32_t firstQueryIndex, uint32_t queryCount) const {
		queryPool.Reset(firstQueryIndex, queryCount);
	}
	/* Non-const Function */
	void Create(uint32_t capacity) {
		passingSampleCounts.resize(capacity);
		passingSampleCounts.shrink_to_fit();
		queryPool.Create(VK_QUERY_TYPE_OCCLUSION, Capacity());
	}
	void Recreate(uint32_t capacity) {
		queryPool.~Object();
		Create(capacity);
	}
	RESULT GetResults() {
		return GetResults(Capacity());
	}
	RESULT GetResults(uint32_t queryCount) {
		return queryPool.GetResults(0, queryCount, passingSampleCounts, 4);
	}
};

class PipelineStatisticQuery {
protected:
	enum {
		// Input Assembly
		vertexCount_ia,
		primitiveCount_ia,
		// Vertex Shader
		invocationCount_vs,
		// Geometry Shader
		invocationCount_gs,
		primitiveCount_gs,
		// Clipping
		invocationCount_clipping,
		primitiveCount_clipping,
		// Fragment Shader
		invocationCount_fs,
		// Tessellation
		patchCount_tcs,
		invocationCount_tes,
		// Compute Shader
		invocationCount_cs,
		statisticCount
	};
	oop::QueryPool queryPool;
	uint32_t statistics[statisticCount] = {};
public:
	PipelineStatisticQuery() = default;
	PipelineStatisticQuery(EmptyList) {
		Create();
	}
	/* Getter */
	operator const QueryPool&() const { return queryPool; }
	const QueryPool* operator&() const { return &queryPool; }
	uint32_t     VertexCount_Ia() const { return statistics[vertexCount_ia]; }
	uint32_t  PrimitiveCount_Ia() const { return statistics[primitiveCount_ia]; }
	uint32_t InvocationCount_Vs() const { return statistics[invocationCount_vs]; }
	uint32_t InvocationCount_Gs() const { return statistics[invocationCount_gs]; }
	uint32_t  PrimitiveCount_Gs() const { return statistics[primitiveCount_gs]; }
	uint32_t InvocationCount_Clipping() const { return statistics[invocationCount_clipping]; }
	uint32_t  PrimitiveCount_Clipping() const { return statistics[primitiveCount_clipping]; }
	uint32_t InvocationCount_Fs() const { return statistics[invocationCount_fs]; }
	uint32_t      PatchCount_Tcs() const { return statistics[patchCount_tcs]; }
	uint32_t InvocationCount_Tes() const { return statistics[invocationCount_tes]; }
	uint32_t InvocationCount_Cs() const { return statistics[invocationCount_cs]; }
	/* Const Function */
	void CmdBegin() const {
		queryPool.CmdBegin(0);
	}
	void CmdEnd() const {
		queryPool.CmdEnd(0);
	}
	void CmdReset() const {
		queryPool.CmdReset(0, 1);
	}
	void CmdResetAndBegin() const {
		CmdReset();
		CmdBegin();
	}
	// Provided by VK_API_VERSION_1_2 or VK_EXT_host_query_reset
	void Reset() const {
		queryPool.Reset(0, 1);
	}
	/* Non-const Function */
	void Create() {
		queryPool.Create(VK_QUERY_TYPE_PIPELINE_STATISTICS, 1, (1 << statisticCount) - 1);
	}
	RESULT GetResults() {
		return queryPool.GetResults(0, 1, statistics);
	}
};

class TimestampQueries {
protected:
	oop::QueryPool queryPool;
	std::vector<uint32_t> timestamps;
public:
	TimestampQueries() = default;
	TimestampQueries(uint32_t capacity) {
		Create(capacity);
	}
	/* Getter */
	operator const QueryPool&() const { return queryPool; }
	const QueryPool* operator&() const { return &queryPool; }
	uint32_t Capacity() const { return timestamps.size(); }
	uint32_t Timestamp(uint32_t index) const { return timestamps[index]; }
	uint32_t Duration(uint32_t index) const { return timestamps[index + 1] - timestamps[index]; }
	/* Const Function */
	void CmdReset() const {
		queryPool.CmdReset(0, Capacity());
	}
	void CmdWriteTimestamp(PipelineStageFlagBits pipelineStage, uint32_t queryIndex) const {
		queryPool.CmdWriteTimestamp(pipelineStage, queryIndex);
	}
	// Provided by VK_API_VERSION_1_2 or VK_EXT_host_query_reset
	void Reset(uint32_t firstQueryIndex, uint32_t queryCount) const {
		queryPool.Reset(firstQueryIndex, queryCount);
	}
	/* Non-const Function */
	void Create(uint32_t capacity) {
		timestamps.resize(capacity);
		timestamps.shrink_to_fit();
		queryPool.Create(VK_QUERY_TYPE_TIMESTAMP, Capacity());
	}
	void Recreate(uint32_t capacity) {
		queryPool.~Object();
		Create(capacity);
	}
	RESULT GetResults() {
		return GetResults(Capacity());
	}
	RESULT GetResults(uint32_t queryCount) {
		return queryPool.GetResults(0, queryCount, timestamps, 4);
	}
};
#pragma endregion

VK_ENCAPSULATION_NAMESPACE_END