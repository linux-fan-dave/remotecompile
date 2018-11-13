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

    ProjectExplorer::Kit *selectedKit() const;
    int selectedKitIdx() const { return m_selectedKitIndex; }
    void setSelectedKit(const QModelIndex& idx);
    void setSelectedKit(int idx);
signals:
    void selectedKitChanged();

public slots:

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    ProjectExplorer::Kit* kitFromIndex(const QModelIndex &index) const;
    int m_selectedKitIndex;
};

}
}

#endif // KITMODEL_H
