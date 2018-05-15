#ifndef REMOTECOMPILERMANAGER_H
#define REMOTECOMPILERMANAGER_H

#include <QObject>
#include <QList>
#include "remotecompiler.h"

namespace RemoteCompile {

class RemoteCompilerManager : public QObject
{
    Q_OBJECT
public:
    static RemoteCompilerManager* instance();
private:
    RemoteCompilerManager();
public:
    int remoteCompilerCount() const;
    void addRemoteCompiler(RemoteCompiler* remoteCompiler);
    RemoteCompiler* remoteCompilerAt(int idx);
private:
    typedef QList<RemoteCompiler*> RemoteCompilerList;
    RemoteCompilerList m_remoteCompiler;

};

}

#endif // REMOTECOMPILERMANAGER_H
