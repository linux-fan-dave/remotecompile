#include "remotesystemoptionsform.h"
#include "ui_remotesystemoptionsform.h"
#include <projectexplorer/devicesupport/devicemanagermodel.h>
#include <projectexplorer/devicesupport/devicemanager.h>
#include <kitmodel.h>


namespace RemoteCompile {
namespace  Options {
namespace Internal {


void RemoteSystemOptionsForm::handleSelectedKitChanged()
{
    ui->cb_Kits->setCurrentIndex(m_kitModel->selectedKitIdx().row());
    bool hasKit = m_kitModel->selectedKitIdx().isValid();
    ui->pb_Delete->setEnabled(hasKit);
    ui->wg_ClientArea->setEnabled(hasKit);
}

RemoteSystemOptionsForm::RemoteSystemOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoteSystemOptionsForm),
    m_deviceModel(new ProjectExplorer::DeviceManagerModel(ProjectExplorer::DeviceManager::instance(), this)),
    m_kitModel(new RemoteCompile::Internal::RemoteKitFilterModel)
{
    ui->setupUi(this);
    ui->cb_Kits->setModel(m_kitModel.get());
    //ui->comboBox->setModel(m_deviceModel.get());

    handleSelectedKitChanged();

    connect(&(m_kitModel->kitModel()), &RemoteCompile::Internal::KitModel::selectedKitIdxChanged, [=](){
           handleSelectedKitChanged();
    });

    connect(ui->cb_Kits, &QComboBox::currentTextChanged, [=](){
        m_kitModel->setSelectedKitIdx(m_kitModel->index(ui->cb_Kits->currentIndex(), 0));
    });

    connect(ui->pb_Add, &QPushButton::clicked, [=]() {
        m_kitModel->kitModel().addNewRemoteKit();
    });

    connect(ui->pb_Delete, &QPushButton::clicked, [=](){
       m_kitModel->kitModel().deleteSelectedKit();
    });
}

RemoteSystemOptionsForm::~RemoteSystemOptionsForm()
{
    delete ui;
}

}
}
}
