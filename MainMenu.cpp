#include "Character.h" 
#include "Hero.h"
#include "Enemy.h"
#include "Battle.h"
#include "MainMenu.h"

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
#include<limits>
#include<random>
#include <cstdlib>
using namespace std;


void MainMenu()
{
    int n=10;
    character c;
    HERO h;
    ENEMY e;
    Battle arena;

    while(n!=4)
    {
        cout<<"+==========================+"<<endl;
        cout<<"|     RPG BATTLE ARENA     | "<<endl;
        cout<<"+==========================+"<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<">> You against Boss"<<endl;
        cout<<">> Hero Lore"<<endl;
        cout<<">> Enemy Lore"<<endl;
        cout<<">> Exit"<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<">> Enter your choice:"<<endl;

        int i;
        cin>>i;

        if(i==1)
        {
            h.ChooseYourCharacter();
            e.GenerateBoss();
            arena.StartFight(h,e);
        }
        else if(i==2)
            c.HeroLore();
        
        else if(i==3)
            c.EnemyLore();

        else
            n=4;
    }

}

int main()
{
    srand(time(0));
    MainMenu();
    return 0;
}