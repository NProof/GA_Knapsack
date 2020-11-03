#include "Experiment.h"

Experiment::Experiment()
{
    times = 0;
    table = std::vector<Record> ();
}

std::ostream& operator<<(std::ostream& os, const Experiment& ex)
{
    os << ex.gettimes() << " and " << ex.calBest();
    return os;
}

long Experiment::gettimes() const
{
    return times;
}

void Experiment::addRecord(Record record)
{
    ++(this->times);
    this->table.push_back(record);
}

double Experiment::calBest() const
{
    double best, output;
    int i = 0;
    output = table[i].getOutput();
    best = output;
    ++i;
    for(; i < (int)table.size(); ++i)
    {
        output = table[i].getOutput();
        if(output > best)
        {
            best = output;
        }
    }
    return best;
}
