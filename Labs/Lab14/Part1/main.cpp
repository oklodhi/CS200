#include <iostream>
#include <string>

#include "part1.h"

using namespace std;

int main() {
    string fileName, text;

    cout << "File to write to =: \t";
    cin >> fileName;

    FileWriter writer(fileName + ".txt");

    cout << "Enter a line of text or STOP to quit." << endl << endl;

    while ( text != "STOP") {
        //cin.ignore();
        getline(cin, text);
        writer.Writer(text);
    }
}
