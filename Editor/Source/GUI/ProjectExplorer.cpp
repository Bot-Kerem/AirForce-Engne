#include <GUI.h>

#include <Builder.h>
extern Builder builder;

#include <Graphics/Texture.h>
extern Icon* FileIcon;
extern Icon* FolderIcon;
extern Icon* ParentFolderIcon;

#include <imgui.h>

#include <iostream>
#include <filesystem>

void GUI::ProjectExplorer()
{
  static std::string viewFolder = builder.Settings["path"];

  ImGuiWindowClass window_class;
  window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Project Explorer", nullptr, ImGuiWindowFlags_NoCollapse);

  //ShowFolder(ProjectFolder);

  ImGui::End();

  ImGui::SetNextWindowClass(&window_class);
  ImGui::Begin("Folder Viewer", nullptr, ImGuiWindowFlags_NoCollapse);

  ImVec2 size = ImGui::GetWindowContentRegionMax();
  ImGui::Columns(std::max((size.x/120), 1.0f));

  int ID = 0;
  if(viewFolder != builder.Settings["path"])
  {
    auto up_dir = std::filesystem::path(viewFolder).parent_path();
    ImGui::PushID(ID++);
    ImGui::ImageButton(ParentFolderIcon->GetTexture(), ImVec2(100.f, 100.f), {0, 0}, {1, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
    if(ImGui::BeginDragDropTarget())
        {
          ImGui::AcceptDragDropPayload("PROJECT_EXPLORER_FILE");
          ImGui::EndDragDropTarget();
        }
        if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
        {
          viewFolder = up_dir;
        }
    ImGui::Text(up_dir.filename().c_str());
    ImGui::NextColumn();
    ImGui::PopID();
  }

  for(auto&& dir: std::filesystem::directory_iterator(viewFolder))
  {
    if((dir.path().filename().c_str())[0] == '.')
      continue;
    ImGui::PushID(ID++);
    if(dir.is_directory())
    {
      ImGui::ImageButton(FolderIcon->GetTexture(), ImVec2(100.f, 100.f), {0, 0}, {1, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
      if(ImGui::BeginDragDropTarget())
      {
        ImGui::AcceptDragDropPayload("PROJECT_EXPLORER_FILE");
        ImGui::EndDragDropTarget();
      }
      if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
      {
        viewFolder = dir.path();
      }
    }
    else
    {
      ImGui::ImageButton(FileIcon->GetTexture(), ImVec2(100.f, 100.f), {0, 0}, {1, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
      if(ImGui::BeginDragDropSource())
      {
        ImGui::SetDragDropPayload("PROJECT_EXPLORER_FILE", &ID, 8, ImGuiCond_Once); // Pointers are 8 bytes
        ImGui::ImageButton(FileIcon->GetTexture(), ImVec2(100.f, 100.f), {0, 0}, {1, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
        ImGui::Text(dir.path().filename().c_str());
        ImGui::EndDragDropSource();
      }
    }
    ImGui::Text(dir.path().filename().c_str());
    ImGui::NextColumn();
    ImGui::PopID();
  }
  ImGui::End();
} // void GUI::ProjectExplorer()

//void ShowFolder(Folder& folder)
//{
//  if(!folder.Name.empty())
//  {
//    if(ImGui::TreeNode(folder.Name.c_str()))
//    {
//      for(auto& _folder: folder.Folders)
//      {
//        ShowFolder(_folder); // List folders in folder
//      }
//      for(auto& file: folder.Files) // List files in folder
//      {
//        ImGui::Selectable(file.Name.c_str());
//      }
//      ImGui::TreePop();
//    }
//  }
//} // void ShowFolder(Folder& folder)
