#ifndef KITTEN_H_INCLUDED
#define KITTEN_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Kitten
{
    public:
    Kitten( string name );
    void Display();

    private:
    string m_name;
    static int m_kittenCount;
};

#endif // KITTEN_H_INCLUDED
