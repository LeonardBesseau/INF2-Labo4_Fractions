//
// Created by leonard on 3/27/20.
//

#ifndef LABO4_FRACTIONS_FRACTIONIMPL_H
#define LABO4_FRACTIONS_FRACTIONIMPL_H

#include "Fraction.h"

template<typename T>
T gcd(T a, T b);

template<typename T>
T safeMultiply(T a, T b);

template<typename T>
T safeAddition(T a, T b);

template<typename T>
Fraction<T>::Fraction(T numerator, T denominator) try : numerator(numerator), denominator(denominator) {
    if (!this->denominator) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // If sign is at denominator set it on the numerator
    if (this->denominator < 0) {
        this->denominator *= -1;
        this->numerator *= -1;
    }
} catch (const std::invalid_argument &e) {
    throw;
}

template<typename T>
Fraction<T>::operator float() const {
    return (float) numerator / denominator;
}

template<typename T>
Fraction<T>::operator double() const {
    return (double) numerator / denominator;
}

template<typename T>
Fraction<T> Fraction<T>::simplify() const{
    T divisor = gcd(abs(numerator), abs(denominator));
    if (divisor == 1) {
        return *this;
    }

    return Fraction(numerator / divisor, denominator / divisor);
}

template<typename T>
bool Fraction<T>::operator==(const Fraction &rhs) const {
    Fraction<T> left = this->simplify();
    Fraction<T> right = rhs.simplify();
    return left.identite(right);
}

template<typename T>
Fraction<T> &Fraction<T>::operator+=(const Fraction<T> &rhs) {
    return *this;
}


template<typename T>
Fraction<T> &Fraction<T>::operator*=(const Fraction<T> &rhs) {
    Fraction left = this;
    Fraction right = rhs;
    T simplify = gcd(abs(left.numerator), abs(right.denominator));
    if(simplify == 1){
        left.numerator/=simplify;
        right.denominator/=simplify;
    }

    simplify = gcd(abs(right.numerator), abs(left.denominator));
    if(simplify == 1){
        right.numerator/=simplify;
        left.denominator/=simplify;
    }
    left.numerator = safeMultiply(left.numerator, right.numerator);
    left.denominator = safeMultiply(left.denominator, right.denominator);

    *this = left;
    return *this;
}

template<typename T>
bool Fraction<T>::identite(const Fraction<T> &rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template<typename T>
T safeMultiply(T a, T b) {
    T newNumerator = a * b;
    if (a != newNumerator / b) {
        throw std::overflow_error("Overflow in calculation detected");
    }
    return newNumerator;
}

template<typename T>
T safeAddition(T a, T b){
    if(std::numeric_limits<T>::is_signed){
        if(a > 0 && b > std::numeric_limits<T>::max() - a){
            throw std::overflow_error("Overflow in calculation detected");
        }else if(a < 0 && b < std::numeric_limits<T>::min() - a){
            throw std::underflow_error("Underflow in calculation detected");
        }
    }else{
        if(a > std::numeric_limits<T>::max()-b){
            throw std::overflow_error("Overflow in calculation detected");
        }
    }
}


template<typename T>
std::ostream &operator<<(std::ostream &lhs, const Fraction<T> &rhs) {
    lhs << rhs.numerator ;
    lhs << "/" ;
    lhs << rhs.denominator;
    return lhs;
}

template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs += rhs;
    return lhs;
}

template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs*= rhs;
    return lhs;
}

#endif //LABO4_FRACTIONS_FRACTIONIMPL_H
