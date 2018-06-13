#include "petInformation.hpp"
#include "mainMenu.hpp"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

bool isQuitting; 

// Display main menu
int main() {
	
	// Initialize variables
	cout << "VIRTUAL PET GAME \n \n"; 

	// Get pet type and pet name
	getPetType(); 
	getPetName(); 
	
	// Loop game as long as quit == false
	while (isQuitting != true) {
		showPetStats();

		// If hunger == 100, quit game
		if (getPercentHunger() == 100) {
			isQuitting = true;
			cout << "\nYour pet has been taken away from you! \n" << "Game over" << endl;

			int a;
			cin >> a; 
		}
		else { // Else, continue

			// Prompt user choice
			int choice = promptUserChoice(1, 4);

			// Do some action based on choice3
			doCommand(choice);

			// Check when to quit
			isQuitting = getQuitStatus(); 
		}
	}
}
