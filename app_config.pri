


#Release也能生成 pdb文件
#QMAKE_LFLAGS_RELEASE = /INCREMENTAL:NO /DEBUG
QMAKE_CXXFLAGS_RELEASE += -Zi
QMAKE_LFLAGS_RELEASE +=  /DEBUG

#使所有文件以utf-8格式打开，HImage.h会报警,需要手动另存为utf-8格式
QMAKE_CXXFLAGS += /utf-8


#exe文件图标
#RC_ICONS = res/app.ico

#exe文件版本
VERSION = 1.2.0.0

#禁止在exe文件名后面加上版本后缀
CONFIG += skip_target_version_ext

#exe文件生产商
QMAKE_TARGET_COMPANY = $${appname}

#exe文件应用程序
QMAKE_TARGET_DESCRIPTION = "Test Git Dump"

#exe文件声明版权
QMAKE_TARGET_COPYRIGHT = "2001-2022 Sunlight Copyright"

#exe文件产品名称
QMAKE_TARGET_PRODUCT = $${appname}

#中文（简体）
RC_LANG = 0x0004
