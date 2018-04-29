#include "remotesystemoptionsform.h"
#include "ui_remotesystemoptionsform.h"
#include <projectexplorer/devicesupport/devicemanagermodel.h>
#include <projectexplorer/devicesupport/devicemanager.h>


namespace RemoteCompile {
namespace  Options {
namespace Internal {


RemoteSystemOptionsForm::RemoteSystemOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoteSystemOptionsForm),
    m_deviceModel(new ProjectExplorer::DeviceManagerModel(ProjectExplorer::DeviceManager::instance(), this))
{
    ui->setupUi(this);
    ui->comboBox->setModel(m_deviceModel);
}

RemoteSystemOptionsForm::~RemoteSystemOptionsForm()
{
    delete ui;
}

}
}
}
