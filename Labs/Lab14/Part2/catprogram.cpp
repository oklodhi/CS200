#include <iostream>

using namespace std;

#include "Kitten.h"

int main () {
    Kitten happyCat ("Fluffy");
    happyCat.Display();

    Kitten angryCat ("Stripey");
    angryCat.Display();

    Kitten sadCat ("Sluggy");
    sadCat.Display();

    Kitten curiousCat ("Spotty");
    curiousCat.Display();


    // hi
    cout << "?";

    return 0;
}
