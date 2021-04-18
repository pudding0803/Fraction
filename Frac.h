#ifndef FRAC_H
#define FRAC_H

#include <iostream>
using namespace std;

class Frac {
public:
    Frac();
    Frac(int);
    // Frac(int, int);
    // Frac(const Frac &);
    Frac(const Frac &, const Frac &);
    void showStatus();
    void reduce();
    static int gcd(int, int);
    static int lcm(int, int);
    // friend istream &operator>>(istream &, Frac &);
    friend ostream &operator<<(ostream &, const Frac &);
    friend Frac operator+(const Frac &, const Frac &);
    friend Frac operator-(const Frac &, const Frac &);
    friend Frac operator*(const Frac &, const Frac &);
    friend Frac operator/(const Frac &, const Frac &);
    friend void operator+=(Frac &, const Frac &);
    friend void operator-=(Frac &, const Frac &);
    friend void operator*=(Frac &, const Frac &);
    friend void operator/=(Frac &, const Frac &);
    friend bool operator==(const Frac &, const Frac &);
    friend bool operator!=(const Frac &, const Frac &);
    friend bool operator>=(const Frac &, const Frac &);
    friend bool operator<=(const Frac &, const Frac &);
    friend bool operator>(const Frac &, const Frac &);
    friend bool operator<(const Frac &, const Frac &);
private:
    int numer;
    int denom;
    bool isInteger();
    bool isProper();
    bool isFinite();
};

#endif // FRAC_H
