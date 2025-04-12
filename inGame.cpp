#include "elden.h"

//GLOBAL VARIABELS FOR THIS FILE LUL
int place;
tarnished player;
enemies enemy;

std::array <bool, 5> estus;
int enemy_actual_typeOfAttack = 1; 
bool actual_parry; 
int times_SpecialEffectFromEnemy_Bloody = 0; 
bool SpecialEffectFromEnemy_Bloody = false; 

//FUNCTION THAT STARTS THE GAME
void game() {
    std::string nameCharacter;
    char enter;
    system("cls");

    player.assign_HP(50);
    player.assign_strength(1);
    player.assign_dexterity(1);
    player.assign_arcane(1);

    std::cout<<"You've already lost, yes...welcome to FromSoftware\n";
    std::cout<<"...You've been found by someone, but you fall asleep.\n\n";

    system("pause");
    system("cls");

    std::cout<<"You wake up in a dark room. Two rooms after you find and kill a knight.\n\n";
    
    system("pause");
    system("cls");

    std::cout<<"You find and open a door, you see a beautiful landscape...There is a beautiful forest ahead and you\n";
    std::cout<<"run in direction of it\n\n";
    std::cout<<"You forget your name and try to remember which it is\n";

    while(true) {
        std::cin.clear();
        std::cin.ignore();

        if(!(getline(std::cin, nameCharacter))) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        } 
        else {

            if(nameCharacter == "") {
                continue; 
            } 
            else {
                break; 
            }
        }
    }

    places::place1_siofra(nameCharacter);

}


