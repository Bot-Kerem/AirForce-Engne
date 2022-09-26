#include <Core/Scene.h>

#include <glad/glad.h>
#include <Graphics/Renderer.h>


namespace AirForce
{
    Scene::Scene(std::string Name, glm::vec3 ClearColor)
        :Name(Name), ClearColor(ClearColor)
    {

    }

    void Scene::Draw()
    {
        m_Framebuffer.Bind();
        AirForce::ClearScreen();

        m_Framebuffer.UnBind();
    }
} // namespace AirForce
