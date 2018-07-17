#ifndef LAB14_PART1_H
#define LAB14_PART1_H

#include <string>
#include <fstream>

using namespace std;

class FileWriter {
    public:
        FileWriter (const string& filename);
        ~FileWriter();

        void Writer(const string& lineOfText);

    private:
        fstream m_output;
};

#endif //LAB14_PART1_H
