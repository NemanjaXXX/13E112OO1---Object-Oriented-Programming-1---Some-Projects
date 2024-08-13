#ifndef SKLADISTE_H
#define SKLADISTE_H

#include "Lista.h"
#include "Proizvod.h"


class Skladiste {
	Lista<Proizvod> lista;
	double trenVr, ukupVr;
public:
	Skladiste() :lista() { trenVr = ukupVr = 0; }
	Skladiste(const Skladiste& s) = delete;
	Skladiste& operator=(const Skladiste& s) = delete;

	Skladiste& dodaj(Proizvod* p) {
		lista.dodajNaKraj(p);
		trenVr += p->vrednost();
		ukupVr += p->vrednost();
		return *this;
	}
	Proizvod* uzmi() {
		Proizvod* p = lista.uzmiSaPocetka();
		trenVr -= p->vrednost();
		return p;
	}

	double trenVrednost()const { return trenVr; }
	double ukupVrednost()const { return ukupVr; }
	void anuliraj() { ukupVr = 0; trenVr = 0; }

	friend ostream& operator<<(ostream& it, const Skladiste& s) {
		return it << s.lista;
	}
};
#endif
