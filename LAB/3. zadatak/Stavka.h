#ifndef STAVKA_H
#define STAVKA_H

#include <string>
#include"Element.h"

class Stavka : public Element {
	string naziv;
	double cena, kol;
public:
	Stavka(string nazivv, double cenaa, double koll) : naziv(nazivv) {
		cena = cenaa; kol = koll;
	}
	double velicina() const override { return cena * kol; }
	Stavka* kopija() const override {
		return new Stavka(*this);
	}
private:
	void pisi(ostream& it) const override {
		it << "Naziv: " << naziv << " Cena: " << cena << " Kolicina: " << kol << " Vrednost: " << cena * kol << endl;
	}
};
#endif