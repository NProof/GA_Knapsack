#include "Record.h"

Record::Record(std::bitset<100> input, double output) {
    this->input = input;
    this->output = output;
}

std::bitset<100> Record::getInput() const
{
    return input;
}

double Record::getOutput() const
{
    return output;
}
