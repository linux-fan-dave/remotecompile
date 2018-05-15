#include "remotecompiler.h"

namespace RemoteCompile {

RemoteCompiler::RemoteCompiler(QObject *parent) : QObject(parent)
{

}

QString RemoteCompiler::name() const
{
    return m_name;
}

void RemoteCompiler::setName(const QString &name)
{
    if(m_name != name) {
        m_name = name;
        nameChanged();
    }
}

}
