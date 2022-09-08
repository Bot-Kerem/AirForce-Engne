// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 08.09.2022

#ifndef AIRFORCE_TYPES_H
#define AIRFORCE_TYPES_H

#define ERROR 31

#include <stdio.h>

namespace AirForce{
    
    void Debug(const char* log, int color = 32){
        printf("\033[1;%im[DEBUG] \033[0m%s\n", color, log);
    }
} // namespace AirForce
#endif // AIRFORCE_TYPES_H