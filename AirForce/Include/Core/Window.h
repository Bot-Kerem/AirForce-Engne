// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 08.09.2022

#ifndef AIRFORCE_WINDOW_H
#define AIRFORCE_WINDOW_H

struct GLFWwindow;

namespace AirForce
{
    class Window
    {
    private:
        GLFWwindow* m_Window;
    public:
        Window(const char* title, int width, int height);
        ~Window();

        bool IsClosed();

        void SwapBuffers();

        GLFWwindow* getWindow();

        void makeContextCurrent();

        static GLFWwindow* getContextCurrent();

        static void makeContextCurrent(GLFWwindow* window);

        static void PollEvents();

    }; // class Window

} // namespace AirForce


#endif // AIRFORCE_WINDOW_H
