#include <iostream>
#include <cstring>

using namespace std; 

int main() {

	char username[5]; 

	strcpy_s(username, "bob");

	cout << "\"" << username << "\"" << endl;



	char username_2[5];

	strcpy_s(username_2, "Alexanderr");

	cout << "\"" << username_2 << "\"" << endl;

	cin.ignore();
	cin.get();
	return 0;
}