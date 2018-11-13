#pragma once

namespace RemoteCompile {
namespace Constants {

const char ACTION_ID[] = "RemoteCompile.Action";
const char MENU_ID[] = "RemoteCompile.Menu";
const char FILEMAPPING_OPTIONS_ID[] = "RemoteCompile.Filemapping.Options";
const char REMOTECOMPILE_OPTIONS_ID[] = "RemoteCompile.RemoteCompile.Options";

const char FILEMAPPING_OPTIONS_CATEGORY[] = "H.Remote Compile";
const char FILEMAPPING_OPTIONS_CATEGORY_ICON[] = ":resources/Icon.png";
const char FILEMAPPING_OPTIONS_CATEGORY_TR_CATEGORY[] =
    QT_TRANSLATE_NOOP("Remote Compile", "Remote Compile");

const char TOOLCHAIN_ID[] = "RemoteCompile.ToolChain";
const char INNERTOOLCHAIN_ID[] = "RemoteCompile.InnerToolChain";

const char KIT_IS_REMOTE_ID[] = "RemoteCompile.IsRemote";

} // namespace RemoteCompile
} // namespace Constants
