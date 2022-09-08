// AirForce Headers
#include <Core/Window.h>
#include <Core/Types.h>

// third party
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standart Headers

namespace AirForce{

    void Window::init(){
        Debug("Initializing GLFW");
        if(!glfwInit()){
            Debug("GLFW couldn't initialized!", ERROR);
        }
    }

    Window::~Window(){
        glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    Window::Window(const char* title, int width, int height){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        glfwMakeContextCurrent(m_Window);

        Debug("Loading OpenGL Compatibility Profile");
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            Debug("OpenGL Compatibility Profile couldn't loaded!", ERROR);
        }
    }

    bool Window::IsClosed(){
        return glfwWindowShouldClose(m_Window);
    }

    void Window::SwapBuffers(){
        glfwSwapBuffers(m_Window);
    }

    void Window::PollEvents(){
        glfwPollEvents();
    }
    
} // namespace AirForce
