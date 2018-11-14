#ifndef REMOTESYSTEMOPTIONSFORM_H
#define REMOTESYSTEMOPTIONSFORM_H

#include <QWidget>
#include <remotekitfiltermodel.h>
#include <memory>

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
    explicit RemoteSystemOptionsForm(QWidget *parent = nullptr);
    ~RemoteSystemOptionsForm();

private:
    Ui::RemoteSystemOptionsForm *ui;
    std::shared_ptr<ProjectExplorer::DeviceManagerModel> m_deviceModel;
    std::shared_ptr<RemoteCompile::Internal::RemoteKitFilterModel> m_kitModel;
    bool m_inDataBinding;
    void handleSelectedKitChanged();
};

}
}
}
#endif // REMOTESYSTEMOPTIONSFORM_H
