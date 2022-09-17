#include <GUI.h>

#include <Builder.h>
extern Builder builder;

#include <imgui.h>

#include <filesystem>
#include <iostream>

void GUI::ProjectExplorer()
{
  ImGuiWindowClass window_class;
  window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Project Explorer", nullptr, ImGuiWindowFlags_NoCollapse);

  if (!builder.Settings.ProjectPath.empty())
  {
    for (const auto & entry : std::filesystem::directory_iterator(builder.Settings.ProjectPath))
    {
      ImGui::Text(std::string(entry.path()).c_str());
    }
  }
  ImGui::End();

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Folder", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoCollapse);

  ImGui::End();
}
