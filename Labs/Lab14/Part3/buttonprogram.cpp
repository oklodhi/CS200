#include <iostream>
using namespace std;

#include "Button.h"

int main()
{
    Button btn;
    btn.SetText( "Button!" );
    btn.Draw();

    btn.SetText( "Another Button!" );
    btn.Draw();

    return 0;

    cin.ignore();
    cin.get();
}
