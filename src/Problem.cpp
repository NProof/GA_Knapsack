#include "Problem.h"

Problem::Problem() {
    this->W = 275;
    for(int i=0; i<100; ++i) {
        this->items.push_back(Item((i/10)+1, (i/10)+6));
    }
}