// FUNCTION WHICH CONTAINS THE FIRST PLACE OF THE GAME
void places::place1_siofra(std::string nameCharacter) {

    while(true) {
        player.assign_name(nameCharacter);  
        player.take_soldier_sword();
        player.reset_HP(50);

        displayOutGame::diplay_tarnished_stats();

        std::cout<<"You speedrun half of the game...now "<<player.readName()<<" is at Siofra River and has this weapon...\n";
        std::cout<<player.readWeapon_name()<<"\n\n";
        
        system("pause");

        displayOutGame::diplay_tarnished_stats();

        std::cout<<"You continue to walk, you can't yet understand how is it possible to see a sky full of stars in underground\n";
        std::cout<<"While you are trying to give an explaination, remembering the words of Ranni, two magic albinaurs attacks you\n";
        std::cout<<"The fight is on\n\n";

        system("pause");
        // I CREATED MAGIC ALBINAUR ENEMY OBJECT BUT THIS WILL NOT BE THE ONE USING IN THE FIGHT FUNCTIONS, BECAUSE THEY
        // MUST BE GENERAL, SO I WILL ASSIGN TO A GENERAL ENEMY OBJECT HIS STATS, CHANGING THEM FOR ANOTHER FIGHT AND SO ENEMY
        enemies magicAlbinaur; 
        magicAlbinaur.assignName("Magic Albinaur");
        magicAlbinaur.assignHp(150);
        magicAlbinaur.assignBasicAttack(50, "AxeSlash");
        magicAlbinaur.assignSpecialAttack(30, "BlueDust");

        // GENERAL DYNAMIC ENEY OBJECT FOR ALL THE FIGHTS, IN THIS CASE I ASSIGN THE STATS OF MAGIC ALBINAUR
        enemy.assignName(magicAlbinaur.readName());
        enemy.assignHp(magicAlbinaur.readHp());
        enemy.assignBasicAttack(magicAlbinaur.readBasicAttack_damage(), magicAlbinaur.readBasicAttack_name());
        enemy.assignSpecialAttack(magicAlbinaur.readSpecialAttack_damage(), magicAlbinaur.readSpecialAttack_name());

        // RESETTING ESTUS
        for(int i = 0 ; i < 5 ; i++ ) {
            estus[i] = true; 
        }  

        // I WANT FOR THIS FIGHT THAT THE PLAYER ONLY HAS 3 ESTUS WHICH CAN HEAL HIM 
        estus[4] = false; 
        estus[3] = false; 

        // CALLING THE FIGHT FUNCTION TO START THE COMBAT
        fight();

        // CHECKING IF THE PLAYER LOST
        if(player.readHP() == 0) {
            displayOutGame::diplay_tarnished_stats(); 
            displayOutGame::display_enemy_stats(); 

            std::cout<<"/\\/\\/\\YOU DIED/\\/\\/\\\n\n";

            system("pause"); 

            continue; 
        }

        while(true) {

            displayOutGame::diplay_tarnished_stats(); 

            std::cout<<"You continue to explore the place, it looks so unreal to you\n\n";

            system("pause"); 
            
            displayOutGame::diplay_tarnished_stats(); 

            std::cout<<"You see a mercant but you don't want to spend your earned souls\nAfter some time you finally find a falo\n\n";

            system("pause"); 

            falo1_siofra_beforeMohg(); 

            displayOutGame::diplay_tarnished_stats(); 

            std::cout<<"You leave the falo. You continue to walk and see a castle. You recognize it and as the legends say that's\n"; 
            std::cout<<"the Mohgwin palace. You explore it and after walking between boiled blood and scary enemies, you arrive\n";
            std::cout<<"to the finale boss'door\n\n";

            system("pause"); 

            std::cout<<"\nYou are afraid to continue, but you must fight the robber of the Miquella's body. You enter and engage the\n";
            std::cout<<"Blood Lord\n\n"; 

            system("pause"); 

            bosses LordOfBlood; 

            LordOfBlood.assignName("Mohgwin");
            LordOfBlood.assignHp(300);
            // both cause bleeding, an effect i writed in the fight which allowes to THE TARNISHED TO LOSE SOME DAMAGE
            // FOR THE NEXT THREE TURNS AS AN EFFECT OF THE PREVIOUS HIT
            LordOfBlood.assignBasicAttack(75, "BloodySlash");
            LordOfBlood.assignSpecialAttack(40, "BloodyTempest");

            enemy.assignName(LordOfBlood.readName());
            enemy.assignHp(LordOfBlood.readHp());
            enemy.assignBasicAttack(LordOfBlood.readBasicAttack_damage(), LordOfBlood.readBasicAttack_name());
            enemy.assignSpecialAttack(LordOfBlood.readSpecialAttack_damage(), LordOfBlood.readSpecialAttack_name());

            fight(); 

            if(player.readHP() == 0) {
                displayOutGame::diplay_tarnished_stats(); 
                displayOutGame::display_enemy_stats(); 

                std::cout<<"/\\/\\/\\YOU DIED/\\/\\/\\\n\n";

                system("pause"); 

                continue; 
            }

            displayOutGame::diplay_tarnished_stats(); 

            std::cout<<"Mohg is dead...you now can stop for a moment to see the miquella body, it's half dead half alive";

            // FINISHING OF THE FIRST PLACE, I LEAVE THE PROJECT HALF DONE CUZ IT WOULD REQUIRE TOO MUCH SCRIPTING AND TOO
            // MANY SITUATIONS THAT WOULD HAVE REQUIRED TOO MUCH TIME. I WILL DEFINITELY REMAKE THIS GAME WITH AN 
            // APPROPIATE ENGINE LIKE UNITY, BUT BASIC C++ AND A TERMINAL ISN'T ENOUGH TO GIVE ME ENOUGH SATISFACTION AFTER
            // ALL THE HOURS I SHOULD HAVE THINKED AND PROGRAMMED THIS GAME. I WILL GO MUCH IN DEPTH WITH C++, THEN I WILL
            // PROBABLY LEARN C SHARP TO MAKE A UNITY GAME OR IN ALTERNATIVES I WILL START LEARNING A BIT OF CYBERSECURITY

        }

    }

}


