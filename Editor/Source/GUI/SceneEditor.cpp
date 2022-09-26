#include <GUI.h>

#include <imgui.h>

namespace GUI
{
    void SceneEditor(AirForce::Scene& scene)
    {
        ImGui::Begin(scene.Name.c_str());

        ImGui::End();
    }   
} // namespace GUI
