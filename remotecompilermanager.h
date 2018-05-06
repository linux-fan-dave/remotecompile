#ifndef REMOTECOMPILERMANAGER_H
#define REMOTECOMPILERMANAGER_H

#include <QObject>

namespace RemoteCompile {

class RemoteCompilerManager : public QObject
{
    Q_OBJECT
public:
    static RemoteCompilerManager* instance();
private:
    RemoteCompilerManager();
};

}

#endif // REMOTECOMPILERMANAGER_H
