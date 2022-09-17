#include <GUI.h>

#include <imgui.h>

extern bool isProjectSettingsOpen;

#include <Builder.h>
extern Builder builder;

namespace GUI
{
  void MainMenuBar()
  {
    ImGui::BeginMainMenuBar();
    if(ImGui::BeginMenu("Project"))
    {
      if(ImGui::MenuItem("Project Settings")) {isProjectSettingsOpen = !isProjectSettingsOpen;}
      if(ImGui::MenuItem("Open Project")) {builder.Load("");}
      if(ImGui::MenuItem("Build")) {}
      ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
  }
}
