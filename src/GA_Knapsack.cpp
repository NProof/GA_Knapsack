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
        exps.push_back(new Experiment(p));
        Experiment experiment = *exps.at(i);
        experiment.runAlgorithm();
        summaryfile << experiment;
//        std::ofstream file;
//        std::string name = "output";
//        file.open(name+std::to_string(i+1)+".csv");
//        experiment.reportToFile(file);
//        file.close();
    }
    summaryfile.close();
/*
 *     std::ofstream file;
 *     file.open("avg.csv");
 *     std::vector<Record> tables[SAMPLES];
 *     std::vector<Record>::iterator iter[SAMPLES];
 *     double betters[SAMPLES];
 *     long conuts = 1;
 *     for(int i=0; i<SAMPLES; ++i) {
 *         tables[i] = exps[i]->gettable();
 *         iter[i] = tables[i].begin();
 *         betters[i] = iter[i]->getOutput();
 *
 *         double avg = 0.0;
 *         for(int i=0; i<SAMPLES; ++i) {
 *             avg += betters[i];
 *         }
 *         avg /= SAMPLES;
 *
 *         file << conuts << "\t" << avg << "\n";
 *     }
 *     bool condition;
 *     while (true) {
 *         ++conuts;
 *         condition = false;
 *         for(int i=0; i<SAMPLES; ++i) {
 *             if(iter[i]!=tables[i].end()) {
 *                 condition = true;
 *                 ++iter[i];
 *                 if(iter[i]->getOutput()>betters[i])
 *                     betters[i] = iter[i]->getOutput();
 *             }
 *         }
 *         if(!condition)
 *             break;
 *
 *         double avg = 0.0;
 *         for(int i=0; i<SAMPLES; ++i) {
 *             avg += betters[i];
 *         }
 *         avg /= SAMPLES;
 *
 *         file << conuts << "\t" << avg << "\n";
 *     }
 *     file.close();
 */
    return 0;
}
