#include "Problem.h"

Problem::Problem() {
    this->W = 275;
    for(int i=0; i<100; ++i) {
        this->items.push_back(Item((i/10)+1, (i/10)+6));
    }
}

//double Problem::fitness(Chromosome & input) {
//
//    std::bitset<100> g = input.getbody();
//    double worth = 0;
//    double load = 0;
//    for(int i=0; i<100; ++i) {
//           load += items[i].getw() * g.test(i);
//    }
//    for(int i=0; i<100; ++i) {
//           worth += items[i].getp() * g.test(i);
//    }
//    double val = worth - (load > W ? 550 : 0);
//    return val;
//}

double Problem::fitness(Chromosome & input, Experiment & experiment) {

    std::bitset<100> g = input.getbody();
    double worth = 0;
    double load = 0;
    for(int i=0; i<100; ++i) {
           load += items[i].getw() * g.test(i);
    }
    for(int i=0; i<100; ++i) {
           worth += items[i].getp() * g.test(i);
    }
    double val = worth - (load > W ? 550 : 0);
    experiment.addRecord(Record(g, val));
    return val;
}
