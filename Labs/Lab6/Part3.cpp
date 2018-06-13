#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main() {
	ifstream input; 
	input.open("story.txt");

	string line; 

	if (input.fail()) {
		cout << "Could not open file!" << endl; 
		return 1; 
	}
	else {
		while (getline(input, line)) {
			cout << line << endl; 
		}
		cin.ignore(); 
		cin.get(); 
		input.close(); 
	}
}
