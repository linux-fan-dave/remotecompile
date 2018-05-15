#ifndef REMOTECOMPILERMANAGERMODEL_H
#define REMOTECOMPILERMANAGERMODEL_H

#include <QAbstractListModel>
#include "remotecompilermanager.h"

namespace RemoteCompile {

class RemoteCompilerManagerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    RemoteCompilerManagerModel(QObject* parent = nullptr, RemoteCompilerManager* manager = RemoteCompilerManager::instance());

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
private:
    RemoteCompilerManager* m_manager;
};

}

#endif // REMOTECOMPILERMANAGERMODEL_H
