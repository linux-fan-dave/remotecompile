#include "remotecompilermanager.h"

namespace RemoteCompile {

RemoteCompilerManager *RemoteCompilerManager::instance()
{
    static RemoteCompilerManager manager;
    return &manager;
}

RemoteCompilerManager::RemoteCompilerManager()
    :m_remoteCompiler()
{

}

int RemoteCompilerManager::remoteCompilerCount() const
{
    return m_remoteCompiler.count();
}

void RemoteCompilerManager::addRemoteCompiler(RemoteCompiler *remoteCompiler)
{
    m_remoteCompiler.append(remoteCompiler);
}

RemoteCompiler *RemoteCompilerManager::remoteCompilerAt(int idx)
{
    return m_remoteCompiler.at(idx);
}

}
