#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H

#include <QVulkanWindow>

#include <vulkan/vulkan.hpp>

#include <kompute/Manager.hpp>

class VulkanRenderer : public QVulkanWindowRenderer
{
public:
    VulkanRenderer(QVulkanWindow *w);

    void initResources() override;
    void initSwapChainResources() override;
    void releaseSwapChainResources() override;
    void releaseResources() override;

    void startNextFrame() override;

private:
    QVulkanWindow *mWindow;
    QVulkanDeviceFunctions *mDevFuncs;
    float mGreen = 0;
};

class VulkanWindow : public QVulkanWindow
{
public:
    VulkanWindow(const vk::Instance instance);

    QVulkanWindowRenderer *createRenderer() override;

private:
    std::shared_ptr<vk::Instance> mInstance;
    std::shared_ptr<vk::PhysicalDevice> mPhysicalDevice;
    std::shared_ptr<vk::Device> mDevice;
//    vk::Instance mInstance;
//    vk::PhysicalDevice mPhysicalDevice;
//    vk::Device mDevice;

    std::unique_ptr<kp::Manager> mManager;
};

#endif // VULKANWINDOW_H
