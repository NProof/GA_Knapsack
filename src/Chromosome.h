#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED

#include <bitset>
#include <vector>
#include <set>
#include <map>

class Chromosome {
    std::bitset<100> body;

    static std::bitset<100> randomBitset();

public :
    Chromosome(std::bitset<100> *);

    std::bitset<100> getbody() const;

    void mutationGa(int i) {
        body.flip(i);
    }
};

#endif // CHROMOSOME_H_INCLUDED
