#include <iostream>
#include <string>

using namespace std; 

class Student {
	private:
		string name, className[3]; 
	public: 
		void setName(const string& value) {
			name = value; 
		}

		void setClassName(int index, const string& value) {
			for (int i = 0; i < index; i++) {
				className[i] = value; 
			}
		}

		void displayInfo() {
			cout << name << "\t" << className; 
		}

};


int main() {
	Student bill, noah, karen; 
	bill.setName("Bill"); 
	noah.setName("Noah"); 
	karen.setName("Karen"); 

	bill.setClassName(1, "English");

	bill.displayInfo(); 

	cin.ignore();
	cin.get(); 
}