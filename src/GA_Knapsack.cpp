#include <bits/stdc++.h>
#include "Problem.h"

Problem problem;

class Ga{
    std::bitset<100> ga;

    static std::bitset<100> randomga() {
        int i=100;
        std::string s;
        while(i > 0) {
            int r = rand();
            std::bitset<15> bs(r);
            s.append(bs.to_string());
            i-=15;
        }
        return std::bitset<100>(s);
    }

public :
    Ga(std::bitset<100> *ga = nullptr) {
        if(ga)
            this->ga = *ga;
        else
            this->ga = randomga();
    }

    std::bitset<100> getGa() const {
        return ga;
    }

    void mutationGa(int i) {
        ga.flip(i);
    }
};

double fitness(const Ga & ga) {
    std::bitset<100> g = ga.getGa();
    double worth = 0;
    double load = 0;
    for(int i=0; i<100; ++i) {
           load += problem.items[i].getw() * g.test(i);
    }
    for(int i=0; i<100; ++i) {
           worth += problem.items[i].getp() * g.test(i);
    }
    return worth - (load > problem.W ? 550 : 0);
}

struct compare {
    bool operator() (const Ga* a, const Ga* b) const{
        return fitness(*a) > fitness(*b);
    }
};

double meanFit(std::set<Ga*> gas) {
    double mean = 0;
    for(Ga * g : gas) {
        mean += fitness(*g);
    }
    return mean / gas.size();
}

std::pair<std::vector<Ga*>, std::vector<Ga*> > select(std::set<Ga*> gas, int n) {
    std::set<Ga*, compare> orderGas;
    for(Ga* g : gas) {
        orderGas.insert(g);
    }
//    std::cout << orderGas.size() << "\n";
    std::set<Ga*, compare>::iterator iter = orderGas.begin();
    std::pair<std::vector<Ga*>, std::vector<Ga*> > ret;
    for(int i=0; i<n; ++i) {
        ret.first.push_back(*iter);
        ++iter;
    }
    while(iter != orderGas.end()) {
        ret.second.push_back(*iter);
        ++iter;
    }
    return ret;
}

Ga * crossover(Ga & a, Ga & b) {
    std::bitset<100> rmask;
    double rate = 0.4;
    for(int i=0; i<100; ++i) {
        double r = (double) rand() / RAND_MAX;
        if(r<rate) {
            rmask[i] = 1;
        }
    }
//    std::cout << rmask;
    std::bitset<100> ret;
    std::bitset<100> aga, bga;
    aga = a.getGa();
    bga = b.getGa();
    for(int i=0; i<100; ++i) {
        if(rmask.test(i)) {
            ret[i] = aga[i];
        }
        else {
            ret[i] = bga[i];
        }
    }
    return new Ga(&ret);
}

Ga & mutation(Ga & ga) {
    std::bitset<100> rmask;
    double rate = 0.043;
    for(int i=0; i<100; ++i) {
        double r = (double) rand() / RAND_MAX;
        if(r<rate) {
            rmask[i] = 1;
        }
    }
//    std::cout << rmask;
    std::bitset<100> ret;
    for(int i=0; i<100; ++i) {
        if(rmask.test(i)) {
            ga.mutationGa(i);
        }
    }
    return ga;
}

//int main() {
//    Problem p;
//    std::cout << p.W << "\n";
//    double sum = 0;
//    for(auto item : p.items) {
//        sum += item.getw();
//        std::cout << item.getw() << " and "  << item.getp() << "\n";
//    }
//    std::cout << sum << "\n";
//    return 0;
//}

int main(int argc, char ** argv) {
    std::ios_base::sync_with_stdio(false);

    srand(std::time(0));
//    srand(484687641);

    std::set<Ga*> gas;
    for(int i=0; i<15; ++i) {
        gas.insert(new Ga());
    }
    double lastFitMean;
    double crrFitMean = meanFit(gas);
    int times = 1;
    do {
        lastFitMean = crrFitMean;
        auto selGas = select(gas, 5);
        for(auto i : selGas.second) {
            gas.erase(i);
            delete i;
        }
        selGas.second.clear();

    //    std::cout << selGas.first.size() << "\n";
        for(auto a : selGas.first) {
            for(auto b : selGas.first) {
                if(a!=b)
                    continue;
                Ga * nGa = crossover(*a, *b);
                mutation(*nGa);
                gas.insert(nGa);
//                std::cout << nGa->getGa() << " : " << fitness(*nGa) << "\n";
            }
        }
        selGas.first.clear();
        crrFitMean = meanFit(gas);
    } while(times++ < 500000 && abs(crrFitMean-lastFitMean)/lastFitMean>0.005);

    // Print The First Ga
    auto theOneGa = select(gas, 1);
    Ga * g = *(theOneGa.first.begin());
    std::cout << fitness(*g) << " : " << g->getGa() << "\n";

    for(auto i : gas) {
        delete i;
    }

    return 0;
}
