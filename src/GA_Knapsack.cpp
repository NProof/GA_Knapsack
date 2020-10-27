//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <set>

#include "Problem.h"
#include "Chromosome.h"
#include "Experiment.h"

int main() {
    std::ios_base::sync_with_stdio(false);

    Problem p;
    Experiment experiment;

    std::set<Chromosome*> group ;
    for(int i=0; i<15; ++i) {
        group.insert(new Chromosome(nullptr));
    }
    for(auto individual : group) {
        std::cout << individual->getbody() << " [F] : " << p.fitness(*individual) << "\n";
    }
    return 0;
}
