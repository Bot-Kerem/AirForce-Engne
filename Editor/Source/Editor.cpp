#include <Editor.h>

#include <Graphics/Renderer.h>
#include <GUI.h>
#include <Builder.h>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>

Builder builder{};

Editor::Editor()
{
  Build();
}

void Editor::Run()
{
  while (!window.IsClosed()){
      AirForce::Window::PollEvents();

      //AirForce::ClearScreen();
      if(glfwGetKey(window.getWindow(), GLFW_KEY_SPACE)) { m_Scene.m_Camera.Position.y += 0.1; }
      if(glfwGetKey(window.getWindow(), GLFW_KEY_W)) { m_Scene.m_Camera.Position.z += 0.1; }
      if(glfwGetKey(window.getWindow(), GLFW_KEY_S)) { m_Scene.m_Camera.Position.z -= 0.1; }
      if(glfwGetKey(window.getWindow(), GLFW_KEY_D)) { m_Scene.m_Camera.Position.x -= 0.1; }
      if(glfwGetKey(window.getWindow(), GLFW_KEY_A)) { m_Scene.m_Camera.Position.x += 0.1; }

      m_Scene.Draw();

      GUI::Show(m_Scene);

      window.SwapBuffers();
  }
}

void Editor::Build()
{
  GUI::LoadImGui(window.getWindow());
  GUI::LoadIcons();

  builder.Load("/home/kereem/Desktop/AirForceProject");

  AirForce::ClearColor(0.31f, 0.31f, 0.31f); // gray
}

void Editor::Terminate()
{
  GUI::FreeIcons();
}
