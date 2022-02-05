#include "mainwindow.h"

#include <QApplication>
#include <QLoggingCategory>
#include <QVulkanInstance>

#include "vulkanwindow.h"

Q_LOGGING_CATEGORY(lcVk, "qt.vulkan")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLoggingCategory::setFilterRules(QStringLiteral("qt.vulkan=true"));

    QVulkanInstance instance;

    instance.setLayers(QByteArrayList() << "VK_LAYER_KHRONOS_validation");

    if (!instance.create())
        qFatal("Failed to create Vulkan instance: %d", instance.errorCode());

    VulkanWindow w(instance.vkInstance());
    w.setVulkanInstance(&instance);
    w.resize(1024, 768);
    w.show();

    return a.exec();
}
