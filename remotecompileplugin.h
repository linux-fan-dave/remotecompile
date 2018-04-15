#pragma once

#include "remotecompile_global.h"

#include <extensionsystem/iplugin.h>

namespace RemoteCompile {
namespace Internal {

class RemoteCompilePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "RemoteCompile.json")

public:
    RemoteCompilePlugin();
    ~RemoteCompilePlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace RemoteCompile
