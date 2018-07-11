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
}

bool CourseList::IsFull()
{
    return false; // temp
}

int CourseList::FindAvailableIndex()
{
    return -1; // temp
}

void CourseList::Remove( int index )
{
}

string CourseList::GetCourse( int index )
{
    return ""; // temp
}

void CourseList::Display()
{
}

bool CourseList::IsValidIndex( int index )
{
    return false; // temp
}

int CourseList::Size()
{
    return -1; // temp
}

int CourseList::CourseCount()
{
    return -1; // temp
}

void CourseList::Resize()
{
}
