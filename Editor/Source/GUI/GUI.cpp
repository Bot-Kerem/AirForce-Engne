#include <GUI.h>

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
