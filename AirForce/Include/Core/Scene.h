// project: AirForce
// created by: Bot-Kerem
// create date: 26.09.2022
// updated: 26.09.2022

#ifndef AIRFORCE_SCENE_H
#define AIRFORCE_SCENE_H

#include <Graphics/Framebuffer.h>
#include <Core/Shader.h>
#include <Utils/Camera.h>

#include <glm/vec3.hpp>

#include <string>

namespace AirForce
{
    class Scene
    {
    private:
        Framebuffer m_Framebuffer{800, 600};
    public:
        AirForce::Shader m_Shader{"./../Shaders/raymarch.vs", "./../Shaders/raymarch.fs"};
        std::string Name;
        glm::vec3 ClearColor;
        Camera m_Camera{};
        
        Scene(std::string Name, glm::vec3 ClearColor = {0.31f, 0.31f, 0.31f});

        void Draw();

        inline unsigned int getRenderImage(){return m_Framebuffer.getRenderImage();}
    };
} // namespace AirForce

#endif // AIRFORCE_SCENE_H