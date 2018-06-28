#include <iostream>
#include <cstring> 

using namespace std;

int main() {
	char a_1[5] = { 'a', 'b', 'c', 'd' };
	char b_1[5] = { 'a', 'b', 'c', 'd' };

	cout << "Compare strings: " << strcmp(a_1, b_1) << endl;

	char a_2[5] = { 'a', 'b', 'c', 'd', '\0' };
	char b_2[5] = { 'a', 'b', 'c', 'd' };

	cout << "Compare strings: " << strcmp(a_2, b_2) << endl;

	char a_3[5] = { 'a', 'b', 'c', 'd'};
	char b_3[5] = { 'b', 'b', 'c', 'd' };

	cout << "Compare strings: " << strcmp(a_3, b_3) << endl;

	char a_4[5] = { 'c', 'b', 'c', 'd'};
	char b_4[5] = { 'b', 'b', 'c', 'd' };

	cout << "Compare strings: " << strcmp(a_4, b_4) << endl;

	cin.ignore(); 
	cin.get();
	return 0; 
}