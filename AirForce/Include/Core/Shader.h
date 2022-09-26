// project: AirForce
// created by: Bot-Kerem
// create date: 26.09.2022
// updated: 26.09.2022

#ifndef AIRFORCE_SHADER_H
#define AIRFORCE_SHADER_H

#include <string>

namespace AirForce
{
    class Shader
    {
        private:
            unsigned int m_Program{0};
        public:
            Shader(std::string VertexShaderPath, std::string FragmentShaderPath);
    };
} // namespace AirForce


#endif // AIRFORCE_SHADER_H