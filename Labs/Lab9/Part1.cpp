#include <iostream>
#include <string>
using namespace std; 

int main() {
	int* myInt;
	string* myStr;
	float* myFloat;

	myInt = new int(20);
	myStr = new string("Muhammad Khan");
	myFloat = new float(199.9);

	cout << *myInt << "\t" << *myStr << "\t" << *myFloat;

	delete myInt; delete myStr; delete myFloat;

	cin.ignore();
	cin.get();

}