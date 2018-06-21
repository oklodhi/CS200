#ifndef _SUDOKU_FUNCTIONS
#define _SUDOKU_FUNCTIONS

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void PlaceNumberInCell( int grid[3][3], int row, int column, int number );
bool CellIsTaken( int grid[3][3], int row, int column );
void ResetGrid( int grid[3][3] );
bool NumberAlreadyUsed( int grid[3][3], int number );
bool AllCellsTaken( int grid[3][3] );
int GetUserInput( int min, int max );
int GetRow();
int GetColumn();
int GetNumber();

/* PRE-WRITTEN FUNCTION **************************************/

void DisplayHeader();
void SetRandom( int grid[3][3], int randomCount );
void DisplayGrid( int grid[3][3] );

#endif
