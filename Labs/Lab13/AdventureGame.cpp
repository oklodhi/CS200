#include "AdventureGame.hpp"

void AdventureGame::Setup()
{
	// Set up each location's title and description
	m_locations[0].SetInfo("\nForest", "The forest is cool and dark.");
	m_locations[1].SetInfo("\nEastern forest edge", "The forest expands to the west.");
	m_locations[2].SetInfo("\nLake", "The lake has several plants growing around it.");
	m_locations[3].SetInfo("\nSouthern forest edge", "The forest expands to the north.");
	m_locations[4].SetInfo("\nWestern desert edge", "The desert is barren, but nearby grass is growing.");
	m_locations[5].SetInfo("\nEast cave entrance", "The cave leads further in to the south.");
	m_locations[6].SetInfo("\nNorthern desert edge", "Dry grass speckle the landscape here.");
	m_locations[7].SetInfo("\nSouth cave entrance", "The cave leads further in to the east.");
	m_locations[8].SetInfo("\nCave internal", "The cave is dark and damp.");

	// Set location 0's EAST neighbor to location 1...
	m_locations[0].SetNeighbor("east", &m_locations[1]);
	m_locations[0].SetNeighbor("south", &m_locations[3]);

	m_locations[1].SetNeighbor("west", &m_locations[0]);
	m_locations[1].SetNeighbor("south", &m_locations[4]);
	m_locations[1].SetNeighbor("east", &m_locations[2]);

	m_locations[2].SetNeighbor("west", &m_locations[1]);
	m_locations[2].SetNeighbor("south", &m_locations[5]);

	m_locations[3].SetNeighbor("east", &m_locations[4]);
	m_locations[3].SetNeighbor("south", &m_locations[6]);
	m_locations[3].SetNeighbor("north", &m_locations[0]);

	m_locations[4].SetNeighbor("west", &m_locations[3]);
	m_locations[4].SetNeighbor("south", &m_locations[7]);
	m_locations[4].SetNeighbor("north", &m_locations[1]);
	m_locations[4].SetNeighbor("east", &m_locations[5]);

	m_locations[5].SetNeighbor("west", &m_locations[4]);
	m_locations[5].SetNeighbor("south", &m_locations[8]);
	m_locations[5].SetNeighbor("north", &m_locations[2]);

	m_locations[6].SetNeighbor("east", &m_locations[7]);
	m_locations[6].SetNeighbor("north", &m_locations[3]);

	m_locations[7].SetNeighbor("west", &m_locations[6]);
	m_locations[7].SetNeighbor("north", &m_locations[4]);
	m_locations[7].SetNeighbor("east", &m_locations[8]);

	m_locations[8].SetNeighbor("west", &m_locations[7]);
	m_locations[8].SetNeighbor("north", &m_locations[5]);

	/*for (int i = 0; i < 9; i++)
	{
		cout << "LOCATION " << i << ":" << endl;
		m_locations[i].Display();
		cout << endl << endl;
	}*/

	m_ptrCurrentLocation = &m_locations[0];
}

void AdventureGame::Run()
{
	bool done = false;
	char choice; 
	while (!done)
	{
		m_ptrCurrentLocation->Display();
		choice = GetInput(); 

		switch (choice) {
			case 'n': 
				Move("north");
				break; 
			case 's':
				Move("south");
				break; 
			case 'e':
				Move("east"); 
				break; 
			case 'w':
				Move("west"); 
				break; 
			case 'q':
				done = true; 
				break; 
		}
	}

	// Game loop is over
	cout << endl << "Goodbye" << endl;
}

void AdventureGame::Move(const string& direction)
{
	Location* ptrNeightbor = m_ptrCurrentLocation->GetNeighbor(direction); 

	if (ptrNeightbor == nullptr) {
		cout << "Error. Can't move there!" << endl;
	}
	else {
		cout << "\nYou move " << direction << endl; 
		m_ptrCurrentLocation = ptrNeightbor;
		cout << "\n\n-------------------------------- \n\n"; 
	}
}

char AdventureGame::GetInput()
{
	char choice; 

	cout << "Choose an option: (n)orth, (s)outh, (e)ast, (w)est, (q)uit" << endl; 
	cin >> choice; 
	choice = tolower(choice); 

	if (choice == 'n' || choice == 's' || choice == 'e' || choice == 'w' || choice == 'q') {
		return choice;
	}
	else {
		cout << "Invalid choice! Try again: "; 
		cin >> choice; 
	}
}