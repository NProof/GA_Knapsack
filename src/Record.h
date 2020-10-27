#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <bitset>

class Record
{
    std::bitset<100> input;
    double output;
public:
    Record(std::bitset<100>, double) ;

    std::bitset<100> getInput();
    double getOutput();
};

#endif // RECORD_H_INCLUDED
