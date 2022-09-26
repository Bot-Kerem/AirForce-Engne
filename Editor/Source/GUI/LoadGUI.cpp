#include <GUI.h>

#include <Graphics/Texture.h>
extern Icon* FileIcon;
extern Icon* FolderIcon;
extern Icon* ParentFolderIcon;

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace GUI
{
  void LoadImGui(GLFWwindow* window)
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460 compatibility");
  }

  void LoadIcons()
  {
    FileIcon = new Icon{"./../Resources/File.png"};
    FolderIcon = new Icon{"./../Resources/Folder.png"};
    ParentFolderIcon = new Icon{"./../Resources/ParentFolder.png"};
  } // void LoadIcons()

  void FreeIcons()
  {
    delete FileIcon;
    delete FolderIcon;
    delete ParentFolderIcon;
  }
} // namespace GUI
