#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "CourseList.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("Test_Setup()",
            		bind(&Tester::Test_Setup, this)));

		AddTest(TestListItem("Test_IsFull()",
            		bind(&Tester::Test_IsFull, this)));

		AddTest(TestListItem("Test_FindAvailableIndex()",
            		bind(&Tester::Test_FindAvailableIndex, this)));

		AddTest(TestListItem("Test_GetCourse()",
            		bind(&Tester::Test_GetCourse, this)));

		AddTest(TestListItem("Test_IsValidIndex()",
            		bind(&Tester::Test_IsValidIndex, this)));

		AddTest(TestListItem("Test_CourseCount()",
            		bind(&Tester::Test_CourseCount, this)));

		AddTest(TestListItem("Test_Size()",
            		bind(&Tester::Test_Size, this)));

		AddTest(TestListItem("Test_Resize()",
            		bind(&Tester::Test_Resize, this)));

		AddTest(TestListItem("Test_Add()",
            		bind(&Tester::Test_Add, this)));

		AddTest(TestListItem("Test_Remove()",
            		bind(&Tester::Test_Remove, this)));
	}

	virtual ~Tester() { }

private:
	int Test_Setup();
	int Test_IsFull();
	int Test_FindAvailableIndex();
	int Test_GetCourse();
	int Test_IsValidIndex();
	int Test_CourseCount();
	int Test_Size();
	int Test_Resize();
	int Test_Add();
	int Test_Remove();
};

int Tester::Test_Setup()
{
    StartTestSet( "Test_Setup", { "No prerequisites" } );

    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if course count is set to 0 after Setup" );
        CourseList cl;

        //Set_Comments( "Row" );

        int expectedOutput = 0;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } /* TEST END **************************************************************/


    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if array size isn't 0 Setup" );
        CourseList cl;

        //Set_Comments( "Row" );

        int actualOutput = cl.m_arraySize;

        Set_ExpectedOutput( "m_courseCount", "> 0" );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput <= 0 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

        FinishTest();
    } /* TEST END **************************************************************/

    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if m_array is pointing to memory address after Setup" );
        CourseList cl;
        ostringstream oss;
        oss << cl.m_array;

        string * actualOutput = cl.m_array;

        Set_ExpectedOutput( "m_array address", string("not nullptr") );
        Set_ActualOutput( "m_array address", oss.str() );

        if ( actualOutput == nullptr )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

        FinishTest();
    } /* TEST END **************************************************************/

    FinishTestSet();
    return TestResult();
}

