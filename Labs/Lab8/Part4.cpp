#include <iostream>
#include <string>

using namespace std; 

void displayStudents(string students[3]);
void updateNames(string students[3]);

int main() {
	string students[3];
	
	int choice; 
	bool done = false; 

	while (!done) {
		displayStudents(students);

		cout << "\n\n1. UPDATE NAME \t 2. QUIT\n";
		cin >> choice;
		switch (choice) {
		case 1:
			updateNames(students);
			break;
		case 2:
			done = true;
			break;
		}
	}
}

void displayStudents(string students[3]) {
	cout << "--------------------------\n";
	cout << "STUDENT ID \t STUDNET NAME \n";

	for (int i = 0; i < 3; i++) {
		cout << "\t" << i << "\t" << students[i] << endl;
	}
}

void updateNames(string students[3]) {
	int id; 
	string* ptrStudent = nullptr;
	cout << "Student ID: "; 
	cin >> id; 
	ptrStudent = &students[id]; 
	cout << "New Student Name: "; 
	cin >> *ptrStudent;  
}