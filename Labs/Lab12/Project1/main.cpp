#include <iostream>

using namespace std; 

#include "student.hpp"

int main() {
	Student student1, student2, student3; 

	student1.name = "Bob"; 
	student1.gpa = 3.2; 
	student1.degree = "CS";

	student2.name = "Karen";
	student2.gpa = 4.0;
	student2.degree = "Stats";

	student3.name = "Noah";
	student3.gpa = 3.5;
	student3.degree = "Math";

	student1.display(); 
	student2.display(); 
	student3.display(); 

	cin.ignore();
	cin.get(); 
}