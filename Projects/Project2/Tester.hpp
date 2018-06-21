#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "sudoku_functions.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("Test_PlaceNumberInCell()",
            		bind(&Tester::Test_PlaceNumberInCell, this)));
		AddTest(TestListItem("Test_NumberAlreadyUsed()",
            		bind(&Tester::Test_NumberAlreadyUsed, this)));
		AddTest(TestListItem("Test_AllCellsTaken()",
            		bind(&Tester::Test_AllCellsTaken, this)));
		AddTest(TestListItem("Test_ResetGrid()",
            		bind(&Tester::Test_ResetGrid, this)));
	}

	virtual ~Tester() { }

private:
	int Test_PlaceNumberInCell();
	int Test_NumberAlreadyUsed();
	int Test_AllCellsTaken();
	int Test_ResetGrid();
};

int Tester::Test_PlaceNumberInCell()
{
    StartTestSet( "Test_PlaceNumberInCell", { "PlaceNumberInCell" } );


        int grid[3][3] = {
            { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
        };
        int row, column, number;

        for ( row = 0; row < 3; row++ )
        {
            for ( column = 0; column < 3; column++ )
            {
                for ( number = 1; number <= 9; number++ )
                {
                    { /* TEST BEGIN ************************************************************/
                    StartTest( "Check to make sure PlaceNumberInCell() updates the grid properly" );

                    Set_Comments( "Row " + StringUtil::ToString( row ) + ", Column: " + StringUtil::ToString( column ) + ", Number: " + StringUtil::ToString( number ) );
                    PlaceNumberInCell( grid, row, column, number );

                    Set_ExpectedOutput( "grid[" + SU::I2S( row ) + "][" + SU::I2S( column ) + "]", number );
                    Set_ActualOutput( "grid[" + SU::I2S( row ) + "][" + SU::I2S( column ) + "]", grid[row][column] );

                    if ( grid[row][column] != number )
                    {
                        TestFail();
                    }
                    else
                    {
                        TestPass();
                    }

                    FinishTest();
                } /* TEST END **************************************************************/
                }
            }
        }

    FinishTestSet();
    return TestResult();
}

int Tester::Test_NumberAlreadyUsed()
{
    StartTestSet( "Test_NumberAlreadyUsed", { "NumberAlreadyUsed" } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };

    int testNumbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for ( int i = 0; i < 9; i++ )
    {
        { /* TEST BEGIN ************************************************************/
            StartTest( "Test to make sure FALSE is returned for all numbers with an empty grid" );

            Set_Comments( "Number " + SU::I2S( i ) );
            Set_ExpectedOutput( "NumberAlreadyUsed return value", false );
            Set_ActualOutput( "NumberAlreadyUsed return value", NumberAlreadyUsed( grid, testNumbers[i] ) );

            if ( NumberAlreadyUsed( grid, testNumbers[i] ) == true )
            {
                TestFail();
            }
            else
            {
                TestPass();
            }

            FinishTest();
        } /* TEST END **************************************************************/


    }

    for ( int i = 0; i < 9; i++ )
    {
        { /* TEST BEGIN ************************************************************/
            StartTest( "More tests" );

            grid[1][1] = testNumbers[i];

            Set_Comments( "Number at [1][1]: " + SU::I2S( i ) );

            if ( NumberAlreadyUsed( grid, testNumbers[i] ) == false )
            {
                TestFail();
            }
            else if ( i < 8 && NumberAlreadyUsed( grid, testNumbers[i+1] ) == true )
            {
                TestFail();
            }
            else
            {
                TestPass();
            }
            FinishTest();
        } /* TEST END **************************************************************/
    }


    int grid2[3][3] = {
        { 7, 8, 9 }, { 4, 5, 6 }, { 1, 2, 3 }
    };

    for ( int i = 0; i < 9; i++ )
    {
        { /* TEST BEGIN ************************************************************/
            StartTest( "..." );
            Set_Comments( "Number " + SU::I2S( i ) );

            if ( NumberAlreadyUsed( grid2, testNumbers[i] ) == false )
            {
                TestFail();
            }
            else
            {
                TestPass();
            }
            FinishTest();
        } /* TEST END **************************************************************/
    }

    FinishTestSet();
    return TestResult();
}

int Tester::Test_AllCellsTaken()
{
    StartTestSet( "Test_AllCellsTaken", { "AllCellsTaken" } );


    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };
    int row, column;

    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            StartTest( "Check to see if CellIsTaken() returns false for all cells in an empty grid" );

            Set_Comments( "Row " + StringUtil::ToString( row ) + ", Column: " + StringUtil::ToString( column ) );
            Set_ExpectedOutput( "CellIsTaken return value", false );
            Set_ActualOutput( "CellIsTaken return value", CellIsTaken( grid, row, column ) );

            if ( CellIsTaken( grid, row, column ) )
            {
                TestFail();
            }
            else
            {
                TestPass();
            }
            FinishTest();
        }
    }

    int grid2[3][3] = {
        { 1, 2, 3 }, { 7, 8, 9 }, { 4, 5, 6 }
    };

    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            { /* TEST BEGIN ************************************************************/
                StartTest( "Check to see if CellIsTaken() returns true for a full grid" );

                Set_Comments( "Row " + StringUtil::ToString( row ) + ", Column: " + StringUtil::ToString( column ) );
                Set_ExpectedOutput( "CellIsTaken return value", true );
                Set_ActualOutput( "CellIsTaken return value", CellIsTaken( grid2, row, column ) );

                if ( CellIsTaken( grid2, row, column ) == false )
                {
                    TestFail();
                }
                else
                {
                    TestPass();
                }

                FinishTest();
            } /* TEST END **************************************************************/
        }
    }


    int grid3[3][3] = {
        { 1, 2, 0 }, { 7, 0, 9 }, { 0, 5, 6 }
    };

    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            { /* TEST BEGIN ************************************************************/
                StartTest( "Check to see if CellIsTaken() returns true or false correctly on partially-filled grid" );

                Set_Comments( "Row " + StringUtil::ToString( row ) + ", Column: " + StringUtil::ToString( column ) );

                Set_ExpectedOutput( "1. CellIsTaken return value", true );
                Set_ExpectedOutput( "2. grid[" + SU::I2S( row ) + "][" + SU::I2S( column ) + "]", "not 0" );

                Set_ExpectedOutput( "...OR...", "" );

                Set_ExpectedOutput( "1. CellIsTaken return value", false );
                Set_ExpectedOutput( "2. grid[" + SU::I2S( row ) + "][" + SU::I2S( column ) + "]", 0 );

                Set_ActualOutput( "CellIsTaken return value", CellIsTaken( grid3, row, column ) );
                Set_ActualOutput( "grid[" + SU::I2S( row ) + "][" + SU::I2S( column ) + "]", grid3[row][column] );

                if ( CellIsTaken( grid3, row, column ) == true && grid3[row][column] == 0 )
                {
                    TestFail();
                }
                else if ( CellIsTaken( grid3, row, column ) == false && grid3[row][column] != 0 )
                {
                    TestFail();
                }
                else
                {
                    TestPass();
                }
                FinishTest();
            } /* TEST END **************************************************************/
        }
    }

    FinishTestSet();
    return TestResult();
}

int Tester::Test_ResetGrid()
{
    StartTestSet( "Test_ResetGrid", { "ResetGrid" } );

    int grid[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            { /* TEST BEGIN ************************************************************/
                StartTest( "Test to make sure ResetGrid sets cell ["+SU::I2S(x)+"]["+SU::I2S(y)+"] to 0." );

                int expectedResult = 0;
                int actualResult = grid[x][y];

                Set_ExpectedOutput  ( "Value at ["+SU::I2S(x)+"]["+SU::I2S(y)+"]", expectedResult );
                Set_ActualOutput    ( "Value at ["+SU::I2S(x)+"]["+SU::I2S(y)+"]", actualResult );

                if ( actualResult != expectedResult )
                {
                    TestFail();
                }
                else
                {
                    TestPass();
                }

                FinishTest();
            } /* TEST END **************************************************************/
        }
    }

    FinishTestSet();
    return TestResult();
}

#endif
