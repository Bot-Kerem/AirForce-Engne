#include <Core/Window.h>
#include <Graphics/Renderer.h>

int main(){
    AirForce::Window::init();

    AirForce::Window window{"AirForce Editor", 800, 600};
    AirForce::ClearColor(0.31f, 0.31f, 0.31f); // gray
    while (!window.IsClosed()){
        AirForce::Window::PollEvents();

        AirForce::ClearScreen();

        window.SwapBuffers();
    }
    return 0;
 }