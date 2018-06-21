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
		AddTest(TestListItem("PlaceNumberInCell()",
            bind(&Tester::Test_PlaceNumberInCell, this)));

		AddTest(TestListItem("CellIsTaken()",
            bind(&Tester::Test_CellIsTaken, this)));

		AddTest(TestListItem("NumberAlreadyUsed()",
            bind(&Tester::Test_NumberAlreadyUsed, this)));

		AddTest(TestListItem("AllCellsTaken()",
            bind(&Tester::Test_AllCellsTaken, this)));

		AddTest(TestListItem("ResetGrid()",
            bind(&Tester::Test_ResetGrid, this)));
	}

	virtual ~Tester()
	{
	}

private:
	int Test_PlaceNumberInCell();
	int Test_CellIsTaken();
	int Test_NumberAlreadyUsed();
	int Test_AllCellsTaken();
	int Test_ResetGrid();
};

int Tester::Test_PlaceNumberInCell()
{
cout << "HI" << endl;
    StartTestSet( "PlaceNumberInCell", { } );

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
            }
        }
    }

    FinishTestSet();
    return TestResult();
}

int Tester::Test_CellIsTaken()
{
    StartTestSet( "CellIsTaken", { } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };
    int row, column;

    bool fail = false;

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

    fail = false;
    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            StartTest( "Check to see if CellIsTaken() returns true for a full grid" );

            Set_Comments( "Row " + StringUtil::ToString( row ) + ", Column: " + StringUtil::ToString( column ) );
            Set_ExpectedOutput( "CellIsTaken return value", true );
            Set_ActualOutput( "CellIsTaken return value", CellIsTaken( grid2, row, column ) );

            if ( CellIsTaken( grid2, row, column ) == false )
            {
                TestFail();
                fail = true;
            }
            else
            {
                TestPass();
            }

            FinishTest();

        }
    }


    int grid3[3][3] = {
        { 1, 2, 0 }, { 7, 0, 9 }, { 0, 5, 6 }
    };

    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
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
                fail = true;
            }
            else if ( CellIsTaken( grid3, row, column ) == false && grid3[row][column] != 0 )
            {
                TestFail();
                fail = true;
            }
            else
            {
                TestPass();
            }
            FinishTest();
        }
    }


    FinishTestSet();
    return TestResult();
}

int Tester::Test_NumberAlreadyUsed()
{
    StartTestSet( "NumberAlreadyUsed", { } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };

    int testNumbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for ( int i = 0; i < 9; i++ )
    {
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
    }


    for ( int i = 0; i < 9; i++ )
    {
        StartTest( "..." );

        grid[1][1] = testNumbers[i];

        Set_Comments( "Number " + SU::I2S( i ) );

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
    }


    int grid2[3][3] = {
        { 7, 8, 9 }, { 4, 5, 6 }, { 1, 2, 3 }
    };

    for ( int i = 0; i < 9; i++ )
    {
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
    }

    FinishTestSet();
    return TestResult();
}

// I'm bored of fixing tests now.

int Tester::Test_AllCellsTaken()
{
    StartTestSet( "AllCellsTaken", { } );

    int grid[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    StartTest( "Check that TRUE is returned if ALL cells are taken." );

    if ( AllCellsTaken( grid ) == false )
    {
        TestFail();
    }
    else
    {
        TestPass();
    }



    StartTest( "Check that FALSE is returned if there EXISTS at least one cell that is not taken." );
    //AdditionalDescription( "For a cell to be considered \"empty\", it must be assigned the value of 0." );

    int grid2[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 0, 4 }
    };

    if ( AllCellsTaken( grid2 ) == true )
    {
        TestFail();
    }
    else
    {
        TestPass();
    }



    StartTest( "Check that FALSE is returned if the entire grid is empty." );
    //AdditionalDescription( "For a cell to be considered \"empty\", it must be assigned the value of 0." );

    int grid3[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };

    if ( AllCellsTaken( grid3 ) == true )
    {
        TestFail();
    }
    else
    {
        TestPass();
    }




    FinishTestSet();
    return TestResult();
}

int Tester::Test_ResetGrid()
{
    StartTestSet( "ResetGrid", { } );

    int grid[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    StartTest( "Check that all cells are 0" );
//    AdditionalDescription( "The grid is 3x3, so there are 9 cells." );
//    AdditionalDescription( "After the ResetGrid() function is called on the grid," );
//    AdditionalDescription( "all cells of the grid should be set to 0." );
    ResetGrid( grid );

    bool fail = false;
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            if ( grid[x][y] != 0 )
            {
                TestFail();
                fail = true;
            }
        }
    }

    if ( !fail )
    {
        TestPass();
    }

    FinishTestSet();
    return TestResult();
}

#endif
