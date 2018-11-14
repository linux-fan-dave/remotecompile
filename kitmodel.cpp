#include "kitmodel.h"
#include <projectexplorer/kitmodel.h>
#include <projectexplorer/kitmanager.h>
#include "remotecompileconstants.h"

namespace RemoteCompile {
namespace Internal {

KitModel::KitModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_selectedKitIdx()
{
    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitsChanged, [=](){
       int oldIdx = m_selectedKitIdx.row();
       this->beginResetModel();
       this->endResetModel();
       this->setSelectedKitIdx(index(oldIdx, 0));
    });
}

void KitModel::addNewRemoteKit()
{
    ProjectExplorer::Kit* kit = new ProjectExplorer::Kit();
    kit->setValue(Constants::KIT_IS_REMOTE_ID, true);
    kit->setAutoDetected(true);
    kit->setAutoDetectionSource("remoteCompilerPlugin");
    kit->makeSticky();
    kit->setUnexpandedDisplayName("RemoteCompilerKit");
    ProjectExplorer::KitManager::instance()->registerKit(kit);
}

void KitModel::deleteSelectedKit()
{
    ProjectExplorer::Kit* kit = selectedKit();
    if(kit) {
        ProjectExplorer::KitManager::instance()->deregisterKit(kit);
    }
}

int KitModel::rowCount(const QModelIndex &parent) const
{
    int retval = 0;
    if(!parent.isValid()) {
        retval = ProjectExplorer::KitManager::instance()->kits().size();
    }
    return retval;
}

ProjectExplorer::Kit *KitModel::kitFromIndex(const QModelIndex &index) const
{
    ProjectExplorer::Kit* kit = nullptr;
    if(!index.parent().isValid() && index.isValid()) {
        QList<ProjectExplorer::Kit*> kitList =  ProjectExplorer::KitManager::instance()->kits();
        if(index.row() <= kitList.size()) {
            kit = kitList[index.row()];
        }
    }
    return kit;
}

void KitModel::setSelectedKitIdx(const QModelIndex &idx)
{
    if(m_selectedKitIdx != idx) {
        m_selectedKitIdx = idx;
        selectedKitIdxChanged();
    }
}

ProjectExplorer::Kit *KitModel::selectedKit() const
{
    QVariant kit = selectedKitIdx().data(DataRole_Kit);
    return kit.value<ProjectExplorer::Kit*>();
}


QVariant KitModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index)

    QVariant retval;
    ProjectExplorer::Kit* kit = kitFromIndex(index);
    if(kit) {
        switch (role) {
        case Qt::DisplayRole:
            retval = kit->displayName();
            break;
        case DataRole_Kit:
            retval = QVariant::fromValue(kit);
            break;
        case DataRole_IsRemoteRole:
            retval = kit->value(Constants::KIT_IS_REMOTE_ID, false);
            break;
        }
    }
    return retval;
}

}
}
