#include <iostream>
#include <string>
#include <cmath> // used for square root
using namespace std;

float GetDistance(float x1, float y1, float x2, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	float squaredx = dx * dx;
	float squaredy = dy * dy;

	float distance = sqrt(squaredx + squaredy);

	return distance;
}

int main()
{
	cout << "DISTANCE" << endl;

	while (true)
	{
		float x1, y1, x2, y2;

		cout << "\nFirst coordinate pair,  enter x and y: ";
		cin >> x1 >> y1;

		cout << "Second coordinate pair, enter x and y: ";
		cin >> x2 >> y2;

		float distance = GetDistance(x1, y1, x2, y2);
		cout << "Distance: " << distance << endl;

		cout << endl << endl;
	}

	return 0;
}