// FALO FUNCTION 
void places::falo1_siofra_beforeMohg() {
    int choice; 

    while(true) {

        // RESETTING ESTUS
        for(int i = 0 ; i < 5 ; i++ ) {
            estus[i] = true; 
        }       

        // RESETTING HP
        player.assign_HP(10000); 
        displayOutGame::diplay_tarnished_stats(); 
        displayOutGame::display_falo_menu(); 

        if (!(std::cin>>choice)) {

            std::cin.clear(); 
            std::cin.ignore(); 
            continue;

        }

        else if (choice == 1) {

            improve_stats_atfalo(); 

        } 

        else if (choice == 3) {

            break; 

        }
    }
}


void improve_stats_atfalo() {

    while(true) {
        int choice; 

        displayOutGame::diplay_tarnished_stats(); 

        std::cout<<"STATS\n\nNEEDED SOULS: "<<player.readNeededsouls()<<"\n\n"; 

        std::cout<<"1. STRENGTH: "<<player.readStrength()<<"\n";
        std::cout<<"2. DEXTERITY: "<<player.readDexterity()<<"\n"; 
        std::cout<<"3. ARCANE: "<<player.readArcane()<<"\n";
        std::cout<<"4. VITALITY: "<<player.readHP()<<"\n\n";
        std::cout<<"5. EXIT\n\n: ";

        if(!(std::cin>>choice)) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        } 

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {

            // I HAVE TWO OTHER OBJECT VARIABELS, NEEDEDSOULS AND CONTSTATS OR SMTHNG, BASED ON SECOND SO HOW MANY TIMES 
            // I IMPROVE THE STATS OF MY PG, THE NEEDED SOULS WILL CHANGE AND WILL HAVE A GREATER VALUE  
            if (player.readSouls() > player.readNeededsouls()) {

                player.assign_souls(-(player.readNeededsouls())); 
                player.increase_FaloImpCont(); 
                player.assign_neededsouls(player.readNeededsouls() + (100 * player.readFaloImpCont() ) ); 

            } 
            else {
                std::cout<<"\nYou don't have enough souls\n\n";

                system("pause"); 

                break; 
            }

            if (choice == 1) {
                player.assign_strength(1); 
                std::cout<<"\n\nYou improved strength!\n\n"; 
                system("pause");
                break; 
            } 

            else if (choice == 2) {
                player.assign_dexterity(1); 
                std::cout<<"\n\nYou improved dexterity!\n\n"; 
                system("pause"); 
                break; 
            }

            else if (choice == 3) {
                player.assign_arcane(1); 
                std::cout<<"\n\nYou improved arcane!\n\n"; 
                system("pause"); 
                break; 
            }

            else {
                player.reset_HP(player.readHP() + 20);
            }

        }

        else if (choice == 5) {

            break;

        }

    }
}


// FIGTH MODE FUNCTION
// FIGHT TURN 1 WILL BE THE TARNISHED ATTACKING, FIGHT TURN 2 WILL BE THE ENEMY ATTACKING, THE FIGHT TURN 2 ALSO HAS 
// THE TARNISHED DEFENSE FUNCTION, WHICH GIVES 3 WAYS FOR THE PLAYER TO DEFEND
void fight() {

    while(true) {

        if(SpecialEffectFromEnemy_Bloody) {

            if(times_SpecialEffectFromEnemy_Bloody < 3) {
                displayOutGame::diplay_tarnished_stats(); 
                displayOutGame::display_enemy_stats(); 

                std::cout<<"\nThe bloody effect still occours\n\n"; 
                player.diminuish_HP(4); 
                times_SpecialEffectFromEnemy_Bloody++; 

                system("pause"); 
            }
            else {
                SpecialEffectFromEnemy_Bloody = false; 
            }

        }
        
        fight_turn1();

        if(enemy.readHp() == 0) {
            tarnished_wins();
            break;
        }

        fight_turn2();

        // I DIDNT CREATE ANOTHER FUNCTION LIKE TARNISHED_LOST() BECAUSE I WOULDNT HAVE THE CAPABILITY OF RESTARTING 
        // FROM PLACE 1 FUNCTION, I JUST BREAK THE FIGHT FUNCTION AND CHECK THE CONDITION OF LOST AFTER, IN PLACE 1 FUNC.
        if(player.readHP() == 0) {
            player.erase_souls();
            break; 
        }

    }
}


