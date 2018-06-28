#include <iostream>
#include <cstring>

using namespace std; 

int main() {
	char a[15] = { 'c', 'h', 'e', 'e', 's', 'e' };
	char b[15] = { 'p', 'i', 'z', 'z', 'a' };

	strcat_s(a, b);

	cout << "\"" << a << "\"" << endl;

	cin.ignore(); 
	cin.get(); 
	return 0; 
}