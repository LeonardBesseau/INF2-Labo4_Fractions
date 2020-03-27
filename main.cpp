#include <iostream>
#include "Fraction.h"

int main() {
    std::cout << "Test valid constructor" << std::endl;
    Fraction<int > a(-4, 8);
    Fraction<unsigned > b(-4, 8);
    Fraction<long > c(-4, 8);
    Fraction<unsigned long > d(-4, 8);
    Fraction<long long> e(-4, 8);
    Fraction<unsigned long long> f(-4, 8);


    return 0;
}
