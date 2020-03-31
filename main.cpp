/* ---------------------------
Laboratoire : 04
Fichier : main.cpp
Auteur(s) : Besseau Cerottini Viotti
Date : 30-03-2020

But : Ce fichier teste l'implementation d'une classe fraction générique fournissant
      les opérations addition et multiplication

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */
#include <iostream>
#include "Fraction.h"

int main() {

    std::cout << "Test auxillary function " << std::endl;
    {
        std::cout << "gcd of " << 2 << " and " << 3 << " = " << gcd(2, 3) << " == 1" << std::endl;
        std::cout << "gcd of " << 2 << " and " << 6 << " = " << gcd(2, 6) << " == 3" << std::endl;

        std::cout << std::endl;

        std::cout << "lcm of " << 2 << " and " << 3 << " = " << lcm(2, 3) << " == 6" << std::endl;
        std::cout << "gcd of " << 21 << " and " << 6 << " = " << lcm(21, 6) << " == 42" << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test valid constructor" << std::endl;
        Fraction<int> a(4, 8);
        Fraction<long> c(-4, 8);
        Fraction<long long> e(-4, 8);
    }

    std::cout << std::endl;

    {
        std::cout << "Test invalid constructor" << std::endl;
        try {
            Fraction<int> a(3, 0);
            std::cerr << "Error Denominator with zero Failed" << std::endl;
            std::terminate();
        } catch (const std::invalid_argument &e) {
            std::cout << "Test denominator with 0 OK" << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Test invalid constructor" << std::endl;
        try {
            Fraction<int> a(3, -1);
            std::cerr << "Error Denominator negative Failed" << std::endl;
            std::terminate();
        } catch (const std::invalid_argument &e) {
            std::cout << "Test denominator negative OK" << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Test display" << std::endl;
        Fraction<int> a(-4, 8);
        std::cout << a << " should be same as " << -4 << "/" << 8 << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test conversion into float" << std::endl;
        Fraction<int> a(-4, 8);
        std::cout << (float) a << " = " << -0.5f << std::endl;
        Fraction<int> b(1, 3);
        std::cout << (float) b << " = " << 0.333333f << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test conversion into double" << std::endl;
        Fraction<int> a(-4, 8);
        std::cout << (double) a << " = " << -0.5 << std::endl;
        Fraction<int> b(1, 3);
        std::cout << (double) b << " = " << 0.333333 << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test simplify with modification" << std::endl;
        Fraction<int> a(3, 12);
        std::cout << "Before : " << a << std::endl;
        a = a.simplify();
        std::cout << "After  : " << a << std::endl;

        std::cout << "Test simplify without modification" << std::endl;
        Fraction<int> b(3, 8);
        std::cout << "Before : " << b << std::endl;
        b = b.simplify();
        std::cout << "After  : " << b << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test identite " << std::endl;
        Fraction<int> a(3, 12);
        Fraction<int> b(3, 12);
        std::cout << a << " " << b << " " << a.identite(b) << std::endl;
        Fraction<int> c(3, 12);
        Fraction<int> d(2, 11);
        std::cout << c << " " << d << " " << c.identite(d) << std::endl;
        Fraction<int> e(3, 12);
        Fraction<int> f(1, 4);
        std::cout << e << " " << f << " " << e.identite(f) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test == " << std::endl;
        Fraction<int> a(3, 12);
        Fraction<int> b(3, 12);
        std::cout << a << " " << b << " " << a.identite(b) << std::endl;
        Fraction<int> c(3, 12);
        Fraction<int> d(2, 11);
        std::cout << c << " " << d << " " << c.identite(d) << std::endl;
        Fraction<int> e(3, 12);
        Fraction<int> f(1, 4);
        std::cout << e << " " << f << " " << (e == f) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test addition same denominator" << std::endl;
        Fraction<int> a(3, 12);
        Fraction<int> b(3, 12);
        std::cout << a << " " << b << " " << a + b << " == 1/2" << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test addition different denominator" << std::endl;
        Fraction<int> a(2, 3);
        Fraction<int> b(3, 4);
        std::cout << a << " " << b << " " << a + b << " == 17/12" << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test addition overflow" << std::endl;
        try {
            Fraction<int> a(std::numeric_limits<int>::max(), 3);
            Fraction<int> b(3, 3);
            a += b;
            std::cerr << "Error No overflow detected" << std::endl;
            std::terminate();
        } catch (const std::overflow_error &e) {
            std::cout << "Overflow detected Ok" << std::endl;
        }
    }

    std::cout << std::endl;
//TODO
 /*   {
        std::cout << "Test addition simplification to avoid overflow " << std::endl;
        try {
            Fraction<int> a(std::numeric_limits<int>::max() - 1, 3);
            Fraction<int> b(3, 4);
            a += b;
            std::cout << "Simplification avoiding overflow Ok" << std::endl;
        } catch (const std::overflow_error &e) {
            std::cerr << "Error overflow detected" << std::endl;
            std::terminate();
        }
    }*/

    std::cout << std::endl;

    {
        std::cout << "Test addition underflow" << std::endl;
        try {
            Fraction<int> a(std::numeric_limits<int>::min(), 3);
            Fraction<int> b(-3, 3);
            a += b;
            std::cerr << "Error No Underflow detected" << std::endl;
            std::terminate();
        } catch (const std::underflow_error &e) {
            std::cout << "Underflow detected Ok" << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Test multiplication different denominator" << std::endl;
        Fraction<int> a(2, 3);
        Fraction<int> b(3, 2);
        std::cout << a << " " << b << " " << a * b << " == 1/1" << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << "Test multiplication same denominator" << std::endl;
        Fraction<int> a(1, 2);
        Fraction<int> b(1, 2);
        std::cout << a << " " << b << " " << a * b << " == 1/4" << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << "Test multiplication overflow" << std::endl;
        try {
            Fraction<int> a(std::numeric_limits<int>::max(), 3);
            Fraction<int> b(2, 3);
            a *= b;
            std::cerr << "Error No overflow detected" << std::endl;
            std::terminate();
        } catch (const std::overflow_error &e) {
            std::cout << "Overflow detected Ok" << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Test multiplication overflow" << std::endl;
        try {
            Fraction<int> a(std::numeric_limits<int>::max() - 1, 3);
            Fraction<int> b(2, 3);
            a *= b;
            std::cout << "Simplification avoiding overflow Ok" << std::endl;
        } catch (const std::overflow_error &e) {

            std::cerr << "Error overflow detected" << std::endl;
            std::terminate();
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Test multiplication overflow error immutable" << std::endl;
        Fraction<int> a(std::numeric_limits<int>::max(), 3);
        Fraction<int> b(2, 3);
        std::cout << a << " " << b << " == ";
        {
            try {
                a *= b;
                std::cerr << "Error No overflow detected" << std::endl;
                std::terminate();
            } catch (const std::overflow_error &e) {

            }
        }
        std::cout << a << " " << b << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << "Test addition overflow error immutable" << std::endl;
        Fraction<int> a(std::numeric_limits<int>::max(), 3);
        Fraction<int> b(2, 3);
        std::cout << a << " " << b << " == ";
        {
            try {
                a += b;
                std::cerr << "Error No underflow detected" << std::endl;
                std::terminate();
            } catch (const std::overflow_error &e) {

            }
        }
        std::cout << a << " " << b << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << "Test addition underflow error immutable" << std::endl;
        Fraction<int> a(std::numeric_limits<int>::min(), 3);
        Fraction<int> b(-2, 3);
        std::cout << a << " " << b << " == ";
        {
            try {
                a += b;
                std::cerr << "Error No overflow detected" << std::endl;
                std::terminate();
            } catch (const std::underflow_error &e) {

            }
        }
        std::cout << a << " " << b << std::endl;

    }

    std::cout << "All test ok" << std::endl;

    std::cout << std::endl;

    {
        const int numerator = 4;
        int denominator = 1;
        Fraction<int> result(numerator, denominator);
        int sign = -1;
        denominator += 2;
        size_t iter = 0;
        try {
            while (true) {
                Fraction<int> b(numerator * sign, denominator);
                result += b;
                sign *= -1;
                denominator += 2;
                std::cout << ++iter<<" "<<result << std::endl;
            }
        } catch (const std::overflow_error &e) {
            std::cout << result << " = " << (float) result << " " << (double) result << std::endl;
        }
    }

    std::cout << std::endl;

    {
        const int numerator = 4;
        int denominator = 1;
        Fraction<long long> result(numerator, denominator);
        int sign = -1;
        denominator += 2;
        size_t iter = 0;
        try {
            while (true) {
                Fraction<long long> b(numerator * sign, denominator);
                result += b;
                sign *= -1;
                denominator += 2;
                std::cout << ++iter<<" "<<result << std::endl;
            }
        } catch (const std::overflow_error &e) {
            std::cout << result << " = " << (float) result << " " << (double) result << std::endl;
        }
    }

    std::cout << std::endl;

    {
        const int numerator = 4;
        int denominator = 2;
        Fraction<int> result(3, 1);
        int sign = 1;
        size_t iter = 0;
        try {
            while (true) {
                int temp = denominator +1;
                denominator*=temp;
                ++temp;
                denominator*=temp;
                Fraction<int> b(numerator * sign, denominator);
                result += b;
                denominator = temp;
                sign *= -1;
                std::cout << ++iter<<" "<<result << std::endl;
            }
        } catch (const std::overflow_error &e) {
            std::cout << result << " = " << (float) result << " " << (double) result << std::endl;
        }
    }

    std::cout << std::endl;

    {
        const int numerator = 4;
        int denominator = 2;
        Fraction<long long> result(3, 1);
        int sign = 1;
        size_t iter = 0;
        try {
            while (true) {
                int temp = denominator +1;
                denominator*=temp;
                ++temp;
                denominator*=temp;
                Fraction<long long> b(numerator * sign, denominator);
                result += b;
                denominator = temp;
                sign *= -1;
                std::cout << ++iter<<" "<<result << std::endl;
            }
        } catch (const std::overflow_error &e) {
            std::cout << result << " = " << (float) result << " " << (double) result << std::endl;
        }
    }
    return 0;
}
