#include <iostream>
#include <string>

#include "Location.hpp"

using namespace std; 

Location::Location() {
	m_ptrNorth = nullptr; 
	m_ptrSouth = nullptr;
	m_ptrEast = nullptr;
	m_ptrWest = nullptr;
}

void Location::SetInfo(string name, string description) {
	m_name = name; 
	m_desctiption = description; 
}

string Location::GetName() {
	return m_name; 
}

void Location::Display() {
	cout << m_name << "\n\t " << m_desctiption << endl; 

	if (m_ptrNorth != nullptr) {
		cout << "To the north is: " << m_ptrNorth->GetName() << endl;
	}

	if (m_ptrSouth != nullptr) {
		cout << "To the south is: " << m_ptrSouth->GetName() << endl;
	}

	if (m_ptrEast != nullptr) {
		cout << "To the east is: " << m_ptrEast->GetName() << endl;
	}

	if (m_ptrWest != nullptr) {
		cout << "To the west is: " << m_ptrWest->GetName() << endl;
	}
}

void Location::SetNeighbor(string direction, Location* ptrLocation) {
	if (direction == "north") {
		m_ptrNorth = ptrLocation; 
	} 
	else if (direction == "south") {
		m_ptrSouth = ptrLocation;
	}
	else if (direction == "east") {
		m_ptrEast = ptrLocation;
	}
	else if (direction == "west") {
		m_ptrWest = ptrLocation;
	}
}

Location* Location::GetNeighbor(string direction) {
	if (direction == "north") {
		return m_ptrNorth; 
	}
	else if (direction == "south") {
		return m_ptrSouth; 
	}
	else if (direction == "east") {
		return m_ptrEast; 
	}
	else if (direction == "west") {
		return m_ptrWest; 
	}
}