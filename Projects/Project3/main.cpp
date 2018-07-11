#include "College.hpp"

#include "cuTEST/Menu.hpp"

#include "Tester.hpp"

int main()
{
    Menu::Header( "PROJECT 3" );

    bool done = false;
    while ( !done )
    {
        int choice = Menu::ShowIntMenuWithPrompt( {"Run tests", "Run program", "Quit"} );

        if ( choice == 1 )
        {
            Tester tester;
            tester.Start();
        }
        else if ( choice == 2 )
        {
            College college;
            college.Run();
        }
        else
        {
            done = true;
        }
    }
    return 0;
}
