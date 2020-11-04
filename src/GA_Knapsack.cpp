//#include <bits/stdc++.h>
#include <iostream>
#include <string>

#include "Problem.h"
#include "Experiment.h"

#define SAMPLES 5

std::ostream& operator<<(std::ostream& os, const Experiment& ex)
{
    os << ex.gettimes() << ", " << ex.calBest() << "\n";
    return os;
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


//    for(int i=0; i<SAMPLES; ++i) {
//        Experiment experiment = *exps.at(i);
//        auto ta = experiment.gettable();
//        std::cout << ta.size() << "\n";
//    }

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
    avgfile << conuts << ",\t" << avg << "\n";
//    bool condition;
//    while (true) {
//        ++conuts;
//        condition = false;
//        for(int i=0; i<SAMPLES; ++i) {
//            if(iter[i]!=tables[i].end()) {
//                condition = true;
//            ++iter[i];
//            if(iter[i]->getOutput()>betters[i])
//                betters[i] = iter[i]->getOutput();
//            }
//        }
//        if(!condition)
//        break;
//
//        double avg = 0.0;
//        for(int i=0; i<SAMPLES; ++i) {
//            avg += betters[i];
//        }
//        avg /= SAMPLES;
//
//        avgfile << conuts << ",\t" << avg << "\n";
//    }
    avgfile.close();

    return 0;
}
