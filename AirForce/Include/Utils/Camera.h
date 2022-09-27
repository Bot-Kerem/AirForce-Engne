// project: AirForce
// created by: Bot-Kerem
// create date: 27.09.2022
// updated: 27.09.2022

#ifndef AIRFORCE_CAMERA_H
#define AIRFORCE_CAMERA_H

#include <glm/vec3.hpp>

namespace AirForce
{
    class Camera
    {
        private:

        public:
            Camera(glm::vec3 Position = {0.0f, 0.0f, 0.0f});
            float ViewDistance = 100.0f;
            int MaxSteps = 100;

            glm::vec3 Position;
    };
} // namespace AirForce


#endif // AIRFORCE_CAMERA_H
