// project: AirForce
// created by: Bot-Kerem
// create date: 08.09.2022
// updated: 08.09.2022

#ifndef AIRFORCE_GRAPHICS_RENDERER
#define AIRFORCE_GRAPHICS_RENDERER

namespace AirForce{
    void ClearScreen();

    // values needs to be between 1 and 0
    void ClearColor(float red, float green, float blue, float alpha = 1.0f);
} // namespace AirForce


#endif