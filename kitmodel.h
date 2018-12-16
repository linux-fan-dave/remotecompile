#ifndef KITMODEL_H
#define KITMODEL_H

#include <QAbstractListModel>
#include <memory>

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
        DataRole_Kit,
        DataRole_DeviceId,
        DataRole_Deleted
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
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    typedef std::shared_ptr<ProjectExplorer::Kit> KitPtr;
    typedef QList<KitPtr> KitList;

    KitPtr kitFromIndex(const QModelIndex &index) const;
    QString findUnusedName(const QString& prefix);
    QModelIndex kitByName(const QString& name);
    void modelLayoutChanged();

    QModelIndex m_selectedKitIdx;
    KitList m_changedKits;
    KitList m_newKits;
};

}
}

#endif // KITMODEL_H
