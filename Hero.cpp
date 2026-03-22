#include "Hero.h"

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

HERO::HERO() 
{
    HP = 0; 
    name = ""; 
    position = ""; 
    SuperPower = false; 
    SuperCounter = 0;
}

void HERO::ChooseYourCharacter()
{
                cout << "+==============================+" << endl;
                cout << "|       CHOOSE YOUR HERO       |" << endl;
                cout << "+==============================+" << endl;
                cout <<" "<< endl;
                cout << " "<< endl;
                cout << ">> 1.  Calyra        (Mage)" << endl;
                cout << ">> 2.  Hoopslash     (Rogue)" << endl;
                cout << ">> 3.  Nairos        (Mage)" << endl;
                cout << ">> 4.  Warchef       (Warrior)" << endl;
                cout << ">> 5.  Hammerstorm   (Warrior)" << endl;
                cout << ">> 6.  Nightshift    (Rogue)" << endl;
                cout << ">> 7.  Electra Gale  (Warrior)" << endl;
                cout << ">> 8.  Felina        (Mage)" << endl;
                cout << ">> 9.  Aurelia       (Mage)" << endl;
                cout << ">> 10. Dzirabelle     (Rogue)" << endl;
                cout << ">> 11. Codexa        (Rogue)" << endl;
                cout << ">> 12. Fablea        (Warrior)" << endl;
                cout <<" "<< endl;
                cout << ">> Enter the number of your choice: ";

                int choice;
                cin>>choice;
                int index = choice-1;

                if(index >= 0 && index < 12)
                {
                    this -> name = HeroNames[index];

                    if( index==0 || index==2 || index==7 || index==8)
                    {
                        this -> position = "Mage";
                        this -> HP = 75;

                        if(index==0)
                        {
                            Attacks.push_back({"Vital Surge",10,80,0});
                            Attacks.push_back({"Pulse Injection",10,80,0});
                            Attacks.push_back({"Syringe Barrage",15,50,3});
                        }
                        else if(index==2)
                        {
                            Attacks.push_back({"Liquid Blade",10,80,0});
                            Attacks.push_back({"Cresting Wave",10,80,0});
                            Attacks.push_back({"Rainfall Strike",15,50,3});
                        }
                        else if(index==7)
                        {
                            Attacks.push_back({"Feline Strike",10,80,0});
                            Attacks.push_back({"Purr Pulse",10,50,0});
                            Attacks.push_back({"Cataclysm Charm",15,50,3});
                        }
                        else if(index==8)
                        {
                            Attacks.push_back({"Pure light",10,80,0});
                            Attacks.push_back({"Light Radiation",10,80,0});
                            Attacks.push_back({"Aurora borealis",15,50,3});
                        }
                    }
                    else if( index==1 || index==5 || index==9 || index==10)
                    {
                        this -> position = "Rogue";
                        this -> HP = 100;

                        if(index==1)
                        {
                            Attacks.push_back({"Slam Dunk",8,75,0});
                            Attacks.push_back({"Fast Break",8,75,0});
                            Attacks.push_back({"Crossover Strike",13,45,3});
                        }
                        else if(index==5)
                        {
                            Attacks.push_back({"Teleportation",8,75,0});
                            Attacks.push_back({"Invisibility",8,75,0});
                            Attacks.push_back({"Metamorphosis",13,45,3});
                        }
                        else if(index==9)
                        {
                            Attacks.push_back({"Toxin Dart",8,75,0});
                            Attacks.push_back({"Elixir Trap",8,75,0});
                            Attacks.push_back({"Pharma Strike",13,45,3});
                        }
                        else if(index==10)
                        {
                            Attacks.push_back({"Code Spike",8,75,0});
                            Attacks.push_back({"Logic Trap",8,75,0});
                            Attacks.push_back({"Algorithmic Strike",13,45,3});
                        }
                    }
                    else if(index==3 || index==4 || index==6 || index==11)
                    {
                        this -> position = "Warrior";
                        this -> HP = 125;

                        if(index==3)
                        {
                            Attacks.push_back({"Pan Smash",6,75,0});
                            Attacks.push_back({"Spice Bomb",6,75,0});
                            Attacks.push_back({"Aromatic Wave",10,45,3});
                        }
                        else if(index==4)
                        {
                            Attacks.push_back({"Hammering",6,75,0});
                            Attacks.push_back({"Hammer blow",6,75,0});
                            Attacks.push_back({"Lightning",10,45,3});
                        }
                        else if(index==6)
                        {
                            Attacks.push_back({"Electric shock",6,75,0});
                            Attacks.push_back({"Electric current",6,75,0});
                            Attacks.push_back({"Tornado",10,45,3});
                        }
                        else if(index==11)
                        {
                            Attacks.push_back({"Story Slam",6,75,0});
                            Attacks.push_back({"Cinematic Strike",6,75,0});
                            Attacks.push_back({"Cliffhanger",10,45,3});
                        }
                    }

                    cout << "\n======================================" << endl;
                    cout << "   HERO SELECTED: " << this->name << endl;
                    cout << "   CLASS:         " << this->position << endl;
                    cout << "   HEALTH POINTS: " << this->HP << " HP" << endl;
                    cout << "======================================" << endl;
                    cout << "\n[Press ENTER to enter the Arena...]" << endl;
                    cin.ignore();
                    cin.get();
                }

                else
                {
                    cout<<"Invalid number! Returning to Main Menu!"<<endl;
                }

}