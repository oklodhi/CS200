#include <iostream>
#include <string>

using namespace std; 

class MyClass {
	public: 
		MyClass() {
			cout << "Constructor" << endl; 
		}

		MyClass(const string& value) {
			cout << "Constructor " << value << endl; 
		}

		~MyClass() {
			cout << "Destructor" << endl; 
		}
};


int main() {
	MyClass classA; 

	if (true) {
		MyClass classB("B!"); 
		MyClass classC; 
	}

	cin.ignore(); 
	cin.get(); 

	return 0;
}