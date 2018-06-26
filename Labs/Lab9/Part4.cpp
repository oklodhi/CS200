#include <iostream>
#include <string>

using namespace std;

int main() {
	bool again = true; 
	char yesOrNo; 

	while (again) {
		string ears[3] = { "   ^ ^   ",   "  n   n ",     "  *   *  " };
		string heads[3] = { " ( o_o ) ",   " ( x_x )" ,    " ( >_< ) " };
		string bodies[3] = { "/(     )\\",  "\\(     )/",   "o(     )o" };
		string feet[3] = { "  d   b   ",  "  @   @ ",     "  () () " };

		string * ptrEars;
		string * ptrHead;
		string * ptrBody;
		string * ptrFeet;

		int choiceEars, choiceHead, choiceBody, choiceFeet;

		cout << "Enter ears (0 - 2): ";
		cin >> choiceEars;
		cout << "Enter head (0 - 2): ";
		cin >> choiceHead;
		cout << "Enter body (0 - 2): ";
		cin >> choiceBody;
		cout << "Enter feet (0 - 2): ";
		cin >> choiceFeet;

		ptrEars = &ears[choiceEars];
		ptrHead = &heads[choiceHead];
		ptrBody = &bodies[choiceBody];
		ptrFeet = &feet[choiceFeet];

		cout << *ptrEars << endl << *ptrHead << endl << *ptrBody << endl << *ptrFeet << endl;

		cout << "\nAgain? (y/n): "; 
		cin >> yesOrNo; 

		if (yesOrNo == 'n') {
			again = false; 
			break; 
		}
	}
}