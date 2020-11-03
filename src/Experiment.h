#ifndef EXPERIMENT_H_INCLUDED
#define EXPERIMENT_H_INCLUDED

#include <iostream>
#include <vector>
#include <bitset>

#include "Record.h"

class Experiment
{
    long times;
    std::vector<Record> table;
public:
    Experiment();

    friend std::ostream& operator<<(std::ostream& os, const Experiment& ex);

    long gettimes() const;

    void addRecord(Record record);

    double calBest() const;
};

#endif // EXPERIMENT_H_INCLUDED
