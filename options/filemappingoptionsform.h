#ifndef FILEMAPPINGOPTIONSFORM_H
#define FILEMAPPINGOPTIONSFORM_H

#include <QWidget>

class QStandardItemModel;

namespace Ui {
class FileMappingOptionsForm;
}

namespace RemoteCompile {
namespace  Options {
namespace Internal {

class FileMappingOptionsForm : public QWidget
{
    Q_OBJECT

public:
    enum MappingType {
        MappingType_LocallyMounted,
        MappingType_SSH
    };
    enum RoleType {
        RoleType_MappingType = Qt::UserRole + 1
    };

    explicit FileMappingOptionsForm(QWidget *parent = 0);
    ~FileMappingOptionsForm();
private Q_SLOTS:
    void currentMappingTypeChanged();

private:
    Ui::FileMappingOptionsForm *ui;
    void addMappingType(QStandardItemModel* model, QString title, MappingType mappingType);

};

}
}
}

#endif // FILEMAPPINGOPTIONSFORM_H
