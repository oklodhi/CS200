#include <iostream>
#include <string>

using namespace std; 

int main() {
	int myInt = 10; 
	double myDoub = 123.45; 
	string myStr = "World Cup 2018"; 

	cout << "NAME \t ADDRESS \t SIZE \t VALUE \n"; 
	cout << "myInt \t " << &myInt << "\t" << sizeof(myInt) << "\t " << myInt << endl; 
	cout << "myDoub \t " << &myDoub << "\t" << sizeof(myDoub) << "\t " << myDoub << endl;
	cout << "myStr \t " << &myStr << "\t" << sizeof(myStr) << "\t " << myStr << endl;

	cin.ignore();
}