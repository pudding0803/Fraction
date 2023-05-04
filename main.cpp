#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction f = 1;
    cout << f << endl;
    cout << endl;
    Fraction f1(1, 4), f2(8, 7), f3(3), f4(2, 6), f5(2);
    cout << f1 << endl;
	cout << f2 << endl;
	cout << f3 << endl;
	cout << f4 << endl;
	cout << endl;
	Fraction f6(-1, 6), f7(-2, 4), f8(-3, -4), f9(1, -5);
	cout << f6 << endl;
	cout << f7 << endl;
	cout << f8 << endl;
	cout << f9 << endl;
	cout << endl;
	Fraction f10(f1), f11(f2, f3), f12(f4, 8), f13(Fraction(f6, f7), Fraction(f8, f9));
	cout << f10 << endl;
	cout << f11 << endl;
	cout << f12 << endl;
	cout << f13 << endl;
	return 0;
}
