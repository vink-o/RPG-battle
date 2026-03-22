#ifndef BATTLE_H
#define BATTLE_H

#include "Hero.h"
#include "Enemy.h"

class Battle 
{
    private:
        void BossAttack(HERO &player, ENEMY &boss);
        void HitAndDamage(HERO &player);
        void SuperPower(HERO &player);

    public:
        void StartFight(HERO &player, ENEMY &boss);
};

#endif