#ifndef DEVICEFILTERMODEL_H
#define DEVICEFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <memory>

namespace ProjectExplorer {
    class DeviceManagerModel;
}

namespace RemoteCompile {
namespace Internal {

class DeviceFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit DeviceFilterModel(QObject *parent = nullptr);

signals:

public slots:
private:
    std::shared_ptr<ProjectExplorer::DeviceManagerModel> m_deviceModel;

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
};

}
}
#endif // DEVICEFILTERMODEL_H
