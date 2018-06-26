#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Choose a starting point:" << endl
		<< "1. Kansas City" << endl
		<< "2. Seattle" << endl;

	int city;
	cin >> city;

	string cityName;

	ifstream input;

	if (city == 1)
	{
		input.open("from_kc.txt");
		cityName = "Kansas City";
	}
	else
	{
		input.open("from_seattle.txt");
		cityName = "Seattle";
	}

	int locationCount = 0;
	string * locations;
	int * distances;

	input >> locationCount;

	// Allocate memory for locations and distances
	
	locations = new string[locationCount]; 
	distances = new int[locationCount]; 

	// Use a for loop to load in all the data from text files
	for (int i = 0; i < locationCount; i++) {
		input >> locations[i] >> distances[i]; 
	}

	// Display all the data to the screen with cout
	cout << "\n\nDiSTANCE FROM KANSAS CITY TO...\n"; 
	for (int i = 0; i < locationCount; i++) {
		cout << "* " << distances[i] << " miles - Distance from Kansas City to " << locations[i] << endl; 
	}

	// After the for loop, free the memory of locations and distances.
	delete[] locations;
	delete[] distances;


	input.close();


	cin.ignore(); 
	cin.get(); 
	return 0;
}