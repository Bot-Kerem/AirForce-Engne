// project: AirForce
// created by: Bot-Kerem
// create date: 14.09.2022
// updated: 14.09.2022
#ifndef AIRFORCE_EDITOR
#define AIRFORCE_EDITOR

#include <Core/Window.h>
#include <Core/Scene.h>
#include <Core/Shader.h>

class Editor
{
  private:
    const char* Title = "AirForce Editor";
    const int Width = 800;
    const int Height = 600;

    void Build();

    AirForce::Window window{Title, Width, Height};
    AirForce::Scene m_Scene{"Main Scene"};
    AirForce::Shader m_Shader{"./../Shaders/raymarch.vs", "./../Shaders/raymarch.fs"};
    
  public:
    Editor();
    void Run();

    void Terminate();

};

#endif // AIRFORCE_EDITOR