void tarnished_wins() { 
    displayOutGame::diplay_tarnished_stats(); 
    std::cout<<"___/\\_YOU WON_/\\___\n\n"; 

    if(enemy.readName() == "Magic Albinaur") {

        std::cout<<"You obtain 1000 souls\n\n\n"; 
        player.assign_souls(1000); 
        system("pause"); 
    }

    if(enemy.readName() == "Mohgwin") {

        std::cout<<"You obtain 5000 souls aftear defeting Mohgwin\n\n\n"; 
        player.assign_souls(5000); 
        system("pause"); 
    }

    // OTHER ENEMIES
    
}


// FIGHT TURN 1 
void fight_turn1() {
    bool exit = false;
    int att_or_cure; 
    int another; 
    bool *estus_p = &estus[0]; 

    while(true) {
        // THIS IF IS A WAY TO EXIT THE FIGHT TURN 2 IF THE PLAYER HEALS, I DIDNT FIND ANY OTHER WAY
        if(exit == true) {
            break; 
        }
        exit = false; 
        displayOutGame::diplay_tarnished_stats();
        displayOutGame::display_enemy_stats();

        std::cout<<"1. Attack\n2. Estus\n\n: ";

        if(!(std::cin>>att_or_cure)) {
            std::cin.clear();
            std::cin.ignore();
            continue; 
        }

        // THE PLAYER ATTACKS
        if(att_or_cure == 1) {
            tarnished_attack();
            break;
        }

        // THE PLAYER HEALS
        else if(att_or_cure == 2) {

            while(true) {

                if(exit == true) {
                    break; 
                }

                if(check_estus(estus_p) == true ) {
                    player.assign_HP(20);
                } 
                else {
                    std::cout<<"\nNo Estus remained\n\n"; 

                    system("pause"); 
                    exit = true; 
                    continue; 
                }

                while(true) {
                    std::cout<<"\nAnother?\n1.Yes\n2.No\n: ";
                    if(!(std::cin>>another)) {
                        std::cin.clear();
                        std::cin.ignore();
                        continue; 
                    }
                    else if(another == 1) {
                        break; 
                    }
                    else if(another == 2) {
                        exit = true; 
                        break; 
                    }
                }
            }
        }
    }
}


// HEALING TURN 1 PLAYER 
// FOR THE HEALING I USED A POINTER SYSTEM, WHICH POINT IN THE ESTUS ARRAY A "TRUE" VARIABLE, IF THERE IT IS, THAT MEMBER IN
// THE ARRAY WILL BECOME FALSE, BECAUSE THE PLAYER TAKE IT, AND THE PLAYER WILL HEAL HP BASED ON HOW MANY ESTUS HE TAKES
bool check_estus(bool *array_first_element_pointer) {

    for(int i = 0; i<5; i++) {

        if(*(array_first_element_pointer + i) == true) {

            *(array_first_element_pointer + i) = false;
            return true;
        }
    }
    return false;
}


// ATTACKING TURN 1 PLAYER
void tarnished_attack() {
    int choice;

    while(true) {
        displayOutGame::diplay_tarnished_stats();
        displayOutGame::display_enemy_stats();
        
        std::cout<<"1. BASIC ATTACK\n2. SPECIAL ATTACK\n";

        if(actual_parry == true) {
            std::cout<<"3. PARRY COUNTER\n\n: "; 
        } 
        else {
            std::cout<<"\n: ";
        }


        if(!(std::cin>>choice)) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }


        // I WILL DISCERN THE CASE FOR THIS WEAPON BECAUSE IT DOESNT HAVE SPECIAL ATTACKS
        if(player.readWeapon_name() == "Soldier Sword") {

            if(choice == 2) {
                std::cout<<"\n\nThis weapon doesn't have special attacks\n\n";
                system("pause");  
                continue; 
            }
        } 

        if (choice == 1) {
            tarnished_basicAttack();
            break; 
        }
        else if (choice == 2) {
            //tarnished special attack
        }
        
        // ALL OTHER TARNISHED WEAPONS

        // PREVIOUS SUCCESSFUL PARRY CASE
        if(choice == 3) {

                if(actual_parry == true) {
                    std::cout<<"\n\n"<<player.readName()<<" counters the "<<enemy.readName()<<"\n\n"; 
                    enemy.diminuishHp(player.readBasicDamage() + 10); 
                    system("pause"); 
                    break; 
                }
                else {
                    continue; 
                }
            }

    }
}


