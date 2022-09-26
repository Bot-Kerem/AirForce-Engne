#include <Editor.h>

#include <Graphics/Renderer.h>
#include <GUI.h>
#include <Builder.h>

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
