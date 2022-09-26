// project: AirForce
// created by: Bot-Kerem
// create date: 16.09.2022
// updated: 16.09.2022

#ifndef AIRFORCE_EDITOR_GUI
#define AIRFORCE_EDITOR_GUI

#include <Core/Scene.h>

struct GLFWwindow;

namespace GUI
{
  void Show(AirForce::Scene& scene);

  void DockSpace();
  void MainMenuBar();
  void ProjectExplorer();
  void SceneEdit(AirForce::Scene& scene);

  void ProjectSettings();

  void SceneEditor(AirForce::Scene& scene);

  void LoadImGui(GLFWwindow* window);
  void LoadIcons();
  void FreeIcons();
} // GUI

#endif // AIRFORCE_EDITOR_GUI
