#include "Chromosome.h"

std::bitset<100> Chromosome::randomBitset(){
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

Chromosome::Chromosome(std::bitset<100> *ptr_body = nullptr) {
    if(ptr_body)
        this->body = *ptr_body;
    else
        this->body = randomBitset();
}

std::bitset<100> Chromosome::getbody() const {
    return body;
}

void Chromosome::mutationGa(int i){
    body.flip(i);
}

std::pair<std::vector<Chromosome*>, std::vector<Chromosome*> > select(std::map<Chromosome*, double> gas, int n) {
    auto cmp = [](std::pair<Chromosome*, double> a, std::pair<Chromosome*, double> b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    std::set<std::pair<Chromosome*, double>, decltype(cmp)> orderGas(cmp);
    for(std::pair<Chromosome*, double> g : gas) {
        orderGas.insert(g);
    }
//    std::cout << "orderGas.size() : " << orderGas.size() << "\n";
    auto iter = orderGas.begin();
    std::pair<std::vector<Chromosome*>, std::vector<Chromosome*> > ret;
    for(int i=0; i<n; ++i) {
        ret.first.push_back(iter->first);
        ++iter;
    }
    while(iter != orderGas.end()) {
        ret.second.push_back(iter->first);
        ++iter;
    }
    return ret;
}

Chromosome * crossover(Chromosome & a, Chromosome & b) {
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
    aga = a.getbody();
    bga = b.getbody();
    for(int i=0; i<100; ++i) {
        if(rmask.test(i)) {
            ret[i] = bga[i];
        }
        else {
            ret[i] = aga[i];
        }
    }
    return new Chromosome(&ret);
}

Chromosome & mutation(Chromosome & ga) {
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
