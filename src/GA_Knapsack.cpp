//#include <bits/stdc++.h>
#include <iostream>

#include "Problem.h"
#include "Experiment.h"

std::ostream& operator<<(std::ostream& os, const Experiment& ex)
{
    os << ex.gettimes() << " and " << ex.calBest();
    return os;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    Problem p;
    Experiment experiment(p);
    experiment.runAlgorithm();
    std::cout << experiment << "\n";
    return 0;
}
