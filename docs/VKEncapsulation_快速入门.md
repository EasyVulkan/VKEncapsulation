#  VKEncapsulation 快速入门

[](二级标题)
## 目录

* [配置项目](#配置项目)
* [功能划分](#功能划分)
* [初始化 (施工中)](#初始化)
* [特性：基于线程的状态机](#特性基于线程的状态机)
* [填写结构体](#填写结构体)
* [调用函数](#调用函数)
* [注意事项：对编译器的要求](#注意事项对编译器的要求)
* [宏设置一览](#宏设置一览)

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
## 特性：基于线程的状态机

这是这个库区别于其他Vulkan的C++绑定库的重要特性。

在Vulkan程序中，一个线程中任意时刻只允许一个命令缓冲区处于录制状态。<br>
既然如此，在开始录制命令缓冲区后，理应可以完全省略各种 `vkCmd` 函数中的 `commandBuffer` 参数。

这个库考虑到常见的Vulkan多线程程序的写法，对**逻辑设备**、**队列**、**命令缓冲区**实现了基于线程的状态机机制，在需要填写相关参数时可以直接省略。<br>
（实现起来非常简单，用 `thread_local` 变量就行了）

// todo 具体说明

[](二级标题)
## 填写结构体

### 结构体初始化

* [复制初始化](https://cppreference.cn/w/cpp/language/copy_initialization)+在初始化器中链式调用setter填写数据成员（推荐）：

    ```cpp
    auto applicationInfo = ApplicationInfo{}.
        ApplicationName("Chime GUI Sample").
        EngineName("Chime Vulkan Renderer").
        EngineVersion(20260129).
        ApiVersion(VK_API_VERSION_1_4);
    ```

* [复制初始化](https://cppreference.cn/w/cpp/language/copy_initialization)+[聚合初始化](https://cppreference.cn/w/cpp/language/aggregate_initialization)风格，使用 `Structure` 取代类型占位符 `auto` ，等号右侧的类型为 *vulkan_core.h* 中定义的C结构体：

    ```cpp
    // 如果你嫌这个 Structure 太长还得切换大小写，你可以自行定义一个诸如 STRUCT 之类的模板别名
    Structure applicationInfo = VkApplicationInfo{
        .pApplicationName = "Chime GUI Sample",
        .pEngineName = "Chime Vulkan Renderer",
        .engineVersion = 20260129,
        .apiVersion = VK_API_VERSION_1_4
    };
    ```
[复制初始化](https://cppreference.cn/w/cpp/language/copy_initialization)是个C++术语，以上两种形式都不需要发生复制。<br>
无论哪种风格都不需要填写结构体的 `sType` 成员，都可以常量初始化。

### Setter

```cpp
auto instanceCreateInfo = InstanceCreateInfo{}.
    PNext(pNext_instanceCreateInfo).
    Flags(flags).
    ApplicationInfo(applicationInfo).
    EnabledLayers(instanceLayers).         // 这两行的参数是动态数组容器 std::vector
    EnabledExtensions(instanceExtensions); //
```

* 对于有关联的参数，会自动赋值相应值，比如调用 `PipelineDepthStencilStateCreateInfo{}.DepthCompareOp(...)` 会自动将 `VkPipelineDepthStencilStateCreateInfo::depthTestEnable` 设置为 `true` 。

* 对于需要提供数组的情况，这些setter接收非数组变量、C式数组、数组的包装类（ `std::array` ）、动态数组容器（ `std::vector` 、`std::string` 等）、引用数组的包装类（ `std::span` 等）等一系列满足特定类型约束的参数，也可以分别指定数组地址和元素个数。<br>
Vulkan-Hpp 实现了相同机制，不过这个库的实现对类型的检查更为严格（它用的是C++11，我用的是C++20，胜在有 `<concept>` ）。
* 会区分对象本身、参数、返回值的引用类型，有助于减少悬垂引用。

如果这些setter要设置的是一个指针变量（用于提供数组、大体积结构体的地址，字符串除外），默认情况下其参数必须能被绑定到左值引用（即不能是临时量）。<br>
在 `#include"` 这个库的文件前，定义宏 `VK_ENCAPSULATION_ALLOW_PASSING_TEMPORARY_ADDRESS_TO_SETTER` 可以将临时量提供给这些setter，以简化调用函数时的参数填写。<br>
（但是有注意事项，见后文[对编译器的要求](#注意事项对编译器的要求)）

### AddNextStructure(...)

该函数用于向结构体的pNext链添加结构体，如果设置成功，返回pNext链尾部的引用，因此加入N个结构体的效率是O(N)。

```cpp
graphicsPipelineCreateInfo.
    AddNextStructure(pipelineRenderingCreateInfo).
    AddNextStructure(renderingAttachmentLocationInfo);
```

如果之后要让设置的pNext链断开，可以向第三个参数引用传递一个 `BaseOutStructure**` 类型的二级指针：

```cpp
BaseOutStructure** ppNext;
deviceCreateInfo.AddNextStructure(physicalDevicesFeatures, false, ppNext); // 第二个参数用于指定加入pNext链的结构体的类型能否重复

/*...*/

device.Create(physicalDevice, deviceCreateInfo);
if (ppNext)
    *ppNext = nullptr;
```

[](二级标题)
## 调用函数

以创建描述符布局为例。

### 使用临时量作为参数

函数的参数列表中各类info结构体，可以直接使用临时量：

```cpp
auto descriptorSetLayoutBinding_gBuffer = DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT };
descriptorSetLayout_gBuffer.Create(DescriptorSetLayoutCreateInfo{}. // 这里创建临时的 DescriptorSetLayoutCreateInfo
    Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
    Bindings(descriptorSetLayoutBinding_gBuffer));
```

如前文 [填写结构体](#setter) 所言，结构体的setter中也可以提供临时量作为参数，真是非常省事呢：

```cpp
descriptorSetLayout_gBuffer.Create(DescriptorSetLayoutCreateInfo{}. // 这里创建临时的 DescriptorSetLayoutCreateInfo
    Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
    Bindings(DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT }));
```

### 链式设置参数

对于大多数只需要提供一个info结构体，或一个info加一个其他参数，或极个别需要提供两个info结构体的函数，可以直接链式地设置info中的参数。<br>
（实现原理：让函数返回一个以相关参数为成员变量的临时对象）

* 链式设置参数后利用RAII机制（利用析构器）执行函数：

```cpp
auto descriptorSetLayoutBinding_gBuffer = DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT };
descriptorSetLayout_gBuffer.Create().
    Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
    Bindings(descriptorSetLayoutBinding_gBuffer);
```

* 链式设置参数后通过隐式转型执行函数：

```cpp
auto descriptorSetLayoutBinding_gBuffer = DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT };
RESULT result = descriptorSetLayout_gBuffer.Create(). // 隐式转型
    Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
    Bindings(descriptorSetLayoutBinding_gBuffer);
```
```cpp
auto descriptorSetLayoutBinding_gBuffer = DescriptorSetLayoutBinding{ 0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT };
if (descriptorSetLayout_gBuffer.Create().             // 隐式转型
    Flags(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT).
    Bindings(descriptorSetLayoutBinding_gBuffer)) {
    /*...*/
}
```

因为存在后述的两个注意事项，链式设置参数并非是这个库默认可用的特性。<br>
你需要在 `#include"` 这个库的文件前，定义宏 `VK_ENCAPSULATION_ALLOW_RAII_FUNCTIONS` 以使用这一特性。 

### 注意事项：执行顺序

需要注意的是，C++语法规定[“所有临时对象都在对（词法上）包含其创建点的完整表达式求值的最后一步被销毁”](https://cppreference.cn/w/cpp/language/lifetime#Temporary_object_lifetime)，考虑以下情况：

```cpp
if ((VkeApp::Base().QueueFamilyProperties(i).queueFlags & queueFlags) == queueFlags)
    singleton.commandPool.Create(i).Flags(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT), // 这一行的函数链式设置参数，需要利用RAII机制执行其效果，注意这行是逗号结尾
    singleton.commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, singleton.commandBuffer);
```

这里 `if` 语句下的完整表达式是到分号结束为止，因此上述代码的实际执行效果是：

1. 填写 `Create(i).Flags(...)` 会填写命令池 `commandPool` 的创建信息。
2. 调用 `AllocateBuffers(...)` 分配命令缓冲区，但**此时还没创建命令池，函数执行失败**。
3. `Create(i).Flags(...)` 返回的临时对象发生析构，实际执行命令池的创建。

以下两种写法都是能正常达到预期效果的：

* 给 `if` 语句块加花括号，改逗号为分号：

    ```cpp
    if ((VkeApp::Base().QueueFamilyProperties(i).queueFlags & queueFlags) == queueFlags) {
        singleton.commandPool.Create(i).Flags(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
        singleton.commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, singleton.commandBuffer);
    }
    ```

* 直接向函数提供info结构体：

    ```cpp
    if ((VkeApp::Base().QueueFamilyProperties(i).queueFlags & queueFlags) == queueFlags)
        singleton.commandPool.Create(CommandPoolCreateInfo{}.QueueFamilyIndex(i).Flags(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT)),
        singleton.commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, singleton.commandBuffer);
    ```

### 注意事项：编译器优化

在开启优化的情况下，编译器可能会对临时量的使用进行激进的优化，因此需要对优化级别进行设置，详见后文 [对编译器的要求](#注意事项对编译器的要求) 。

[](二级标题)
## 注意事项：对编译器的要求

### MSVC

没有要求。

### CLang

没有要求（因为我做了相应处理）。

Core 中的代码必须在不开启优化的情况下进行编译，否则会优化掉临时量的零初始化，或把临时量的内存块提前优化掉。<br>
代码中已经用预编译指令对特定文件进行了相应处理，所以你什么都不用做。

至于不开优化对效率的影响么…由于这本就是个对“调接口”进行绑定和封装的库，所以不会有太大影响，图形程序的性能开销并不在向接口传递参数这种事上。

顺便，CLang在编译时默认情况下会很多管闲事地抛出一些无关紧要的警告信息，有碍找出有效的警告信息。<br>
你可以在 `#include"` 这个库的文件前，定义宏 `VK_ENCAPSULATION_IGNORE_CLANG_WARNINGS` 来关闭个别警告信息，具体关闭的列表见 [VKEncapsulation.h#L11](../VKEncapsulation/Core/VKEncapsulation.h#L11) 。

### GCC

我没装GCC（因此要是有GCC用户帮我测试下就好了，我不想仅仅因为这个理由安装它），这里对可能出现的情况做个指导。

就我使用 Compiler Explorer 的情况来看，GCC不太待见我的代码风格。<br>
虽然我清楚这一点并且在写这个库的时候已经相当收敛了，如果无法编译，请添加编译选项 `-fpermissive` 。<br>
当前版本的GCC已经不支持用预编译指令指定这个编译选项了，所以代码中我没写进去，你得在 CMakeLists.txt 等项目配置文件中自行指定。

然后不排除GCC跟CLang一样会进行激进优化，要是无法程序正常运行，试着在 `#include "Core/VKEncapsulation.h"` 前用预编译指令关闭优化：

```cpp
#pragma GCC optimize ("O0")
```

之后再用类似的语法开启优化即可。

[](二级标题)
## 宏设置一览

### 宏替换

* `VK_ENCAPSULATION_NAMESPACE`

    定义 VKEncapsulation 的命名空间，默认为 `vke` 。

* `VK_ENCAPSULATION_CALLBACK_TYPE`

    定义 VKEncapsulation 中使用的回调函数类型命名空间，默认为 `void(*)()` 。

* `VK_ENCAPSULATION_DEFAULT_SWAPCHAIN_EXTENT`

    定义 Core/VkAppBase.h 中的函数 `CreateSwapchain(...)` 创建交换链时的图像大小的缺省值，默认为 `1280, 720`。<br>
    （仅在 window surface 没有指定大小时使用该值， Windows 和 macOS 不会发生这种情况）

* [依赖项目录](#选项2使用宏在代码中自定义依赖项目录)

### 宏开关

* [`VK_ENCAPSULATION_IGNORE_CLANG_WARNINGS`](#CLang)

* [`VK_ENCAPSULATION_ALLOW_RAII_FUNCTIONS`](#链式设置参数)

* [`VK_ENCAPSULATION_ALLOW_PASSING_TEMPORARY_ADDRESS_TO_SETTER`](#Setter)

* `VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICES`

    //TODO

* `VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_THREADS`

    //TODO

* `VK_ENCAPSULATION_MAY_USE_OBJECT_SPECIFIC_HOST_MEMORY_ALLOCATOR`

    //TODO

* `VK_ENCAPSULATION_RAII_ONLY_PROMOTED_FUNCTIONS`

    //TODO

* `VK_ENCAPSULATION_RAII_ONLY_EXTENSION_FUNCTIONS`

    //TODO

* `VK_ENCAPSULATION_RESULT_THROW`

    //TODO

* `VK_ENCAPSULATION_RESULT_NODISCARD`

    //TODO