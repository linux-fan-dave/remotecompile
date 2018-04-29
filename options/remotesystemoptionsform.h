#ifndef REMOTESYSTEMOPTIONSFORM_H
#define REMOTESYSTEMOPTIONSFORM_H

#include <QWidget>

namespace ProjectExplorer {
    class DeviceManagerModel;
}

namespace Ui {
class RemoteSystemOptionsForm;
}

namespace RemoteCompile {
namespace  Options {
namespace Internal {


class RemoteSystemOptionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit RemoteSystemOptionsForm(QWidget *parent = 0);
    ~RemoteSystemOptionsForm();

private:
    Ui::RemoteSystemOptionsForm *ui;
    ProjectExplorer::DeviceManagerModel* m_deviceModel;
};

}
}
}
#endif // REMOTESYSTEMOPTIONSFORM_H
