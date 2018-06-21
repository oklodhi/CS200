#ifndef _UTILITIES_HPP
#define _UTILITIES_HPP

#include <cstdlib>
#include <limits>
#include <string>
using namespace std;

/* DON'T MODIFY THIS FILE */

void ClearScreen();
void DrawHorizontalBar( int width, char symbol );
void Header( const string& header );
void Pause();

struct Cell
{
    int c, r;
    Cell( int c, int r )
    {
        this->c = c;
        this->r = r;
    }
};

#endif
