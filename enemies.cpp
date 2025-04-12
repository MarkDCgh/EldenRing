#include "elden.h"


// ENEMIES CLASSSSSS

// ASSIGN STUFF 
void enemies::assignHp(int number) {
    HP = number; 
}

void enemies::diminuishHp(int number) {
    HP -= number; 
    if(HP < 0) {
        HP = 0;
    }
}

void enemies::assignName(std::string name) {
    this -> name = name;
} 

void enemies::assignBasicAttack(int number, std::string name) {
    basicAttack_damage = number;
    basicAttack_name = name; 
}

void enemies::assignSpecialAttack(int number, std::string name) {
    specialAttack_damage = number; 
    specialAttack_name = name; 
}


// READ STUFF
int enemies::readHp() {
    return HP;
}

std::string enemies::readName() {
    return name; 
}

int enemies::readBasicAttack_damage() {
    return basicAttack_damage; 
}

int enemies::readSpecialAttack_damage() {
    return specialAttack_damage; 
}

std::string enemies::readBasicAttack_name() {
    return basicAttack_name; 
}

std::string enemies::readSpecialAttack_name() {
    return specialAttack_name; 
}


