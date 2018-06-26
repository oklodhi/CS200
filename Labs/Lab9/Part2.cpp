#include <iostream>
#include <string>

using namespace std; 

int main() {
	int* myIntArr; 
	string* myStrArr; 
	float* myFloatArr; 

	int size; 

	cout << "Enter array size: \t\t"; 
	cin >> size; 

	myIntArr = new int[size]; 
	myStrArr = new string[size]; 
	myFloatArr = new float[size]; 

	for (int i = 0; i < size; i++) {
		cout << "\ni = " << i << endl; 

		cout << "\tEnter int value: \t"; 
		cin >> myIntArr[i]; 
		cout << "\tEnter string value: \t";
		cin >> myStrArr[i];
		cout << "\tEnter float value: \t";
		cin >> myFloatArr[i];

	}

	cout << "\nHere is your data: \n\n"; 
	cout << "int \tstring \tfloat \n\n"; 

	for (int y = 0; y < size; y++) {
		cout << myIntArr[y] << " \t" << myStrArr[y] << " \t" << myFloatArr[y] << endl; 
	}

	cin.ignore(); 
	cin.get(); 
}