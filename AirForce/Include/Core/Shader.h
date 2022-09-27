// project: AirForce
// created by: Bot-Kerem
// create date: 26.09.2022
// updated: 26.09.2022

#ifndef AIRFORCE_SHADER_H
#define AIRFORCE_SHADER_H

#include <string>
#include <glm/vec3.hpp>

namespace AirForce
{
    class Shader
    {
        private:
            unsigned int m_Program{0};
            unsigned int getUniformLocation(const char* uniformName);
        public:
            Shader(std::string VertexShaderPath, std::string FragmentShaderPath);
            void use();

            void setFloat(const char* uniformName, float val);
            void setInt(const char* uniformName, int val);

            void setVec3(const char* uniformName, const glm::vec3& val);
            void setVec3(const char* uniformName, glm::vec3&& val);
    };
} // namespace AirForce


#endif // AIRFORCE_SHADER_H