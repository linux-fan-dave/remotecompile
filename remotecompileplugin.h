#pragma once

#include "remotecompile_global.h"

#include <extensionsystem/iplugin.h>
#include <memory>

namespace RemoteCompile {
namespace Internal {
class RemoteCompilePluginPrivate;

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
    std::shared_ptr<RemoteCompilePluginPrivate> d;
};

} // namespace Internal
} // namespace RemoteCompile
