/* ---------------------------
Laboratoire : 04
Fichier : FractionImpl.h
Auteur(s) : Besseau Cerottini Viotti
Date : 30-03-2020

But : Ce fichier contient l'implémentation d'une classe fraction générique ainsi que ses fonctions associées

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */

#ifndef LABO4_FRACTIONS_FRACTIONIMPL_H
#define LABO4_FRACTIONS_FRACTIONIMPL_H

#include "Fraction.h"

/**
 * Computes the greatest common divisor
 * @tparam T an integer type for the value
 * @param a the first number
 * @param b the second number
 * @return the greatest common divisor between a and b. Returns 1 if a and b are prime
 */
template<typename T>
T gcd(T a, T b);

/**
 * Computes the least common multiple
 * @tparam T an integer type for the value
 * @param a the first number
 * @param b the second number
 * @return the least common multiple of a and b. Return a*b if both are prime
 * @throws overflow_error if an overflow occurs during calculation
 */
template<typename T>
T lcm(T a, T b);

/**
 * Computes a multiplication and verify for overflow
 * @tparam T an integer type for the value
 * @param a an integer
 * @param b an integer
 * @return a * b
 * @throws overflow_error if an overflow occurs during calculation
 */
template<typename T>
T safeMultiply(T a, T b);

/**
 * Computes an addition and verify for overflow and underflow
 * @tparam T an integer type for the value
 * @param a an integer
 * @param b an integer
 * @return a + b
 * @throws overflow_error if an overflow occurs during calculation
 * @throws underflow_error if an underflow occurs during calculation
 */
template<typename T>
T safeAddition(T a, T b);

template<typename T>
Fraction<T>::Fraction(T numerator, T denominator) try : numerator(numerator), denominator(denominator) {
    if (!this->denominator) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // If sign is at denominator set it on the numerator
    if (this->denominator < 0) {
        throw std::invalid_argument("Denominator cannot be negative");
    }
} catch (const std::invalid_argument &e) {
    throw;
}

template<typename T>
template<typename To>
Fraction<T>::operator To() const {
    return (To)numerator / (To) denominator;
}

template<typename T>
Fraction<T> Fraction<T>::simplify() const {
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
    Fraction left = this->simplify();
    Fraction right = rhs.simplify();
    if (left.denominator != right.denominator) {
        T common = lcm(left.denominator, right.denominator);
        left.numerator = safeMultiply(left.numerator, common/left.denominator);
        left.denominator = safeMultiply(left.denominator, common/left.denominator);
        right.numerator = safeMultiply(right.numerator, common / right.denominator);
    }

    left.numerator = safeAddition(left.numerator, right.numerator);

    *this = left.simplify();
    return *this;
}


template<typename T>
Fraction<T> &Fraction<T>::operator*=(const Fraction<T> &rhs) {
    Fraction left = *this;
    Fraction right = rhs;
    T simplify = gcd(abs(left.numerator), abs(right.denominator));
    if (simplify != 1) {
        left.numerator /= simplify;
        right.denominator /= simplify;
    }

    simplify = gcd(abs(right.numerator), abs(left.denominator));
    if (simplify != 1) {
        right.numerator /= simplify;
        left.denominator /= simplify;
    }
    left.numerator = safeMultiply(left.numerator, right.numerator);
    left.denominator = safeMultiply(left.denominator, right.denominator);

    *this = left.simplify();
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
T lcm(T a, T b) {
    return safeMultiply(a, b) / gcd(a, b);
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
T safeAddition(T a, T b) {
    if (std::numeric_limits<T>::is_signed) {
        if (a > 0 && b > std::numeric_limits<T>::max() - a) {
            throw std::overflow_error("Overflow in calculation detected");
        } else if (a < 0 && b < std::numeric_limits<T>::min() - a) {
            throw std::underflow_error("Underflow in calculation detected");
        }
    } else {
        if (a > std::numeric_limits<T>::max() - b) {
            throw std::overflow_error("Overflow in calculation detected");
        }
    }
    return a + b;
}


template<typename T>
std::ostream &operator<<(std::ostream &lhs, const Fraction<T> &rhs) {
    return lhs << rhs.numerator << "/" << rhs.denominator;
}

template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs += rhs;
    return lhs;
}

template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs) {
    lhs *= rhs;
    return lhs;
}



#endif //LABO4_FRACTIONS_FRACTIONIMPL_H
