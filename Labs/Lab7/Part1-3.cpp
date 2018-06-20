#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Program1()
{
	const int MAX_CLASSES = 5;

	string classes[MAX_CLASSES];

	int studentClassCount = 0;

	for (int i = 0; i < 6; i++) {
		string userInput;

		cout << "Enter class " << i + 1 << " or type STOP:\t";
		cin >> userInput;

		if (userInput == "STOP") {
			break;
		}
		else {
			classes[i] = userInput;
			studentClassCount++;
		}
	}

	cout << "\n\nYour classes: \n";
	for (int i = 0; i < studentClassCount; i++)
	{
		cout << classes[i] << "\t";
	}
}

void Program2()
{
	const int totalItems = 5;

	float price[totalItems];
	string name[totalItems];

	cout << "\nSTOREFRONT \n\n";

	for (int i = 0; i < totalItems; i++) {
		cout << "ITEM " << i + 1 << endl;
		cout << "\t Enter the item's name: \t";
		cin.ignore();
		getline(cin, name[i]);
		cout << "\t Enter the item's price: \t$";
		cin >> price[i];
	}

	ofstream stream("SaleItems.txt");
	if (!stream.is_open()) {
		cout << "Cannot open file \n";
	}
	else {
		stream << "ITEMS FOR SALE \n\n";
		for (int i = 0; i < totalItems; i++) {
			stream << i + 1 << ". " << name[i] << "\t\t\t\t$" << price[i] << endl;
		}
		stream.close();
	}
}

void Program3()
{
	string todo[7][24];
	int todoItemCount = 0, choice, dayOfWeek, timeOfDay; 
	string fileName; 

	bool quit = false; 

	while (!quit) {
		cout << "\nTO DO LIST \n\n";
		cout << "1. Add new to-do item \n" << "2. Save list \n" << "3. Quit" << endl << endl; 
		cin >> choice; 

		if (choice == 1) {
			cout << "\n0. Sunday \t 1. Monday \t 2. Tuesday \t 3. Wednesday \n4. Thursday \t 5. Friday \t 6. Saturday \n\n"; 

			cout << "which day of the week? (0 to 6): \t"; 
			cin >> dayOfWeek;
			cout << "\nWhat time of day? (0 to 23): \t\t";
			cin >> timeOfDay;
			cout << "\nWhat is the to do item? \t\t";
			cin.ignore(); 
			getline(cin, todo[dayOfWeek][timeOfDay]); 
		}
		else if (choice == 2) {
			cout << "Enter a name for your file (in camelCase): \t";
			cin >> fileName; 

			fileName = fileName + ".txt"; 

			ofstream strTxtFile(fileName);

			if (!strTxtFile.is_open()) {
				cout << "Cannot open file \n";
			}
			else {
				strTxtFile << "TO DO LIST \n\n";
				for (int day = 0; day < 7; day++) {
					if (day == 0) {
						strTxtFile << "\nSunday\n";
					} else if (day == 1) {
						strTxtFile << "\nMonday\n";
					} else if (day == 2) {
						strTxtFile << "\nTuesday\n";
					} else if (day == 3) {
						strTxtFile << "\nWednesday\n";
					} else if (day == 4) {
						strTxtFile << "\nThursday\n";
					} else if (day == 5) {
						strTxtFile << "\nFriday\n";
					} else {
						strTxtFile << "\nSaturday\n";
					}
					for (int hour = 0; hour < 24; hour++) {

						strTxtFile << hour << ":00 \t" <<todo[day][hour] << endl; 
					}
				}
				strTxtFile.close();
			}
		}
		else if (choice == 3) {
			quit = true; 
			break;
		}
		else {
			cout << "Invalid option! \n\n";
			break; 
		}
	}
}

int main()
{
	bool done = false;

	while (!done)
	{
		int choice;
		cout << "0. QUIT" << endl;
		cout << "1. Program 1" << endl;
		cout << "2. Program 2" << endl;
		cout << "3. Program 3" << endl;
		cout << endl << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 0: done = true; break;
		case 1: Program1(); break;
		case 2: Program2(); break;
		case 3: Program3(); break;
		}
	}

	return 0;
}