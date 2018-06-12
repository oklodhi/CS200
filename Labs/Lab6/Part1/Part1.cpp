#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Display two options: Add new to-do item, or quit.
void DisplayMainMenu()
{
	cout << "TO DO LIST \n \n" << "------------------- \n" << "1. New to-do item \n" << "2. Quit \n" << endl; 
}

// Get the user's input, validate whether it is between min and max,
// if the value is invalid, ask the user to input it again
// (using a while loop).
// Once the user's input is valid, return that value.
int GetChoice(int min, int max)
{
	int choice; 

	cin >> choice; 

	while (choice < min || choice > max) {
		cout << "Invalid value, try again." << endl; 
		cin >> choice; 
	}

	return choice;
}

// Get a line of text from the user using cin, and return this info.
string GetToDoItem()
{
	string item; 

	cout << "\nEnter a new to-do item: ";
	cin.ignore();
	getline(cin, item); 

	return item; 
}

int main()
{
	// 1. Create an ofstream object and open a text file.
	ofstream out_stream; 
	out_stream.open("TextFile.txt"); 

	// 2. Create an integer called counter, initialize it to 1.
	int counter = 1; 

	// 3. Create a boolean called done, initialize it to false.
	bool done = false; 

	// 4. While done is not true...
	//      4a. Display the main menu
	//      4b. Get the user's input via the GetChoice function,
	//          store it in a variable.
	//      4c. If choice is 1...
	//          * Get a to do item with the GetToDoItem function.
	//          * Write the counter # and the to do item to the
	//            output file.
	//          * Increment the counter.
	//      4d. If choice is 2...
	//          * Set done to true.
	while (!done) {
		DisplayMainMenu(); 
		int choice = GetChoice(1,2); 
		
		if (choice == 1) {
			out_stream << GetToDoItem() << endl;
			counter++; 
		}
		else {
			done = true; 
		}
	}

	// 5. Once the while loop is over, close the output file.

	return 0;
}
