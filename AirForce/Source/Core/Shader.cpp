#include <Core/Shader.h>

#include <Core/Platform.h>
#include <Core/Types.h>

#include <glad/glad.h>

namespace AirForce
{
    Shader::Shader(std::string VertexShaderPath, std::string FragmentShaderPath)
    {
        m_Program = glCreateProgram();

        unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
        {
            std::string VertexSource = OpenFile(VertexShaderPath);
            const char* sourceCode = &VertexSource[0];
            glShaderSource(VertexShader, 1, &sourceCode, 0);
            glCompileShader(VertexShader);
            int isCompiled = 0;
            glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &isCompiled);
            if(!isCompiled)
            {
                char log[512];
                glGetShaderInfoLog(VertexShader, 512, 0, log);
                Debug(std::string(VertexShaderPath + std::string{log}).c_str() , ERROR);
            }
        }
        unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        {
            std::string FragmentSource = OpenFile(FragmentShaderPath);
            const char* sourceCode = &FragmentSource[0];
            glShaderSource(FragmentShader, 1, &sourceCode, 0);
            glCompileShader(FragmentShader);
            int isCompiled = 0;
            glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &isCompiled);
            if(!isCompiled)
            {
                char log[512];
                glGetShaderInfoLog(FragmentShader, 512, 0, log);
                Debug(std::string(FragmentShaderPath + std::string{log}).c_str() , ERROR);
            }
        }
        glAttachShader(m_Program, VertexShader);
        glAttachShader(m_Program, FragmentShader);

        glLinkProgram(m_Program);

        int isLinked = 0;
        glGetProgramiv(m_Program, GL_LINK_STATUS, &isLinked);
        if(!isLinked)
        {
            char log[512];
            glGetProgramInfoLog(m_Program, 512, 0, log);
            Debug(std::string{log}.c_str() , ERROR);
        }

        glDeleteShader(VertexShader);
        glDeleteShader(FragmentShader);
    }

    void Shader::use()
    {
        glUseProgram(m_Program);
    }

    unsigned int Shader::getUniformLocation(const char* uniformName)
    {
        return glGetUniformLocation(m_Program, uniformName);
    }

    void Shader::setVec3(const char* uniformName, const glm::vec3& val)
    {
        glUniform3f(getUniformLocation(uniformName), val.x, val.y, val.z);
    }

    void Shader::setVec3(const char* uniformName, glm::vec3&& val)
    {
        glUniform3f(getUniformLocation(uniformName), val.x, val.y, val.z);
    }

    void Shader::setFloat(const char* uniformName, float val)
    {
        glUniform1f(getUniformLocation(uniformName), val);
    }

    void Shader::setInt(const char* uniformName, int val)
    {
        glUniform1i(getUniformLocation(uniformName), val);
    }

    void Shader::setMat4(const char* uniformName, glm::mat4* ptrMatrix)
    {
        glUniformMatrix4fv(getUniformLocation(uniformName), 1, GL_FALSE, (float*)(ptrMatrix));
    }
    
} // namespace AirForce
