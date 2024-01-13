TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += /lib/*.so
LIBS += /usr/local/lib/*.so
LIBS += -lpthread


INCLUDEPATH += "../../include/"

LIBS += -lMVSDK
INCLUDEPATH +=/usr/local/include/
INCLUDEPATH +=/usr/local/include/opencv4/
INCLUDEPATH +=/usr/local/include/opencv4/opencv2/




SOURCES += \
        camera_mindvision_running.cpp \
        main.cpp



HEADERS += \
    CameraApi.h \
    CameraDefine.h \
    CameraStatus.h \
    camera_mindvision_running.h
