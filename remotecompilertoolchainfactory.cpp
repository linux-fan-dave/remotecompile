#include "remotecompilertoolchainfactory.h"
#include <projectexplorer/projectexplorerconstants.h>
#include <remotecompiletoolchain.h>

namespace RemoteCompile {
namespace Internal {

RemoteCompilerToolChainFactory::RemoteCompilerToolChainFactory()
    :ProjectExplorer::ToolChainFactory()
{
    setDisplayName("my factory");
}

QList<ProjectExplorer::ToolChain *> RemoteCompilerToolChainFactory::autoDetect(const QList<ProjectExplorer::ToolChain *> &alreadyKnown)
{
    RemoteCompileToolchain* toolchain = new RemoteCompileToolchain(ProjectExplorer::ToolChain::AutoDetectionFromSettings);
    QList<ProjectExplorer::ToolChain *>   toolchains ;
    toolchains <<  alreadyKnown << toolchain;
    return toolchains;
}

QSet<Core::Id> RemoteCompilerToolChainFactory::supportedLanguages() const
{
    return {ProjectExplorer::Constants::CXX_LANGUAGE_ID,
                ProjectExplorer::Constants::C_LANGUAGE_ID};
}

}
}
