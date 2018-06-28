#include <iostream>
#include <string>

using namespace std; 

bool StringCompare(const string& str1, const string& str2);
bool IsLessThan(const string& str1, const string& str2); 
string StringConcatenate(const string& str1, const string& str2); 

int main() {
	string str1, str2; 

	cout << "Enter two string: \n"; 
	cout << "\t 1. \t"; 
	cin >> str1; 
	cout << "\t 2. \t";
	cin >> str2; 

	StringCompare(str1, str2);
	IsLessThan(str1, str2); 
	StringConcatenate(str1, str2); 

	cin.ignore();
	cin.get(); 
	return 0; 
}

bool StringCompare(const string& str1, const string& str2)
{
	if (str1 == str2 && str1.length() == str2.length()) {
		cout << "\n\t Same" << endl;
		return true;
	}
	else {
		cout << "\n\t Not the same" << endl;
		return false; 
	}
}

bool IsLessThan(const string& str1, const string& str2)
{
	if (str1 < str2) {
		cout << "\t " << str1 << " come first" << endl;
		return true; 
	}
	else {
		cout << "\t " << str2 << " come first" << endl;
		return false; 
	}
}

string StringConcatenate(const string& str1, const string& str2)
{
	string newString = str1 + str2; 
	cout << "\t Result: " << newString << endl; 
	return newString; 
}