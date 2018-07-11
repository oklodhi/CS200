#include "CourseList.hpp"

#include <iostream>
using namespace std;

void CourseList::Setup()
{
	m_courseCount = 0;
	m_arraySize = 5;
	m_array = new string[5]; 
}

void CourseList::Cleanup()
{
	delete[] m_array; 
}

void CourseList::Add( const string& item )
{
	if (IsFull()) {
		Resize(); 
	}

	int availIndex = FindAvailableIndex(); 

	m_array[availIndex] = item; 

	m_courseCount++; 
}

bool CourseList::IsFull()
{
	if (m_courseCount == m_arraySize) {
		return true; 
	}
	else {
		return false; 
	}
}

int CourseList::FindAvailableIndex()
{
	for (int i = 0; i < m_arraySize; i++) {
		if (m_array[i] == "") {
			return i; 
		}
	}
	return -1; 
}

void CourseList::Remove( int index )
{
	if (!IsValidIndex(index)) {
		cout << "Error: Invalid index" << endl;
		return; 
	}
	else if (m_array[index] == ""){
		cout << "Error: Nothing in index" << endl;
		return;
	}
	else {
		m_array[index] = ""; 
		m_courseCount--; 
		cout << "Item at index " << index << " removed." << endl; 
	}
}

string CourseList::GetCourse( int index )
{
	if (index >= 0 && index < m_arraySize) {
		return m_array[index];
	}
	else {
		return ""; 
	}
}

void CourseList::Display()
{
	for (int i = 0; i < m_array->size; i++) {
		cout << "Index " << i << " :" << m_array[i] << endl; 
	}
}

bool CourseList::IsValidIndex( int index )
{
	if (index >= 0 && index < m_arraySize) {
		return true;
	}
	else {
		return false; 
	}
}

int CourseList::Size()
{
	return m_arraySize; 
}

int CourseList::CourseCount()
{
	return m_courseCount; 
}

void CourseList::Resize()
{
	int newSize = m_arraySize + 5; 

	string * newArray = new string[newSize]; 

	for (int i = 0; i < m_arraySize; i++) {
		newArray[i] = m_array[i]; 
	}

	delete[] m_array; 

	m_array = newArray; 
	m_arraySize = newSize; 
}
