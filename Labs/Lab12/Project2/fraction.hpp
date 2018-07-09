#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include <string>

using namespace std; 

// Object Declaration

struct fraction {
	public:
		void setup(int n, int d);
		void display();
		fraction add(fraction* other);
		fraction subtract(fraction* other);
		fraction multiply(fraction* other);
		fraction divide(fraction* other);

	private:
		int num, denom;
};


#endif
