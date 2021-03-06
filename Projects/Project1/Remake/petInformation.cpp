#include "petInformation.hpp"
#include "mainMenu.hpp"

// Function Definitions

#include <iostream>
#include <string>

using namespace std;

// Initialize variables
string petName;
int percentHunger = 0, percentHappiness = 100, percentHealth = 100;
bool quit = false;
int petChoice;

// Prompt for pet type
void getPetType() {
	

	cout << endl << "   ^ ^   " << endl << "=( o.o )= \t 1. Cat" << endl << endl;
	cout << endl << "   U U   " << endl << "  (o.o)   \t 2. Bunny" << endl << endl;
	cout << endl << "   A A   " << endl << "  (. .)    \t 3. Fox\n" << "    U   " << endl << endl;

	cout << "Choose your pet: ";
	cin >> petChoice;

	drawPetType(petChoice);
	setPetChoice(petChoice);
	 
}

// Set petChoice
void setPetChoice(int petChoice) {
	switch (petChoice) {
	case 1:
		cout << "You chose CAT\n\n";
		break;
	case 2:
		cout << "You chose BUNNY\n\n";
		break;
	case 3:
		cout << "You chose FOX\n\n";
		break;
	default:
		while (true) {
			exit(1); 
		}
		
	}
}

// Prompt for pet name
void getPetName() {

	cout << "What do you want to name your pet? \t";
	cin >> petName;
}

// cout pet stats
void showPetStats() {
	drawPetType(petChoice); 
	
	cout << "\nName: \t \t" << petName << endl;

	cout << "Hunger: \t" << percentHunger << "%" << endl;
	cout << "Happiness: \t" << percentHappiness << "%" << endl;
	cout << "Health: \t" << percentHealth << "%" << endl << endl;

}

// Return hunger to mainMenu.cpp
int getPercentHunger() {

	return percentHunger;
}

// Prompt user choice
int promptUserChoice(int min, int max) {
	int choice;

	cout << "1. Feed \t 2. Play \t 3. Heal \t 4. Quit" << endl;

	cout << "Enter your selection: \t ";
	cin >> choice;

	while (choice < min || choice > max) {
		cout << "Invalid choice, try again: \t";
		cin >> choice;
	}
	return choice;
}

// Do some action based on choice
void doCommand(int choice) {
	switch (choice) {
	case 1:
		percentHunger = percentHunger - 10;
		break;
	case 2:
		percentHappiness = percentHappiness + 10;
		break;
	case 3:
		percentHealth = percentHealth + 10;
		break;
	case 4:
		quit = true;
		getQuitStatus();
		break;
	}

	makeStatChanges();
	keepWithinBounds();
}

// Return quit to mainMenu.cpp
bool getQuitStatus() {
	return quit;
}

// Stat changes during each loop
void makeStatChanges() {
	percentHunger = percentHunger + 5;
	percentHappiness = percentHappiness - 5;
	percentHealth = percentHealth - 5;
}

// Keep health, happiness, and hunger within bounds 0% - 100%
void keepWithinBounds() {

	if (percentHealth < 0) {
		percentHealth = 0;
	}
	else if (percentHealth > 100) {
		percentHealth = 100;
	}

	if (percentHappiness < 0) {
		percentHappiness = 0;
	}
	else if (percentHappiness > 100) {
		percentHappiness = 100;
	}

	if (percentHunger < 0) {
		percentHunger = 0;
	}
	else if (percentHunger == 100 || percentHunger > 100) {
		percentHunger = 100;
	}
}

// Displays pet type based on petChoice
void drawPetType(int petChoice) {
	if (petChoice == 1) {
		cout << endl << "   ^ ^   " << endl << "=( o.o )= " << endl << endl;
	}
	else if (petChoice == 2) {
		cout << endl << "   U U   " << endl << "  (o.o)   " << endl << endl;
	}
	else if (petChoice == 3) {
		cout << endl << "   A A   " << endl << "  (. .)    " << endl << "    U   " << endl << endl;
	}
}
