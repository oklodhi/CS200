#include <iostream>
#include <string>
using namespace std;

void Program1()
{
	cout << "COUNTING UP! \n";
	int n = 0;
	while (n <= 20) {
		cout << n << " ";
		n++;
	}
}

void Program2()
{
	cout << "COUNTING UP! \n"; 
	int n = 1; 
	while (n <= 128) {
		cout << n << " "; 
		n = n * 2; 
	}
}

void Program3()
{
	int secretNumber = 13;
	int playerGuess;

	cout << "NUMBER GUESSER \n";
	do {
		cout << "Guess a number: \t";
		cin >> playerGuess;

		if (playerGuess < secretNumber) {
			cout << "Too low! \n";
		}
		else if (playerGuess > secretNumber) {
			cout << "Too high! \n";
		}
		else {
			cout << "That's right \n \n";
		}
	} while (playerGuess != secretNumber);

	cout << "GAME OVER";
}

void Program4()
{
	int num;
	cout << "Please enter a number between 0 and 5: \t";

	cin >> num;

	while (num <= -1 || num >= 6) {
		cout << "Invalid entry, try again: ";
		cin >> num;
	}

	cout << "Thank you.";
}

void Program5()
{
	float startingWage, percentRaisePerYear, adjustedWage;
	int yearsWorked,
		yearCounter = 1;

	cout << "What is your starting wage? \t \t";
	cin >> startingWage;

	adjustedWage = startingWage;

	cout << "What % raise do you get per year? \t";
	cin >> percentRaisePerYear;

	cout << "How many years have you worked there? \t";
	cin >> yearsWorked;
	cout << endl;

	cout << "Salary at year " << yearCounter << ": \t" << startingWage << endl;

	while (yearCounter != yearsWorked) {
		adjustedWage = (adjustedWage * percentRaisePerYear / 100) + adjustedWage;

		cout << "Salary at year " << yearCounter + 1 << ": \t" << adjustedWage << endl;

		yearCounter++;
	}
}

void Program6()
{
	int n, sum = 0, counter = 1;

	cout << "CALCULATE A SUM \n \n" << "Enter a value for n: ";
	cin >> n;
	cout << endl;

	while (counter <= n) {
		sum = counter + sum;

		cout << "Sum: " << sum << endl;
		counter++;
	}
}

int main()
{
	// Don't modify main
	while (true)
	{
		cout << "Run which program? (1-6): ";
		int choice;
		cin >> choice;

		cout << endl << endl;

		if (choice == 1) { Program1(); }
		else if (choice == 2) { Program2(); }
		else if (choice == 3) { Program3(); }
		else if (choice == 4) { Program4(); }
		else if (choice == 5) { Program5(); }
		else if (choice == 6) { Program6(); }

		cout << endl << "------------------------------------" << endl;
	}

	return 0;
}
