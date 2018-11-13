#ifndef REMOTEKITFILTERMODEL_H
#define REMOTEKITFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <memory>

namespace RemoteCompile {
namespace Internal {

class KitModel;

class RemoteKitFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit RemoteKitFilterModel(QObject *parent = nullptr);

    KitModel& kitModel() const;

signals:

public slots:

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
private:
    std::shared_ptr<KitModel> m_kitModel;
};

}
}
#endif // REMOTEKITFILTERMODEL_H
