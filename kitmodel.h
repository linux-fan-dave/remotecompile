#ifndef KITMODEL_H
#define KITMODEL_H

#include <QAbstractListModel>

namespace ProjectExplorer {
   class Kit;
}


namespace RemoteCompile {
namespace Internal {

class KitModel : public QAbstractListModel
{
    Q_OBJECT    
public:
    enum DataRole {
        DataRole_IsRemoteRole = Qt::UserRole + 1
    };
    Q_ENUM(DataRole)

    explicit KitModel(QObject *parent = nullptr);

    void addNewRemoteKit();
signals:

public slots:

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    ProjectExplorer::Kit* kitFromIndex(const QModelIndex &index) const;
};

}
}

#endif // KITMODEL_H
