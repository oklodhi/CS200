#ifndef _COLLEGE_HPP
#define _COLLEGE_HPP

#include "CourseList.hpp"

class College
{
    public:
    void Run();
    void MainMenu();
    int GetIntInput( int min, int max );

    void ViewCourses();
    void AddCourse();
    void RemoveCourse();

    string GetCourse( int index );

    void Save();
    void Load();

    private:
    CourseList m_courseList;
};

#endif
