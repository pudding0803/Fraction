#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int);
    // Fraction(int, int);
    // Fraction(const Fraction &);
    Fraction(const Fraction &, const Fraction &);
    void showStatus();
    void reduce();
    static int gcd(int, int);
    static int lcm(int, int);
    // friend istream &operator>>(istream &, Fraction &);
    friend ostream &operator<<(ostream &, const Fraction &);
    friend Fraction operator+(const Fraction &, const Fraction &);
    friend Fraction operator-(const Fraction &, const Fraction &);
    friend Fraction operator*(const Fraction &, const Fraction &);
    friend Fraction operator/(const Fraction &, const Fraction &);
    friend void operator+=(Fraction &, const Fraction &);
    friend void operator-=(Fraction &, const Fraction &);
    friend void operator*=(Fraction &, const Fraction &);
    friend void operator/=(Fraction &, const Fraction &);
    friend bool operator==(const Fraction &, const Fraction &);
    friend bool operator!=(const Fraction &, const Fraction &);
    friend bool operator>=(const Fraction &, const Fraction &);
    friend bool operator<=(const Fraction &, const Fraction &);
    friend bool operator>(const Fraction &, const Fraction &);
    friend bool operator<(const Fraction &, const Fraction &);
private:
    int numer;
    int denom;
    bool isInteger();
    bool isProper();
    bool isFinite();
};

#endif // FRACTION_H
