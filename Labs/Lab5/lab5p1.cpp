#include <iostream>
using namespace std;

// Input: A percent value (0% - 100%, no percent sign though)
// Output: The decimal equivalent (0.0 - 1.0)
float PercentToDecimal(float percent)
{
	float decimal = percent / 100;
	return decimal;
}

int main()
{
	float num;

	cout << "PERCENT TO DECIMAL \n \n";
	cout << "Enter a percent value, without the %: ";
	cin >> num;

	float dec = PercentToDecimal(num);

	cout << "\nDecimal value: " << dec;
	return 0;
}