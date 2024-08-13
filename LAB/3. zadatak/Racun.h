#ifndef RACUN_H
#define RACUN_H

#include <string>
#include"Stavka.h"
#include"Zbirka.h"

class Racun {
	string ime;
	long int datum;
	Zbirka<Stavka> spisak;
public:
	Racun(string imee, long int datumm, int k) : ime(imee), spisak(k) {
		datum = datumm;
	}
	Racun& dodajStavku(const Stavka& s) {
		spisak.dodaj(s);
		return *this;
	}
	double ukupnaVrednost() const;
	friend ostream& operator<< (ostream& it, const Racun& r);
};
#endif
