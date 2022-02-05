QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    vulkanwindow.cpp

HEADERS += \
    mainwindow.h \
    vulkanwindow.h

FORMS += \
    mainwindow.ui

win32-msvc* {
    INCLUDEPATH += C:/VulkanSDK/1.2.198.1/include
    INCLUDEPATH += C:/Users/ryzen/Cascade/external/kompute/install/include

    LIBS += -LC:/Users/ryzen/Cascade/external/kompute/install/debug/lib -lkompute
    LIBS += -LC:/Users/ryzen/Cascade/external/kompute/install/debug/lib -lfmtd
    LIBS += -LC:/VulkanSDK/1.2.198.1/Lib -lvulkan-1

}