// BASIC ATTACKS TARNISHED TURN 1
void tarnished_basicAttack() {
    displayOutGame::diplay_tarnished_stats();
    displayOutGame::display_enemy_stats();

    // IF IN THE PREVIOUS TURN 2, THE ENEMY ATTACKS WITH A SPECIAL ABILITY, EACH ENEMY HAS OWN, THE ATTACK COULD BE 
    // INFLUENCED BASED ON WHICH ENEMY THE PLAYER IS FIGHTING 
    if(enemy.readName() == "Magic Albinaur") {
        if(enemy_actual_typeOfAttack == 1 ) {
            std::cout<<player.readName()<<" use "<<player.readBasicAttack_name(); 
            enemy.diminuishHp(player.readBasicDamage()); 
        }
        else if (enemy_actual_typeOfAttack == 2) {

            if((rand() % 2 + 1) == 1) {
                std::cout<<"Despite the magic dust "<<player.readName()<<" succeed in hitting the "<<enemy.readName(); 
                enemy.diminuishHp(player.readBasicDamage()); 
            } 
            else {
                std::cout<<"Because of the magic dust "<<player.readName()<<" doesn't hit well the "<<enemy.readName(); 
                enemy.diminuishHp(player.readBasicDamage() / 2); 
            }
        }
    }

    if(enemy.readName() == "Mohgwin") {
        std::cout<<player.readName()<<" use "<<player.readBasicAttack_name(); 
        enemy.diminuishHp(player.readBasicDamage()); 

        
    }

    std::cout<<"\n\n";
    system("pause"); 
}


