#define VK_ENCAPSULATION_ENUMS_NAMESPACE_BEGIN namespace VK_ENCAPSULATION_NAMESPACE::enums {

VK_ENCAPSULATION_ENUMS_NAMESPACE_BEGIN

//enum Result {
constexpr auto Success                                     = VK_SUCCESS;
constexpr auto NotReady                                    = VK_NOT_READY;
constexpr auto Timeout                                     = VK_TIMEOUT;
constexpr auto EventSet                                    = VK_EVENT_SET;
constexpr auto EventReset                                  = VK_EVENT_RESET;
constexpr auto Incomplete                                  = VK_INCOMPLETE;
constexpr auto ErrorOutOfHostMemory                        = VK_ERROR_OUT_OF_HOST_MEMORY;
constexpr auto ErrorOutOfDeviceMemory                      = VK_ERROR_OUT_OF_DEVICE_MEMORY;
constexpr auto ErrorInitializationFailed                   = VK_ERROR_INITIALIZATION_FAILED;
constexpr auto ErrorDeviceLost                             = VK_ERROR_DEVICE_LOST;
constexpr auto ErrorMemoryMapFailed                        = VK_ERROR_MEMORY_MAP_FAILED;
constexpr auto ErrorLayerNotPresent                        = VK_ERROR_LAYER_NOT_PRESENT;
constexpr auto ErrorExtensionNotPresent                    = VK_ERROR_EXTENSION_NOT_PRESENT;
constexpr auto ErrorFeatureNotPresent                      = VK_ERROR_FEATURE_NOT_PRESENT;
constexpr auto ErrorIncompatibleDriver                     = VK_ERROR_INCOMPATIBLE_DRIVER;
constexpr auto ErrorTooManyObjects                         = VK_ERROR_TOO_MANY_OBJECTS;
constexpr auto ErrorFormatNotSupported                     = VK_ERROR_FORMAT_NOT_SUPPORTED;
constexpr auto ErrorFragmentedPool                         = VK_ERROR_FRAGMENTED_POOL;
constexpr auto ErrorUnknown                                = VK_ERROR_UNKNOWN;
constexpr auto ErrorValidationFailed                       = VK_ERROR_VALIDATION_FAILED;
constexpr auto ErrorValidationFailedEXT                    = VK_ERROR_VALIDATION_FAILED_EXT;
constexpr auto ErrorOutOfPoolMemory                        = VK_ERROR_OUT_OF_POOL_MEMORY;
constexpr auto ErrorOutOfPoolMemoryKHR                     = VK_ERROR_OUT_OF_POOL_MEMORY_KHR;
constexpr auto ErrorInvalidExternalHandle                  = VK_ERROR_INVALID_EXTERNAL_HANDLE;
constexpr auto ErrorInvalidExternalHandleKHR               = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR;
constexpr auto ErrorFragmentation                          = VK_ERROR_FRAGMENTATION;
constexpr auto ErrorFragmentationEXT                       = VK_ERROR_FRAGMENTATION_EXT;
constexpr auto ErrorInvalidOpaqueCaptureAddress            = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS;
constexpr auto ErrorInvalidDeviceAddressEXT                = VK_ERROR_INVALID_DEVICE_ADDRESS_EXT;
constexpr auto ErrorInvalidOpaqueCaptureAddressKHR         = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR;
constexpr auto PipelineCompileRequired                     = VK_PIPELINE_COMPILE_REQUIRED;
constexpr auto PipelineCompileRequiredEXT                  = VK_PIPELINE_COMPILE_REQUIRED_EXT;
constexpr auto ErrorPipelineCompileRequiredEXT             = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT;
constexpr auto ErrorNotPermitted                           = VK_ERROR_NOT_PERMITTED;
constexpr auto ErrorNotPermittedEXT                        = VK_ERROR_NOT_PERMITTED_EXT;
constexpr auto ErrorNotPermittedKHR                        = VK_ERROR_NOT_PERMITTED_KHR;
constexpr auto ErrorSurfaceLostKHR                         = VK_ERROR_SURFACE_LOST_KHR;
constexpr auto ErrorNativeWindowInUseKHR                   = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR;
constexpr auto SuboptimalKHR                               = VK_SUBOPTIMAL_KHR;
constexpr auto ErrorOutOfDateKHR                           = VK_ERROR_OUT_OF_DATE_KHR;
constexpr auto ErrorIncompatibleDisplayKHR                 = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR;
constexpr auto ErrorInvalidShaderNV                        = VK_ERROR_INVALID_SHADER_NV;
constexpr auto ErrorImageUsageNotSupportedKHR              = VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR;
constexpr auto ErrorVideoPictureLayoutNotSupportedKHR      = VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR;
constexpr auto ErrorVideoProfileOperationNotSupportedKHR   = VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR;
constexpr auto ErrorVideoProfileFormatNotSupportedKHR      = VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR;
constexpr auto ErrorVideoProfileCodecNotSupportedKHR       = VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
constexpr auto ErrorVideoStdVersionNotSupportedKHR         = VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR;
constexpr auto ErrorInvalidDrmFormatModifierPlaneLayoutEXT = VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto ErrorFullScreenExclusiveModeLostEXT         = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto ThreadIdleKHR                               = VK_THREAD_IDLE_KHR;
constexpr auto ThreadDoneKHR                               = VK_THREAD_DONE_KHR;
constexpr auto OperationDeferredKHR                        = VK_OPERATION_DEFERRED_KHR;
constexpr auto OperationNotDeferredKHR                     = VK_OPERATION_NOT_DEFERRED_KHR;
constexpr auto ErrorInvalidVideoStdParametersKHR           = VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR;
constexpr auto ErrorCompressionExhaustedEXT                = VK_ERROR_COMPRESSION_EXHAUSTED_EXT;
constexpr auto IncompatibleShaderBinaryEXT                 = VK_INCOMPATIBLE_SHADER_BINARY_EXT;
constexpr auto ErrorIncompatibleShaderBinaryEXT            = VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT;
constexpr auto PipelineBinaryMissingKHR                    = VK_PIPELINE_BINARY_MISSING_KHR;
constexpr auto ErrorNotEnoughSpaceKHR                      = VK_ERROR_NOT_ENOUGH_SPACE_KHR;
//};

//enum StructureType {
constexpr auto StructureTypeApplicationInfo                                              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
constexpr auto StructureTypeInstanceCreateInfo                                           = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
constexpr auto StructureTypeDeviceQueueCreateInfo                                        = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
constexpr auto StructureTypeDeviceCreateInfo                                             = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
constexpr auto StructureTypeSubmitInfo                                                   = VK_STRUCTURE_TYPE_SUBMIT_INFO;
constexpr auto StructureTypeMemoryAllocateInfo                                           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
constexpr auto StructureTypeMappedMemoryRange                                            = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
constexpr auto StructureTypeBindSparseInfo                                               = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
constexpr auto StructureTypeFenceCreateInfo                                              = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
constexpr auto StructureTypeSemaphoreCreateInfo                                          = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
constexpr auto StructureTypeEventCreateInfo                                              = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
constexpr auto StructureTypeQueryPoolCreateInfo                                          = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
constexpr auto StructureTypeBufferCreateInfo                                             = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
constexpr auto StructureTypeBufferViewCreateInfo                                         = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
constexpr auto StructureTypeImageCreateInfo                                              = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
constexpr auto StructureTypeImageViewCreateInfo                                          = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
constexpr auto StructureTypeShaderModuleCreateInfo                                       = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
constexpr auto StructureTypePipelineCacheCreateInfo                                      = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
constexpr auto StructureTypePipelineShaderStageCreateInfo                                = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
constexpr auto StructureTypePipelineVertexInputStateCreateInfo                           = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineInputAssemblyStateCreateInfo                         = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineTessellationStateCreateInfo                          = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineViewportStateCreateInfo                              = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineRasterizationStateCreateInfo                         = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineMultisampleStateCreateInfo                           = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineDepthStencilStateCreateInfo                          = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineColorBlendStateCreateInfo                            = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineDynamicStateCreateInfo                               = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
constexpr auto StructureTypeGraphicsPipelineCreateInfo                                   = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
constexpr auto StructureTypeComputePipelineCreateInfo                                    = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
constexpr auto StructureTypePipelineLayoutCreateInfo                                     = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
constexpr auto StructureTypeSamplerCreateInfo                                            = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
constexpr auto StructureTypeDescriptorSetLayoutCreateInfo                                = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
constexpr auto StructureTypeDescriptorPoolCreateInfo                                     = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
constexpr auto StructureTypeDescriptorSetAllocateInfo                                    = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
constexpr auto StructureTypeWriteDescriptorSet                                           = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
constexpr auto StructureTypeCopyDescriptorSet                                            = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
constexpr auto StructureTypeFramebufferCreateInfo                                        = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
constexpr auto StructureTypeRenderPassCreateInfo                                         = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
constexpr auto StructureTypeCommandPoolCreateInfo                                        = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
constexpr auto StructureTypeCommandBufferAllocateInfo                                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
constexpr auto StructureTypeCommandBufferInheritanceInfo                                 = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
constexpr auto StructureTypeCommandBufferBeginInfo                                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
constexpr auto StructureTypeRenderPassBeginInfo                                          = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
constexpr auto StructureTypeBufferMemoryBarrier                                          = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
constexpr auto StructureTypeImageMemoryBarrier                                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
constexpr auto StructureTypeMemoryBarrier                                                = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
constexpr auto StructureTypeLoaderInstanceCreateInfo                                     = VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO;
constexpr auto StructureTypeLoaderDeviceCreateInfo                                       = VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO;
constexpr auto StructureTypePhysicalDeviceSubgroupProperties                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
constexpr auto StructureTypeBindBufferMemoryInfo                                         = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
constexpr auto StructureTypeBindBufferMemoryInfoKHR                                      = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR;
constexpr auto StructureTypeBindImageMemoryInfo                                          = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
constexpr auto StructureTypeBindImageMemoryInfoKHR                                       = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR;
constexpr auto StructureTypePhysicalDevice16BitStorageFeatures                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
constexpr auto StructureTypePhysicalDevice16BitStorageFeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR;
constexpr auto StructureTypeMemoryDedicatedRequirements                                  = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS;
constexpr auto StructureTypeMemoryDedicatedRequirementsKHR                               = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR;
constexpr auto StructureTypeMemoryDedicatedAllocateInfo                                  = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
constexpr auto StructureTypeMemoryDedicatedAllocateInfoKHR                               = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR;
constexpr auto StructureTypeMemoryAllocateFlagsInfo                                      = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
constexpr auto StructureTypeMemoryAllocateFlagsInfoKHR                                   = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR;
constexpr auto StructureTypeDeviceGroupRenderPassBeginInfo                               = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO;
constexpr auto StructureTypeDeviceGroupRenderPassBeginInfoKHR                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR;
constexpr auto StructureTypeDeviceGroupCommandBufferBeginInfo                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO;
constexpr auto StructureTypeDeviceGroupCommandBufferBeginInfoKHR                         = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR;
constexpr auto StructureTypeDeviceGroupSubmitInfo                                        = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO;
constexpr auto StructureTypeDeviceGroupSubmitInfoKHR                                     = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR;
constexpr auto StructureTypeDeviceGroupBindSparseInfo                                    = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO;
constexpr auto StructureTypeDeviceGroupBindSparseInfoKHR                                 = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR;
constexpr auto StructureTypeBindBufferMemoryDeviceGroupInfo                              = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO;
constexpr auto StructureTypeBindBufferMemoryDeviceGroupInfoKHR                           = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR;
constexpr auto StructureTypeBindImageMemoryDeviceGroupInfo                               = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO;
constexpr auto StructureTypeBindImageMemoryDeviceGroupInfoKHR                            = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceGroupProperties                                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceGroupPropertiesKHR                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR;
constexpr auto StructureTypeDeviceGroupDeviceCreateInfo                                  = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO;
constexpr auto StructureTypeDeviceGroupDeviceCreateInfoKHR                               = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR;
constexpr auto StructureTypeBufferMemoryRequirementsInfo2                                = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2;
constexpr auto StructureTypeBufferMemoryRequirementsInfo2KHR                             = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR;
constexpr auto StructureTypeImageMemoryRequirementsInfo2                                 = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2;
constexpr auto StructureTypeImageMemoryRequirementsInfo2KHR                              = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR;
constexpr auto StructureTypeImageSparseMemoryRequirementsInfo2                           = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2;
constexpr auto StructureTypeImageSparseMemoryRequirementsInfo2KHR                        = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR;
constexpr auto StructureTypeMemoryRequirements2                                          = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;
constexpr auto StructureTypeMemoryRequirements2KHR                                       = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR;
constexpr auto StructureTypeSparseImageMemoryRequirements2                               = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2;
constexpr auto StructureTypeSparseImageMemoryRequirements2KHR                            = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR;
constexpr auto StructureTypePhysicalDeviceFeatures2                                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
constexpr auto StructureTypePhysicalDeviceFeatures2KHR                                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
constexpr auto StructureTypePhysicalDeviceProperties2                                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
constexpr auto StructureTypePhysicalDeviceProperties2KHR                                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
constexpr auto StructureTypeFormatProperties2                                            = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
constexpr auto StructureTypeFormatProperties2KHR                                         = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR;
constexpr auto StructureTypeImageFormatProperties2                                       = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2;
constexpr auto StructureTypeImageFormatProperties2KHR                                    = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR;
constexpr auto StructureTypePhysicalDeviceImageFormatInfo2                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2;
constexpr auto StructureTypePhysicalDeviceImageFormatInfo2KHR                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR;
constexpr auto StructureTypeQueueFamilyProperties2                                       = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
constexpr auto StructureTypeQueueFamilyProperties2KHR                                    = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR;
constexpr auto StructureTypePhysicalDeviceMemoryProperties2                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
constexpr auto StructureTypePhysicalDeviceMemoryProperties2KHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR;
constexpr auto StructureTypeSparseImageFormatProperties2                                 = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2;
constexpr auto StructureTypeSparseImageFormatProperties2KHR                              = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR;
constexpr auto StructureTypePhysicalDeviceSparseImageFormatInfo2                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2;
constexpr auto StructureTypePhysicalDeviceSparseImageFormatInfo2KHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR;
constexpr auto StructureTypePhysicalDevicePointClippingProperties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
constexpr auto StructureTypePhysicalDevicePointClippingPropertiesKHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR;
constexpr auto StructureTypeRenderPassInputAttachmentAspectCreateInfo                    = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO;
constexpr auto StructureTypeRenderPassInputAttachmentAspectCreateInfoKHR                 = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR;
constexpr auto StructureTypeImageViewUsageCreateInfo                                     = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO;
constexpr auto StructureTypeImageViewUsageCreateInfoKHR                                  = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR;
constexpr auto StructureTypePipelineTessellationDomainOriginStateCreateInfo              = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineTessellationDomainOriginStateCreateInfoKHR           = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR;
constexpr auto StructureTypeRenderPassMultiviewCreateInfo                                = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO;
constexpr auto StructureTypeRenderPassMultiviewCreateInfoKHR                             = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceMultiviewFeatures                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
constexpr auto StructureTypePhysicalDeviceMultiviewFeaturesKHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMultiviewProperties                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceMultiviewPropertiesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceVariablePointersFeatures                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
constexpr auto StructureTypePhysicalDeviceVariablePointerFeatures                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES;
constexpr auto StructureTypePhysicalDeviceVariablePointersFeaturesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceVariablePointerFeaturesKHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR;
constexpr auto StructureTypeProtectedSubmitInfo                                          = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO;
constexpr auto StructureTypePhysicalDeviceProtectedMemoryFeatures                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
constexpr auto StructureTypePhysicalDeviceProtectedMemoryProperties                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
constexpr auto StructureTypeDeviceQueueInfo2                                             = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2;
constexpr auto StructureTypeSamplerYcbcrConversionCreateInfo                             = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
constexpr auto StructureTypeSamplerYcbcrConversionCreateInfoKHR                          = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR;
constexpr auto StructureTypeSamplerYcbcrConversionInfo                                   = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
constexpr auto StructureTypeSamplerYcbcrConversionInfoKHR                                = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR;
constexpr auto StructureTypeBindImagePlaneMemoryInfo                                     = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO;
constexpr auto StructureTypeBindImagePlaneMemoryInfoKHR                                  = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR;
constexpr auto StructureTypeImagePlaneMemoryRequirementsInfo                             = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO;
constexpr auto StructureTypeImagePlaneMemoryRequirementsInfoKHR                          = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceSamplerYcbcrConversionFeatures                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
constexpr auto StructureTypePhysicalDeviceSamplerYcbcrConversionFeaturesKHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR;
constexpr auto StructureTypeSamplerYcbcrConversionImageFormatProperties                  = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES;
constexpr auto StructureTypeSamplerYcbcrConversionImageFormatPropertiesKHR               = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR;
constexpr auto StructureTypeDescriptorUpdateTemplateCreateInfo                           = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO;
constexpr auto StructureTypeDescriptorUpdateTemplateCreateInfoKHR                        = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceExternalImageFormatInfo                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO;
constexpr auto StructureTypePhysicalDeviceExternalImageFormatInfoKHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR;
constexpr auto StructureTypeExternalImageFormatProperties                                = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES;
constexpr auto StructureTypeExternalImageFormatPropertiesKHR                             = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceExternalBufferInfo                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO;
constexpr auto StructureTypePhysicalDeviceExternalBufferInfoKHR                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR;
constexpr auto StructureTypeExternalBufferProperties                                     = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES;
constexpr auto StructureTypeExternalBufferPropertiesKHR                                  = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceIdProperties                                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceIdPropertiesKHR                                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR;
constexpr auto StructureTypeExternalMemoryBufferCreateInfo                               = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
constexpr auto StructureTypeExternalMemoryBufferCreateInfoKHR                            = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR;
constexpr auto StructureTypeExternalMemoryImageCreateInfo                                = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
constexpr auto StructureTypeExternalMemoryImageCreateInfoKHR                             = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR;
constexpr auto StructureTypeExportMemoryAllocateInfo                                     = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
constexpr auto StructureTypeExportMemoryAllocateInfoKHR                                  = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceExternalFenceInfo                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO;
constexpr auto StructureTypePhysicalDeviceExternalFenceInfoKHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR;
constexpr auto StructureTypeExternalFenceProperties                                      = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES;
constexpr auto StructureTypeExternalFencePropertiesKHR                                   = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR;
constexpr auto StructureTypeExportFenceCreateInfo                                        = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO;
constexpr auto StructureTypeExportFenceCreateInfoKHR                                     = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR;
constexpr auto StructureTypeExportSemaphoreCreateInfo                                    = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO;
constexpr auto StructureTypeExportSemaphoreCreateInfoKHR                                 = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceExternalSemaphoreInfo                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO;
constexpr auto StructureTypePhysicalDeviceExternalSemaphoreInfoKHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR;
constexpr auto StructureTypeExternalSemaphoreProperties                                  = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES;
constexpr auto StructureTypeExternalSemaphorePropertiesKHR                               = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance3Properties                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceMaintenance3PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR;
constexpr auto StructureTypeDescriptorSetLayoutSupport                                   = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT;
constexpr auto StructureTypeDescriptorSetLayoutSupportKHR                                = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR;
constexpr auto StructureTypePhysicalDeviceShaderDrawParametersFeatures                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderDrawParameterFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkan11Features                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkan11Properties                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceVulkan12Features                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkan12Properties                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
constexpr auto StructureTypeImageFormatListCreateInfo                                    = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO;
constexpr auto StructureTypeImageFormatListCreateInfoKHR                                 = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR;
constexpr auto StructureTypeAttachmentDescription2                                       = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2;
constexpr auto StructureTypeAttachmentDescription2KHR                                    = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR;
constexpr auto StructureTypeAttachmentReference2                                         = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2;
constexpr auto StructureTypeAttachmentReference2KHR                                      = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR;
constexpr auto StructureTypeSubpassDescription2                                          = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2;
constexpr auto StructureTypeSubpassDescription2KHR                                       = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR;
constexpr auto StructureTypeSubpassDependency2                                           = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2;
constexpr auto StructureTypeSubpassDependency2KHR                                        = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR;
constexpr auto StructureTypeRenderPassCreateInfo2                                        = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
constexpr auto StructureTypeRenderPassCreateInfo2KHR                                     = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR;
constexpr auto StructureTypeSubpassBeginInfo                                             = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO;
constexpr auto StructureTypeSubpassBeginInfoKHR                                          = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR;
constexpr auto StructureTypeSubpassEndInfo                                               = VK_STRUCTURE_TYPE_SUBPASS_END_INFO;
constexpr auto StructureTypeSubpassEndInfoKHR                                            = VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR;
constexpr auto StructureTypePhysicalDevice8BitStorageFeatures                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
constexpr auto StructureTypePhysicalDevice8BitStorageFeaturesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceDriverProperties                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceDriverPropertiesKHR                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderAtomicInt64Features                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderAtomicInt64FeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderFloat16Int8Features                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderFloat16Int8FeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceFloat16Int8FeaturesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceFloatControlsProperties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceFloatControlsPropertiesKHR                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR;
constexpr auto StructureTypeDescriptorSetLayoutBindingFlagsCreateInfo                    = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO;
constexpr auto StructureTypeDescriptorSetLayoutBindingFlagsCreateInfoEXT                 = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorIndexingFeatures                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
constexpr auto StructureTypePhysicalDeviceDescriptorIndexingFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorIndexingProperties                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceDescriptorIndexingPropertiesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT;
constexpr auto StructureTypeDescriptorSetVariableDescriptorCountAllocateInfo             = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO;
constexpr auto StructureTypeDescriptorSetVariableDescriptorCountAllocateInfoEXT          = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT;
constexpr auto StructureTypeDescriptorSetVariableDescriptorCountLayoutSupport            = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT;
constexpr auto StructureTypeDescriptorSetVariableDescriptorCountLayoutSupportEXT         = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT;
constexpr auto StructureTypePhysicalDeviceDepthStencilResolveProperties                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceDepthStencilResolvePropertiesKHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR;
constexpr auto StructureTypeSubpassDescriptionDepthStencilResolve                        = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE;
constexpr auto StructureTypeSubpassDescriptionDepthStencilResolveKHR                     = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR;
constexpr auto StructureTypePhysicalDeviceScalarBlockLayoutFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
constexpr auto StructureTypePhysicalDeviceScalarBlockLayoutFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT;
constexpr auto StructureTypeImageStencilUsageCreateInfo                                  = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO;
constexpr auto StructureTypeImageStencilUsageCreateInfoEXT                               = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceSamplerFilterMinmaxProperties                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceSamplerFilterMinmaxPropertiesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT;
constexpr auto StructureTypeSamplerReductionModeCreateInfo                               = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO;
constexpr auto StructureTypeSamplerReductionModeCreateInfoEXT                            = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceVulkanMemoryModelFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkanMemoryModelFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceImagelessFramebufferFeatures                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
constexpr auto StructureTypePhysicalDeviceImagelessFramebufferFeaturesKHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR;
constexpr auto StructureTypeFramebufferAttachmentsCreateInfo                             = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO;
constexpr auto StructureTypeFramebufferAttachmentsCreateInfoKHR                          = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR;
constexpr auto StructureTypeFramebufferAttachmentImageInfo                               = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO;
constexpr auto StructureTypeFramebufferAttachmentImageInfoKHR                            = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR;
constexpr auto StructureTypeRenderPassAttachmentBeginInfo                                = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO;
constexpr auto StructureTypeRenderPassAttachmentBeginInfoKHR                             = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceUniformBufferStandardLayoutFeatures            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
constexpr auto StructureTypePhysicalDeviceUniformBufferStandardLayoutFeaturesKHR         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderSubgroupExtendedTypesFeatures            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceSeparateDepthStencilLayoutsFeatures            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
constexpr auto StructureTypePhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR;
constexpr auto StructureTypeAttachmentReferenceStencilLayout                             = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
constexpr auto StructureTypeAttachmentReferenceStencilLayoutKHR                          = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR;
constexpr auto StructureTypeAttachmentDescriptionStencilLayout                           = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT;
constexpr auto StructureTypeAttachmentDescriptionStencilLayoutKHR                        = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR;
constexpr auto StructureTypePhysicalDeviceHostQueryResetFeatures                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
constexpr auto StructureTypePhysicalDeviceHostQueryResetFeaturesEXT                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceTimelineSemaphoreFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
constexpr auto StructureTypePhysicalDeviceTimelineSemaphoreFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceTimelineSemaphoreProperties                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceTimelineSemaphorePropertiesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR;
constexpr auto StructureTypeSemaphoreTypeCreateInfo                                      = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
constexpr auto StructureTypeSemaphoreTypeCreateInfoKHR                                   = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR;
constexpr auto StructureTypeTimelineSemaphoreSubmitInfo                                  = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
constexpr auto StructureTypeTimelineSemaphoreSubmitInfoKHR                               = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR;
constexpr auto StructureTypeSemaphoreWaitInfo                                            = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
constexpr auto StructureTypeSemaphoreWaitInfoKHR                                         = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO_KHR;
constexpr auto StructureTypeSemaphoreSignalInfo                                          = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO;
constexpr auto StructureTypeSemaphoreSignalInfoKHR                                       = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceBufferDeviceAddressFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
constexpr auto StructureTypePhysicalDeviceBufferDeviceAddressFeaturesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR;
constexpr auto StructureTypeBufferDeviceAddressInfo                                      = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
constexpr auto StructureTypeBufferDeviceAddressInfoEXT                                   = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT;
constexpr auto StructureTypeBufferDeviceAddressInfoKHR                                   = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR;
constexpr auto StructureTypeBufferOpaqueCaptureAddressCreateInfo                         = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO;
constexpr auto StructureTypeBufferOpaqueCaptureAddressCreateInfoKHR                      = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR;
constexpr auto StructureTypeMemoryOpaqueCaptureAddressAllocateInfo                       = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO;
constexpr auto StructureTypeMemoryOpaqueCaptureAddressAllocateInfoKHR                    = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR;
constexpr auto StructureTypeDeviceMemoryOpaqueCaptureAddressInfo                         = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO;
constexpr auto StructureTypeDeviceMemoryOpaqueCaptureAddressInfoKHR                      = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVulkan13Features                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkan13Properties                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
constexpr auto StructureTypePipelineCreationFeedbackCreateInfo                           = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO;
constexpr auto StructureTypePipelineCreationFeedbackCreateInfoEXT                        = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceShaderTerminateInvocationFeatures              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderTerminateInvocationFeaturesKHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceToolProperties                                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceToolPropertiesEXT                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderDemoteToHelperInvocationFeatures         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePrivateDataFeatures                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
constexpr auto StructureTypePhysicalDevicePrivateDataFeaturesEXT                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT;
constexpr auto StructureTypeDevicePrivateDataCreateInfo                                  = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO;
constexpr auto StructureTypeDevicePrivateDataCreateInfoEXT                               = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT;
constexpr auto StructureTypePrivateDataSlotCreateInfo                                    = VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO;
constexpr auto StructureTypePrivateDataSlotCreateInfoEXT                                 = VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePipelineCreationCacheControlFeatures           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
constexpr auto StructureTypePhysicalDevicePipelineCreationCacheControlFeaturesEXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT;
constexpr auto StructureTypeMemoryBarrier2                                               = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
constexpr auto StructureTypeMemoryBarrier2KHR                                            = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR;
constexpr auto StructureTypeBufferMemoryBarrier2                                         = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2;
constexpr auto StructureTypeBufferMemoryBarrier2KHR                                      = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2_KHR;
constexpr auto StructureTypeImageMemoryBarrier2                                          = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
constexpr auto StructureTypeImageMemoryBarrier2KHR                                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2_KHR;
constexpr auto StructureTypeDependencyInfo                                               = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
constexpr auto StructureTypeDependencyInfoKHR                                            = VK_STRUCTURE_TYPE_DEPENDENCY_INFO_KHR;
constexpr auto StructureTypeSubmitInfo2                                                  = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
constexpr auto StructureTypeSubmitInfo2KHR                                               = VK_STRUCTURE_TYPE_SUBMIT_INFO_2_KHR;
constexpr auto StructureTypeSemaphoreSubmitInfo                                          = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
constexpr auto StructureTypeSemaphoreSubmitInfoKHR                                       = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO_KHR;
constexpr auto StructureTypeCommandBufferSubmitInfo                                      = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO;
constexpr auto StructureTypeCommandBufferSubmitInfoKHR                                   = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceSynchronization2Features                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
constexpr auto StructureTypePhysicalDeviceSynchronization2FeaturesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceZeroInitializeWorkgroupMemoryFeatures          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
constexpr auto StructureTypePhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceImageRobustnessFeatures                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
constexpr auto StructureTypePhysicalDeviceImageRobustnessFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT;
constexpr auto StructureTypeCopyBufferInfo2                                              = VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2;
constexpr auto StructureTypeCopyBufferInfo2KHR                                           = VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2_KHR;
constexpr auto StructureTypeCopyImageInfo2                                               = VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2;
constexpr auto StructureTypeCopyImageInfo2KHR                                            = VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2_KHR;
constexpr auto StructureTypeCopyBufferToImageInfo2                                       = VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2;
constexpr auto StructureTypeCopyBufferToImageInfo2KHR                                    = VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2_KHR;
constexpr auto StructureTypeCopyImageToBufferInfo2                                       = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2;
constexpr auto StructureTypeCopyImageToBufferInfo2KHR                                    = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2_KHR;
constexpr auto StructureTypeBlitImageInfo2                                               = VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2;
constexpr auto StructureTypeBlitImageInfo2KHR                                            = VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2_KHR;
constexpr auto StructureTypeResolveImageInfo2                                            = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2;
constexpr auto StructureTypeResolveImageInfo2KHR                                         = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2_KHR;
constexpr auto StructureTypeBufferCopy2                                                  = VK_STRUCTURE_TYPE_BUFFER_COPY_2;
constexpr auto StructureTypeBufferCopy2KHR                                               = VK_STRUCTURE_TYPE_BUFFER_COPY_2_KHR;
constexpr auto StructureTypeImageCopy2                                                   = VK_STRUCTURE_TYPE_IMAGE_COPY_2;
constexpr auto StructureTypeImageCopy2KHR                                                = VK_STRUCTURE_TYPE_IMAGE_COPY_2_KHR;
constexpr auto StructureTypeImageBlit2                                                   = VK_STRUCTURE_TYPE_IMAGE_BLIT_2;
constexpr auto StructureTypeImageBlit2KHR                                                = VK_STRUCTURE_TYPE_IMAGE_BLIT_2_KHR;
constexpr auto StructureTypeBufferImageCopy2                                             = VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2;
constexpr auto StructureTypeBufferImageCopy2KHR                                          = VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2_KHR;
constexpr auto StructureTypeImageResolve2                                                = VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2;
constexpr auto StructureTypeImageResolve2KHR                                             = VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2_KHR;
constexpr auto StructureTypePhysicalDeviceSubgroupSizeControlProperties                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceSubgroupSizeControlPropertiesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT;
constexpr auto StructureTypePipelineShaderStageRequiredSubgroupSizeCreateInfo            = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO;
constexpr auto StructureTypePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT         = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT;
constexpr auto StructureTypeShaderRequiredSubgroupSizeCreateInfoEXT                      = VK_STRUCTURE_TYPE_SHADER_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceSubgroupSizeControlFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
constexpr auto StructureTypePhysicalDeviceSubgroupSizeControlFeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceInlineUniformBlockFeatures                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
constexpr auto StructureTypePhysicalDeviceInlineUniformBlockFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceInlineUniformBlockProperties                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceInlineUniformBlockPropertiesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;
constexpr auto StructureTypeWriteDescriptorSetInlineUniformBlock                         = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK;
constexpr auto StructureTypeWriteDescriptorSetInlineUniformBlockEXT                      = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT;
constexpr auto StructureTypeDescriptorPoolInlineUniformBlockCreateInfo                   = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO;
constexpr auto StructureTypeDescriptorPoolInlineUniformBlockCreateInfoEXT                = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceTextureCompressionAstcHdrFeatures              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
constexpr auto StructureTypePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT;
constexpr auto StructureTypeRenderingInfo                                                = VK_STRUCTURE_TYPE_RENDERING_INFO;
constexpr auto StructureTypeRenderingInfoKHR                                             = VK_STRUCTURE_TYPE_RENDERING_INFO_KHR;
constexpr auto StructureTypeRenderingAttachmentInfo                                      = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
constexpr auto StructureTypeRenderingAttachmentInfoKHR                                   = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO_KHR;
constexpr auto StructureTypePipelineRenderingCreateInfo                                  = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO;
constexpr auto StructureTypePipelineRenderingCreateInfoKHR                               = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceDynamicRenderingFeatures                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
constexpr auto StructureTypePhysicalDeviceDynamicRenderingFeaturesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR;
constexpr auto StructureTypeCommandBufferInheritanceRenderingInfo                        = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO;
constexpr auto StructureTypeCommandBufferInheritanceRenderingInfoKHR                     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceShaderIntegerDotProductFeatures                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderIntegerDotProductFeaturesKHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderIntegerDotProductProperties              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceShaderIntegerDotProductPropertiesKHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceTexelBufferAlignmentProperties                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceTexelBufferAlignmentPropertiesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT;
constexpr auto StructureTypeFormatProperties3                                            = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3;
constexpr auto StructureTypeFormatProperties3KHR                                         = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance4Features                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
constexpr auto StructureTypePhysicalDeviceMaintenance4FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance4Properties                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceMaintenance4PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR;
constexpr auto StructureTypeDeviceBufferMemoryRequirements                               = VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS;
constexpr auto StructureTypeDeviceBufferMemoryRequirementsKHR                            = VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS_KHR;
constexpr auto StructureTypeDeviceImageMemoryRequirements                                = VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS;
constexpr auto StructureTypeDeviceImageMemoryRequirementsKHR                             = VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS_KHR;
constexpr auto StructureTypePhysicalDeviceVulkan14Features                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES;
constexpr auto StructureTypePhysicalDeviceVulkan14Properties                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES;
constexpr auto StructureTypeDeviceQueueGlobalPriorityCreateInfo                          = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO;
constexpr auto StructureTypeDeviceQueueGlobalPriorityCreateInfoEXT                       = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT;
constexpr auto StructureTypeDeviceQueueGlobalPriorityCreateInfoKHR                       = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceGlobalPriorityQueryFeatures                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES;
constexpr auto StructureTypePhysicalDeviceGlobalPriorityQueryFeaturesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceGlobalPriorityQueryFeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT;
constexpr auto StructureTypeQueueFamilyGlobalPriorityProperties                          = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES;
constexpr auto StructureTypeQueueFamilyGlobalPriorityPropertiesKHR                       = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR;
constexpr auto StructureTypeQueueFamilyGlobalPriorityPropertiesEXT                       = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderSubgroupRotateFeatures                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderSubgroupRotateFeaturesKHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderFloatControls2Features                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderFloatControls2FeaturesKHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderExpectAssumeFeatures                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES;
constexpr auto StructureTypePhysicalDeviceShaderExpectAssumeFeaturesKHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceLineRasterizationFeatures                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES;
constexpr auto StructureTypePhysicalDeviceLineRasterizationFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceLineRasterizationFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR;
constexpr auto StructureTypePipelineRasterizationLineStateCreateInfo                     = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineRasterizationLineStateCreateInfoEXT                  = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePipelineRasterizationLineStateCreateInfoKHR                  = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceLineRasterizationProperties                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceLineRasterizationPropertiesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceLineRasterizationPropertiesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorProperties               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorPropertiesKHR            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR;
constexpr auto StructureTypePipelineVertexInputDivisorStateCreateInfo                    = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO;
constexpr auto StructureTypePipelineVertexInputDivisorStateCreateInfoEXT                 = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePipelineVertexInputDivisorStateCreateInfoKHR                 = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorFeatures                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorFeaturesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorFeaturesKHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceIndexTypeUint8Features                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES;
constexpr auto StructureTypePhysicalDeviceIndexTypeUint8FeaturesEXT                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceIndexTypeUint8FeaturesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR;
constexpr auto StructureTypeMemoryMapInfo                                                = VK_STRUCTURE_TYPE_MEMORY_MAP_INFO;
constexpr auto StructureTypeMemoryMapInfoKHR                                             = VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR;
constexpr auto StructureTypeMemoryUnmapInfo                                              = VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO;
constexpr auto StructureTypeMemoryUnmapInfoKHR                                           = VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance5Features                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES;
constexpr auto StructureTypePhysicalDeviceMaintenance5FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance5Properties                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceMaintenance5PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR;
constexpr auto StructureTypeRenderingAreaInfo                                            = VK_STRUCTURE_TYPE_RENDERING_AREA_INFO;
constexpr auto StructureTypeRenderingAreaInfoKHR                                         = VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR;
constexpr auto StructureTypeDeviceImageSubresourceInfo                                   = VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO;
constexpr auto StructureTypeDeviceImageSubresourceInfoKHR                                = VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR;
constexpr auto StructureTypeSubresourceLayout2                                           = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2;
constexpr auto StructureTypeSubresourceLayout2EXT                                        = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_EXT;
constexpr auto StructureTypeSubresourceLayout2KHR                                        = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR;
constexpr auto StructureTypeImageSubresource2                                            = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2;
constexpr auto StructureTypeImageSubresource2EXT                                         = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_EXT;
constexpr auto StructureTypeImageSubresource2KHR                                         = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR;
constexpr auto StructureTypePipelineCreateFlags2CreateInfo                               = VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO;
constexpr auto StructureTypePipelineCreateFlags2CreateInfoKHR                            = VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR;
constexpr auto StructureTypeBufferUsageFlags2CreateInfo                                  = VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO;
constexpr auto StructureTypeBufferUsageFlags2CreateInfoKHR                               = VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDevicePushDescriptorProperties                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES;
constexpr auto StructureTypePhysicalDevicePushDescriptorPropertiesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceDynamicRenderingLocalReadFeatures              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES;
constexpr auto StructureTypePhysicalDeviceDynamicRenderingLocalReadFeaturesKHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR;
constexpr auto StructureTypeRenderingAttachmentLocationInfo                              = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO;
constexpr auto StructureTypeRenderingAttachmentLocationInfoKHR                           = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR;
constexpr auto StructureTypeRenderingInputAttachmentIndexInfo                            = VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO;
constexpr auto StructureTypeRenderingInputAttachmentIndexInfoKHR                         = VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance6Features                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES;
constexpr auto StructureTypePhysicalDeviceMaintenance6FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance6Properties                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceMaintenance6PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR;
constexpr auto StructureTypeBindMemoryStatus                                             = VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS;
constexpr auto StructureTypeBindMemoryStatusKHR                                          = VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR;
constexpr auto StructureTypeBindDescriptorSetsInfo                                       = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO;
constexpr auto StructureTypeBindDescriptorSetsInfoKHR                                    = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR;
constexpr auto StructureTypePushConstantsInfo                                            = VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO;
constexpr auto StructureTypePushConstantsInfoKHR                                         = VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR;
constexpr auto StructureTypePushDescriptorSetInfo                                        = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO;
constexpr auto StructureTypePushDescriptorSetInfoKHR                                     = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR;
constexpr auto StructureTypePushDescriptorSetWithTemplateInfo                            = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO;
constexpr auto StructureTypePushDescriptorSetWithTemplateInfoKHR                         = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR;
constexpr auto StructureTypePhysicalDevicePipelineProtectedAccessFeatures                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES;
constexpr auto StructureTypePhysicalDevicePipelineProtectedAccessFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT;
constexpr auto StructureTypePipelineRobustnessCreateInfo                                 = VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO;
constexpr auto StructureTypePipelineRobustnessCreateInfoEXT                              = VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePipelineRobustnessFeatures                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES;
constexpr auto StructureTypePhysicalDevicePipelineRobustnessFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePipelineRobustnessProperties                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES;
constexpr auto StructureTypePhysicalDevicePipelineRobustnessPropertiesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceHostImageCopyFeatures                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES;
constexpr auto StructureTypePhysicalDeviceHostImageCopyFeaturesEXT                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceHostImageCopyProperties                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES;
constexpr auto StructureTypePhysicalDeviceHostImageCopyPropertiesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT;
constexpr auto StructureTypeMemoryToImageCopy                                            = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY;
constexpr auto StructureTypeMemoryToImageCopyEXT                                         = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT;
constexpr auto StructureTypeImageToMemoryCopy                                            = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY;
constexpr auto StructureTypeImageToMemoryCopyEXT                                         = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT;
constexpr auto StructureTypeCopyImageToMemoryInfo                                        = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO;
constexpr auto StructureTypeCopyImageToMemoryInfoEXT                                     = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT;
constexpr auto StructureTypeCopyMemoryToImageInfo                                        = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO;
constexpr auto StructureTypeCopyMemoryToImageInfoEXT                                     = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT;
constexpr auto StructureTypeHostImageLayoutTransitionInfo                                = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO;
constexpr auto StructureTypeHostImageLayoutTransitionInfoEXT                             = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT;
constexpr auto StructureTypeCopyImageToImageInfo                                         = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO;
constexpr auto StructureTypeCopyImageToImageInfoEXT                                      = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT;
constexpr auto StructureTypeSubresourceHostMemcpySize                                    = VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE;
constexpr auto StructureTypeSubresourceHostMemcpySizeEXT                                 = VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT;
constexpr auto StructureTypeHostImageCopyDevicePerformanceQuery                          = VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY;
constexpr auto StructureTypeHostImageCopyDevicePerformanceQueryEXT                       = VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT;
constexpr auto StructureTypeSwapchainCreateInfoKHR                                       = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
constexpr auto StructureTypePresentInfoKHR                                               = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
constexpr auto StructureTypeDeviceGroupPresentCapabilitiesKHR                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR;
constexpr auto StructureTypeImageSwapchainCreateInfoKHR                                  = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
constexpr auto StructureTypeBindImageMemorySwapchainInfoKHR                              = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR;
constexpr auto StructureTypeAcquireNextImageInfoKHR                                      = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
constexpr auto StructureTypeDeviceGroupPresentInfoKHR                                    = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR;
constexpr auto StructureTypeDeviceGroupSwapchainCreateInfoKHR                            = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR;
constexpr auto StructureTypeDisplayModeCreateInfoKHR                                     = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
constexpr auto StructureTypeDisplaySurfaceCreateInfoKHR                                  = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
constexpr auto StructureTypeDisplayPresentInfoKHR                                        = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR;
#ifdef VK_USE_PLATFORM_XLIB_KHR
constexpr auto StructureTypeXlibSurfaceCreateInfoKHR                                     = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
constexpr auto StructureTypeXcbSurfaceCreateInfoKHR                                      = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
constexpr auto StructureTypeWaylandSurfaceCreateInfoKHR                                  = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
constexpr auto StructureTypeAndroidSurfaceCreateInfoKHR                                  = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeWin32SurfaceCreateInfoKHR                                    = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeDebugReportCallbackCreateInfoEXT                             = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
constexpr auto StructureTypeDebugReportCreateInfoEXT                                     = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
constexpr auto StructureTypePipelineRasterizationStateRasterizationOrderAMD              = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD;
constexpr auto StructureTypeDebugMarkerObjectNameInfoEXT                                 = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT;
constexpr auto StructureTypeDebugMarkerObjectTagInfoEXT                                  = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT;
constexpr auto StructureTypeDebugMarkerMarkerInfoEXT                                     = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT;
constexpr auto StructureTypeVideoProfileInfoKHR                                          = VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoCapabilitiesKHR                                         = VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoPictureResourceInfoKHR                                  = VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR;
constexpr auto StructureTypeVideoSessionMemoryRequirementsKHR                            = VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR;
constexpr auto StructureTypeBindVideoSessionMemoryInfoKHR                                = VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR;
constexpr auto StructureTypeVideoSessionCreateInfoKHR                                    = VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoSessionParametersCreateInfoKHR                          = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoSessionParametersUpdateInfoKHR                          = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR;
constexpr auto StructureTypeVideoBeginCodingInfoKHR                                      = VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR;
constexpr auto StructureTypeVideoEndCodingInfoKHR                                        = VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR;
constexpr auto StructureTypeVideoCodingControlInfoKHR                                    = VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR;
constexpr auto StructureTypeVideoReferenceSlotInfoKHR                                    = VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR;
constexpr auto StructureTypeQueueFamilyVideoPropertiesKHR                                = VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR;
constexpr auto StructureTypeVideoProfileListInfoKHR                                      = VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoFormatInfoKHR                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR;
constexpr auto StructureTypeVideoFormatPropertiesKHR                                     = VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR;
constexpr auto StructureTypeQueueFamilyQueryResultStatusPropertiesKHR                    = VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR;
constexpr auto StructureTypeVideoDecodeInfoKHR                                           = VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeCapabilitiesKHR                                   = VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoDecodeUsageInfoKHR                                      = VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR;
constexpr auto StructureTypeDedicatedAllocationImageCreateInfoNV                         = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV;
constexpr auto StructureTypeDedicatedAllocationBufferCreateInfoNV                        = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV;
constexpr auto StructureTypeDedicatedAllocationMemoryAllocateInfoNV                      = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceTransformFeedbackFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceTransformFeedbackPropertiesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
constexpr auto StructureTypePipelineRasterizationStateStreamCreateInfoEXT                = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT;
constexpr auto StructureTypeCuModuleCreateInfoNVX                                        = VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX;
constexpr auto StructureTypeCuFunctionCreateInfoNVX                                      = VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX;
constexpr auto StructureTypeCuLaunchInfoNVX                                              = VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX;
constexpr auto StructureTypeCuModuleTexturingModeCreateInfoNVX                           = VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX;
constexpr auto StructureTypeImageViewHandleInfoNVX                                       = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX;
constexpr auto StructureTypeImageViewAddressPropertiesNVX                                = VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX;
constexpr auto StructureTypeVideoEncodeH264CapabilitiesKHR                               = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeH264SessionParametersCreateInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264SessionParametersAddInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264PictureInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264DpbSlotInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264NaluSliceInfoKHR                              = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264GopRemainingFrameInfoKHR                      = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264ProfileInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264RateControlInfoKHR                            = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264RateControlLayerInfoKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264SessionCreateInfoKHR                          = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264QualityLevelPropertiesKHR                     = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeH264SessionParametersGetInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH264SessionParametersFeedbackInfoKHR              = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265CapabilitiesKHR                               = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeH265SessionParametersCreateInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265SessionParametersAddInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265PictureInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265DpbSlotInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265NaluSliceSegmentInfoKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265GopRemainingFrameInfoKHR                      = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265ProfileInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265RateControlInfoKHR                            = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265RateControlLayerInfoKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265SessionCreateInfoKHR                          = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265QualityLevelPropertiesKHR                     = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeH265SessionParametersGetInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR;
constexpr auto StructureTypeVideoEncodeH265SessionParametersFeedbackInfoKHR              = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH264CapabilitiesKHR                               = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoDecodeH264PictureInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH264ProfileInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH264SessionParametersCreateInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH264SessionParametersAddInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH264DpbSlotInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypeTextureLodGatherFormatPropertiesAMD                          = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD;
#ifdef VK_USE_PLATFORM_GGP
constexpr auto StructureTypeStreamDescriptorSurfaceCreateInfoGGP                         = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP;
#endif  // VK_USE_PLATFORM_GGP
constexpr auto StructureTypePhysicalDeviceCornerSampledImageFeaturesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
constexpr auto StructureTypeExternalMemoryImageCreateInfoNV                              = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV;
constexpr auto StructureTypeExportMemoryAllocateInfoNV                                   = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportMemoryWin32HandleInfoNV                                = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV;
constexpr auto StructureTypeExportMemoryWin32HandleInfoNV                                = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV;
constexpr auto StructureTypeWin32KeyedMutexAcquireReleaseInfoNV                          = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeValidationFlagsEXT                                           = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
#ifdef VK_USE_PLATFORM_VI_NN
constexpr auto StructureTypeViSurfaceCreateInfoNN                                        = VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN;
#endif  // VK_USE_PLATFORM_VI_NN
constexpr auto StructureTypeImageViewAstcDecodeModeEXT                                   = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT;
constexpr auto StructureTypePhysicalDeviceAstcDecodeFeaturesEXT                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportMemoryWin32HandleInfoKHR                               = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeExportMemoryWin32HandleInfoKHR                               = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeMemoryWin32HandlePropertiesKHR                               = VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR;
constexpr auto StructureTypeMemoryGetWin32HandleInfoKHR                                  = VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportMemoryFdInfoKHR                                        = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR;
constexpr auto StructureTypeMemoryFdPropertiesKHR                                        = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR;
constexpr auto StructureTypeMemoryGetFdInfoKHR                                           = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeWin32KeyedMutexAcquireReleaseInfoKHR                         = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR;
constexpr auto StructureTypeImportSemaphoreWin32HandleInfoKHR                            = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeExportSemaphoreWin32HandleInfoKHR                            = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeD3D12FenceSubmitInfoKHR                                      = VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR;
constexpr auto StructureTypeSemaphoreGetWin32HandleInfoKHR                               = VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportSemaphoreFdInfoKHR                                     = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR;
constexpr auto StructureTypeSemaphoreGetFdInfoKHR                                        = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR;
constexpr auto StructureTypeCommandBufferInheritanceConditionalRenderingInfoEXT          = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceConditionalRenderingFeaturesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
constexpr auto StructureTypeConditionalRenderingBeginInfoEXT                             = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT;
constexpr auto StructureTypePresentRegionsKHR                                            = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR;
constexpr auto StructureTypePipelineViewportWScalingStateCreateInfoNV                    = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV;
constexpr auto StructureTypeSurfaceCapabilities2EXT                                      = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT;
constexpr auto StructureTypeDisplayPowerInfoEXT                                          = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT;
constexpr auto StructureTypeDeviceEventInfoEXT                                           = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT;
constexpr auto StructureTypeDisplayEventInfoEXT                                          = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT;
constexpr auto StructureTypeSwapchainCounterCreateInfoEXT                                = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT;
constexpr auto StructureTypePresentTimesInfoGOOGLE                                       = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE;
constexpr auto StructureTypePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
constexpr auto StructureTypeMultiviewPerViewAttributesInfoNVX                            = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX;
constexpr auto StructureTypePipelineViewportSwizzleStateCreateInfoNV                     = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceDiscardRectanglePropertiesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
constexpr auto StructureTypePipelineDiscardRectangleStateCreateInfoEXT                   = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceConservativeRasterizationPropertiesEXT         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
constexpr auto StructureTypePipelineRasterizationConservativeStateCreateInfoEXT          = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceDepthClipEnableFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
constexpr auto StructureTypePipelineRasterizationDepthClipStateCreateInfoEXT             = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypeHdrMetadataEXT                                               = VK_STRUCTURE_TYPE_HDR_METADATA_EXT;
constexpr auto StructureTypePhysicalDeviceRelaxedLineRasterizationFeaturesIMG            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG;
constexpr auto StructureTypeSharedPresentSurfaceCapabilitiesKHR                          = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportFenceWin32HandleInfoKHR                                = VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeExportFenceWin32HandleInfoKHR                                = VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR;
constexpr auto StructureTypeFenceGetWin32HandleInfoKHR                                   = VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeImportFenceFdInfoKHR                                         = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
constexpr auto StructureTypeFenceGetFdInfoKHR                                            = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
constexpr auto StructureTypePhysicalDevicePerformanceQueryFeaturesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
constexpr auto StructureTypePhysicalDevicePerformanceQueryPropertiesKHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
constexpr auto StructureTypeQueryPoolPerformanceCreateInfoKHR                            = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR;
constexpr auto StructureTypePerformanceQuerySubmitInfoKHR                                = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR;
constexpr auto StructureTypeAcquireProfilingLockInfoKHR                                  = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR;
constexpr auto StructureTypePerformanceCounterKHR                                        = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR;
constexpr auto StructureTypePerformanceCounterDescriptionKHR                             = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR;
constexpr auto StructureTypePhysicalDeviceSurfaceInfo2KHR                                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
constexpr auto StructureTypeSurfaceCapabilities2KHR                                      = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
constexpr auto StructureTypeSurfaceFormat2KHR                                            = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
constexpr auto StructureTypeDisplayProperties2KHR                                        = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR;
constexpr auto StructureTypeDisplayPlaneProperties2KHR                                   = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR;
constexpr auto StructureTypeDisplayModeProperties2KHR                                    = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR;
constexpr auto StructureTypeDisplayPlaneInfo2KHR                                         = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR;
constexpr auto StructureTypeDisplayPlaneCapabilities2KHR                                 = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR;
#ifdef VK_USE_PLATFORM_IOS_MVK
constexpr auto StructureTypeIosSurfaceCreateInfoMVK                                      = VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK;
#endif  // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
constexpr auto StructureTypeMacosSurfaceCreateInfoMVK                                    = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
#endif  // VK_USE_PLATFORM_MACOS_MVK
constexpr auto StructureTypeDebugUtilsObjectNameInfoEXT                                  = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
constexpr auto StructureTypeDebugUtilsObjectTagInfoEXT                                   = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
constexpr auto StructureTypeDebugUtilsLabelEXT                                           = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT;
constexpr auto StructureTypeDebugUtilsMessengerCallbackDataEXT                           = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT;
constexpr auto StructureTypeDebugUtilsMessengerCreateInfoEXT                             = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
constexpr auto StructureTypeAndroidHardwareBufferUsageANDROID                            = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID;
constexpr auto StructureTypeAndroidHardwareBufferPropertiesANDROID                       = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID;
constexpr auto StructureTypeAndroidHardwareBufferFormatPropertiesANDROID                 = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID;
constexpr auto StructureTypeImportAndroidHardwareBufferInfoANDROID                       = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
constexpr auto StructureTypeMemoryGetAndroidHardwareBufferInfoANDROID                    = VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
constexpr auto StructureTypeExternalFormatANDROID                                        = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID;
constexpr auto StructureTypeAndroidHardwareBufferFormatProperties2ANDROID                = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceShaderEnqueueFeaturesAMDX                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX;
constexpr auto StructureTypePhysicalDeviceShaderEnqueuePropertiesAMDX                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX;
constexpr auto StructureTypeExecutionGraphPipelineScratchSizeAMDX                        = VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX;
constexpr auto StructureTypeExecutionGraphPipelineCreateInfoAMDX                         = VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX;
constexpr auto StructureTypePipelineShaderStageNodeCreateInfoAMDX                        = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypeAttachmentSampleCountInfoAMD                                 = VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD;
constexpr auto StructureTypeAttachmentSampleCountInfoNV                                  = VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_NV;
constexpr auto StructureTypePhysicalDeviceShaderBfloat16FeaturesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR;
constexpr auto StructureTypeSampleLocationsInfoEXT                                       = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT;
constexpr auto StructureTypeRenderPassSampleLocationsBeginInfoEXT                        = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT;
constexpr auto StructureTypePipelineSampleLocationsStateCreateInfoEXT                    = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceSampleLocationsPropertiesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
constexpr auto StructureTypeMultisamplePropertiesEXT                                     = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceBlendOperationAdvancedFeaturesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceBlendOperationAdvancedPropertiesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
constexpr auto StructureTypePipelineColorBlendAdvancedStateCreateInfoEXT                 = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePipelineCoverageToColorStateCreateInfoNV                     = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV;
constexpr auto StructureTypeWriteDescriptorSetAccelerationStructureKHR                   = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
constexpr auto StructureTypeAccelerationStructureBuildGeometryInfoKHR                    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
constexpr auto StructureTypeAccelerationStructureDeviceAddressInfoKHR                    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR;
constexpr auto StructureTypeAccelerationStructureGeometryAabbsDataKHR                    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR;
constexpr auto StructureTypeAccelerationStructureGeometryInstancesDataKHR                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR;
constexpr auto StructureTypeAccelerationStructureGeometryTrianglesDataKHR                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR;
constexpr auto StructureTypeAccelerationStructureGeometryKHR                             = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
constexpr auto StructureTypeAccelerationStructureVersionInfoKHR                          = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR;
constexpr auto StructureTypeCopyAccelerationStructureInfoKHR                             = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR;
constexpr auto StructureTypeCopyAccelerationStructureToMemoryInfoKHR                     = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR;
constexpr auto StructureTypeCopyMemoryToAccelerationStructureInfoKHR                     = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceAccelerationStructureFeaturesKHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceAccelerationStructurePropertiesKHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR;
constexpr auto StructureTypeAccelerationStructureCreateInfoKHR                           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR;
constexpr auto StructureTypeAccelerationStructureBuildSizesInfoKHR                       = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceRayTracingPipelineFeaturesKHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceRayTracingPipelinePropertiesKHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;
constexpr auto StructureTypeRayTracingPipelineCreateInfoKHR                              = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR;
constexpr auto StructureTypeRayTracingShaderGroupCreateInfoKHR                           = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR;
constexpr auto StructureTypeRayTracingPipelineInterfaceCreateInfoKHR                     = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceRayQueryFeaturesKHR                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR;
constexpr auto StructureTypePipelineCoverageModulationStateCreateInfoNV                  = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceShaderSmBuiltinsFeaturesNV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceShaderSmBuiltinsPropertiesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
constexpr auto StructureTypeDrmFormatModifierPropertiesListEXT                           = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT;
constexpr auto StructureTypePhysicalDeviceImageDrmFormatModifierInfoEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT;
constexpr auto StructureTypeImageDrmFormatModifierListCreateInfoEXT                      = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT;
constexpr auto StructureTypeImageDrmFormatModifierExplicitCreateInfoEXT                  = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT;
constexpr auto StructureTypeImageDrmFormatModifierPropertiesEXT                          = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
constexpr auto StructureTypeDrmFormatModifierPropertiesList2EXT                          = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT;
constexpr auto StructureTypeValidationCacheCreateInfoEXT                                 = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT;
constexpr auto StructureTypeShaderModuleValidationCacheCreateInfoEXT                     = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDevicePortabilitySubsetFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR;
constexpr auto StructureTypePhysicalDevicePortabilitySubsetPropertiesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePipelineViewportShadingRateImageStateCreateInfoNV            = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceShadingRateImageFeaturesNV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceShadingRateImagePropertiesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
constexpr auto StructureTypePipelineViewportCoarseSampleOrderStateCreateInfoNV           = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV;
constexpr auto StructureTypeRayTracingPipelineCreateInfoNV                               = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV;
constexpr auto StructureTypeAccelerationStructureCreateInfoNV                            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV;
constexpr auto StructureTypeGeometryNV                                                   = VK_STRUCTURE_TYPE_GEOMETRY_NV;
constexpr auto StructureTypeGeometryTrianglesNV                                          = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV;
constexpr auto StructureTypeGeometryAabbNV                                               = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV;
constexpr auto StructureTypeBindAccelerationStructureMemoryInfoNV                        = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV;
constexpr auto StructureTypeWriteDescriptorSetAccelerationStructureNV                    = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV;
constexpr auto StructureTypeAccelerationStructureMemoryRequirementsInfoNV                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV;
constexpr auto StructureTypePhysicalDeviceRayTracingPropertiesNV                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
constexpr auto StructureTypeRayTracingShaderGroupCreateInfoNV                            = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV;
constexpr auto StructureTypeAccelerationStructureInfoNV                                  = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceRepresentativeFragmentTestFeaturesNV           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
constexpr auto StructureTypePipelineRepresentativeFragmentTestStateCreateInfoNV          = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceImageViewImageFormatInfoEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT;
constexpr auto StructureTypeFilterCubicImageViewImageFormatPropertiesEXT                 = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT;
constexpr auto StructureTypeImportMemoryHostPointerInfoEXT                               = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
constexpr auto StructureTypeMemoryHostPointerPropertiesEXT                               = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceExternalMemoryHostPropertiesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderClockFeaturesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
constexpr auto StructureTypePipelineCompilerControlCreateInfoAMD                         = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD;
constexpr auto StructureTypePhysicalDeviceShaderCorePropertiesAMD                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
constexpr auto StructureTypeVideoDecodeH265CapabilitiesKHR                               = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoDecodeH265SessionParametersCreateInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH265SessionParametersAddInfoKHR                   = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH265ProfileInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH265PictureInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH265DpbSlotInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypeDeviceMemoryOverallocationCreateInfoAMD                      = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD;
constexpr auto StructureTypePhysicalDeviceVertexAttributeDivisorPropertiesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
#ifdef VK_USE_PLATFORM_GGP
constexpr auto StructureTypePresentFrameTokenGGP                                         = VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP;
#endif  // VK_USE_PLATFORM_GGP
constexpr auto StructureTypePhysicalDeviceMeshShaderFeaturesNV                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceMeshShaderPropertiesNV                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceShaderImageFootprintFeaturesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
constexpr auto StructureTypePipelineViewportExclusiveScissorStateCreateInfoNV            = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDeviceExclusiveScissorFeaturesNV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
constexpr auto StructureTypeCheckpointDataNV                                             = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV;
constexpr auto StructureTypeQueueFamilyCheckpointPropertiesNV                            = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV;
constexpr auto StructureTypeQueueFamilyCheckpointProperties2NV                           = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV;
constexpr auto StructureTypeCheckpointData2NV                                            = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV;
constexpr auto StructureTypePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
constexpr auto StructureTypeQueryPoolPerformanceQueryCreateInfoINTEL                     = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL;
constexpr auto StructureTypeQueryPoolCreateInfoINTEL                                     = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL;
constexpr auto StructureTypeInitializePerformanceApiInfoINTEL                            = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL;
constexpr auto StructureTypePerformanceMarkerInfoINTEL                                   = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL;
constexpr auto StructureTypePerformanceStreamMarkerInfoINTEL                             = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL;
constexpr auto StructureTypePerformanceOverrideInfoINTEL                                 = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL;
constexpr auto StructureTypePerformanceConfigurationAcquireInfoINTEL                     = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL;
constexpr auto StructureTypePhysicalDevicePciBusInfoPropertiesEXT                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
constexpr auto StructureTypeDisplayNativeHdrSurfaceCapabilitiesAMD                       = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD;
constexpr auto StructureTypeSwapchainDisplayNativeHdrCreateInfoAMD                       = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD;
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto StructureTypeImagepipeSurfaceCreateInfoFUCHSIA                            = VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypeMetalSurfaceCreateInfoEXT                                    = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
#endif  // VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapPropertiesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
constexpr auto StructureTypeRenderPassFragmentDensityMapCreateInfoEXT                    = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT;
constexpr auto StructureTypeRenderingFragmentDensityMapAttachmentInfoEXT                 = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT;
constexpr auto StructureTypeFragmentShadingRateAttachmentInfoKHR                         = VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR;
constexpr auto StructureTypePipelineFragmentShadingRateStateCreateInfoKHR                = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceFragmentShadingRatePropertiesKHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceFragmentShadingRateFeaturesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceFragmentShadingRateKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR;
constexpr auto StructureTypeRenderingFragmentShadingRateAttachmentInfoKHR                = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceShaderCoreProperties2AMD                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
constexpr auto StructureTypePhysicalDeviceCoherentMemoryFeaturesAMD                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
constexpr auto StructureTypePhysicalDeviceShaderImageAtomicInt64FeaturesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderQuadControlFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMemoryBudgetPropertiesEXT                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceMemoryPriorityFeaturesEXT                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
constexpr auto StructureTypeMemoryPriorityAllocateInfoEXT                                = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT;
constexpr auto StructureTypeSurfaceProtectedCapabilitiesKHR                              = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR;
constexpr auto StructureTypePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceBufferDeviceAddressFeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceBufferAddressFeaturesEXT                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT;
constexpr auto StructureTypeBufferDeviceAddressCreateInfoEXT                             = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT;
constexpr auto StructureTypeValidationFeaturesEXT                                        = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePresentWaitFeaturesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrixFeaturesNV                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
constexpr auto StructureTypeCooperativeMatrixPropertiesNV                                = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrixPropertiesNV                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceCoverageReductionModeFeaturesNV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
constexpr auto StructureTypePipelineCoverageReductionStateCreateInfoNV                   = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV;
constexpr auto StructureTypeFramebufferMixedSamplesCombinationNV                         = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV;
constexpr auto StructureTypePhysicalDeviceFragmentShaderInterlockFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceYcbcrImageArraysFeaturesEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceProvokingVertexFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT;
constexpr auto StructureTypePipelineRasterizationProvokingVertexStateCreateInfoEXT       = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceProvokingVertexPropertiesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT;
#ifdef VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeSurfaceFullScreenExclusiveInfoEXT                            = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT;
constexpr auto StructureTypeSurfaceCapabilitiesFullScreenExclusiveEXT                    = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT;
constexpr auto StructureTypeSurfaceFullScreenExclusiveWin32InfoEXT                       = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT;
#endif  // VK_USE_PLATFORM_WIN32_KHR
constexpr auto StructureTypeHeadlessSurfaceCreateInfoEXT                                 = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceShaderAtomicFloatFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceExtendedDynamicStateFeaturesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePipelineExecutablePropertiesFeaturesKHR        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
constexpr auto StructureTypePipelineInfoKHR                                              = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR;
constexpr auto StructureTypePipelineInfoEXT                                              = VK_STRUCTURE_TYPE_PIPELINE_INFO_EXT;
constexpr auto StructureTypePipelineExecutablePropertiesKHR                              = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR;
constexpr auto StructureTypePipelineExecutableInfoKHR                                    = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR;
constexpr auto StructureTypePipelineExecutableStatisticKHR                               = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR;
constexpr auto StructureTypePipelineExecutableInternalRepresentationKHR                  = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR;
constexpr auto StructureTypePhysicalDeviceMapMemoryPlacedFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceMapMemoryPlacedPropertiesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT;
constexpr auto StructureTypeMemoryMapPlacedInfoEXT                                       = VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceShaderAtomicFloat2FeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceDeviceGeneratedCommandsPropertiesNV            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
constexpr auto StructureTypeGraphicsShaderGroupCreateInfoNV                              = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV;
constexpr auto StructureTypeGraphicsPipelineShaderGroupsCreateInfoNV                     = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV;
constexpr auto StructureTypeIndirectCommandsLayoutTokenNV                                = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV;
constexpr auto StructureTypeIndirectCommandsLayoutCreateInfoNV                           = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV;
constexpr auto StructureTypeGeneratedCommandsInfoNV                                      = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV;
constexpr auto StructureTypeGeneratedCommandsMemoryRequirementsInfoNV                    = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV;
constexpr auto StructureTypePhysicalDeviceDeviceGeneratedCommandsFeaturesNV              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceInheritedViewportScissorFeaturesNV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV;
constexpr auto StructureTypeCommandBufferInheritanceViewportScissorInfoNV                = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV;
constexpr auto StructureTypePhysicalDeviceTexelBufferAlignmentFeaturesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
constexpr auto StructureTypeCommandBufferInheritanceRenderPassTransformInfoQCOM          = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM;
constexpr auto StructureTypeRenderPassTransformBeginInfoQCOM                             = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceDepthBiasControlFeaturesEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT;
constexpr auto StructureTypeDepthBiasInfoEXT                                             = VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT;
constexpr auto StructureTypeDepthBiasRepresentationInfoEXT                               = VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceDeviceMemoryReportFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT;
constexpr auto StructureTypeDeviceDeviceMemoryReportCreateInfoEXT                        = VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT;
constexpr auto StructureTypeDeviceMemoryReportCallbackDataEXT                            = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT;
constexpr auto StructureTypeSamplerCustomBorderColorCreateInfoEXT                        = VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceCustomBorderColorPropertiesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceCustomBorderColorFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT;
constexpr auto StructureTypePipelineLibraryCreateInfoKHR                                 = VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDevicePresentBarrierFeaturesNV                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV;
constexpr auto StructureTypeSurfaceCapabilitiesPresentBarrierNV                          = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV;
constexpr auto StructureTypeSwapchainPresentBarrierCreateInfoNV                          = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV;
constexpr auto StructureTypePresentIdKHR                                                 = VK_STRUCTURE_TYPE_PRESENT_ID_KHR;
constexpr auto StructureTypePhysicalDevicePresentIdFeaturesKHR                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR;
constexpr auto StructureTypeVideoEncodeInfoKHR                                           = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeRateControlInfoKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeRateControlLayerInfoKHR                           = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR;
constexpr auto StructureTypeVideoEncodeCapabilitiesKHR                                   = VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeUsageInfoKHR                                      = VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR;
constexpr auto StructureTypeQueryPoolVideoEncodeFeedbackCreateInfoKHR                    = VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoEncodeQualityLevelInfoKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeQualityLevelPropertiesKHR                         = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeQualityLevelInfoKHR                               = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeSessionParametersGetInfoKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR;
constexpr auto StructureTypeVideoEncodeSessionParametersFeedbackInfoKHR                  = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceDiagnosticsConfigFeaturesNV                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV;
constexpr auto StructureTypeDeviceDiagnosticsConfigCreateInfoNV                          = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypeCudaModuleCreateInfoNV                                       = VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV;
constexpr auto StructureTypeCudaFunctionCreateInfoNV                                     = VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV;
constexpr auto StructureTypeCudaLaunchInfoNV                                             = VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV;
constexpr auto StructureTypePhysicalDeviceCudaKernelLaunchFeaturesNV                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceCudaKernelLaunchPropertiesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceTileShadingFeaturesQCOM                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceTileShadingPropertiesQCOM                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM;
constexpr auto StructureTypeRenderPassTileShadingCreateInfoQCOM                          = VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM;
constexpr auto StructureTypePerTileBeginInfoQCOM                                         = VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM;
constexpr auto StructureTypePerTileEndInfoQCOM                                           = VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM;
constexpr auto StructureTypeDispatchTileInfoQCOM                                         = VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM;
constexpr auto StructureTypeQueryLowLatencySupportNV                                     = VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV;
#ifdef VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypeExportMetalObjectCreateInfoEXT                               = VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT;
constexpr auto StructureTypeExportMetalObjectsInfoEXT                                    = VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT;
constexpr auto StructureTypeExportMetalDeviceInfoEXT                                     = VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT;
constexpr auto StructureTypeExportMetalCommandQueueInfoEXT                               = VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT;
constexpr auto StructureTypeExportMetalBufferInfoEXT                                     = VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT;
constexpr auto StructureTypeImportMetalBufferInfoEXT                                     = VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT;
constexpr auto StructureTypeExportMetalTextureInfoEXT                                    = VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT;
constexpr auto StructureTypeImportMetalTextureInfoEXT                                    = VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT;
constexpr auto StructureTypeExportMetalIoSurfaceInfoEXT                                  = VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT;
constexpr auto StructureTypeImportMetalIoSurfaceInfoEXT                                  = VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT;
constexpr auto StructureTypeExportMetalSharedEventInfoEXT                                = VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT;
constexpr auto StructureTypeImportMetalSharedEventInfoEXT                                = VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT;
#endif  // VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypePhysicalDeviceDescriptorBufferPropertiesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorBufferDensityMapPropertiesEXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorBufferFeaturesEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT;
constexpr auto StructureTypeDescriptorAddressInfoEXT                                     = VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT;
constexpr auto StructureTypeDescriptorGetInfoEXT                                         = VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT;
constexpr auto StructureTypeBufferCaptureDescriptorDataInfoEXT                           = VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
constexpr auto StructureTypeImageCaptureDescriptorDataInfoEXT                            = VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
constexpr auto StructureTypeImageViewCaptureDescriptorDataInfoEXT                        = VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
constexpr auto StructureTypeSamplerCaptureDescriptorDataInfoEXT                          = VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
constexpr auto StructureTypeOpaqueCaptureDescriptorDataCreateInfoEXT                     = VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT;
constexpr auto StructureTypeDescriptorBufferBindingInfoEXT                               = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT;
constexpr auto StructureTypeDescriptorBufferBindingPushDescriptorBufferHandleEXT         = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT;
constexpr auto StructureTypeAccelerationStructureCaptureDescriptorDataInfoEXT            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceGraphicsPipelineLibraryFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceGraphicsPipelineLibraryPropertiesEXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT;
constexpr auto StructureTypeGraphicsPipelineLibraryCreateInfoEXT                         = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD;
constexpr auto StructureTypePhysicalDeviceFragmentShaderBarycentricFeaturesKHR           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceFragmentShaderBarycentricFeaturesNV            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceFragmentShaderBarycentricPropertiesKHR         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceFragmentShadingRateEnumsPropertiesNV           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceFragmentShadingRateEnumsFeaturesNV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV;
constexpr auto StructureTypePipelineFragmentShadingRateEnumStateCreateInfoNV             = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV;
constexpr auto StructureTypeAccelerationStructureGeometryMotionTrianglesDataNV           = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV;
constexpr auto StructureTypePhysicalDeviceRayTracingMotionBlurFeaturesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV;
constexpr auto StructureTypeAccelerationStructureMotionInfoNV                            = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV;
constexpr auto StructureTypePhysicalDeviceMeshShaderFeaturesEXT                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceMeshShaderPropertiesEXT                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMap2FeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMap2PropertiesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT;
constexpr auto StructureTypeCopyCommandTransformInfoQCOM                                 = VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceImageCompressionControlFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT;
constexpr auto StructureTypeImageCompressionControlEXT                                   = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT;
constexpr auto StructureTypeImageCompressionPropertiesEXT                                = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevice4444FormatsFeaturesEXT                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFaultFeaturesEXT                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT;
constexpr auto StructureTypeDeviceFaultCountsEXT                                         = VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT;
constexpr auto StructureTypeDeviceFaultInfoEXT                                           = VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceRgba10X6FormatsFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT;
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
constexpr auto StructureTypeDirectfbSurfaceCreateInfoEXT                                 = VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT;
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
constexpr auto StructureTypePhysicalDeviceVertexInputDynamicStateFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
constexpr auto StructureTypeVertexInputBindingDescription2EXT                            = VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT;
constexpr auto StructureTypeVertexInputAttributeDescription2EXT                          = VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT;
constexpr auto StructureTypePhysicalDeviceDrmPropertiesEXT                               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceAddressBindingReportFeaturesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT;
constexpr auto StructureTypeDeviceAddressBindingCallbackDataEXT                          = VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT;
constexpr auto StructureTypePhysicalDeviceDepthClipControlFeaturesEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT;
constexpr auto StructureTypePipelineViewportDepthClipControlCreateInfoEXT                = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePrimitiveTopologyListRestartFeaturesEXT        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT;
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto StructureTypeImportMemoryZirconHandleInfoFUCHSIA                          = VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA;
constexpr auto StructureTypeMemoryZirconHandlePropertiesFUCHSIA                          = VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA;
constexpr auto StructureTypeMemoryGetZirconHandleInfoFUCHSIA                             = VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA;
constexpr auto StructureTypeImportSemaphoreZirconHandleInfoFUCHSIA                       = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA;
constexpr auto StructureTypeSemaphoreGetZirconHandleInfoFUCHSIA                          = VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA;
constexpr auto StructureTypeBufferCollectionCreateInfoFUCHSIA                            = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA;
constexpr auto StructureTypeImportMemoryBufferCollectionFUCHSIA                          = VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA;
constexpr auto StructureTypeBufferCollectionImageCreateInfoFUCHSIA                       = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA;
constexpr auto StructureTypeBufferCollectionPropertiesFUCHSIA                            = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA;
constexpr auto StructureTypeBufferConstraintsInfoFUCHSIA                                 = VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA;
constexpr auto StructureTypeBufferCollectionBufferCreateInfoFUCHSIA                      = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA;
constexpr auto StructureTypeImageConstraintsInfoFUCHSIA                                  = VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA;
constexpr auto StructureTypeImageFormatConstraintsInfoFUCHSIA                            = VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA;
constexpr auto StructureTypeSysmemColorSpaceFUCHSIA                                      = VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA;
constexpr auto StructureTypeBufferCollectionConstraintsInfoFUCHSIA                       = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
constexpr auto StructureTypeSubpassShadingPipelineCreateInfoHUAWEI                       = VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI;
constexpr auto StructureTypePhysicalDeviceSubpassShadingFeaturesHUAWEI                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI;
constexpr auto StructureTypePhysicalDeviceSubpassShadingPropertiesHUAWEI                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI;
constexpr auto StructureTypePhysicalDeviceInvocationMaskFeaturesHUAWEI                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI;
constexpr auto StructureTypeMemoryGetRemoteAddressInfoNV                                 = VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV;
constexpr auto StructureTypePhysicalDeviceExternalMemoryRdmaFeaturesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV;
constexpr auto StructureTypePipelinePropertiesIdentifierEXT                              = VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT;
constexpr auto StructureTypePhysicalDevicePipelinePropertiesFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFrameBoundaryFeaturesEXT                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
constexpr auto StructureTypeFrameBoundaryEXT                                             = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
constexpr auto StructureTypePhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT;
constexpr auto StructureTypeSubpassResolvePerformanceQueryEXT                            = VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT;
constexpr auto StructureTypeMultisampledRenderToSingleSampledInfoEXT                     = VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceExtendedDynamicState2FeaturesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
constexpr auto StructureTypeScreenSurfaceCreateInfoQNX                                   = VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX;
#endif  // VK_USE_PLATFORM_SCREEN_QNX
constexpr auto StructureTypePhysicalDeviceColorWriteEnableFeaturesEXT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT;
constexpr auto StructureTypePipelineColorWriteCreateInfoEXT                              = VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePrimitivesGeneratedQueryFeaturesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceRayTracingMaintenance1FeaturesKHR              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderUntypedPointersFeaturesKHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE;
constexpr auto StructureTypeVideoEncodeRgbConversionCapabilitiesVALVE                    = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE;
constexpr auto StructureTypeVideoEncodeProfileRgbConversionInfoVALVE                     = VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE;
constexpr auto StructureTypeVideoEncodeSessionRgbConversionCreateInfoVALVE               = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE;
constexpr auto StructureTypePhysicalDeviceImageViewMinLodFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT;
constexpr auto StructureTypeImageViewMinLodCreateInfoEXT                                 = VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceMultiDrawFeaturesEXT                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceMultiDrawPropertiesEXT                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceImage2DViewOf3DFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderTileImageFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderTileImagePropertiesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT;
constexpr auto StructureTypeMicromapBuildInfoEXT                                         = VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT;
constexpr auto StructureTypeMicromapVersionInfoEXT                                       = VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT;
constexpr auto StructureTypeCopyMicromapInfoEXT                                          = VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT;
constexpr auto StructureTypeCopyMicromapToMemoryInfoEXT                                  = VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT;
constexpr auto StructureTypeCopyMemoryToMicromapInfoEXT                                  = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceOpacityMicromapFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceOpacityMicromapPropertiesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT;
constexpr auto StructureTypeMicromapCreateInfoEXT                                        = VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT;
constexpr auto StructureTypeMicromapBuildSizesInfoEXT                                    = VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT;
constexpr auto StructureTypeAccelerationStructureTrianglesOpacityMicromapEXT             = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceDisplacementMicromapFeaturesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceDisplacementMicromapPropertiesNV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV;
constexpr auto StructureTypeAccelerationStructureTrianglesDisplacementMicromapNV         = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceClusterCullingShaderFeaturesHUAWEI             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI;
constexpr auto StructureTypePhysicalDeviceClusterCullingShaderPropertiesHUAWEI           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI;
constexpr auto StructureTypePhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI;
constexpr auto StructureTypePhysicalDeviceBorderColorSwizzleFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT;
constexpr auto StructureTypeSamplerBorderColorComponentMappingCreateInfoEXT              = VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePageableDeviceLocalMemoryFeaturesEXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderCorePropertiesARM                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM;
constexpr auto StructureTypeDeviceQueueShaderCoreControlCreateInfoARM                    = VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM;
constexpr auto StructureTypePhysicalDeviceSchedulingControlsFeaturesARM                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceSchedulingControlsPropertiesARM                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM;
constexpr auto StructureTypePhysicalDeviceImageSlicedViewOf3DFeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT;
constexpr auto StructureTypeImageViewSlicedCreateInfoEXT                                 = VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorSetHostMappingFeaturesVALVE          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE;
constexpr auto StructureTypeDescriptorSetBindingReferenceVALVE                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE;
constexpr auto StructureTypeDescriptorSetLayoutHostMappingInfoVALVE                      = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE;
constexpr auto StructureTypePhysicalDeviceNonSeamlessCubeMapFeaturesEXT                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceRenderPassStripedFeaturesARM                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceRenderPassStripedPropertiesARM                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM;
constexpr auto StructureTypeRenderPassStripeBeginInfoARM                                 = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM;
constexpr auto StructureTypeRenderPassStripeInfoARM                                      = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM;
constexpr auto StructureTypeRenderPassStripeSubmitInfoARM                                = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM;
constexpr auto StructureTypePhysicalDeviceCopyMemoryIndirectFeaturesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceMemoryDecompressionFeaturesNV                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceMemoryDecompressionPropertiesNV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV;
constexpr auto StructureTypeComputePipelineIndirectBufferInfoNV                          = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV;
constexpr auto StructureTypePipelineIndirectDeviceAddressInfoNV                          = VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV;
constexpr auto StructureTypePhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV;
constexpr auto StructureTypeAccelerationStructureGeometryLinearSweptSpheresDataNV        = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV;
constexpr auto StructureTypeAccelerationStructureGeometrySpheresDataNV                   = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV;
constexpr auto StructureTypePhysicalDeviceLinearColorAttachmentFeaturesNV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceShaderMaximalReconvergenceFeaturesKHR          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceImageCompressionControlSwapchainFeaturesEXT    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceImageProcessingFeaturesQCOM                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceImageProcessingPropertiesQCOM                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM;
constexpr auto StructureTypeImageViewSampleWeightCreateInfoQCOM                          = VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceNestedCommandBufferFeaturesEXT                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceNestedCommandBufferPropertiesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT;
constexpr auto StructureTypeExternalMemoryAcquireUnmodifiedEXT                           = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT;
constexpr auto StructureTypePhysicalDeviceExtendedDynamicState3FeaturesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceExtendedDynamicState3PropertiesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceSubpassMergeFeedbackFeaturesEXT                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT;
constexpr auto StructureTypeRenderPassCreationControlEXT                                 = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT;
constexpr auto StructureTypeRenderPassCreationFeedbackCreateInfoEXT                      = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT;
constexpr auto StructureTypeRenderPassSubpassFeedbackCreateInfoEXT                       = VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT;
constexpr auto StructureTypeDirectDriverLoadingInfoLUNARG                                = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG;
constexpr auto StructureTypeDirectDriverLoadingListLUNARG                                = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG;
constexpr auto StructureTypeTensorCreateInfoARM                                          = VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM;
constexpr auto StructureTypeTensorViewCreateInfoARM                                      = VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM;
constexpr auto StructureTypeBindTensorMemoryInfoARM                                      = VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM;
constexpr auto StructureTypeWriteDescriptorSetTensorARM                                  = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM;
constexpr auto StructureTypePhysicalDeviceTensorPropertiesARM                            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM;
constexpr auto StructureTypeTensorFormatPropertiesARM                                    = VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM;
constexpr auto StructureTypeTensorDescriptionARM                                         = VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM;
constexpr auto StructureTypeTensorMemoryRequirementsInfoARM                              = VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM;
constexpr auto StructureTypeTensorMemoryBarrierARM                                       = VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM;
constexpr auto StructureTypePhysicalDeviceTensorFeaturesARM                              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM;
constexpr auto StructureTypeDeviceTensorMemoryRequirementsARM                            = VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM;
constexpr auto StructureTypeCopyTensorInfoARM                                            = VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM;
constexpr auto StructureTypeTensorCopyARM                                                = VK_STRUCTURE_TYPE_TENSOR_COPY_ARM;
constexpr auto StructureTypeTensorDependencyInfoARM                                      = VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM;
constexpr auto StructureTypeMemoryDedicatedAllocateInfoTensorARM                         = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM;
constexpr auto StructureTypePhysicalDeviceExternalTensorInfoARM                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM;
constexpr auto StructureTypeExternalTensorPropertiesARM                                  = VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM;
constexpr auto StructureTypeExternalMemoryTensorCreateInfoARM                            = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM;
constexpr auto StructureTypePhysicalDeviceDescriptorBufferTensorFeaturesARM              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceDescriptorBufferTensorPropertiesARM            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM;
constexpr auto StructureTypeDescriptorGetTensorInfoARM                                   = VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM;
constexpr auto StructureTypeTensorCaptureDescriptorDataInfoARM                           = VK_STRUCTURE_TYPE_TENSOR_CAPTURE_DESCRIPTOR_DATA_INFO_ARM;
constexpr auto StructureTypeTensorViewCaptureDescriptorDataInfoARM                       = VK_STRUCTURE_TYPE_TENSOR_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_ARM;
constexpr auto StructureTypeFrameBoundaryTensorsARM                                      = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM;
constexpr auto StructureTypePhysicalDeviceShaderModuleIdentifierFeaturesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderModuleIdentifierPropertiesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT;
constexpr auto StructureTypePipelineShaderStageModuleIdentifierCreateInfoEXT             = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT;
constexpr auto StructureTypeShaderModuleIdentifierEXT                                    = VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT;
constexpr auto StructureTypePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceOpticalFlowFeaturesNV                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceOpticalFlowPropertiesNV                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV;
constexpr auto StructureTypeOpticalFlowImageFormatInfoNV                                 = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV;
constexpr auto StructureTypeOpticalFlowImageFormatPropertiesNV                           = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV;
constexpr auto StructureTypeOpticalFlowSessionCreateInfoNV                               = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV;
constexpr auto StructureTypeOpticalFlowExecuteInfoNV                                     = VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV;
constexpr auto StructureTypeOpticalFlowSessionCreatePrivateDataInfoNV                    = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV;
constexpr auto StructureTypePhysicalDeviceLegacyDitheringFeaturesEXT                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
constexpr auto StructureTypePhysicalDeviceExternalFormatResolveFeaturesANDROID           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID;
constexpr auto StructureTypePhysicalDeviceExternalFormatResolvePropertiesANDROID         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID;
constexpr auto StructureTypeAndroidHardwareBufferFormatResolvePropertiesANDROID          = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
constexpr auto StructureTypePhysicalDeviceAntiLagFeaturesAMD                             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD;
constexpr auto StructureTypeAntiLagDataAMD                                               = VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD;
constexpr auto StructureTypeAntiLagPresentationInfoAMD                                   = VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceDenseGeometryFormatFeaturesAMDX                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX;
constexpr auto StructureTypeAccelerationStructureDenseGeometryFormatTrianglesDataAMDX    = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DENSE_GEOMETRY_FORMAT_TRIANGLES_DATA_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypeSurfaceCapabilitiesPresentId2KHR                             = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR;
constexpr auto StructureTypePresentId2KHR                                                = VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR;
constexpr auto StructureTypePhysicalDevicePresentId2FeaturesKHR                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR;
constexpr auto StructureTypeSurfaceCapabilitiesPresentWait2KHR                           = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR;
constexpr auto StructureTypePhysicalDevicePresentWait2FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR;
constexpr auto StructureTypePresentWait2InfoKHR                                          = VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceRayTracingPositionFetchFeaturesKHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderObjectFeaturesEXT                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderObjectPropertiesEXT                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT;
constexpr auto StructureTypeShaderCreateInfoEXT                                          = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDevicePipelineBinaryFeaturesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR;
constexpr auto StructureTypePipelineBinaryCreateInfoKHR                                  = VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR;
constexpr auto StructureTypePipelineBinaryInfoKHR                                        = VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR;
constexpr auto StructureTypePipelineBinaryKeyKHR                                         = VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR;
constexpr auto StructureTypePhysicalDevicePipelineBinaryPropertiesKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR;
constexpr auto StructureTypeReleaseCapturedPipelineDataInfoKHR                           = VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR;
constexpr auto StructureTypePipelineBinaryDataInfoKHR                                    = VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR;
constexpr auto StructureTypePipelineCreateInfoKHR                                        = VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR;
constexpr auto StructureTypeDevicePipelineBinaryInternalCacheControlKHR                  = VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR;
constexpr auto StructureTypePipelineBinaryHandlesInfoKHR                                 = VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceTilePropertiesFeaturesQCOM                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM;
constexpr auto StructureTypeTilePropertiesQCOM                                           = VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM;
constexpr auto StructureTypePhysicalDeviceAmigoProfilingFeaturesSEC                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC;
constexpr auto StructureTypeAmigoProfilingSubmitInfoSEC                                  = VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC;
constexpr auto StructureTypeSurfacePresentModeKHR                                        = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR;
constexpr auto StructureTypeSurfacePresentModeEXT                                        = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT;
constexpr auto StructureTypeSurfacePresentScalingCapabilitiesKHR                         = VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR;
constexpr auto StructureTypeSurfacePresentScalingCapabilitiesEXT                         = VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT;
constexpr auto StructureTypeSurfacePresentModeCompatibilityKHR                           = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR;
constexpr auto StructureTypeSurfacePresentModeCompatibilityEXT                           = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT;
constexpr auto StructureTypePhysicalDeviceSwapchainMaintenance1FeaturesKHR               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceSwapchainMaintenance1FeaturesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT;
constexpr auto StructureTypeSwapchainPresentFenceInfoKHR                                 = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR;
constexpr auto StructureTypeSwapchainPresentFenceInfoEXT                                 = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT;
constexpr auto StructureTypeSwapchainPresentModesCreateInfoKHR                           = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR;
constexpr auto StructureTypeSwapchainPresentModesCreateInfoEXT                           = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT;
constexpr auto StructureTypeSwapchainPresentModeInfoKHR                                  = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR;
constexpr auto StructureTypeSwapchainPresentModeInfoEXT                                  = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT;
constexpr auto StructureTypeSwapchainPresentScalingCreateInfoKHR                         = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR;
constexpr auto StructureTypeSwapchainPresentScalingCreateInfoEXT                         = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT;
constexpr auto StructureTypeReleaseSwapchainImagesInfoKHR                                = VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR;
constexpr auto StructureTypeReleaseSwapchainImagesInfoEXT                                = VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceRayTracingInvocationReorderFeaturesNV          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceRayTracingInvocationReorderPropertiesNV        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceCooperativeVectorFeaturesNV                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceCooperativeVectorPropertiesNV                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV;
constexpr auto StructureTypeCooperativeVectorPropertiesNV                                = VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV;
constexpr auto StructureTypeConvertCooperativeVectorMatrixInfoNV                         = VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV;
constexpr auto StructureTypePhysicalDeviceExtendedSparseAddressSpaceFeaturesNV           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceExtendedSparseAddressSpacePropertiesNV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceMutableDescriptorTypeFeaturesEXT               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceMutableDescriptorTypeFeaturesVALVE             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE;
constexpr auto StructureTypeMutableDescriptorTypeCreateInfoEXT                           = VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT;
constexpr auto StructureTypeMutableDescriptorTypeCreateInfoVALVE                         = VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE;
constexpr auto StructureTypePhysicalDeviceLegacyVertexAttributesFeaturesEXT              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceLegacyVertexAttributesPropertiesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT;
constexpr auto StructureTypeLayerSettingsCreateInfoEXT                                   = VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceShaderCoreBuiltinsFeaturesARM                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceShaderCoreBuiltinsPropertiesARM                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM;
constexpr auto StructureTypePhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT;
constexpr auto StructureTypeLatencySleepModeInfoNV                                       = VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV;
constexpr auto StructureTypeLatencySleepInfoNV                                           = VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV;
constexpr auto StructureTypeSetLatencyMarkerInfoNV                                       = VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV;
constexpr auto StructureTypeGetLatencyMarkerInfoNV                                       = VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV;
constexpr auto StructureTypeLatencyTimingsFrameReportNV                                  = VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV;
constexpr auto StructureTypeLatencySubmissionPresentIdNV                                 = VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV;
constexpr auto StructureTypeOutOfBandQueueTypeInfoNV                                     = VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV;
constexpr auto StructureTypeSwapchainLatencyCreateInfoNV                                 = VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV;
constexpr auto StructureTypeLatencySurfaceCapabilitiesNV                                 = VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrixFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR;
constexpr auto StructureTypeCooperativeMatrixPropertiesKHR                               = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrixPropertiesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR;
constexpr auto StructureTypeDataGraphPipelineCreateInfoARM                               = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineSessionCreateInfoARM                        = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineResourceInfoARM                             = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineConstantARM                                 = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM;
constexpr auto StructureTypeDataGraphPipelineSessionMemoryRequirementsInfoARM            = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM;
constexpr auto StructureTypeBindDataGraphPipelineSessionMemoryInfoARM                    = VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM;
constexpr auto StructureTypePhysicalDeviceDataGraphFeaturesARM                           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM;
constexpr auto StructureTypeDataGraphPipelineShaderModuleCreateInfoARM                   = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelinePropertyQueryResultARM                      = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM;
constexpr auto StructureTypeDataGraphPipelineInfoARM                                     = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineCompilerControlCreateInfoARM                = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineSessionBindPointRequirementsInfoARM         = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineSessionBindPointRequirementARM              = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM;
constexpr auto StructureTypeDataGraphPipelineIdentifierCreateInfoARM                     = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineDispatchInfoARM                             = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM;
constexpr auto StructureTypeDataGraphProcessingEngineCreateInfoARM                       = VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM;
constexpr auto StructureTypeQueueFamilyDataGraphProcessingEnginePropertiesARM            = VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM;
constexpr auto StructureTypeQueueFamilyDataGraphPropertiesARM                            = VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM;
constexpr auto StructureTypePhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM;
constexpr auto StructureTypeDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM = VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM;
constexpr auto StructureTypePhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM;
constexpr auto StructureTypeMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM           = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceComputeShaderDerivativesFeaturesKHR            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceComputeShaderDerivativesFeaturesNV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceComputeShaderDerivativesPropertiesKHR          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR;
constexpr auto StructureTypeVideoDecodeAv1CapabilitiesKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoDecodeAv1PictureInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeAv1ProfileInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeAv1SessionParametersCreateInfoKHR                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeAv1DpbSlotInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1CapabilitiesKHR                                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeAv1SessionParametersCreateInfoKHR                 = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1PictureInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1DpbSlotInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoEncodeAv1FeaturesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR;
constexpr auto StructureTypeVideoEncodeAv1ProfileInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1RateControlInfoKHR                             = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1RateControlLayerInfoKHR                        = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1QualityLevelPropertiesKHR                      = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeAv1SessionCreateInfoKHR                           = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeAv1GopRemainingFrameInfoKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoDecodeVp9FeaturesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR;
constexpr auto StructureTypeVideoDecodeVp9CapabilitiesKHR                                = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoDecodeVp9PictureInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR;
constexpr auto StructureTypeVideoDecodeVp9ProfileInfoKHR                                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoMaintenance1FeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR;
constexpr auto StructureTypeVideoInlineQueryInfoKHR                                      = VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR;
constexpr auto StructureTypePhysicalDevicePerStageDescriptorSetFeaturesNV                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceImageProcessing2FeaturesQCOM                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceImageProcessing2PropertiesQCOM                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM;
constexpr auto StructureTypeSamplerBlockMatchWindowCreateInfoQCOM                        = VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM;
constexpr auto StructureTypeSamplerCubicWeightsCreateInfoQCOM                            = VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceCubicWeightsFeaturesQCOM                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM;
constexpr auto StructureTypeBlitImageCubicWeightsInfoQCOM                                = VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceYcbcrDegammaFeaturesQCOM                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM;
constexpr auto StructureTypeSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM             = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceCubicClampFeaturesQCOM                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceUnifiedImageLayoutsFeaturesKHR                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR;
constexpr auto StructureTypeAttachmentFeedbackLoopInfoEXT                                = VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
constexpr auto StructureTypeScreenBufferPropertiesQNX                                    = VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX;
constexpr auto StructureTypeScreenBufferFormatPropertiesQNX                              = VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX;
constexpr auto StructureTypeImportScreenBufferInfoQNX                                    = VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX;
constexpr auto StructureTypeExternalFormatQNX                                            = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX;
constexpr auto StructureTypePhysicalDeviceExternalMemoryScreenBufferFeaturesQNX          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX;
#endif  // VK_USE_PLATFORM_SCREEN_QNX
constexpr auto StructureTypePhysicalDeviceLayeredDriverPropertiesMSFT                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT;
constexpr auto StructureTypeCalibratedTimestampInfoKHR                                   = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR;
constexpr auto StructureTypeCalibratedTimestampInfoEXT                                   = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT;
constexpr auto StructureTypeSetDescriptorBufferOffsetsInfoEXT                            = VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT;
constexpr auto StructureTypeBindDescriptorBufferEmbeddedSamplersInfoEXT                  = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceDescriptorPoolOverallocationFeaturesNV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceTileMemoryHeapFeaturesQCOM                     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceTileMemoryHeapPropertiesQCOM                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM;
constexpr auto StructureTypeTileMemoryRequirementsQCOM                                   = VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM;
constexpr auto StructureTypeTileMemoryBindInfoQCOM                                       = VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM;
constexpr auto StructureTypeTileMemorySizeInfoQCOM                                       = VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM;
constexpr auto StructureTypePhysicalDeviceCopyMemoryIndirectFeaturesKHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceCopyMemoryIndirectPropertiesKHR                = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceCopyMemoryIndirectPropertiesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV;
constexpr auto StructureTypeCopyMemoryIndirectInfoKHR                                    = VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR;
constexpr auto StructureTypeCopyMemoryToImageIndirectInfoKHR                             = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR;
constexpr auto StructureTypeDisplaySurfaceStereoCreateInfoNV                             = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV;
constexpr auto StructureTypeDisplayModeStereoPropertiesNV                                = VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV;
constexpr auto StructureTypeVideoEncodeIntraRefreshCapabilitiesKHR                       = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeSessionIntraRefreshCreateInfoKHR                  = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR;
constexpr auto StructureTypeVideoEncodeIntraRefreshInfoKHR                               = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR;
constexpr auto StructureTypeVideoReferenceIntraRefreshInfoKHR                            = VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR;
constexpr auto StructureTypeVideoEncodeQuantizationMapCapabilitiesKHR                    = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoFormatQuantizationMapPropertiesKHR                      = VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeQuantizationMapInfoKHR                            = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR;
constexpr auto StructureTypeVideoEncodeQuantizationMapSessionParametersCreateInfoKHR     = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR;
constexpr auto StructureTypePhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR;
constexpr auto StructureTypeVideoEncodeH264QuantizationMapCapabilitiesKHR                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoEncodeH265QuantizationMapCapabilitiesKHR                = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoFormatH265QuantizationMapPropertiesKHR                  = VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR;
constexpr auto StructureTypeVideoEncodeAv1QuantizationMapCapabilitiesKHR                 = VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR;
constexpr auto StructureTypeVideoFormatAv1QuantizationMapPropertiesKHR                   = VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceRawAccessChainsFeaturesNV                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV;
constexpr auto StructureTypeExternalComputeQueueDeviceCreateInfoNV                       = VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DEVICE_CREATE_INFO_NV;
constexpr auto StructureTypeExternalComputeQueueCreateInfoNV                             = VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_CREATE_INFO_NV;
constexpr auto StructureTypeExternalComputeQueueDataParamsNV                             = VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DATA_PARAMS_NV;
constexpr auto StructureTypePhysicalDeviceExternalComputeQueuePropertiesNV               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_COMPUTE_QUEUE_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceCommandBufferInheritanceFeaturesNV             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceMaintenance7FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance7PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceLayeredApiPropertiesListKHR                    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR;
constexpr auto StructureTypePhysicalDeviceLayeredApiPropertiesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceLayeredApiVulkanPropertiesKHR                  = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceShaderAtomicFloat16VectorFeaturesNV            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceShaderReplicatedCompositesFeaturesEXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceShaderFloat8FeaturesEXT                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceRayTracingValidationFeaturesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceClusterAccelerationStructureFeaturesNV         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV;
constexpr auto StructureTypePhysicalDeviceClusterAccelerationStructurePropertiesNV       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV;
constexpr auto StructureTypeClusterAccelerationStructureClustersBottomLevelInputNV       = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV;
constexpr auto StructureTypeClusterAccelerationStructureTriangleClusterInputNV           = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV;
constexpr auto StructureTypeClusterAccelerationStructureMoveObjectsInputNV               = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV;
constexpr auto StructureTypeClusterAccelerationStructureInputInfoNV                      = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV;
constexpr auto StructureTypeClusterAccelerationStructureCommandsInfoNV                   = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV;
constexpr auto StructureTypeRayTracingPipelineClusterAccelerationStructureCreateInfoNV   = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV;
constexpr auto StructureTypePhysicalDevicePartitionedAccelerationStructureFeaturesNV     = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV;
constexpr auto StructureTypePhysicalDevicePartitionedAccelerationStructurePropertiesNV   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV;
constexpr auto StructureTypeWriteDescriptorSetPartitionedAccelerationStructureNV         = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV;
constexpr auto StructureTypePartitionedAccelerationStructureInstancesInputNV             = VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV;
constexpr auto StructureTypeBuildPartitionedAccelerationStructureInfoNV                  = VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV;
constexpr auto StructureTypePartitionedAccelerationStructureFlagsNV                      = VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV;
constexpr auto StructureTypePhysicalDeviceDeviceGeneratedCommandsFeaturesEXT             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceDeviceGeneratedCommandsPropertiesEXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT;
constexpr auto StructureTypeGeneratedCommandsMemoryRequirementsInfoEXT                   = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT;
constexpr auto StructureTypeIndirectExecutionSetCreateInfoEXT                            = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT;
constexpr auto StructureTypeGeneratedCommandsInfoEXT                                     = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT;
constexpr auto StructureTypeIndirectCommandsLayoutCreateInfoEXT                          = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT;
constexpr auto StructureTypeIndirectCommandsLayoutTokenEXT                               = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT;
constexpr auto StructureTypeWriteIndirectExecutionSetPipelineEXT                         = VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT;
constexpr auto StructureTypeWriteIndirectExecutionSetShaderEXT                           = VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT;
constexpr auto StructureTypeIndirectExecutionSetPipelineInfoEXT                          = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT;
constexpr auto StructureTypeIndirectExecutionSetShaderInfoEXT                            = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT;
constexpr auto StructureTypeIndirectExecutionSetShaderLayoutInfoEXT                      = VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT;
constexpr auto StructureTypeGeneratedCommandsPipelineInfoEXT                             = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT;
constexpr auto StructureTypeGeneratedCommandsShaderInfoEXT                               = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceMaintenance8FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR;
constexpr auto StructureTypeMemoryBarrierAccessFlags3KHR                                 = VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR;
constexpr auto StructureTypePhysicalDeviceImageAlignmentControlFeaturesMESA              = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA;
constexpr auto StructureTypePhysicalDeviceImageAlignmentControlPropertiesMESA            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA;
constexpr auto StructureTypeImageAlignmentControlCreateInfoMESA                          = VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA;
constexpr auto StructureTypePhysicalDeviceDepthClampControlFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT;
constexpr auto StructureTypePipelineViewportDepthClampControlCreateInfoEXT               = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceMaintenance9FeaturesKHR                        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceMaintenance9PropertiesKHR                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR;
constexpr auto StructureTypeQueueFamilyOwnershipTransferPropertiesKHR                    = VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceVideoMaintenance2FeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR;
constexpr auto StructureTypeVideoDecodeH264InlineSessionParametersInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR;
constexpr auto StructureTypeVideoDecodeH265InlineSessionParametersInfoKHR                = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR;
constexpr auto StructureTypeVideoDecodeAv1InlineSessionParametersInfoKHR                 = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR;
#ifdef VK_USE_PLATFORM_OHOS
constexpr auto StructureTypeSurfaceCreateInfoOHOS                                        = VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS;
#endif  // VK_USE_PLATFORM_OHOS
constexpr auto StructureTypePhysicalDeviceHdrVividFeaturesHUAWEI                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI;
constexpr auto StructureTypeHdrVividDynamicMetadataHUAWEI                                = VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrix2FeaturesNV                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV;
constexpr auto StructureTypeCooperativeMatrixFlexibleDimensionsPropertiesNV              = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDeviceCooperativeMatrix2PropertiesNV                 = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV;
constexpr auto StructureTypePhysicalDevicePipelineOpacityMicromapFeaturesARM             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM;
#ifdef VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypeImportMemoryMetalHandleInfoEXT                               = VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT;
constexpr auto StructureTypeMemoryMetalHandlePropertiesEXT                               = VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT;
constexpr auto StructureTypeMemoryGetMetalHandleInfoEXT                                  = VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT;
#endif  // VK_USE_PLATFORM_METAL_EXT
constexpr auto StructureTypePhysicalDeviceDepthClampZeroOneFeaturesKHR                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceDepthClampZeroOneFeaturesEXT                   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceVertexAttributeRobustnessFeaturesEXT           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFormatPackFeaturesARM                          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE;
constexpr auto StructureTypePipelineFragmentDensityMapLayeredCreateInfoVALVE             = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE;
constexpr auto StructureTypePhysicalDeviceRobustness2FeaturesKHR                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR;
constexpr auto StructureTypePhysicalDeviceRobustness2FeaturesEXT                         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceRobustness2PropertiesKHR                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR;
constexpr auto StructureTypePhysicalDeviceRobustness2PropertiesEXT                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypeSetPresentConfigNV                                           = VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV;
constexpr auto StructureTypePhysicalDevicePresentMeteringFeaturesNV                      = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapOffsetFeaturesEXT            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM           = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapOffsetPropertiesEXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT;
constexpr auto StructureTypePhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM;
constexpr auto StructureTypeRenderPassFragmentDensityMapOffsetEndInfoEXT                 = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT;
constexpr auto StructureTypeSubpassFragmentDensityMapOffsetEndInfoQCOM                   = VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM;
constexpr auto StructureTypeRenderingEndInfoEXT                                          = VK_STRUCTURE_TYPE_RENDERING_END_INFO_EXT;
constexpr auto StructureTypePhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePresentModeFifoLatestReadyFeaturesKHR          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR;
constexpr auto StructureTypePhysicalDevicePresentModeFifoLatestReadyFeaturesEXT          = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_EXT;
constexpr auto StructureTypePhysicalDevicePipelineCacheIncrementalModeFeaturesSEC        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC;
//};

//enum PipelineCacheHeaderVersion {
constexpr auto PipelineCacheHeaderVersionOne = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
//};

//enum ObjectType {
constexpr auto ObjectTypeUnknown                       = VK_OBJECT_TYPE_UNKNOWN;
constexpr auto ObjectTypeInstance                      = VK_OBJECT_TYPE_INSTANCE;
constexpr auto ObjectTypePhysicalDevice                = VK_OBJECT_TYPE_PHYSICAL_DEVICE;
constexpr auto ObjectTypeDevice                        = VK_OBJECT_TYPE_DEVICE;
constexpr auto ObjectTypeQueue                         = VK_OBJECT_TYPE_QUEUE;
constexpr auto ObjectTypeSemaphore                     = VK_OBJECT_TYPE_SEMAPHORE;
constexpr auto ObjectTypeCommandBuffer                 = VK_OBJECT_TYPE_COMMAND_BUFFER;
constexpr auto ObjectTypeFence                         = VK_OBJECT_TYPE_FENCE;
constexpr auto ObjectTypeDeviceMemory                  = VK_OBJECT_TYPE_DEVICE_MEMORY;
constexpr auto ObjectTypeBuffer                        = VK_OBJECT_TYPE_BUFFER;
constexpr auto ObjectTypeImage                         = VK_OBJECT_TYPE_IMAGE;
constexpr auto ObjectTypeEvent                         = VK_OBJECT_TYPE_EVENT;
constexpr auto ObjectTypeQueryPool                     = VK_OBJECT_TYPE_QUERY_POOL;
constexpr auto ObjectTypeBufferView                    = VK_OBJECT_TYPE_BUFFER_VIEW;
constexpr auto ObjectTypeImageView                     = VK_OBJECT_TYPE_IMAGE_VIEW;
constexpr auto ObjectTypeShaderModule                  = VK_OBJECT_TYPE_SHADER_MODULE;
constexpr auto ObjectTypePipelineCache                 = VK_OBJECT_TYPE_PIPELINE_CACHE;
constexpr auto ObjectTypePipelineLayout                = VK_OBJECT_TYPE_PIPELINE_LAYOUT;
constexpr auto ObjectTypeRenderPass                    = VK_OBJECT_TYPE_RENDER_PASS;
constexpr auto ObjectTypePipeline                      = VK_OBJECT_TYPE_PIPELINE;
constexpr auto ObjectTypeDescriptorSetLayout           = VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT;
constexpr auto ObjectTypeSampler                       = VK_OBJECT_TYPE_SAMPLER;
constexpr auto ObjectTypeDescriptorPool                = VK_OBJECT_TYPE_DESCRIPTOR_POOL;
constexpr auto ObjectTypeDescriptorSet                 = VK_OBJECT_TYPE_DESCRIPTOR_SET;
constexpr auto ObjectTypeFramebuffer                   = VK_OBJECT_TYPE_FRAMEBUFFER;
constexpr auto ObjectTypeCommandPool                   = VK_OBJECT_TYPE_COMMAND_POOL;
constexpr auto ObjectTypeSamplerYcbcrConversion        = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION;
constexpr auto ObjectTypeSamplerYcbcrConversionKHR     = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR;
constexpr auto ObjectTypeDescriptorUpdateTemplate      = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE;
constexpr auto ObjectTypeDescriptorUpdateTemplateKHR   = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR;
constexpr auto ObjectTypePrivateDataSlot               = VK_OBJECT_TYPE_PRIVATE_DATA_SLOT;
constexpr auto ObjectTypePrivateDataSlotEXT            = VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT;
constexpr auto ObjectTypeSurfaceKHR                    = VK_OBJECT_TYPE_SURFACE_KHR;
constexpr auto ObjectTypeSwapchainKHR                  = VK_OBJECT_TYPE_SWAPCHAIN_KHR;
constexpr auto ObjectTypeDisplayKHR                    = VK_OBJECT_TYPE_DISPLAY_KHR;
constexpr auto ObjectTypeDisplayModeKHR                = VK_OBJECT_TYPE_DISPLAY_MODE_KHR;
constexpr auto ObjectTypeDebugReportCallbackEXT        = VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT;
constexpr auto ObjectTypeVideoSessionKHR               = VK_OBJECT_TYPE_VIDEO_SESSION_KHR;
constexpr auto ObjectTypeVideoSessionParametersKHR     = VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR;
constexpr auto ObjectTypeCuModuleNVX                   = VK_OBJECT_TYPE_CU_MODULE_NVX;
constexpr auto ObjectTypeCuFunctionNVX                 = VK_OBJECT_TYPE_CU_FUNCTION_NVX;
constexpr auto ObjectTypeDebugUtilsMessengerEXT        = VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT;
constexpr auto ObjectTypeAccelerationStructureKHR      = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR;
constexpr auto ObjectTypeValidationCacheEXT            = VK_OBJECT_TYPE_VALIDATION_CACHE_EXT;
constexpr auto ObjectTypeAccelerationStructureNV       = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV;
constexpr auto ObjectTypePerformanceConfigurationINTEL = VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL;
constexpr auto ObjectTypeDeferredOperationKHR          = VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR;
constexpr auto ObjectTypeIndirectCommandsLayoutNV      = VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto ObjectTypeCudaModuleNV   = VK_OBJECT_TYPE_CUDA_MODULE_NV;
constexpr auto ObjectTypeCudaFunctionNV = VK_OBJECT_TYPE_CUDA_FUNCTION_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto ObjectTypeBufferCollectionFUCHSIA = VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
constexpr auto ObjectTypeMicromapEXT                 = VK_OBJECT_TYPE_MICROMAP_EXT;
constexpr auto ObjectTypeTensorARM                   = VK_OBJECT_TYPE_TENSOR_ARM;
constexpr auto ObjectTypeTensorViewARM               = VK_OBJECT_TYPE_TENSOR_VIEW_ARM;
constexpr auto ObjectTypeOpticalFlowSessionNV        = VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV;
constexpr auto ObjectTypeShaderEXT                   = VK_OBJECT_TYPE_SHADER_EXT;
constexpr auto ObjectTypePipelineBinaryKHR           = VK_OBJECT_TYPE_PIPELINE_BINARY_KHR;
constexpr auto ObjectTypeDataGraphPipelineSessionARM = VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM;
constexpr auto ObjectTypeExternalComputeQueueNV      = VK_OBJECT_TYPE_EXTERNAL_COMPUTE_QUEUE_NV;
constexpr auto ObjectTypeIndirectCommandsLayoutEXT   = VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT;
constexpr auto ObjectTypeIndirectExecutionSetEXT     = VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT;
//};

//enum VendorId {
constexpr auto VendorIdKhronos  = VK_VENDOR_ID_KHRONOS;
constexpr auto VendorIdVIV      = VK_VENDOR_ID_VIV;
constexpr auto VendorIdVSI      = VK_VENDOR_ID_VSI;
constexpr auto VendorIdKazan    = VK_VENDOR_ID_KAZAN;
constexpr auto VendorIdCodeplay = VK_VENDOR_ID_CODEPLAY;
constexpr auto VendorIdMESA     = VK_VENDOR_ID_MESA;
constexpr auto VendorIdPocl     = VK_VENDOR_ID_POCL;
constexpr auto VendorIdMobileye = VK_VENDOR_ID_MOBILEYE;
//};

//enum Format {
constexpr auto FormatUndefined                               = VK_FORMAT_UNDEFINED;
constexpr auto FormatR4G4UnormPack8                          = VK_FORMAT_R4G4_UNORM_PACK8;
constexpr auto FormatR4G4B4A4UnormPack16                     = VK_FORMAT_R4G4B4A4_UNORM_PACK16;
constexpr auto FormatB4G4R4A4UnormPack16                     = VK_FORMAT_B4G4R4A4_UNORM_PACK16;
constexpr auto FormatR5G6B5UnormPack16                       = VK_FORMAT_R5G6B5_UNORM_PACK16;
constexpr auto FormatB5G6R5UnormPack16                       = VK_FORMAT_B5G6R5_UNORM_PACK16;
constexpr auto FormatR5G5B5A1UnormPack16                     = VK_FORMAT_R5G5B5A1_UNORM_PACK16;
constexpr auto FormatB5G5R5A1UnormPack16                     = VK_FORMAT_B5G5R5A1_UNORM_PACK16;
constexpr auto FormatA1R5G5B5UnormPack16                     = VK_FORMAT_A1R5G5B5_UNORM_PACK16;
constexpr auto FormatR8Unorm                                 = VK_FORMAT_R8_UNORM;
constexpr auto FormatR8Snorm                                 = VK_FORMAT_R8_SNORM;
constexpr auto FormatR8Uscaled                               = VK_FORMAT_R8_USCALED;
constexpr auto FormatR8Sscaled                               = VK_FORMAT_R8_SSCALED;
constexpr auto FormatR8Uint                                  = VK_FORMAT_R8_UINT;
constexpr auto FormatR8Sint                                  = VK_FORMAT_R8_SINT;
constexpr auto FormatR8Srgb                                  = VK_FORMAT_R8_SRGB;
constexpr auto FormatR8G8Unorm                               = VK_FORMAT_R8G8_UNORM;
constexpr auto FormatR8G8Snorm                               = VK_FORMAT_R8G8_SNORM;
constexpr auto FormatR8G8Uscaled                             = VK_FORMAT_R8G8_USCALED;
constexpr auto FormatR8G8Sscaled                             = VK_FORMAT_R8G8_SSCALED;
constexpr auto FormatR8G8Uint                                = VK_FORMAT_R8G8_UINT;
constexpr auto FormatR8G8Sint                                = VK_FORMAT_R8G8_SINT;
constexpr auto FormatR8G8Srgb                                = VK_FORMAT_R8G8_SRGB;
constexpr auto FormatR8G8B8Unorm                             = VK_FORMAT_R8G8B8_UNORM;
constexpr auto FormatR8G8B8Snorm                             = VK_FORMAT_R8G8B8_SNORM;
constexpr auto FormatR8G8B8Uscaled                           = VK_FORMAT_R8G8B8_USCALED;
constexpr auto FormatR8G8B8Sscaled                           = VK_FORMAT_R8G8B8_SSCALED;
constexpr auto FormatR8G8B8Uint                              = VK_FORMAT_R8G8B8_UINT;
constexpr auto FormatR8G8B8Sint                              = VK_FORMAT_R8G8B8_SINT;
constexpr auto FormatR8G8B8Srgb                              = VK_FORMAT_R8G8B8_SRGB;
constexpr auto FormatB8G8R8Unorm                             = VK_FORMAT_B8G8R8_UNORM;
constexpr auto FormatB8G8R8Snorm                             = VK_FORMAT_B8G8R8_SNORM;
constexpr auto FormatB8G8R8Uscaled                           = VK_FORMAT_B8G8R8_USCALED;
constexpr auto FormatB8G8R8Sscaled                           = VK_FORMAT_B8G8R8_SSCALED;
constexpr auto FormatB8G8R8Uint                              = VK_FORMAT_B8G8R8_UINT;
constexpr auto FormatB8G8R8Sint                              = VK_FORMAT_B8G8R8_SINT;
constexpr auto FormatB8G8R8Srgb                              = VK_FORMAT_B8G8R8_SRGB;
constexpr auto FormatR8G8B8A8Unorm                           = VK_FORMAT_R8G8B8A8_UNORM;
constexpr auto FormatR8G8B8A8Snorm                           = VK_FORMAT_R8G8B8A8_SNORM;
constexpr auto FormatR8G8B8A8Uscaled                         = VK_FORMAT_R8G8B8A8_USCALED;
constexpr auto FormatR8G8B8A8Sscaled                         = VK_FORMAT_R8G8B8A8_SSCALED;
constexpr auto FormatR8G8B8A8Uint                            = VK_FORMAT_R8G8B8A8_UINT;
constexpr auto FormatR8G8B8A8Sint                            = VK_FORMAT_R8G8B8A8_SINT;
constexpr auto FormatR8G8B8A8Srgb                            = VK_FORMAT_R8G8B8A8_SRGB;
constexpr auto FormatB8G8R8A8Unorm                           = VK_FORMAT_B8G8R8A8_UNORM;
constexpr auto FormatB8G8R8A8Snorm                           = VK_FORMAT_B8G8R8A8_SNORM;
constexpr auto FormatB8G8R8A8Uscaled                         = VK_FORMAT_B8G8R8A8_USCALED;
constexpr auto FormatB8G8R8A8Sscaled                         = VK_FORMAT_B8G8R8A8_SSCALED;
constexpr auto FormatB8G8R8A8Uint                            = VK_FORMAT_B8G8R8A8_UINT;
constexpr auto FormatB8G8R8A8Sint                            = VK_FORMAT_B8G8R8A8_SINT;
constexpr auto FormatB8G8R8A8Srgb                            = VK_FORMAT_B8G8R8A8_SRGB;
constexpr auto FormatA8B8G8R8UnormPack32                     = VK_FORMAT_A8B8G8R8_UNORM_PACK32;
constexpr auto FormatA8B8G8R8SnormPack32                     = VK_FORMAT_A8B8G8R8_SNORM_PACK32;
constexpr auto FormatA8B8G8R8UscaledPack32                   = VK_FORMAT_A8B8G8R8_USCALED_PACK32;
constexpr auto FormatA8B8G8R8SscaledPack32                   = VK_FORMAT_A8B8G8R8_SSCALED_PACK32;
constexpr auto FormatA8B8G8R8UintPack32                      = VK_FORMAT_A8B8G8R8_UINT_PACK32;
constexpr auto FormatA8B8G8R8SintPack32                      = VK_FORMAT_A8B8G8R8_SINT_PACK32;
constexpr auto FormatA8B8G8R8SrgbPack32                      = VK_FORMAT_A8B8G8R8_SRGB_PACK32;
constexpr auto FormatA2R10G10B10UnormPack32                  = VK_FORMAT_A2R10G10B10_UNORM_PACK32;
constexpr auto FormatA2R10G10B10SnormPack32                  = VK_FORMAT_A2R10G10B10_SNORM_PACK32;
constexpr auto FormatA2R10G10B10UscaledPack32                = VK_FORMAT_A2R10G10B10_USCALED_PACK32;
constexpr auto FormatA2R10G10B10SscaledPack32                = VK_FORMAT_A2R10G10B10_SSCALED_PACK32;
constexpr auto FormatA2R10G10B10UintPack32                   = VK_FORMAT_A2R10G10B10_UINT_PACK32;
constexpr auto FormatA2R10G10B10SintPack32                   = VK_FORMAT_A2R10G10B10_SINT_PACK32;
constexpr auto FormatA2B10G10R10UnormPack32                  = VK_FORMAT_A2B10G10R10_UNORM_PACK32;
constexpr auto FormatA2B10G10R10SnormPack32                  = VK_FORMAT_A2B10G10R10_SNORM_PACK32;
constexpr auto FormatA2B10G10R10UscaledPack32                = VK_FORMAT_A2B10G10R10_USCALED_PACK32;
constexpr auto FormatA2B10G10R10SscaledPack32                = VK_FORMAT_A2B10G10R10_SSCALED_PACK32;
constexpr auto FormatA2B10G10R10UintPack32                   = VK_FORMAT_A2B10G10R10_UINT_PACK32;
constexpr auto FormatA2B10G10R10SintPack32                   = VK_FORMAT_A2B10G10R10_SINT_PACK32;
constexpr auto FormatR16Unorm                                = VK_FORMAT_R16_UNORM;
constexpr auto FormatR16Snorm                                = VK_FORMAT_R16_SNORM;
constexpr auto FormatR16Uscaled                              = VK_FORMAT_R16_USCALED;
constexpr auto FormatR16Sscaled                              = VK_FORMAT_R16_SSCALED;
constexpr auto FormatR16Uint                                 = VK_FORMAT_R16_UINT;
constexpr auto FormatR16Sint                                 = VK_FORMAT_R16_SINT;
constexpr auto FormatR16Sfloat                               = VK_FORMAT_R16_SFLOAT;
constexpr auto FormatR16G16Unorm                             = VK_FORMAT_R16G16_UNORM;
constexpr auto FormatR16G16Snorm                             = VK_FORMAT_R16G16_SNORM;
constexpr auto FormatR16G16Uscaled                           = VK_FORMAT_R16G16_USCALED;
constexpr auto FormatR16G16Sscaled                           = VK_FORMAT_R16G16_SSCALED;
constexpr auto FormatR16G16Uint                              = VK_FORMAT_R16G16_UINT;
constexpr auto FormatR16G16Sint                              = VK_FORMAT_R16G16_SINT;
constexpr auto FormatR16G16Sfloat                            = VK_FORMAT_R16G16_SFLOAT;
constexpr auto FormatR16G16B16Unorm                          = VK_FORMAT_R16G16B16_UNORM;
constexpr auto FormatR16G16B16Snorm                          = VK_FORMAT_R16G16B16_SNORM;
constexpr auto FormatR16G16B16Uscaled                        = VK_FORMAT_R16G16B16_USCALED;
constexpr auto FormatR16G16B16Sscaled                        = VK_FORMAT_R16G16B16_SSCALED;
constexpr auto FormatR16G16B16Uint                           = VK_FORMAT_R16G16B16_UINT;
constexpr auto FormatR16G16B16Sint                           = VK_FORMAT_R16G16B16_SINT;
constexpr auto FormatR16G16B16Sfloat                         = VK_FORMAT_R16G16B16_SFLOAT;
constexpr auto FormatR16G16B16A16Unorm                       = VK_FORMAT_R16G16B16A16_UNORM;
constexpr auto FormatR16G16B16A16Snorm                       = VK_FORMAT_R16G16B16A16_SNORM;
constexpr auto FormatR16G16B16A16Uscaled                     = VK_FORMAT_R16G16B16A16_USCALED;
constexpr auto FormatR16G16B16A16Sscaled                     = VK_FORMAT_R16G16B16A16_SSCALED;
constexpr auto FormatR16G16B16A16Uint                        = VK_FORMAT_R16G16B16A16_UINT;
constexpr auto FormatR16G16B16A16Sint                        = VK_FORMAT_R16G16B16A16_SINT;
constexpr auto FormatR16G16B16A16Sfloat                      = VK_FORMAT_R16G16B16A16_SFLOAT;
constexpr auto FormatR32Uint                                 = VK_FORMAT_R32_UINT;
constexpr auto FormatR32Sint                                 = VK_FORMAT_R32_SINT;
constexpr auto FormatR32Sfloat                               = VK_FORMAT_R32_SFLOAT;
constexpr auto FormatR32G32Uint                              = VK_FORMAT_R32G32_UINT;
constexpr auto FormatR32G32Sint                              = VK_FORMAT_R32G32_SINT;
constexpr auto FormatR32G32Sfloat                            = VK_FORMAT_R32G32_SFLOAT;
constexpr auto FormatR32G32B32Uint                           = VK_FORMAT_R32G32B32_UINT;
constexpr auto FormatR32G32B32Sint                           = VK_FORMAT_R32G32B32_SINT;
constexpr auto FormatR32G32B32Sfloat                         = VK_FORMAT_R32G32B32_SFLOAT;
constexpr auto FormatR32G32B32A32Uint                        = VK_FORMAT_R32G32B32A32_UINT;
constexpr auto FormatR32G32B32A32Sint                        = VK_FORMAT_R32G32B32A32_SINT;
constexpr auto FormatR32G32B32A32Sfloat                      = VK_FORMAT_R32G32B32A32_SFLOAT;
constexpr auto FormatR64Uint                                 = VK_FORMAT_R64_UINT;
constexpr auto FormatR64Sint                                 = VK_FORMAT_R64_SINT;
constexpr auto FormatR64Sfloat                               = VK_FORMAT_R64_SFLOAT;
constexpr auto FormatR64G64Uint                              = VK_FORMAT_R64G64_UINT;
constexpr auto FormatR64G64Sint                              = VK_FORMAT_R64G64_SINT;
constexpr auto FormatR64G64Sfloat                            = VK_FORMAT_R64G64_SFLOAT;
constexpr auto FormatR64G64B64Uint                           = VK_FORMAT_R64G64B64_UINT;
constexpr auto FormatR64G64B64Sint                           = VK_FORMAT_R64G64B64_SINT;
constexpr auto FormatR64G64B64Sfloat                         = VK_FORMAT_R64G64B64_SFLOAT;
constexpr auto FormatR64G64B64A64Uint                        = VK_FORMAT_R64G64B64A64_UINT;
constexpr auto FormatR64G64B64A64Sint                        = VK_FORMAT_R64G64B64A64_SINT;
constexpr auto FormatR64G64B64A64Sfloat                      = VK_FORMAT_R64G64B64A64_SFLOAT;
constexpr auto FormatB10G11R11UfloatPack32                   = VK_FORMAT_B10G11R11_UFLOAT_PACK32;
constexpr auto FormatE5B9G9R9UfloatPack32                    = VK_FORMAT_E5B9G9R9_UFLOAT_PACK32;
constexpr auto FormatD16Unorm                                = VK_FORMAT_D16_UNORM;
constexpr auto FormatX8D24UnormPack32                        = VK_FORMAT_X8_D24_UNORM_PACK32;
constexpr auto FormatD32Sfloat                               = VK_FORMAT_D32_SFLOAT;
constexpr auto FormatS8Uint                                  = VK_FORMAT_S8_UINT;
constexpr auto FormatD16UnormS8Uint                          = VK_FORMAT_D16_UNORM_S8_UINT;
constexpr auto FormatD24UnormS8Uint                          = VK_FORMAT_D24_UNORM_S8_UINT;
constexpr auto FormatD32SfloatS8Uint                         = VK_FORMAT_D32_SFLOAT_S8_UINT;
constexpr auto FormatBc1RgbUnormBlock                        = VK_FORMAT_BC1_RGB_UNORM_BLOCK;
constexpr auto FormatBc1RgbSrgbBlock                         = VK_FORMAT_BC1_RGB_SRGB_BLOCK;
constexpr auto FormatBc1RgbaUnormBlock                       = VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
constexpr auto FormatBc1RgbaSrgbBlock                        = VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
constexpr auto FormatBc2UnormBlock                           = VK_FORMAT_BC2_UNORM_BLOCK;
constexpr auto FormatBc2SrgbBlock                            = VK_FORMAT_BC2_SRGB_BLOCK;
constexpr auto FormatBc3UnormBlock                           = VK_FORMAT_BC3_UNORM_BLOCK;
constexpr auto FormatBc3SrgbBlock                            = VK_FORMAT_BC3_SRGB_BLOCK;
constexpr auto FormatBc4UnormBlock                           = VK_FORMAT_BC4_UNORM_BLOCK;
constexpr auto FormatBc4SnormBlock                           = VK_FORMAT_BC4_SNORM_BLOCK;
constexpr auto FormatBc5UnormBlock                           = VK_FORMAT_BC5_UNORM_BLOCK;
constexpr auto FormatBc5SnormBlock                           = VK_FORMAT_BC5_SNORM_BLOCK;
constexpr auto FormatBc6HUfloatBlock                         = VK_FORMAT_BC6H_UFLOAT_BLOCK;
constexpr auto FormatBc6HSfloatBlock                         = VK_FORMAT_BC6H_SFLOAT_BLOCK;
constexpr auto FormatBc7UnormBlock                           = VK_FORMAT_BC7_UNORM_BLOCK;
constexpr auto FormatBc7SrgbBlock                            = VK_FORMAT_BC7_SRGB_BLOCK;
constexpr auto FormatEtc2R8G8B8UnormBlock                    = VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK;
constexpr auto FormatEtc2R8G8B8SrgbBlock                     = VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK;
constexpr auto FormatEtc2R8G8B8A1UnormBlock                  = VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK;
constexpr auto FormatEtc2R8G8B8A1SrgbBlock                   = VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK;
constexpr auto FormatEtc2R8G8B8A8UnormBlock                  = VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK;
constexpr auto FormatEtc2R8G8B8A8SrgbBlock                   = VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
constexpr auto FormatEacR11UnormBlock                        = VK_FORMAT_EAC_R11_UNORM_BLOCK;
constexpr auto FormatEacR11SnormBlock                        = VK_FORMAT_EAC_R11_SNORM_BLOCK;
constexpr auto FormatEacR11G11UnormBlock                     = VK_FORMAT_EAC_R11G11_UNORM_BLOCK;
constexpr auto FormatEacR11G11SnormBlock                     = VK_FORMAT_EAC_R11G11_SNORM_BLOCK;
constexpr auto FormatAstc4x4UnormBlock                       = VK_FORMAT_ASTC_4x4_UNORM_BLOCK;
constexpr auto FormatAstc4x4SrgbBlock                        = VK_FORMAT_ASTC_4x4_SRGB_BLOCK;
constexpr auto FormatAstc5x4UnormBlock                       = VK_FORMAT_ASTC_5x4_UNORM_BLOCK;
constexpr auto FormatAstc5x4SrgbBlock                        = VK_FORMAT_ASTC_5x4_SRGB_BLOCK;
constexpr auto FormatAstc5x5UnormBlock                       = VK_FORMAT_ASTC_5x5_UNORM_BLOCK;
constexpr auto FormatAstc5x5SrgbBlock                        = VK_FORMAT_ASTC_5x5_SRGB_BLOCK;
constexpr auto FormatAstc6x5UnormBlock                       = VK_FORMAT_ASTC_6x5_UNORM_BLOCK;
constexpr auto FormatAstc6x5SrgbBlock                        = VK_FORMAT_ASTC_6x5_SRGB_BLOCK;
constexpr auto FormatAstc6x6UnormBlock                       = VK_FORMAT_ASTC_6x6_UNORM_BLOCK;
constexpr auto FormatAstc6x6SrgbBlock                        = VK_FORMAT_ASTC_6x6_SRGB_BLOCK;
constexpr auto FormatAstc8x5UnormBlock                       = VK_FORMAT_ASTC_8x5_UNORM_BLOCK;
constexpr auto FormatAstc8x5SrgbBlock                        = VK_FORMAT_ASTC_8x5_SRGB_BLOCK;
constexpr auto FormatAstc8x6UnormBlock                       = VK_FORMAT_ASTC_8x6_UNORM_BLOCK;
constexpr auto FormatAstc8x6SrgbBlock                        = VK_FORMAT_ASTC_8x6_SRGB_BLOCK;
constexpr auto FormatAstc8x8UnormBlock                       = VK_FORMAT_ASTC_8x8_UNORM_BLOCK;
constexpr auto FormatAstc8x8SrgbBlock                        = VK_FORMAT_ASTC_8x8_SRGB_BLOCK;
constexpr auto FormatAstc10x5UnormBlock                      = VK_FORMAT_ASTC_10x5_UNORM_BLOCK;
constexpr auto FormatAstc10x5SrgbBlock                       = VK_FORMAT_ASTC_10x5_SRGB_BLOCK;
constexpr auto FormatAstc10x6UnormBlock                      = VK_FORMAT_ASTC_10x6_UNORM_BLOCK;
constexpr auto FormatAstc10x6SrgbBlock                       = VK_FORMAT_ASTC_10x6_SRGB_BLOCK;
constexpr auto FormatAstc10x8UnormBlock                      = VK_FORMAT_ASTC_10x8_UNORM_BLOCK;
constexpr auto FormatAstc10x8SrgbBlock                       = VK_FORMAT_ASTC_10x8_SRGB_BLOCK;
constexpr auto FormatAstc10x10UnormBlock                     = VK_FORMAT_ASTC_10x10_UNORM_BLOCK;
constexpr auto FormatAstc10x10SrgbBlock                      = VK_FORMAT_ASTC_10x10_SRGB_BLOCK;
constexpr auto FormatAstc12x10UnormBlock                     = VK_FORMAT_ASTC_12x10_UNORM_BLOCK;
constexpr auto FormatAstc12x10SrgbBlock                      = VK_FORMAT_ASTC_12x10_SRGB_BLOCK;
constexpr auto FormatAstc12x12UnormBlock                     = VK_FORMAT_ASTC_12x12_UNORM_BLOCK;
constexpr auto FormatAstc12x12SrgbBlock                      = VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
constexpr auto FormatG8B8G8R8422Unorm                        = VK_FORMAT_G8B8G8R8_422_UNORM;
constexpr auto FormatG8B8G8R8422UnormKHR                     = VK_FORMAT_G8B8G8R8_422_UNORM_KHR;
constexpr auto FormatB8G8R8G8422Unorm                        = VK_FORMAT_B8G8R8G8_422_UNORM;
constexpr auto FormatB8G8R8G8422UnormKHR                     = VK_FORMAT_B8G8R8G8_422_UNORM_KHR;
constexpr auto FormatG8B8R83Plane420Unorm                    = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM;
constexpr auto FormatG8B8R83Plane420UnormKHR                 = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR;
constexpr auto FormatG8B8R82Plane420Unorm                    = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM;
constexpr auto FormatG8B8R82Plane420UnormKHR                 = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR;
constexpr auto FormatG8B8R83Plane422Unorm                    = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM;
constexpr auto FormatG8B8R83Plane422UnormKHR                 = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR;
constexpr auto FormatG8B8R82Plane422Unorm                    = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM;
constexpr auto FormatG8B8R82Plane422UnormKHR                 = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR;
constexpr auto FormatG8B8R83Plane444Unorm                    = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM;
constexpr auto FormatG8B8R83Plane444UnormKHR                 = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR;
constexpr auto FormatR10X6UnormPack16                        = VK_FORMAT_R10X6_UNORM_PACK16;
constexpr auto FormatR10X6UnormPack16KHR                     = VK_FORMAT_R10X6_UNORM_PACK16_KHR;
constexpr auto FormatR10X6G10X6Unorm2Pack16                  = VK_FORMAT_R10X6G10X6_UNORM_2PACK16;
constexpr auto FormatR10X6G10X6Unorm2Pack16KHR               = VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR;
constexpr auto FormatR10X6G10X6B10X6A10X6Unorm4Pack16        = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16;
constexpr auto FormatR10X6G10X6B10X6A10X6Unorm4Pack16KHR     = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR;
constexpr auto FormatG10X6B10X6G10X6R10X6422Unorm4Pack16     = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16;
constexpr auto FormatG10X6B10X6G10X6R10X6422Unorm4Pack16KHR  = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR;
constexpr auto FormatB10X6G10X6R10X6G10X6422Unorm4Pack16     = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16;
constexpr auto FormatB10X6G10X6R10X6G10X6422Unorm4Pack16KHR  = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR;
constexpr auto FormatG10X6B10X6R10X63Plane420Unorm3Pack16    = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X63Plane420Unorm3Pack16KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR;
constexpr auto FormatG10X6B10X6R10X62Plane420Unorm3Pack16    = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X62Plane420Unorm3Pack16KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR;
constexpr auto FormatG10X6B10X6R10X63Plane422Unorm3Pack16    = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X63Plane422Unorm3Pack16KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR;
constexpr auto FormatG10X6B10X6R10X62Plane422Unorm3Pack16    = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X62Plane422Unorm3Pack16KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR;
constexpr auto FormatG10X6B10X6R10X63Plane444Unorm3Pack16    = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X63Plane444Unorm3Pack16KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR;
constexpr auto FormatR12X4UnormPack16                        = VK_FORMAT_R12X4_UNORM_PACK16;
constexpr auto FormatR12X4UnormPack16KHR                     = VK_FORMAT_R12X4_UNORM_PACK16_KHR;
constexpr auto FormatR12X4G12X4Unorm2Pack16                  = VK_FORMAT_R12X4G12X4_UNORM_2PACK16;
constexpr auto FormatR12X4G12X4Unorm2Pack16KHR               = VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR;
constexpr auto FormatR12X4G12X4B12X4A12X4Unorm4Pack16        = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16;
constexpr auto FormatR12X4G12X4B12X4A12X4Unorm4Pack16KHR     = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR;
constexpr auto FormatG12X4B12X4G12X4R12X4422Unorm4Pack16     = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16;
constexpr auto FormatG12X4B12X4G12X4R12X4422Unorm4Pack16KHR  = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR;
constexpr auto FormatB12X4G12X4R12X4G12X4422Unorm4Pack16     = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16;
constexpr auto FormatB12X4G12X4R12X4G12X4422Unorm4Pack16KHR  = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR;
constexpr auto FormatG12X4B12X4R12X43Plane420Unorm3Pack16    = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X43Plane420Unorm3Pack16KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR;
constexpr auto FormatG12X4B12X4R12X42Plane420Unorm3Pack16    = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X42Plane420Unorm3Pack16KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR;
constexpr auto FormatG12X4B12X4R12X43Plane422Unorm3Pack16    = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X43Plane422Unorm3Pack16KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR;
constexpr auto FormatG12X4B12X4R12X42Plane422Unorm3Pack16    = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X42Plane422Unorm3Pack16KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR;
constexpr auto FormatG12X4B12X4R12X43Plane444Unorm3Pack16    = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X43Plane444Unorm3Pack16KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR;
constexpr auto FormatG16B16G16R16422Unorm                    = VK_FORMAT_G16B16G16R16_422_UNORM;
constexpr auto FormatG16B16G16R16422UnormKHR                 = VK_FORMAT_G16B16G16R16_422_UNORM_KHR;
constexpr auto FormatB16G16R16G16422Unorm                    = VK_FORMAT_B16G16R16G16_422_UNORM;
constexpr auto FormatB16G16R16G16422UnormKHR                 = VK_FORMAT_B16G16R16G16_422_UNORM_KHR;
constexpr auto FormatG16B16R163Plane420Unorm                 = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM;
constexpr auto FormatG16B16R163Plane420UnormKHR              = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR;
constexpr auto FormatG16B16R162Plane420Unorm                 = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM;
constexpr auto FormatG16B16R162Plane420UnormKHR              = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR;
constexpr auto FormatG16B16R163Plane422Unorm                 = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM;
constexpr auto FormatG16B16R163Plane422UnormKHR              = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR;
constexpr auto FormatG16B16R162Plane422Unorm                 = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM;
constexpr auto FormatG16B16R162Plane422UnormKHR              = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR;
constexpr auto FormatG16B16R163Plane444Unorm                 = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM;
constexpr auto FormatG16B16R163Plane444UnormKHR              = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR;
constexpr auto FormatG8B8R82Plane444Unorm                    = VK_FORMAT_G8_B8R8_2PLANE_444_UNORM;
constexpr auto FormatG8B8R82Plane444UnormEXT                 = VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT;
constexpr auto FormatG10X6B10X6R10X62Plane444Unorm3Pack16    = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16;
constexpr auto FormatG10X6B10X6R10X62Plane444Unorm3Pack16EXT = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT;
constexpr auto FormatG12X4B12X4R12X42Plane444Unorm3Pack16    = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16;
constexpr auto FormatG12X4B12X4R12X42Plane444Unorm3Pack16EXT = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT;
constexpr auto FormatG16B16R162Plane444Unorm                 = VK_FORMAT_G16_B16R16_2PLANE_444_UNORM;
constexpr auto FormatG16B16R162Plane444UnormEXT              = VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT;
constexpr auto FormatA4R4G4B4UnormPack16                     = VK_FORMAT_A4R4G4B4_UNORM_PACK16;
constexpr auto FormatA4R4G4B4UnormPack16EXT                  = VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT;
constexpr auto FormatA4B4G4R4UnormPack16                     = VK_FORMAT_A4B4G4R4_UNORM_PACK16;
constexpr auto FormatA4B4G4R4UnormPack16EXT                  = VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT;
constexpr auto FormatAstc4x4SfloatBlock                      = VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK;
constexpr auto FormatAstc4x4SfloatBlockEXT                   = VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc5x4SfloatBlock                      = VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK;
constexpr auto FormatAstc5x4SfloatBlockEXT                   = VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc5x5SfloatBlock                      = VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK;
constexpr auto FormatAstc5x5SfloatBlockEXT                   = VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc6x5SfloatBlock                      = VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK;
constexpr auto FormatAstc6x5SfloatBlockEXT                   = VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc6x6SfloatBlock                      = VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK;
constexpr auto FormatAstc6x6SfloatBlockEXT                   = VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc8x5SfloatBlock                      = VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK;
constexpr auto FormatAstc8x5SfloatBlockEXT                   = VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc8x6SfloatBlock                      = VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK;
constexpr auto FormatAstc8x6SfloatBlockEXT                   = VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc8x8SfloatBlock                      = VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK;
constexpr auto FormatAstc8x8SfloatBlockEXT                   = VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc10x5SfloatBlock                     = VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK;
constexpr auto FormatAstc10x5SfloatBlockEXT                  = VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc10x6SfloatBlock                     = VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK;
constexpr auto FormatAstc10x6SfloatBlockEXT                  = VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc10x8SfloatBlock                     = VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK;
constexpr auto FormatAstc10x8SfloatBlockEXT                  = VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc10x10SfloatBlock                    = VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK;
constexpr auto FormatAstc10x10SfloatBlockEXT                 = VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc12x10SfloatBlock                    = VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK;
constexpr auto FormatAstc12x10SfloatBlockEXT                 = VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT;
constexpr auto FormatAstc12x12SfloatBlock                    = VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK;
constexpr auto FormatAstc12x12SfloatBlockEXT                 = VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT;
constexpr auto FormatA1B5G5R5UnormPack16                     = VK_FORMAT_A1B5G5R5_UNORM_PACK16;
constexpr auto FormatA1B5G5R5UnormPack16KHR                  = VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR;
constexpr auto FormatA8Unorm                                 = VK_FORMAT_A8_UNORM;
constexpr auto FormatA8UnormKHR                              = VK_FORMAT_A8_UNORM_KHR;
constexpr auto FormatPvrtc12BppUnormBlockIMG                 = VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG;
constexpr auto FormatPvrtc14BppUnormBlockIMG                 = VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG;
constexpr auto FormatPvrtc22BppUnormBlockIMG                 = VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG;
constexpr auto FormatPvrtc24BppUnormBlockIMG                 = VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG;
constexpr auto FormatPvrtc12BppSrgbBlockIMG                  = VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG;
constexpr auto FormatPvrtc14BppSrgbBlockIMG                  = VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG;
constexpr auto FormatPvrtc22BppSrgbBlockIMG                  = VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG;
constexpr auto FormatPvrtc24BppSrgbBlockIMG                  = VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG;
constexpr auto FormatR8BoolARM                               = VK_FORMAT_R8_BOOL_ARM;
constexpr auto FormatR16G16Sfixed5NV                         = VK_FORMAT_R16G16_SFIXED5_NV;
constexpr auto FormatR16G16S105NV                            = VK_FORMAT_R16G16_S10_5_NV;
constexpr auto FormatR10X6UintPack16ARM                      = VK_FORMAT_R10X6_UINT_PACK16_ARM;
constexpr auto FormatR10X6G10X6Uint2Pack16ARM                = VK_FORMAT_R10X6G10X6_UINT_2PACK16_ARM;
constexpr auto FormatR10X6G10X6B10X6A10X6Uint4Pack16ARM      = VK_FORMAT_R10X6G10X6B10X6A10X6_UINT_4PACK16_ARM;
constexpr auto FormatR12X4UintPack16ARM                      = VK_FORMAT_R12X4_UINT_PACK16_ARM;
constexpr auto FormatR12X4G12X4Uint2Pack16ARM                = VK_FORMAT_R12X4G12X4_UINT_2PACK16_ARM;
constexpr auto FormatR12X4G12X4B12X4A12X4Uint4Pack16ARM      = VK_FORMAT_R12X4G12X4B12X4A12X4_UINT_4PACK16_ARM;
constexpr auto FormatR14X2UintPack16ARM                      = VK_FORMAT_R14X2_UINT_PACK16_ARM;
constexpr auto FormatR14X2G14X2Uint2Pack16ARM                = VK_FORMAT_R14X2G14X2_UINT_2PACK16_ARM;
constexpr auto FormatR14X2G14X2B14X2A14X2Uint4Pack16ARM      = VK_FORMAT_R14X2G14X2B14X2A14X2_UINT_4PACK16_ARM;
constexpr auto FormatR14X2UnormPack16ARM                     = VK_FORMAT_R14X2_UNORM_PACK16_ARM;
constexpr auto FormatR14X2G14X2Unorm2Pack16ARM               = VK_FORMAT_R14X2G14X2_UNORM_2PACK16_ARM;
constexpr auto FormatR14X2G14X2B14X2A14X2Unorm4Pack16ARM     = VK_FORMAT_R14X2G14X2B14X2A14X2_UNORM_4PACK16_ARM;
constexpr auto FormatG14X2B14X2R14X22Plane420Unorm3Pack16ARM = VK_FORMAT_G14X2_B14X2R14X2_2PLANE_420_UNORM_3PACK16_ARM;
constexpr auto FormatG14X2B14X2R14X22Plane422Unorm3Pack16ARM = VK_FORMAT_G14X2_B14X2R14X2_2PLANE_422_UNORM_3PACK16_ARM;
//};

//enum FormatFeature {
constexpr auto FormatFeatureSampledImageBit                                                        = VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
constexpr auto FormatFeatureStorageImageBit                                                        = VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT;
constexpr auto FormatFeatureStorageImageAtomicBit                                                  = VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT;
constexpr auto FormatFeatureUniformTexelBufferBit                                                  = VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT;
constexpr auto FormatFeatureStorageTexelBufferBit                                                  = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT;
constexpr auto FormatFeatureStorageTexelBufferAtomicBit                                            = VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT;
constexpr auto FormatFeatureVertexBufferBit                                                        = VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT;
constexpr auto FormatFeatureColorAttachmentBit                                                     = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT;
constexpr auto FormatFeatureColorAttachmentBlendBit                                                = VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT;
constexpr auto FormatFeatureDepthStencilAttachmentBit                                              = VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT;
constexpr auto FormatFeatureBlitSrcBit                                                             = VK_FORMAT_FEATURE_BLIT_SRC_BIT;
constexpr auto FormatFeatureBlitDstBit                                                             = VK_FORMAT_FEATURE_BLIT_DST_BIT;
constexpr auto FormatFeatureSampledImageFilterLinearBit                                            = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT;
constexpr auto FormatFeatureTransferSrcBit                                                         = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT;
constexpr auto FormatFeatureTransferSrcBitKHR                                                      = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR;
constexpr auto FormatFeatureTransferDstBit                                                         = VK_FORMAT_FEATURE_TRANSFER_DST_BIT;
constexpr auto FormatFeatureTransferDstBitKHR                                                      = VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR;
constexpr auto FormatFeatureMidpointChromaSamplesBit                                               = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT;
constexpr auto FormatFeatureMidpointChromaSamplesBitKHR                                            = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR;
constexpr auto FormatFeatureSampledImageYcbcrConversionLinearFilterBit                             = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT;
constexpr auto FormatFeatureSampledImageYcbcrConversionLinearFilterBitKHR                          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR;
constexpr auto FormatFeatureSampledImageYcbcrConversionSeparateReconstructionFilterBit             = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT;
constexpr auto FormatFeatureSampledImageYcbcrConversionSeparateReconstructionFilterBitKHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR;
constexpr auto FormatFeatureSampledImageYcbcrConversionChromaReconstructionExplicitBit             = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT;
constexpr auto FormatFeatureSampledImageYcbcrConversionChromaReconstructionExplicitBitKHR          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR;
constexpr auto FormatFeatureSampledImageYcbcrConversionChromaReconstructionExplicitForceableBit    = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT;
constexpr auto FormatFeatureSampledImageYcbcrConversionChromaReconstructionExplicitForceableBitKHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR;
constexpr auto FormatFeatureDisjointBit                                                            = VK_FORMAT_FEATURE_DISJOINT_BIT;
constexpr auto FormatFeatureDisjointBitKHR                                                         = VK_FORMAT_FEATURE_DISJOINT_BIT_KHR;
constexpr auto FormatFeatureCositedChromaSamplesBit                                                = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT;
constexpr auto FormatFeatureCositedChromaSamplesBitKHR                                             = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR;
constexpr auto FormatFeatureSampledImageFilterMinmaxBit                                            = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT;
constexpr auto FormatFeatureSampledImageFilterMinmaxBitEXT                                         = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT;
constexpr auto FormatFeatureVideoDecodeOutputBitKHR                                                = VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR;
constexpr auto FormatFeatureVideoDecodeDpbBitKHR                                                   = VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR;
constexpr auto FormatFeatureAccelerationStructureVertexBufferBitKHR                                = VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR;
constexpr auto FormatFeatureSampledImageFilterCubicBitEXT                                          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT;
constexpr auto FormatFeatureSampledImageFilterCubicBitIMG                                          = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG;
constexpr auto FormatFeatureFragmentDensityMapBitEXT                                               = VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT;
constexpr auto FormatFeatureFragmentShadingRateAttachmentBitKHR                                    = VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto FormatFeatureVideoEncodeInputBitKHR                                                 = VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR;
constexpr auto FormatFeatureVideoEncodeDpbBitKHR                                                   = VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR;
//};

//enum ImageCreate {
constexpr auto ImageCreateSparseBindingBit                        = VK_IMAGE_CREATE_SPARSE_BINDING_BIT;
constexpr auto ImageCreateSparseResidencyBit                      = VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT;
constexpr auto ImageCreateSparseAliasedBit                        = VK_IMAGE_CREATE_SPARSE_ALIASED_BIT;
constexpr auto ImageCreateMutableFormatBit                        = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
constexpr auto ImageCreateCubeCompatibleBit                       = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
constexpr auto ImageCreateAliasBit                                = VK_IMAGE_CREATE_ALIAS_BIT;
constexpr auto ImageCreateAliasBitKHR                             = VK_IMAGE_CREATE_ALIAS_BIT_KHR;
constexpr auto ImageCreateSplitInstanceBindRegionsBit             = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT;
constexpr auto ImageCreateSplitInstanceBindRegionsBitKHR          = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR;
constexpr auto ImageCreate2DArrayCompatibleBit                    = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT;
constexpr auto ImageCreate2DArrayCompatibleBitKHR                 = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR;
constexpr auto ImageCreateBlockTexelViewCompatibleBit             = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT;
constexpr auto ImageCreateBlockTexelViewCompatibleBitKHR          = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR;
constexpr auto ImageCreateExtendedUsageBit                        = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT;
constexpr auto ImageCreateExtendedUsageBitKHR                     = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR;
constexpr auto ImageCreateProtectedBit                            = VK_IMAGE_CREATE_PROTECTED_BIT;
constexpr auto ImageCreateDisjointBit                             = VK_IMAGE_CREATE_DISJOINT_BIT;
constexpr auto ImageCreateDisjointBitKHR                          = VK_IMAGE_CREATE_DISJOINT_BIT_KHR;
constexpr auto ImageCreateCornerSampledBitNV                      = VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV;
constexpr auto ImageCreateSampleLocationsCompatibleDepthBitEXT    = VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT;
constexpr auto ImageCreateSubsampledBitEXT                        = VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT;
constexpr auto ImageCreateDescriptorBufferCaptureReplayBitEXT     = VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
constexpr auto ImageCreateMultisampledRenderToSingleSampledBitEXT = VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT;
constexpr auto ImageCreate2DViewCompatibleBitEXT                  = VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT;
constexpr auto ImageCreateVideoProfileIndependentBitKHR           = VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR;
constexpr auto ImageCreateFragmentDensityMapOffsetBitEXT          = VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_EXT;
constexpr auto ImageCreateFragmentDensityMapOffsetBitQCOM         = VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM;
//};

//enum ImageTiling {
constexpr auto ImageTilingOptimal              = VK_IMAGE_TILING_OPTIMAL;
constexpr auto ImageTilingLinear               = VK_IMAGE_TILING_LINEAR;
constexpr auto ImageTilingDrmFormatModifierEXT = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT;
//};

//enum ImageType {
constexpr auto ImageType1D = VK_IMAGE_TYPE_1D;
constexpr auto ImageType2D = VK_IMAGE_TYPE_2D;
constexpr auto ImageType3D = VK_IMAGE_TYPE_3D;
//};

//enum ImageUsage {
constexpr auto ImageUsageTransferSrcBit                        = VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
constexpr auto ImageUsageTransferDstBit                        = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
constexpr auto ImageUsageSampledBit                            = VK_IMAGE_USAGE_SAMPLED_BIT;
constexpr auto ImageUsageStorageBit                            = VK_IMAGE_USAGE_STORAGE_BIT;
constexpr auto ImageUsageColorAttachmentBit                    = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
constexpr auto ImageUsageDepthStencilAttachmentBit             = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
constexpr auto ImageUsageTransientAttachmentBit                = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
constexpr auto ImageUsageInputAttachmentBit                    = VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT;
constexpr auto ImageUsageHostTransferBit                       = VK_IMAGE_USAGE_HOST_TRANSFER_BIT;
constexpr auto ImageUsageHostTransferBitEXT                    = VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT;
constexpr auto ImageUsageVideoDecodeDstBitKHR                  = VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR;
constexpr auto ImageUsageVideoDecodeSrcBitKHR                  = VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR;
constexpr auto ImageUsageVideoDecodeDpbBitKHR                  = VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR;
constexpr auto ImageUsageFragmentDensityMapBitEXT              = VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT;
constexpr auto ImageUsageFragmentShadingRateAttachmentBitKHR   = VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto ImageUsageShadingRateImageBitNV                 = VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV;
constexpr auto ImageUsageVideoEncodeDstBitKHR                  = VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR;
constexpr auto ImageUsageVideoEncodeSrcBitKHR                  = VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR;
constexpr auto ImageUsageVideoEncodeDpbBitKHR                  = VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR;
constexpr auto ImageUsageAttachmentFeedbackLoopBitEXT          = VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT;
constexpr auto ImageUsageInvocationMaskBitHUAWEI               = VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI;
constexpr auto ImageUsageSampleWeightBitQCOM                   = VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM;
constexpr auto ImageUsageSampleBlockMatchBitQCOM               = VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM;
constexpr auto ImageUsageTensorAliasingBitARM                  = VK_IMAGE_USAGE_TENSOR_ALIASING_BIT_ARM;
constexpr auto ImageUsageTileMemoryBitQCOM                     = VK_IMAGE_USAGE_TILE_MEMORY_BIT_QCOM;
constexpr auto ImageUsageVideoEncodeQuantizationDeltaMapBitKHR = VK_IMAGE_USAGE_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR;
constexpr auto ImageUsageVideoEncodeEmphasisMapBitKHR          = VK_IMAGE_USAGE_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR;
//};

//enum InstanceCreate {
constexpr auto InstanceCreateEnumeratePortabilityBitKHR = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
//};

//enum InternalAllocationType {
constexpr auto InternalAllocationTypeExecutable = VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE;
//};

//enum MemoryHeap {
constexpr auto MemoryHeapDeviceLocalBit      = VK_MEMORY_HEAP_DEVICE_LOCAL_BIT;
constexpr auto MemoryHeapMultiInstanceBit    = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT;
constexpr auto MemoryHeapMultiInstanceBitKHR = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR;
constexpr auto MemoryHeapTileMemoryBitQCOM   = VK_MEMORY_HEAP_TILE_MEMORY_BIT_QCOM;
//};

//enum MemoryProperty {
constexpr auto MemoryPropertyDeviceLocalBit       = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
constexpr auto MemoryPropertyHostVisibleBit       = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;
constexpr auto MemoryPropertyHostCoherentBit      = VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
constexpr auto MemoryPropertyHostCachedBit        = VK_MEMORY_PROPERTY_HOST_CACHED_BIT;
constexpr auto MemoryPropertyLazilyAllocatedBit   = VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT;
constexpr auto MemoryPropertyProtectedBit         = VK_MEMORY_PROPERTY_PROTECTED_BIT;
constexpr auto MemoryPropertyDeviceCoherentBitAMD = VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD;
constexpr auto MemoryPropertyDeviceUncachedBitAMD = VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD;
constexpr auto MemoryPropertyRdmaCapableBitNV     = VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV;
//};

//enum PhysicalDeviceType {
constexpr auto PhysicalDeviceTypeOther         = VK_PHYSICAL_DEVICE_TYPE_OTHER;
constexpr auto PhysicalDeviceTypeIntegratedGpu = VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU;
constexpr auto PhysicalDeviceTypeDiscreteGpu   = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
constexpr auto PhysicalDeviceTypeVirtualGpu    = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU;
constexpr auto PhysicalDeviceTypeCpu           = VK_PHYSICAL_DEVICE_TYPE_CPU;
//};

//enum Queue {
constexpr auto QueueGraphicsBit       = VK_QUEUE_GRAPHICS_BIT;
constexpr auto QueueComputeBit        = VK_QUEUE_COMPUTE_BIT;
constexpr auto QueueTransferBit       = VK_QUEUE_TRANSFER_BIT;
constexpr auto QueueSparseBindingBit  = VK_QUEUE_SPARSE_BINDING_BIT;
constexpr auto QueueProtectedBit      = VK_QUEUE_PROTECTED_BIT;
constexpr auto QueueVideoDecodeBitKHR = VK_QUEUE_VIDEO_DECODE_BIT_KHR;
constexpr auto QueueVideoEncodeBitKHR = VK_QUEUE_VIDEO_ENCODE_BIT_KHR;
constexpr auto QueueOpticalFlowBitNV  = VK_QUEUE_OPTICAL_FLOW_BIT_NV;
constexpr auto QueueDataGraphBitARM   = VK_QUEUE_DATA_GRAPH_BIT_ARM;
//};

//enum SampleCount {
constexpr auto SampleCount1Bit  = VK_SAMPLE_COUNT_1_BIT;
constexpr auto SampleCount2Bit  = VK_SAMPLE_COUNT_2_BIT;
constexpr auto SampleCount4Bit  = VK_SAMPLE_COUNT_4_BIT;
constexpr auto SampleCount8Bit  = VK_SAMPLE_COUNT_8_BIT;
constexpr auto SampleCount16Bit = VK_SAMPLE_COUNT_16_BIT;
constexpr auto SampleCount32Bit = VK_SAMPLE_COUNT_32_BIT;
constexpr auto SampleCount64Bit = VK_SAMPLE_COUNT_64_BIT;
//};

//enum SystemAllocationScope {
constexpr auto SystemAllocationScopeCommand  = VK_SYSTEM_ALLOCATION_SCOPE_COMMAND;
constexpr auto SystemAllocationScopeObject   = VK_SYSTEM_ALLOCATION_SCOPE_OBJECT;
constexpr auto SystemAllocationScopeCache    = VK_SYSTEM_ALLOCATION_SCOPE_CACHE;
constexpr auto SystemAllocationScopeDevice   = VK_SYSTEM_ALLOCATION_SCOPE_DEVICE;
constexpr auto SystemAllocationScopeInstance = VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE;
//};

//enum DeviceCreate {
//};

//enum DeviceQueueCreate {
constexpr auto DeviceQueueCreateProtectedBit = VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT;
//};

//enum PipelineStage {
constexpr auto PipelineStageTopOfPipeBit                        = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
constexpr auto PipelineStageDrawIndirectBit                     = VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT;
constexpr auto PipelineStageVertexInputBit                      = VK_PIPELINE_STAGE_VERTEX_INPUT_BIT;
constexpr auto PipelineStageVertexShaderBit                     = VK_PIPELINE_STAGE_VERTEX_SHADER_BIT;
constexpr auto PipelineStageTessellationControlShaderBit        = VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT;
constexpr auto PipelineStageTessellationEvaluationShaderBit     = VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT;
constexpr auto PipelineStageGeometryShaderBit                   = VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT;
constexpr auto PipelineStageFragmentShaderBit                   = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
constexpr auto PipelineStageEarlyFragmentTestsBit               = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
constexpr auto PipelineStageLateFragmentTestsBit                = VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
constexpr auto PipelineStageColorAttachmentOutputBit            = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
constexpr auto PipelineStageComputeShaderBit                    = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
constexpr auto PipelineStageTransferBit                         = VK_PIPELINE_STAGE_TRANSFER_BIT;
constexpr auto PipelineStageBottomOfPipeBit                     = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
constexpr auto PipelineStageHostBit                             = VK_PIPELINE_STAGE_HOST_BIT;
constexpr auto PipelineStageAllGraphicsBit                      = VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT;
constexpr auto PipelineStageAllCommandsBit                      = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
constexpr auto PipelineStageNone                                = VK_PIPELINE_STAGE_NONE;
constexpr auto PipelineStageNoneKHR                             = VK_PIPELINE_STAGE_NONE_KHR;
constexpr auto PipelineStageTransformFeedbackBitEXT             = VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT;
constexpr auto PipelineStageConditionalRenderingBitEXT          = VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT;
constexpr auto PipelineStageAccelerationStructureBuildBitKHR    = VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR;
constexpr auto PipelineStageAccelerationStructureBuildBitNV     = VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV;
constexpr auto PipelineStageRayTracingShaderBitKHR              = VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR;
constexpr auto PipelineStageRayTracingShaderBitNV               = VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV;
constexpr auto PipelineStageFragmentDensityProcessBitEXT        = VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT;
constexpr auto PipelineStageFragmentShadingRateAttachmentBitKHR = VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto PipelineStageShadingRateImageBitNV               = VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV;
constexpr auto PipelineStageTaskShaderBitEXT                    = VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT;
constexpr auto PipelineStageTaskShaderBitNV                     = VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV;
constexpr auto PipelineStageMeshShaderBitEXT                    = VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT;
constexpr auto PipelineStageMeshShaderBitNV                     = VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV;
constexpr auto PipelineStageCommandPreprocessBitEXT             = VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_EXT;
constexpr auto PipelineStageCommandPreprocessBitNV              = VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV;
//};

//enum MemoryMap {
constexpr auto MemoryMapPlacedBitEXT = VK_MEMORY_MAP_PLACED_BIT_EXT;
//};

//enum ImageAspect {
constexpr auto ImageAspectColorBit           = VK_IMAGE_ASPECT_COLOR_BIT;
constexpr auto ImageAspectDepthBit           = VK_IMAGE_ASPECT_DEPTH_BIT;
constexpr auto ImageAspectStencilBit         = VK_IMAGE_ASPECT_STENCIL_BIT;
constexpr auto ImageAspectMetadataBit        = VK_IMAGE_ASPECT_METADATA_BIT;
constexpr auto ImageAspectPlane0Bit          = VK_IMAGE_ASPECT_PLANE_0_BIT;
constexpr auto ImageAspectPlane0BitKHR       = VK_IMAGE_ASPECT_PLANE_0_BIT_KHR;
constexpr auto ImageAspectPlane1Bit          = VK_IMAGE_ASPECT_PLANE_1_BIT;
constexpr auto ImageAspectPlane1BitKHR       = VK_IMAGE_ASPECT_PLANE_1_BIT_KHR;
constexpr auto ImageAspectPlane2Bit          = VK_IMAGE_ASPECT_PLANE_2_BIT;
constexpr auto ImageAspectPlane2BitKHR       = VK_IMAGE_ASPECT_PLANE_2_BIT_KHR;
constexpr auto ImageAspectNone               = VK_IMAGE_ASPECT_NONE;
constexpr auto ImageAspectNoneKHR            = VK_IMAGE_ASPECT_NONE_KHR;
constexpr auto ImageAspectMemoryPlane0BitEXT = VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT;
constexpr auto ImageAspectMemoryPlane1BitEXT = VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT;
constexpr auto ImageAspectMemoryPlane2BitEXT = VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT;
constexpr auto ImageAspectMemoryPlane3BitEXT = VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT;
//};

//enum SparseImageFormat {
constexpr auto SparseImageFormatSingleMiptailBit        = VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT;
constexpr auto SparseImageFormatAlignedMipSizeBit       = VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT;
constexpr auto SparseImageFormatNonstandardBlockSizeBit = VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT;
//};

//enum SparseMemoryBind {
constexpr auto SparseMemoryBindMetadataBit = VK_SPARSE_MEMORY_BIND_METADATA_BIT;
//};

//enum FenceCreate {
constexpr auto FenceCreateSignaledBit = VK_FENCE_CREATE_SIGNALED_BIT;
//};

//enum SemaphoreCreate {
//};

//enum EventCreate {
constexpr auto EventCreateDeviceOnlyBit    = VK_EVENT_CREATE_DEVICE_ONLY_BIT;
constexpr auto EventCreateDeviceOnlyBitKHR = VK_EVENT_CREATE_DEVICE_ONLY_BIT_KHR;
//};

//enum QueryPipelineStatistic {
constexpr auto QueryPipelineStatisticInputAssemblyVerticesBit                   = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT;
constexpr auto QueryPipelineStatisticInputAssemblyPrimitivesBit                 = VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT;
constexpr auto QueryPipelineStatisticVertexShaderInvocationsBit                 = VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticGeometryShaderInvocationsBit               = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticGeometryShaderPrimitivesBit                = VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT;
constexpr auto QueryPipelineStatisticClippingInvocationsBit                     = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticClippingPrimitivesBit                      = VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT;
constexpr auto QueryPipelineStatisticFragmentShaderInvocationsBit               = VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticTessellationControlShaderPatchesBit        = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT;
constexpr auto QueryPipelineStatisticTessellationEvaluationShaderInvocationsBit = VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticComputeShaderInvocationsBit                = VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT;
constexpr auto QueryPipelineStatisticTaskShaderInvocationsBitEXT                = VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT;
constexpr auto QueryPipelineStatisticMeshShaderInvocationsBitEXT                = VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT;
constexpr auto QueryPipelineStatisticClusterCullingShaderInvocationsBitHUAWEI   = VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI;
//};

//enum QueryPoolCreate {
constexpr auto QueryPoolCreateResetBitKHR = VK_QUERY_POOL_CREATE_RESET_BIT_KHR;
//};

//enum QueryResult {
constexpr auto QueryResult64Bit               = VK_QUERY_RESULT_64_BIT;
constexpr auto QueryResultWaitBit             = VK_QUERY_RESULT_WAIT_BIT;
constexpr auto QueryResultWithAvailabilityBit = VK_QUERY_RESULT_WITH_AVAILABILITY_BIT;
constexpr auto QueryResultPartialBit          = VK_QUERY_RESULT_PARTIAL_BIT;
constexpr auto QueryResultWithStatusBitKHR    = VK_QUERY_RESULT_WITH_STATUS_BIT_KHR;
//};

//enum QueryType {
constexpr auto QueryTypeOcclusion                                                = VK_QUERY_TYPE_OCCLUSION;
constexpr auto QueryTypePipelineStatistics                                       = VK_QUERY_TYPE_PIPELINE_STATISTICS;
constexpr auto QueryTypeTimestamp                                                = VK_QUERY_TYPE_TIMESTAMP;
constexpr auto QueryTypeResultStatusOnlyKHR                                      = VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR;
constexpr auto QueryTypeTransformFeedbackStreamEXT                               = VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT;
constexpr auto QueryTypePerformanceQueryKHR                                      = VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR;
constexpr auto QueryTypeAccelerationStructureCompactedSizeKHR                    = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR;
constexpr auto QueryTypeAccelerationStructureSerializationSizeKHR                = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR;
constexpr auto QueryTypeAccelerationStructureCompactedSizeNV                     = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV;
constexpr auto QueryTypePerformanceQueryINTEL                                    = VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL;
constexpr auto QueryTypeVideoEncodeFeedbackKHR                                   = VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR;
constexpr auto QueryTypeMeshPrimitivesGeneratedEXT                               = VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT;
constexpr auto QueryTypePrimitivesGeneratedEXT                                   = VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT;
constexpr auto QueryTypeAccelerationStructureSerializationBottomLevelPointersKHR = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR;
constexpr auto QueryTypeAccelerationStructureSizeKHR                             = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR;
constexpr auto QueryTypeMicromapSerializationSizeEXT                             = VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT;
constexpr auto QueryTypeMicromapCompactedSizeEXT                                 = VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT;
//};

//enum BufferCreate {
constexpr auto BufferCreateSparseBindingBit                    = VK_BUFFER_CREATE_SPARSE_BINDING_BIT;
constexpr auto BufferCreateSparseResidencyBit                  = VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT;
constexpr auto BufferCreateSparseAliasedBit                    = VK_BUFFER_CREATE_SPARSE_ALIASED_BIT;
constexpr auto BufferCreateProtectedBit                        = VK_BUFFER_CREATE_PROTECTED_BIT;
constexpr auto BufferCreateDeviceAddressCaptureReplayBit       = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
constexpr auto BufferCreateDeviceAddressCaptureReplayBitEXT    = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT;
constexpr auto BufferCreateDeviceAddressCaptureReplayBitKHR    = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
constexpr auto BufferCreateDescriptorBufferCaptureReplayBitEXT = VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
constexpr auto BufferCreateVideoProfileIndependentBitKHR       = VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR;
//};

//enum BufferUsage {
constexpr auto BufferUsageTransferSrcBit                                = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
constexpr auto BufferUsageTransferDstBit                                = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
constexpr auto BufferUsageUniformTexelBufferBit                         = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT;
constexpr auto BufferUsageStorageTexelBufferBit                         = VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT;
constexpr auto BufferUsageUniformBufferBit                              = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
constexpr auto BufferUsageStorageBufferBit                              = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
constexpr auto BufferUsageIndexBufferBit                                = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
constexpr auto BufferUsageVertexBufferBit                               = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
constexpr auto BufferUsageIndirectBufferBit                             = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT;
constexpr auto BufferUsageShaderDeviceAddressBit                        = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
constexpr auto BufferUsageShaderDeviceAddressBitEXT                     = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_EXT;
constexpr auto BufferUsageShaderDeviceAddressBitKHR                     = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_KHR;
constexpr auto BufferUsageVideoDecodeSrcBitKHR                          = VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR;
constexpr auto BufferUsageVideoDecodeDstBitKHR                          = VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR;
constexpr auto BufferUsageTransformFeedbackBufferBitEXT                 = VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT;
constexpr auto BufferUsageTransformFeedbackCounterBufferBitEXT          = VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT;
constexpr auto BufferUsageConditionalRenderingBitEXT                    = VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsageExecutionGraphScratchBitAMDX                  = VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsageAccelerationStructureBuildInputReadOnlyBitKHR = VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR;
constexpr auto BufferUsageAccelerationStructureStorageBitKHR            = VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR;
constexpr auto BufferUsageShaderBindingTableBitKHR                      = VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR;
constexpr auto BufferUsageRayTracingBitNV                               = VK_BUFFER_USAGE_RAY_TRACING_BIT_NV;
constexpr auto BufferUsageVideoEncodeDstBitKHR                          = VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR;
constexpr auto BufferUsageVideoEncodeSrcBitKHR                          = VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR;
constexpr auto BufferUsageSamplerDescriptorBufferBitEXT                 = VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsageResourceDescriptorBufferBitEXT                = VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsagePushDescriptorsDescriptorBufferBitEXT         = VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsageMicromapBuildInputReadOnlyBitEXT              = VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT;
constexpr auto BufferUsageMicromapStorageBitEXT                         = VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT;
constexpr auto BufferUsageTileMemoryBitQCOM                             = VK_BUFFER_USAGE_TILE_MEMORY_BIT_QCOM;
//};

//enum SharingMode {
constexpr auto SharingModeExclusive  = VK_SHARING_MODE_EXCLUSIVE;
constexpr auto SharingModeConcurrent = VK_SHARING_MODE_CONCURRENT;
//};

//enum BufferViewCreate {
//};

//enum ImageLayout {
constexpr auto ImageLayoutUndefined                                = VK_IMAGE_LAYOUT_UNDEFINED;
constexpr auto ImageLayoutGeneral                                  = VK_IMAGE_LAYOUT_GENERAL;
constexpr auto ImageLayoutColorAttachmentOptimal                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutDepthStencilAttachmentOptimal            = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutDepthStencilReadOnlyOptimal              = VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutShaderReadOnlyOptimal                    = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutTransferSrcOptimal                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
constexpr auto ImageLayoutTransferDstOptimal                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
constexpr auto ImageLayoutPreinitialized                           = VK_IMAGE_LAYOUT_PREINITIALIZED;
constexpr auto ImageLayoutDepthReadOnlyStencilAttachmentOptimal    = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutDepthReadOnlyStencilAttachmentOptimalKHR = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR;
constexpr auto ImageLayoutDepthAttachmentStencilReadOnlyOptimal    = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutDepthAttachmentStencilReadOnlyOptimalKHR = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR;
constexpr auto ImageLayoutDepthAttachmentOptimal                   = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutDepthAttachmentOptimalKHR                = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR;
constexpr auto ImageLayoutDepthReadOnlyOptimal                     = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutDepthReadOnlyOptimalKHR                  = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR;
constexpr auto ImageLayoutStencilAttachmentOptimal                 = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutStencilAttachmentOptimalKHR              = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR;
constexpr auto ImageLayoutStencilReadOnlyOptimal                   = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutStencilReadOnlyOptimalKHR                = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR;
constexpr auto ImageLayoutReadOnlyOptimal                          = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
constexpr auto ImageLayoutReadOnlyOptimalKHR                       = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR;
constexpr auto ImageLayoutAttachmentOptimal                        = VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL;
constexpr auto ImageLayoutAttachmentOptimalKHR                     = VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR;
constexpr auto ImageLayoutRenderingLocalRead                       = VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ;
constexpr auto ImageLayoutRenderingLocalReadKHR                    = VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR;
constexpr auto ImageLayoutPresentSrcKHR                            = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
constexpr auto ImageLayoutVideoDecodeDstKHR                        = VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR;
constexpr auto ImageLayoutVideoDecodeSrcKHR                        = VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR;
constexpr auto ImageLayoutVideoDecodeDpbKHR                        = VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR;
constexpr auto ImageLayoutSharedPresentKHR                         = VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR;
constexpr auto ImageLayoutFragmentDensityMapOptimalEXT             = VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT;
constexpr auto ImageLayoutFragmentShadingRateAttachmentOptimalKHR  = VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR;
constexpr auto ImageLayoutShadingRateOptimalNV                     = VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV;
constexpr auto ImageLayoutVideoEncodeDstKHR                        = VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR;
constexpr auto ImageLayoutVideoEncodeSrcKHR                        = VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR;
constexpr auto ImageLayoutVideoEncodeDpbKHR                        = VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR;
constexpr auto ImageLayoutAttachmentFeedbackLoopOptimalEXT         = VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT;
constexpr auto ImageLayoutTensorAliasingARM                        = VK_IMAGE_LAYOUT_TENSOR_ALIASING_ARM;
constexpr auto ImageLayoutVideoEncodeQuantizationMapKHR            = VK_IMAGE_LAYOUT_VIDEO_ENCODE_QUANTIZATION_MAP_KHR;
constexpr auto ImageLayoutZeroInitializedEXT                       = VK_IMAGE_LAYOUT_ZERO_INITIALIZED_EXT;
//};

//enum ComponentSwizzle {
constexpr auto ComponentSwizzleIdentity = VK_COMPONENT_SWIZZLE_IDENTITY;
constexpr auto ComponentSwizzleZero     = VK_COMPONENT_SWIZZLE_ZERO;
constexpr auto ComponentSwizzleOne      = VK_COMPONENT_SWIZZLE_ONE;
constexpr auto ComponentSwizzleR        = VK_COMPONENT_SWIZZLE_R;
constexpr auto ComponentSwizzleG        = VK_COMPONENT_SWIZZLE_G;
constexpr auto ComponentSwizzleB        = VK_COMPONENT_SWIZZLE_B;
constexpr auto ComponentSwizzleA        = VK_COMPONENT_SWIZZLE_A;
//};

//enum ImageViewCreate {
constexpr auto ImageViewCreateFragmentDensityMapDynamicBitEXT     = VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT;
constexpr auto ImageViewCreateDescriptorBufferCaptureReplayBitEXT = VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
constexpr auto ImageViewCreateFragmentDensityMapDeferredBitEXT    = VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT;
//};

//enum ImageViewType {
constexpr auto ImageViewType1D        = VK_IMAGE_VIEW_TYPE_1D;
constexpr auto ImageViewType2D        = VK_IMAGE_VIEW_TYPE_2D;
constexpr auto ImageViewType3D        = VK_IMAGE_VIEW_TYPE_3D;
constexpr auto ImageViewTypeCube      = VK_IMAGE_VIEW_TYPE_CUBE;
constexpr auto ImageViewType1DArray   = VK_IMAGE_VIEW_TYPE_1D_ARRAY;
constexpr auto ImageViewType2DArray   = VK_IMAGE_VIEW_TYPE_2D_ARRAY;
constexpr auto ImageViewTypeCubeArray = VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
//};

//enum ShaderModuleCreate {
//};

//enum PipelineCacheCreate {
constexpr auto PipelineCacheCreateExternallySynchronizedBit         = VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT;
constexpr auto PipelineCacheCreateExternallySynchronizedBitEXT      = VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT;
constexpr auto PipelineCacheCreateInternallySynchronizedMergeBitKHR = VK_PIPELINE_CACHE_CREATE_INTERNALLY_SYNCHRONIZED_MERGE_BIT_KHR;
//};

//enum BlendFactor {
constexpr auto BlendFactorZero                  = VK_BLEND_FACTOR_ZERO;
constexpr auto BlendFactorOne                   = VK_BLEND_FACTOR_ONE;
constexpr auto BlendFactorSrcColor              = VK_BLEND_FACTOR_SRC_COLOR;
constexpr auto BlendFactorOneMinusSrcColor      = VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
constexpr auto BlendFactorDstColor              = VK_BLEND_FACTOR_DST_COLOR;
constexpr auto BlendFactorOneMinusDstColor      = VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
constexpr auto BlendFactorSrcAlpha              = VK_BLEND_FACTOR_SRC_ALPHA;
constexpr auto BlendFactorOneMinusSrcAlpha      = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
constexpr auto BlendFactorDstAlpha              = VK_BLEND_FACTOR_DST_ALPHA;
constexpr auto BlendFactorOneMinusDstAlpha      = VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
constexpr auto BlendFactorConstantColor         = VK_BLEND_FACTOR_CONSTANT_COLOR;
constexpr auto BlendFactorOneMinusConstantColor = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR;
constexpr auto BlendFactorConstantAlpha         = VK_BLEND_FACTOR_CONSTANT_ALPHA;
constexpr auto BlendFactorOneMinusConstantAlpha = VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
constexpr auto BlendFactorSrcAlphaSaturate      = VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
constexpr auto BlendFactorSrc1Color             = VK_BLEND_FACTOR_SRC1_COLOR;
constexpr auto BlendFactorOneMinusSrc1Color     = VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR;
constexpr auto BlendFactorSrc1Alpha             = VK_BLEND_FACTOR_SRC1_ALPHA;
constexpr auto BlendFactorOneMinusSrc1Alpha     = VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA;
//};

//enum BlendOp {
constexpr auto BlendOpAdd                 = VK_BLEND_OP_ADD;
constexpr auto BlendOpSubtract            = VK_BLEND_OP_SUBTRACT;
constexpr auto BlendOpReverseSubtract     = VK_BLEND_OP_REVERSE_SUBTRACT;
constexpr auto BlendOpMin                 = VK_BLEND_OP_MIN;
constexpr auto BlendOpMax                 = VK_BLEND_OP_MAX;
constexpr auto BlendOpZeroEXT             = VK_BLEND_OP_ZERO_EXT;
constexpr auto BlendOpSrcEXT              = VK_BLEND_OP_SRC_EXT;
constexpr auto BlendOpDstEXT              = VK_BLEND_OP_DST_EXT;
constexpr auto BlendOpSrcOverEXT          = VK_BLEND_OP_SRC_OVER_EXT;
constexpr auto BlendOpDstOverEXT          = VK_BLEND_OP_DST_OVER_EXT;
constexpr auto BlendOpSrcInEXT            = VK_BLEND_OP_SRC_IN_EXT;
constexpr auto BlendOpDstInEXT            = VK_BLEND_OP_DST_IN_EXT;
constexpr auto BlendOpSrcOutEXT           = VK_BLEND_OP_SRC_OUT_EXT;
constexpr auto BlendOpDstOutEXT           = VK_BLEND_OP_DST_OUT_EXT;
constexpr auto BlendOpSrcAtopEXT          = VK_BLEND_OP_SRC_ATOP_EXT;
constexpr auto BlendOpDstAtopEXT          = VK_BLEND_OP_DST_ATOP_EXT;
constexpr auto BlendOpXorEXT              = VK_BLEND_OP_XOR_EXT;
constexpr auto BlendOpMultiplyEXT         = VK_BLEND_OP_MULTIPLY_EXT;
constexpr auto BlendOpScreenEXT           = VK_BLEND_OP_SCREEN_EXT;
constexpr auto BlendOpOverlayEXT          = VK_BLEND_OP_OVERLAY_EXT;
constexpr auto BlendOpDarkenEXT           = VK_BLEND_OP_DARKEN_EXT;
constexpr auto BlendOpLightenEXT          = VK_BLEND_OP_LIGHTEN_EXT;
constexpr auto BlendOpColordodgeEXT       = VK_BLEND_OP_COLORDODGE_EXT;
constexpr auto BlendOpColorburnEXT        = VK_BLEND_OP_COLORBURN_EXT;
constexpr auto BlendOpHardlightEXT        = VK_BLEND_OP_HARDLIGHT_EXT;
constexpr auto BlendOpSoftlightEXT        = VK_BLEND_OP_SOFTLIGHT_EXT;
constexpr auto BlendOpDifferenceEXT       = VK_BLEND_OP_DIFFERENCE_EXT;
constexpr auto BlendOpExclusionEXT        = VK_BLEND_OP_EXCLUSION_EXT;
constexpr auto BlendOpInvertEXT           = VK_BLEND_OP_INVERT_EXT;
constexpr auto BlendOpInvertRgbEXT        = VK_BLEND_OP_INVERT_RGB_EXT;
constexpr auto BlendOpLineardodgeEXT      = VK_BLEND_OP_LINEARDODGE_EXT;
constexpr auto BlendOpLinearburnEXT       = VK_BLEND_OP_LINEARBURN_EXT;
constexpr auto BlendOpVividlightEXT       = VK_BLEND_OP_VIVIDLIGHT_EXT;
constexpr auto BlendOpLinearlightEXT      = VK_BLEND_OP_LINEARLIGHT_EXT;
constexpr auto BlendOpPinlightEXT         = VK_BLEND_OP_PINLIGHT_EXT;
constexpr auto BlendOpHardmixEXT          = VK_BLEND_OP_HARDMIX_EXT;
constexpr auto BlendOpHslHueEXT           = VK_BLEND_OP_HSL_HUE_EXT;
constexpr auto BlendOpHslSaturationEXT    = VK_BLEND_OP_HSL_SATURATION_EXT;
constexpr auto BlendOpHslColorEXT         = VK_BLEND_OP_HSL_COLOR_EXT;
constexpr auto BlendOpHslLuminosityEXT    = VK_BLEND_OP_HSL_LUMINOSITY_EXT;
constexpr auto BlendOpPlusEXT             = VK_BLEND_OP_PLUS_EXT;
constexpr auto BlendOpPlusClampedEXT      = VK_BLEND_OP_PLUS_CLAMPED_EXT;
constexpr auto BlendOpPlusClampedAlphaEXT = VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT;
constexpr auto BlendOpPlusDarkerEXT       = VK_BLEND_OP_PLUS_DARKER_EXT;
constexpr auto BlendOpMinusEXT            = VK_BLEND_OP_MINUS_EXT;
constexpr auto BlendOpMinusClampedEXT     = VK_BLEND_OP_MINUS_CLAMPED_EXT;
constexpr auto BlendOpContrastEXT         = VK_BLEND_OP_CONTRAST_EXT;
constexpr auto BlendOpInvertOvgEXT        = VK_BLEND_OP_INVERT_OVG_EXT;
constexpr auto BlendOpRedEXT              = VK_BLEND_OP_RED_EXT;
constexpr auto BlendOpGreenEXT            = VK_BLEND_OP_GREEN_EXT;
constexpr auto BlendOpBlueEXT             = VK_BLEND_OP_BLUE_EXT;
//};

//enum ColorComponent {
constexpr auto ColorComponentRBit = VK_COLOR_COMPONENT_R_BIT;
constexpr auto ColorComponentGBit = VK_COLOR_COMPONENT_G_BIT;
constexpr auto ColorComponentBBit = VK_COLOR_COMPONENT_B_BIT;
constexpr auto ColorComponentABit = VK_COLOR_COMPONENT_A_BIT;
//};

//enum CompareOp {
constexpr auto CompareOpNever          = VK_COMPARE_OP_NEVER;
constexpr auto CompareOpLess           = VK_COMPARE_OP_LESS;
constexpr auto CompareOpEqual          = VK_COMPARE_OP_EQUAL;
constexpr auto CompareOpLessOrEqual    = VK_COMPARE_OP_LESS_OR_EQUAL;
constexpr auto CompareOpGreater        = VK_COMPARE_OP_GREATER;
constexpr auto CompareOpNotEqual       = VK_COMPARE_OP_NOT_EQUAL;
constexpr auto CompareOpGreaterOrEqual = VK_COMPARE_OP_GREATER_OR_EQUAL;
constexpr auto CompareOpAlways         = VK_COMPARE_OP_ALWAYS;
//};

//enum CullMode {
constexpr auto CullModeNone         = VK_CULL_MODE_NONE;
constexpr auto CullModeFrontBit     = VK_CULL_MODE_FRONT_BIT;
constexpr auto CullModeBackBit      = VK_CULL_MODE_BACK_BIT;
constexpr auto CullModeFrontAndBack = VK_CULL_MODE_FRONT_AND_BACK;
//};

//enum DynamicState {
constexpr auto DynamicStateViewport                            = VK_DYNAMIC_STATE_VIEWPORT;
constexpr auto DynamicStateScissor                             = VK_DYNAMIC_STATE_SCISSOR;
constexpr auto DynamicStateLineWidth                           = VK_DYNAMIC_STATE_LINE_WIDTH;
constexpr auto DynamicStateDepthBias                           = VK_DYNAMIC_STATE_DEPTH_BIAS;
constexpr auto DynamicStateBlendConstants                      = VK_DYNAMIC_STATE_BLEND_CONSTANTS;
constexpr auto DynamicStateDepthBounds                         = VK_DYNAMIC_STATE_DEPTH_BOUNDS;
constexpr auto DynamicStateStencilCompareMask                  = VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK;
constexpr auto DynamicStateStencilWriteMask                    = VK_DYNAMIC_STATE_STENCIL_WRITE_MASK;
constexpr auto DynamicStateStencilReference                    = VK_DYNAMIC_STATE_STENCIL_REFERENCE;
constexpr auto DynamicStateCullMode                            = VK_DYNAMIC_STATE_CULL_MODE;
constexpr auto DynamicStateCullModeEXT                         = VK_DYNAMIC_STATE_CULL_MODE_EXT;
constexpr auto DynamicStateFrontFace                           = VK_DYNAMIC_STATE_FRONT_FACE;
constexpr auto DynamicStateFrontFaceEXT                        = VK_DYNAMIC_STATE_FRONT_FACE_EXT;
constexpr auto DynamicStatePrimitiveTopology                   = VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY;
constexpr auto DynamicStatePrimitiveTopologyEXT                = VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT;
constexpr auto DynamicStateViewportWithCount                   = VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT;
constexpr auto DynamicStateViewportWithCountEXT                = VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT;
constexpr auto DynamicStateScissorWithCount                    = VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT;
constexpr auto DynamicStateScissorWithCountEXT                 = VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT;
constexpr auto DynamicStateVertexInputBindingStride            = VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE;
constexpr auto DynamicStateVertexInputBindingStrideEXT         = VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT;
constexpr auto DynamicStateDepthTestEnable                     = VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE;
constexpr auto DynamicStateDepthTestEnableEXT                  = VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT;
constexpr auto DynamicStateDepthWriteEnable                    = VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE;
constexpr auto DynamicStateDepthWriteEnableEXT                 = VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT;
constexpr auto DynamicStateDepthCompareOp                      = VK_DYNAMIC_STATE_DEPTH_COMPARE_OP;
constexpr auto DynamicStateDepthCompareOpEXT                   = VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT;
constexpr auto DynamicStateDepthBoundsTestEnable               = VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE;
constexpr auto DynamicStateDepthBoundsTestEnableEXT            = VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT;
constexpr auto DynamicStateStencilTestEnable                   = VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE;
constexpr auto DynamicStateStencilTestEnableEXT                = VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT;
constexpr auto DynamicStateStencilOp                           = VK_DYNAMIC_STATE_STENCIL_OP;
constexpr auto DynamicStateStencilOpEXT                        = VK_DYNAMIC_STATE_STENCIL_OP_EXT;
constexpr auto DynamicStateRasterizerDiscardEnable             = VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE;
constexpr auto DynamicStateRasterizerDiscardEnableEXT          = VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE_EXT;
constexpr auto DynamicStateDepthBiasEnable                     = VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE;
constexpr auto DynamicStateDepthBiasEnableEXT                  = VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE_EXT;
constexpr auto DynamicStatePrimitiveRestartEnable              = VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE;
constexpr auto DynamicStatePrimitiveRestartEnableEXT           = VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE_EXT;
constexpr auto DynamicStateLineStipple                         = VK_DYNAMIC_STATE_LINE_STIPPLE;
constexpr auto DynamicStateLineStippleEXT                      = VK_DYNAMIC_STATE_LINE_STIPPLE_EXT;
constexpr auto DynamicStateLineStippleKHR                      = VK_DYNAMIC_STATE_LINE_STIPPLE_KHR;
constexpr auto DynamicStateViewportWScalingNV                  = VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV;
constexpr auto DynamicStateDiscardRectangleEXT                 = VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT;
constexpr auto DynamicStateDiscardRectangleEnableEXT           = VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT;
constexpr auto DynamicStateDiscardRectangleModeEXT             = VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT;
constexpr auto DynamicStateSampleLocationsEXT                  = VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT;
constexpr auto DynamicStateRayTracingPipelineStackSizeKHR      = VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR;
constexpr auto DynamicStateViewportShadingRatePaletteNV        = VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV;
constexpr auto DynamicStateViewportCoarseSampleOrderNV         = VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV;
constexpr auto DynamicStateExclusiveScissorEnableNV            = VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV;
constexpr auto DynamicStateExclusiveScissorNV                  = VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV;
constexpr auto DynamicStateFragmentShadingRateKHR              = VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR;
constexpr auto DynamicStateVertexInputEXT                      = VK_DYNAMIC_STATE_VERTEX_INPUT_EXT;
constexpr auto DynamicStatePatchControlPointsEXT               = VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT;
constexpr auto DynamicStateLogicOpEXT                          = VK_DYNAMIC_STATE_LOGIC_OP_EXT;
constexpr auto DynamicStateColorWriteEnableEXT                 = VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT;
constexpr auto DynamicStateDepthClampEnableEXT                 = VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT;
constexpr auto DynamicStatePolygonModeEXT                      = VK_DYNAMIC_STATE_POLYGON_MODE_EXT;
constexpr auto DynamicStateRasterizationSamplesEXT             = VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT;
constexpr auto DynamicStateSampleMaskEXT                       = VK_DYNAMIC_STATE_SAMPLE_MASK_EXT;
constexpr auto DynamicStateAlphaToCoverageEnableEXT            = VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT;
constexpr auto DynamicStateAlphaToOneEnableEXT                 = VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT;
constexpr auto DynamicStateLogicOpEnableEXT                    = VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT;
constexpr auto DynamicStateColorBlendEnableEXT                 = VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT;
constexpr auto DynamicStateColorBlendEquationEXT               = VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT;
constexpr auto DynamicStateColorWriteMaskEXT                   = VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT;
constexpr auto DynamicStateTessellationDomainOriginEXT         = VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT;
constexpr auto DynamicStateRasterizationStreamEXT              = VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT;
constexpr auto DynamicStateConservativeRasterizationModeEXT    = VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT;
constexpr auto DynamicStateExtraPrimitiveOverestimationSizeEXT = VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT;
constexpr auto DynamicStateDepthClipEnableEXT                  = VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT;
constexpr auto DynamicStateSampleLocationsEnableEXT            = VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT;
constexpr auto DynamicStateColorBlendAdvancedEXT               = VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT;
constexpr auto DynamicStateProvokingVertexModeEXT              = VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT;
constexpr auto DynamicStateLineRasterizationModeEXT            = VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT;
constexpr auto DynamicStateLineStippleEnableEXT                = VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT;
constexpr auto DynamicStateDepthClipNegativeOneToOneEXT        = VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT;
constexpr auto DynamicStateViewportWScalingEnableNV            = VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV;
constexpr auto DynamicStateViewportSwizzleNV                   = VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV;
constexpr auto DynamicStateCoverageToColorEnableNV             = VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV;
constexpr auto DynamicStateCoverageToColorLocationNV           = VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV;
constexpr auto DynamicStateCoverageModulationModeNV            = VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV;
constexpr auto DynamicStateCoverageModulationTableEnableNV     = VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV;
constexpr auto DynamicStateCoverageModulationTableNV           = VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV;
constexpr auto DynamicStateShadingRateImageEnableNV            = VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV;
constexpr auto DynamicStateRepresentativeFragmentTestEnableNV  = VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV;
constexpr auto DynamicStateCoverageReductionModeNV             = VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV;
constexpr auto DynamicStateAttachmentFeedbackLoopEnableEXT     = VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT;
constexpr auto DynamicStateDepthClampRangeEXT                  = VK_DYNAMIC_STATE_DEPTH_CLAMP_RANGE_EXT;
//};

//enum FrontFace {
constexpr auto FrontFaceCounterClockwise = VK_FRONT_FACE_COUNTER_CLOCKWISE;
constexpr auto FrontFaceClockwise        = VK_FRONT_FACE_CLOCKWISE;
//};

//enum LogicOp {
constexpr auto LogicOpClear        = VK_LOGIC_OP_CLEAR;
constexpr auto LogicOpAnd          = VK_LOGIC_OP_AND;
constexpr auto LogicOpAndReverse   = VK_LOGIC_OP_AND_REVERSE;
constexpr auto LogicOpCopy         = VK_LOGIC_OP_COPY;
constexpr auto LogicOpAndInverted  = VK_LOGIC_OP_AND_INVERTED;
constexpr auto LogicOpNoOp         = VK_LOGIC_OP_NO_OP;
constexpr auto LogicOpXor          = VK_LOGIC_OP_XOR;
constexpr auto LogicOpOr           = VK_LOGIC_OP_OR;
constexpr auto LogicOpNor          = VK_LOGIC_OP_NOR;
constexpr auto LogicOpEquivalent   = VK_LOGIC_OP_EQUIVALENT;
constexpr auto LogicOpInvert       = VK_LOGIC_OP_INVERT;
constexpr auto LogicOpOrReverse    = VK_LOGIC_OP_OR_REVERSE;
constexpr auto LogicOpCopyInverted = VK_LOGIC_OP_COPY_INVERTED;
constexpr auto LogicOpOrInverted   = VK_LOGIC_OP_OR_INVERTED;
constexpr auto LogicOpNand         = VK_LOGIC_OP_NAND;
constexpr auto LogicOpSet          = VK_LOGIC_OP_SET;
//};

//enum PipelineCreate {
constexpr auto PipelineCreateDisableOptimizationBit                                                = VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT;
constexpr auto PipelineCreateAllowDerivativesBit                                                   = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
constexpr auto PipelineCreateDerivativeBit                                                         = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
constexpr auto PipelineCreateViewIndexFromDeviceIndexBit                                           = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT;
constexpr auto PipelineCreateViewIndexFromDeviceIndexBitKHR                                        = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR;
constexpr auto PipelineCreateDispatchBaseBit                                                       = VK_PIPELINE_CREATE_DISPATCH_BASE_BIT;
constexpr auto PipelineCreateDispatchBaseBitKHR                                                    = VK_PIPELINE_CREATE_DISPATCH_BASE_BIT_KHR;
constexpr auto PipelineCreateFailOnPipelineCompileRequiredBit                                      = VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT;
constexpr auto PipelineCreateFailOnPipelineCompileRequiredBitEXT                                   = VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT;
constexpr auto PipelineCreateEarlyReturnOnFailureBit                                               = VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT;
constexpr auto PipelineCreateEarlyReturnOnFailureBitEXT                                            = VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT;
constexpr auto PipelineCreateNoProtectedAccessBit                                                  = VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT;
constexpr auto PipelineCreateNoProtectedAccessBitEXT                                               = VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT;
constexpr auto PipelineCreateProtectedAccessOnlyBit                                                = VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT;
constexpr auto PipelineCreateProtectedAccessOnlyBitEXT                                             = VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT;
constexpr auto PipelineCreateRayTracingNoNullAnyHitShadersBitKHR                                   = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR;
constexpr auto PipelineCreateRayTracingNoNullClosestHitShadersBitKHR                               = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR;
constexpr auto PipelineCreateRayTracingNoNullMissShadersBitKHR                                     = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR;
constexpr auto PipelineCreateRayTracingNoNullIntersectionShadersBitKHR                             = VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR;
constexpr auto PipelineCreateRayTracingSkipTrianglesBitKHR                                         = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR;
constexpr auto PipelineCreateRayTracingSkipAabbsBitKHR                                             = VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR;
constexpr auto PipelineCreateRayTracingShaderGroupHandleCaptureReplayBitKHR                        = VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;
constexpr auto PipelineCreateDeferCompileBitNV                                                     = VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV;
constexpr auto PipelineCreateRenderingFragmentDensityMapAttachmentBitEXT                           = VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT;
constexpr auto PipelineCreateVkPipelineRasterizationStateCreateFragmentDensityMapAttachmentBitEXT  = VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT;
constexpr auto PipelineCreateRenderingFragmentShadingRateAttachmentBitKHR                          = VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto PipelineCreateVkPipelineRasterizationStateCreateFragmentShadingRateAttachmentBitKHR = VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto PipelineCreateCaptureStatisticsBitKHR                                               = VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR;
constexpr auto PipelineCreateCaptureInternalRepresentationsBitKHR                                  = VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR;
constexpr auto PipelineCreateIndirectBindableBitNV                                                 = VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV;
constexpr auto PipelineCreateLibraryBitKHR                                                         = VK_PIPELINE_CREATE_LIBRARY_BIT_KHR;
constexpr auto PipelineCreateDescriptorBufferBitEXT                                                = VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto PipelineCreateRetainLinkTimeOptimizationInfoBitEXT                                  = VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT;
constexpr auto PipelineCreateLinkTimeOptimizationBitEXT                                            = VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT;
constexpr auto PipelineCreateRayTracingAllowMotionBitNV                                            = VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV;
constexpr auto PipelineCreateColorAttachmentFeedbackLoopBitEXT                                     = VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT;
constexpr auto PipelineCreateDepthStencilAttachmentFeedbackLoopBitEXT                              = VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT;
constexpr auto PipelineCreateRayTracingOpacityMicromapBitEXT                                       = VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto PipelineCreateRayTracingDisplacementMicromapBitNV                                   = VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
//};

//enum PipelineShaderStageCreate {
constexpr auto PipelineShaderStageCreateAllowVaryingSubgroupSizeBit    = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT;
constexpr auto PipelineShaderStageCreateAllowVaryingSubgroupSizeBitEXT = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT;
constexpr auto PipelineShaderStageCreateRequireFullSubgroupsBit        = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT;
constexpr auto PipelineShaderStageCreateRequireFullSubgroupsBitEXT     = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT;
//};

//enum PolygonMode {
constexpr auto PolygonModeFill            = VK_POLYGON_MODE_FILL;
constexpr auto PolygonModeLine            = VK_POLYGON_MODE_LINE;
constexpr auto PolygonModePoint           = VK_POLYGON_MODE_POINT;
constexpr auto PolygonModeFillRectangleNV = VK_POLYGON_MODE_FILL_RECTANGLE_NV;
//};

//enum PrimitiveTopology {
constexpr auto PrimitiveTopologyPointList                  = VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
constexpr auto PrimitiveTopologyLineList                   = VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
constexpr auto PrimitiveTopologyLineStrip                  = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
constexpr auto PrimitiveTopologyTriangleList               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
constexpr auto PrimitiveTopologyTriangleStrip              = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
constexpr auto PrimitiveTopologyTriangleFan                = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
constexpr auto PrimitiveTopologyLineListWithAdjacency      = VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
constexpr auto PrimitiveTopologyLineStripWithAdjacency     = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
constexpr auto PrimitiveTopologyTriangleListWithAdjacency  = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
constexpr auto PrimitiveTopologyTriangleStripWithAdjacency = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
constexpr auto PrimitiveTopologyPatchList                  = VK_PRIMITIVE_TOPOLOGY_PATCH_LIST;
//};

//enum ShaderStage {
constexpr auto ShaderStageVertexBit                 = VK_SHADER_STAGE_VERTEX_BIT;
constexpr auto ShaderStageTessellationControlBit    = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
constexpr auto ShaderStageTessellationEvaluationBit = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
constexpr auto ShaderStageGeometryBit               = VK_SHADER_STAGE_GEOMETRY_BIT;
constexpr auto ShaderStageFragmentBit               = VK_SHADER_STAGE_FRAGMENT_BIT;
constexpr auto ShaderStageComputeBit                = VK_SHADER_STAGE_COMPUTE_BIT;
constexpr auto ShaderStageAllGraphics               = VK_SHADER_STAGE_ALL_GRAPHICS;
constexpr auto ShaderStageAll                       = VK_SHADER_STAGE_ALL;
constexpr auto ShaderStageRaygenBitKHR              = VK_SHADER_STAGE_RAYGEN_BIT_KHR;
constexpr auto ShaderStageRaygenBitNV               = VK_SHADER_STAGE_RAYGEN_BIT_NV;
constexpr auto ShaderStageAnyHitBitKHR              = VK_SHADER_STAGE_ANY_HIT_BIT_KHR;
constexpr auto ShaderStageAnyHitBitNV               = VK_SHADER_STAGE_ANY_HIT_BIT_NV;
constexpr auto ShaderStageClosestHitBitKHR          = VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR;
constexpr auto ShaderStageClosestHitBitNV           = VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV;
constexpr auto ShaderStageMissBitKHR                = VK_SHADER_STAGE_MISS_BIT_KHR;
constexpr auto ShaderStageMissBitNV                 = VK_SHADER_STAGE_MISS_BIT_NV;
constexpr auto ShaderStageIntersectionBitKHR        = VK_SHADER_STAGE_INTERSECTION_BIT_KHR;
constexpr auto ShaderStageIntersectionBitNV         = VK_SHADER_STAGE_INTERSECTION_BIT_NV;
constexpr auto ShaderStageCallableBitKHR            = VK_SHADER_STAGE_CALLABLE_BIT_KHR;
constexpr auto ShaderStageCallableBitNV             = VK_SHADER_STAGE_CALLABLE_BIT_NV;
constexpr auto ShaderStageTaskBitEXT                = VK_SHADER_STAGE_TASK_BIT_EXT;
constexpr auto ShaderStageTaskBitNV                 = VK_SHADER_STAGE_TASK_BIT_NV;
constexpr auto ShaderStageMeshBitEXT                = VK_SHADER_STAGE_MESH_BIT_EXT;
constexpr auto ShaderStageMeshBitNV                 = VK_SHADER_STAGE_MESH_BIT_NV;
constexpr auto ShaderStageSubpassShadingBitHUAWEI   = VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI;
constexpr auto ShaderStageClusterCullingBitHUAWEI   = VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI;
//};

//enum StencilOp {
constexpr auto StencilOpKeep              = VK_STENCIL_OP_KEEP;
constexpr auto StencilOpZero              = VK_STENCIL_OP_ZERO;
constexpr auto StencilOpReplace           = VK_STENCIL_OP_REPLACE;
constexpr auto StencilOpIncrementAndClamp = VK_STENCIL_OP_INCREMENT_AND_CLAMP;
constexpr auto StencilOpDecrementAndClamp = VK_STENCIL_OP_DECREMENT_AND_CLAMP;
constexpr auto StencilOpInvert            = VK_STENCIL_OP_INVERT;
constexpr auto StencilOpIncrementAndWrap  = VK_STENCIL_OP_INCREMENT_AND_WRAP;
constexpr auto StencilOpDecrementAndWrap  = VK_STENCIL_OP_DECREMENT_AND_WRAP;
//};

//enum VertexInputRate {
constexpr auto VertexInputRateVertex   = VK_VERTEX_INPUT_RATE_VERTEX;
constexpr auto VertexInputRateInstance = VK_VERTEX_INPUT_RATE_INSTANCE;
//};

//enum PipelineColorBlendStateCreate {
constexpr auto PipelineColorBlendStateCreateRasterizationOrderAttachmentAccessBitEXT = VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT;
constexpr auto PipelineColorBlendStateCreateRasterizationOrderAttachmentAccessBitARM = VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_ARM;
//};

//enum PipelineDepthStencilStateCreate {
constexpr auto PipelineDepthStencilStateCreateRasterizationOrderAttachmentDepthAccessBitEXT   = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT;
constexpr auto PipelineDepthStencilStateCreateRasterizationOrderAttachmentDepthAccessBitARM   = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_ARM;
constexpr auto PipelineDepthStencilStateCreateRasterizationOrderAttachmentStencilAccessBitEXT = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT;
constexpr auto PipelineDepthStencilStateCreateRasterizationOrderAttachmentStencilAccessBitARM = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_ARM;
//};

//enum PipelineDynamicStateCreate {
//};

//enum PipelineInputAssemblyStateCreate {
//};

//enum PipelineLayoutCreate {
constexpr auto PipelineLayoutCreateIndependentSetsBitEXT = VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT;
//};

//enum PipelineMultisampleStateCreate {
//};

//enum PipelineRasterizationStateCreate {
//};

//enum PipelineTessellationStateCreate {
//};

//enum PipelineVertexInputStateCreate {
//};

//enum PipelineViewportStateCreate {
//};

//enum BorderColor {
constexpr auto BorderColorFloatTransparentBlack = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
constexpr auto BorderColorIntTransparentBlack   = VK_BORDER_COLOR_INT_TRANSPARENT_BLACK;
constexpr auto BorderColorFloatOpaqueBlack      = VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK;
constexpr auto BorderColorIntOpaqueBlack        = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
constexpr auto BorderColorFloatOpaqueWhite      = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE;
constexpr auto BorderColorIntOpaqueWhite        = VK_BORDER_COLOR_INT_OPAQUE_WHITE;
constexpr auto BorderColorFloatCustomEXT        = VK_BORDER_COLOR_FLOAT_CUSTOM_EXT;
constexpr auto BorderColorIntCustomEXT          = VK_BORDER_COLOR_INT_CUSTOM_EXT;
//};

//enum Filter {
constexpr auto FilterNearest  = VK_FILTER_NEAREST;
constexpr auto FilterLinear   = VK_FILTER_LINEAR;
constexpr auto FilterCubicEXT = VK_FILTER_CUBIC_EXT;
constexpr auto FilterCubicIMG = VK_FILTER_CUBIC_IMG;
//};

//enum SamplerAddressMode {
constexpr auto SamplerAddressModeRepeat               = VK_SAMPLER_ADDRESS_MODE_REPEAT;
constexpr auto SamplerAddressModeMirroredRepeat       = VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
constexpr auto SamplerAddressModeClampToEdge          = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
constexpr auto SamplerAddressModeClampToBorder        = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
constexpr auto SamplerAddressModeMirrorClampToEdge    = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE;
constexpr auto SamplerAddressModeMirrorClampToEdgeKHR = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR;
//};

//enum SamplerCreate {
constexpr auto SamplerCreateSubsampledBitEXT                     = VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT;
constexpr auto SamplerCreateSubsampledCoarseReconstructionBitEXT = VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT;
constexpr auto SamplerCreateDescriptorBufferCaptureReplayBitEXT  = VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
constexpr auto SamplerCreateNonSeamlessCubeMapBitEXT             = VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT;
constexpr auto SamplerCreateImageProcessingBitQCOM               = VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM;
//};

//enum SamplerMipmapMode {
constexpr auto SamplerMipmapModeNearest = VK_SAMPLER_MIPMAP_MODE_NEAREST;
constexpr auto SamplerMipmapModeLinear  = VK_SAMPLER_MIPMAP_MODE_LINEAR;
//};

//enum DescriptorPoolCreate {
constexpr auto DescriptorPoolCreateFreeDescriptorSetBit          = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
constexpr auto DescriptorPoolCreateUpdateAfterBindBit            = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
constexpr auto DescriptorPoolCreateUpdateAfterBindBitEXT         = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT;
constexpr auto DescriptorPoolCreateHostOnlyBitEXT                = VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT;
constexpr auto DescriptorPoolCreateHostOnlyBitVALVE              = VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_VALVE;
constexpr auto DescriptorPoolCreateAllowOverallocationSetsBitNV  = VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV;
constexpr auto DescriptorPoolCreateAllowOverallocationPoolsBitNV = VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV;
//};

//enum DescriptorSetLayoutCreate {
constexpr auto DescriptorSetLayoutCreateUpdateAfterBindPoolBit          = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT;
constexpr auto DescriptorSetLayoutCreateUpdateAfterBindPoolBitEXT       = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT;
constexpr auto DescriptorSetLayoutCreatePushDescriptorBit               = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT;
constexpr auto DescriptorSetLayoutCreatePushDescriptorBitKHR            = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR;
constexpr auto DescriptorSetLayoutCreateDescriptorBufferBitEXT          = VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto DescriptorSetLayoutCreateEmbeddedImmutableSamplersBitEXT = VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT;
constexpr auto DescriptorSetLayoutCreateIndirectBindableBitNV           = VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV;
constexpr auto DescriptorSetLayoutCreateHostOnlyPoolBitEXT              = VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT;
constexpr auto DescriptorSetLayoutCreateHostOnlyPoolBitVALVE            = VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_VALVE;
constexpr auto DescriptorSetLayoutCreatePerStageBitNV                   = VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV;
//};

//enum DescriptorType {
constexpr auto DescriptorTypeSampler                            = VK_DESCRIPTOR_TYPE_SAMPLER;
constexpr auto DescriptorTypeCombinedImageSampler               = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
constexpr auto DescriptorTypeSampledImage                       = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
constexpr auto DescriptorTypeStorageImage                       = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
constexpr auto DescriptorTypeUniformTexelBuffer                 = VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;
constexpr auto DescriptorTypeStorageTexelBuffer                 = VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;
constexpr auto DescriptorTypeUniformBuffer                      = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
constexpr auto DescriptorTypeStorageBuffer                      = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
constexpr auto DescriptorTypeUniformBufferDynamic               = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
constexpr auto DescriptorTypeStorageBufferDynamic               = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC;
constexpr auto DescriptorTypeInputAttachment                    = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;
constexpr auto DescriptorTypeInlineUniformBlock                 = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK;
constexpr auto DescriptorTypeInlineUniformBlockEXT              = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT;
constexpr auto DescriptorTypeAccelerationStructureKHR           = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR;
constexpr auto DescriptorTypeAccelerationStructureNV            = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV;
constexpr auto DescriptorTypeSampleWeightImageQCOM              = VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM;
constexpr auto DescriptorTypeBlockMatchImageQCOM                = VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM;
constexpr auto DescriptorTypeTensorARM                          = VK_DESCRIPTOR_TYPE_TENSOR_ARM;
constexpr auto DescriptorTypeMutableEXT                         = VK_DESCRIPTOR_TYPE_MUTABLE_EXT;
constexpr auto DescriptorTypeMutableVALVE                       = VK_DESCRIPTOR_TYPE_MUTABLE_VALVE;
constexpr auto DescriptorTypePartitionedAccelerationStructureNV = VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV;
//};

//enum DescriptorPoolReset {
//};

//enum Access {
constexpr auto AccessIndirectCommandReadBit                  = VK_ACCESS_INDIRECT_COMMAND_READ_BIT;
constexpr auto AccessIndexReadBit                            = VK_ACCESS_INDEX_READ_BIT;
constexpr auto AccessVertexAttributeReadBit                  = VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT;
constexpr auto AccessUniformReadBit                          = VK_ACCESS_UNIFORM_READ_BIT;
constexpr auto AccessInputAttachmentReadBit                  = VK_ACCESS_INPUT_ATTACHMENT_READ_BIT;
constexpr auto AccessShaderReadBit                           = VK_ACCESS_SHADER_READ_BIT;
constexpr auto AccessShaderWriteBit                          = VK_ACCESS_SHADER_WRITE_BIT;
constexpr auto AccessColorAttachmentReadBit                  = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT;
constexpr auto AccessColorAttachmentWriteBit                 = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
constexpr auto AccessDepthStencilAttachmentReadBit           = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT;
constexpr auto AccessDepthStencilAttachmentWriteBit          = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
constexpr auto AccessTransferReadBit                         = VK_ACCESS_TRANSFER_READ_BIT;
constexpr auto AccessTransferWriteBit                        = VK_ACCESS_TRANSFER_WRITE_BIT;
constexpr auto AccessHostReadBit                             = VK_ACCESS_HOST_READ_BIT;
constexpr auto AccessHostWriteBit                            = VK_ACCESS_HOST_WRITE_BIT;
constexpr auto AccessMemoryReadBit                           = VK_ACCESS_MEMORY_READ_BIT;
constexpr auto AccessMemoryWriteBit                          = VK_ACCESS_MEMORY_WRITE_BIT;
constexpr auto AccessNone                                    = VK_ACCESS_NONE;
constexpr auto AccessNoneKHR                                 = VK_ACCESS_NONE_KHR;
constexpr auto AccessTransformFeedbackWriteBitEXT            = VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT;
constexpr auto AccessTransformFeedbackCounterReadBitEXT      = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT;
constexpr auto AccessTransformFeedbackCounterWriteBitEXT     = VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT;
constexpr auto AccessConditionalRenderingReadBitEXT          = VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT;
constexpr auto AccessColorAttachmentReadNoncoherentBitEXT    = VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT;
constexpr auto AccessAccelerationStructureReadBitKHR         = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR;
constexpr auto AccessAccelerationStructureReadBitNV          = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_NV;
constexpr auto AccessAccelerationStructureWriteBitKHR        = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR;
constexpr auto AccessAccelerationStructureWriteBitNV         = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_NV;
constexpr auto AccessFragmentDensityMapReadBitEXT            = VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT;
constexpr auto AccessFragmentShadingRateAttachmentReadBitKHR = VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR;
constexpr auto AccessShadingRateImageReadBitNV               = VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV;
constexpr auto AccessCommandPreprocessReadBitEXT             = VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_EXT;
constexpr auto AccessCommandPreprocessReadBitNV              = VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV;
constexpr auto AccessCommandPreprocessWriteBitEXT            = VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_EXT;
constexpr auto AccessCommandPreprocessWriteBitNV             = VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV;
//};

//enum AttachmentDescription {
constexpr auto AttachmentDescriptionMayAliasBit = VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT;
//};

//enum AttachmentLoadOp {
constexpr auto AttachmentLoadOpLoad     = VK_ATTACHMENT_LOAD_OP_LOAD;
constexpr auto AttachmentLoadOpClear    = VK_ATTACHMENT_LOAD_OP_CLEAR;
constexpr auto AttachmentLoadOpDontCare = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
constexpr auto AttachmentLoadOpNone     = VK_ATTACHMENT_LOAD_OP_NONE;
constexpr auto AttachmentLoadOpNoneEXT  = VK_ATTACHMENT_LOAD_OP_NONE_EXT;
constexpr auto AttachmentLoadOpNoneKHR  = VK_ATTACHMENT_LOAD_OP_NONE_KHR;
//};

//enum AttachmentStoreOp {
constexpr auto AttachmentStoreOpStore    = VK_ATTACHMENT_STORE_OP_STORE;
constexpr auto AttachmentStoreOpDontCare = VK_ATTACHMENT_STORE_OP_DONT_CARE;
constexpr auto AttachmentStoreOpNone     = VK_ATTACHMENT_STORE_OP_NONE;
constexpr auto AttachmentStoreOpNoneKHR  = VK_ATTACHMENT_STORE_OP_NONE_KHR;
constexpr auto AttachmentStoreOpNoneQCOM = VK_ATTACHMENT_STORE_OP_NONE_QCOM;
constexpr auto AttachmentStoreOpNoneEXT  = VK_ATTACHMENT_STORE_OP_NONE_EXT;
//};

//enum Dependency {
constexpr auto DependencyByRegionBit                                    = VK_DEPENDENCY_BY_REGION_BIT;
constexpr auto DependencyDeviceGroupBit                                 = VK_DEPENDENCY_DEVICE_GROUP_BIT;
constexpr auto DependencyDeviceGroupBitKHR                              = VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR;
constexpr auto DependencyViewLocalBit                                   = VK_DEPENDENCY_VIEW_LOCAL_BIT;
constexpr auto DependencyViewLocalBitKHR                                = VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR;
constexpr auto DependencyFeedbackLoopBitEXT                             = VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT;
constexpr auto DependencyQueueFamilyOwnershipTransferUseAllStagesBitKHR = VK_DEPENDENCY_QUEUE_FAMILY_OWNERSHIP_TRANSFER_USE_ALL_STAGES_BIT_KHR;
constexpr auto DependencyAsymmetricEventBitKHR                          = VK_DEPENDENCY_ASYMMETRIC_EVENT_BIT_KHR;
//};

//enum FramebufferCreate {
constexpr auto FramebufferCreateImagelessBit    = VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT;
constexpr auto FramebufferCreateImagelessBitKHR = VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT_KHR;
//};

//enum PipelineBindPoint {
constexpr auto PipelineBindPointGraphics = VK_PIPELINE_BIND_POINT_GRAPHICS;
constexpr auto PipelineBindPointCompute  = VK_PIPELINE_BIND_POINT_COMPUTE;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto PipelineBindPointExecutionGraphAMDX = VK_PIPELINE_BIND_POINT_EXECUTION_GRAPH_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto PipelineBindPointRayTracingKHR        = VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR;
constexpr auto PipelineBindPointRayTracingNV         = VK_PIPELINE_BIND_POINT_RAY_TRACING_NV;
constexpr auto PipelineBindPointSubpassShadingHUAWEI = VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI;
constexpr auto PipelineBindPointDataGraphARM         = VK_PIPELINE_BIND_POINT_DATA_GRAPH_ARM;
//};

//enum RenderPassCreate {
constexpr auto RenderPassCreateTransformBitQCOM                = VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM;
constexpr auto RenderPassCreatePerLayerFragmentDensityBitVALVE = VK_RENDER_PASS_CREATE_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE;
//};

//enum SubpassDescription {
constexpr auto SubpassDescriptionPerViewAttributesBitNVX                         = VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX;
constexpr auto SubpassDescriptionPerViewPositionXOnlyBitNVX                      = VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX;
constexpr auto SubpassDescriptionFragmentRegionBitQCOM                           = VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM;
constexpr auto SubpassDescriptionShaderResolveBitQCOM                            = VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM;
constexpr auto SubpassDescriptionTileShadingApronBitQCOM                         = VK_SUBPASS_DESCRIPTION_TILE_SHADING_APRON_BIT_QCOM;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentColorAccessBitEXT   = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentColorAccessBitARM   = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_ARM;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentDepthAccessBitEXT   = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentDepthAccessBitARM   = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_ARM;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentStencilAccessBitEXT = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT;
constexpr auto SubpassDescriptionRasterizationOrderAttachmentStencilAccessBitARM = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_ARM;
constexpr auto SubpassDescriptionEnableLegacyDitheringBitEXT                     = VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT;
//};

//enum CommandPoolCreate {
constexpr auto CommandPoolCreateTransientBit          = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
constexpr auto CommandPoolCreateResetCommandBufferBit = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
constexpr auto CommandPoolCreateProtectedBit          = VK_COMMAND_POOL_CREATE_PROTECTED_BIT;
//};

//enum CommandPoolReset {
constexpr auto CommandPoolResetReleaseResourcesBit = VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT;
//};

//enum CommandBufferLevel {
constexpr auto CommandBufferLevelPrimary   = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
constexpr auto CommandBufferLevelSecondary = VK_COMMAND_BUFFER_LEVEL_SECONDARY;
//};

//enum CommandBufferReset {
constexpr auto CommandBufferResetReleaseResourcesBit = VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT;
//};

//enum CommandBufferUsage {
constexpr auto CommandBufferUsageOneTimeSubmitBit      = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
constexpr auto CommandBufferUsageRenderPassContinueBit = VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT;
constexpr auto CommandBufferUsageSimultaneousUseBit    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
//};

//enum QueryControl {
constexpr auto QueryControlPreciseBit = VK_QUERY_CONTROL_PRECISE_BIT;
//};

//enum IndexType {
constexpr auto IndexTypeUint16   = VK_INDEX_TYPE_UINT16;
constexpr auto IndexTypeUint32   = VK_INDEX_TYPE_UINT32;
constexpr auto IndexTypeUint8    = VK_INDEX_TYPE_UINT8;
constexpr auto IndexTypeUint8EXT = VK_INDEX_TYPE_UINT8_EXT;
constexpr auto IndexTypeUint8KHR = VK_INDEX_TYPE_UINT8_KHR;
constexpr auto IndexTypeNoneKHR  = VK_INDEX_TYPE_NONE_KHR;
constexpr auto IndexTypeNoneNV   = VK_INDEX_TYPE_NONE_NV;
//};

//enum StencilFace {
constexpr auto StencilFaceFrontBit                 = VK_STENCIL_FACE_FRONT_BIT;
constexpr auto StencilFaceBackBit                  = VK_STENCIL_FACE_BACK_BIT;
constexpr auto StencilFaceFrontAndBack             = VK_STENCIL_FACE_FRONT_AND_BACK;
constexpr auto StencilFaceVkStencilFrontAndBack    = VK_STENCIL_FRONT_AND_BACK;
//};

//enum SubpassContents {
constexpr auto SubpassContentsInline                              = VK_SUBPASS_CONTENTS_INLINE;
constexpr auto SubpassContentsSecondaryCommandBuffers             = VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS;
constexpr auto SubpassContentsInlineAndSecondaryCommandBuffersKHR = VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_KHR;
constexpr auto SubpassContentsInlineAndSecondaryCommandBuffersEXT = VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT;
//};

//enum SubgroupFeature {
constexpr auto SubgroupFeatureBasicBit              = VK_SUBGROUP_FEATURE_BASIC_BIT;
constexpr auto SubgroupFeatureVoteBit               = VK_SUBGROUP_FEATURE_VOTE_BIT;
constexpr auto SubgroupFeatureArithmeticBit         = VK_SUBGROUP_FEATURE_ARITHMETIC_BIT;
constexpr auto SubgroupFeatureBallotBit             = VK_SUBGROUP_FEATURE_BALLOT_BIT;
constexpr auto SubgroupFeatureShuffleBit            = VK_SUBGROUP_FEATURE_SHUFFLE_BIT;
constexpr auto SubgroupFeatureShuffleRelativeBit    = VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT;
constexpr auto SubgroupFeatureClusteredBit          = VK_SUBGROUP_FEATURE_CLUSTERED_BIT;
constexpr auto SubgroupFeatureQuadBit               = VK_SUBGROUP_FEATURE_QUAD_BIT;
constexpr auto SubgroupFeatureRotateBit             = VK_SUBGROUP_FEATURE_ROTATE_BIT;
constexpr auto SubgroupFeatureRotateBitKHR          = VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR;
constexpr auto SubgroupFeatureRotateClusteredBit    = VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT;
constexpr auto SubgroupFeatureRotateClusteredBitKHR = VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR;
constexpr auto SubgroupFeaturePartitionedBitNV      = VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV;
//};

//enum PeerMemoryFeature {
constexpr auto PeerMemoryFeatureCopySrcBit    = VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT;
constexpr auto PeerMemoryFeatureCopyDstBit    = VK_PEER_MEMORY_FEATURE_COPY_DST_BIT;
constexpr auto PeerMemoryFeatureGenericSrcBit = VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT;
constexpr auto PeerMemoryFeatureGenericDstBit = VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT;
//};

//enum MemoryAllocate {
constexpr auto MemoryAllocateDeviceMaskBit                 = VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT;
constexpr auto MemoryAllocateDeviceAddressBit              = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;
constexpr auto MemoryAllocateDeviceAddressCaptureReplayBit = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
constexpr auto MemoryAllocateZeroInitializeBitEXT          = VK_MEMORY_ALLOCATE_ZERO_INITIALIZE_BIT_EXT;
//};

//enum CommandPoolTrim {
//};

//enum PointClippingBehavior {
constexpr auto PointClippingBehaviorAllClipPlanes      = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES;
constexpr auto PointClippingBehaviorUserClipPlanesOnly = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY;
//};

//enum TessellationDomainOrigin {
constexpr auto TessellationDomainOriginUpperLeft = VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT;
constexpr auto TessellationDomainOriginLowerLeft = VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT;
//};

//enum SamplerYcbcrModelConversion {
constexpr auto SamplerYcbcrModelConversionRgbIdentity   = VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY;
constexpr auto SamplerYcbcrModelConversionYcbcrIdentity = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY;
constexpr auto SamplerYcbcrModelConversionYcbcr709      = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709;
constexpr auto SamplerYcbcrModelConversionYcbcr601      = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601;
constexpr auto SamplerYcbcrModelConversionYcbcr2020     = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020;
//};

//enum SamplerYcbcrRange {
constexpr auto SamplerYcbcrRangeItuFull   = VK_SAMPLER_YCBCR_RANGE_ITU_FULL;
constexpr auto SamplerYcbcrRangeItuNarrow = VK_SAMPLER_YCBCR_RANGE_ITU_NARROW;
//};

//enum ChromaLocation {
constexpr auto ChromaLocationCositedEven = VK_CHROMA_LOCATION_COSITED_EVEN;
constexpr auto ChromaLocationMidpoint    = VK_CHROMA_LOCATION_MIDPOINT;
//};

//enum DescriptorUpdateTemplateType {
constexpr auto DescriptorUpdateTemplateTypeDescriptorSet   = VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET;
constexpr auto DescriptorUpdateTemplateTypePushDescriptors = VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS;
//};

//enum DescriptorUpdateTemplateCreate {
//};

//enum ExternalMemoryHandleType {
constexpr auto ExternalMemoryHandleTypeOpaqueFdBit                     = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;
constexpr auto ExternalMemoryHandleTypeOpaqueWin32Bit                  = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT;
constexpr auto ExternalMemoryHandleTypeOpaqueWin32KmtBit               = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT;
constexpr auto ExternalMemoryHandleTypeD3D11TextureBit                 = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT;
constexpr auto ExternalMemoryHandleTypeD3D11TextureKmtBit              = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT;
constexpr auto ExternalMemoryHandleTypeD3D12HeapBit                    = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT;
constexpr auto ExternalMemoryHandleTypeD3D12ResourceBit                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT;
constexpr auto ExternalMemoryHandleTypeDmaBufBitEXT                    = VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
constexpr auto ExternalMemoryHandleTypeAndroidHardwareBufferBitANDROID = VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
constexpr auto ExternalMemoryHandleTypeHostAllocationBitEXT            = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT;
constexpr auto ExternalMemoryHandleTypeHostMappedForeignMemoryBitEXT   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT;
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto ExternalMemoryHandleTypeZirconVmoBitFUCHSIA             = VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
constexpr auto ExternalMemoryHandleTypeRdmaAddressBitNV                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
constexpr auto ExternalMemoryHandleTypeScreenBufferBitQNX              = VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX;
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_METAL_EXT
constexpr auto ExternalMemoryHandleTypeMtlbufferBitEXT                 = VK_EXTERNAL_MEMORY_HANDLE_TYPE_MTLBUFFER_BIT_EXT;
constexpr auto ExternalMemoryHandleTypeMtltextureBitEXT                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_MTLTEXTURE_BIT_EXT;
constexpr auto ExternalMemoryHandleTypeMtlheapBitEXT                   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_MTLHEAP_BIT_EXT;
#endif  // VK_USE_PLATFORM_METAL_EXT
//};

//enum ExternalMemoryFeature {
constexpr auto ExternalMemoryFeatureDedicatedOnlyBit = VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT;
constexpr auto ExternalMemoryFeatureExportableBit    = VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT;
constexpr auto ExternalMemoryFeatureImportableBit    = VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT;
//};

//enum ExternalFenceHandleType {
constexpr auto ExternalFenceHandleTypeOpaqueFdBit       = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT;
constexpr auto ExternalFenceHandleTypeOpaqueWin32Bit    = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT;
constexpr auto ExternalFenceHandleTypeOpaqueWin32KmtBit = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT;
constexpr auto ExternalFenceHandleTypeSyncFdBit         = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;
//};

//enum ExternalFenceFeature {
constexpr auto ExternalFenceFeatureExportableBit = VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT;
constexpr auto ExternalFenceFeatureImportableBit = VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT;
//};

//enum FenceImport {
constexpr auto FenceImportTemporaryBit = VK_FENCE_IMPORT_TEMPORARY_BIT;
//};

//enum SemaphoreImport {
constexpr auto SemaphoreImportTemporaryBit = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT;
//};

//enum ExternalSemaphoreHandleType {
constexpr auto ExternalSemaphoreHandleTypeOpaqueFdBit           = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT;
constexpr auto ExternalSemaphoreHandleTypeOpaqueWin32Bit        = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT;
constexpr auto ExternalSemaphoreHandleTypeOpaqueWin32KmtBit     = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT;
constexpr auto ExternalSemaphoreHandleTypeD3D12FenceBit         = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT;
constexpr auto ExternalSemaphoreHandleTypeD3D11FenceBit         = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT;
constexpr auto ExternalSemaphoreHandleTypeSyncFdBit             = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto ExternalSemaphoreHandleTypeZirconEventBitFUCHSIA = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
//};

//enum ExternalSemaphoreFeature {
constexpr auto ExternalSemaphoreFeatureExportableBit = VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT;
constexpr auto ExternalSemaphoreFeatureImportableBit = VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT;
//};

//enum DriverId {
constexpr auto DriverIdAmdProprietary            = VK_DRIVER_ID_AMD_PROPRIETARY;
constexpr auto DriverIdAmdOpenSource             = VK_DRIVER_ID_AMD_OPEN_SOURCE;
constexpr auto DriverIdMesaRadv                  = VK_DRIVER_ID_MESA_RADV;
constexpr auto DriverIdNvidiaProprietary         = VK_DRIVER_ID_NVIDIA_PROPRIETARY;
constexpr auto DriverIdIntelProprietaryWindows   = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS;
constexpr auto DriverIdIntelOpenSourceMESA       = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA;
constexpr auto DriverIdImaginationProprietary    = VK_DRIVER_ID_IMAGINATION_PROPRIETARY;
constexpr auto DriverIdQualcommProprietary       = VK_DRIVER_ID_QUALCOMM_PROPRIETARY;
constexpr auto DriverIdArmProprietary            = VK_DRIVER_ID_ARM_PROPRIETARY;
constexpr auto DriverIdGoogleSwiftshader         = VK_DRIVER_ID_GOOGLE_SWIFTSHADER;
constexpr auto DriverIdGgpProprietary            = VK_DRIVER_ID_GGP_PROPRIETARY;
constexpr auto DriverIdBroadcomProprietary       = VK_DRIVER_ID_BROADCOM_PROPRIETARY;
constexpr auto DriverIdMesaLlvmpipe              = VK_DRIVER_ID_MESA_LLVMPIPE;
constexpr auto DriverIdMoltenvk                  = VK_DRIVER_ID_MOLTENVK;
constexpr auto DriverIdCoreaviProprietary        = VK_DRIVER_ID_COREAVI_PROPRIETARY;
constexpr auto DriverIdJuiceProprietary          = VK_DRIVER_ID_JUICE_PROPRIETARY;
constexpr auto DriverIdVerisiliconProprietary    = VK_DRIVER_ID_VERISILICON_PROPRIETARY;
constexpr auto DriverIdMesaTurnip                = VK_DRIVER_ID_MESA_TURNIP;
constexpr auto DriverIdMesaV3Dv                  = VK_DRIVER_ID_MESA_V3DV;
constexpr auto DriverIdMesaPanvk                 = VK_DRIVER_ID_MESA_PANVK;
constexpr auto DriverIdSamsungProprietary        = VK_DRIVER_ID_SAMSUNG_PROPRIETARY;
constexpr auto DriverIdMesaVenus                 = VK_DRIVER_ID_MESA_VENUS;
constexpr auto DriverIdMesaDozen                 = VK_DRIVER_ID_MESA_DOZEN;
constexpr auto DriverIdMesaNvk                   = VK_DRIVER_ID_MESA_NVK;
constexpr auto DriverIdImaginationOpenSourceMESA = VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA;
constexpr auto DriverIdMesaHoneykrisp            = VK_DRIVER_ID_MESA_HONEYKRISP;
constexpr auto DriverIdVulkanScEmulationOnVulkan = VK_DRIVER_ID_VULKAN_SC_EMULATION_ON_VULKAN;
//};

//enum ShaderFloatControlsIndependence {
constexpr auto ShaderFloatControlsIndependence32BitOnly = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY;
constexpr auto ShaderFloatControlsIndependenceAll       = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL;
constexpr auto ShaderFloatControlsIndependenceNone      = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE;
//};

//enum DescriptorBinding {
constexpr auto DescriptorBindingUpdateAfterBindBit          = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT;
constexpr auto DescriptorBindingUpdateUnusedWhilePendingBit = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT;
constexpr auto DescriptorBindingPartiallyBoundBit           = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT;
constexpr auto DescriptorBindingVariableDescriptorCountBit  = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT;
//};

//enum ResolveMode {
constexpr auto ResolveModeNone       = VK_RESOLVE_MODE_NONE;
constexpr auto ResolveModeSampleZeroBit                      = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT;
constexpr auto ResolveModeAverageBit                         = VK_RESOLVE_MODE_AVERAGE_BIT;
constexpr auto ResolveModeMinBit                             = VK_RESOLVE_MODE_MIN_BIT;
constexpr auto ResolveModeMaxBit                             = VK_RESOLVE_MODE_MAX_BIT;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
constexpr auto ResolveModeExternalFormatDownsampleBitANDROID = VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_BIT_ANDROID;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
//};

//enum SamplerReductionMode {
constexpr auto SamplerReductionModeWeightedAverage               = VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE;
constexpr auto SamplerReductionModeMin                           = VK_SAMPLER_REDUCTION_MODE_MIN;
constexpr auto SamplerReductionModeMax                           = VK_SAMPLER_REDUCTION_MODE_MAX;
constexpr auto SamplerReductionModeWeightedAverageRangeclampQCOM = VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM;
//};

//enum SemaphoreType {
constexpr auto SemaphoreTypeBinary   = VK_SEMAPHORE_TYPE_BINARY;
constexpr auto SemaphoreTypeTimeline = VK_SEMAPHORE_TYPE_TIMELINE;
//};

//enum SemaphoreWait {
constexpr auto SemaphoreWaitAnyBit = VK_SEMAPHORE_WAIT_ANY_BIT;
//};

//enum PipelineCreationFeedback {
constexpr auto PipelineCreationFeedbackValidBit                       = VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT;
constexpr auto PipelineCreationFeedbackApplicationPipelineCacheHitBit = VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT;
constexpr auto PipelineCreationFeedbackBasePipelineAccelerationBit    = VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT;
//};

//enum ToolPurpose {
constexpr auto ToolPurposeValidationBit         = VK_TOOL_PURPOSE_VALIDATION_BIT;
constexpr auto ToolPurposeProfilingBit          = VK_TOOL_PURPOSE_PROFILING_BIT;
constexpr auto ToolPurposeTracingBit            = VK_TOOL_PURPOSE_TRACING_BIT;
constexpr auto ToolPurposeAdditionalFeaturesBit = VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT;
constexpr auto ToolPurposeModifyingFeaturesBit  = VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT;
constexpr auto ToolPurposeDebugReportingBitEXT  = VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT;
constexpr auto ToolPurposeDebugMarkersBitEXT    = VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT;
//};

//enum PrivateDataSlotCreate {
//};

//enum PipelineStage2 : uint64_t {
constexpr auto PipelineStage2None                                = VK_PIPELINE_STAGE_2_NONE;
constexpr auto PipelineStage2TopOfPipeBit                        = VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT;
constexpr auto PipelineStage2DrawIndirectBit                     = VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT;
constexpr auto PipelineStage2VertexInputBit                      = VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT;
constexpr auto PipelineStage2VertexShaderBit                     = VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT;
constexpr auto PipelineStage2TessellationControlShaderBit        = VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT;
constexpr auto PipelineStage2TessellationEvaluationShaderBit     = VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT;
constexpr auto PipelineStage2GeometryShaderBit                   = VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT;
constexpr auto PipelineStage2FragmentShaderBit                   = VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT;
constexpr auto PipelineStage2EarlyFragmentTestsBit               = VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT;
constexpr auto PipelineStage2LateFragmentTestsBit                = VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
constexpr auto PipelineStage2ColorAttachmentOutputBit            = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
constexpr auto PipelineStage2ComputeShaderBit                    = VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT;
constexpr auto PipelineStage2AllTransferBit                      = VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT;
constexpr auto PipelineStage2TransferBit                         = VK_PIPELINE_STAGE_2_TRANSFER_BIT;
constexpr auto PipelineStage2BottomOfPipeBit                     = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT;
constexpr auto PipelineStage2HostBit                             = VK_PIPELINE_STAGE_2_HOST_BIT;
constexpr auto PipelineStage2AllGraphicsBit                      = VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT;
constexpr auto PipelineStage2AllCommandsBit                      = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;
constexpr auto PipelineStage2CopyBit                             = VK_PIPELINE_STAGE_2_COPY_BIT;
constexpr auto PipelineStage2ResolveBit                          = VK_PIPELINE_STAGE_2_RESOLVE_BIT;
constexpr auto PipelineStage2BlitBit                             = VK_PIPELINE_STAGE_2_BLIT_BIT;
constexpr auto PipelineStage2ClearBit                            = VK_PIPELINE_STAGE_2_CLEAR_BIT;
constexpr auto PipelineStage2IndexInputBit                       = VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT;
constexpr auto PipelineStage2VertexAttributeInputBit             = VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT;
constexpr auto PipelineStage2PreRasterizationShadersBit          = VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT;
constexpr auto PipelineStage2VideoDecodeBitKHR                   = VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR;
constexpr auto PipelineStage2VideoEncodeBitKHR                   = VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR;
constexpr auto PipelineStage2TransformFeedbackBitEXT             = VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT;
constexpr auto PipelineStage2ConditionalRenderingBitEXT          = VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT;
constexpr auto PipelineStage2CommandPreprocessBitEXT             = VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT;
constexpr auto PipelineStage2CommandPreprocessBitNV              = VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV;
constexpr auto PipelineStage2FragmentShadingRateAttachmentBitKHR = VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto PipelineStage2ShadingRateImageBitNV               = VK_PIPELINE_STAGE_2_SHADING_RATE_IMAGE_BIT_NV;
constexpr auto PipelineStage2AccelerationStructureBuildBitKHR    = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR;
constexpr auto PipelineStage2AccelerationStructureBuildBitNV     = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_NV;
constexpr auto PipelineStage2RayTracingShaderBitKHR              = VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR;
constexpr auto PipelineStage2RayTracingShaderBitNV               = VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_NV;
constexpr auto PipelineStage2FragmentDensityProcessBitEXT        = VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT;
constexpr auto PipelineStage2TaskShaderBitEXT                    = VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT;
constexpr auto PipelineStage2TaskShaderBitNV                     = VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_NV;
constexpr auto PipelineStage2MeshShaderBitEXT                    = VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT;
constexpr auto PipelineStage2MeshShaderBitNV                     = VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_NV;
constexpr auto PipelineStage2SubpassShaderBitHUAWEI              = VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI;
constexpr auto PipelineStage2SubpassShadingBitHUAWEI             = VK_PIPELINE_STAGE_2_SUBPASS_SHADING_BIT_HUAWEI;
constexpr auto PipelineStage2InvocationMaskBitHUAWEI             = VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI;
constexpr auto PipelineStage2AccelerationStructureCopyBitKHR     = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR;
constexpr auto PipelineStage2MicromapBuildBitEXT                 = VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT;
constexpr auto PipelineStage2ClusterCullingShaderBitHUAWEI       = VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI;
constexpr auto PipelineStage2OpticalFlowBitNV                    = VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV;
constexpr auto PipelineStage2ConvertCooperativeVectorMatrixBitNV = VK_PIPELINE_STAGE_2_CONVERT_COOPERATIVE_VECTOR_MATRIX_BIT_NV;
constexpr auto PipelineStage2DataGraphBitARM                     = VK_PIPELINE_STAGE_2_DATA_GRAPH_BIT_ARM;
constexpr auto PipelineStage2CopyIndirectBitKHR                  = VK_PIPELINE_STAGE_2_COPY_INDIRECT_BIT_KHR;
//};

//enum Access2 : uint64_t {
constexpr auto Access2None                                    = VK_ACCESS_2_NONE;
constexpr auto Access2IndirectCommandReadBit                  = VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT;
constexpr auto Access2IndexReadBit                            = VK_ACCESS_2_INDEX_READ_BIT;
constexpr auto Access2VertexAttributeReadBit                  = VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT;
constexpr auto Access2UniformReadBit                          = VK_ACCESS_2_UNIFORM_READ_BIT;
constexpr auto Access2InputAttachmentReadBit                  = VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT;
constexpr auto Access2ShaderReadBit                           = VK_ACCESS_2_SHADER_READ_BIT;
constexpr auto Access2ShaderWriteBit                          = VK_ACCESS_2_SHADER_WRITE_BIT;
constexpr auto Access2ColorAttachmentReadBit                  = VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT;
constexpr auto Access2ColorAttachmentWriteBit                 = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT;
constexpr auto Access2DepthStencilAttachmentReadBit           = VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT;
constexpr auto Access2DepthStencilAttachmentWriteBit          = VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
constexpr auto Access2TransferReadBit                         = VK_ACCESS_2_TRANSFER_READ_BIT;
constexpr auto Access2TransferWriteBit                        = VK_ACCESS_2_TRANSFER_WRITE_BIT;
constexpr auto Access2HostReadBit                             = VK_ACCESS_2_HOST_READ_BIT;
constexpr auto Access2HostWriteBit                            = VK_ACCESS_2_HOST_WRITE_BIT;
constexpr auto Access2MemoryReadBit                           = VK_ACCESS_2_MEMORY_READ_BIT;
constexpr auto Access2MemoryWriteBit                          = VK_ACCESS_2_MEMORY_WRITE_BIT;
constexpr auto Access2ShaderSampledReadBit                    = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
constexpr auto Access2ShaderStorageReadBit                    = VK_ACCESS_2_SHADER_STORAGE_READ_BIT;
constexpr auto Access2ShaderStorageWriteBit                   = VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT;
constexpr auto Access2VideoDecodeReadBitKHR                   = VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR;
constexpr auto Access2VideoDecodeWriteBitKHR                  = VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR;
constexpr auto Access2VideoEncodeReadBitKHR                   = VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR;
constexpr auto Access2VideoEncodeWriteBitKHR                  = VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR;
constexpr auto Access2ShaderTileAttachmentReadBitQCOM         = VK_ACCESS_2_SHADER_TILE_ATTACHMENT_READ_BIT_QCOM;
constexpr auto Access2ShaderTileAttachmentWriteBitQCOM        = VK_ACCESS_2_SHADER_TILE_ATTACHMENT_WRITE_BIT_QCOM;
constexpr auto Access2TransformFeedbackWriteBitEXT            = VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT;
constexpr auto Access2TransformFeedbackCounterReadBitEXT      = VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT;
constexpr auto Access2TransformFeedbackCounterWriteBitEXT     = VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT;
constexpr auto Access2ConditionalRenderingReadBitEXT          = VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT;
constexpr auto Access2CommandPreprocessReadBitEXT             = VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_EXT;
constexpr auto Access2CommandPreprocessReadBitNV              = VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV;
constexpr auto Access2CommandPreprocessWriteBitEXT            = VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_EXT;
constexpr auto Access2CommandPreprocessWriteBitNV             = VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV;
constexpr auto Access2FragmentShadingRateAttachmentReadBitKHR = VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR;
constexpr auto Access2ShadingRateImageReadBitNV               = VK_ACCESS_2_SHADING_RATE_IMAGE_READ_BIT_NV;
constexpr auto Access2AccelerationStructureReadBitKHR         = VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR;
constexpr auto Access2AccelerationStructureReadBitNV          = VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_NV;
constexpr auto Access2AccelerationStructureWriteBitKHR        = VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR;
constexpr auto Access2AccelerationStructureWriteBitNV         = VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_NV;
constexpr auto Access2FragmentDensityMapReadBitEXT            = VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT;
constexpr auto Access2ColorAttachmentReadNoncoherentBitEXT    = VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT;
constexpr auto Access2DescriptorBufferReadBitEXT              = VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT;
constexpr auto Access2InvocationMaskReadBitHUAWEI             = VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI;
constexpr auto Access2ShaderBindingTableReadBitKHR            = VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR;
constexpr auto Access2MicromapReadBitEXT                      = VK_ACCESS_2_MICROMAP_READ_BIT_EXT;
constexpr auto Access2MicromapWriteBitEXT                     = VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT;
constexpr auto Access2OpticalFlowReadBitNV                    = VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV;
constexpr auto Access2OpticalFlowWriteBitNV                   = VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV;
constexpr auto Access2DataGraphReadBitARM                     = VK_ACCESS_2_DATA_GRAPH_READ_BIT_ARM;
constexpr auto Access2DataGraphWriteBitARM                    = VK_ACCESS_2_DATA_GRAPH_WRITE_BIT_ARM;
//};

//enum Submit {
constexpr auto SubmitProtectedBit = VK_SUBMIT_PROTECTED_BIT;
//};

//enum Rendering {
constexpr auto RenderingContentsSecondaryCommandBuffersBit = VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT;
constexpr auto RenderingSuspendingBit                      = VK_RENDERING_SUSPENDING_BIT;
constexpr auto RenderingResumingBit                        = VK_RENDERING_RESUMING_BIT;
constexpr auto RenderingEnableLegacyDitheringBitEXT        = VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT;
constexpr auto RenderingContentsInlineBitKHR               = VK_RENDERING_CONTENTS_INLINE_BIT_KHR;
constexpr auto RenderingContentsInlineBitEXT               = VK_RENDERING_CONTENTS_INLINE_BIT_EXT;
constexpr auto RenderingPerLayerFragmentDensityBitVALVE    = VK_RENDERING_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE;
//};

//enum FormatFeature2 : uint64_t {
constexpr auto FormatFeature2SampledImageBit                                                     = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT;
constexpr auto FormatFeature2StorageImageBit                                                     = VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT;
constexpr auto FormatFeature2StorageImageAtomicBit                                               = VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT;
constexpr auto FormatFeature2UniformTexelBufferBit                                               = VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT;
constexpr auto FormatFeature2StorageTexelBufferBit                                               = VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT;
constexpr auto FormatFeature2StorageTexelBufferAtomicBit                                         = VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT;
constexpr auto FormatFeature2VertexBufferBit                                                     = VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT;
constexpr auto FormatFeature2ColorAttachmentBit                                                  = VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT;
constexpr auto FormatFeature2ColorAttachmentBlendBit                                             = VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT;
constexpr auto FormatFeature2DepthStencilAttachmentBit                                           = VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT;
constexpr auto FormatFeature2BlitSrcBit                                                          = VK_FORMAT_FEATURE_2_BLIT_SRC_BIT;
constexpr auto FormatFeature2BlitDstBit                                                          = VK_FORMAT_FEATURE_2_BLIT_DST_BIT;
constexpr auto FormatFeature2SampledImageFilterLinearBit                                         = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT;
constexpr auto FormatFeature2TransferSrcBit                                                      = VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT;
constexpr auto FormatFeature2TransferDstBit                                                      = VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT;
constexpr auto FormatFeature2SampledImageFilterMinmaxBit                                         = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT;
constexpr auto FormatFeature2MidpointChromaSamplesBit                                            = VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT;
constexpr auto FormatFeature2SampledImageYcbcrConversionLinearFilterBit                          = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT;
constexpr auto FormatFeature2SampledImageYcbcrConversionSeparateReconstructionFilterBit          = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT;
constexpr auto FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitBit          = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT;
constexpr auto FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitForceableBit = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT;
constexpr auto FormatFeature2DisjointBit                                                         = VK_FORMAT_FEATURE_2_DISJOINT_BIT;
constexpr auto FormatFeature2CositedChromaSamplesBit                                             = VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT;
constexpr auto FormatFeature2StorageReadWithoutFormatBit                                         = VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT;
constexpr auto FormatFeature2StorageWriteWithoutFormatBit                                        = VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT;
constexpr auto FormatFeature2SampledImageDepthComparisonBit                                      = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT;
constexpr auto FormatFeature2SampledImageFilterCubicBit                                          = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT;
constexpr auto FormatFeature2SampledImageFilterCubicBitEXT                                       = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT;
constexpr auto FormatFeature2HostImageTransferBit                                                = VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT;
constexpr auto FormatFeature2HostImageTransferBitEXT                                             = VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT;
constexpr auto FormatFeature2VideoDecodeOutputBitKHR                                             = VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR;
constexpr auto FormatFeature2VideoDecodeDpbBitKHR                                                = VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR;
constexpr auto FormatFeature2AccelerationStructureVertexBufferBitKHR                             = VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR;
constexpr auto FormatFeature2FragmentDensityMapBitEXT                                            = VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT;
constexpr auto FormatFeature2FragmentShadingRateAttachmentBitKHR                                 = VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto FormatFeature2VideoEncodeInputBitKHR                                              = VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR;
constexpr auto FormatFeature2VideoEncodeDpbBitKHR                                                = VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR;
constexpr auto FormatFeature2AccelerationStructureRadiusBufferBitNV                              = VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV;
constexpr auto FormatFeature2LinearColorAttachmentBitNV                                          = VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV;
constexpr auto FormatFeature2WeightImageBitQCOM                                                  = VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM;
constexpr auto FormatFeature2WeightSampledImageBitQCOM                                           = VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM;
constexpr auto FormatFeature2BlockMatchingBitQCOM                                                = VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM;
constexpr auto FormatFeature2BoxFilterSampledBitQCOM                                             = VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM;
constexpr auto FormatFeature2TensorShaderBitARM                                                  = VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM;
constexpr auto FormatFeature2TensorImageAliasingBitARM                                           = VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM;
constexpr auto FormatFeature2OpticalFlowImageBitNV                                               = VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV;
constexpr auto FormatFeature2OpticalFlowVectorBitNV                                              = VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV;
constexpr auto FormatFeature2OpticalFlowCostBitNV                                                = VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV;
constexpr auto FormatFeature2TensorDataGraphBitARM                                               = VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM;
constexpr auto FormatFeature2CopyImageIndirectDstBitKHR                                          = VK_FORMAT_FEATURE_2_COPY_IMAGE_INDIRECT_DST_BIT_KHR;
constexpr auto FormatFeature2VideoEncodeQuantizationDeltaMapBitKHR                               = VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR;
constexpr auto FormatFeature2VideoEncodeEmphasisMapBitKHR                                        = VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR;
//};

//enum QueueGlobalPriority {
constexpr auto QueueGlobalPriorityLow         = VK_QUEUE_GLOBAL_PRIORITY_LOW;
constexpr auto QueueGlobalPriorityLowKHR      = VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR;
constexpr auto QueueGlobalPriorityMedium      = VK_QUEUE_GLOBAL_PRIORITY_MEDIUM;
constexpr auto QueueGlobalPriorityMediumKHR   = VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR;
constexpr auto QueueGlobalPriorityHigh        = VK_QUEUE_GLOBAL_PRIORITY_HIGH;
constexpr auto QueueGlobalPriorityHighKHR     = VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR;
constexpr auto QueueGlobalPriorityRealtime    = VK_QUEUE_GLOBAL_PRIORITY_REALTIME;
constexpr auto QueueGlobalPriorityRealtimeKHR = VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR;
//};

//enum LineRasterizationMode {
constexpr auto LineRasterizationModeDefault              = VK_LINE_RASTERIZATION_MODE_DEFAULT;
constexpr auto LineRasterizationModeDefaultKHR           = VK_LINE_RASTERIZATION_MODE_DEFAULT_KHR;
constexpr auto LineRasterizationModeRectangular          = VK_LINE_RASTERIZATION_MODE_RECTANGULAR;
constexpr auto LineRasterizationModeRectangularKHR       = VK_LINE_RASTERIZATION_MODE_RECTANGULAR_KHR;
constexpr auto LineRasterizationModeBresenham            = VK_LINE_RASTERIZATION_MODE_BRESENHAM;
constexpr auto LineRasterizationModeBresenhamKHR         = VK_LINE_RASTERIZATION_MODE_BRESENHAM_KHR;
constexpr auto LineRasterizationModeRectangularSmooth    = VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH;
constexpr auto LineRasterizationModeRectangularSmoothKHR = VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_KHR;
//};

//enum MemoryUnmap {
constexpr auto MemoryUnmapReserveBitEXT = VK_MEMORY_UNMAP_RESERVE_BIT_EXT;
//};

//enum PipelineCreate2 : uint64_t {
constexpr auto PipelineCreate2DisableOptimizationBit                           = VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT;
constexpr auto PipelineCreate2AllowDerivativesBit                              = VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT;
constexpr auto PipelineCreate2DerivativeBit                                    = VK_PIPELINE_CREATE_2_DERIVATIVE_BIT;
constexpr auto PipelineCreate2ViewIndexFromDeviceIndexBit                      = VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT;
constexpr auto PipelineCreate2DispatchBaseBit                                  = VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT;
constexpr auto PipelineCreate2FailOnPipelineCompileRequiredBit                 = VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT;
constexpr auto PipelineCreate2EarlyReturnOnFailureBit                          = VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT;
constexpr auto PipelineCreate2NoProtectedAccessBit                             = VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT;
constexpr auto PipelineCreate2NoProtectedAccessBitEXT                          = VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT;
constexpr auto PipelineCreate2ProtectedAccessOnlyBit                           = VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT;
constexpr auto PipelineCreate2ProtectedAccessOnlyBitEXT                        = VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto PipelineCreate2ExecutionGraphBitAMDX                            = VK_PIPELINE_CREATE_2_EXECUTION_GRAPH_BIT_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto PipelineCreate2RayTracingAllowSpheresAndLinearSweptSpheresBitNV = VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_SPHERES_AND_LINEAR_SWEPT_SPHERES_BIT_NV;
constexpr auto PipelineCreate2EnableLegacyDitheringBitEXT                      = VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT;
constexpr auto PipelineCreate2DeferCompileBitNV                                = VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV;
constexpr auto PipelineCreate2CaptureStatisticsBitKHR                          = VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR;
constexpr auto PipelineCreate2CaptureInternalRepresentationsBitKHR             = VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR;
constexpr auto PipelineCreate2LinkTimeOptimizationBitEXT                       = VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT;
constexpr auto PipelineCreate2RetainLinkTimeOptimizationInfoBitEXT             = VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT;
constexpr auto PipelineCreate2LibraryBitKHR                                    = VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR;
constexpr auto PipelineCreate2RayTracingSkipTrianglesBitKHR                    = VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR;
constexpr auto PipelineCreate2RayTracingSkipBuiltInPrimitivesBitKHR            = VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_BUILT_IN_PRIMITIVES_BIT_KHR;
constexpr auto PipelineCreate2RayTracingSkipAabbsBitKHR                        = VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR;
constexpr auto PipelineCreate2RayTracingNoNullAnyHitShadersBitKHR              = VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR;
constexpr auto PipelineCreate2RayTracingNoNullClosestHitShadersBitKHR          = VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR;
constexpr auto PipelineCreate2RayTracingNoNullMissShadersBitKHR                = VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR;
constexpr auto PipelineCreate2RayTracingNoNullIntersectionShadersBitKHR        = VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR;
constexpr auto PipelineCreate2RayTracingShaderGroupHandleCaptureReplayBitKHR   = VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;
constexpr auto PipelineCreate2IndirectBindableBitNV                            = VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV;
constexpr auto PipelineCreate2RayTracingAllowMotionBitNV                       = VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV;
constexpr auto PipelineCreate2RenderingFragmentShadingRateAttachmentBitKHR     = VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR;
constexpr auto PipelineCreate2RenderingFragmentDensityMapAttachmentBitEXT      = VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT;
constexpr auto PipelineCreate2RayTracingOpacityMicromapBitEXT                  = VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT;
constexpr auto PipelineCreate2ColorAttachmentFeedbackLoopBitEXT                = VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT;
constexpr auto PipelineCreate2DepthStencilAttachmentFeedbackLoopBitEXT         = VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT;
constexpr auto PipelineCreate2RayTracingDisplacementMicromapBitNV              = VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV;
constexpr auto PipelineCreate2DescriptorBufferBitEXT                           = VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto PipelineCreate2DisallowOpacityMicromapBitARM                    = VK_PIPELINE_CREATE_2_DISALLOW_OPACITY_MICROMAP_BIT_ARM;
constexpr auto PipelineCreate2CaptureDataBitKHR                                = VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR;
constexpr auto PipelineCreate2IndirectBindableBitEXT                           = VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_EXT;
constexpr auto PipelineCreate2PerLayerFragmentDensityBitVALVE                  = VK_PIPELINE_CREATE_2_PER_LAYER_FRAGMENT_DENSITY_BIT_VALVE;
//};

//enum BufferUsage2 : uint64_t {
constexpr auto BufferUsage2TransferSrcBit                                = VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT;
constexpr auto BufferUsage2TransferDstBit                                = VK_BUFFER_USAGE_2_TRANSFER_DST_BIT;
constexpr auto BufferUsage2UniformTexelBufferBit                         = VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT;
constexpr auto BufferUsage2StorageTexelBufferBit                         = VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT;
constexpr auto BufferUsage2UniformBufferBit                              = VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT;
constexpr auto BufferUsage2StorageBufferBit                              = VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT;
constexpr auto BufferUsage2IndexBufferBit                                = VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT;
constexpr auto BufferUsage2VertexBufferBit                               = VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT;
constexpr auto BufferUsage2IndirectBufferBit                             = VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT;
constexpr auto BufferUsage2ShaderDeviceAddressBit                        = VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsage2ExecutionGraphScratchBitAMDX                  = VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsage2ConditionalRenderingBitEXT                    = VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT;
constexpr auto BufferUsage2ShaderBindingTableBitKHR                      = VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR;
constexpr auto BufferUsage2RayTracingBitNV                               = VK_BUFFER_USAGE_2_RAY_TRACING_BIT_NV;
constexpr auto BufferUsage2TransformFeedbackBufferBitEXT                 = VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT;
constexpr auto BufferUsage2TransformFeedbackCounterBufferBitEXT          = VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT;
constexpr auto BufferUsage2VideoDecodeSrcBitKHR                          = VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR;
constexpr auto BufferUsage2VideoDecodeDstBitKHR                          = VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR;
constexpr auto BufferUsage2VideoEncodeDstBitKHR                          = VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR;
constexpr auto BufferUsage2VideoEncodeSrcBitKHR                          = VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR;
constexpr auto BufferUsage2AccelerationStructureBuildInputReadOnlyBitKHR = VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR;
constexpr auto BufferUsage2AccelerationStructureStorageBitKHR            = VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR;
constexpr auto BufferUsage2SamplerDescriptorBufferBitEXT                 = VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsage2ResourceDescriptorBufferBitEXT                = VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsage2PushDescriptorsDescriptorBufferBitEXT         = VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT;
constexpr auto BufferUsage2MicromapBuildInputReadOnlyBitEXT              = VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT;
constexpr auto BufferUsage2MicromapStorageBitEXT                         = VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsage2CompressedDataDgf1BitAMDX                     = VK_BUFFER_USAGE_2_COMPRESSED_DATA_DGF1_BIT_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto BufferUsage2DataGraphForeignDescriptorBitARM              = VK_BUFFER_USAGE_2_DATA_GRAPH_FOREIGN_DESCRIPTOR_BIT_ARM;
constexpr auto BufferUsage2TileMemoryBitQCOM                             = VK_BUFFER_USAGE_2_TILE_MEMORY_BIT_QCOM;
constexpr auto BufferUsage2PreprocessBufferBitEXT                        = VK_BUFFER_USAGE_2_PREPROCESS_BUFFER_BIT_EXT;
//};

//enum PipelineRobustnessBufferBehavior {
constexpr auto PipelineRobustnessBufferBehaviorDeviceDefault       = VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT;
constexpr auto PipelineRobustnessBufferBehaviorDisabled            = VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED;
constexpr auto PipelineRobustnessBufferBehaviorRobustBufferAccess  = VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS;
constexpr auto PipelineRobustnessBufferBehaviorRobustBufferAccess2 = VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2;
//};

//enum PipelineRobustnessImageBehavior {
constexpr auto PipelineRobustnessImageBehaviorDeviceDefault      = VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT;
constexpr auto PipelineRobustnessImageBehaviorDisabled           = VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED;
constexpr auto PipelineRobustnessImageBehaviorRobustImageAccess  = VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS;
constexpr auto PipelineRobustnessImageBehaviorRobustImageAccess2 = VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2;
//};

//enum HostImageCopy {
constexpr auto HostImageCopyMemcpyBit = VK_HOST_IMAGE_COPY_MEMCPY_BIT;
//};

//enum SurfaceTransformKHR {
constexpr auto SurfaceTransformIdentityBitKHR                  = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
constexpr auto SurfaceTransformRotate90BitKHR                  = VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR;
constexpr auto SurfaceTransformRotate180BitKHR                 = VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR;
constexpr auto SurfaceTransformRotate270BitKHR                 = VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR;
constexpr auto SurfaceTransformHorizontalMirrorBitKHR          = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR;
constexpr auto SurfaceTransformHorizontalMirrorRotate90BitKHR  = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR;
constexpr auto SurfaceTransformHorizontalMirrorRotate180BitKHR = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR;
constexpr auto SurfaceTransformHorizontalMirrorRotate270BitKHR = VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR;
constexpr auto SurfaceTransformInheritBitKHR                   = VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR;
//};

//enum PresentModeKHR {
constexpr auto PresentModeImmediateKHR               = VK_PRESENT_MODE_IMMEDIATE_KHR;
constexpr auto PresentModeMailboxKHR                 = VK_PRESENT_MODE_MAILBOX_KHR;
constexpr auto PresentModeFifoKHR                    = VK_PRESENT_MODE_FIFO_KHR;
constexpr auto PresentModeFifoRelaxedKHR             = VK_PRESENT_MODE_FIFO_RELAXED_KHR;
constexpr auto PresentModeSharedDemandRefreshKHR     = VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR;
constexpr auto PresentModeSharedContinuousRefreshKHR = VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR;
constexpr auto PresentModeFifoLatestReadyKHR         = VK_PRESENT_MODE_FIFO_LATEST_READY_KHR;
constexpr auto PresentModeFifoLatestReadyEXTKHR      = VK_PRESENT_MODE_FIFO_LATEST_READY_EXT;
//};

//enum ColorSpaceKHR {
constexpr auto ColorSpaceSrgbNonlinearKHR             = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
constexpr auto ColorSpaceVkColorspaceSrgbNonlinearKHR = VK_COLORSPACE_SRGB_NONLINEAR_KHR;
constexpr auto ColorSpaceDisplayP3NonlinearEXTKHR     = VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT;
constexpr auto ColorSpaceExtendedSrgbLinearEXTKHR     = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT;
constexpr auto ColorSpaceDisplayP3LinearEXTKHR        = VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT;
constexpr auto ColorSpaceDciP3LinearEXTKHR            = VK_COLOR_SPACE_DCI_P3_LINEAR_EXT;
constexpr auto ColorSpaceDciP3NonlinearEXTKHR         = VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT;
constexpr auto ColorSpaceBt709LinearEXTKHR            = VK_COLOR_SPACE_BT709_LINEAR_EXT;
constexpr auto ColorSpaceBt709NonlinearEXTKHR         = VK_COLOR_SPACE_BT709_NONLINEAR_EXT;
constexpr auto ColorSpaceBt2020LinearEXTKHR           = VK_COLOR_SPACE_BT2020_LINEAR_EXT;
constexpr auto ColorSpaceHdr10St2084EXTKHR            = VK_COLOR_SPACE_HDR10_ST2084_EXT;
constexpr auto ColorSpaceDolbyvisionEXTKHR            = VK_COLOR_SPACE_DOLBYVISION_EXT;
constexpr auto ColorSpaceHdr10HlgEXTKHR               = VK_COLOR_SPACE_HDR10_HLG_EXT;
constexpr auto ColorSpaceAdobergbLinearEXTKHR         = VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT;
constexpr auto ColorSpaceAdobergbNonlinearEXTKHR      = VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT;
constexpr auto ColorSpacePassThroughEXTKHR            = VK_COLOR_SPACE_PASS_THROUGH_EXT;
constexpr auto ColorSpaceExtendedSrgbNonlinearEXTKHR  = VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT;
constexpr auto ColorSpaceDisplayNativeAMDKHR          = VK_COLOR_SPACE_DISPLAY_NATIVE_AMD;
//};

//enum CompositeAlphaKHR {
constexpr auto CompositeAlphaOpaqueBitKHR         = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
constexpr auto CompositeAlphaPreMultipliedBitKHR  = VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR;
constexpr auto CompositeAlphaPostMultipliedBitKHR = VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR;
constexpr auto CompositeAlphaInheritBitKHR        = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;
//};

//enum SwapchainCreateKHR {
constexpr auto SwapchainCreateSplitInstanceBindRegionsBitKHR    = VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR;
constexpr auto SwapchainCreateProtectedBitKHR                   = VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR;
constexpr auto SwapchainCreateMutableFormatBitKHR               = VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR;
constexpr auto SwapchainCreatePresentId2BitKHR                  = VK_SWAPCHAIN_CREATE_PRESENT_ID_2_BIT_KHR;
constexpr auto SwapchainCreatePresentWait2BitKHR                = VK_SWAPCHAIN_CREATE_PRESENT_WAIT_2_BIT_KHR;
constexpr auto SwapchainCreateDeferredMemoryAllocationBitKHR    = VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_KHR;
constexpr auto SwapchainCreateDeferredMemoryAllocationBitEXTKHR = VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT;
//};

//enum DeviceGroupPresentModeKHR {
constexpr auto DeviceGroupPresentModeLocalBitKHR            = VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR;
constexpr auto DeviceGroupPresentModeRemoteBitKHR           = VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR;
constexpr auto DeviceGroupPresentModeSumBitKHR              = VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR;
constexpr auto DeviceGroupPresentModeLocalMultiDeviceBitKHR = VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR;
//};

//enum DisplayPlaneAlphaKHR {
constexpr auto DisplayPlaneAlphaOpaqueBitKHR                = VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR;
constexpr auto DisplayPlaneAlphaGlobalBitKHR                = VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR;
constexpr auto DisplayPlaneAlphaPerPixelBitKHR              = VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR;
constexpr auto DisplayPlaneAlphaPerPixelPremultipliedBitKHR = VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR;
//};

//enum DisplayModeCreateKHR {
//};

//enum DisplaySurfaceCreateKHR {
//};

#ifdef VK_USE_PLATFORM_XLIB_KHR
//enum XlibSurfaceCreateKHR {
//};
#endif  // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR
//enum XcbSurfaceCreateKHR {
//};
#endif  // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
//enum WaylandSurfaceCreateKHR {
//};
#endif  // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
//enum AndroidSurfaceCreateKHR {
//};
#endif  // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
//enum Win32SurfaceCreateKHR {
//};
#endif  // VK_USE_PLATFORM_WIN32_KHR

//enum DebugReportEXT {
constexpr auto DebugReportInformationBitEXT        = VK_DEBUG_REPORT_INFORMATION_BIT_EXT;
constexpr auto DebugReportWarningBitEXT            = VK_DEBUG_REPORT_WARNING_BIT_EXT;
constexpr auto DebugReportPerformanceWarningBitEXT = VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
constexpr auto DebugReportErrorBitEXT              = VK_DEBUG_REPORT_ERROR_BIT_EXT;
constexpr auto DebugReportDebugBitEXT              = VK_DEBUG_REPORT_DEBUG_BIT_EXT;
//};

//enum DebugReportObjectTypeEXT {
constexpr auto DebugReportObjectTypeUnknownEXT                     = VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT;
constexpr auto DebugReportObjectTypeInstanceEXT                    = VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT;
constexpr auto DebugReportObjectTypePhysicalDeviceEXT              = VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT;
constexpr auto DebugReportObjectTypeDeviceEXT                      = VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT;
constexpr auto DebugReportObjectTypeQueueEXT                       = VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT;
constexpr auto DebugReportObjectTypeSemaphoreEXT                   = VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT;
constexpr auto DebugReportObjectTypeCommandBufferEXT               = VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT;
constexpr auto DebugReportObjectTypeFenceEXT                       = VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT;
constexpr auto DebugReportObjectTypeDeviceMemoryEXT                = VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT;
constexpr auto DebugReportObjectTypeBufferEXT                      = VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT;
constexpr auto DebugReportObjectTypeImageEXT                       = VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT;
constexpr auto DebugReportObjectTypeEventEXT                       = VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT;
constexpr auto DebugReportObjectTypeQueryPoolEXT                   = VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT;
constexpr auto DebugReportObjectTypeBufferViewEXT                  = VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT;
constexpr auto DebugReportObjectTypeImageViewEXT                   = VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT;
constexpr auto DebugReportObjectTypeShaderModuleEXT                = VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT;
constexpr auto DebugReportObjectTypePipelineCacheEXT               = VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT;
constexpr auto DebugReportObjectTypePipelineLayoutEXT              = VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT;
constexpr auto DebugReportObjectTypeRenderPassEXT                  = VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT;
constexpr auto DebugReportObjectTypePipelineEXT                    = VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT;
constexpr auto DebugReportObjectTypeDescriptorSetLayoutEXT         = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT;
constexpr auto DebugReportObjectTypeSamplerEXT                     = VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT;
constexpr auto DebugReportObjectTypeDescriptorPoolEXT              = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT;
constexpr auto DebugReportObjectTypeDescriptorSetEXT               = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT;
constexpr auto DebugReportObjectTypeFramebufferEXT                 = VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT;
constexpr auto DebugReportObjectTypeCommandPoolEXT                 = VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT;
constexpr auto DebugReportObjectTypeSurfaceKHREXT                  = VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT;
constexpr auto DebugReportObjectTypeSwapchainKHREXT                = VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT;
constexpr auto DebugReportObjectTypeDebugReportCallbackEXTEXT      = VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT;
constexpr auto DebugReportObjectTypeDebugReportEXT                 = VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT;
constexpr auto DebugReportObjectTypeDisplayKHREXT                  = VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT;
constexpr auto DebugReportObjectTypeDisplayModeKHREXT              = VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT;
constexpr auto DebugReportObjectTypeValidationCacheEXTEXT          = VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT;
constexpr auto DebugReportObjectTypeValidationCacheEXT             = VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT;
constexpr auto DebugReportObjectTypeSamplerYcbcrConversionEXT      = VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT;
constexpr auto DebugReportObjectTypeSamplerYcbcrConversionKHREXT   = VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT;
constexpr auto DebugReportObjectTypeDescriptorUpdateTemplateEXT    = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT;
constexpr auto DebugReportObjectTypeDescriptorUpdateTemplateKHREXT = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT;
constexpr auto DebugReportObjectTypeCuModuleNVXEXT                 = VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT;
constexpr auto DebugReportObjectTypeCuFunctionNVXEXT               = VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT;
constexpr auto DebugReportObjectTypeAccelerationStructureKHREXT    = VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT;
constexpr auto DebugReportObjectTypeAccelerationStructureNVEXT     = VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto DebugReportObjectTypeCudaModuleNVEXT   = VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT;
constexpr auto DebugReportObjectTypeCudaFunctionNVEXT = VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT;
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
constexpr auto DebugReportObjectTypeBufferCollectionFUCHSIAEXT = VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT;
#endif  // VK_USE_PLATFORM_FUCHSIA
//};

//enum RasterizationOrderAMD {
constexpr auto RasterizationOrderStrictAMD  = VK_RASTERIZATION_ORDER_STRICT_AMD;
constexpr auto RasterizationOrderRelaxedAMD = VK_RASTERIZATION_ORDER_RELAXED_AMD;
//};

//enum VideoCodecOperationKHR {
constexpr auto VideoCodecOperationNoneKHR          = VK_VIDEO_CODEC_OPERATION_NONE_KHR;
constexpr auto VideoCodecOperationEncodeH264BitKHR = VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR;
constexpr auto VideoCodecOperationEncodeH265BitKHR = VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR;
constexpr auto VideoCodecOperationDecodeH264BitKHR = VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR;
constexpr auto VideoCodecOperationDecodeH265BitKHR = VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR;
constexpr auto VideoCodecOperationDecodeAv1BitKHR  = VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR;
constexpr auto VideoCodecOperationEncodeAv1BitKHR  = VK_VIDEO_CODEC_OPERATION_ENCODE_AV1_BIT_KHR;
constexpr auto VideoCodecOperationDecodeVp9BitKHR  = VK_VIDEO_CODEC_OPERATION_DECODE_VP9_BIT_KHR;
//};

//enum VideoChromaSubsamplingKHR {
constexpr auto VideoChromaSubsamplingInvalidKHR       = VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR;
constexpr auto VideoChromaSubsamplingMonochromeBitKHR = VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR;
constexpr auto VideoChromaSubsampling420BitKHR        = VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR;
constexpr auto VideoChromaSubsampling422BitKHR        = VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR;
constexpr auto VideoChromaSubsampling444BitKHR        = VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR;
//};

//enum VideoComponentBitDepthKHR {
constexpr auto VideoComponentBitDepthInvalidBitKHR = VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR;
constexpr auto VideoComponentBitDepth8BitKHR       = VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR;
constexpr auto VideoComponentBitDepth10BitKHR      = VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR;
constexpr auto VideoComponentBitDepth12BitKHR      = VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR;
//};

//enum VideoCapabilityKHR {
constexpr auto VideoCapabilityProtectedContentBitKHR        = VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR;
constexpr auto VideoCapabilitySeparateReferenceImagesBitKHR = VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR;
//};

//enum VideoSessionCreateKHR {
constexpr auto VideoSessionCreateProtectedContentBitKHR                  = VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR;
constexpr auto VideoSessionCreateAllowEncodeParameterOptimizationsBitKHR = VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR;
constexpr auto VideoSessionCreateInlineQueriesBitKHR                     = VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR;
constexpr auto VideoSessionCreateAllowEncodeQuantizationDeltaMapBitKHR   = VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR;
constexpr auto VideoSessionCreateAllowEncodeEmphasisMapBitKHR            = VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_EMPHASIS_MAP_BIT_KHR;
constexpr auto VideoSessionCreateInlineSessionParametersBitKHR           = VK_VIDEO_SESSION_CREATE_INLINE_SESSION_PARAMETERS_BIT_KHR;
//};

//enum VideoCodingControlKHR {
constexpr auto VideoCodingControlResetBitKHR              = VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR;
constexpr auto VideoCodingControlEncodeRateControlBitKHR  = VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR;
constexpr auto VideoCodingControlEncodeQualityLevelBitKHR = VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR;
//};

//enum QueryResultStatusKHR {
constexpr auto QueryResultStatusErrorKHR                            = VK_QUERY_RESULT_STATUS_ERROR_KHR;
constexpr auto QueryResultStatusNotReadyKHR                         = VK_QUERY_RESULT_STATUS_NOT_READY_KHR;
constexpr auto QueryResultStatusCompleteKHR                         = VK_QUERY_RESULT_STATUS_COMPLETE_KHR;
constexpr auto QueryResultStatusInsufficientBitstreamBufferRangeKHR = VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR;
//};

//enum VideoSessionParametersCreateKHR {
constexpr auto VideoSessionParametersCreateQuantizationMapCompatibleBitKHR = VK_VIDEO_SESSION_PARAMETERS_CREATE_QUANTIZATION_MAP_COMPATIBLE_BIT_KHR;
//};

//enum VideoBeginCodingKHR {
//};

//enum VideoEndCodingKHR {
//};

//enum VideoDecodeCapabilityKHR {
constexpr auto VideoDecodeCapabilityDpbAndOutputCoincideBitKHR = VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR;
constexpr auto VideoDecodeCapabilityDpbAndOutputDistinctBitKHR = VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR;
//};

//enum VideoDecodeUsageKHR {
constexpr auto VideoDecodeUsageDefaultKHR        = VK_VIDEO_DECODE_USAGE_DEFAULT_KHR;
constexpr auto VideoDecodeUsageTranscodingBitKHR = VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR;
constexpr auto VideoDecodeUsageOfflineBitKHR     = VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR;
constexpr auto VideoDecodeUsageStreamingBitKHR   = VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR;
//};

//enum VideoDecodeKHR {
//};

//enum PipelineRasterizationStateStreamCreateEXT {
//};

//enum VideoEncodeH264CapabilityKHR {
constexpr auto VideoEncodeH264CapabilityHrdComplianceBitKHR                  = VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityPredictionWeightTableGeneratedBitKHR = VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityRowUnalignedSliceBitKHR              = VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityDifferentSliceTypeBitKHR             = VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityBFrameInL0ListBitKHR                 = VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityBFrameInL1ListBitKHR                 = VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityPerPictureTypeMinMaxQpBitKHR         = VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityPerSliceConstantQpBitKHR             = VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityGeneratePrefixNaluBitKHR             = VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityBPictureIntraRefreshBitKHR           = VK_VIDEO_ENCODE_H264_CAPABILITY_B_PICTURE_INTRA_REFRESH_BIT_KHR;
constexpr auto VideoEncodeH264CapabilityMbQpDiffWraparoundBitKHR             = VK_VIDEO_ENCODE_H264_CAPABILITY_MB_QP_DIFF_WRAPAROUND_BIT_KHR;
//};

//enum VideoEncodeH264StdKHR {
constexpr auto VideoEncodeH264StdSeparateColorPlaneFlagSetBitKHR          = VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdQpprimeYZeroTransformBypassFlagSetBitKHR = VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdScalingMatrixPresentFlagSetBitKHR        = VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdChromaQpIndexOffsetBitKHR                = VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR;
constexpr auto VideoEncodeH264StdSecondChromaQpIndexOffsetBitKHR          = VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR;
constexpr auto VideoEncodeH264StdPicInitQpMinus26BitKHR                   = VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR;
constexpr auto VideoEncodeH264StdWeightedPredFlagSetBitKHR                = VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdWeightedBipredIdcExplicitBitKHR          = VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR;
constexpr auto VideoEncodeH264StdWeightedBipredIdcImplicitBitKHR          = VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR;
constexpr auto VideoEncodeH264StdTransform8X8ModeFlagSetBitKHR            = VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdDirectSpatialMvPredFlagUnsetBitKHR       = VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR;
constexpr auto VideoEncodeH264StdEntropyCodingModeFlagUnsetBitKHR         = VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR;
constexpr auto VideoEncodeH264StdEntropyCodingModeFlagSetBitKHR           = VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdDirect8X8InferenceFlagUnsetBitKHR        = VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR;
constexpr auto VideoEncodeH264StdConstrainedIntraPredFlagSetBitKHR        = VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH264StdDeblockingFilterDisabledBitKHR           = VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR;
constexpr auto VideoEncodeH264StdDeblockingFilterEnabledBitKHR            = VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR;
constexpr auto VideoEncodeH264StdDeblockingFilterPartialBitKHR            = VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR;
constexpr auto VideoEncodeH264StdSliceQpDeltaBitKHR                       = VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR;
constexpr auto VideoEncodeH264StdDifferentSliceQpDeltaBitKHR              = VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR;
//};

//enum VideoEncodeH264RateControlKHR {
constexpr auto VideoEncodeH264RateControlAttemptHrdComplianceBitKHR       = VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR;
constexpr auto VideoEncodeH264RateControlRegularGopBitKHR                 = VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR;
constexpr auto VideoEncodeH264RateControlReferencePatternFlatBitKHR       = VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR;
constexpr auto VideoEncodeH264RateControlReferencePatternDyadicBitKHR     = VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR;
constexpr auto VideoEncodeH264RateControlTemporalLayerPatternDyadicBitKHR = VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR;
//};

//enum VideoEncodeH265CapabilityKHR {
constexpr auto VideoEncodeH265CapabilityHrdComplianceBitKHR                  = VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityPredictionWeightTableGeneratedBitKHR = VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityRowUnalignedSliceSegmentBitKHR       = VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityDifferentSliceSegmentTypeBitKHR      = VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityBFrameInL0ListBitKHR                 = VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityBFrameInL1ListBitKHR                 = VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityPerPictureTypeMinMaxQpBitKHR         = VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityPerSliceSegmentConstantQpBitKHR      = VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityMultipleTilesPerSliceSegmentBitKHR   = VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityMultipleSliceSegmentsPerTileBitKHR   = VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityBPictureIntraRefreshBitKHR           = VK_VIDEO_ENCODE_H265_CAPABILITY_B_PICTURE_INTRA_REFRESH_BIT_KHR;
constexpr auto VideoEncodeH265CapabilityCuQpDiffWraparoundBitKHR             = VK_VIDEO_ENCODE_H265_CAPABILITY_CU_QP_DIFF_WRAPAROUND_BIT_KHR;
//};

//enum VideoEncodeH265StdKHR {
constexpr auto VideoEncodeH265StdSeparateColorPlaneFlagSetBitKHR              = VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdSampleAdaptiveOffsetEnabledFlagSetBitKHR     = VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdScalingListDataPresentFlagSetBitKHR          = VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdPcmEnabledFlagSetBitKHR                      = VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdSpsTemporalMvpEnabledFlagSetBitKHR           = VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdInitQpMinus26BitKHR                          = VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR;
constexpr auto VideoEncodeH265StdWeightedPredFlagSetBitKHR                    = VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdWeightedBipredFlagSetBitKHR                  = VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdLog2ParallelMergeLevelMinus2BitKHR           = VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR;
constexpr auto VideoEncodeH265StdSignDataHidingEnabledFlagSetBitKHR           = VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdTransformSkipEnabledFlagSetBitKHR            = VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdTransformSkipEnabledFlagUnsetBitKHR          = VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR;
constexpr auto VideoEncodeH265StdPpsSliceChromaQpOffsetsPresentFlagSetBitKHR  = VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdTransquantBypassEnabledFlagSetBitKHR         = VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdConstrainedIntraPredFlagSetBitKHR            = VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdEntropyCodingSyncEnabledFlagSetBitKHR        = VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdDeblockingFilterOverrideEnabledFlagSetBitKHR = VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdDependentSliceSegmentsEnabledFlagSetBitKHR   = VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdDependentSliceSegmentFlagSetBitKHR           = VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeH265StdSliceQpDeltaBitKHR                           = VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR;
constexpr auto VideoEncodeH265StdDifferentSliceQpDeltaBitKHR                  = VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR;
//};

//enum VideoEncodeH265CtbSizeKHR {
constexpr auto VideoEncodeH265CtbSize16BitKHR = VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR;
constexpr auto VideoEncodeH265CtbSize32BitKHR = VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR;
constexpr auto VideoEncodeH265CtbSize64BitKHR = VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR;
//};

//enum VideoEncodeH265TransformBlockSizeKHR {
constexpr auto VideoEncodeH265TransformBlockSize4BitKHR  = VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR;
constexpr auto VideoEncodeH265TransformBlockSize8BitKHR  = VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR;
constexpr auto VideoEncodeH265TransformBlockSize16BitKHR = VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR;
constexpr auto VideoEncodeH265TransformBlockSize32BitKHR = VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR;
//};

//enum VideoEncodeH265RateControlKHR {
constexpr auto VideoEncodeH265RateControlAttemptHrdComplianceBitKHR          = VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR;
constexpr auto VideoEncodeH265RateControlRegularGopBitKHR                    = VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR;
constexpr auto VideoEncodeH265RateControlReferencePatternFlatBitKHR          = VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR;
constexpr auto VideoEncodeH265RateControlReferencePatternDyadicBitKHR        = VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR;
constexpr auto VideoEncodeH265RateControlTemporalSubLayerPatternDyadicBitKHR = VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR;
//};

//enum VideoDecodeH264PictureLayoutKHR {
constexpr auto VideoDecodeH264PictureLayoutProgressiveKHR                   = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR;
constexpr auto VideoDecodeH264PictureLayoutInterlacedInterleavedLinesBitKHR = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR;
constexpr auto VideoDecodeH264PictureLayoutInterlacedSeparatePlanesBitKHR   = VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR;
//};

//enum ShaderInfoTypeAMD {
constexpr auto ShaderInfoTypeStatisticsAMD  = VK_SHADER_INFO_TYPE_STATISTICS_AMD;
constexpr auto ShaderInfoTypeBinaryAMD      = VK_SHADER_INFO_TYPE_BINARY_AMD;
constexpr auto ShaderInfoTypeDisassemblyAMD = VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD;
//};

#ifdef VK_USE_PLATFORM_GGP
//enum StreamDescriptorSurfaceCreateGGP {
//};
#endif  // VK_USE_PLATFORM_GGP

//enum ExternalMemoryHandleTypeNV {
constexpr auto ExternalMemoryHandleTypeOpaqueWin32BitNV    = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV;
constexpr auto ExternalMemoryHandleTypeOpaqueWin32KmtBitNV = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV;
constexpr auto ExternalMemoryHandleTypeD3D11ImageBitNV     = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV;
constexpr auto ExternalMemoryHandleTypeD3D11ImageKmtBitNV  = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV;
//};

//enum ExternalMemoryFeatureNV {
constexpr auto ExternalMemoryFeatureDedicatedOnlyBitNV = VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV;
constexpr auto ExternalMemoryFeatureExportableBitNV    = VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV;
constexpr auto ExternalMemoryFeatureImportableBitNV    = VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV;
//};

//enum ValidationCheckEXT {
constexpr auto ValidationCheckAllEXT     = VK_VALIDATION_CHECK_ALL_EXT;
constexpr auto ValidationCheckShadersEXT = VK_VALIDATION_CHECK_SHADERS_EXT;
//};

#ifdef VK_USE_PLATFORM_VI_NN
//enum ViSurfaceCreateNN {
//};
#endif  // VK_USE_PLATFORM_VI_NN

//enum ConditionalRenderingEXT {
constexpr auto ConditionalRenderingInvertedBitEXT = VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT;
//};

//enum SurfaceCounterEXT {
constexpr auto SurfaceCounterVblankBitEXT = VK_SURFACE_COUNTER_VBLANK_BIT_EXT;
//};

//enum DisplayPowerStateEXT {
constexpr auto DisplayPowerStateOffEXT     = VK_DISPLAY_POWER_STATE_OFF_EXT;
constexpr auto DisplayPowerStateSuspendEXT = VK_DISPLAY_POWER_STATE_SUSPEND_EXT;
constexpr auto DisplayPowerStateOnEXT      = VK_DISPLAY_POWER_STATE_ON_EXT;
//};

//enum DeviceEventTypeEXT {
constexpr auto DeviceEventTypeDisplayHotplugEXT = VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT;
//};

//enum DisplayEventTypeEXT {
constexpr auto DisplayEventTypeFirstPixelOutEXT = VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT;
//};

//enum ViewportCoordinateSwizzleNV {
constexpr auto ViewportCoordinateSwizzlePositiveXNV = VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV;
constexpr auto ViewportCoordinateSwizzleNegativeXNV = VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV;
constexpr auto ViewportCoordinateSwizzlePositiveYNV = VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV;
constexpr auto ViewportCoordinateSwizzleNegativeYNV = VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV;
constexpr auto ViewportCoordinateSwizzlePositiveZNV = VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV;
constexpr auto ViewportCoordinateSwizzleNegativeZNV = VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV;
constexpr auto ViewportCoordinateSwizzlePositiveWNV = VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV;
constexpr auto ViewportCoordinateSwizzleNegativeWNV = VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV;
//};

//enum PipelineViewportSwizzleStateCreateNV {
//};

//enum DiscardRectangleModeEXT {
constexpr auto DiscardRectangleModeInclusiveEXT = VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT;
constexpr auto DiscardRectangleModeExclusiveEXT = VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT;
//};

//enum PipelineDiscardRectangleStateCreateEXT {
//};

//enum ConservativeRasterizationModeEXT {
constexpr auto ConservativeRasterizationModeDisabledEXT      = VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT;
constexpr auto ConservativeRasterizationModeOverestimateEXT  = VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT;
constexpr auto ConservativeRasterizationModeUnderestimateEXT = VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT;
//};

//enum PipelineRasterizationConservativeStateCreateEXT {
//};

//enum PipelineRasterizationDepthClipStateCreateEXT {
//};

//enum PerformanceCounterDescriptionKHR {
constexpr auto PerformanceCounterDescriptionPerformanceImpactingBitKHR = VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR;
constexpr auto PerformanceCounterDescriptionConcurrentlyImpactedBitKHR = VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR;
//};

//enum PerformanceCounterScopeKHR {
constexpr auto PerformanceCounterScopeCommandBufferKHR             = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR;
constexpr auto PerformanceCounterScopeVkQueryScopeCommandBufferKHR = VK_QUERY_SCOPE_COMMAND_BUFFER_KHR;
constexpr auto PerformanceCounterScopeRenderPassKHR                = VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR;
constexpr auto PerformanceCounterScopeVkQueryScopeRenderPassKHR    = VK_QUERY_SCOPE_RENDER_PASS_KHR;
constexpr auto PerformanceCounterScopeCommandKHR                   = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR;
constexpr auto PerformanceCounterScopeVkQueryScopeCommandKHR       = VK_QUERY_SCOPE_COMMAND_KHR;
//};

//enum PerformanceCounterStorageKHR {
constexpr auto PerformanceCounterStorageInt32KHR   = VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR;
constexpr auto PerformanceCounterStorageInt64KHR   = VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR;
constexpr auto PerformanceCounterStorageUint32KHR  = VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR;
constexpr auto PerformanceCounterStorageUint64KHR  = VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR;
constexpr auto PerformanceCounterStorageFloat32KHR = VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR;
constexpr auto PerformanceCounterStorageFloat64KHR = VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR;
//};

//enum PerformanceCounterUnitKHR {
constexpr auto PerformanceCounterUnitGenericKHR        = VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR;
constexpr auto PerformanceCounterUnitPercentageKHR     = VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR;
constexpr auto PerformanceCounterUnitNanosecondsKHR    = VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR;
constexpr auto PerformanceCounterUnitBytesKHR          = VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR;
constexpr auto PerformanceCounterUnitBytesPerSecondKHR = VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR;
constexpr auto PerformanceCounterUnitKelvinKHR         = VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR;
constexpr auto PerformanceCounterUnitWattsKHR          = VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR;
constexpr auto PerformanceCounterUnitVoltsKHR          = VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR;
constexpr auto PerformanceCounterUnitAmpsKHR           = VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR;
constexpr auto PerformanceCounterUnitHertzKHR          = VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR;
constexpr auto PerformanceCounterUnitCyclesKHR         = VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR;
//};

//enum AcquireProfilingLockKHR {
//};

#ifdef VK_USE_PLATFORM_IOS_MVK
//enum IOSSurfaceCreateMVK {
//};
#endif  // VK_USE_PLATFORM_IOS_MVK

#ifdef VK_USE_PLATFORM_MACOS_MVK
//enum MacOSSurfaceCreateMVK {
//};
#endif  // VK_USE_PLATFORM_MACOS_MVK

//enum DebugUtilsMessageSeverityEXT {
constexpr auto DebugUtilsMessageSeverityVerboseBitEXT = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
constexpr auto DebugUtilsMessageSeverityInfoBitEXT    = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
constexpr auto DebugUtilsMessageSeverityWarningBitEXT = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
constexpr auto DebugUtilsMessageSeverityErrorBitEXT   = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
//};

//enum DebugUtilsMessageTypeEXT {
constexpr auto DebugUtilsMessageTypeGeneralBitEXT              = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
constexpr auto DebugUtilsMessageTypeValidationBitEXT           = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
constexpr auto DebugUtilsMessageTypePerformanceBitEXT          = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
constexpr auto DebugUtilsMessageTypeDeviceAddressBindingBitEXT = VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
//};

//enum DebugUtilsMessengerCallbackDataEXT {
//};

//enum DebugUtilsMessengerCreateEXT {
//};

//enum BlendOverlapEXT {
constexpr auto BlendOverlapUncorrelatedEXT = VK_BLEND_OVERLAP_UNCORRELATED_EXT;
constexpr auto BlendOverlapDisjointEXT     = VK_BLEND_OVERLAP_DISJOINT_EXT;
constexpr auto BlendOverlapConjointEXT     = VK_BLEND_OVERLAP_CONJOINT_EXT;
//};

//enum PipelineCoverageToColorStateCreateNV {
//};

//enum AccelerationStructureTypeKHR {
constexpr auto AccelerationStructureTypeTopLevelKHR    = VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR;
constexpr auto AccelerationStructureTypeBottomLevelKHR = VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR;
constexpr auto AccelerationStructureTypeGenericKHR     = VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR;
//};

//enum AccelerationStructureBuildTypeKHR {
constexpr auto AccelerationStructureBuildTypeHostKHR         = VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR;
constexpr auto AccelerationStructureBuildTypeDeviceKHR       = VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR;
constexpr auto AccelerationStructureBuildTypeHostOrDeviceKHR = VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR;
//};

//enum GeometryKHR {
constexpr auto GeometryOpaqueBitKHR                      = VK_GEOMETRY_OPAQUE_BIT_KHR;
constexpr auto GeometryNoDuplicateAnyHitInvocationBitKHR = VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR;
//};

//enum GeometryInstanceKHR {
constexpr auto GeometryInstanceTriangleFacingCullDisableBitKHR     = VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR;
constexpr auto GeometryInstanceTriangleCullDisableBitKHR           = VK_GEOMETRY_INSTANCE_TRIANGLE_CULL_DISABLE_BIT_NV;
constexpr auto GeometryInstanceTriangleFlipFacingBitKHR            = VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR;
constexpr auto GeometryInstanceTriangleFrontCounterclockwiseBitKHR = VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR;
constexpr auto GeometryInstanceForceOpaqueBitKHR                   = VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR;
constexpr auto GeometryInstanceForceNoOpaqueBitKHR                 = VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR;
constexpr auto GeometryInstanceForceOpacityMicromap2StateBitEXTKHR = VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_BIT_EXT;
constexpr auto GeometryInstanceDisableOpacityMicromapsBitEXTKHR    = VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_BIT_EXT;
//};

//enum BuildAccelerationStructureKHR {
constexpr auto BuildAccelerationStructureAllowUpdateBitKHR                       = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR;
constexpr auto BuildAccelerationStructureAllowCompactionBitKHR                   = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR;
constexpr auto BuildAccelerationStructurePreferFastTraceBitKHR                   = VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR;
constexpr auto BuildAccelerationStructurePreferFastBuildBitKHR                   = VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR;
constexpr auto BuildAccelerationStructureLowMemoryBitKHR                         = VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR;
constexpr auto BuildAccelerationStructureMotionBitNVKHR                          = VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV;
constexpr auto BuildAccelerationStructureAllowOpacityMicromapUpdateBitEXTKHR     = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_BIT_EXT;
constexpr auto BuildAccelerationStructureAllowDisableOpacityMicromapsBitEXTKHR   = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_BIT_EXT;
constexpr auto BuildAccelerationStructureAllowOpacityMicromapDataUpdateBitEXTKHR = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_BIT_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto BuildAccelerationStructureAllowDisplacementMicromapUpdateBitNVKHR = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_BIT_NV;
constexpr auto BuildAccelerationStructureAllowDisplacementMicromapUpdateKHR      = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
constexpr auto BuildAccelerationStructureAllowDataAccessBitKHR                   = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_BIT_KHR;
constexpr auto BuildAccelerationStructureAllowClusterOpacityMicromapsBitNVKHR    = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_CLUSTER_OPACITY_MICROMAPS_BIT_NV;
//};

//enum CopyAccelerationStructureModeKHR {
constexpr auto CopyAccelerationStructureModeCloneKHR       = VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR;
constexpr auto CopyAccelerationStructureModeCompactKHR     = VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR;
constexpr auto CopyAccelerationStructureModeSerializeKHR   = VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR;
constexpr auto CopyAccelerationStructureModeDeserializeKHR = VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR;
//};

//enum GeometryTypeKHR {
constexpr auto GeometryTypeTrianglesKHR            = VK_GEOMETRY_TYPE_TRIANGLES_KHR;
constexpr auto GeometryTypeAabbsKHR                = VK_GEOMETRY_TYPE_AABBS_KHR;
constexpr auto GeometryTypeInstancesKHR            = VK_GEOMETRY_TYPE_INSTANCES_KHR;
constexpr auto GeometryTypeSpheresNVKHR            = VK_GEOMETRY_TYPE_SPHERES_NV;
constexpr auto GeometryTypeLinearSweptSpheresNVKHR = VK_GEOMETRY_TYPE_LINEAR_SWEPT_SPHERES_NV;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto GeometryTypeDenseGeometryFormatTrianglesAMDXKHR = VK_GEOMETRY_TYPE_DENSE_GEOMETRY_FORMAT_TRIANGLES_AMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
//};

//enum AccelerationStructureCompatibilityKHR {
constexpr auto AccelerationStructureCompatibilityCompatibleKHR   = VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR;
constexpr auto AccelerationStructureCompatibilityIncompatibleKHR = VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR;
//};

//enum AccelerationStructureCreateKHR {
constexpr auto AccelerationStructureCreateDeviceAddressCaptureReplayBitKHR       = VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
constexpr auto AccelerationStructureCreateDescriptorBufferCaptureReplayBitEXTKHR = VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
constexpr auto AccelerationStructureCreateMotionBitNVKHR                         = VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV;
//};

//enum BuildAccelerationStructureModeKHR {
constexpr auto BuildAccelerationStructureModeBuildKHR  = VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR;
constexpr auto BuildAccelerationStructureModeUpdateKHR = VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR;
//};

//enum RayTracingShaderGroupTypeKHR {
constexpr auto RayTracingShaderGroupTypeGeneralKHR            = VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR;
constexpr auto RayTracingShaderGroupTypeTrianglesHitGroupKHR  = VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR;
constexpr auto RayTracingShaderGroupTypeProceduralHitGroupKHR = VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR;
//};

//enum ShaderGroupShaderKHR {
constexpr auto ShaderGroupShaderGeneralKHR      = VK_SHADER_GROUP_SHADER_GENERAL_KHR;
constexpr auto ShaderGroupShaderClosestHitKHR   = VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR;
constexpr auto ShaderGroupShaderAnyHitKHR       = VK_SHADER_GROUP_SHADER_ANY_HIT_KHR;
constexpr auto ShaderGroupShaderIntersectionKHR = VK_SHADER_GROUP_SHADER_INTERSECTION_KHR;
//};

//enum CoverageModulationModeNV {
constexpr auto CoverageModulationModeNoneNV  = VK_COVERAGE_MODULATION_MODE_NONE_NV;
constexpr auto CoverageModulationModeRgbNV   = VK_COVERAGE_MODULATION_MODE_RGB_NV;
constexpr auto CoverageModulationModeAlphaNV = VK_COVERAGE_MODULATION_MODE_ALPHA_NV;
constexpr auto CoverageModulationModeRgbaNV  = VK_COVERAGE_MODULATION_MODE_RGBA_NV;
//};

//enum PipelineCoverageModulationStateCreateNV {
//};

//enum ValidationCacheHeaderVersionEXT {
constexpr auto ValidationCacheHeaderVersionOneEXT = VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT;
//};

//enum ValidationCacheCreateEXT {
//};

//enum ShadingRatePaletteEntryNV {
constexpr auto ShadingRatePaletteEntryNoInvocationsNV           = VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV;
constexpr auto ShadingRatePaletteEntry16InvocationsPerPixelNV   = VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV;
constexpr auto ShadingRatePaletteEntry8InvocationsPerPixelNV    = VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV;
constexpr auto ShadingRatePaletteEntry4InvocationsPerPixelNV    = VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV;
constexpr auto ShadingRatePaletteEntry2InvocationsPerPixelNV    = VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPerPixelNV     = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer2X1PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer1X2PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer2X2PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer4X2PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer2X4PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV;
constexpr auto ShadingRatePaletteEntry1InvocationPer4X4PixelsNV = VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV;
//};

//enum CoarseSampleOrderTypeNV {
constexpr auto CoarseSampleOrderTypeDefaultNV     = VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV;
constexpr auto CoarseSampleOrderTypeCustomNV      = VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV;
constexpr auto CoarseSampleOrderTypePixelMajorNV  = VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV;
constexpr auto CoarseSampleOrderTypeSampleMajorNV = VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV;
//};

//enum AccelerationStructureMemoryRequirementsTypeNV {
constexpr auto AccelerationStructureMemoryRequirementsTypeObjectNV        = VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV;
constexpr auto AccelerationStructureMemoryRequirementsTypeBuildScratchNV  = VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV;
constexpr auto AccelerationStructureMemoryRequirementsTypeUpdateScratchNV = VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV;
//};

//enum PipelineCompilerControlAMD {
//};

//enum MemoryOverallocationBehaviorAMD {
constexpr auto MemoryOverallocationBehaviorDefaultAMD    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD;
constexpr auto MemoryOverallocationBehaviorAllowedAMD    = VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD;
constexpr auto MemoryOverallocationBehaviorDisallowedAMD = VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD;
//};

//enum PerformanceConfigurationTypeINTEL {
constexpr auto PerformanceConfigurationTypeCommandQueueMetricsDiscoveryActivatedINTEL = VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL;
//};

//enum QueryPoolSamplingModeINTEL {
constexpr auto QueryPoolSamplingModeManualINTEL = VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL;
//};

//enum PerformanceOverrideTypeINTEL {
constexpr auto PerformanceOverrideTypeNullHardwareINTEL   = VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL;
constexpr auto PerformanceOverrideTypeFlushGpuCachesINTEL = VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL;
//};

//enum PerformanceParameterTypeINTEL {
constexpr auto PerformanceParameterTypeHwCountersSupportedINTEL   = VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL;
constexpr auto PerformanceParameterTypeStreamMarkerValidBitsINTEL = VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL;
//};

//enum PerformanceValueTypeINTEL {
constexpr auto PerformanceValueTypeUint32INTEL = VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL;
constexpr auto PerformanceValueTypeUint64INTEL = VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL;
constexpr auto PerformanceValueTypeFloatINTEL  = VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL;
constexpr auto PerformanceValueTypeBoolINTEL   = VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL;
constexpr auto PerformanceValueTypeStringINTEL = VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL;
//};

#ifdef VK_USE_PLATFORM_FUCHSIA
//enum ImagePipeSurfaceCreateFUCHSIA {
//};
#endif  // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_METAL_EXT
//enum MetalSurfaceCreateEXT {
//};
#endif  // VK_USE_PLATFORM_METAL_EXT

//enum FragmentShadingRateCombinerOpKHR {
constexpr auto FragmentShadingRateCombinerOpKeepKHR    = VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR;
constexpr auto FragmentShadingRateCombinerOpReplaceKHR = VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR;
constexpr auto FragmentShadingRateCombinerOpMinKHR     = VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR;
constexpr auto FragmentShadingRateCombinerOpMaxKHR     = VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR;
constexpr auto FragmentShadingRateCombinerOpMulKHR     = VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR;
//};

//enum ShaderCorePropertiesAMD {
//};

//enum ValidationFeatureEnableEXT {
constexpr auto ValidationFeatureEnableGpuAssistedEXT                   = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT;
constexpr auto ValidationFeatureEnableGpuAssistedReserveBindingSlotEXT = VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT;
constexpr auto ValidationFeatureEnableBestPracticesEXT                 = VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT;
constexpr auto ValidationFeatureEnableDebugPrintfEXT                   = VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT;
constexpr auto ValidationFeatureEnableSynchronizationValidationEXT     = VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT;
//};

//enum ValidationFeatureDisableEXT {
constexpr auto ValidationFeatureDisableAllEXT                   = VK_VALIDATION_FEATURE_DISABLE_ALL_EXT;
constexpr auto ValidationFeatureDisableShadersEXT               = VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT;
constexpr auto ValidationFeatureDisableThreadSafetyEXT          = VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT;
constexpr auto ValidationFeatureDisableApiParametersEXT         = VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT;
constexpr auto ValidationFeatureDisableObjectLifetimesEXT       = VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT;
constexpr auto ValidationFeatureDisableCoreChecksEXT            = VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT;
constexpr auto ValidationFeatureDisableUniqueHandlesEXT         = VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT;
constexpr auto ValidationFeatureDisableShaderValidationCacheEXT = VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT;
//};

//enum CoverageReductionModeNV {
constexpr auto CoverageReductionModeMergeNV    = VK_COVERAGE_REDUCTION_MODE_MERGE_NV;
constexpr auto CoverageReductionModeTruncateNV = VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV;
//};

//enum PipelineCoverageReductionStateCreateNV {
//};

//enum ProvokingVertexModeEXT {
constexpr auto ProvokingVertexModeFirstVertexEXT = VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT;
constexpr auto ProvokingVertexModeLastVertexEXT  = VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT;
//};

#ifdef VK_USE_PLATFORM_WIN32_KHR
//enum FullScreenExclusiveEXT {
constexpr auto FullScreenExclusiveDefaultEXT               = VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT;
constexpr auto FullScreenExclusiveAllowedEXT               = VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT;
constexpr auto FullScreenExclusiveDisallowedEXT            = VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT;
constexpr auto FullScreenExclusiveApplicationControlledEXT = VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT;
//};
#endif  // VK_USE_PLATFORM_WIN32_KHR

//enum HeadlessSurfaceCreateEXT {
//};

//enum PipelineExecutableStatisticFormatKHR {
constexpr auto PipelineExecutableStatisticFormatBool32KHR  = VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR;
constexpr auto PipelineExecutableStatisticFormatInt64KHR   = VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR;
constexpr auto PipelineExecutableStatisticFormatUint64KHR  = VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR;
constexpr auto PipelineExecutableStatisticFormatFloat64KHR = VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR;
//};

//enum IndirectStateNV {
constexpr auto IndirectStateFlagFrontfaceBitNV = VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV;
//};

//enum IndirectCommandsTokenTypeNV {
constexpr auto IndirectCommandsTokenTypeShaderGroupNV   = VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV;
constexpr auto IndirectCommandsTokenTypeStateFlagsNV    = VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV;
constexpr auto IndirectCommandsTokenTypeIndexBufferNV   = VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV;
constexpr auto IndirectCommandsTokenTypeVertexBufferNV  = VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV;
constexpr auto IndirectCommandsTokenTypePushConstantNV  = VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV;
constexpr auto IndirectCommandsTokenTypeDrawIndexedNV   = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV;
constexpr auto IndirectCommandsTokenTypeDrawNV          = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV;
constexpr auto IndirectCommandsTokenTypeDrawTasksNV     = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV;
constexpr auto IndirectCommandsTokenTypeDrawMeshTasksNV = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV;
constexpr auto IndirectCommandsTokenTypePipelineNV      = VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV;
constexpr auto IndirectCommandsTokenTypeDispatchNV      = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV;
//};

//enum IndirectCommandsLayoutUsageNV {
constexpr auto IndirectCommandsLayoutUsageExplicitPreprocessBitNV = VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV;
constexpr auto IndirectCommandsLayoutUsageIndexedSequencesBitNV   = VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV;
constexpr auto IndirectCommandsLayoutUsageUnorderedSequencesBitNV = VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV;
//};

//enum DepthBiasRepresentationEXT {
constexpr auto DepthBiasRepresentationLeastRepresentableValueFormatEXT     = VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT;
constexpr auto DepthBiasRepresentationLeastRepresentableValueForceUnormEXT = VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT;
constexpr auto DepthBiasRepresentationFloatEXT                             = VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT;
//};

//enum DeviceMemoryReportEventTypeEXT {
constexpr auto DeviceMemoryReportEventTypeAllocateEXT         = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT;
constexpr auto DeviceMemoryReportEventTypeFreeEXT             = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT;
constexpr auto DeviceMemoryReportEventTypeImportEXT           = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT;
constexpr auto DeviceMemoryReportEventTypeUnimportEXT         = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT;
constexpr auto DeviceMemoryReportEventTypeAllocationFailedEXT = VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT;
//};

//enum DeviceMemoryReportEXT {
//};

//enum VideoEncodeCapabilityKHR {
constexpr auto VideoEncodeCapabilityPrecedingExternallyEncodedBytesBitKHR           = VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR;
constexpr auto VideoEncodeCapabilityInsufficientBitstreamBufferRangeDetectionBitKHR = VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR;
constexpr auto VideoEncodeCapabilityQuantizationDeltaMapBitKHR                      = VK_VIDEO_ENCODE_CAPABILITY_QUANTIZATION_DELTA_MAP_BIT_KHR;
constexpr auto VideoEncodeCapabilityEmphasisMapBitKHR                               = VK_VIDEO_ENCODE_CAPABILITY_EMPHASIS_MAP_BIT_KHR;
//};

//enum VideoEncodeFeedbackKHR {
constexpr auto VideoEncodeFeedbackBitstreamBufferOffsetBitKHR = VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR;
constexpr auto VideoEncodeFeedbackBitstreamBytesWrittenBitKHR = VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR;
constexpr auto VideoEncodeFeedbackBitstreamHasOverridesBitKHR = VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR;
//};

//enum VideoEncodeUsageKHR {
constexpr auto VideoEncodeUsageDefaultKHR         = VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR;
constexpr auto VideoEncodeUsageTranscodingBitKHR  = VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR;
constexpr auto VideoEncodeUsageStreamingBitKHR    = VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR;
constexpr auto VideoEncodeUsageRecordingBitKHR    = VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR;
constexpr auto VideoEncodeUsageConferencingBitKHR = VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR;
//};

//enum VideoEncodeContentKHR {
constexpr auto VideoEncodeContentDefaultKHR     = VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR;
constexpr auto VideoEncodeContentCameraBitKHR   = VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR;
constexpr auto VideoEncodeContentDesktopBitKHR  = VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR;
constexpr auto VideoEncodeContentRenderedBitKHR = VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR;
//};

//enum VideoEncodeTuningModeKHR {
constexpr auto VideoEncodeTuningModeDefaultKHR         = VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR;
constexpr auto VideoEncodeTuningModeHighQualityKHR     = VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR;
constexpr auto VideoEncodeTuningModeLowLatencyKHR      = VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR;
constexpr auto VideoEncodeTuningModeUltraLowLatencyKHR = VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR;
constexpr auto VideoEncodeTuningModeLosslessKHR        = VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR;
//};

//enum VideoEncodeRateControlModeKHR {
constexpr auto VideoEncodeRateControlModeDefaultKHR     = VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR;
constexpr auto VideoEncodeRateControlModeDisabledBitKHR = VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR;
constexpr auto VideoEncodeRateControlModeCbrBitKHR      = VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR;
constexpr auto VideoEncodeRateControlModeVbrBitKHR      = VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR;
//};

//enum VideoEncodeKHR {
constexpr auto VideoEncodeIntraRefreshBitKHR             = VK_VIDEO_ENCODE_INTRA_REFRESH_BIT_KHR;
constexpr auto VideoEncodeWithQuantizationDeltaMapBitKHR = VK_VIDEO_ENCODE_WITH_QUANTIZATION_DELTA_MAP_BIT_KHR;
constexpr auto VideoEncodeWithEmphasisMapBitKHR          = VK_VIDEO_ENCODE_WITH_EMPHASIS_MAP_BIT_KHR;
//};

//enum VideoEncodeRateControlKHR {
//};

//enum DeviceDiagnosticsConfigNV {
constexpr auto DeviceDiagnosticsConfigEnableShaderDebugInfoBitNV      = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV;
constexpr auto DeviceDiagnosticsConfigEnableResourceTrackingBitNV     = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV;
constexpr auto DeviceDiagnosticsConfigEnableAutomaticCheckpointsBitNV = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV;
constexpr auto DeviceDiagnosticsConfigEnableShaderErrorReportingBitNV = VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV;
//};

//enum TileShadingRenderPassQCOM {
constexpr auto TileShadingRenderPassEnableBitQCOM           = VK_TILE_SHADING_RENDER_PASS_ENABLE_BIT_QCOM;
constexpr auto TileShadingRenderPassPerTileExecutionBitQCOM = VK_TILE_SHADING_RENDER_PASS_PER_TILE_EXECUTION_BIT_QCOM;
//};

#ifdef VK_USE_PLATFORM_METAL_EXT
//enum ExportMetalObjectTypeEXT {
constexpr auto ExportMetalObjectTypeMetalDeviceBitEXT       = VK_EXPORT_METAL_OBJECT_TYPE_METAL_DEVICE_BIT_EXT;
constexpr auto ExportMetalObjectTypeMetalCommandQueueBitEXT = VK_EXPORT_METAL_OBJECT_TYPE_METAL_COMMAND_QUEUE_BIT_EXT;
constexpr auto ExportMetalObjectTypeMetalBufferBitEXT       = VK_EXPORT_METAL_OBJECT_TYPE_METAL_BUFFER_BIT_EXT;
constexpr auto ExportMetalObjectTypeMetalTextureBitEXT      = VK_EXPORT_METAL_OBJECT_TYPE_METAL_TEXTURE_BIT_EXT;
constexpr auto ExportMetalObjectTypeMetalIosurfaceBitEXT    = VK_EXPORT_METAL_OBJECT_TYPE_METAL_IOSURFACE_BIT_EXT;
constexpr auto ExportMetalObjectTypeMetalSharedEventBitEXT  = VK_EXPORT_METAL_OBJECT_TYPE_METAL_SHARED_EVENT_BIT_EXT;
//};
#endif  // VK_USE_PLATFORM_METAL_EXT

//enum GraphicsPipelineLibraryEXT {
constexpr auto GraphicsPipelineLibraryVertexInputInterfaceBitEXT    = VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT;
constexpr auto GraphicsPipelineLibraryPreRasterizationShadersBitEXT = VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT;
constexpr auto GraphicsPipelineLibraryFragmentShaderBitEXT          = VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT;
constexpr auto GraphicsPipelineLibraryFragmentOutputInterfaceBitEXT = VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT;
//};

//enum FragmentShadingRateNV {
constexpr auto FragmentShadingRate1InvocationPerPixelNV     = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV;
constexpr auto FragmentShadingRate1InvocationPer1X2PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV;
constexpr auto FragmentShadingRate1InvocationPer2X1PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV;
constexpr auto FragmentShadingRate1InvocationPer2X2PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV;
constexpr auto FragmentShadingRate1InvocationPer2X4PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV;
constexpr auto FragmentShadingRate1InvocationPer4X2PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV;
constexpr auto FragmentShadingRate1InvocationPer4X4PixelsNV = VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV;
constexpr auto FragmentShadingRate2InvocationsPerPixelNV    = VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV;
constexpr auto FragmentShadingRate4InvocationsPerPixelNV    = VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV;
constexpr auto FragmentShadingRate8InvocationsPerPixelNV    = VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV;
constexpr auto FragmentShadingRate16InvocationsPerPixelNV   = VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV;
constexpr auto FragmentShadingRateNoInvocationsNV           = VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV;
//};

//enum FragmentShadingRateTypeNV {
constexpr auto FragmentShadingRateTypeFragmentSizeNV = VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV;
constexpr auto FragmentShadingRateTypeEnumsNV        = VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV;
//};

//enum AccelerationStructureMotionInstanceTypeNV {
constexpr auto AccelerationStructureMotionInstanceTypeStaticNV       = VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV;
constexpr auto AccelerationStructureMotionInstanceTypeMatrixMotionNV = VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV;
constexpr auto AccelerationStructureMotionInstanceTypeSrtMotionNV    = VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV;
//};

//enum AccelerationStructureMotionInfoNV {
//};

//enum AccelerationStructureMotionInstanceNV {
//};

//enum ImageCompressionEXT {
constexpr auto ImageCompressionDefaultEXT           = VK_IMAGE_COMPRESSION_DEFAULT_EXT;
constexpr auto ImageCompressionFixedRateDefaultEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT;
constexpr auto ImageCompressionFixedRateExplicitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT;
constexpr auto ImageCompressionDisabledEXT          = VK_IMAGE_COMPRESSION_DISABLED_EXT;
//};

//enum ImageCompressionFixedRateEXT {
constexpr auto ImageCompressionFixedRateNoneEXT     = VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT;
constexpr auto ImageCompressionFixedRate1BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate2BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate3BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate4BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate5BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate6BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate7BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate8BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate9BpcBitEXT  = VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate10BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate11BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate12BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate13BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate14BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate15BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate16BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate17BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate18BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate19BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate20BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate21BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate22BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate23BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT;
constexpr auto ImageCompressionFixedRate24BpcBitEXT = VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT;
//};

//enum DeviceFaultAddressTypeEXT {
constexpr auto DeviceFaultAddressTypeNoneEXT                      = VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT;
constexpr auto DeviceFaultAddressTypeReadInvalidEXT               = VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT;
constexpr auto DeviceFaultAddressTypeWriteInvalidEXT              = VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT;
constexpr auto DeviceFaultAddressTypeExecuteInvalidEXT            = VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT;
constexpr auto DeviceFaultAddressTypeInstructionPointerUnknownEXT = VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT;
constexpr auto DeviceFaultAddressTypeInstructionPointerInvalidEXT = VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT;
constexpr auto DeviceFaultAddressTypeInstructionPointerFaultEXT   = VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT;
//};

//enum DeviceFaultVendorBinaryHeaderVersionEXT {
constexpr auto DeviceFaultVendorBinaryHeaderVersionOneEXT = VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT;
//};

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
//enum DirectFBSurfaceCreateEXT {
//};
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT

//enum DeviceAddressBindingEXT {
constexpr auto DeviceAddressBindingInternalObjectBitEXT = VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT;
//};

//enum DeviceAddressBindingTypeEXT {
constexpr auto DeviceAddressBindingTypeBindEXT   = VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT;
constexpr auto DeviceAddressBindingTypeUnbindEXT = VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT;
//};

#ifdef VK_USE_PLATFORM_FUCHSIA
//enum ImageConstraintsInfoFUCHSIA {
constexpr auto ImageConstraintsInfoCpuReadRarelyFUCHSIA     = VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA;
constexpr auto ImageConstraintsInfoCpuReadOftenFUCHSIA      = VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA;
constexpr auto ImageConstraintsInfoCpuWriteRarelyFUCHSIA    = VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA;
constexpr auto ImageConstraintsInfoCpuWriteOftenFUCHSIA     = VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA;
constexpr auto ImageConstraintsInfoProtectedOptionalFUCHSIA = VK_IMAGE_CONSTRAINTS_INFO_PROTECTED_OPTIONAL_FUCHSIA;
//};

//enum ImageFormatConstraintsFUCHSIA {
//};
#endif  // VK_USE_PLATFORM_FUCHSIA

//enum FrameBoundaryEXT {
constexpr auto FrameBoundaryFrameEndBitEXT = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
//};

#ifdef VK_USE_PLATFORM_SCREEN_QNX
//enum ScreenSurfaceCreateQNX {
//};
#endif  // VK_USE_PLATFORM_SCREEN_QNX

//enum VideoEncodeRgbModelConversionVALVE {
constexpr auto VideoEncodeRgbModelConversionRgbIdentityBitVALVE   = VK_VIDEO_ENCODE_RGB_MODEL_CONVERSION_RGB_IDENTITY_BIT_VALVE;
constexpr auto VideoEncodeRgbModelConversionYcbcrIdentityBitVALVE = VK_VIDEO_ENCODE_RGB_MODEL_CONVERSION_YCBCR_IDENTITY_BIT_VALVE;
constexpr auto VideoEncodeRgbModelConversionYcbcr709BitVALVE      = VK_VIDEO_ENCODE_RGB_MODEL_CONVERSION_YCBCR_709_BIT_VALVE;
constexpr auto VideoEncodeRgbModelConversionYcbcr601BitVALVE      = VK_VIDEO_ENCODE_RGB_MODEL_CONVERSION_YCBCR_601_BIT_VALVE;
constexpr auto VideoEncodeRgbModelConversionYcbcr2020BitVALVE     = VK_VIDEO_ENCODE_RGB_MODEL_CONVERSION_YCBCR_2020_BIT_VALVE;
//};

//enum VideoEncodeRgbRangeCompressionVALVE {
constexpr auto VideoEncodeRgbRangeCompressionFullRangeBitVALVE   = VK_VIDEO_ENCODE_RGB_RANGE_COMPRESSION_FULL_RANGE_BIT_VALVE;
constexpr auto VideoEncodeRgbRangeCompressionNarrowRangeBitVALVE = VK_VIDEO_ENCODE_RGB_RANGE_COMPRESSION_NARROW_RANGE_BIT_VALVE;
//};

//enum VideoEncodeRgbChromaOffsetVALVE {
constexpr auto VideoEncodeRgbChromaOffsetCositedEvenBitVALVE = VK_VIDEO_ENCODE_RGB_CHROMA_OFFSET_COSITED_EVEN_BIT_VALVE;
constexpr auto VideoEncodeRgbChromaOffsetMidpointBitVALVE    = VK_VIDEO_ENCODE_RGB_CHROMA_OFFSET_MIDPOINT_BIT_VALVE;
//};

//enum MicromapTypeEXT {
constexpr auto MicromapTypeOpacityMicromapEXT = VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
constexpr auto MicromapTypeDisplacementMicromapNVEXT = VK_MICROMAP_TYPE_DISPLACEMENT_MICROMAP_NV;
#endif  // VK_ENABLE_BETA_EXTENSIONS
//};

//enum BuildMicromapEXT {
constexpr auto BuildMicromapPreferFastTraceBitEXT = VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT;
constexpr auto BuildMicromapPreferFastBuildBitEXT = VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT;
constexpr auto BuildMicromapAllowCompactionBitEXT = VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT;
//};

//enum CopyMicromapModeEXT {
constexpr auto CopyMicromapModeCloneEXT       = VK_COPY_MICROMAP_MODE_CLONE_EXT;
constexpr auto CopyMicromapModeSerializeEXT   = VK_COPY_MICROMAP_MODE_SERIALIZE_EXT;
constexpr auto CopyMicromapModeDeserializeEXT = VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT;
constexpr auto CopyMicromapModeCompactEXT     = VK_COPY_MICROMAP_MODE_COMPACT_EXT;
//};

//enum MicromapCreateEXT {
constexpr auto MicromapCreateDeviceAddressCaptureReplayBitEXT = VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT;
//};

//enum BuildMicromapModeEXT {
constexpr auto BuildMicromapModeBuildEXT = VK_BUILD_MICROMAP_MODE_BUILD_EXT;
//};

//enum OpacityMicromapFormatEXT {
constexpr auto OpacityMicromapFormat2StateEXT = VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT;
constexpr auto OpacityMicromapFormat4StateEXT = VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT;
//};

//enum OpacityMicromapSpecialIndexEXT {
constexpr auto OpacityMicromapSpecialIndexFullyTransparentEXT                        = VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT;
constexpr auto OpacityMicromapSpecialIndexFullyOpaqueEXT                             = VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT;
constexpr auto OpacityMicromapSpecialIndexFullyUnknownTransparentEXT                 = VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT;
constexpr auto OpacityMicromapSpecialIndexFullyUnknownOpaqueEXT                      = VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT;
constexpr auto OpacityMicromapSpecialIndexClusterGeometryDisableOpacityMicromapNVEXT = VK_OPACITY_MICROMAP_SPECIAL_INDEX_CLUSTER_GEOMETRY_DISABLE_OPACITY_MICROMAP_NV;
//};

#ifdef VK_ENABLE_BETA_EXTENSIONS
//enum DisplacementMicromapFormatNV {
constexpr auto DisplacementMicromapFormat64Triangles64BytesNV    = VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV;
constexpr auto DisplacementMicromapFormat256Triangles128BytesNV  = VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV;
constexpr auto DisplacementMicromapFormat1024Triangles128BytesNV = VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV;
//};
#endif  // VK_ENABLE_BETA_EXTENSIONS

//enum PhysicalDeviceSchedulingControlsARM : uint64_t {
constexpr auto PhysicalDeviceSchedulingControlsShaderCoreCountARM = VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM;
//};

//enum MemoryDecompressionMethodNV : uint64_t {
constexpr auto MemoryDecompressionMethodGdeflate10BitNV = VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_NV;
//};

//enum RayTracingLssIndexingModeNV {
constexpr auto RayTracingLssIndexingModeListNV       = VK_RAY_TRACING_LSS_INDEXING_MODE_LIST_NV;
constexpr auto RayTracingLssIndexingModeSuccessiveNV = VK_RAY_TRACING_LSS_INDEXING_MODE_SUCCESSIVE_NV;
//};

//enum RayTracingLssPrimitiveEndCapsModeNV {
constexpr auto RayTracingLssPrimitiveEndCapsModeNoneNV    = VK_RAY_TRACING_LSS_PRIMITIVE_END_CAPS_MODE_NONE_NV;
constexpr auto RayTracingLssPrimitiveEndCapsModeChainedNV = VK_RAY_TRACING_LSS_PRIMITIVE_END_CAPS_MODE_CHAINED_NV;
//};

//enum SubpassMergeStatusEXT {
constexpr auto SubpassMergeStatusMergedEXT                               = VK_SUBPASS_MERGE_STATUS_MERGED_EXT;
constexpr auto SubpassMergeStatusDisallowedEXT                           = VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT;
constexpr auto SubpassMergeStatusNotMergedSideEffectsEXT                 = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT;
constexpr auto SubpassMergeStatusNotMergedSamplesMismatchEXT             = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT;
constexpr auto SubpassMergeStatusNotMergedViewsMismatchEXT               = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT;
constexpr auto SubpassMergeStatusNotMergedAliasingEXT                    = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT;
constexpr auto SubpassMergeStatusNotMergedDependenciesEXT                = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT;
constexpr auto SubpassMergeStatusNotMergedIncompatibleInputAttachmentEXT = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT;
constexpr auto SubpassMergeStatusNotMergedTooManyAttachmentsEXT          = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT;
constexpr auto SubpassMergeStatusNotMergedInsufficientStorageEXT         = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT;
constexpr auto SubpassMergeStatusNotMergedDepthStencilCountEXT           = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT;
constexpr auto SubpassMergeStatusNotMergedResolveAttachmentReuseEXT      = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT;
constexpr auto SubpassMergeStatusNotMergedSingleSubpassEXT               = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT;
constexpr auto SubpassMergeStatusNotMergedUnspecifiedEXT                 = VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT;
//};

//enum DirectDriverLoadingModeLUNARG {
constexpr auto DirectDriverLoadingModeExclusiveLUNARG = VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG;
constexpr auto DirectDriverLoadingModeInclusiveLUNARG = VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG;
//};

//enum DirectDriverLoadingLUNARG {
//};

//enum TensorCreateARM : uint64_t {
constexpr auto TensorCreateMutableFormatBitARM                 = VK_TENSOR_CREATE_MUTABLE_FORMAT_BIT_ARM;
constexpr auto TensorCreateProtectedBitARM                     = VK_TENSOR_CREATE_PROTECTED_BIT_ARM;
constexpr auto TensorCreateDescriptorBufferCaptureReplayBitARM = VK_TENSOR_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM;
//};

//enum TensorViewCreateARM : uint64_t {
constexpr auto TensorViewCreateDescriptorBufferCaptureReplayBitARM = VK_TENSOR_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_ARM;
//};

//enum TensorUsageARM : uint64_t {
constexpr auto TensorUsageShaderBitARM        = VK_TENSOR_USAGE_SHADER_BIT_ARM;
constexpr auto TensorUsageTransferSrcBitARM   = VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM;
constexpr auto TensorUsageTransferDstBitARM   = VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM;
constexpr auto TensorUsageImageAliasingBitARM = VK_TENSOR_USAGE_IMAGE_ALIASING_BIT_ARM;
constexpr auto TensorUsageDataGraphBitARM     = VK_TENSOR_USAGE_DATA_GRAPH_BIT_ARM;
//};

//enum TensorTilingARM {
constexpr auto TensorTilingOptimalARM = VK_TENSOR_TILING_OPTIMAL_ARM;
constexpr auto TensorTilingLinearARM  = VK_TENSOR_TILING_LINEAR_ARM;
//};

//enum OpticalFlowUsageNV {
constexpr auto OpticalFlowUsageUnknownNV       = VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV;
constexpr auto OpticalFlowUsageInputBitNV      = VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV;
constexpr auto OpticalFlowUsageOutputBitNV     = VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV;
constexpr auto OpticalFlowUsageHintBitNV       = VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV;
constexpr auto OpticalFlowUsageCostBitNV       = VK_OPTICAL_FLOW_USAGE_COST_BIT_NV;
constexpr auto OpticalFlowUsageGlobalFlowBitNV = VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV;
//};

//enum OpticalFlowGridSizeNV {
constexpr auto OpticalFlowGridSizeUnknownNV    = VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV;
constexpr auto OpticalFlowGridSize1X1BitNV     = VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV;
constexpr auto OpticalFlowGridSize2X2BitNV     = VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV;
constexpr auto OpticalFlowGridSize4X4BitNV     = VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV;
constexpr auto OpticalFlowGridSize8X8BitNV     = VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV;
//};

//enum OpticalFlowPerformanceLevelNV {
constexpr auto OpticalFlowPerformanceLevelUnknownNV = VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV;
constexpr auto OpticalFlowPerformanceLevelSlowNV    = VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV;
constexpr auto OpticalFlowPerformanceLevelMediumNV  = VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV;
constexpr auto OpticalFlowPerformanceLevelFastNV    = VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV;
//};

//enum OpticalFlowSessionBindingPointNV {
constexpr auto OpticalFlowSessionBindingPointUnknownNV            = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV;
constexpr auto OpticalFlowSessionBindingPointInputNV              = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV;
constexpr auto OpticalFlowSessionBindingPointReferenceNV          = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV;
constexpr auto OpticalFlowSessionBindingPointHintNV               = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV;
constexpr auto OpticalFlowSessionBindingPointFlowVectorNV         = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV;
constexpr auto OpticalFlowSessionBindingPointBackwardFlowVectorNV = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV;
constexpr auto OpticalFlowSessionBindingPointCostNV               = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV;
constexpr auto OpticalFlowSessionBindingPointBackwardCostNV       = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV;
constexpr auto OpticalFlowSessionBindingPointGlobalFlowNV         = VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV;
//};

//enum OpticalFlowSessionCreateNV {
constexpr auto OpticalFlowSessionCreateEnableHintBitNV       = VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV;
constexpr auto OpticalFlowSessionCreateEnableCostBitNV       = VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV;
constexpr auto OpticalFlowSessionCreateEnableGlobalFlowBitNV = VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV;
constexpr auto OpticalFlowSessionCreateAllowRegionsBitNV     = VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV;
constexpr auto OpticalFlowSessionCreateBothDirectionsBitNV   = VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV;
//};

//enum OpticalFlowExecuteNV {
constexpr auto OpticalFlowExecuteDisableTemporalHintsBitNV = VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV;
//};

//enum AntiLagModeAMD {
constexpr auto AntiLagModeDriverControlAMD = VK_ANTI_LAG_MODE_DRIVER_CONTROL_AMD;
constexpr auto AntiLagModeOnAMD            = VK_ANTI_LAG_MODE_ON_AMD;
constexpr auto AntiLagModeOffAMD           = VK_ANTI_LAG_MODE_OFF_AMD;
//};

//enum AntiLagStageAMD {
constexpr auto AntiLagStageInputAMD   = VK_ANTI_LAG_STAGE_INPUT_AMD;
constexpr auto AntiLagStagePresentAMD = VK_ANTI_LAG_STAGE_PRESENT_AMD;
//};

#ifdef VK_ENABLE_BETA_EXTENSIONS
//enum CompressedTriangleFormatAMDX {
constexpr auto CompressedTriangleFormatDgf1AMDX = VK_COMPRESSED_TRIANGLE_FORMAT_DGF1_AMDX;
//};
#endif  // VK_ENABLE_BETA_EXTENSIONS

//enum ShaderCreateEXT {
constexpr auto ShaderCreateLinkStageBitEXT                     = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
constexpr auto ShaderCreateAllowVaryingSubgroupSizeBitEXT      = VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT;
constexpr auto ShaderCreateRequireFullSubgroupsBitEXT          = VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT;
constexpr auto ShaderCreateNoTaskShaderBitEXT                  = VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT;
constexpr auto ShaderCreateDispatchBaseBitEXT                  = VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT;
constexpr auto ShaderCreateFragmentShadingRateAttachmentBitEXT = VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT;
constexpr auto ShaderCreateFragmentDensityMapAttachmentBitEXT  = VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT;
constexpr auto ShaderCreateIndirectBindableBitEXT              = VK_SHADER_CREATE_INDIRECT_BINDABLE_BIT_EXT;
//};

//enum ShaderCodeTypeEXT {
constexpr auto ShaderCodeTypeBinaryEXT = VK_SHADER_CODE_TYPE_BINARY_EXT;
constexpr auto ShaderCodeTypeSpirvEXT  = VK_SHADER_CODE_TYPE_SPIRV_EXT;
//};

//enum PresentScalingKHR {
constexpr auto PresentScalingOneToOneBitKHR           = VK_PRESENT_SCALING_ONE_TO_ONE_BIT_KHR;
constexpr auto PresentScalingAspectRatioStretchBitKHR = VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_KHR;
constexpr auto PresentScalingStretchBitKHR            = VK_PRESENT_SCALING_STRETCH_BIT_KHR;
//};

//enum PresentGravityKHR {
constexpr auto PresentGravityMinBitKHR      = VK_PRESENT_GRAVITY_MIN_BIT_KHR;
constexpr auto PresentGravityMaxBitKHR      = VK_PRESENT_GRAVITY_MAX_BIT_KHR;
constexpr auto PresentGravityCenteredBitKHR = VK_PRESENT_GRAVITY_CENTERED_BIT_KHR;
//};

//enum RayTracingInvocationReorderModeNV {
constexpr auto RayTracingInvocationReorderModeNoneNV    = VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV;
constexpr auto RayTracingInvocationReorderModeReorderNV = VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV;
//};

//enum CooperativeVectorMatrixLayoutNV {
constexpr auto CooperativeVectorMatrixLayoutRowMajorNV           = VK_COOPERATIVE_VECTOR_MATRIX_LAYOUT_ROW_MAJOR_NV;
constexpr auto CooperativeVectorMatrixLayoutColumnMajorNV        = VK_COOPERATIVE_VECTOR_MATRIX_LAYOUT_COLUMN_MAJOR_NV;
constexpr auto CooperativeVectorMatrixLayoutInferencingOptimalNV = VK_COOPERATIVE_VECTOR_MATRIX_LAYOUT_INFERENCING_OPTIMAL_NV;
constexpr auto CooperativeVectorMatrixLayoutTrainingOptimalNV    = VK_COOPERATIVE_VECTOR_MATRIX_LAYOUT_TRAINING_OPTIMAL_NV;
//};

//enum ComponentTypeKHR {
constexpr auto ComponentTypeFloat16KHR       = VK_COMPONENT_TYPE_FLOAT16_KHR;
constexpr auto ComponentTypeFloat32KHR       = VK_COMPONENT_TYPE_FLOAT32_KHR;
constexpr auto ComponentTypeFloat64KHR       = VK_COMPONENT_TYPE_FLOAT64_KHR;
constexpr auto ComponentTypeSint8KHR         = VK_COMPONENT_TYPE_SINT8_KHR;
constexpr auto ComponentTypeSint16KHR        = VK_COMPONENT_TYPE_SINT16_KHR;
constexpr auto ComponentTypeSint32KHR        = VK_COMPONENT_TYPE_SINT32_KHR;
constexpr auto ComponentTypeSint64KHR        = VK_COMPONENT_TYPE_SINT64_KHR;
constexpr auto ComponentTypeUint8KHR         = VK_COMPONENT_TYPE_UINT8_KHR;
constexpr auto ComponentTypeUint16KHR        = VK_COMPONENT_TYPE_UINT16_KHR;
constexpr auto ComponentTypeUint32KHR        = VK_COMPONENT_TYPE_UINT32_KHR;
constexpr auto ComponentTypeUint64KHR        = VK_COMPONENT_TYPE_UINT64_KHR;
constexpr auto ComponentTypeBfloat16KHR      = VK_COMPONENT_TYPE_BFLOAT16_KHR;
constexpr auto ComponentTypeSint8PackedNVKHR = VK_COMPONENT_TYPE_SINT8_PACKED_NV;
constexpr auto ComponentTypeUint8PackedNVKHR = VK_COMPONENT_TYPE_UINT8_PACKED_NV;
constexpr auto ComponentTypeFloat8E4M3EXTKHR = VK_COMPONENT_TYPE_FLOAT8_E4M3_EXT;
constexpr auto ComponentTypeFloatE4M3KHR     = VK_COMPONENT_TYPE_FLOAT_E4M3_NV;
constexpr auto ComponentTypeFloat8E5M2EXTKHR = VK_COMPONENT_TYPE_FLOAT8_E5M2_EXT;
constexpr auto ComponentTypeFloatE5M2KHR     = VK_COMPONENT_TYPE_FLOAT_E5M2_NV;
//};

//enum LayerSettingTypeEXT {
constexpr auto LayerSettingTypeBool32EXT  = VK_LAYER_SETTING_TYPE_BOOL32_EXT;
constexpr auto LayerSettingTypeInt32EXT   = VK_LAYER_SETTING_TYPE_INT32_EXT;
constexpr auto LayerSettingTypeInt64EXT   = VK_LAYER_SETTING_TYPE_INT64_EXT;
constexpr auto LayerSettingTypeUint32EXT  = VK_LAYER_SETTING_TYPE_UINT32_EXT;
constexpr auto LayerSettingTypeUint64EXT  = VK_LAYER_SETTING_TYPE_UINT64_EXT;
constexpr auto LayerSettingTypeFloat32EXT = VK_LAYER_SETTING_TYPE_FLOAT32_EXT;
constexpr auto LayerSettingTypeFloat64EXT = VK_LAYER_SETTING_TYPE_FLOAT64_EXT;
constexpr auto LayerSettingTypeStringEXT  = VK_LAYER_SETTING_TYPE_STRING_EXT;
//};

//enum LatencyMarkerNV {
constexpr auto LatencyMarkerSimulationStartNV            = VK_LATENCY_MARKER_SIMULATION_START_NV;
constexpr auto LatencyMarkerSimulationEndNV              = VK_LATENCY_MARKER_SIMULATION_END_NV;
constexpr auto LatencyMarkerRendersubmitStartNV          = VK_LATENCY_MARKER_RENDERSUBMIT_START_NV;
constexpr auto LatencyMarkerRendersubmitEndNV            = VK_LATENCY_MARKER_RENDERSUBMIT_END_NV;
constexpr auto LatencyMarkerPresentStartNV               = VK_LATENCY_MARKER_PRESENT_START_NV;
constexpr auto LatencyMarkerPresentEndNV                 = VK_LATENCY_MARKER_PRESENT_END_NV;
constexpr auto LatencyMarkerInputSampleNV                = VK_LATENCY_MARKER_INPUT_SAMPLE_NV;
constexpr auto LatencyMarkerTriggerFlashNV               = VK_LATENCY_MARKER_TRIGGER_FLASH_NV;
constexpr auto LatencyMarkerOutOfBandRendersubmitStartNV = VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV;
constexpr auto LatencyMarkerOutOfBandRendersubmitEndNV   = VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV;
constexpr auto LatencyMarkerOutOfBandPresentStartNV      = VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV;
constexpr auto LatencyMarkerOutOfBandPresentEndNV        = VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV;
//};

//enum OutOfBandQueueTypeNV {
constexpr auto OutOfBandQueueTypeRenderNV  = VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV;
constexpr auto OutOfBandQueueTypePresentNV = VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV;
//};

//enum ScopeKHR {
constexpr auto ScopeDeviceKHR      = VK_SCOPE_DEVICE_KHR;
constexpr auto ScopeWorkgroupKHR   = VK_SCOPE_WORKGROUP_KHR;
constexpr auto ScopeSubgroupKHR    = VK_SCOPE_SUBGROUP_KHR;
constexpr auto ScopeQueueFamilyKHR = VK_SCOPE_QUEUE_FAMILY_KHR;
//};

//enum DataGraphPipelineSessionBindPointARM {
constexpr auto DataGraphPipelineSessionBindPointTransientARM = VK_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_TRANSIENT_ARM;
//};

//enum DataGraphPipelineSessionBindPointTypeARM {
constexpr auto DataGraphPipelineSessionBindPointTypeMemoryARM = VK_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_TYPE_MEMORY_ARM;
//};

//enum DataGraphPipelineSessionCreateARM : uint64_t {
constexpr auto DataGraphPipelineSessionCreateProtectedBitARM = VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM;
//};

//enum DataGraphPipelinePropertyARM {
constexpr auto DataGraphPipelinePropertyCreationLogARM = VK_DATA_GRAPH_PIPELINE_PROPERTY_CREATION_LOG_ARM;
constexpr auto DataGraphPipelinePropertyIdentifierARM  = VK_DATA_GRAPH_PIPELINE_PROPERTY_IDENTIFIER_ARM;
//};

//enum DataGraphPipelineDispatchARM : uint64_t {
//};

//enum PhysicalDeviceDataGraphProcessingEngineTypeARM {
constexpr auto PhysicalDeviceDataGraphProcessingEngineTypeDefaultARM = VK_PHYSICAL_DEVICE_DATA_GRAPH_PROCESSING_ENGINE_TYPE_DEFAULT_ARM;
//};

//enum PhysicalDeviceDataGraphOperationTypeARM {
constexpr auto PhysicalDeviceDataGraphOperationTypeSpirvExtendedInstructionSetARM = VK_PHYSICAL_DEVICE_DATA_GRAPH_OPERATION_TYPE_SPIRV_EXTENDED_INSTRUCTION_SET_ARM;
//};

//enum VideoEncodeAV1PredictionModeKHR {
constexpr auto VideoEncodeAV1PredictionModeIntraOnlyKHR              = VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_INTRA_ONLY_KHR;
constexpr auto VideoEncodeAV1PredictionModeSingleReferenceKHR        = VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_SINGLE_REFERENCE_KHR;
constexpr auto VideoEncodeAV1PredictionModeUnidirectionalCompoundKHR = VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_UNIDIRECTIONAL_COMPOUND_KHR;
constexpr auto VideoEncodeAV1PredictionModeBidirectionalCompoundKHR  = VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_BIDIRECTIONAL_COMPOUND_KHR;
//};

//enum VideoEncodeAV1RateControlGroupKHR {
constexpr auto VideoEncodeAV1RateControlGroupIntraKHR        = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_INTRA_KHR;
constexpr auto VideoEncodeAV1RateControlGroupPredictiveKHR   = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_PREDICTIVE_KHR;
constexpr auto VideoEncodeAV1RateControlGroupBipredictiveKHR = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_BIPREDICTIVE_KHR;
//};

//enum VideoEncodeAV1CapabilityKHR {
constexpr auto VideoEncodeAV1CapabilityPerRateControlGroupMinMaxQIndexBitKHR = VK_VIDEO_ENCODE_AV1_CAPABILITY_PER_RATE_CONTROL_GROUP_MIN_MAX_Q_INDEX_BIT_KHR;
constexpr auto VideoEncodeAV1CapabilityGenerateObuExtensionHeaderBitKHR      = VK_VIDEO_ENCODE_AV1_CAPABILITY_GENERATE_OBU_EXTENSION_HEADER_BIT_KHR;
constexpr auto VideoEncodeAV1CapabilityPrimaryReferenceCdfOnlyBitKHR         = VK_VIDEO_ENCODE_AV1_CAPABILITY_PRIMARY_REFERENCE_CDF_ONLY_BIT_KHR;
constexpr auto VideoEncodeAV1CapabilityFrameSizeOverrideBitKHR               = VK_VIDEO_ENCODE_AV1_CAPABILITY_FRAME_SIZE_OVERRIDE_BIT_KHR;
constexpr auto VideoEncodeAV1CapabilityMotionVectorScalingBitKHR             = VK_VIDEO_ENCODE_AV1_CAPABILITY_MOTION_VECTOR_SCALING_BIT_KHR;
constexpr auto VideoEncodeAV1CapabilityCompoundPredictionIntraRefreshBitKHR  = VK_VIDEO_ENCODE_AV1_CAPABILITY_COMPOUND_PREDICTION_INTRA_REFRESH_BIT_KHR;
//};

//enum VideoEncodeAV1StdKHR {
constexpr auto VideoEncodeAV1StdUniformTileSpacingFlagSetBitKHR = VK_VIDEO_ENCODE_AV1_STD_UNIFORM_TILE_SPACING_FLAG_SET_BIT_KHR;
constexpr auto VideoEncodeAV1StdSkipModePresentUnsetBitKHR      = VK_VIDEO_ENCODE_AV1_STD_SKIP_MODE_PRESENT_UNSET_BIT_KHR;
constexpr auto VideoEncodeAV1StdPrimaryRefFrameBitKHR           = VK_VIDEO_ENCODE_AV1_STD_PRIMARY_REF_FRAME_BIT_KHR;
constexpr auto VideoEncodeAV1StdDeltaBitQKHR                    = VK_VIDEO_ENCODE_AV1_STD_DELTA_Q_BIT_KHR;
//};

//enum VideoEncodeAV1SuperblockSizeKHR {
constexpr auto VideoEncodeAV1SuperblockSize64BitKHR  = VK_VIDEO_ENCODE_AV1_SUPERBLOCK_SIZE_64_BIT_KHR;
constexpr auto VideoEncodeAV1SuperblockSize128BitKHR = VK_VIDEO_ENCODE_AV1_SUPERBLOCK_SIZE_128_BIT_KHR;
//};

//enum VideoEncodeAV1RateControlKHR {
constexpr auto VideoEncodeAV1RateControlRegularGopBitKHR                 = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_REGULAR_GOP_BIT_KHR;
constexpr auto VideoEncodeAV1RateControlTemporalLayerPatternDyadicBitKHR = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR;
constexpr auto VideoEncodeAV1RateControlReferencePatternFlatBitKHR       = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR;
constexpr auto VideoEncodeAV1RateControlReferencePatternDyadicBitKHR     = VK_VIDEO_ENCODE_AV1_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR;
//};

//enum BlockMatchWindowCompareModeQCOM {
constexpr auto BlockMatchWindowCompareModeMinQCOM = VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM;
constexpr auto BlockMatchWindowCompareModeMaxQCOM = VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM;
//};

//enum CubicFilterWeightsQCOM {
constexpr auto CubicFilterWeightsCatmullRomQCOM          = VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM;
constexpr auto CubicFilterWeightsZeroTangentCardinalQCOM = VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM;
constexpr auto CubicFilterWeightsBSplineQCOM             = VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM;
constexpr auto CubicFilterWeightsMitchellNetravaliQCOM   = VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM;
//};

//enum LayeredDriverUnderlyingApiMSFT {
constexpr auto LayeredDriverUnderlyingApiNoneMSFT  = VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT;
constexpr auto LayeredDriverUnderlyingApiD3D12MSFT = VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT;
//};

//enum TimeDomainKHR {
constexpr auto TimeDomainDeviceKHR                  = VK_TIME_DOMAIN_DEVICE_KHR;
constexpr auto TimeDomainClockMonotonicKHR          = VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR;
constexpr auto TimeDomainClockMonotonicRawKHR       = VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR;
constexpr auto TimeDomainQueryPerformanceCounterKHR = VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR;
//};

//enum AddressCopyKHR {
constexpr auto AddressCopyDeviceLocalBitKHR = VK_ADDRESS_COPY_DEVICE_LOCAL_BIT_KHR;
constexpr auto AddressCopySparseBitKHR      = VK_ADDRESS_COPY_SPARSE_BIT_KHR;
constexpr auto AddressCopyProtectedBitKHR   = VK_ADDRESS_COPY_PROTECTED_BIT_KHR;
//};

//enum DisplaySurfaceStereoTypeNV {
constexpr auto DisplaySurfaceStereoTypeNoneNV              = VK_DISPLAY_SURFACE_STEREO_TYPE_NONE_NV;
constexpr auto DisplaySurfaceStereoTypeOnboardDinNV        = VK_DISPLAY_SURFACE_STEREO_TYPE_ONBOARD_DIN_NV;
constexpr auto DisplaySurfaceStereoTypeHdmi3DNV            = VK_DISPLAY_SURFACE_STEREO_TYPE_HDMI_3D_NV;
constexpr auto DisplaySurfaceStereoTypeInbandDisplayportNV = VK_DISPLAY_SURFACE_STEREO_TYPE_INBAND_DISPLAYPORT_NV;
//};

//enum VideoEncodeIntraRefreshModeKHR {
constexpr auto VideoEncodeIntraRefreshModeNoneKHR                   = VK_VIDEO_ENCODE_INTRA_REFRESH_MODE_NONE_KHR;
constexpr auto VideoEncodeIntraRefreshModePerPicturePartitionBitKHR = VK_VIDEO_ENCODE_INTRA_REFRESH_MODE_PER_PICTURE_PARTITION_BIT_KHR;
constexpr auto VideoEncodeIntraRefreshModeBlockBasedBitKHR          = VK_VIDEO_ENCODE_INTRA_REFRESH_MODE_BLOCK_BASED_BIT_KHR;
constexpr auto VideoEncodeIntraRefreshModeBlockRowBasedBitKHR       = VK_VIDEO_ENCODE_INTRA_REFRESH_MODE_BLOCK_ROW_BASED_BIT_KHR;
constexpr auto VideoEncodeIntraRefreshModeBlockColumnBasedBitKHR    = VK_VIDEO_ENCODE_INTRA_REFRESH_MODE_BLOCK_COLUMN_BASED_BIT_KHR;
//};

//enum PhysicalDeviceLayeredApiKHR {
constexpr auto PhysicalDeviceLayeredApiVulkanKHR   = VK_PHYSICAL_DEVICE_LAYERED_API_VULKAN_KHR;
constexpr auto PhysicalDeviceLayeredApiD3D12KHR    = VK_PHYSICAL_DEVICE_LAYERED_API_D3D12_KHR;
constexpr auto PhysicalDeviceLayeredApiMetalKHR    = VK_PHYSICAL_DEVICE_LAYERED_API_METAL_KHR;
constexpr auto PhysicalDeviceLayeredApiOpenglKHR   = VK_PHYSICAL_DEVICE_LAYERED_API_OPENGL_KHR;
constexpr auto PhysicalDeviceLayeredApiOpenglesKHR = VK_PHYSICAL_DEVICE_LAYERED_API_OPENGLES_KHR;
constexpr auto PhysicalDeviceLayeredApiOpenGLKHR   = VK_PHYSICAL_DEVICE_LAYERED_API_OPENGL_KHR;
constexpr auto PhysicalDeviceLayeredApiOpenGLESKHR = VK_PHYSICAL_DEVICE_LAYERED_API_OPENGLES_KHR;
//};

//enum ClusterAccelerationStructureClusterNV {
constexpr auto ClusterAccelerationStructureClusterAllowDisableOpacityMicromapsNV = VK_CLUSTER_ACCELERATION_STRUCTURE_CLUSTER_ALLOW_DISABLE_OPACITY_MICROMAPS_NV;
//};

//enum ClusterAccelerationStructureGeometryNV {
constexpr auto ClusterAccelerationStructureGeometryCullDisableBitNV                 = VK_CLUSTER_ACCELERATION_STRUCTURE_GEOMETRY_CULL_DISABLE_BIT_NV;
constexpr auto ClusterAccelerationStructureGeometryNoDuplicateAnyhitInvocationBitNV = VK_CLUSTER_ACCELERATION_STRUCTURE_GEOMETRY_NO_DUPLICATE_ANYHIT_INVOCATION_BIT_NV;
constexpr auto ClusterAccelerationStructureGeometryOpaqueBitNV                      = VK_CLUSTER_ACCELERATION_STRUCTURE_GEOMETRY_OPAQUE_BIT_NV;
//};

//enum ClusterAccelerationStructureAddressResolutionNV {
constexpr auto ClusterAccelerationStructureAddressResolutionNoneNV                         = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_NONE_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedDstImplicitDataBitNV = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_DST_IMPLICIT_DATA_BIT_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedScratchDataBitNV     = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_SCRATCH_DATA_BIT_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedDstAddressArrayBitNV = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_DST_ADDRESS_ARRAY_BIT_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedDstSizesArrayBitNV   = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_DST_SIZES_ARRAY_BIT_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedSrcInfosArrayBitNV   = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_SRC_INFOS_ARRAY_BIT_NV;
constexpr auto ClusterAccelerationStructureAddressResolutionIndirectedSrcInfosCountBitNV   = VK_CLUSTER_ACCELERATION_STRUCTURE_ADDRESS_RESOLUTION_INDIRECTED_SRC_INFOS_COUNT_BIT_NV;
//};

//enum ClusterAccelerationStructureIndexFormatNV {
constexpr auto ClusterAccelerationStructureIndexFormat8BitNV  = VK_CLUSTER_ACCELERATION_STRUCTURE_INDEX_FORMAT_8BIT_NV;
constexpr auto ClusterAccelerationStructureIndexFormat16BitNV = VK_CLUSTER_ACCELERATION_STRUCTURE_INDEX_FORMAT_16BIT_NV;
constexpr auto ClusterAccelerationStructureIndexFormat32BitNV = VK_CLUSTER_ACCELERATION_STRUCTURE_INDEX_FORMAT_32BIT_NV;
//};

//enum ClusterAccelerationStructureTypeNV {
constexpr auto ClusterAccelerationStructureTypeClustersBottomLevelNV     = VK_CLUSTER_ACCELERATION_STRUCTURE_TYPE_CLUSTERS_BOTTOM_LEVEL_NV;
constexpr auto ClusterAccelerationStructureTypeTriangleClusterNV         = VK_CLUSTER_ACCELERATION_STRUCTURE_TYPE_TRIANGLE_CLUSTER_NV;
constexpr auto ClusterAccelerationStructureTypeTriangleClusterTemplateNV = VK_CLUSTER_ACCELERATION_STRUCTURE_TYPE_TRIANGLE_CLUSTER_TEMPLATE_NV;
//};

//enum ClusterAccelerationStructureOpTypeNV {
constexpr auto ClusterAccelerationStructureOpTypeMoveObjectsNV                  = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_MOVE_OBJECTS_NV;
constexpr auto ClusterAccelerationStructureOpTypeBuildClustersBottomLevelNV     = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_BUILD_CLUSTERS_BOTTOM_LEVEL_NV;
constexpr auto ClusterAccelerationStructureOpTypeBuildTriangleClusterNV         = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_BUILD_TRIANGLE_CLUSTER_NV;
constexpr auto ClusterAccelerationStructureOpTypeBuildTriangleClusterTemplateNV = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_BUILD_TRIANGLE_CLUSTER_TEMPLATE_NV;
constexpr auto ClusterAccelerationStructureOpTypeInstantiateTriangleClusterNV   = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_INSTANTIATE_TRIANGLE_CLUSTER_NV;
constexpr auto ClusterAccelerationStructureOpTypeGetClusterTemplateIndicesNV    = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_TYPE_GET_CLUSTER_TEMPLATE_INDICES_NV;
//};

//enum ClusterAccelerationStructureOpModeNV {
constexpr auto ClusterAccelerationStructureOpModeImplicitDestinationsNV = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_MODE_IMPLICIT_DESTINATIONS_NV;
constexpr auto ClusterAccelerationStructureOpModeExplicitDestinationsNV = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_MODE_EXPLICIT_DESTINATIONS_NV;
constexpr auto ClusterAccelerationStructureOpModeComputeSizesNV         = VK_CLUSTER_ACCELERATION_STRUCTURE_OP_MODE_COMPUTE_SIZES_NV;
//};

//enum PartitionedAccelerationStructureOpTypeNV {
constexpr auto PartitionedAccelerationStructureOpTypeWriteInstanceNV             = VK_PARTITIONED_ACCELERATION_STRUCTURE_OP_TYPE_WRITE_INSTANCE_NV;
constexpr auto PartitionedAccelerationStructureOpTypeUpdateInstanceNV            = VK_PARTITIONED_ACCELERATION_STRUCTURE_OP_TYPE_UPDATE_INSTANCE_NV;
constexpr auto PartitionedAccelerationStructureOpTypeWritePartitionTranslationNV = VK_PARTITIONED_ACCELERATION_STRUCTURE_OP_TYPE_WRITE_PARTITION_TRANSLATION_NV;
//};

//enum PartitionedAccelerationStructureInstanceNV {
constexpr auto PartitionedAccelerationStructureInstanceFlagTriangleFacingCullDisableBitNV = VK_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_FACING_CULL_DISABLE_BIT_NV;
constexpr auto PartitionedAccelerationStructureInstanceFlagTriangleFlipFacingBitNV        = VK_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_FLIP_FACING_BIT_NV;
constexpr auto PartitionedAccelerationStructureInstanceFlagForceOpaqueBitNV               = VK_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_OPAQUE_BIT_NV;
constexpr auto PartitionedAccelerationStructureInstanceFlagForceNoOpaqueBitNV             = VK_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_NO_OPAQUE_BIT_NV;
constexpr auto PartitionedAccelerationStructureInstanceFlagEnableExplicitBoundingBoxNV    = VK_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCE_FLAG_ENABLE_EXPLICIT_BOUNDING_BOX_NV;
//};

//enum IndirectCommandsTokenTypeEXT {
constexpr auto IndirectCommandsTokenTypeExecutionSetEXT         = VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT;
constexpr auto IndirectCommandsTokenTypePushConstantEXT         = VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT;
constexpr auto IndirectCommandsTokenTypeSequenceIndexEXT        = VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT;
constexpr auto IndirectCommandsTokenTypeIndexBufferEXT          = VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT;
constexpr auto IndirectCommandsTokenTypeVertexBufferEXT         = VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT;
constexpr auto IndirectCommandsTokenTypeDrawIndexedEXT          = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_EXT;
constexpr auto IndirectCommandsTokenTypeDrawEXT                 = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_EXT;
constexpr auto IndirectCommandsTokenTypeDrawIndexedCountEXT     = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_COUNT_EXT;
constexpr auto IndirectCommandsTokenTypeDrawCountEXT            = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_COUNT_EXT;
constexpr auto IndirectCommandsTokenTypeDispatchEXT             = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_EXT;
constexpr auto IndirectCommandsTokenTypeDrawMeshTasksNVEXT      = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV_EXT;
constexpr auto IndirectCommandsTokenTypeDrawMeshTasksCountNVEXT = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_COUNT_NV_EXT;
constexpr auto IndirectCommandsTokenTypeDrawMeshTasksEXT        = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_EXT;
constexpr auto IndirectCommandsTokenTypeDrawMeshTasksCountEXT   = VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_COUNT_EXT;
constexpr auto IndirectCommandsTokenTypeTraceRays2EXT           = VK_INDIRECT_COMMANDS_TOKEN_TYPE_TRACE_RAYS2_EXT;
//};

//enum IndirectExecutionSetInfoTypeEXT {
constexpr auto IndirectExecutionSetInfoTypePipelinesEXT     = VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT;
constexpr auto IndirectExecutionSetInfoTypeShaderObjectsEXT = VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT;
//};

//enum IndirectCommandsLayoutUsageEXT {
constexpr auto IndirectCommandsLayoutUsageExplicitPreprocessBitEXT = VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_EXT;
constexpr auto IndirectCommandsLayoutUsageUnorderedSequencesBitEXT = VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_EXT;
//};

//enum IndirectCommandsInputModeEXT {
constexpr auto IndirectCommandsInputModeVulkanIndexBufferEXT = VK_INDIRECT_COMMANDS_INPUT_MODE_VULKAN_INDEX_BUFFER_EXT;
constexpr auto IndirectCommandsInputModeDxgiIndexBufferEXT   = VK_INDIRECT_COMMANDS_INPUT_MODE_DXGI_INDEX_BUFFER_EXT;
//};

//enum Access3KHR : uint64_t {
constexpr auto Access3NoneKHR = VK_ACCESS_3_NONE_KHR;
//};

//enum DepthClampModeEXT {
constexpr auto DepthClampModeViewportRangeEXT    = VK_DEPTH_CLAMP_MODE_VIEWPORT_RANGE_EXT;
constexpr auto DepthClampModeUserDefinedRangeEXT = VK_DEPTH_CLAMP_MODE_USER_DEFINED_RANGE_EXT;
//};

//enum DefaultVertexAttributeValueKHR {
constexpr auto DefaultVertexAttributeValueZeroZeroZeroZeroKHR = VK_DEFAULT_VERTEX_ATTRIBUTE_VALUE_ZERO_ZERO_ZERO_ZERO_KHR;
constexpr auto DefaultVertexAttributeValueZeroZeroZeroOneKHR  = VK_DEFAULT_VERTEX_ATTRIBUTE_VALUE_ZERO_ZERO_ZERO_ONE_KHR;
//};

#ifdef VK_USE_PLATFORM_OHOS
//enum SurfaceCreateOHOS {
//};
#endif  // VK_USE_PLATFORM_OHOS

VK_ENCAPSULATION_NAMESPACE_END