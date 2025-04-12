#include "elden.h"


// MENU FUNCTION
void menu() {

    int choice;

    while(true) {

        displayOutGame::display_menu();

        if(!(std::cin>>choice)) {
            std::cin.clear();
            std::cin.ignore();
            continue; 
        }

        if(choice == 1) {
            startGame();
        }
        if(choice == 2) {
            howtoplay();
        }
        if(choice == 3) {
            exit(0);
        }   
    }
}


//START GAME FUNCTION
void startGame() {
    system("cls");
    int choice; 

    while(true) {

        displayOutGame::display_start_game();
        if(!(std::cin>>choice)) {
            std::cin.clear();
            std::cin.ignore();
            system("cls");
            continue; 
        }

        if(choice == 1) {
            game();
        }  
        if(choice == 2) {
            break;
        }
        
    }
}

// HOW TO PLAY FUNCTION
void howtoplay() {
    std::cout<<"\nThere are two phases: exploration and fighting\n";
    std::cout<<"In the exploration it will just appear some text and you can make some choises\n"; 
    std::cout<<"While in the fighting you fight an enemy or the boss of the place. The fighting has: \n\n"; 
    std::cout<<"The turn where the player can heal or attack the enemy\n"; 
    std::cout<<"The turn where the enemy attacks the player, during this turn the player can defend with three moves\n\n"; 
    std::cout<<"Dodging, it will appear some directions and the player chose the one where he wants to dodge"; 
    std::cout<<"Parring, it will appear a message followed by a number, this number will appear for a very short time, so\n";
    std::cout<<"pay attention, if you succeed in seeing the number, you write that number and the parry is successful,\n"; 
    std::cout<<"otherwise you fail the parry\n"; 
    std::cout<<"Blocking, is the less risky but that can't avoid all the damage from the enemy\n\n";
    std::cout<<"There is a restore place called the falo: \n";
    std::cout<<"All your estus, the object which you use to heal, will be repristinated\n"; 
    std::cout<<"You can use the won souls to improve the stats of Strength, Dexterity, Arcane\n"; 
    std::cout<<"Strength improve basic damage, Dexterity improve the luck of dodging and blocking, Arcane improve bloody stats\n\n";

    system("pause");   
}



// DISPLAY FUNCTIONS FROM DISPLAY OUT GAME CLASS

void displayOutGame::display_menu() {
    system("cls"); 

    std::cout<<" ____________________________\n";
    std::cout<<"|                            |\n";
    std::cout<<"| 1. Start New Game          |\n";
    std::cout<<"| 2. How to play             |\n";
    std::cout<<"| 3. Exit                    |\n";
    std::cout<<"|____________________________|\n";
    std::cout<<"\n";
    std::cout<<": ";
}

void displayOutGame::display_start_game() {

    std::cout<<"In the Lands Between there are 2 types of people, who has the grace of the Elden Tree, and who lost the grace\n,"; 
    std::cout<<"also called Tarnisheds. The division started when the Ring was shuttered, the prince Godrick killed in the mind\n";
    std::cout<<"and Ranni The Witch killed in the body. All of these happened during the knifes'night and Now, Tarnished,\n";
    std::cout<<"you are called in the lands between from the Elden Tree to repair the Elden Ring."; 

    std::cout<<"\nTarnished...Are you ready?\n1. Yes\n2. No\n\n: ";
}







