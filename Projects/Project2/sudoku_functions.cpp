#include "sudoku_functions.hpp"

#include "utilities.hpp"

/* MODIFY THESE FUNCTIONS */

void PlaceNumberInCell( int grid[3][3], int row, int column, int number )
{
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			grid[r][c] = number; 
		}
	}
}

bool CellIsTaken( int grid[3][3], int row, int column )
{
	int* ptrNumber = nullptr;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			ptrNumber = &grid[r][c]; 

			if (*ptrNumber != 0) {
				return true; 
			}
			else {
				return false; 
			}
		}
	}
}

void ResetGrid( int grid[3][3] )
{
}

bool NumberAlreadyUsed( int grid[3][3], int number )
{
    return false; // temp 
}

bool AllCellsTaken( int grid[3][3] )
{
    return false; // temp
}

int GetUserInput( int min, int max ) // doesn't have test
{
    return 0; // temp
}

int GetRow() // doesn't have test
{
    return 0; // temp
}

int GetColumn() // doesn't have test
{
    return 0; // temp
}

int GetNumber() // doesn't have test
{
    return 0; // temp
}

/* PRE-WRITTEN FUNCTION **************************************/

void DisplayHeader() // done
{
    ClearScreen();  // special function from utilities.hpp
    Header( "Mini-Sudoku" );  // special function from utilities.hpp
}

void SetRandom( int grid[3][3], int randomCount ) // done
{
    vector< Cell > cells = {
        Cell( 0, 0 ), Cell( 0, 1 ), Cell( 0, 2 ),
        Cell( 1, 0 ), Cell( 1, 1 ), Cell( 1, 2 ),
        Cell( 2, 0 ), Cell( 2, 1 ), Cell( 2, 2 )
    };

    if ( randomCount < 0 || randomCount > 8 ) { return; }

    for ( int random = 0; random < randomCount; random++ )
    {
        int v = rand() % cells.size();
        int r = cells[v].r;
        int c = cells[v].c;
        int n = rand() % 9;
        while ( NumberAlreadyUsed( grid, n ) )
        {
            n = rand() % 9;
        }

        grid[r][c] = n;

        cells.erase( cells.begin() + v );
    }
}

void DisplayGrid( int grid[3][3] ) // done
{
    cout << "\t";
    for ( int c = 0; c < 3; c++ )
    {
        cout << "  " << c << " ";
    }
    cout << endl << endl;

    for ( int r = 0; r < 3; r++ )
    {
        cout << r << "\t";
        for ( int c = 0; c < 3; c++ )
        {
            if ( c == 0 ) { cout << "| "; }
            if ( grid[r][c] == 0 )
            {
                cout << "  | ";
            }
            else
            {
                cout << grid[r][c] << " | ";
            }
        }
        if ( r != 2 )
        {
            cout << endl << "\t-------------" << endl;
        }
    }
    cout << endl << endl;
}
