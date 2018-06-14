#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

string name, buffer; 
int level, money; 

int main() {
	cout << "SAVEGAME \n\n"; 

	ifstream input; 
	input.open("savegame.txt"); 

	if (input.fail()) {
		return 1; 
	}
	else {
		input >> buffer >> name; 
		input >> buffer >> level; 
		input >> buffer >> money; 
	}

	cout << "Name: \t" << name << endl << "Level: \t" << level << endl << "Money: \t" << money << endl << endl; 
	cout << "LEVELING UP \n" << "SAVING \n" << "CLOSING \n"; 

	level++; 
	money = money + 100; 

	ofstream output; 
	output.open("savegame.txt");

	output << "NAME \t" << name << endl;
	output << "LEVEL \t" << level << endl;
	output << "MONEY \t"<< money << endl;

	cin.ignore(); 
	cin.get(); 

	input.close(); 
}
