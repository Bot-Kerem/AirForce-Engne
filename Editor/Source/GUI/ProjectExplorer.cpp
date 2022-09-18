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
  ImGui::Columns(std::max((size.x/100) - 1, 1.0f));
  // PARENT
  if(currentFolder->Parent)
  {
    ImGui::ImageButton(FolderIcon->GetTexture(), ImVec2(100.f, 100.f), {1, 0}, {0, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f}); // FIXME: Add Parent Folder Icon
    if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
    {
      currentFolder = currentFolder->Parent;
    }
    if(currentFolder->Parent) ImGui::Text(currentFolder->Parent->Name.c_str());
    ImGui::NextColumn();
  }

  // PARENT
  int ID = 0;
  for(auto& folder: currentFolder->Folders)
  {
      ImGui::PushID(ID++);
      ImGui::ImageButton(FolderIcon->GetTexture(), ImVec2(100.f, 100.f), {1, 0}, {0, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
      if(ImGui::BeginDragDropSource())
      {
        ImGui::SetDragDropPayload("PROJECT_EXPLORER_DIR", &folder, 8, ImGuiCond_Once); // Pointers are 8 bytes
        ImGui::ImageButton(FolderIcon->GetTexture(), ImVec2(100.f, 100.f), {1, 0}, {0, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
        ImGui::Text(folder.Name.c_str());
        ImGui::EndDragDropSource();
      }
      if(ImGui::BeginDragDropTarget())
      {
        ImGui::AcceptDragDropPayload("PROJECT_EXPLORER_FILE");
        ImGui::EndDragDropTarget();
      }
      if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
      {
        currentFolder = &folder;
      }
      ImGui::Text(folder.Name.c_str());
      ImGui::NextColumn();
      ImGui::PopID();
  }
  for(auto& file: currentFolder->Files)
  {
      ImGui::PushID(ID++);
      ImGui::ImageButton(FileIcon->GetTexture(), ImVec2(100.f, 100.f), {1, 0}, {0, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
      if(ImGui::BeginDragDropSource())
      {
        ImGui::SetDragDropPayload("PROJECT_EXPLORER_FILE", &file, 8, ImGuiCond_Once); // Pointers are 8 bytes
        ImGui::ImageButton(FileIcon->GetTexture(), ImVec2(100.f, 100.f), {1, 0}, {0, 1}, 0, {0.31f, 0.31f, 0.28f, 0.7f});
        ImGui::Text(file.Name.c_str());
        ImGui::EndDragDropSource();
      }
      ImGui::Text(file.Name.c_str());
      ImGui::NextColumn();
      ImGui::PopID();
  }

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
