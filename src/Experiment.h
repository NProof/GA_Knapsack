#ifndef EXPERIMENT_H_INCLUDED
#define EXPERIMENT_H_INCLUDED

#include <iostream>
#include <set>
#include <vector>
#include <bitset>

#include "Problem.h"
#include "Chromosome.h"
#include "Record.h"

class Experiment
{
    Problem & p;
    long times;
    std::vector<Record> table;
public:
    Experiment(Problem & p);

    friend std::ostream& operator<<(std::ostream& os, const Experiment& ex);

    long gettimes() const;

    void addRecord(Record record);

    double calBest() const;

    int runAlgorithm();
};

#endif // EXPERIMENT_H_INCLUDED
