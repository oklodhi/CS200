#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("TestItem1()",
            		bind(&Tester::Test_Item1, this)));
	}

	virtual ~Tester() { }

private:
	int Test_Item1();
};

int Tester::Test_Item1()
{
    StartTestSet( "TestItem1", { "Prereq()" } );

	{ /* TEST BEGIN ************************************************************/
        StartTest( "Check to make sure 2 + 2 = 4" );
        
        int expectedResult = 4;
        int actualResult = 2 + 2;
        
        Set_ExpectedOutput  ( "Math result", expectedResult );
        Set_ActualOutput    ( "Math result", actualResult );
        
        if ( actualoutput != expectedOutput )
        {
            TestFail( "Error message" );
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

#endif
