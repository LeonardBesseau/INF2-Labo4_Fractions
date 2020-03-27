//
// Created by leonard on 3/27/20.
//

#ifndef LABO4_FRACTIONS_FRACTION_H
#define LABO4_FRACTIONS_FRACTION_H

#include <stdexcept>
#include <iostream>
#include <limits>

template<typename T>
class Fraction;

template<typename T>
std::ostream &operator<<(std::ostream &lhs, const Fraction<T> &rhs);

template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs);

template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs);


template<typename T>
class Fraction {
    friend std::ostream &operator<<<T>(std::ostream &lhs, const Fraction<T> &rhs);

    friend Fraction<T> operator+<T>(Fraction<T> lhs, const Fraction<T> &rhs);

    friend Fraction<T> operator*<T>(Fraction<T> lhs, const Fraction<T> &rhs);

public:
    Fraction<T>(T numerator, T denominator);

    Fraction<T> simplify();

    explicit operator float() const;

    explicit operator double() const;

    bool identite(const Fraction<T> &rhs) const;

    bool operator==(const Fraction<T> &rhs) const;

    Fraction<T> &operator+=(const Fraction<T> &rhs);

    Fraction<T> &operator*=(const Fraction<T> &rhs);


private:
    T numerator;
    T denominator;


};


#include "FractionImpl.h"


#endif //LABO4_FRACTIONS_FRACTION_H
