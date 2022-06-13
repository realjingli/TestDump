QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#自定义变量，exe名称
appname = "TestGitDump"


CONFIG(debug, debug|release | profile) {
    appdir = $$PWD/build/debug
    TARGET = $${appname}
} else {
    appdir = $$PWD//build/release
    TARGET = $${appname}
}

DESTDIR = $${appdir}/bin
UI_DIR = $${appdir}/$${appname}/ui
MOC_DIR = $${appdir}/$${appname}/moc
RCC_DIR = $${appdir}/$${appname}/rcc
OBJECTS_DIR = $${appdir}/$${appname}/obj

include(app_config.pri)







SOURCES += \
    Data.cpp \
    MyThread.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Data.h \
    MainWindow.h \
    MyThread.h \
    helper.hpp

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

