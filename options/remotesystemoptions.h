#ifndef REMOTESYSTEMOPTIONS_H
#define REMOTESYSTEMOPTIONS_H

#include <coreplugin/dialogs/ioptionspage.h>
#include <QObject>
#include <memory>

namespace RemoteCompile {
namespace Internal {
class DeviceFilterModel;
}
namespace  Options {
namespace Internal {

class RemoteSystemOptions : public Core::IOptionsPage
{
    Q_OBJECT
public:
    RemoteSystemOptions(QObject *parent = nullptr);

    // IOptionsPage interface
public:
    virtual QWidget *widget() override;
    virtual void apply() override;
    virtual void finish() override;

    std::shared_ptr<RemoteCompile::Internal::DeviceFilterModel> deviceModel() const;

private:
    std::shared_ptr<RemoteCompile::Internal::DeviceFilterModel> m_deviceModel;
};

}
}
}

#endif // REMOTESYSTEMOPTIONS_H
