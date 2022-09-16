#include <GUI.h>

#include <imgui.h>

namespace GUI{
  void DockSpace()
  {
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
  } // void DockSpace()
} // GUI
