//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <set>

#include "Problem.h"
#include "Chromosome.h"

int main() {
    std::ios_base::sync_with_stdio(false);

    Problem p;

    std::set<Chromosome*> group ;
    for(int i=0; i<15; ++i) {
        group.insert(new Chromosome(nullptr));
    }
    for(auto individual : group) {
        std::cout << individual->getbody() << "\n";
    }
    return 0;
}
