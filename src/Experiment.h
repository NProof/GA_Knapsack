#ifndef EXPERIMENT_H_INCLUDED
#define EXPERIMENT_H_INCLUDED

#include <vector>
#include <bitset>

#include "Record.h"

class Experiment
{
    long times;
    std::vector<Record> table;
public:
    Experiment();

    long gettimes();

    void addRecord(Record record);

    double calBest();
};

#endif // EXPERIMENT_H_INCLUDED
