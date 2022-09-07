// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 07.09.2022

#ifndef AIRFORCE_TYPES_H
#define AIRFORCE_TYPES_H

//#ifdef AF_DEBUG // not for now
    #define Debug(T) AirForce::_DEBUG(T);
//#endif

#include <iostream>

namespace AirForce{
    template <typename T> void _DEBUG(T log){
        std::cout << log << std::endl; // easy debug xd
    }
} // namespace AirForce


#endif // AIRFORCE_TYPES_H