int Tester::Test_IsFull()
{
    StartTestSet( "Test_IsFull", { "Add" } );

    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if IsFull() returns true when m_arraySize and m_courseCount match." );
        CourseList cl;
        cl.m_arraySize = 5;
        cl.m_courseCount = 5;

        //Set_Comments( "Row" );

        bool expectedOutput = true;
        bool actualOutput = cl.IsFull();

        Set_ExpectedOutput( "IsFull()", expectedOutput );
        Set_ActualOutput( "IsFull()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } /* TEST END **************************************************************/

    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if IsFull() returns false when m_arraySize and m_courseCount DON'T match." );
        CourseList cl;
        cl.m_arraySize = 5;
        cl.m_courseCount = 2;

        //Set_Comments( "Row" );

        bool expectedOutput = false;
        bool actualOutput = cl.IsFull();

        Set_ExpectedOutput( "IsFull()", expectedOutput );
        Set_ActualOutput( "IsFull()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } /* TEST END **************************************************************/


    { /* TEST BEGIN ************************************************************/
        StartTest( "Check if IsFull() returns true when calling Add() to fill up the array." );
        CourseList cl;

        Set_Comments( "Note: This test won't pass until you've implemented Add()" );

        int arraySize = cl.Size();
        for ( int i = 0; i < arraySize; i++ )
        {
            cl.Add( "cs200" );
        }

        bool expectedOutput = true;
        bool actualOutput = cl.IsFull();

        Set_ExpectedOutput( "IsFull()", expectedOutput );
        Set_ActualOutput( "IsFull()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } /* TEST END **************************************************************/


    FinishTestSet();
    return TestResult();
}

int Tester::Test_FindAvailableIndex()
{
    StartTestSet( "Test_FindAvailableIndex", { "No prerequisites" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "In empty array, check that available index is 0." );
        CourseList cl;

        //Set_Comments( "Row" );

        int expectedOutput = 0;
        int actualOutput = cl.FindAvailableIndex();

        Set_ExpectedOutput( "FindAvailableIndex()", expectedOutput );
        Set_ActualOutput( "FindAvailableIndex()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Fill array partially, check if FindAvailableIndex() returns appropriate index" );
        CourseList cl;

        int holeAt = cl.Size() - 1;

        for ( int i = 0; i < holeAt; i++ )
        {
            cl.m_array[i] = "cs200";
        }

        Set_Comments( "Gap is at position " + StringUtil::ToString( holeAt ) );

        int expectedOutput = holeAt;
        int actualOutput = cl.FindAvailableIndex();

        Set_ExpectedOutput( "FindAvailableIndex()", expectedOutput );
        Set_ActualOutput( "FindAvailableIndex()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Fill array completely, check if FindAvailableIndex() returns -1 for no available spaces." );
        CourseList cl;

        for ( int i = 0; i < cl.Size(); i++ )
        {
            cl.m_array[i] = "cs200";
        }

        int expectedOutput = -1;
        int actualOutput = cl.FindAvailableIndex();

        Set_ExpectedOutput( "FindAvailableIndex()", expectedOutput );
        Set_ActualOutput( "FindAvailableIndex()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetCourse()
{
    StartTestSet( "Test_GetCourse", { "Size()", "IsValidIndex()" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if GetCourse() returns \"\" if the index is invalid." );
        CourseList cl;
        int badIndex = cl.Size();

        string expectedOutput = "";
        string actualOutput = cl.GetCourse( badIndex );

        Set_Comments( "Bad index is " + StringUtil::ToString( badIndex ) );

        Set_ExpectedOutput( "GetCourse()", expectedOutput );
        Set_ActualOutput( "GetCourse()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if GetCourse() returns the right item at index." );
        CourseList cl;

        for ( int i = 0; i < cl.Size(); i++ )
        {
            cl.m_array[i] = "cs200";
        }

        // Change array item
        cl.m_array[1] = "cs250";

        string expectedOutput = "cs250";
        string actualOutput = cl.GetCourse( 1 );

        Set_ExpectedOutput( "GetCourse()", expectedOutput );
        Set_ActualOutput( "GetCourse()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_IsValidIndex()
{
    StartTestSet( "Test_IsValidIndex", { "No prerequisites" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if IsValidIndex() returns false for an index < 0" );
        CourseList cl;

        int badIndex = -1;
        Set_Comments( "Bad index is " + StringUtil::ToString( badIndex ) );

        bool expectedOutput = false;
        bool actualOutput = cl.IsValidIndex( badIndex );

        Set_ExpectedOutput( "IsValidIndex()", expectedOutput );
        Set_ActualOutput( "IsValidIndex()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if IsValidIndex() returns false for an index = array size" );
        CourseList cl;

        int badIndex = cl.m_arraySize;
        Set_Comments( "Bad index is " + StringUtil::ToString( badIndex ) );

        bool expectedOutput = false;
        bool actualOutput = cl.IsValidIndex( badIndex );

        Set_ExpectedOutput( "IsValidIndex()", expectedOutput );
        Set_ActualOutput( "IsValidIndex()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        CourseList cl;

        for ( int i = 0; i < cl.Size(); i++ )
        {
            StartTest( "Check if IsValidIndex() returns true for 0 <= index < arraySize" );

            Set_Comments( "Index is " + StringUtil::ToString( i ) );

            bool expectedOutput = true;
            bool actualOutput = cl.IsValidIndex( i );

            Set_ExpectedOutput( "IsValidIndex()", expectedOutput );
            Set_ActualOutput( "IsValidIndex()", actualOutput );

            if ( actualOutput == expectedOutput )
            {
                TestPass();
            }
            else
            {
                TestFail();
            }
            FinishTest();
        }
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_CourseCount()
{
    StartTestSet( "Test_CourseCount", { "No prereqs" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Set the course count and check if CourseCount() returns the right number" );
        CourseList cl;
        cl.m_courseCount = 10;

        int expectedOutput = 10;
        int actualOutput = cl.CourseCount();

        Set_ExpectedOutput( "CourseCount()", expectedOutput );
        Set_ActualOutput( "CourseCount()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Size()
{
    StartTestSet( "Test_Size", { "PlaceNumberInCell" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Set the array size and check if Size() returns the right number" );
        CourseList cl;
        cl.m_arraySize = 10;

        int expectedOutput = 10;
        int actualOutput = cl.Size();

        Set_ExpectedOutput( "Size()", expectedOutput );
        Set_ActualOutput( "Size()", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Resize()
{
    StartTestSet( "Test_Resize", { "" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if m_arraySize changes after Resize()" );
        CourseList cl;

        int oldSize = cl.m_arraySize;
        cl.Resize();
        int newSize = cl.m_arraySize;

        Set_Comments( "Old size is: " + StringUtil::ToString( oldSize ) );
        Set_Comments( "New size is: " + StringUtil::ToString( newSize ) );

        Set_ExpectedOutput( "m_arraySize", string( "> old size" ) );
        Set_ActualOutput( "m_arraySize", newSize );

        if ( newSize > oldSize )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if m_courseCount stays the same after Resize()" );
        CourseList cl;
        cl.m_courseCount = 2;

        int oldSize = cl.m_courseCount;
        cl.Resize();
        int newSize = cl.m_courseCount;

        int expectedOutput = oldSize;
        int actualOutput = newSize;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if array's address is different after Resize()" );
        CourseList cl;
        ostringstream oss;

        string * oldAddress = cl.m_array;
        cl.Resize();
        string * newAddress = cl.m_array;

        oss.clear();
        oss << oldAddress;
        Set_ExpectedOutput( "m_array address", oss.str() );
        oss.clear();
        oss << newAddress;
        Set_ActualOutput( "m_array address", oss.str() );

        if ( oldAddress != newAddress )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Add()
{
    StartTestSet( "Test_Add", { "FindAvailableIndex()", "IsFull()", "Resize()" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check Add() to make sure items are added to array" );
        CourseList cl;
        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }

        bool expectedOutput = true;
        bool actualOutput = true;

        for ( int i = 0; i < 5; i++ )
        {
            if ( cl.m_array[i] != values[i] )
            {
                Set_Comments( "Item at " + StringUtil::ToString( i ) + " is wrong! Value: " + cl.m_array[i] + ", Expected: " + values[i] );
                actualOutput = false;
            }
        }

        Set_ExpectedOutput( "All items added", expectedOutput );
        Set_ActualOutput( "All items added", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check Add() to make sure m_courseCount is right" );
        CourseList cl;
        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }

        int expectedOutput = 5;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check Add() to make sure we can add stuff past the Resize()" );
        CourseList cl;
        string values[] = { "a", "b", "c", "d", "e", "f", "g" };

        for ( int i = 0; i < 7; i++ )
        {
            cl.Add( values[i] );
        }

        bool expectedOutput = true;
        bool actualOutput = true;

        for ( int i = 0; i < 7; i++ )
        {
            if ( cl.m_array[i] != values[i] )
            {
                Set_Comments( "Item at " + StringUtil::ToString( i ) + " is wrong! Value: " + cl.m_array[i] + ", Expected: " + values[i] );
                actualOutput = false;
            }
        }

        Set_ExpectedOutput( "All items added", expectedOutput );
        Set_ActualOutput( "All items added", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check Add() to make sure m_courseCount is correct after the Resize()" );
        CourseList cl;
        string values[] = { "a", "b", "c", "d", "e", "f", "g" };

        for ( int i = 0; i < 7; i++ )
        {
            cl.Add( values[i] );
        }

        int expectedOutput = 7;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Remove()
{
    StartTestSet( "Test_Remove", { "Add()", "IsValidIndex()" } );

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if remove doesn't modify the array if the index is bad." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.m_array[i] = values[i];
        }

        Set_Comments( "Remove at index -1" );
        cl.Remove( -1 );

        bool allGood = true;
        for ( int i = 0; i < 5; i++ )
        {
            if ( cl.m_array[i] != values[i] )
            {
                Set_Comments( "Item #" + StringUtil::ToString( i ) + " was changed! Value: " + StringUtil::ToString( i ) + ": " + cl.m_array[i] + ", expected: " + values[i] );
                allGood = false;
                break;
            }
        }

        int expectedOutput = true;
        int actualOutput = allGood;

        Set_ExpectedOutput( "no changes made", expectedOutput );
        Set_ActualOutput( "no changes made", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check if remove doesn't modify the array if the index is bad." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.m_array[i] = values[i];
        }

        Set_Comments( "Remove at index 5" );
        cl.Remove( 5 );

        bool allGood = true;
        for ( int i = 0; i < 5; i++ )
        {
            if ( cl.m_array[i] != values[i] )
            {
                Set_Comments( "Item #" + StringUtil::ToString( i ) + " was changed! Value: " + StringUtil::ToString( i ) + ": " + cl.m_array[i] + ", expected: " + values[i] );
                allGood = false;
                break;
            }
        }

        int expectedOutput = true;
        int actualOutput = allGood;

        Set_ExpectedOutput( "no changes made", expectedOutput );
        Set_ActualOutput( "no changes made", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check that array is in correct state after Remove()." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };
        string expectedAfter[] = { "a", "b", "", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }

        cl.Remove( 2 );


        bool expectedOutput = true;
        bool actualOutput = true;

        for ( int i = 0; i < 5; i++ )
        {
            if ( cl.m_array[i] != expectedAfter[i] )
            {
                Set_Comments( "Wrong element at position " + StringUtil::ToString( i ) +
                    "! Value: " + cl.m_array[i] + ", expected: " + expectedAfter[i] );
                actualOutput = false;
                break;
            }
        }

        Set_ExpectedOutput( "Correct state?", expectedOutput );
        Set_ActualOutput( "Correct state?", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check that m_courseCount isn't changed when Remove() is called with bad index." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }

        cl.Remove( 5 );

        int expectedOutput = 5;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Check that m_courseCount is reduced when Remove() is called with good index." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }

        cl.Remove( 3 );

        int expectedOutput = 4;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    { // TEST BEGIN *********************************************************** /
        StartTest( "Make sure m_courseCount doesn't change when trying to Remove() an empty item." );
        CourseList cl;

        string values[] = { "a", "b", "c", "d", "e" };

        for ( int i = 0; i < 5; i++ )
        {
            cl.Add( values[i] );
        }
        cl.Remove( 3 );
        cl.Remove( 3 );

        int expectedOutput = 4;
        int actualOutput = cl.m_courseCount;

        Set_ExpectedOutput( "m_courseCount", expectedOutput );
        Set_ActualOutput( "m_courseCount", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /

    FinishTestSet();
    return TestResult();
}




/*
    { // TEST BEGIN *********************************************************** /
        StartTest( "asdf" );

        //Set_Comments( "Row" );

        int expectedOutput;
        int actualOutput;

        Set_ExpectedOutput( "a", expectedOutput );
        Set_ActualOutput( "b", actualOutput );

        if ( actualOutput == expectedOutput )
        {
            TestPass();
        }
        else
        {
            TestFail();
        }

        FinishTest();
    } // TEST END ************************************************************* /
*/

#endif
