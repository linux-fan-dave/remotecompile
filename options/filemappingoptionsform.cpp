#include "filemappingoptionsform.h"
#include "ui_filemappingoptionsform.h"
#include <QStandardItemModel>
#include <QComboBox>

namespace RemoteCompile {
namespace  Options {
namespace Internal {

void FileMappingOptionsForm::addMappingType(QStandardItemModel* model, QString title, MappingType mappingType)
{
    QStandardItem* item =  new QStandardItem(title);
    item->setData(mappingType, RoleType_MappingType);
    model->appendRow(item);
}

FileMappingOptionsForm::FileMappingOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileMappingOptionsForm)
{
    ui->setupUi(this);
    QStandardItemModel* model = new QStandardItemModel(this);
    ui->comboBox->setModel(model);
    addMappingType(model, tr("locally mounted"), MappingType_LocallyMounted);
    addMappingType(model, tr("file mapping via ssh"), MappingType_SSH);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(currentMappingTypeChanged()));
}

FileMappingOptionsForm::~FileMappingOptionsForm()
{
    delete ui;
}

void FileMappingOptionsForm::currentMappingTypeChanged()
{
    ui->stackedWidget->setCurrentIndex(ui->comboBox->currentIndex());
}

}
}
}
