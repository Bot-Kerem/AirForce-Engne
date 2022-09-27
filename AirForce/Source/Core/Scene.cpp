#include <Core/Scene.h>

#include <glad/glad.h>
#include <Graphics/Renderer.h>

#include <glm/gtc/matrix_transform.hpp>

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
        m_Shader.setVec3("ro", m_Camera.Position);
        m_Shader.setFloat("MAX_DIST", m_Camera.ViewDistance);
        m_Shader.setFloat("k", m_Camera.k);
        glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), m_Camera.Pitch, glm::vec3(0.0f, 1.0f, 0.0f));
        m_Shader.setMat4("rotateCamera", &rotate);
        m_Shader.setInt("MAX_STEPS", m_Camera.MaxSteps);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        m_Framebuffer.UnBind();
    }
} // namespace AirForce
