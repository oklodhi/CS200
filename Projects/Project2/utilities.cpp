#include "utilities.hpp"

#include <iostream>
using namespace std;


void ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

void Header( const string& header )
{
    DrawHorizontalBar( 80, '*' );
    string head = "* " + header + " *";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size(), '*' );
    cout << endl;
}

void Pause()
{
    cout << endl << "Press ENTER to continue..." << endl;

    string blah;
    cin.ignore();
    getline( cin, blah );
}

