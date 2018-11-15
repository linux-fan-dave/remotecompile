#include "remotesystemoptionsform.h"
#include "ui_remotesystemoptionsform.h"
#include <projectexplorer/devicesupport/devicemanagermodel.h>
#include <projectexplorer/devicesupport/devicemanager.h>
#include <projectexplorer/kit.h>
#include <kitmodel.h>


namespace RemoteCompile {
namespace  Options {
namespace Internal {


void RemoteSystemOptionsForm::handleSelectedKitChanged()
{
    m_inDataBinding = true;
    ui->cb_Kits->setCurrentIndex(m_kitModel->selectedKitIdx().row());
    bool hasKit = m_kitModel->selectedKitIdx().isValid();
    ui->pb_Delete->setEnabled(hasKit);
    ui->wg_ClientArea->setEnabled(hasKit);
    if(hasKit) {
        ProjectExplorer::Kit* kit = m_kitModel->kitModel().selectedKit();
        if(ui->le_Name->text() != kit->displayName()) {
            ui->le_Name->setText(kit->displayName());
        }
        ui->cb_Device->setModel(m_deviceModel.get());
    } else {
        ui->le_Name->setText("");
        ui->cb_Device->setModel(nullptr);
    }
    m_inDataBinding = false;
}

RemoteSystemOptionsForm::RemoteSystemOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoteSystemOptionsForm),
    m_deviceModel(new RemoteCompile::Internal::DeviceFilterModel),
    m_kitModel(new RemoteCompile::Internal::RemoteKitFilterModel),
    m_inDataBinding(false)
{
    ui->setupUi(this);
    ui->cb_Kits->setModel(m_kitModel.get());

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

    connect(ui->le_Name, &QLineEdit::textChanged, [=]{
        if(!m_inDataBinding) {
            ProjectExplorer::Kit* kit = m_kitModel->kitModel().selectedKit();
            if(kit) {
                kit->setUnexpandedDisplayName(ui->le_Name->text());
            }
        }
    });
    connect(ui->pb_manageDevices, &QPushButton::clicked, [=]() {

    });
}

RemoteSystemOptionsForm::~RemoteSystemOptionsForm()
{
    delete ui;
}

}
}
}
