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
    , m_changedKits()
{
//    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitAdded, [=](){
//        modelLayoutChanged();
//    });
//    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitRemoved, [=](){
//        modelLayoutChanged();
//    });
//    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitUpdated, [=](ProjectExplorer::Kit* kit){
//        QModelIndex idx = indexFromKit(kit);
//        this->dataChanged(idx, idx);
//    });
    QList<ProjectExplorer::Kit*> kitList =  ProjectExplorer::KitManager::instance()->kits();
    for(ProjectExplorer::Kit* kit : kitList) {
        m_changedKits.push_back(KitPtr(kit->clone(true)));
    }

}

void KitModel::addNewRemoteKit()
{
    KitPtr kit = KitPtr(new ProjectExplorer::Kit());
    kit->setValue(Constants::KIT_IS_REMOTE_ID, true);
    kit->setAutoDetected(true);
    kit->setAutoDetectionSource("remoteCompilerPlugin");
    kit->makeSticky();
    kit->setUnexpandedDisplayName(findUnusedName("RemoteCompilerKit"));
    int rows = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), rows, rows);
    m_changedKits.append(kit);
    endInsertRows();
    setSelectedKitIdx(index(rows, 0));
}

void KitModel::deleteSelectedKit()
{
    setData(selectedKitIdx(), true, DataRole_Deleted);
}

int KitModel::rowCount(const QModelIndex &parent) const
{
    int retval = 0;
    if(!parent.isValid()) {
        retval = m_changedKits.size() + m_newKits.size();
    }
    return retval;
}

KitModel::KitPtr KitModel::kitFromIndex(const QModelIndex &index) const
{
    KitPtr kit;
    if(!index.parent().isValid() && index.isValid()) {
        if(index.row() <= m_changedKits.size()) {
            kit = m_changedKits[index.row()];
        } else if(index.row() - m_changedKits.size() < m_newKits.size()) {
            kit = m_newKits[index.row() - m_changedKits.size()];
        }
    }
    return kit;
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
        if(!kitByName(retval).isValid()) {
            break;
        }
    }
    return retval;
}

QModelIndex KitModel::kitByName(const QString &name)
{
    QModelIndex retval;
    const int rowCnt = rowCount(QModelIndex());
    for(int i = 0; i < rowCnt; ++i) {
        QModelIndex idx = index(i, 0);
        if(idx.data().toString() == name) {
            retval = idx;
            break;
        }
    }
    return retval;
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
    KitPtr kit = kitFromIndex(index);
    if(kit) {
        switch (role) {
        case Qt::DisplayRole:
            retval = kit->displayName();
            break;
        case DataRole_Kit:
            retval = QVariant::fromValue(kit.get());
            break;
        case DataRole_IsRemoteRole:
            retval = kit->value(Constants::KIT_IS_REMOTE_ID, false);
            break;
        case DataRole_DeviceId:
            retval = kit->value(Constants::KIT_DEVICE_ID, false);
            break;
        case DataRole_Deleted:
            retval = kit->value(Constants::KIT_DELETED, false);
            break;
        }
    }
    return retval;
}

bool KitModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool retval = false;
    KitPtr kit = kitFromIndex(index);
    if(kit) {
        switch (role) {
        case DataRole_DeviceId:
            kit->setValue(Constants::KIT_DEVICE_ID, value);
            retval = true;
            break;
        case DataRole_Deleted:
            kit->setValue(Constants::KIT_DELETED, value);
            retval = true;
            break;
        }
    }
    if(retval) {
        dataChanged(index, index);
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
