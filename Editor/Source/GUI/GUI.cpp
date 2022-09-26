#include <GUI.h>

#include <Graphics/Texture.h>

Icon* FileIcon;
Icon* FolderIcon;
Icon* ParentFolderIcon;

bool isProjectSettingsOpen = false;

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace GUI
{
  void Show(AirForce::Scene& scene)
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

      
    GUI::MainMenuBar();
    DockSpace();

    ProjectExplorer();
    if(isProjectSettingsOpen) ProjectSettings();

    SceneEdit(scene);
    SceneEditor(scene);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}
