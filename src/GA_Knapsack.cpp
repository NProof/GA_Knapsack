#include <bits/stdc++.h>
#include "Problem.h"

int main() {
    Problem p;
    std::cout << p.W << "\n";
    double sum = 0;
    for(auto item : p.items) {
        sum += item.getw();
        std::cout << item.getw() << " and "  << item.getp() << "\n";
    }
    std::cout << sum << "\n";
    return 0;
}
