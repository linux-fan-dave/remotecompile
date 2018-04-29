#ifndef REMOTESYSTEMOPTIONS_H
#define REMOTESYSTEMOPTIONS_H

#include <coreplugin/dialogs/ioptionspage.h>
#include <QObject>

namespace RemoteCompile {
namespace  Options {
namespace Internal {

class RemoteSystemOptions : public Core::IOptionsPage
{
    Q_OBJECT
public:
    RemoteSystemOptions(QObject *parent = 0);

    // IOptionsPage interface
public:
    virtual QWidget *widget() override;
    virtual void apply() override;
    virtual void finish() override;
};

}
}
}

#endif // REMOTESYSTEMOPTIONS_H
