#  VKEncapsulation 编程指南

[](二级标题)
## 目录

* [配置项目](#配置项目)
* [功能划分](#功能划分)

[](二级标题)
## 配置项目

### 取得依赖项

你需要：

* **1.4.328** 或以上版本的 [Vulkan SDK](https://vulkan.lunarg.com/sdk/home)。

* [GLFW](https://www.glfw.org/download.html) 用于创建窗口（如果你只是在Windows上练习或写写玩具，可以不需要）。

* [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h) 用于读取图像。

安装 Vulkan SDK 时，勾选：

* GLM Headers

* Volk headers, source, and library.

GLFW通常选择下载预编译的binaries即可。

接下来，如果你不打算帮我写个高大全的 CMakeLists.txt 的话，你有两个选择：

### 选项1：添加依赖项到 Dependency 并在项目设置中指定附加目录

VKEncapsulation/Dependency 这个文件夹顾名思义，用于存放依赖项。

* 将 VulkanSDK安装目录/版本号/**Include** 目录下的 **vulkan**、**vk_video**、**glm**、**Volk** 这四个文件夹复制到 Dependency/Vulkan/**Include** 文件夹下。<br>
    （你可以干脆把 VulkanSDK安装目录/版本号/**Include** 整个复制粘贴到 **Dependency** ）

* 如果你需要在运行期编译GLSL：
    * 将 VulkanSDK安装目录/版本号/**Include** 目录下的 **shaderc** 文件夹复制到 Dependency/Vulkan/**Include** 。
    * 将 VulkanSDK安装目录/版本号/**Lib** 目录下的 **shaderc_shared.lib** 和 **shaderc_combined.lib** 复制到 Dependency/Vulkan/**Lib** 。

* 将 **glfw-版本号.bin.平台.zip** 中的 **include** 文件夹复制粘贴到 Dependency/GLFW 目录下（与既有占位用的 Dependency/GLFW/**include** 合并）。<br>
    从 **glfw-版本号.bin.平台.zip** 找到与你的开发环境匹配的 **lib-\*\*\*** 文件夹（VS2026 使用 lib-vc2022 中的即可），将其中的文件复制到 Dependency/GLFW/**lib** 目录下。

* 将 **stb_image.h** 复制到 Dependency 文件夹下。

然后，你需要给项目设定附加目录：

* 如果你使用近期大跌的老牌软件公司 MSFT 旗下的 Visual Studio 创建解决方案，在项目属性中做如下变更： 

    ```
    [所有配置, 所有平台]
    C/C++ → 常规 → 附加包含目录
    添加：
    $(ProjectDir)Dependency\Vulkan\Include;
    $(ProjectDir)Dependency\GLFW\include;

    [所有配置, Win32]
    链接器 → 常规 → 附加库目录
    添加：
    $(ProjectDir)Dependency\Vulkan\Lib;
    $(ProjectDir)Dependency\GLFW\lib;
    %(AdditionalLibraryDirectories)
    ```

* 如果你使用 CMake 构建项目，在 CMakeLists.txt 中加入如下代码：

    ```
    # 指定附加包含目录
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_SOURCE_DIR}/Dependency/Vulkan/Include"
        "${CMAKE_SOURCE_DIR}/Dependency/GLFW/include"
    )
    # 指定附加链接目录
    target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_SOURCE_DIR}/Dependency/Vulkan/Lib"
        "${CMAKE_SOURCE_DIR}/Dependency/GLFW/lib"
    )
    ```

### 选项2：使用宏在代码中自定义依赖项目录

你可以把这些依赖项放到你期望的位置，然后在代码中包含 VKEncapsulation 的文件前，定义以下宏，将“目录”字样替换成你期望的目录位置：

```cpp
#define VOLK_VULKAN_H_PATH    "目录/vulkan/vulkan.h"      // 这两行
#define M_VulkanSdkHeader(f)  M_MakeStringLiteral(目录/f) // 的“目录”存放 VulkanSDK安装目录/版本号/Include 下的文件

#define M_VulkanSdkLibrary(f) M_MakeStringLiteral(目录/f) // 此“目录”存放 VulkanSDK安装目录/版本号/Lib 中的文件

#define M_GlfwHeader(f)       M_MakeStringLiteral(目录/f) // 此“目录”存放 glfw-版本号.bin.平台.zip 中的 include 文件夹下的文件

#define M_GlfwLibrary(f)      M_MakeStringLiteral(目录/f) // 此“目录”存放 glfw-版本号.bin.平台.zip 中的 lib-*** 文件夹下的文件

#define M_StbHeader(f)        M_MakeStringLiteral(目录/f) // 此“目录”存放 stb_image.h
```

[](二级标题)
## 功能划分

VKEncapsulation 的功能被划分为三个部分，对应三个文件夹：

### Core

严格来讲，只有这个文件夹下的文件被我算作是 VKEncapsulation 的内容，WindowSystem 中的算是应用示例，而 Plus 中的代码……总感觉有些不上不下的。

* VKCore.h 提供对 *vulkan-core.h* 中函数的C++绑定、结构体的包装类、对象的RAII包装类（仅实现最基本的RAII机制，通过析构器实现对象的自动销毁）。

* VKAppBase.h 提供对使用单个逻辑设备及单个交换链的程序的语境管理，并封装了创建Vulkan实例、获取物理设备信息、创建逻辑设备、创建交换链等一系列初始化流程。

* VKOop.h 提供对Vulkan核心功能中各类对象的OOP封装，类成员函数囊括了核心功能中与该类对象有关的函数。

* VKEnum.h 提供了按驼峰法命名的与Vulkan枚举项对应的常量。<br>
    （其实我自己并没有使用这些常量，因为我觉得看着太奇怪了）

你不该单独包含这些文件，通过 `#include "Core/VKEncapsulation.h"` 以一次性包含以上文件。

### WindowSystem

* Glfw.h 使用 GLFW 创建窗口并完成初始化，并提供切换全屏/窗口模式、在窗口标题上显示帧数的功能。

* Win32.h 与前者提供的功能相同，不过直接使用Win32的API创建窗口。

这两个文件中都包含了 VKEncapsulation.h ，所以如果你愿意用我写好的现成的Vulkan图形程序初始化函数，直接 `#include "WindowSystem/Glfw.h"` 或  `#include "WindowSystem/Win32.h"` 即可。

### Plus

这些文件没VK前缀是因为我觉得其中的代码写得还不够标准（虽然我也不知道怎么才算更标准）。

* AppBasePlus.h 是我为一些常见的使用情形所写的封装，包含实现即时帧所需的同步对象、暂存缓冲区、2D贴图、2D贴图数组、立方体贴图、图像附件、三种查询等。

* GlslToSpv.h 提供了在运行期将 GLSL 代码编译为 Spir-V 二进制数据，并创建着色器模组的简易封装。

根据需要选择性地 `#include` Plus 中的文件。

[](二级标题)
## 初始化

参见：[VkAppBase.h 说明文档 (todo)]()。

[](二级标题)
## 基于线程的状态机

[](二级标题)
## 填写结构体

[](二级标题)
## 调用函数

[](二级标题)
## 注意事项：对编译器的要求

[](二级标题)
## 宏一览

### 宏开关

### 宏替换