// ENEMIES ATTACKING FIGHT TURN 2   
// I INVENTED A MINI MICRO IA, FOR THE ENEMY, THE NORMAL ATTACK USUALLY CAUSES MORE DAMAGE BUT IT DOESNT HAVE SPECIAL
// EFFECT, SO IF THE HP OF THE PLAYER ARE LESS THAN THE BASIC DAMAGE OF THE ENEMY, IT JUST USE BASIC DAMAGE, PURE EVIL
void fight_turn2() { 
    actual_parry = false;

    if(player.readHP() < enemy.readBasicAttack_damage()) {
        enemy_actual_typeOfAttack = 1;
    } 
    else {
        enemy_actual_typeOfAttack = rand() % 2 + 1; 
    }

    // AFTER THE ENEMY CHOOSE THE ATTACK, THE BIGGEST PART IS THE PLAYER DEFENSE, HE CAN DODGE, PARRY OR BLOCK
    // I USED A BOOL ARRAY WITH 3 ELEMENTS, EACH MEANS DODGE, PARRY OR BLOCK. IF ONE IS TRUE, IT MEANS THE PLAYER
    // SUCCESS IN DEFENSE, OTHERWISE NOT. I USED A POINTER TO POINT THE ARRAY AND MODIFY THE VALUE OF THE ARRAY IN 
    // THE NEXT FUNCTION, BUT IN THIS ONE (FUNCTION) IT IS WRITTEN WHAT TO DO FOR ALL THE OUTCOMES. 
    std::array <bool, 3> results_array; 
    bool *result = &results_array[0];

    // IN THE TARNISHED DEFENSE FUNCTION WILL BE MODIFIED THE ARRAY ELEMENTS VALUE THANKS TO DODGE, PARRY AND BLOCK FUNCTIONS
    // BUT THE TARNISHED DEFENSE FUNCTION WILL RETURN 1,2 OR 3, TO MAKE THIS FUNCTION UNDERSTAND WHICH TYPE OF DEFENSE
    // THE PLAYER HAS CHOSEN: 1 DODGE   2 PARRY   3 BLOCK
    int choice = tarnished_defense(result);

    if(choice == 1) {

        if(enemy.readName() == "Magic Albinaur") {

            if(enemy_actual_typeOfAttack == 1) {

                if(*result == true) {
                    std::cout<<"\n"<<player.readName()<<" dodged"; 
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" tried to dodge but failed"; 
                    player.diminuish_HP(enemy.readBasicAttack_damage());
                }
            } 

            else if(enemy_actual_typeOfAttack == 2) {

                if(*result == true) {
                    std::cout<<"\n"<<player.readName()<<" dodged"; 
                }
                else {
                    std::cout<<"\n"<<player.readName()<<" tried to dodge but failed"; 
                    player.diminuish_HP(enemy.readSpecialAttack_damage());
                }
            }     
        }

        if(enemy.readName() == "Mohgwin") {
            if(enemy_actual_typeOfAttack == 1) {

                if(*result == true) {
                    std::cout<<"\n"<<player.readName()<<" dodged"; 
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" tried to dodge but failed"; 
                    player.diminuish_HP(enemy.readBasicAttack_damage());
                    SpecialEffectFromEnemy_Bloody = true; 
                    times_SpecialEffectFromEnemy_Bloody = 0;
                }
            } 

            else if(enemy_actual_typeOfAttack == 2) {
                std::cout<<player.readName()<<" can't dodge the bloody tempest"; 
                player.diminuish_HP(enemy.readSpecialAttack_damage()); 
                SpecialEffectFromEnemy_Bloody = true; 
                times_SpecialEffectFromEnemy_Bloody = 0;
            }
        }
    }

    if(choice == 2) {
        // YOU COULD WANT TO CHANGE CODE BASED ON THE ENEMY, LINKED TO BOOL PARRY FUNCTION

        if(enemy.readName() == "Magic Albinaur") {

            if(enemy_actual_typeOfAttack == 1) {

                if(*(result+1) == true) {
                    actual_parry = true;
                    std::cout<<"\n"<<player.readName()<<" has parried AxeSlash"; 
                }
                else {
                    std::cout<<"\n"<<"wrong timing, it caught "<<player.readName(); 
                    player.diminuish_HP(enemy.readBasicAttack_damage());
                }
            } 

            if(enemy_actual_typeOfAttack == 2) {
                if(*(result+1) == true) {
                    actual_parry = true;
                    std::cout<<"\n"<<"BlueDust has flied away";
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" tried to parry but failed"; 
                    player.diminuish_HP(enemy.readSpecialAttack_damage());
                }
            }     
        } 

        if(enemy.readName() == "Mohgwin") {

            if(enemy_actual_typeOfAttack == 1) {
                if(*(result+1) == true) {
                    actual_parry = true;
                    std::cout<<"\n"<<player.readName()<<" has parried BloodySlash"; 
                }

                else {
                    std::cout<<"\n"<<"wrong timing, it caught "<<player.readName(); 
                    player.diminuish_HP(enemy.readBasicAttack_damage());
                    SpecialEffectFromEnemy_Bloody = true; 
                    times_SpecialEffectFromEnemy_Bloody = 0; 
                }
            }
            
            else if(enemy_actual_typeOfAttack == 2) {
                if(*(result+1) == true) {
                    actual_parry = true;
                    std::cout<<"\n"<<"Blood gets destroyed by your shield";
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" tried to parry but failed"; 
                    player.diminuish_HP(enemy.readSpecialAttack_damage());
                    SpecialEffectFromEnemy_Bloody = true; 
                    times_SpecialEffectFromEnemy_Bloody = 0;
                }
            }

        }
    }

    if(choice == 3) {

        if(enemy.readName() == "Magic Albinaur" || enemy.readName() == "Mohgwin") {
                
            if(enemy_actual_typeOfAttack == 1) {

                if(*(result+2) == false) {
                    std::cout<<"\n"<<player.readName()<<" didn't block in time"; 
                    player.diminuish_HP(enemy.readBasicAttack_damage());
                    if (enemy.readName() == "Mohgwin") {
                        SpecialEffectFromEnemy_Bloody = true; 
                        times_SpecialEffectFromEnemy_Bloody = 0;
                    }
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" blocked but still received damage"; 
                    player.diminuish_HP(enemy.readBasicAttack_damage() / 2); 
                }
            } 

            else if(enemy_actual_typeOfAttack == 2) {

                if(*(result+2) == false) {
                    std::cout<<"\n"<<player.readName()<<" didn't block in time"; 
                    player.diminuish_HP(enemy.readSpecialAttack_damage()); 
                    if (enemy.readName() == "Mohgwin") {
                        SpecialEffectFromEnemy_Bloody = true; 
                        times_SpecialEffectFromEnemy_Bloody = 0;
                    }
                } 
                else {
                    std::cout<<"\n"<<player.readName()<<" blocked a bit, but he shouldn't with this type of attacks";
                    player.diminuish_HP(enemy.readSpecialAttack_damage() / 1.2);  
                    if (enemy.readName() == "Mohgwin") {
                        SpecialEffectFromEnemy_Bloody = true; 
                        times_SpecialEffectFromEnemy_Bloody = 0;
                    }
                }
            }
        }

    }

    std::cout<<"\n\n"; 
    system("pause");
}
    

