#include <GUI.h>

#include <Graphics/Texture.h>

Icon* FileIcon;
Icon* FolderIcon;
Icon* ParentFolderIcon;

bool isProjectSettingsOpen = false;

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <Core/Scene.h>
extern AirForce::Scene scene;

namespace GUI
{
  void Show()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

      
    GUI::MainMenuBar();
    DockSpace();

    ProjectExplorer();
    if(isProjectSettingsOpen) ProjectSettings();

    SceneEditor(scene);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}
