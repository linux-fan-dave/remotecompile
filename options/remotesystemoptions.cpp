#include "remotesystemoptions.h"
#include "remotecompileconstants.h"
#include "remotesystemoptionsform.h"

namespace RemoteCompile {
namespace  Options {
namespace Internal {

RemoteSystemOptions::RemoteSystemOptions(QObject *parent)
    :Core::IOptionsPage(parent)
{
    setId(Core::Id(Constants::REMOTECOMPILE_OPTIONS_ID));
    setDisplayName(tr("Remote Compile Settings"));

    // Create a new category for the options page. Here we create a totally
    // new category. In that case we also provide an icon. If we choose in
    // 'setCategory' an already existing category, the options page is added
    // the chosen category and an additional tab. No icon is set in this case.
    setCategory(Constants::FILEMAPPING_OPTIONS_CATEGORY);
    setDisplayCategory(Constants::FILEMAPPING_OPTIONS_CATEGORY_TR_CATEGORY);
    setCategoryIcon(QString(Constants::FILEMAPPING_OPTIONS_CATEGORY_ICON));
}

QWidget *RemoteSystemOptions::widget()
{
    return new RemoteSystemOptionsForm();
}

void RemoteSystemOptions::apply()
{

}

void RemoteSystemOptions::finish()
{

}

}
}
}
