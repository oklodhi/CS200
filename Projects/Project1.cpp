#include <iostream>
#include <string>
using namespace std; 

int main() {

	// Initialize and declare all variables
	int percentHunger = 0, percentHappiness = 100, percentHealth = 100, userChoice;
	string petName;
	bool quit = false;

	// Prompt user input for pet name and store to petName
	cout << "What do you want to name your pet? \t";
	cin >> petName;


	// Loop game as long as quit = false
	while (quit != true) {
		// Main menu cout2
		cout << endl << "   ^ ^   " << endl << "=( o.o )=" << endl << endl;
		cout << "Name: \t \t" << petName << endl;
		cout << "Hunger: \t" << percentHunger << "%" << endl;
		cout << "Happiness: \t" << percentHappiness << "%" << endl;
		cout << "Health: \t" << percentHealth << "%" << endl << endl;

		// Game over if: hunger = 100%, else: keep running program
		if (percentHunger == 100) {
			quit = true;
			cout << "\nYour pet has been taken away from you! \n" << "Game over" << endl;

			int a;
			cin >> a;
			return 0; 
		}
		else {
			// User input options cout
			cout << "1. Feed \t 2. Play \t 3. Heal \t 4. Quit" << endl;

			// Prompt user selection and store to userChoice
			cout << "Enter your selection: \t ";
			cin >> userChoice;

			// If invalid selection
			while (userChoice < 1 || userChoice > 4) {
				cout << "Invalid choice, try again: \t";
				cin >> userChoice;
			}

			// Based on user choice... do the following
			switch (userChoice) {
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
				break;
			}

			// Stat changes during each loop
			percentHunger = percentHunger + 5;
			percentHappiness = percentHappiness - 5;
			percentHealth = percentHealth - 5;

			// Keep health, happiness, and hunger within bounds 0% - 100% 
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
	}
}
