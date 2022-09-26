#include <GUI.h>

#include <imgui.h>

namespace GUI
{
    void SceneEditor(AirForce::Scene& scene)
    {
        ImGui::PushID(1);
        ImGui::Begin((scene.Name + "###Scene").c_str());
        ImGui::BeginChild("#Scene");
        auto renderSceneSize = ImGui::GetWindowSize();
        ImGui::Image(scene.getRenderImage(), renderSceneSize, {0, 0}, {1, 1});

        ImGui::EndChild();
        ImGui::End();
        ImGui::PopID();
    }   
} // namespace GUI
