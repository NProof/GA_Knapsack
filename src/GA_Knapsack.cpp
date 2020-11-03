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
    Experiment experiment(p);
    experiment.runAlgorithm();
    std::cout << experiment << "\n";
    return 0;
}
