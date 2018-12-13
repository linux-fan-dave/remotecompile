#ifndef REMOTESYSTEMOPTIONSFORM_H
#define REMOTESYSTEMOPTIONSFORM_H

#include <QWidget>
#include <remotekitfiltermodel.h>
#include <devicefiltermodel.h>
#include <memory>

namespace Ui {
class RemoteSystemOptionsForm;
}

namespace RemoteCompile {
namespace  Options {
namespace Internal {

class RemoteSystemOptions;

class RemoteSystemOptionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit RemoteSystemOptionsForm(RemoteSystemOptions& remoteSystemOptions);
    ~RemoteSystemOptionsForm();

private:
    Ui::RemoteSystemOptionsForm *ui;
    std::shared_ptr<RemoteCompile::Internal::RemoteKitFilterModel> m_kitModel;
    RemoteSystemOptions& m_remoteSystemOptions;
    bool m_inDataBinding;
    void handleSelectedKitChanged();
};

}
}
}
#endif // REMOTESYSTEMOPTIONSFORM_H
