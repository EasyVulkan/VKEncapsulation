#  `VK_ENCAPSULATION`

**VKEncapsulation** is a library offers C++ binding and encapsulation of ***vulkan_core.h*** for small projects.

**VKEncapsulation** 是一个Vulkan的C++绑定及封装库（仅 ***vulkan_core.h*** ，不包含特定平台的功能），适用于小型项目。

虽然文档正在施工，代码已经可以用了。

[](二级标题)
## 目录

* [功能与特性简述](#功能与特性简述)
* [简化代码的效果](#简化参数填写及函数调用的效果)
* [关于本项目](#关于本项目)
* [文档一览](#文档一览)
* [示例](#示例)

[](二级标题)
## 功能与特性简述

如果你有使用一些其他的Vulkan官方或第三方库，光看这个列表应该就能明白这个库的核心部分 [Core (文档还没写)]() 的功能定位：

* 这个使用 [volk](https://github.com/zeux/volk)。
* 这个库在功能上与 [vk-bootstrap](https://github.com/charles-lunarg/vk-bootstrap) 有所重合，但不如它强大（够用就好！）。
* 这个库在特性上与 [Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp) 有所重合，并在一些特性上有所强化。

以上三条分别对应：

* 利用 volk 获取所有函数的指针，无需手动获取扩展功能的函数指针（且 [Core/VKOop.h (文档还没写)]() 中的类成员函数会根据Vulkan运行时版本选择调用有/无扩展后缀的函数）。
* 封装了初始化流程，实现简单且可定制的初始化。
* 为 *vulkan_core.h* 提供C++绑定，简化参数填写、简化函数调用。

在此基础上有：

* [Core (文档还没写)]() 中的各个文件对 *vulkan_core.h* 提供不同程度的面向对象封装，你可以根据自己的编程风格选择使用部分功能和特性。
* [Plus (文档还没写)]() 中的文件提供功能上更加特定的封装。
* [WindowSystem (文档还没写)]() 中的文件提供了执行整个初始化流程的函数封装，以及其它与窗口系统有关的常用功能的函数封装（目前只有对应 [Glfw](https://www.glfw.org/) 和 Win32 API 的版本，因为我只有Win10系统的主机）。<br>
* 近似 C# 的命名风格。

如果你觉得这个库功能上有所欠缺，你也可以结合其它库一起使用。

[](二级标题)
## 简化参数填写及函数调用的效果

以录制推送描述符（push descriptor）命令为例。

使用 *Vulkan-Hpp* ：

```cpp
raii::CommandPool commandPool(device, CommandPoolCreateInfo{}.setFlags(CommandPoolCreateFlagBits::eResetCommandBuffer));
CommandBuffer commandBuffer = device.allocateCommandBuffers(CommandBufferAllocateInfo{}.
	setCommandPool(commandPool).
	setCommandBufferCount(1)).front();

/*...*/

commandBuffer.begin(CommandBufferBeginInfo{}.setFlags(CommandBufferUsageFlagBits::eOneTimeSubmit));

/*...*/

auto bufferInfo = DescriptorBufferInfo{ uniformBuffer, 0, VK_WHOLE_SIZE };
auto imageInfos = {
	DescriptorImageInfo{ VK_NULL_HANDLE, attachment_normalZ, ImageLayout::eShaderReadOnlyOptimal },
	DescriptorImageInfo{ VK_NULL_HANDLE, attachment_albedoSpecular, ImageLayout::eShaderReadOnlyOptimal } };
commandBuffer.pushDescriptorSet(PipelineBindPoint::eGraphics, pipelineLayout_composition, 0, {
	WriteDescriptorSet{}.
    	setDescriptorType(DescriptorType::eUniformBuffer).
    	setBufferInfo(bufferInfo),
	WriteDescriptorSet{}.
    	setDstBinding(1).
    	setDescriptorType(DescriptorType::eInputAttachment).
    	setImageInfo(imageInfos) }):
```

使用 *VKEncapsulation* ：

```cpp
oop::CommandPool commandPool(CommandPoolCreateInfo{}.Flags(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT)); // 省略队列族索引，默认为0
oop::CommandBuffer commandBuffer;
commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBuffer); // 无需填写 device，自动填写为当前线程中创建的逻辑设备

/*...*/

commandBuffer.Begin(FLAGS{ VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT });

/*...*/

auto bufferInfo = DescriptorBufferInfo{ uniformBuffer, 0, VK_WHOLE_SIZE };
auto imageInfos = {
    DescriptorImageInfo{ VK_NULL_HANDLE, attachment_normalZ, VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ },
    DescriptorImageInfo{ VK_NULL_HANDLE, attachment_albedoSpecular, VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ } };
CmdPushDescriptorSet(VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout_composition, 0, { // 无需填写 commandBuffer ，自动填写为当前线程中正在录制的命令缓冲区
    WriteDescriptorSet{}.
        DescriptorType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER).
        BufferInfo(bufferInfo),
    WriteDescriptorSet{}.
        DstBinding(1).
        DescriptorType(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT).
        ImageInfo(imageInfos) });
```

使用 *VKEncapsulation* ，**更激进**的写法：

```cpp
oop::CommandPool commandPool(FLAGS{ VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT });
oop::CommandBuffer commandBuffer;
commandPool.AllocateBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY, commandBuffer);

/*...*/

commandBuffer.Begin().Flags(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);

/*...*/

CmdPushDescriptorSet(VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout_composition, 0, {
    WriteDescriptorSet{}.
        DescriptorType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER).
        BufferInfo(
            DescriptorBufferInfo{}.Buffer(uniformBuffer)), // DescriptorBufferInfo 的默认初始化器会将 range 填写为 VK_WHOLE_SIZE
    WriteDescriptorSet{}.
        DstBinding(1).
        DescriptorType(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT).
        ImageInfo({
            DescriptorImageInfo{}.ImageView(attachment_normalZ).ImageLayout(VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ),
            DescriptorImageInfo{}.ImageView(attachment_albedoSpecular).ImageLayout(VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ) }) });
```

* 枚举项可以写为 `enums` 命名空间中的常量（不过我觉得比较难看）：

    ```cpp
    oop::CommandPool commandPool(FLAGS{ CommandPoolCreateResetCommandBufferBit });
    oop::CommandBuffer commandBuffer;
    commandPool.AllocateBuffers(CommandBufferLevelPrimary, commandBuffer);
    ```

[](二级标题)
## 关于本项目

### 为什么存在？

首先是为了让我先前在 [EasyVulkan教程代码](https://github.com/EasyVulkan/EasyVulkan.github.io) 中提供的封装，及自己私用的略有差别的Vulkan封装作古：

* 我先前在 EasyVulkan 中提供的封装可扩展性太差。
* 我先前在 EasyVulkan 中提供的封装包含过时而冗余的部分（那套封装整体基于 Vulkan 1.0 ，并尽量考虑让略旧的硬件也能跑）。
* 我先前的封装对于参数顺序的设置较为随意。

其次，虽然Khronos官方在 Vulkan SDK 中提供了 [Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp) ：

* 我认为 Vulkan-Hpp 的函数调用尚且不够方便。
* 我不喜欢 Vulkan-Hpp 的命名风格（然而，我也并不喜欢自己这个库的命名风格）。

### 适用情形

必须满足：

* 目标平台为64位，且编译器支持C++20标准

    简而言之，你是一个活在2026年的C++开发者就行了。

整个库**不适用**于：

* 需要多个Vulkan实例的程序

    应当不存在这种 “需要” 。一个程序中可以有多个Vulkan实例，但这应当是因为调用了其他开发者写好的其它基于Vulkan的程序模块，在你自己的代码中创建一个Vulkan实例就够。

* 会在线程中切换逻辑设备的程序

    允许在一个线程中重建逻辑设备，但不能来回切换不同逻辑设备，这是为了在满足 “[基于线程的状态机 (文档还没写)]()” 的同时确保安全性并简化程序设计。

整个库**不推荐**用于：

* 需要多个逻辑设备的程序

    这通常意味着你想使用多个物理设备。<br>
    由于这会将代码复杂化，且个人开发者不太会写这类程序，因此 [Core/VKAppBase.h (文档还没写)]() 中涉及逻辑设备的函数一概只支持单个逻辑设备的情形。<br>
    不过这个库并不抵触 “在不同线程中使用不同逻辑设备” 的情形，但你需要自行撰写相关代码（并不会很麻烦）。

* 需要多个交换链的程序

    这通常意味着程序会有子窗口。子窗口从属于程序，但不受主窗口边框限制的窗口。<br>
    Again，由于这会将代码复杂化，且：

    * 个人开发者，尤其是大部分 ImGui 用户，较倾向于在主窗口中创建面板，且非再单独创建子窗口。<br>
    * 如今一些软件也倾向于把主窗口切分成不同区域（典型的比如 Blender）而非创建子窗口。
    * 右键菜单也可以完全显示在主窗口内（VS Code 正是如此）。

    出现以上这些情况的一个可能的原因，或许是因为创建子窗口需要使用特定操作系统提供的API。<br>
    而你选择使用Vulkan这种跨平台图形API则更多是为了考虑可移植性，是吧？<br>
    （当然，不排除因为讨厌D3D12那套微软祖传的接口命名方式而学习Vulkan的情况）

    如果你需要多个交换链，你可以自行将 [Core/VKAppBase.h (文档还没写)]() 中与交换链相关的的变量和函数封装进一个类（可能会有点麻烦哦！），然后再创建该类实例的数组。

    顺带一提，如果是显示内容较为简单的子窗口（比如右键菜单），可以考虑直接用平台提供的API绘制位图。

### 版本号

目前对应的 Vulkan SDK 版本是 **1.4.328** ，这个库包装了至该版本为止 ***vulkan_core.h*** 中定义的所有可能会被人为使用的结构体和函数。<br>
你需要使用高于该版本的SDK以使用本项目代码。

本项目不使用版本号，仅在这个文档中标定 **[Core (文档还没写)]() 和 [Plus (文档还没写)]() 两个文件夹**中任意文件的最后更新日期（可看成是以日期为版本号）。

### 更新频率

目前本项目由我个人维护，增量更新的频率注定会很低。<br>
（我不介意你贡献代码！细则参见 [CONTRIBUTING (文档还没写)](https://github.com/EasyVulkan/VKEncapsulation/tree/main?tab=contributing-ov-file#) ）

[Core (文档还没写)]() 文件夹中代码的下一次增量更新可能会是 Vulkan SDK 更新到 **1.5.XXX** 的时候。<br>
因为在minor版本号变更前，不会有扩展功能被提升为核心功能，而我也不急着用 **1.4.328** 之后新出的扩展功能。<br>
毕竟赶时髦也没用啊，硬件普遍支持吗？

核心功能（core functionality）：指由没有诸如 `EXT` 、`KHR` 、`NV` 、`AMD` 等大写字母后缀或 `Win32` 等平台标签的函数/类型提供的功能。

[](二级标题)
## 文档一览

* [VKEncapsulation 快速入门 (文档进度1/5)](docs/VKEncapsulation_快速入门.md)

[](二级标题)
## 示例

一些简单示例，尽数使用 **Vulkan 1.3** 起纳入核心功能的动态渲染（dynamic rendering）而非渲染通道对象（render pass object）。

点击 .hpp 前的文件标题可以查看解说（目前还一概没写），点击 hpp 跳转到代码。

### FramesInFlight.[hpp](VKEncapsulation/Sample/FramesInFlight.hpp)

* 正确的即时帧做法
* 最简单的动态渲染
* 最基础的三角形

### BootScreen.[hpp](VKEncapsulation/Sample/BootScreen.hpp)

* 初始化后将图像拷贝到屏幕

    可用于实现平台无关的程序启动画面（但对于启动画面而言这个做法不够快）。

### DeferredToScreen.[hpp](VKEncapsulation/Sample/DeferredToScreen.hpp)

* 在动态渲染中使用输入附件
* 推送描述符（push descriptor）
* 简易延迟渲染