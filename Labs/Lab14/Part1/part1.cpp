#include "part1.h"

#include <iostream>

using namespace std;

FileWriter::FileWriter(const string &filename) {
    m_output.open(filename);
}

FileWriter::~FileWriter() {
    m_output.close();
}

void FileWriter::Writer(const string &lineOfText) {
    m_output << lineOfText << endl;
}