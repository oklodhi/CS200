#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std; 

void showMenu(); 
void castVote(); 
void writeToFile(); 
//void pollResults();

int choice;
int pizza = 0, samosas = 0, taco = 0, bibimbap = 0; 
bool quit = false; 
int main() { 
	while (quit != true) {
		showMenu(); 
		cin >> choice; 
		cout << endl; 

		castVote(); 
		writeToFile();
	}
	 
}

void showMenu() {
	cout << "VOTING \n" << "------------------- \n" << "Vote for a food item: \n";
	cout << "1. Pizza \n2. Samosas \n3. Tacos \n4. Bibimbap \n\n";
	cout << "Or quit the program with: \n5. Quit" << endl << endl;

	cout << "Choice: ";
}

void castVote() {
		switch (choice) {
		case 1:
			pizza++;
			break;
		case 2:
			samosas++;
			break;
		case 3:
			taco++;
			break;
		case 4:
			bibimbap++;
			break;
		case 5:
			quit = true;
			break;
		default:
			cout << "Invalid, try again: ";
			cin >> choice;
			break;
	} 
}

void writeToFile() {
	ofstream out_stream; 
	out_stream.open("VotingFile.txt"); 

	out_stream << "POLL RESULTS" << endl << endl; 

	out_stream << "1. Pizzas: \t" << pizza << endl;
	out_stream << "1. Samosas: \t" << samosas << endl;
	out_stream << "1. Tacos: \t" << taco << endl;
	out_stream << "1. Bibimbaps: \t" << bibimbap << endl;

}
