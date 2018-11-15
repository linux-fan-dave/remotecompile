#include "devicefiltermodel.h"
#include <projectexplorer/devicesupport/devicemanager.h>
#include <projectexplorer/devicesupport/devicemanagermodel.h>

namespace RemoteCompile {
namespace Internal {

DeviceFilterModel::DeviceFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent)
    , m_deviceModel(new ProjectExplorer::DeviceManagerModel(ProjectExplorer::DeviceManager::instance(), this))
{
    setSourceModel(m_deviceModel.get());
}

bool DeviceFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent);
    static Core::Id desktopType("Desktop");
    ProjectExplorer::IDevice::ConstPtr dev = m_deviceModel->device(source_row);
    return dev->type() != desktopType;
}

}
}
