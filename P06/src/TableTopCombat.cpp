#include "Player.hpp"
#include "Monster.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

void menu(){
    //Prints the menu
    cout << "1. Add Monster\n" << "2. Load Monsters from CSV\n" 
         << "3. Begin Combat\n" << "4. Exit\n" << ">>";
}

int main() {
    //Map Declaration
    unordered_map<string, Monster> monsters;

    // Variable
    int choice = 0;
    string filename,
           mon1,
           mon2;

    while(choice != 4){
        menu();
        cin >> choice;
    
        if(choice == 1){
            cout << "Create Your Character!\n";

            //variables
            Monster temp = Monster();
            string name,
                   dmg;
            int level,
                hp,
                ac,
                speed,
                str,
                dex,
                con,
                intu,
                wis,
                cha,
                hit;

            cout << "Got any good ideas? ... Good\nLet's name the monster\n>>";
            cin >> name;

            cout << "Brilliant!\nNow what level is " << name << "\n>>";
            cin >> level;

            cout << "Alright, 2/13ths of the way done!\nNow time to determine the HP!\n>>";
            cin >> hp;

            cout << "Next up is AC!\n>>";
            cin >> ac;

            cout << "Tortois or Hare?\nDoes slow and steady win the race?\nYou choose, what's the SPEED for this thing\n>>";
            cin >> speed;

            cout << "Almost there! Keep Answering!\nDoes this monster hit the gym?\nLet's see those gains.\nWhat is the STRENGTH\n>>";
            cin >> str;

            cout << "Dang this is a lot of info!\nI can only be funny for so long!\nNext up DEXTERITY\n>>";
            cin >> dex;

            cout << "What does the bill fo rights have to do with monsters?\nOh not that type of consitiution?\nOopse, next up CONSTIUTION\n>>";
            cin >> con;

            cout << "Does " << name << " identify as a bimbo/himbo or an intellectual?\nWhat is the INTELLIGENCE\n>>";
            cin >> intu;
        
            cout << "They say wisdom is in the eyes!\nNext up WISDOM\n>>";
            cin >> wis;
        
            cout << "A regular smooth talker or word fumbler?\nChoose that CHARISMA\n>>";
            cin >> cha;

            cout << "Almost there! Just Two more to go!\nNext is HITBONUS\n>>";
            cin >> hit;

            cout << "Okay this one is more complex!\nBe sure to follow directions for Damage (#d# + #)\n>>";
            cin.ignore();
            getline(cin, dmg);

            ofstream add("NewMonster.csv");

            add << name << "," << level << "," << hp << "," << ac << "," << speed << "," 
                << str << "," << dex << "," << con << "," << intu << "," << wis << "," << cha << "," << hit << "," << dmg << "\n";

            add.close();

            ifstream save("NewMonster.csv");

            for (string line; getline(save, line); ) {
                Monster temp = Monster();
                temp.loadFromCSV(line);

                monsters.emplace(temp.name(), temp);            
            }
            add.close();

            remove("NewMonster.csv");

            cout << "\nMonster List:\n";
            for ( auto it = monsters.begin(); it != monsters.end(); ++it ){
                cout << endl << it->first << ": " << it->second;
            }
            cout << endl;
        }

        if(choice == 2) {
            cout << "Enter a Filename: ";
            cin >> filename;

            ifstream file(filename);

            if(file.is_open()){
                int i = 0;
                cout << "Loading\n";

                for (string line; getline(file, line); ) {
                    if (i == 0) {
                        i++;
                        continue;
                    }

                    Monster temp = Monster();
                    temp.loadFromCSV(line);

                    monsters.emplace(temp.name(), temp);            
                }
                file.close();
            } else {
                cout << "File Unknown! Get it together and try again! :)\n";
            }
        }
        
        if(choice == 3){   
            int check = 0;
            Monster a,
                    b;

            cout << endl;
            for ( auto it = monsters.begin(); it != monsters.end(); ++it ){
                cout << it->first << ": " << it->second;
            }
            cout << endl;       

            bool clear = false;
            while(!clear){

                cout << "Select Monster 1> ";
                cin.ignore();
                getline(cin, mon1);

                try {
                    auto result = monsters.at(mon1);
                    cout << result << endl;

                    a = result;
                    clear = true;
                } catch(out_of_range& e) {
                    cout << "Try again Bestie!" << endl;
                }
            }

            for ( auto it = monsters.begin(); it != monsters.end(); ++it ){
                cout << it->first << ": " << it->second;
            }
            cout << endl;

            clear = false;
            while(!clear){
                cout << "Select Monster 2> ";
                getline(cin, mon2);

                try {
                    auto result = monsters.at(mon2);
                    cout << result << endl;

                    b = result;
                    clear = true;
                } catch(out_of_range& e) {
                    cout << "Try again Bestie!" << endl;
                }

                if(mon2 == mon1){
                    clear = false;
                    cout << "You cannot pick the same monster twice!\n" 
                         << "No monster wants to fight themself.\n";
                }
            }
            
            cout << "Great! Good choices! Lets begin!\n";
                
            cout << a.name() << " has " << a.hp() << " hp\n";
            cout << b.name() << " has " << b.hp() << " hp\n\n";

            cout << "FIGHT\n";

            while(check == 0){
                if(a.hp() > 0){
                    int hold = a.attack(b);
                    b.hp() -= hold;

                    if(b.hp() > 0){
                        int hold2 = b.attack(a);
                        a.hp() -= hold2;
                    } else {
                        check++;
                        cout << "\n" << a.name() << " is the winner!\n\n";
                    }
                } else {
                    check++;
                    cout << "\n" << b.name() << " is the winner!\n\n";
                }
            }              
        }

        if(choice == 4){
            cout << "Have a holly jolly Christmas! \nxoxo, \nGossip Girl\n";
        }
    }
    return 0;
}