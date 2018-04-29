#include "filemappingoptions.h"
#include "remotecompileconstants.h"
#include "filemappingoptionsform.h"

namespace RemoteCompile {
namespace  Options {
namespace Internal {

FileMappingOptions::FileMappingOptions(QObject* parent)
    :Core::IOptionsPage(parent)
{
    setId(Core::Id(Constants::FILEMAPPING_OPTIONS_ID));
    setDisplayName(tr("File Mappings"));

    // Create a new category for the options page. Here we create a totally
    // new category. In that case we also provide an icon. If we choose in
    // 'setCategory' an already existing category, the options page is added
    // the chosen category and an additional tab. No icon is set in this case.
    setCategory(Constants::FILEMAPPING_OPTIONS_CATEGORY);
    setDisplayCategory(Constants::FILEMAPPING_OPTIONS_CATEGORY_TR_CATEGORY);
    setCategoryIcon(QString(Constants::FILEMAPPING_OPTIONS_CATEGORY_ICON));
}

QWidget *FileMappingOptions::widget()
{
    return new FileMappingOptionsForm();
}

void FileMappingOptions::apply()
{

}

void FileMappingOptions::finish()
{

}

}
}
}
