#include "remotesystemoptionsform.h"
#include "ui_remotesystemoptionsform.h"
#include <projectexplorer/devicesupport/devicemanagermodel.h>
#include <projectexplorer/devicesupport/devicemanager.h>
#include <kitmodel.h>


namespace RemoteCompile {
namespace  Options {
namespace Internal {


RemoteSystemOptionsForm::RemoteSystemOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoteSystemOptionsForm),
    m_deviceModel(new ProjectExplorer::DeviceManagerModel(ProjectExplorer::DeviceManager::instance(), this)),
    m_kitModel(new RemoteCompile::Internal::RemoteKitFilterModel)
{
    ui->setupUi(this);
    ui->cb_Kits->setModel(m_kitModel.get());
    ui->comboBox->setModel(m_deviceModel.get());

    ui->cb_Kits->setCurrentIndex(m_kitModel->kitModel().selectedKitIdx());

    connect(&(m_kitModel->kitModel()), &RemoteCompile::Internal::KitModel::selectedKitChanged, [=](){
       ui->cb_Kits->setCurrentIndex(m_kitModel->kitModel().selectedKitIdx());
    });

    connect(ui->cb_Kits, &QComboBox::currentTextChanged, [=](){
        m_kitModel->kitModel().setSelectedKit(ui->cb_Kits->currentIndex());
    });

    connect(ui->pb_Add, &QPushButton::clicked, [=]() {
        m_kitModel->kitModel().addNewRemoteKit();
    });
}

RemoteSystemOptionsForm::~RemoteSystemOptionsForm()
{
    delete ui;
}

}
}
}
