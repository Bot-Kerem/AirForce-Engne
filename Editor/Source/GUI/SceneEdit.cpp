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

            if(ImGui::TreeNode("Ray Marching"))
            {
                ImGui::Text("View Distance");
                ImGui::SameLine();
                ImGui::DragFloat("##ViewDistance", &(scene.m_Camera.ViewDistance), 0.1f, 0.0f, FLT_MAX, "%.1f");
                ImGui::Text("Max Steps");
                ImGui::SameLine();
                ImGui::DragInt("##MaxSteps", &(scene.m_Camera.MaxSteps), 1.0f, 0, UINT8_MAX);
                ImGui::TreePop();
            }

        ImGui::End();
    }
} // namespace GUI
