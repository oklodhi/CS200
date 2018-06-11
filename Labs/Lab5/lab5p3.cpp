#include <iostream>
#include <string>
using namespace std;

// Update this function
float CountChange(int quarterCount, int dimeCount, int nickelCount, int pennyCount)
{
	float totalQ = quarterCount * .25;
	float totalD = dimeCount * .10;
	float totalN = nickelCount * .05;
	float totalP = pennyCount * .01;

	float result = totalQ + totalD + totalN + totalP;

	return result;
}

int main()
{
	cout << "COUNT CHANGE" << endl;

	while (true)
	{
		int quarters, dimes, nickels, pennies;

		// 1. Get user input for the amount of each type of change
		cout << "How many quarters? \t";
		cin >> quarters;

		cout << "How many dimes? \t";
		cin >> dimes;

		cout << "How many nickels? \t";
		cin >> nickels;

		cout << "How many pennies? \t";
		cin >> pennies;
		// 2. Call the function and store the result
		float total = CountChange(quarters, dimes, nickels, pennies);

		// 3. Output the result
		cout << "\nYou have: $" << total << endl << endl;
	}
	return 0;
}