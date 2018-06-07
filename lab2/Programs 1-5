#include <iostream>   // Use cin and cout
#include <string>     // Use strings
using namespace std;

void Program1()
{
	string homeTown; 
	string name; 

	cout << "Enter the name of your home town?\n";
	cin >> homeTown; 

	int townSize = homeTown.size();

	if (townSize > 6) {
		cout << "That's a long name!\n"; 
	}

	cout << "Enter your name: "; 
	cin >> name; 

	cout << "Hello, " << name << " from " << homeTown << endl; 
}

void Program2()
{
	float userPoints, totalPoints, grade; 
	cout << "How many points does the assignment have? \t"; 
	cin >> totalPoints; 
	cout << "How many points did you get? \t \t \t"; 
	cin >> userPoints; 

	grade = userPoints / totalPoints;

	cout << "Score: \t \t \t \t \t \t" << grade << endl; 

	if (grade > .69) {
		cout << "You passed!" << endl; 
	}
	else {
		cout << "You failed!" << endl; 
	}
}

void Program3()
{
	int charge; 

	cout << "How much charge is left on your phone? \t"; 
	cin >> charge; 

	if (charge > 74 && charge < 101) {
		cout << "[****]"; 
	} else if (charge > 49 && charge < 75) {
		cout << "[*** ]";
	} else if (charge > 24 && charge < 51) {
		cout << "[** ]";
	} else if (charge > 4 && charge < 25) {
		cout << "[* ]";
	} else {
		cout << "[ ]";
	}
}

void Program4()
{
	int choice; 

	cout << "What is your favorite type of book? \n"; 
	cout << "1. Scifi \n" << "2. Historical \n" << "3. Fantasy \n" << "4. DIY \n \n"; 
	cout << "Your selection: "; 
	cin >> choice; 

	if (choice >= 1 && choice <= 4) {
		cout << "Good choice!"; 
	}
	else {
		cout << "Invalid choice!"; 
	}
}

void Program5()
{
	float num1, num2, newNum; 

	cout << "Enter two numbers, separated by a space: "; 
	cin >> num1 >> num2; 

	cout << "Which type of operation? \n"; 

	int choice; 
	cout << "1. Add \t" << "2. Subtract \t" << "3. Multiply \t" << "4. Divide" << endl; 

	cout << "Choice: "; 
	cin >> choice;

	switch (choice) {
		case 1: 
			newNum = num1 + num2;
			cout << num1 << " + " << num2 << " = " << newNum; 
			break; 
		case 2: 
			newNum = num1 - num2;
			cout << num1 << " - " << num2 << " = " << newNum;
			break; 
		case 3: 
			newNum = num1 * num2;
			cout << num1 << " * " << num2 << " = " << newNum;
			break; 
		case 4: 
			newNum = num1 / num2;
			cout << num1 << " / " << num2 << " = " << newNum;
			break; 
	}
	

}

int main()
{
	// Don't modify main
	while (true)
	{
		cout << "Run which program? (1-5): ";
		int choice;
		cin >> choice;

		cout << endl << endl;

		if (choice == 1) { Program1(); }
		else if (choice == 2) { Program2(); }
		else if (choice == 3) { Program3(); }
		else if (choice == 4) { Program4(); }
		else if (choice == 5) { Program5(); }

		cout << endl << "------------------------------------" << endl;
	}

	return 0;
}
