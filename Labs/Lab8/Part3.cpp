#include <iostream> 

using namespace std; 

int main() {
	float priceA, priceB, priceC; 

	float* ptrPrice;

	ptrPrice = &priceA; 
	*ptrPrice = 9.99; 

	cout << "PriceA: $" << priceA << endl;

	ptrPrice = &priceB;
	*ptrPrice = 0.50;

	cout << "PriceB: $" << priceB << endl;

	ptrPrice = &priceC;
	*ptrPrice = 123.45;

	cout << "PriceC: $" << priceC << endl;

	cin.ignore(); 
}