#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <array>
#include <vector>
#include <string>
#include <ranges>
#include <format>
#include <concepts>

#define M_MakeStringLiteral(s) #s

#ifndef M_VulkanSdkHeader
#define M_VulkanSdkHeader(f)  M_MakeStringLiteral(f)
#endif
#ifndef M_VulkanSdkLibrary
#define M_VulkanSdkLibrary(f) M_MakeStringLiteral(f)
#endif
#ifndef M_GlfwHeader
#define M_GlfwHeader(f)       M_MakeStringLiteral(f)
#endif
#ifndef M_GlfwLibrary
#define M_GlfwLibrary(f)      M_MakeStringLiteral(f)
#endif

#ifdef VK_ENCAPSULATION_ALLOW_PASSING_TEMPORARY_ADDRESS_TO_SETTER
#include "VKCore_Relaxed.h"
#else
#include "VKCore.h"
#endif

#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
#define M_InstantiationGuard_MayCreateMultipleDevice template<std::derived_from<void>>
#else
#define M_InstantiationGuard_MayCreateMultipleDevice
#endif

#include "VKAppBase.h"
#include "VKOop.h"

#ifdef VK_ENCAPSULATION_ALLOW_RAII_FUNCTION
#undef AUTO
#endif