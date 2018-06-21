#include <iostream>
using namespace std;

#include "Tester.hpp"
#include "sudoku_runner.hpp"

int main()
{
    while ( true )
    {
        cout << "1. Run Tests" << endl;
        cout << "2. Run Sudoku" << endl;
        cout << "3. Quit" << endl;

        int choice;
        cout << endl << ">> ";
        cin >> choice;

        if ( choice == 1 )
        {
            Tester test;
            test.Start();
        }
        else if ( choice == 2 )
        {
            SudokuRunner();
        }
        else if ( choice == 3 )
        {
            break;
        }
        cout << endl << endl;
    }

    return 0;
}
