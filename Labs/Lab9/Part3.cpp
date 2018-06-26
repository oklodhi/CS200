#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std; 

int main() {
	srand(time(NULL)); 

	int size; 
	int* lottoNumbers;

	cout << "How many lotto balls with be there? \n"; 
	cin >> size; 

	lottoNumbers = new int[size];

	for (int i = 0; i < size; i++) {
		lottoNumbers[i] = rand() % 100;
		cout << lottoNumbers[i] << "\t"; 
	}

	delete lottoNumbers; 

	cin.ignore();
	cin.get(); 
}