#include <iostream>
#include <cmath>
#include "Frac.h"
using namespace std;

// constructor
Frac::Frac() {
    this->numer = 0;
    this->denom = 1;
}

Frac::Frac(int numer) {
    this->numer = numer;
    this->denom = 1;
}

// Frac::Frac(int numer, int denom) {
//     this->numer = numer;
//     this->denom = denom;
//     reduce();
// }

// Frac::Frac(const Frac &x) {
//     this->numer = x.numer;
//     this->denom = x.denom;
// }

Frac::Frac(const Frac &x, const Frac &y) {
    this->numer = x.numer*y.denom;
    this->denom = x.denom*y.numer;
    reduce();
}

// public
void Frac::showStatus() {
    cout << "The fraction: ";
    cout << *this;
    cout << (this->isInteger() ? " (Integer)" : "") << endl;
    cout << (this->isProper() ? "Proper fraction" : "Improper fraction") << endl;
    cout << (this->isFinite() ? "Finite decimal" : "Circulating decimal") << endl;
    cout << endl;
}

int Frac::gcd(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    if(lhs == 0)
        return rhs;
    if(lhs < rhs)
        return (gcd(rhs, lhs));
    return (gcd(lhs%rhs, rhs));
}

int Frac::lcm(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    return lhs * rhs / gcd(lhs, rhs);
}

void Frac::reduce() {
    int gcdNum = gcd(this->numer, this->denom);
    this->numer /= gcdNum;
    this->denom /= gcdNum;
    if(this->denom < 0) {
        this->numer *= -1;
        this->denom *= -1;
    }
}

// istream &operator>>(istream &input, Frac &frac) {
//   input >> frac.numer >> frac.denom;
//   return input;
// }

ostream &operator<<(ostream &output, const Frac &frac) {
    Frac temp = frac;
    output << temp.numer;
    if(!temp.isInteger())
        output << "/" << temp.denom;
    return output;
}

Frac operator+(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac temp(x.numer*(lcmNum/x.denom) + y.numer*(lcmNum/y.denom), lcmNum);
    temp.reduce();
    return temp;
}

Frac operator-(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac temp(x.numer*(lcmNum/x.denom) - y.numer*(lcmNum/y.denom), lcmNum);
    temp.reduce();
    return temp;
}

Frac operator*(const Frac &x, const Frac &y) {
    Frac temp(x.numer*y.numer, x.denom*y.denom);
    temp.reduce();
    return temp;
}

Frac operator/(const Frac &x, const Frac &y) {
    Frac temp(x.numer*y.denom, x.denom*y.numer);
    temp.reduce();
    return temp;
}

void operator+=(Frac &x, const Frac &y) {
    x = x + y;
}

void operator-=(Frac &x, const Frac &y) {
    x = x - y;
}

void operator*=(Frac &x, const Frac &y) {
    x = x * y;
}

void operator/=(Frac &x, const Frac &y) {
    x = x / y;
}

bool operator==(const Frac &x, const Frac &y) {
    return x.numer == y.numer && x.denom == y.denom;
}

bool operator!=(const Frac &x, const Frac &y) {
    return x.numer != y.numer || x.denom != y.denom;
}

bool operator>=(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer >= tempY.numer;
}

bool operator<=(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer <= tempY.numer;
}

bool operator>(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer > tempY.numer;
}

bool operator<(const Frac &x, const Frac &y) {
    int lcmNum = Frac::lcm(x.denom, y.denom);
    Frac tempX(x.numer*(lcmNum/x.denom), lcmNum), tempY(y.numer*(lcmNum/y.denom), lcmNum);
    return tempX.numer < tempY.numer;
}


// private
bool Frac::isInteger() {
    return this->denom == 1;
}

bool Frac::isProper() {
    return this->numer < this->denom;
}

bool Frac::isFinite() {
    int temp = this->denom;
    while(!(temp % 2))
        temp /= 2;
    while(!(temp % 5))
        temp /= 5;
    return temp == 1;
}
