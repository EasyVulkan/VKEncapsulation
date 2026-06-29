#pragma once
#include <concepts>
#include <array>
#include <vector>
#include <ranges>
#include <string>
#include <format>
#include <fstream>
#include <iostream>

#ifdef VK_ENCAPSULATION_IGNORE_CLANG_WARNINGS
#pragma clang diagnostic ignored "-Wdangling-else"
#pragma clang diagnostic ignored "-Wlogical-op-parentheses"
#pragma clang diagnostic ignored "-Wmissing-braces"
#pragma clang diagnostic ignored "-Wswitch"
#pragma clang diagnostic ignored "-Wunused-value"
#endif

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

#include M_VulkanSdkHeader(volk/volk.h)
#include M_VulkanSdkHeader(vulkan/vk_enum_string_helper.h)

#ifdef VK_ENCAPSULATION_ALLOW_RAII_FUNCTIONS
#ifdef __clang__
#pragma clang optimize off
#endif
#endif

#ifdef VK_ENCAPSULATION_ALLOW_PASSING_TEMPORARY_ADDRESS_TO_SETTER
#include "VKCore_Relaxed.h"
#else
#include "VKCore.h"
#endif

#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICES
#define M_InstantiationGuard_MayCreateMultipleDevices template<std::derived_from<void>>
#else
#define M_InstantiationGuard_MayCreateMultipleDevices
#endif

#include "VKAppBase.h"
#include "VKOop.h"
#include "VKEnum.h"

#ifdef VK_ENCAPSULATION_ALLOW_RAII_FUNCTIONS
#undef AUTO
#if defined __clang__ && defined NDEBUG
#pragma clang optimize on
#endif
#endif