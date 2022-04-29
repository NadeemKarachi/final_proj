#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "Dwarf.h"
#include "character.h"
#include "Human.h"
#include "game.h"
#include "Elf.h"

Dwarf createDwarf(bool isGenerated);
Elf createElf(bool isGenerated);
Human createHuman(bool isGenerated);

using namespace std;

int main() {
    Character vChar;
    Game vGame;

    string name, occupation, race, weapon;
    int stamina;
    int health;
    int level;
    string characChoice;
    int characterChoice, weaponChoice;
    string charName;

    cout << "******WELCOME TO THE FIGHTING REALM******" << endl;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;

    //Input Validation
    while (true) {
        cout << "1. Dwarf" << endl << "2. Human" << endl << "3. Elf" << endl;
        cin >> characterChoice;
        if (characterChoice > 3 || characterChoice < 1) {
            cout << "Invalid selection! Please Try Again" << endl;
            //Clears prev input if invalid
            cin.clear();
            cin.ignore(1000000, '\n');
        } else
            break;
    }

    if (characterChoice == 1) {
        Dwarf vDwarf = createDwarf(false);
        //Dwarf *d = new Dwarf(name, race, (level), (health), (stamina), weapon);
    } else if (characterChoice == 2) {
        Human vHum = createHuman(false);
        //Human *h = new Human(name, race, (level), (health), (stamina), weapon);
    } else if (characterChoice == 3) {
        Elf vElf = createElf(false);
    }
}

Dwarf createDwarf(bool isGenerated){
    Dwarf vDwarf;
    string charName;
    int weaponChoice;

    if (isGenerated)
        charName = "Enemy Dwarf";

    else {
        cout << "You have selected Dwarf!" << endl;
        cout << "GIVE A NAME TO THE DWARF!" << endl;
        cin >> charName;
    }

    vDwarf.SetName(charName);
    vDwarf.SetRace("Dwarf");
    vDwarf.SetHealth(100);
    vDwarf.SetLevel(80);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 4;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Axe" << endl << "3. Hammer" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vDwarf.SetWeapon("Sword");
            break;
        } else if (weaponChoice == 2) {
            vDwarf.SetWeapon("Axe");
            break;
        } else if (weaponChoice == 3) {
            vDwarf.SetWeapon("Hammer");
            break;
        } else {
            cout << "INVALID STATEMENT, Try again!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
    vDwarf.Print();
}

Human createHuman(bool isGenerated) {
    Human vHum;
    string charName;
    int weaponChoice;
    if (isGenerated)
        charName = "Enemy Human";
    else {
        cout << "You have selected Human!" << endl;
        cout << "NAME YOUR HUMAN!" << endl;
        cin >> charName;
    }
    vHum.SetName(charName);
    vHum.SetRace("Human");
    vHum.SetHealth(90);
    vHum.SetLevel(90);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 4;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Kyoketsu-Shoge" << endl << "3. Flail" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vHum.SetWeapon("Sword");
            break;
        } else if (weaponChoice == 2) {
            vHum.SetWeapon("Kyoketsu-Shoge");
            break;
        } else if (weaponChoice == 3) {
            vHum.SetWeapon("Flail");
            break;
        } else {
            cout << "No weapon has been selected!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
    vHum.Print();
}

Elf createElf(bool isGenerated){
    Elf vElf;
    string charName;
    int weaponChoice;
    if(isGenerated)
        charName = "Enemy Elf";
    else{
        cout << "You have selected Elf!" << endl;
        cout << "GIVE A NAME TO THE ELF!" << endl;
        cin >> charName;
    }
    vElf.SetName(charName);
    vElf.SetRace("Elf");
    vElf.SetHealth(95);
    vElf.SetLevel(85);
    while (true) {
        if(isGenerated)
            weaponChoice = rand() % 4;
        else{
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Bow&Arrow" << endl << "2. Sword" << endl << "3. Javelin" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vElf.SetWeapon("Bow&Arrow");
            break;
        } else if (weaponChoice == 2) {
            vElf.SetWeapon("Sword");
            break;
        } else if (weaponChoice == 3) {
            vElf.SetWeapon("Javelin");
            break;
        } else {
            cout << "No weapon has been selected!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
        vElf.setStrength(10);
    }

    vElf.Print();
}