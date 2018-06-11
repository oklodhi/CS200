#include <iostream>
#include <iomanip>
using namespace std;

void DisplayMenu()
{
	cout << "------------------------ \n" << "1. Add money \n" << "2. Subtract money \n" << "3. Quit \n" << endl;
}

void PrintPrice(float price)
{
	cout << "$" << setprecision(2) << price << endl;
	return;
}

int main()
{
	int choice, num1, num2;

	cout << "MONEY MATH";

	while (true)
	{
		// 1. Display the main menu
		DisplayMenu();

		// 2. Get the user's choice
		cin >> choice;

		// 3.   If choice is 1, get two float values and add them.
		//      Display the result with PrintPrice.

		// 4.   If choice is 2, get two float values and adsubtract them.
		//      Display the result with PrintPrice.

		// 5.   If choice is 3, use the break; command to stop the program.
		if (choice == 1) {
			cout << "Enter first amount: \t";
			cin >> num1;
			cout << "Enter second amount: \t";
			cin >> num2;

			int result = num1 + num2;

			PrintPrice(result);
		}
		else if (choice == 2) {
			cout << "Enter first amount: \t";
			cin >> num1;
			cout << "Enter second amount: \t";
			cin >> num2;

			int result = num1 - num2;

			PrintPrice(result);
		}
		else if (choice == 3) {
			cout << "Goodbye.";
			break;
		}

	}

	return 0;
}