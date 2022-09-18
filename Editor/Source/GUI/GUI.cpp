#include <GUI.h>

#include <Graphics/Texture.h>

Icon* FileIcon;

bool isProjectSettingsOpen = false;

namespace GUI
{
  void Show()
  {
    GUI::MainMenuBar();
    DockSpace();

    ProjectExplorer();
    if(isProjectSettingsOpen) ProjectSettings();
  }
}
