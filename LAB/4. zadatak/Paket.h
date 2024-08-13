#ifndef PAKET_H
#define PAKET_H

#include "Roba.h"
#include "Zbirka.h"

class Paket : public Roba {
	Zbirka<Roba> zbirka;
public:
	Paket() :zbirka() {}

	double vrednost() const override;
	Paket* kopija() const override {
		return new Paket(*this);
	}

	Paket& operator+= (Roba* r) {
		zbirka += r;
		return *this;
	}

private:
	void pisi(ostream& it) const override;

};
#endif