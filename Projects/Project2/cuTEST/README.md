# cuTEST

By Rachel Morris!

## About

This is a testing framework I've written to use in my C++ programming classes...
*CS 200: Concepts of Programming Algorithms using C++* and
*CS 250: Data Structures using C++*.

## Usage

Note: This requires building with c++11 flags (or later... using function pointers).
Make sure to build with ```-std=c++11``` or similar.

Build the program, with **test.cpp** as the file that contains main().
When it is run, a file called **test_result.txt** will be generated with
the output of all the tests.

I will usually clone this repository into my project directory,
so that cuTEST is a subdirectory, one level up from my project's source files.

### Creating the Tester file

Copy the **TestTemplate.hpp** file into the directory where you have
the classes you want to test, and rename it **Tester.hpp**.

### Setting up the Tester

This Tester file should ```#include``` the .h/.hpp file of the class you're
going to be testing out.

Within the constructor, you will add a test like this:

```c++
AddTest(TestListItem("TEST_LABEL",             bind(&Tester::TestFunction, this)));
```

Where your ```TestFunction``` is a member function of the Tester.
You will also need to declare your function(s) within the Tester class.

You can define the functions at the bottom of the file if you want.

### Test anatomy

The ```TesterBase``` has some functions you can use to make it easier on yourself.
For example:

```c++
int Tester::ExampleTest()
{
    StartTestSet( "Test_Size", { "Insert" } );

    StartTest( "Create empty Hash Table, add 2 items, check Size()." ); {
        HashTable<int,string> employees;
        employees.Insert( 123, "Bobbert" );
        employees.Insert( 456, "Kabe the Cat" );

        int expectedOutput = 2;
        int actualOutput = employees.Size();

        Set_ExpectedOutput( "Size()", expectedOutput );
        Set_ActualOutput( "Size()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    FinishTestSet();
    return TestResult();
}
```

### Test output

The tests will output a detailed file with information called ```test_result.html```.
Information looks like this:

<table>
<tr>
<th class='col_set'> Test set </th>
<th class='col_test'> Test </th>
<th class='col_prereq'> Prerequisite <br> functions </th>
<th class='col_result'> Pass/fail </th>
<th class='col_expected'> Expected <br> output </th>
<th class='col_actual'> Actual <br> output </th>
<th class='col_comments'> Comments </th>
</tr>
<tr class='pass'>
<td class='test-set'>      Test_IsEmpty       </td>
<td class='test'>          Create empty Hash Table, check if IsEmpty() returns true.       </td>
<td class='prereq'>   <ul> <li>Insert</li> </ul> </td>
<td class='result'>        passed       </td>
<td class='expected'> <ol> <li>IsEmpty() = 1</li> </ol> </td>
<td class='actual'>   <ol> <li>IsEmpty() = 1</li> </ol> </td>
<td class='comments'> <ul>  </ul> </td>
</tr>
<tr class='pass'>
<td class='test-set'>      Test_IsEmpty       </td>
<td class='test'>          Create empty Hash Table, add items, check if IsEmpty() returns false.       </td>
<td class='prereq'>   <ul> <li>Insert</li> </ul> </td>
<td class='result'>        passed       </td>
<td class='expected'> <ol> <li>IsEmpty() = 0</li> </ol> </td>
<td class='actual'>   <ol> <li>IsEmpty() = 0</li> </ol> </td>
<td class='comments'> <ul>  </ul> </td>
</tr>
<tr class='summary'>
<td colspan='7' class='summary'>
<strong>SUMMARY FOR Test_IsEmpty:</strong>
2 out of 2 tests passed
</td>

<tr class='spacer'></tr>
</table>
