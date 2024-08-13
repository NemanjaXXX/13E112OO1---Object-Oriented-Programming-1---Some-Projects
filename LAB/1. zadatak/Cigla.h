#ifndef CIGLA_H
#define CIGLA_H

#include "Proizvod.h"
using namespace std;

class Cigla : public Proizvod {
	double a, b, c;
public:
	Cigla(double cenaa, double aa, double bb, double cc) : Proizvod(cenaa) {
		a = aa; b = bb; c = cc;
	}
	double vrednost() const override {
		return a * b * c * dohvatiCenu();
	}
	Cigla* kopija()const override {
		return new Cigla(*this);
	}
private:
	void pisi(ostream& it) const override {
		it << "C ( ";
		Proizvod::pisi(it);
		it << ", " << a << ", " << b << ", " << c << ")";
	}
};
#endif
