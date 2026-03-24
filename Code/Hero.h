#ifndef HERO_H
#define HERO_H

#include "Character.h" 

class HERO : public character 
{
    private:
        std::string position;

    public: 
        HERO(); 
        void ChooseYourCharacter();
};

#endif
