#ifndef REMOTECOMPILERTOOLCHAINFACTORY_H
#define REMOTECOMPILERTOOLCHAINFACTORY_H

#include <projectexplorer/toolchain.h>

namespace RemoteCompile {
namespace Internal {

class RemoteCompilerToolChainFactory : public ProjectExplorer::ToolChainFactory
{
    Q_OBJECT
public:
    explicit RemoteCompilerToolChainFactory();

signals:

public slots:

    // ToolChainFactory interface
public:
    virtual QList<ProjectExplorer::ToolChain *> autoDetect(const QList<ProjectExplorer::ToolChain *> &alreadyKnown) override;
    virtual QSet<Core::Id> supportedLanguages() const override;
};

}
}
#endif // REMOTECOMPILERTOOLCHAINFACTORY_H
