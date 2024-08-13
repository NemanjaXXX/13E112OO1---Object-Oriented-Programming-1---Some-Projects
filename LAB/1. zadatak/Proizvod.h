#ifndef PROIZVOD_H
#define PROIZVOD_H

#include <iostream>
using namespace std;

class Proizvod {
	double cena;
public:
	explicit Proizvod(double cenaa) { cena = cenaa; }
	virtual ~Proizvod() {}

	double dohvatiCenu() const { return cena; }

	virtual double vrednost() const = 0;
	virtual Proizvod* kopija() const = 0;
protected:
	virtual void pisi(ostream& it) const { it << cena; }
	friend ostream& operator<< (ostream& it, const Proizvod& p) {
		p.pisi(it); return it;
	}
};

#endif