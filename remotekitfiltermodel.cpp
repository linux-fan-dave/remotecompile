#include "remotekitfiltermodel.h"
#include "kitmodel.h"

namespace RemoteCompile {
namespace Internal {


RemoteKitFilterModel::RemoteKitFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent)
    , m_kitModel(new KitModel(this))
{
    setSourceModel(m_kitModel.get());
    connect(m_kitModel.get(), &KitModel::selectedKitIdxChanged, this, &RemoteKitFilterModel::selectedKitChanged);
}

bool RemoteKitFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    return m_kitModel->index(source_row, 0, source_parent).data(KitModel::DataRole_IsRemoteRole).toBool();
}

KitModel &RemoteKitFilterModel::kitModel() const
{
    return *m_kitModel;
}

QModelIndex RemoteKitFilterModel::selectedKitIdx() const
{
    return mapFromSource(m_kitModel->selectedKitIdx());
}

void RemoteKitFilterModel::setSelectedKitIdx(const QModelIndex &idx)
{
    m_kitModel->setSelectedKitIdx(mapToSource(idx));
}

}
}
