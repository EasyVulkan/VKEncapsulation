#pragma once

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
#include "VKAppBase.h"
#include "VKOop.h"

#ifdef VK_ENCAPSULATION_ALLOW_RAII_FUNCTION
#undef AUTO
#endif