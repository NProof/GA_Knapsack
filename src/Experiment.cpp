#include "Experiment.h"

Experiment::Experiment()
{
    times = 0;
    table = std::vector<Record> ();
}

long Experiment::gettimes()
{
    return times;
}

void Experiment::addRecord(Record record)
{
    ++(this->times);
    this->table.push_back(record);
}

double Experiment::calBest()
{
    double best, output;
    int i = 0;
    output = table[i].getOutput();
    best = output;
    ++i;
    for(; i < table.size(); ++i)
    {
        output = table[i].getOutput();
        if(output < best)
        {
            best = output;
        }
    }
    return best;
}
