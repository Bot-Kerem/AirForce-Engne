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

        m_Shader.use();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        m_Framebuffer.UnBind();
    }
} // namespace AirForce
