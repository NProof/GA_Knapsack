#include "Record.h"

Record::Record(std::bitset<100> input, double output) {
    this->input = input;
    this->output = output;
}

double Record::getInput()
{
    return input;
}

double Record::getOutput()
{
    return output;
}
