#ifndef _ADVENTURE_GAME_HPP
#define _ADVENTURE_GAME_HPP

#include <string>
using namespace std;

#include "Location.hpp"

class AdventureGame
{
public:
	void Setup();                           // Create locations
	void Run();                             // Main game loop
	char GetInput();                        // Get valid input
	void Move(const string& direction);   // Move to new location

private:
	Location m_locations[9];                // All the game's locations
	Location* m_ptrCurrentLocation;         // Pointer to current location
};

#endif