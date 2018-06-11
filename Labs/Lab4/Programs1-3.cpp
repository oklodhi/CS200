#include <iostream>
#include <string>
using namespace std;

void Program1()
{
	cout << "COUNTING UP! \n";
	for (int n = 0; n <= 20; n++) {
		cout << n << " "; 
	}
}

void Program2()
{
	cout << "COUNTING UP! \n";
	for (int n = 1; n <= 128; n = n * 2) {
		cout << n  << " ";
	}
}

void Program3()
{
	int sum = 0;
	int i; 

	for (int n = 1; n <= 5; n++) {
		cout << "Enter number " << n << ": \t"; 
		cin >> i; 
		sum = sum + i; 
	}

	cout << "SUM is " << sum; 
}

void Program4()
{
}

void Program5()
{
}

void Program6()
{
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
