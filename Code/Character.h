#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>


extern std::vector<std::string> HeroNames;
extern std::vector<std::string> EnemyNames;

struct Attack
{
    std::string name;
    int damage;
    int chance;
    int SuperRequired;
};

class character
{
    protected:
        double HP;
        std::string name;

    public:
        double damage;
        double MaxHP;
        bool SuperPower = false; // mogucnost koristenja super moci (svako treci udarac?)
        int SuperCounter = 0; // brojac koji broji kada se moze koristiti super moc
        std::vector<Attack> Attacks;

        void HeroLore();
        void EnemyLore();
        void LowerHP(double Damage){HP -= Damage;}

        double GetHP() {return HP;};
        std::string GetName(){return name;};
};

#endif
