#include "Character.h"

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

vector <string> HeroNames =
{
    "Calyra","Hoopslash","Nairos","Warchef",
    "Hammerstorm","Nightshift","Electra Gale",
    "Felina","Aurelia","Dzirabelle","Codexa","Fablea"
};

vector <string> EnemyNames =
{
    "Delta Sphinx","Harpy-X","Anubis-Void","Zeus-Cracked",
    "Hydra-13","The Broken Minotaur","Medusa","Cerberus-Voidspawn",
    "Chimera-Blight","Typhon-Radialis"
};

void character :: HeroLore()
{
    ifstream Lore ("Lore.txt");
    string line;

    if(!Lore.is_open())
    {
        cout<<"Cannot open Lore now!"<<endl;
        return;
    }

    while(getline(Lore,line))
        cout<<line<<endl;
    
    Lore.close();
    cout<<"[Press ENTER to go back]"<<endl;
    cin.ignore();
    cin.get();
}

void character :: EnemyLore()
{
    ifstream BossLore("Bosses.txt");
    string line;

    if(!BossLore.is_open())
    {
        cout<<"Cannot open Enemy Lore now!"<<endl;
        return;
    }

    while(getline(BossLore,line))
        cout<<line<<endl;

    BossLore.close();
    cout<<"[Press ENTER to go back]"<<endl;
    cin.ignore();
    cin.get();
}