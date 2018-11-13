#include "kitmodel.h"
#include <projectexplorer/kitmodel.h>
#include <projectexplorer/kitmanager.h>
#include "remotecompileconstants.h"

namespace RemoteCompile {
namespace Internal {

KitModel::KitModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(ProjectExplorer::KitManager::instance(), &ProjectExplorer::KitManager::kitsChanged, [=](){
       this->beginResetModel();
       this->endResetModel();
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

QVariant KitModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index)

    QVariant retval;
    ProjectExplorer::Kit* kit = kitFromIndex(index);
    if(kit) {
        switch (role) {
        case Qt::DisplayRole:
        {
            retval = kit->displayName();
            break;
        }
        case DataRole_IsRemoteRole:
            retval = kit->value(Constants::KIT_IS_REMOTE_ID, false);
            break;
        }
    }
    return retval;
}

}
}
