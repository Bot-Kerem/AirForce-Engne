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

        glDeleteShader(VertexShader);
        glDeleteShader(FragmentShader);
    }
    
} // namespace AirForce