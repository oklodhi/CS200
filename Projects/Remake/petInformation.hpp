#ifndef _PET_INFORMATION_HPP
#define _PET_INFORMATION_HPP

#include <string>

// Function declarations

using namespace std; 

void getPetType();

void setPetChoice(int petChoice); 

void getPetName();

void showPetStats(); 

int getPercentHunger(); 

int promptUserChoice(int min, int max);

void doCommand(int choice); 

bool getQuitStatus();

void makeStatChanges();

void keepWithinBounds(); 

#endif 
