#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include <string>

using namespace std; 

// Object Declaration

struct Student {
	string name, degree;
	double gpa; 

	void display() {
		cout << "Name: \t\t" << name << endl; 
		cout << "Degree: \t" << degree << endl; 
		cout << "GPA: \t\t" << gpa << endl << endl; 
	}
};


#endif
