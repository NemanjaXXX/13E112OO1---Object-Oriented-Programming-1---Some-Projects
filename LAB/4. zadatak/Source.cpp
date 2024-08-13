#include "Artikal.h"
#include "Paket.h"

Roba* ucitaj() {
	cout << "Unesite oznaku robe koju hocete da ucitate:" << endl;
	cout << "A-Artikal" << endl << "P-Paket" << endl;
	char izbor; cin >> izbor;

	Artikal* a;
	Paket* p;
	Roba* r;
	switch (izbor) {
	case 'A':
		cout << "Unesite oznaku : ";
		char oznaka; cin >> oznaka;
		cout << "Unesite vrednost: ";
		double vrednost; cin >> vrednost;
		a = new Artikal(oznaka, vrednost);
		return a;
	case 'P':
		p = new Paket();
		cout << "Ubacivanje robe u paket" << endl;
		while (r = ucitaj())
			*p += r;
		return p;

	default: return nullptr;
	}
}

int main() {
	Roba* r;
	try {
		while (r = ucitaj()) {
			cout << *r << endl;
			delete r;
		}
	}
	catch (G_Index g) { cout << g << endl; }
	catch (...) { cout << "***Neocekivana greska!***"; }

	return 0;
}
