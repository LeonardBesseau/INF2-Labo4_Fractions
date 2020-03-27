#include <iostream>
#include "Fraction.h"

int main() {
    {
        std::cout << "Test valid constructor" << std::endl;
        Fraction<int> a(-4, 8);
        Fraction<long> c(-4, 8);
        Fraction<long long> e(-4, 8);
    }

    std::cout << std::endl;

    {
        std::cout << "Test invalid constructor" << std::endl;
        try {
            Fraction<int> a(3, 0);
            std::cout << "Error Denominator with zero Failed" << std::endl;
            std::terminate();
        } catch (const std::invalid_argument &e) {
            std::cout << "Test denominator with 0 OK" << std::endl;
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


    return 0;
}
