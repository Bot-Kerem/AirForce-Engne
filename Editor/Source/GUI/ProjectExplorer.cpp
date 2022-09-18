#include <GUI.h>

#include <Builder.h>
extern Builder builder;

#include <ProjectFolder.h>
extern Folder ProjectFolder;

#include <Graphics/Texture.h>
extern Icon* FileIcon;
extern Icon* FolderIcon;

#include <imgui.h>

#include <iostream>

Folder* currentFolder = &ProjectFolder;

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

  ImVec2 size = ImGui::GetWindowContentRegionMax();
  ImGui::Columns(std::max((size.x/100), 1.0f));
  for(auto& folder: currentFolder->Folders)
  {
      ImGui::Image(FolderIcon->GetTexture(), ImVec2(100.f, 100.f));
      ImGui::Text(folder.Name.c_str());
      ImGui::NextColumn();
  }
  for(auto& file: currentFolder->Files)
  {
      ImGui::Image(FileIcon->GetTexture(), ImVec2(100.f, 100.f));
      ImGui::Text(file.Name.c_str());
      ImGui::NextColumn();
  }

  //ImGui::Image(FolderIcon->GetTexture(), ImVec2(100.f, 100.f));//, ImVec2(0,0), ImVec2(1,1), ss);
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
        ShowFolder(_folder); // List folders in folder
      }
      for(auto& file: folder.Files) // List files in folder
      {
        ImGui::Selectable(file.Name.c_str());
      }
      ImGui::TreePop();
    }
  }
} // void ShowFolder(Folder& folder)
