#include "remotecompilermanager.h"

namespace RemoteCompile {

RemoteCompilerManager *RemoteCompilerManager::instance()
{
    static RemoteCompilerManager manager;
    return &manager;
}

RemoteCompilerManager::RemoteCompilerManager()
{

}

}
