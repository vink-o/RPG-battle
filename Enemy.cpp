#include "Enemy.h"

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

ENEMY::ENEMY() 
{
    HP = 0; 
    name = ""; 
    SuperPower = false; 
    SuperCounter = 0;
}

void ENEMY :: GenerateBoss()
        {

            int index = rand() % 10;
            this -> name = EnemyNames[index];

            if(index==0)
            {
                this -> HP = 100;
                Attacks.push_back({"Mind Riddle",8,75,0});
                Attacks.push_back({"Telepathic Shockwave",8,75,0});
                Attacks.push_back({"Fractured Leap",14,50,3});
            }
            else if(index==1)
            {
                this -> HP=100;
                Attacks.push_back({"Sonic Screech",8,100,0});
                Attacks.push_back({"Talon Slash",8,80,0});
                Attacks.push_back({"Wing Gust",14,55,3});
            }
            else if(index==2)
            {
                this -> HP=100;
                Attacks.push_back({"Void Strike",9,70,0});
                Attacks.push_back({"Shadow Step",8,75,0});
                Attacks.push_back({"Sandstorm Wave",15,50,3});
            }
            else if(index==3)
            {
                this -> HP=110;
                Attacks.push_back({"Chain Lightning",7,80,0});
                Attacks.push_back({"Thunder Crash",7,80,0});
                Attacks.push_back({"Static Field",15,50,3});
            }
            else if(index==4)
            {
                this -> HP=100;
                Attacks.push_back({"Head Swipe",6,70,0});
                Attacks.push_back({"Toxic Breath",8,65,0});
                Attacks.push_back({"Regrowth Strike",14,50,0});
            }
            else if(index==5)
            {
                this -> HP=115;
                Attacks.push_back({"Rampage Charge",7,75,0});
                Attacks.push_back({"Ground Slam",7,75,0});
                Attacks.push_back({"Frenzied Horns",14,50,0});
            }
            else if(index==6)
            {
                this -> HP=100;
                Attacks.push_back({"Petrifying Glare",8,65,0});
                Attacks.push_back({"Tendril Lash",8,65,0});
                Attacks.push_back({"Stasis Field",12,55,0});
            }
            else if(index==7)
            {
                this -> HP=110;
                Attacks.push_back({"Triple Bite",8,70,0});
                Attacks.push_back({"Hellfire Roar",8,70,0});
                Attacks.push_back({"Leaping Maul",14,60,0});
            }
            else if(index==8)
            {
                this -> HP=90;
                Attacks.push_back({"Fire Breath",12,70,0});
                Attacks.push_back({"Lightning Strike",12,70,0});
                Attacks.push_back({"Claw Rampage",17,75,3}); 
            }
            else if(index==9)
            {
                this -> HP=110;
                Attacks.push_back({"Devastating Slam",8,70,0});
                Attacks.push_back({"Limb Sweep",8,70,0});
                Attacks.push_back({"Energy Eruption",14,55,3});
            }

            cout << "\n======================================" << endl;
            cout << "   BOSS SELECTED: " << this->name << endl;
            cout << "   HEALTH POINTS: " << this->HP << " HP" << endl;
            cout << "======================================" << endl;
            cout << "\n[Press ENTER to enter the Arena...]" << endl;
            cin.ignore();
            cin.get();
}

