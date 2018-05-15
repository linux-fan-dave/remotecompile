#include "remotecompilermanagermodel.h"

namespace RemoteCompile {

RemoteCompilerManagerModel::RemoteCompilerManagerModel(QObject *parent, RemoteCompilerManager* manager)
    :QAbstractListModel (parent)
    ,m_manager(manager)
{

}

int RemoteCompilerManagerModel::rowCount(const QModelIndex &parent) const
{
    int retval = -1;
    if(!parent.isValid()) {
        retval = m_manager->remoteCompilerCount();
    }
    return retval;
}

QVariant RemoteCompilerManagerModel::data(const QModelIndex &index, int role) const
{
    QVariant retval;
    RemoteCompiler* rc = m_manager->remoteCompilerAt(index.row());
    switch (role) {
    case Qt::DisplayRole:
        retval = rc->name();
        break;
    }
    return  retval;
}

}
