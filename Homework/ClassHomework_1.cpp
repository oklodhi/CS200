#include <iostream>

using namespace std; 

struct CoordPair {
	float x, y; 
	
	void getUserInput() {
		cout << "Enter a coordinate pair x and y: "; 
		cin >> x >> y; 
	}

	void display() {
		cout <<  "Coordinate pair: (" <<  x << ", " << y << ")" << endl;
	}
};

struct CalculateSlope {
	float findSlope(float x1, float y1, float x2, float y2) {
		float deltaY = y2 - y1;
		float deltaX = x2 - x1;

		float slope = deltaY / deltaX;

		return slope;
	}
};



int main() {
	CalculateSlope slope;
	CoordPair point1, point2; 
	point1.getUserInput();
	point1.display();

	point2.getUserInput();
	point2.display();

	cout << "Slope is: " << slope.findSlope(point1.x, point1.y, point2.x, point2.y) << endl; 


	cin.ignore();
	cin.get(); 
}