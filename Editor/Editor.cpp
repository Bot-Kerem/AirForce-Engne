#include <Core/Window.h>

int main(){
    AirForce::Window::init();

    AirForce::Window window{"GAMEE", 800, 600};

    while (!window.IsClosed()){
        AirForce::Window::PollEvents();

        window.SwapBuffers();
    }
    return 0;
 }