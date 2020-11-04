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

    void mutationGa(int);

    void carryIn(int);

    void carryOut(int);
};

std::pair<std::vector<Chromosome*>, std::vector<Chromosome*> > select(std::map<Chromosome*, double> gas, int n);
std::vector<Chromosome *> crossover(Chromosome & a, Chromosome & b);
Chromosome & mutation(Chromosome & ga);

#endif // CHROMOSOME_H_INCLUDED
