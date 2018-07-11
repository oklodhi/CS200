#include "College.hpp"

#include "cuTEST/Menu.hpp"

#include <iostream>
#include <fstream>
using namespace std;

void College::Run()
{
    Load();
    bool done = false;
    while ( !done )
    {
        MainMenu();
        int choice = GetIntInput( 1, 4 );

        switch( choice )
        {
            case 1:     ViewCourses();  break;
            case 2:     AddCourse();    break;
            case 3:     RemoveCourse(); break;
            case 4:     done = true;  break;
        }

        cout << endl << endl;
    }
    Save();
}

void College::MainMenu()
{
    Menu::ClearScreen();
    cout << " ---------------------------" << endl
         << " - COLLEGE COURSE DATABASE -" << endl
         << " ---------------------------" << endl
         << " " << m_courseList.CourseCount() << " total course(s)" << endl
         << " ---------------------------" << endl
         << " 1. View courses" << endl
         << " 2. Add course" << endl
         << " 3. Remove course" << endl
         << " 4. Save and quit" << endl << endl;
}

int College::GetIntInput( int min, int max )
{
    int choice;
    cout << " >> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "** Invalid selection! Try again." << endl;
        cout << " >> ";
        cin >> choice;
    }

    return choice;
}

void College::ViewCourses()
{
    cout << endl;
    cout << " -----------------" << endl;
    cout << " -  VIEW COURSES - "<< endl;
    cout << " -----------------" << endl;

    m_courseList.Display();

    cout << "\n Press a key to continue..." << endl;
    cin.ignore();
    cin.get();
}

void College::AddCourse()
{
    cout << endl;
    cout << " ---------------" << endl;
    cout << " -  NEW COURSE - "<< endl;
    cout << " ---------------" << endl;

    string name;
    cout << " New course name: ";
    cin.ignore();
    getline( cin, name );

    m_courseList.Add( name );

    cout << "\n Press a key to continue..." << endl;
    cin.get();
}

void College::RemoveCourse()
{
    cout << endl;
    cout << " ------------------" << endl;
    cout << " -  REMOVE COURSE - "<< endl;
    cout << " ------------------" << endl;

    m_courseList.Display();

    cout << " Remove at which index? ";
    int choice = GetIntInput( 0, m_courseList.Size() - 1 );

    m_courseList.Remove( choice );

    cout << "\n Press a key to continue..." << endl;
    cin.ignore();
    cin.get();
}

void College::Load()
{
    ifstream input( "courses.txt" );

    if ( input.fail() )
    {
        cout << "** Could not find courses.txt!" << endl;
        cout << "\t Starting new course file..." << endl << endl;
        return;
    }

    string buffer;
    while ( getline( input, buffer ) )
    {
        m_courseList.Add( buffer );
    }

    input.close();
}

void College::Save()
{
    ofstream output( "courses.txt" );

    for ( int i = 0; i < m_courseList.Size(); i++ )
    {
        string course = m_courseList.GetCourse( i );
        if ( course != "" ) { output << course << endl; }
    }

    cout << endl << "Saved courses to courses.txt" << endl;

    output.close();
}
