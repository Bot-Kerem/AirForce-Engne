// project: AirForce
// created by: Bot-Kerem
// create date: 26.09.2022
// updated: 26.09.2022

#ifndef AIRFORCE_FRAMEBUFFER_H
#define AIRFORCE_FRAMEBUFFER_H

#include <Graphics/Texture.h>

namespace AirForce
{
    class Framebuffer
    {
        private:
            unsigned int m_Framebuffer{0};
            unsigned int m_Renderbuffer{0};
            Texture m_Texture{};

        public:
            Framebuffer(int Width, int Height);
            void Bind();
            void UnBind();
            inline unsigned int getRenderImage(){return m_Texture.GetTexture();}
    };
} // namespace AirForce


#endif // AIRFORCE_FRAMEBUFFER_H
