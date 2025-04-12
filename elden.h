#pragma once 
#include <iostream> 
#include <vector> 
#include <string> 
#include <array>
#include <fstream> 
#include <array> 
#include <windows.h>
#include <cmath>
#include <ctime> 

void menu();
void startGame();
void howtoplay();
void game();
void fight();
void fight_turn1();
void fight_turn2();
bool check_estus(bool*);
void tarnished_attack();
void tarnished_basicAttack(); 
int tarnished_defense(bool*); 
bool dodge();
bool parry();
bool block();
void tarnished_wins(); 
void improve_stats_atfalo(); 

// DISPLAY OUT GAME CLASS 
class displayOutGame {

    public: 

    static void display_menu();
    static void diplay_tarnished_stats();
    static void display_enemy_stats();
    static void display_start_game();
    static void display_falo_menu(); 
};

class places {

    public: 
    static void place1_siofra(std::string name);
    static void falo1_siofra_beforeMohg(); 

};

class tarnished {
    int souls; 
    int neededsouls = 1000; // FOR IMPROVING STATS
    int faloImprovementCont = 0; // TO DECIDE THE NEEDED SOULS

    std::string name;
    int HP;
    int strength;
    int arcane;
    int dexterity;

    std::string specialStats;
    std::string weapon_name; 
    int specialDamage;
    int basicDamage; 
    std::string basicAttack_name;
    std::string specialAttack_name;


    public: 
    // NAME
    void assign_name(std::string);
    std::string readName();

    // WEAPONS STATS 
    std::string readWeapon_name();
    int readBasicDamage();
    int readSpecialDamage();
    void assign_specialDamage();
    void assign_basicDamage();

    // HP AND SOULS
    int readHP();
    void reset_HP(int); 
    void assign_HP(int);
    void diminuish_HP(int); 

    int readSouls(); 
    int readNeededsouls(); 
    int readFaloImpCont(); 
    void assign_souls(int); 
    void erase_souls();
    void assign_neededsouls(int);
    void increase_FaloImpCont();  

    

    // STATS
    int readStrength();
    void assign_strength(int);
    int readArcane();
    void assign_arcane(int);
    int readDexterity();
    void assign_dexterity(int);

    // ASSIGNMENT OF WEAPONS
    void take_soldier_sword(); 
    void take_magic_sword();
    void take_bloody_blades();
    void take_light_sword();
    void take_poisoned_knifes();
    void take_fire_spikedBalls();


    // ATTACKS AND DEFENSES
    void assign_basicAttack_name(std::string); 
    std::string readBasicAttack_name(); 


};


class enemies {

    int HP; 

    std::string name; 
    std::string basicAttack_name; 
    std::string specialAttack_name; 

    int basicAttack_damage; 
    int specialAttack_damage; 

    public: 

    // HP
    int readHp();
    void assignHp(int);
    void diminuishHp(int); 

    // NAME
    void assignName(std::string);
    std::string readName();

    // ATTACKS
    int readBasicAttack_damage();
    int readSpecialAttack_damage(); 
    std::string readBasicAttack_name();
    std::string readSpecialAttack_name();

    
    void assignBasicAttack(int, std::string);
    void assignSpecialAttack(int, std::string); 

};


class bosses: public enemies {

    std::string LordName; 

    public: 

}; 



