#include "kitmodel.h"
#include <projectexplorer/kitmodel.h>
#include <projectexplorer/kitmanager.h>
#include "remotecompileconstants.h"
#include <memory>

namespace RemoteCompile {
namespace Internal {

KitModel::KitModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_selectedKitIdx()
{
    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitAdded, [=](){
        modelLayoutChanged();
    });
    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitRemoved, [=](){
        modelLayoutChanged();
    });
    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitUpdated, [=](ProjectExplorer::Kit* kit){
        QModelIndex idx = indexFromKit(kit);
        this->dataChanged(idx, idx);
    });
}

void KitModel::addNewRemoteKit()
{
    ProjectExplorer::Kit* kit = new ProjectExplorer::Kit();
    kit->setValue(Constants::KIT_IS_REMOTE_ID, true);
    kit->setAutoDetected(true);
    kit->setAutoDetectionSource("remoteCompilerPlugin");
    kit->makeSticky();
    kit->setUnexpandedDisplayName(findUnusedName("RemoteCompilerKit"));
    ProjectExplorer::KitManager::instance()->registerKit(std::unique_ptr<ProjectExplorer::Kit>(kit));
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

QModelIndex KitModel::indexFromKit(ProjectExplorer::Kit *kit) const
{
    QModelIndex retval;
    int i = 0;
    for(ProjectExplorer::Kit* tmp_kit : ProjectExplorer::KitManager::instance()->kits()) {
        if(tmp_kit == kit) {
            retval = index(i, 0);
            break;
        }
        ++i;
    }
    return retval;
}

QString KitModel::findUnusedName(const QString &prefix)
{
    QString retval;
    for(int i = 0; /* infinite loop */ ; ++i) {
        if(i == 0) {
            retval = prefix;
        } else {
            retval = QString("%1_%2").arg(prefix).arg(i);
        }
        if(!kitByName(retval)) {
            break;
        }
    }
    return retval;
}

ProjectExplorer::Kit *KitModel::kitByName(const QString &name)
{
    ProjectExplorer::Kit* kit = nullptr;
    const int rowCnt = rowCount(QModelIndex());
    for(int i = 0; i < rowCnt; ++i) {
        QModelIndex idx = index(i, 0);
        if(idx.data().toString() == name) {
            kit = kitFromIndex(idx);
            break;
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
        case DataRole_DeviceId:
            retval = kit->value(Constants::KIT_DEVICE_ID, false);
            break;
        }
    }
    return retval;
}

bool KitModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool retval = false;
    ProjectExplorer::Kit* kit = kitFromIndex(index);
    if(kit) {
        switch (role) {
        case DataRole_DeviceId:
            kit->setValue(Constants::KIT_DEVICE_ID, value);
            retval = true;
            break;
        }
    }
    return retval;
}

void KitModel::modelLayoutChanged()
{
    int oldIdx = m_selectedKitIdx.row();
    this->beginResetModel();
    this->endResetModel();
    if(oldIdx < 0 && rowCount(QModelIndex()) > 0) {
        oldIdx = 0;
    }
    this->setSelectedKitIdx(index(oldIdx, 0));
}

}
}
