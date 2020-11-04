//#include <bits/stdc++.h>
#include <iostream>
#include <string>
//#include <bitset>

#include "Problem.h"
#include "Experiment.h"

#define SAMPLES 100

std::ostream& operator<<(std::ostream& os, const Experiment& ex)
{
    std::vector<Record> table = ex.gettable();
    Record record = table.at(0);
    std::bitset<100> bestInd = record.getInput();
    double bestFit = record.getOutput();
    long last = 0;
    long crru = 1;
    for(; crru<ex.gettimes(); ++crru) {
        record = table.at(crru);
        double temp = record.getOutput();
        if(temp > bestFit) {
            last = crru;
            bestInd = record.getInput();
            bestFit = temp;
        }
    }
    int classItems[10] = {0};
    for(int i=0; i<100; ++i) {
        if(bestInd.test(i))
            ++classItems[(i/10)];
    }
//    os << bestFit << ", " << last + 1 << ", " << crru << ", " << bestInd << "\n";
    os << bestFit << ", " << last + 1 << ", " << crru;
    for(int i=0; i<10; ++i) {
        os << ", " << classItems[i];
    }
    return os << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);

    Problem p;
    std::vector<Experiment *> exps = std::vector<Experiment *>();
//    exps = (Experiment **)malloc(sizeof(Experiment*)*SAMPLES);
    std::ofstream summaryfile;
    summaryfile.open("sumInfo.csv");
    for(int i=0; i<SAMPLES; ++i) {
        Experiment * ptr_exp = new Experiment(p);
        exps.push_back(ptr_exp);
        ptr_exp->runAlgorithm();
        summaryfile << *ptr_exp;

//        std::ofstream file;
//        std::string name = "output";
//        file.open(name+std::to_string(i+1)+".csv");
//        ptr_exp->reportToFile(file);
//        file.close();
    }
    summaryfile.close();

    std::ofstream avgfile;
    avgfile.open("avg.csv");

    std::vector<Record> tables[SAMPLES];
    std::vector<Record>::iterator iter[SAMPLES];
    double betters[SAMPLES];
    long conuts = 1;
    double avg = 0.0;
    for(int i=0; i<SAMPLES; ++i) {
        tables[i] = exps.at(i)->gettable();
        iter[i] = tables[i].begin();
        betters[i] = iter[i]->getOutput();
    }
    for(int i=0; i<SAMPLES; ++i) {
        avg += betters[i];
    }
    avg /= SAMPLES;
//
    avgfile << conuts << "," << avg << "\n";
    bool condition;
    while (true) {
        ++conuts;
        condition = false;
        for(int i=0; i<SAMPLES; ++i) {
            if(iter[i]!=tables[i].end()) {
                condition = true;
            ++iter[i];
            if(iter[i]->getOutput()>betters[i])
                betters[i] = iter[i]->getOutput();
            }
        }
        if(!condition)
        break;

        double avg = 0.0;
        for(int i=0; i<SAMPLES; ++i) {
            avg += betters[i];
        }
        avg /= SAMPLES;

        avgfile << conuts << "," << avg << "\n";
    }
    avgfile.close();

    return 0;
}
