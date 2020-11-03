#ifndef EXPERIMENT_H_INCLUDED
#define EXPERIMENT_H_INCLUDED

#include <iostream>
#include <bitset>
#include <set>
#include <vector>
#include <ctime>
#include <bitset>
#include <fstream>
#include <map>

#include "Problem.h"
#include "Chromosome.h"
#include "Record.h"

class Problem;

class Experiment
{
    Problem & p;
    long times;
    std::vector<Record> table;
public:
    Experiment(Problem & p);

    friend std::ostream& operator<<(std::ostream& os, const Experiment& ex);

    long gettimes() const;

    std::vector<Record> gettable() const;

    void addRecord(Record record);

    double calBest() const;

    int runAlgorithm();

    int reportToFile(std::ofstream & ofs);
};

#endif // EXPERIMENT_H_INCLUDED
