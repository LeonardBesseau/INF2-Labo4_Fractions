/* ---------------------------
Laboratoire : 04
Fichier : Fraction.h
Auteur(s) : Besseau Cerottini Viotti
Date : 30-03-2020

But : Ce fichier contient les déclarations d'une classe fraction générique ainsi que ses fonctions associées

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */

#ifndef LABO4_FRACTIONS_FRACTION_H
#define LABO4_FRACTIONS_FRACTION_H

#include <stdexcept>
#include <iostream>
#include <limits>

/**
 * Generic fraction
 * Capable of simplifying, equality test, addition, multiplication, display on the standard output
 * @tparam T an integer type, the type of the numerator and denominator of the fraction
 */
template<typename T>
class Fraction;

/**
 * Display the fraction on the standard output as numerator/denominator
 * @tparam T an integer type, the type of the numerator and denominator of the fraction
 * @param lhs the standard output stream
 * @param rhs the fraction to display
 * @return the standard output stream
 */
template<typename T>
std::ostream &operator<<(std::ostream &lhs, const Fraction<T> &rhs);

/**
 * Operator for addition
 * @tparam T an integer type, the type of the numerator and denominator of the fraction
 * @param lhs a Fraction
 * @param rhs a Fraction
 * @return lhs + rhs
 * @throws std::overflow_error if an overflow occurs during calculation
 * @throws std::overflow_error if an underflow occurs during calculation
 */
template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T> &rhs);

/**
 * operator for multiplication
 * @tparam T an integer type, the type of the numerator and denominator of the fraction
 * @param lhs a Fraction
 * @param rhs a Fraction
 * @return lhs*rhs
 * @throws std::overflow_error if an overflow occurs during calculation
 */
template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T> &rhs);


template<typename T>
class Fraction {
    friend std::ostream &operator<<<T>(std::ostream &lhs, const Fraction<T> &rhs);

    friend Fraction<T> operator+<T>(Fraction<T> lhs, const Fraction<T> &rhs);

    friend Fraction<T> operator*<T>(Fraction<T> lhs, const Fraction<T> &rhs);

public:
    /**
     * Construct a new fraction
     * @param numerator a type T
     * @param denominator a type T must be positive if T is signed
     * @throws std::invalid_argument if the denominator <= 0
     */
    Fraction<T>(T numerator, T denominator);

    /**
     * Get the simplified form of the fraction
     * @return a Fraction in simplified form
     */
    Fraction<T> simplify() const;

    template<typename To>
    explicit operator To() const;


    /**
     * A strict comparison function for the fraction
     * @param rhs the other fraction to compare with
     * @return true if both fraction are the same (same numerator and denominator), false otherwise
     */
    bool identite(const Fraction<T> &rhs) const;

    /**
     * A loose comparison operator for the fraction
     * @param rhs the other fraction to compare with
     * @return if both fraction are the same (in simplified form), false otherwise
     */
    bool operator==(const Fraction<T> &rhs) const;

    /**
     * Addition operator
     * @param rhs the other fraction to add
     * @return this+rhs
     * @throws std::overflow_error if an overflow occurs during calculation
     * @throws std::overflow_error if an underflow occurs during calculation
     */
    Fraction<T> &operator+=(const Fraction<T> &rhs);

    /**
     * Multiplication operator
     * @param rhs the other fraction to multiply by
     * @return this*rhs
     * @throws std::overflow_error if an overflow occurs during calculation
     */
    Fraction<T> &operator*=(const Fraction<T> &rhs);


private:
    T numerator;
    T denominator;


};


#include "FractionImpl.h"


#endif //LABO4_FRACTIONS_FRACTION_H
