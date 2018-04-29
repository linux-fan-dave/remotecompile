#ifndef FILEMAPPINGOPTIONS_H
#define FILEMAPPINGOPTIONS_H

#include <coreplugin/dialogs/ioptionspage.h>
#include <QObject>

namespace RemoteCompile {
namespace  Options {
namespace Internal {

class FileMappingOptions : public Core::IOptionsPage
{
    Q_OBJECT
public:
    FileMappingOptions(QObject* parent = Q_NULLPTR);

    // IOptionsPage interface
public:
    QWidget *widget() override;
    void apply() override;
    void finish() override;
};

}
}
}
#endif // FILEMAPPINGOPTIONS_H
