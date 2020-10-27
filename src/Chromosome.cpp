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

