#ifndef _LOCATION_HPP
#define _LOCATION_HPP

#include <iostream>
#include <string>

using namespace std; 

class Location {
	private: 
		string m_name, m_desctiption; 
		Location* m_ptrNorth; 
		Location* m_ptrSouth;
		Location* m_ptrEast; 
		Location* m_ptrWest;

	public: 
		Location();
		void SetInfo(string name, string description);
		void Display();
		string GetName();
		void SetNeighbor(string direction, Location* ptrLocation);
		Location* GetNeighbor(string direction);
};

#endif 
