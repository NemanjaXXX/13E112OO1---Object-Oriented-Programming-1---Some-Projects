#include"Racun.h"

double Racun::ukupnaVrednost() const {
	double s = 0;
	for (int i = 0; i < spisak.popunjeno(); i++)
		s += spisak[i]->velicina();
	return s;
}

ostream& operator<< (ostream& it, const Racun& r) {
	it << "Ime: " << r.ime << endl;
	it << "Datum: " << r.datum << endl;
	it << "Spisak:" << endl;
	it << r.spisak << endl;
	it << "Vrednost kupljene robe je: " << r.ukupnaVrednost() << endl;
	return it;
}


