#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;

// constructor
Fraction::Fraction() {
    this->numer = 0;
    this->denom = 1;
}

Fraction::Fraction(int numer) {
    this->numer = numer;
    this->denom = 1;
}

// Fraction::Fraction(int numer, int denom) {
//     this->numer = numer;
//     this->denom = denom;
//     reduce();
// }

// Fraction::Fraction(const Fraction &x) {
//     this->numer = x.numer;
//     this->denom = x.denom;
// }

Fraction::Fraction(const Fraction &x, const Fraction &y) {
    this->numer = x.numer*y.denom;
    this->denom = x.denom*y.numer;
    reduce();
}

// public
void Fraction::showStatus() {
    cout << "The fraction: ";
    cout << *this;
    cout << (this->isInteger() ? " (Integer)" : "") << endl;
    cout << (this->isProper() ? "Proper fraction" : "Improper fraction") << endl;
    cout << (this->isFinite() ? "Finite decimal" : "Circulating decimal") << endl;
    cout << endl;
}

int Fraction::gcd(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    if(lhs == 0)
        return rhs;
    if(lhs < rhs)
        return (gcd(rhs, lhs));
    return (gcd(lhs%rhs, rhs));
}

int Fraction::lcm(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    return lhs * rhs / gcd(lhs, rhs);
}

void Fraction::reduce() {
    int gcdNum = gcd(this->numer, this->denom);
    this->numer /= gcdNum;
    this->denom /= gcdNum;
    if(this->denom < 0) {
        this->numer *= -1;
        this->denom *= -1;
    }
}

// istream &operator>>(istream &input, Fraction &frac) {
//   input >> frac.numer >> frac.denom;
//   return input;
// }

ostream &operator<<(ostream &output, const Fraction &frac) {
    Fraction temp = frac;
    output << temp.numer;
    if(!temp.isInteger())
        output << "/" << temp.denom;
    return output;
}

Fraction operator+(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction temp(x.numer*(lcmNum/x.denom) + y.numer*(lcmNum/y.denom), lcmNum);
    temp.reduce();
    return temp;
}

Fraction operator-(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction temp(x.numer*(lcmNum/x.denom) - y.numer*(lcmNum/y.denom), lcmNum);
    temp.reduce();
    return temp;
}

Fraction operator*(const Fraction &x, const Fraction &y) {
    Fraction temp(x.numer*y.numer, x.denom*y.denom);
    temp.reduce();
    return temp;
}

Fraction operator/(const Fraction &x, const Fraction &y) {
    Fraction temp(x.numer*y.denom, x.denom*y.numer);
    temp.reduce();
    return temp;
}

void operator+=(Fraction &x, const Fraction &y) {
    x = x + y;
}

void operator-=(Fraction &x, const Fraction &y) {
    x = x - y;
}

void operator*=(Fraction &x, const Fraction &y) {
    x = x * y;
}

void operator/=(Fraction &x, const Fraction &y) {
    x = x / y;
}

bool operator==(const Fraction &x, const Fraction &y) {
    return x.numer == y.numer && x.denom == y.denom;
}

bool operator!=(const Fraction &x, const Fraction &y) {
    return x.numer != y.numer || x.denom != y.denom;
}

bool operator>=(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer >= tempY.numer;
}

bool operator<=(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer <= tempY.numer;
}

bool operator>(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer > tempY.numer;
}

bool operator<(const Fraction &x, const Fraction &y) {
    int lcmNum = Fraction::lcm(x.denom, y.denom);
    Fraction tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer < tempY.numer;
}


// private
bool Fraction::isInteger() {
    return this->denom == 1;
}

bool Fraction::isProper() {
    return this->numer < this->denom;
}

bool Fraction::isFinite() {
    int temp = this->denom;
    while(!(temp % 2))
        temp /= 2;
    while(!(temp % 5))
        temp /= 5;
    return temp == 1;
}
