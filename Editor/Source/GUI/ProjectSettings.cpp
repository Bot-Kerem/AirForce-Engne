#include <GUI.h>
#include <Platform.h>

#include <imgui.h>
#include <imgui_stdlib.h>

extern bool isProjectSettingsOpen;

#include <Builder.h>
extern Builder builder;

namespace GUI
{
  void ProjectSettings()
  {
    ImGui::Begin("Project Settings", &isProjectSettingsOpen);
    ImGui::Text("Project Name ");
    ImGui::SameLine();
    ImGui::InputText("##ProjectName", &(builder.Settings.ProjectName));
    ImGui::End();
  }
}
