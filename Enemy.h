#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class ENEMY : public character 
{
    public:
        ENEMY(); 
        void GenerateBoss(); 
};

#endif