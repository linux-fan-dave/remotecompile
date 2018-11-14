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
        DataRole_IsRemoteRole = Qt::UserRole + 1,
        DataRole_Kit
    };
    Q_ENUM(DataRole)

    explicit KitModel(QObject *parent = nullptr);

    void addNewRemoteKit();
    void deleteSelectedKit();

    QModelIndex selectedKitIdx() const { return m_selectedKitIdx; }
    void setSelectedKitIdx(const QModelIndex& idx);
    ProjectExplorer::Kit *selectedKit() const;

signals:
    void selectedKitIdxChanged();

public slots:

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    ProjectExplorer::Kit* kitFromIndex(const QModelIndex &index) const;
    QString findUnusedName(const QString& prefix);
    ProjectExplorer::Kit* kitByName(const QString& name);
    QModelIndex m_selectedKitIdx;
};

}
}

#endif // KITMODEL_H
