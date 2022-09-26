#include <GUI.h>

#include <Graphics/Renderer.h>

#include <imgui.h>
#include <imgui_stdlib.h>

namespace GUI
{
    void SceneEdit(AirForce::Scene& scene)
    {
        ImGui::Begin("Scene Edit");
        ImGui::Text("Name");
        ImGui::SameLine();
        ImGui::InputText(" ", &(scene.Name));

        ImGui::Text("Clear Color");
        ImGui::SameLine();
            if (ImGui::ColorButton("Clear Color", ImVec4(scene.ClearColor.x, scene.ClearColor.y, scene.ClearColor.z, 1.0f))) 
            {
                ImGui::OpenPopup("CLEAR-COLOR_EDIT");
            }

            if (ImGui::BeginPopup("CLEAR-COLOR_EDIT")) 
            {
                ImGui::ColorPicker3("", (float*)&(scene.ClearColor),
                                    ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoSidePreview |
                                    ImGuiColorEditFlags_NoSmallPreview);
                AirForce::ClearColor(scene.ClearColor.x, scene.ClearColor.y, scene.ClearColor.z);
                ImGui::EndPopup();
            }

        ImGui::End();
    }
} // namespace GUI
