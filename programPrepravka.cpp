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

class HERO;
class ENEMY;
class character;
class Battle;

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

struct Attack
{
    string name;
    int damage;
    int chance;
    int SuperRequired;
};

class Battle
{
    public:
        void StartFight(HERO &player, ENEMY &boss);
        void SuperPower(HERO &player);
        void HitAndDamage(HERO &player);
        void BossAttack(HERO &player, ENEMY &boss);
};


class character
{
    protected:
        double HP;
        string name;

    public:
        double damage;
        double MaxHP;
        bool SuperPower = false; // mogucnost koristenja super moci (svako treci udarac?)
        int SuperCounter = 0; // brojac koji broji kada se moze koristiti super moc
        vector <Attack> Attacks;

        void HeroLore();
        void EnemyLore();
        void LowerHP(double Damage){HP -= Damage;}

        double GetHP() {return HP;};
        string GetName(){return name;};
};

class HERO : public character
{
    private:
        string position;

    public:
        HERO(){HP=0; name=""; position=""; SuperPower=false; SuperCounter=0;};
        void ChooseYourCharacter()
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
};

class ENEMY : public character
{
    public:
        ENEMY(){HP=0; name=""; SuperPower=false; SuperCounter=0;};
        
        void GenerateBoss()
        {
            srand(time(0));

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
    MainMenu();
    return 0;
}