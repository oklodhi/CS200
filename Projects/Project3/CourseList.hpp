#ifndef _COURSE_LIST_HPP
#define _COURSE_LIST_HPP

#include <string>
using namespace std;

class CourseList
{
    public:
    CourseList() { m_array = nullptr; Setup(); }
    ~CourseList() { Cleanup(); }

    void Setup();
    void Cleanup();

    void Add( const string& item );
    void Remove( int index );
    void Display();
    string GetCourse( int index );

    int Size();
    int CourseCount();

    private:
    bool IsValidIndex( int index );
    void Resize();
    int FindAvailableIndex();
    bool IsFull();

    string * m_array;
    int m_arraySize;
    int m_courseCount;

    friend class Tester;
};

#endif
