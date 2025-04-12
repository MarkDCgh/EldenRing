#include "elden.h"

int maxlevel_HP = 100; 


// CLASS TARNISHED...ASSIGN AND READ NAME

void tarnished::assign_name(std::string name) {
    this -> name = name;
}

std::string tarnished::readName() {
    return name;
}

// CLASS TARNISHED...WEAPONS ACQUISITION FUNCTIONS
void tarnished::take_soldier_sword() {
    weapon_name = "Soldier Sword";
    basicDamage = 15 + strength*2; 
    specialDamage = 0 ;
    basicAttack_name = "Basicco slaaassho";
    specialAttack_name = "";
}




// CLASS TARNISHED...READ FUNCTIONS

std::string tarnished::readWeapon_name() {
    return weapon_name;
}

std::string tarnished::readBasicAttack_name() {
    return basicAttack_name;
}

int tarnished::readBasicDamage() {
    return basicDamage;
}

int tarnished::readHP() {
    return HP;
}

int tarnished::readSouls() {
    return souls; 
}

int tarnished::readNeededsouls() {
    return neededsouls; 
}

int tarnished::readFaloImpCont() {
    return faloImprovementCont; 
}

int tarnished::readStrength() {
    return strength;
}

int tarnished::readDexterity() {
    return dexterity;
}

int tarnished::readArcane() {
    return arcane;
}


// CLASS TARNISHED...ASSIGN FUNCTIONS

void tarnished::assign_HP(int number) {
    HP += number;
    if(HP>maxlevel_HP) {
        HP = maxlevel_HP; 
    }
}

void tarnished::reset_HP(int number) {
    HP = number; 
}

void tarnished::diminuish_HP(int number) {
    HP -= number; 
    if(HP < 0) {
        HP = 0;
    }
}

void tarnished::assign_souls(int number) {
    souls += number; 
}

void tarnished::erase_souls() {
    souls = 0; 
}

void tarnished::assign_neededsouls(int number) {
    neededsouls += number; 
}

void tarnished::increase_FaloImpCont() {
    faloImprovementCont++; 
}

void tarnished::assign_strength(int number) {
    strength += number; 
    basicDamage = 30 + strength*2;

    //max level case
}

void tarnished::assign_dexterity(int number) {
    dexterity += number; 
    //max level case
}

void tarnished::assign_arcane(int number) {
    arcane += number;
    //max level case
}

void tarnished::assign_basicAttack_name(std::string name) {
    basicAttack_name = name; 
}



// CLASS TARNISHED ATTACK FUNCTIONS




// ADD HOW THESE AFFECT THE DAMAGE OR THE SPECIAL DAMAGE



