#include <Graphics/Renderer.h>

#include <glad/glad.h>

namespace AirForce{
    void ClearScreen(){
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void ClearColor(float red, float green, float blue, float alpha){
        glClearColor(red, green, blue, alpha);
    }
} // namespace AirForce
