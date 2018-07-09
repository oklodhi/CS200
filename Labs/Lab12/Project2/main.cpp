#include <iostream>

using namespace std; 

#include "fraction.hpp"

int main() {
	fraction frac1, frac2, fracResult;
	int n, d, choice; 

	cout << "FRACTION PROGRAM \n\n"; 
	cout << "\t Fraction 1 \n\t\t Enter numerator: \t";
	cin >> n; 
	cout << "\t Fraction 1 \n\t\t Enter denominator: \t";
	cin >> d;
	frac1.setup(n, d); 

	cout << "\n\t Fraction 2 \n\t\t Enter numerator: \t";
	cin >> n;
	cout << "\t Fraction 2 \n\t\t Enter denominator: \t";
	cin >> d;
	frac2.setup(n, d);

	cout << "1. Add \t 2. Subtract \t 3. Multiply \t 4. Divide \t 5. Quit" << endl;
	cin >> choice; 

	if (choice == 1) {
		frac1.display();
		cout << " plus ";
		frac2.display();
		cout << " is ";

		fracResult = frac1.add(&frac2); // passing in address to 2nd fraction
		fracResult.display();
	}
	else if (choice == 2) {
		frac1.display();
		cout << " minus ";
		frac2.display();
		cout << " is ";

		fracResult = frac1.subtract(&frac2); // passing in address to 2nd fraction
		fracResult.display();
	}
	else if (choice == 3) {
		frac1.display();
		cout << " multiplied by ";
		frac2.display();
		cout << " is ";

		fracResult = frac1.multiply(&frac2); // passing in address to 2nd fraction
		fracResult.display();
	}
	else if (choice == 4) {
		frac1.display();
		cout << " divided by ";
		frac2.display();
		cout << " is ";

		fracResult = frac1.divide(&frac2); // passing in address to 2nd fraction
		fracResult.display();
	}
	else if (choice == 5) {
		return 0; 
	}
	else {
		cout << "Invalid choice. Try again: "; 
		cin >> choice; 
	}

	cin.ignore();
	cin.get(); 
}