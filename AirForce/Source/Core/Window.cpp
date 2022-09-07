// AirForce Headers
#include <Core/Window.h>
#include <Core/Types.h>

// Standart Headers
#include <GLFW/glfw3.h>

namespace AirForce{

    void Window::init(){
        Debug("Initializing GLFW");
        if(!glfwInit()){
            Debug("GLFW couldn't initialized!");
        }
    }

    Window::~Window(){
        glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    Window::Window(const char* title, int width, int height){
        m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
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
