#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char name[20] = { 'a', 'b', 'c', 'd', 'e'};

	cout << strlen(name) << endl;

	char name_2[20] = { 'a', 'b', 'c', 'd', 'e', '\0' };

	cout << strlen(name_2) << endl;

	cin.ignore(); 
	cin.get(); 
	return 0; 
}