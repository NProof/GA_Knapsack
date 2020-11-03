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
    std::map<Chromosome*, double> fitMaps;
    for(int i=0; i<15; ++i) {
        auto individual = new Chromosome(nullptr);
        group.insert(individual);
        double val = p.fitness(*individual, this);
        fitMaps.insert(std::make_pair(individual, val));
//        std::cout << individual->getbody() << " [F] : " << val << "\n";
    }

    auto selGas = select(fitMaps, 5);
    for(auto i : selGas.second) {
        fitMaps.erase(i);
        group.erase(i);
        delete i;
    }
    selGas.second.clear();

    double last5Mean;
    double crr5Mean = 0;
    long times = 1;

    for(auto chr : selGas.first) {
        crr5Mean += fitMaps[chr];
    }
    crr5Mean /= selGas.first.size();

    int acc = 0;
    do{
        ++times;
        last5Mean = crr5Mean;

        for(auto a : selGas.first) {
            for(auto b : selGas.first) {
                if(a!=b)
                    continue;
                Chromosome * newIndividual = crossover(*a, *b);
                mutation(*newIndividual);
                double val = p.fitness(*newIndividual, this);
                group.insert(newIndividual);
                fitMaps.insert(std::make_pair(newIndividual, val));
    //            std::cout << newIndividual->getGa() << " : " << fitness(*newIndividual) << "\n";
            }
        }

        selGas = select(fitMaps, 5);
        for(auto i : selGas.second) {
            fitMaps.erase(i);
            group.erase(i);
            delete i;
        }
        selGas.second.clear();

        crr5Mean = 0;
        for(auto chr : selGas.first) {
            crr5Mean += fitMaps[chr];
        }
        crr5Mean /= selGas.first.size();

        if (abs(crr5Mean - last5Mean) > 0.0000001)
            acc = 0;
        else
            ++acc;

    }
    while (times < 350000 && acc < 9999);

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
