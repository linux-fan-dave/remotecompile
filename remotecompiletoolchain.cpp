#include "remotecompiletoolchain.h"
#include "remotecompileconstants.h"
#include <projectexplorer/abi.h>
#include <projectexplorer/task.h>
#include <projectexplorer/headerpath.h>
#include <projectexplorer/projectexplorerconstants.h>
#include <projectexplorer/gcctoolchain.h>

namespace RemoteCompile {
namespace Internal {

RemoteCompileToolchain::RemoteCompileToolchain()
    :ProjectExplorer::ToolChain(Constants::TOOLCHAIN_ID)
    ,m_innerToolChain(new ProjectExplorer::GccToolChain(Constants::INNERTOOLCHAIN_ID))
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

ProjectExplorer::WarningFlags RemoteCompileToolchain::warningFlags(const QStringList &cflags) const
{
    return m_innerToolChain->warningFlags(cflags);
}

ProjectExplorer::Macros RemoteCompileToolchain::predefinedMacros(const QStringList &cxxflags) const
{
    return m_innerToolChain->predefinedMacros(cxxflags);
}

void RemoteCompileToolchain::addToEnvironment(Utils::Environment &env) const
{
    Q_UNUSED(env);
}

Utils::FileName RemoteCompileToolchain::makeCommand(const Utils::Environment &env) const
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

QVector<ProjectExplorer::Task> RemoteCompileToolchain::validateKit(const ProjectExplorer::Kit *k) const
{
    return m_innerToolChain->validateKit(k);
}

Utils::LanguageExtensions RemoteCompileToolchain::languageExtensions(const QStringList &cxxflags) const
{
    return m_innerToolChain->languageExtensions(cxxflags);
}

ProjectExplorer::ToolChain::MacroInspectionRunner RemoteCompileToolchain::createMacroInspectionRunner() const
{
    return m_innerToolChain->createMacroInspectionRunner();
}

ProjectExplorer::ToolChain::BuiltInHeaderPathsRunner RemoteCompileToolchain::createBuiltInHeaderPathsRunner() const
{
    return m_innerToolChain->createBuiltInHeaderPathsRunner();
}

ProjectExplorer::HeaderPaths RemoteCompileToolchain::builtInHeaderPaths(const QStringList &cxxflags, const Utils::FileName &sysRoot) const
{
    return m_innerToolChain->builtInHeaderPaths(cxxflags, sysRoot);
}

std::unique_ptr<ProjectExplorer::ToolChainConfigWidget> RemoteCompileToolchain::createConfigurationWidget()
{
    return m_innerToolChain->createConfigurationWidget();
}

QVector<ProjectExplorer::Abi> RemoteCompileToolchain::supportedAbis() const
{
    return QVector<ProjectExplorer::Abi> ();
}

QStringList RemoteCompileToolchain::extraCodeModelFlags() const
{
    return QStringList();
}

}
}