// TARNISHED DEFENSE FUNCTION, I PASSED AS AN ARGUMENT THE POINTER TO MODIFY THE ARRAY
int tarnished_defense (bool *results) {
    int choice; 
    
    while(1) {
        displayOutGame::diplay_tarnished_stats();
        displayOutGame::display_enemy_stats();

        if(enemy_actual_typeOfAttack == 1) {
            std::cout<<"The "<<enemy.readName()<<" used the "<<enemy.readBasicAttack_name()<<"\n\n";
        } 
        else if (enemy_actual_typeOfAttack == 2) {
            std::cout<<"The "<<enemy.readName()<<" used the "<<enemy.readSpecialAttack_name()<<"\n\n";
        }

        std::cout<<"1. ROLL\n2. PARRY\n3. BLOCK\n\n: ";

        if(!(std::cin>>choice)) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        // THIS FUNCTIONS WILL RETURN TRUE OR FALSE, BASED ON THE TYPE OF DEFENSE, IT WILL BE MODIFIED THAT ELEMENT OF THE
        // ARRAY, THE FIRST ONE FOR THE DODGE (I JUST WROTE *RESULTS BECAUSE THE POINTER POINT TO THE FIRST ELEMENTS),
        // THE SECOND ONE FOR THE PARRY (RESULTS + 1 SO THE POINTER POINT THE NEXT MEMORY CELL, WHICH CONTAINS THE NEXT
        // ELEMENT OF THE ARRAY) AND THE THIRD
        if(choice == 1) {
            *results = dodge();
            break;  
        }
        else if(choice == 2) {
            *(results+1) = parry();
            break;
        }
        else if(choice == 3) {
            *(results+2) = block();
            break; 
        } 
    }
    return choice; 
}


bool dodge() {
    int choice; 
    int enemy_attack_direction; 

    while(1) {
        displayOutGame::diplay_tarnished_stats();
        displayOutGame::display_enemy_stats();

        std::cout<<"           1. Ahead        \n"; 
        std::cout<<"2. Left                3. Right\n";
        std::cout<<"           4. Behind      \n\n: ";

        if(!(std::cin>>choice) || choice>4 || choice<1) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        // I DISTINGUISH ENEMY CASES TO CHANGE THE POSSIBLE "CHANCES" AND CIRCUMSTANCES OF DODGING THAT PARTICULAR ATTACK

        if(enemy.readName() == "Magic Albinaur") {

            if(enemy_actual_typeOfAttack == 1) {
                enemy_attack_direction = rand() % 4 + 1;
            } 
            else if(enemy_actual_typeOfAttack == 2) {
                enemy_attack_direction = rand() % 2 + 1;
            }
        }

        // OTHER ENEMIES

        // IF THEY ARE EQUAL, THE ATTACK CAUGHT ME
        if(choice == enemy_attack_direction) {
            return false; 
        } else {
            return true; 
        }

    }
}

