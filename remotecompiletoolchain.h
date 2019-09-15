#ifndef REMOTECOMPILETOOLCHAIN_H
#define REMOTECOMPILETOOLCHAIN_H

#include <projectexplorer/toolchain.h>
#include <projectexplorer/toolchainconfigwidget.h>

namespace RemoteCompile {
namespace Internal {

class RemoteCompileToolchain : public ProjectExplorer::ToolChain
{
public:
    RemoteCompileToolchain(Detection detection);

    // ToolChain interface
public:
    virtual QString typeDisplayName() const override;
    virtual ProjectExplorer::Abi targetAbi() const override;
    virtual bool isValid() const override;
    virtual ProjectExplorer::WarningFlags warningFlags(const QStringList &cflags) const override;
    virtual ProjectExplorer::Macros predefinedMacros(const QStringList &cxxflags) const override;
    virtual void addToEnvironment(Utils::Environment &env) const override;
    virtual QString makeCommand(const Utils::Environment &env) const override;
    virtual Utils::FileName compilerCommand() const override;
    virtual ProjectExplorer::IOutputParser *outputParser() const override;
    virtual ProjectExplorer::ToolChain *clone() const override;
    virtual QList<ProjectExplorer::Task> validateKit(const ProjectExplorer::Kit *k) const override;
    virtual Utils::LanguageExtensions languageExtensions(const QStringList &cxxflags) const override;
    virtual MacroInspectionRunner createMacroInspectionRunner() const override;
    virtual BuiltInHeaderPathsRunner createBuiltInHeaderPathsRunner() const override;
    virtual ProjectExplorer::HeaderPaths builtInHeaderPaths(const QStringList &cxxflags,
                                          const Utils::FileName &sysRoot) const override;
    virtual std::unique_ptr<ProjectExplorer::ToolChainConfigWidget> createConfigurationWidget() override;

private:
    ToolChain* m_innerToolChain;

    // ToolChain interface
public:
    virtual QList<ProjectExplorer::Abi> supportedAbis() const override;
    virtual QStringList extraCodeModelFlags() const override;
};

}
}
#endif // REMOTECOMPILETOOLCHAIN_H
