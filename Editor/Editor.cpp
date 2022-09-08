#include <Core/Window.h>
#include <Graphics/Renderer.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

int main(){
    AirForce::Window::init();

    AirForce::Window window{"AirForce Editor", 800, 600};

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 460");

    AirForce::ClearColor(0.31f, 0.31f, 0.31f); // gray
    while (!window.IsClosed()){
        AirForce::Window::PollEvents();

        AirForce::ClearScreen();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    	
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = AirForce::Window::getContextCurrent();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            AirForce::Window::makeContextCurrent(backup_current_context);
        }

        window.SwapBuffers();
    }
    return 0;
 }