#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

class Record
{
    std::bitset<100> input;
    double output;
public:
    Record(std::bitset<100> input, double output) {
        this->input = input;
        this->output = output;
    }

    std::bitset<100> getInput();
    double getOutput();
};

#endif // RECORD_H_INCLUDED