// I TRIED TO MAKE AN INPUT WITHIN A TIME, LIKE IF I PUT THE NUMBER 3 WITHIN 0.2 SECONDS AFTER A SIGNAL I WOULD HAVE PARRIED
// OTHERWISE NOT BUT I DIDNT UNDERSTAND HOW TO DO IT, SO WITH CTIME LIBRARY I JUST MADE A NUMBER BEING WRITTEN FOR VERY 
// LITTLE TIME ALL OF SUDDEN AND YOU MUST WRITE THAT SAME NUMBER AFTER, IF YOU HAVE SEEN IT AND GUESS RIGHT, YOU WILL PARRY
// OTHERWISE NOT, AN INPUT ERROR IS CONSIDERED A FAILED PARRY

bool parry() {
    // YOU COULD WANT TO CHANGE THE PARRY BASED ON THE ENEMY
    int timer; 
    int parrynumber = rand() % 10 + 1; 
    int player_parrynumber; 
    int i = rand() % 3 + 1; 

    std::cout<<"\n\nEnemy attacks...\n\n"; 

    displayOutGame::diplay_tarnished_stats();
    displayOutGame::display_enemy_stats();

    timer = clock(); 

    while(i<5) {
        if(clock() > (timer + 150)) {
            timer = clock(); 
            i++; 
        }
    }
    std::cout<<"SLASH    "<<parrynumber; 

    i = 0; 
    timer = clock();
    while(i<3) {
        if(clock() > (timer + 1)) {
            timer = clock(); 
            i++; 
        }
    }
    
    displayOutGame::diplay_tarnished_stats();
    displayOutGame::display_enemy_stats();

    std::cout<<"\nPARRY TIMING: "; 

    if(!(std::cin>>player_parrynumber)) {
        std::cin.clear();
        std::cin.ignore();
        return false; 
    }

    if(parrynumber == player_parrynumber){
        return true; 
    } else {
        return false;
    }
}
    
// BLOCKING IS EASY, SO MOST OF THE TIME IT WILL BLOCK
bool block() {
    int esit = rand() % 6 + 1;

    if( esit == 6) {
        return true; 
    } else {
        return false; 
    }
    
}
















//DISPLAY STATS 
void displayOutGame::diplay_tarnished_stats() {
    system("cls");

    std::cout<<"TARNISHED | HP: "<<player.readHP()<<"\t"<<player.readBasicAttack_name()<<": "<<player.readBasicDamage();
    std::cout<<"\tStrength: "<<player.readStrength()<<"\tDexterity: "<<player.readDexterity()<<
    "\tArcane: "<<player.readArcane()<<"\tSOULS: "<<player.readSouls()<<"\n";

    std::cout<<"__________________________________________________________________________________________\n\n";

}

void displayOutGame::display_enemy_stats() {
    std::cout<<enemy.readName()<<" | HP: "<<enemy.readHp()<<"    "<<enemy.readBasicAttack_name()<<": "<<enemy.readBasicAttack_damage();
    std::cout<<"    "<<enemy.readSpecialAttack_name()<<": "<<enemy.readSpecialAttack_damage(); 

    // ATT THE DESCRIPTION OF THE EFFECT OF THE SPECIAL ABILITY OF THE ENEMY OF THE GAME

    std::cout<<"\n__________________________________________________________________________________________\n\n";

}

void displayOutGame::display_falo_menu() {
    std::cout<<"|    1. INCREASE STATS    \n|    2.\n|    3. EXIT\n\n: "; 
}


















