#include "remotecompiletoolchain.h"
#include "remotecompileconstants.h"
#include <projectexplorer/abi.h>
#include <projectexplorer/task.h>
#include <projectexplorer/headerpath.h>
#include <projectexplorer/projectexplorerconstants.h>
#include <projectexplorer/gcctoolchain.h>

namespace RemoteCompile {
namespace Internal {

RemoteCompileToolchain::RemoteCompileToolchain(ProjectExplorer::ToolChain::Detection detection)
    :ProjectExplorer::ToolChain(Constants::TOOLCHAIN_ID, detection)
    ,m_innerToolChain(new ProjectExplorer::GccToolChain(Constants::INNERTOOLCHAIN_ID, detection))
{
    setLanguage(ProjectExplorer::Constants::CXX_LANGUAGE_ID);
    setDisplayName("jdsf");
}

QString RemoteCompileToolchain::typeDisplayName() const
{
    return "remote compile toolchain";
}

ProjectExplorer::Abi RemoteCompileToolchain::targetAbi() const
{
    return m_innerToolChain->targetAbi();
}

bool RemoteCompileToolchain::isValid() const
{
    return true;
}

ProjectExplorer::ToolChain::CompilerFlags RemoteCompileToolchain::compilerFlags(const QStringList &cxxflags) const
{
    return m_innerToolChain->compilerFlags(cxxflags);
}

ProjectExplorer::WarningFlags RemoteCompileToolchain::warningFlags(const QStringList &cflags) const
{
    return m_innerToolChain->warningFlags(cflags);
}

ProjectExplorer::ToolChain::PredefinedMacrosRunner RemoteCompileToolchain::createPredefinedMacrosRunner() const
{
    return m_innerToolChain->createPredefinedMacrosRunner();
}

ProjectExplorer::Macros RemoteCompileToolchain::predefinedMacros(const QStringList &cxxflags) const
{
    return m_innerToolChain->predefinedMacros(cxxflags);
}

ProjectExplorer::ToolChain::SystemHeaderPathsRunner RemoteCompileToolchain::createSystemHeaderPathsRunner() const
{
   return m_innerToolChain->createSystemHeaderPathsRunner();
}

QList<ProjectExplorer::HeaderPath> RemoteCompileToolchain::systemHeaderPaths(const QStringList &cxxflags, const Utils::FileName &sysRoot) const
{
    return m_innerToolChain->systemHeaderPaths(cxxflags, sysRoot);
}

void RemoteCompileToolchain::addToEnvironment(Utils::Environment &env) const
{
    Q_UNUSED(env);
}

QString RemoteCompileToolchain::makeCommand(const Utils::Environment &env) const
{
    return m_innerToolChain->makeCommand(env);
}

Utils::FileName RemoteCompileToolchain::compilerCommand() const
{
    return m_innerToolChain->compilerCommand();
}

ProjectExplorer::IOutputParser *RemoteCompileToolchain::outputParser() const
{
    return m_innerToolChain->outputParser();
}

ProjectExplorer::ToolChainConfigWidget *RemoteCompileToolchain::configurationWidget()
{
    return m_innerToolChain->configurationWidget();
}

ProjectExplorer::ToolChain *RemoteCompileToolchain::clone() const
{
    return nullptr;
}

QList<ProjectExplorer::Task> RemoteCompileToolchain::validateKit(const ProjectExplorer::Kit *k) const
{
    return m_innerToolChain->validateKit(k);
}

QList<ProjectExplorer::Abi> RemoteCompileToolchain::supportedAbis() const
{
    return QList<ProjectExplorer::Abi> ();
}

QStringList RemoteCompileToolchain::extraCodeModelFlags() const
{
    return QStringList();
}

}
}
