#include"Paket.h"

double Paket::vrednost() const {
	double s = 0;
	for (int i = 0; i < zbirka.dohvatiDuz(); i++)
		s += zbirka[i]->vrednost();
	return s;
}

void Paket::pisi(ostream& it) const {
	it << "[";
	int i;
	for (i = 0; i < zbirka.dohvatiDuz() - 1; i++) {
		it << *zbirka[i] << ", ";
	}
	it << *zbirka[i] << "]";
}
