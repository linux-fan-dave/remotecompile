DEFINES += REMOTECOMPILE_LIBRARY

QT += network

# RemoteCompile files

SOURCES += \
        remotecompileplugin.cpp \
    options/filemappingoptions.cpp \
    options/filemappingoptionsform.cpp \
    options/remotesystemoptions.cpp \
    options/remotesystemoptionsform.cpp \
    remotecompilermanager.cpp \
    remotecompilertoolchainfactory.cpp \
    remotecompiletoolchain.cpp \
    remotecompilermanagermodel.cpp \
    remotecompiler.cpp \
    kitmodel.cpp \
    remotekitfiltermodel.cpp \
    devicefiltermodel.cpp

HEADERS += \
        remotecompileplugin.h \
        remotecompile_global.h \
        remotecompileconstants.h \
    options/filemappingoptions.h \
    options/filemappingoptionsform.h \
    options/remotesystemoptions.h \
    options/remotesystemoptionsform.h \
    remotecompilermanager.h \
    remotecompilertoolchainfactory.h \
    remotecompiletoolchain.h \
    remotecompilermanagermodel.h \
    remotecompiler.h \
    kitmodel.h \
    remotekitfiltermodel.h \
    devicefiltermodel.h

OTHER_FILES += \
    RemoteCompile.json.in


INCLUDEPATH += $$PWD

# Qt Creator linking

## Either set the IDE_SOURCE_TREE when running qmake,
## or set the QTC_SOURCE environment variable, to override the default setting
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$(QTC_SOURCE)
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = "/home/david/projects/qt-creator"

## Either set the IDE_BUILD_TREE when running qmake,
## or set the QTC_BUILD environment variable, to override the default setting
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = "/home/david/projects/build-qtcreator-Desktop_Qt_5_13_0_GCC_64bit-Debug"

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on OS X
USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

QTC_PLUGIN_NAME = RemoteCompile
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

FORMS += \
    options/filemappingoptionsform.ui \
    options/remotesystemoptionsform.ui
