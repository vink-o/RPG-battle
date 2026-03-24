#include "Battle.h"

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

void Battle :: StartFight(HERO &player, ENEMY &boss)
{
    cout<<"---The Fight can Begin!---"<<endl;
    cout<<player.GetName()<<" VS. "<<boss.GetName()<<endl;

    srand(time(0));
    double MaxHP_player=player.GetHP();
    double MaxHP_boss=boss.GetHP();

    while(player.GetHP()>=0 && boss.GetHP()>=0)
    {
        system("cls");

        cout<<player.GetName()<<": ["<<player.GetHP()<<" HP]"<<endl;
        cout<<boss.GetName()<<": ["<<boss.GetHP()<<" HP]"<<endl;

        SuperPower(player);
        cout<<endl<<"--------------------------------"<<endl;
        HitAndDamage(player);

        int choice;
        cin>>choice;

        boss.LowerHP(player.Attacks[choice-1].damage);

        cout<<"Damage : "<<boss.GetName()<<"HP lower for "<<player.Attacks[choice-1].damage<<"!"<<endl;

        if(choice == 3) 
            player.SuperCounter = 0;
        else if(player.SuperCounter < 2) 
            player.SuperCounter++;

        system("pause");

        BossAttack(player,boss);

        system("pause");
    }

    if(player.GetHP()<=0)
        cout<<"You lose!  "<<boss.GetName()<<"  WON!"<<endl;
    else
        cout<<"You are the WINNER!  " <<boss.GetName()<<"  Lost!"<<endl;
}

void Battle::BossAttack(HERO &player, ENEMY &boss)
{
    int BOSSCHOICE;
    if(boss.GetHP()>0)
    {
        if(boss.SuperCounter>=2)
        {
            BOSSCHOICE=2;
            boss.SuperCounter=0;
            cout<<"Boss used SPECIAL ATTACK !"<<endl;
        }
        else
        {
            BOSSCHOICE = rand() % 2;
            boss.SuperCounter++;
        }

        int Damage;
        Damage = boss.Attacks[BOSSCHOICE].damage;
        player.LowerHP(Damage);

        cout << ">>> " << boss.GetName() << " used: " << boss.Attacks[BOSSCHOICE].name << endl;
        cout << ">>> Damage  " << Damage<<" !"<< endl;
    }
}

void Battle :: HitAndDamage(HERO &player)
{
    if(player.SuperCounter!=2)
    {
        cout<<"1."<<player.Attacks[0].name<<endl;
        cout<<"2."<<player.Attacks[1].name<<endl;
        cout<<"Super is Charging!"<<endl;
    }
    else
    {
        cout<<"1."<<player.Attacks[0].name<<endl;
        cout<<"2."<<player.Attacks[1].name<<endl;
        cout<<"3."<<player.Attacks[2].name<<endl;
    }
}

void Battle :: SuperPower(HERO &player)
{
    if(player.SuperCounter==0)
        cout<<"ENERGY [--]";
    else if(player.SuperCounter==1)
        cout<<"ENERGY [X-]";
    else if(player.SuperCounter==2)
        cout<<"ENERGY [XX]    ->  SUPER READY!";
}