#include <GUI.h>

#include <Builder.h>
extern Builder builder;

#include <ProjectFolder.h>
extern Folder ProjectFolder;

#include <Graphics/Texture.h>
extern Icon* FileIcon;

#include <imgui.h>

#include <iostream>

void ShowFolder(Folder& folder);

void GUI::ProjectExplorer()
{
  ImGuiWindowClass window_class;
  window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Project Explorer", nullptr, ImGuiWindowFlags_NoCollapse);

  ShowFolder(ProjectFolder);

  ImGui::End();

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Folder Viewer", nullptr, ImGuiWindowFlags_NoCollapse);

  ImGui::ImageButton(FileIcon->GetTexturePtr(), ImVec2(500.f, 500.f));
  ImGui::Button("aa");

  ImGui::End();
} // void GUI::ProjectExplorer()

void ShowFolder(Folder& folder)
{
  if(!folder.Name.empty())
  {
    if(ImGui::TreeNode(folder.Name.c_str()))
    {
      for(auto& _folder: folder.Folders)
      {
        ShowFolder(_folder);
      }
      for(auto& file: folder.Files) // List files in folder
      {
        ImGui::Selectable(file.Name.c_str());
      }
      ImGui::TreePop();
    }
  }
} // void ShowFolder(Folder& folder)
