#ifndef PROBLEM_H_INCLUDED
#define PROBLEM_H_INCLUDED

#include <vector>

class Item {
    double w;
    double p;

public:
    Item(double w, double p) {
        this->w = w;
        this->p = p;
    }

    double getw() {return w;}
    double getp() {return p;}
};

class Problem {
public:
    double W;
    std::vector<Item> items;
    Problem();
};

#endif // PROBLEM_H_INCLUDED
