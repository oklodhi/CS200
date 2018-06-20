#include <iostream>

using namespace std;

int main() {

	bool arrayBool[4]; 
	int arrayInt[4]; 

	cout << "Bool size: " << sizeof(bool) << "\t\t Int size: " << sizeof(int) << endl; 

	cout << "Bool array size: " << sizeof(arrayBool) << "\t Int array size: " << sizeof(arrayInt) << endl; 

	cout << "\nBool array Addresses: \n";
	for (int i = 0; i < sizeof(arrayBool); i++) {
		cout << "\t Index " << i << ": \t " << &arrayBool[i] << endl; 
	}

	cout << "\nInt array Addresses: \n";
	for (int k = 0; k < 4; k++) {
		cout << "\t Index " << k << ": \t " << &arrayInt[k] << endl;
	}

	cout << "\nBool array address: " << &arrayBool << endl; 
	cout << "Int array address: " << &arrayInt << endl; 

	cin.ignore();
}