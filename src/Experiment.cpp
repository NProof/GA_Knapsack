#include "Experiment.h"

Experiment::Experiment(Problem & p)
:p(p)
{
    times = 0;
    table = std::vector<Record> ();
}

long Experiment::gettimes() const
{
    return times;
}

std::vector<Record> Experiment::gettable() const {
    return table;
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

int Experiment::runAlgorithm() {
    srand(std::time(0));

    std::set<Chromosome*> group ;
    for(int i=0; i<15; ++i) {
        group.insert(new Chromosome(nullptr));
    }
    for(auto individual : group) {
        double val = p.fitness(*individual, this);
        std::cout << individual->getbody() << " [F] : " << val << "\n";
    }
    for(auto i : group) {
        delete i;
    }
    return 0;
}

int Experiment::reportToFile(std::ofstream & ofs) {
    auto table = gettable();
    if(table.size() == 0) {
        ofs << "no message\n";
        return -1;
    }
    else {
        long i = 1;
        std::vector<Record>::iterator iter = table.begin();
        double upperval = iter->getOutput();
        ++iter;
        ofs << i << ", " << upperval << ", " << iter->getInput() << ", " << upperval << "\n";
        while(iter != table.end()) {
            ++i;
            double output = iter->getOutput();
            if(output > upperval)
                upperval = output;
            ofs << i << ", " << upperval << ", " << iter->getInput() << ", " << output << "\n";
            ++iter;
        }
    }
    return 0;
}
