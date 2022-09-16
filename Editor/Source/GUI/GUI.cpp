#include <GUI.h>


bool isProjectSettingsOpen = false;

namespace GUI
{

  void Show()
  {
    GUI::MainMenuBar();
    DockSpace();

    if(isProjectSettingsOpen) ProjectSettings();
  }
}
