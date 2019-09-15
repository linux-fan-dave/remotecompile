#include "remotecompilertoolchainfactory.h"
#include <projectexplorer/projectexplorerconstants.h>
#include <projectexplorer/devicesupport/devicemanager.h>
#include <remotecompiletoolchain.h>
#include <projectexplorer/abi.h>

namespace RemoteCompile {
namespace Internal {

RemoteCompilerToolChainFactory::RemoteCompilerToolChainFactory()
    :ProjectExplorer::ToolChainFactory()
{
    setDisplayName("remote compiler factory");
    setSupportedLanguages({ProjectExplorer::Constants::CXX_LANGUAGE_ID,
                           ProjectExplorer::Constants::C_LANGUAGE_ID});
}

QList<ProjectExplorer::ToolChain *> RemoteCompilerToolChainFactory::autoDetect(const QList<ProjectExplorer::ToolChain *> &alreadyKnown)
{
    using namespace ProjectExplorer;
     QList<ToolChain *> tcs;

    auto devManager = DeviceManager::instance();
    for(int i = 0; i < devManager->deviceCount(); ++i) {
        auto dev = devManager->deviceAt(i);
        tcs << autoDetectRemoteGcc(alreadyKnown, dev);
    }

    RemoteCompileToolchain* toolchain = new RemoteCompileToolchain();
    Q_UNUSED(toolchain);
    return tcs;
}

QList<ProjectExplorer::ToolChain *> RemoteCompilerToolChainFactory::autoDetectRemoteGcc(const QList<ProjectExplorer::ToolChain *> &/*alreadyKnown*/, ProjectExplorer::IDevice::ConstPtr /*device*/)
{
    using namespace ProjectExplorer;
    QList<ToolChain *> tcs;
    tcs.append(new RemoteCompileToolchain());

//    QList<ToolChain *> known = alreadyKnown;

//    if (HostOsInfo::isLinuxHost()) {
//        const QRegularExpression regexp(binaryRegexp);
//        for (const QString &dir : QStringList({ "/usr/bin", "/usr/local/bin" })) {
//            QDir binDir(dir);
//            auto gccProbe = [&](const QString &name, Core::Id language) {
//                for (const QString &entry : binDir.entryList(
//                     {"*-" + name, name + "-*", "*-" + name + "-*"},
//                         QDir::Files | QDir::Executable)) {
//                    const QString fileName = FileName::fromString(entry).fileName();
//                    if (fileName == "c89-gcc" || fileName == "c99-gcc")
//                        continue;
//                    const QRegularExpressionMatch match = regexp.match(fileName);
//                    if (!match.hasMatch())
//                        continue;
//                    const bool isNative = fileName.startsWith(name);
//                    const Abi abi = isNative ? Abi::hostAbi() : Abi();
//                    tcs.append(autoDetectToolchains(entry, abi, language,
//                                                    Constants::GCC_TOOLCHAIN_TYPEID, known));
//                    known.append(tcs);
//                }
//            };
//            gccProbe("g++", Constants::CXX_LANGUAGE_ID);
//            gccProbe("gcc", Constants::C_LANGUAGE_ID);
//        }
//    }

    return tcs;
}

}
}
