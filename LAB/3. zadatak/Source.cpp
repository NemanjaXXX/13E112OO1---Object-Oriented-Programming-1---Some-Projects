#include "racun.h"
#include "stavka.h"
#include"Zbirka.h"
#include <iostream>
using namespace std;


int main() {
	bool kraj = true;

	cout << "Unesite ime kupca, datum kupovine i maksimalan broj stavki koje planirate da kupite: ";
	string ime; long int datum; int kap;
	cin >> ime >> datum >> kap;
	Racun r(ime, datum, kap);

	try {
		while (kraj) {
			cout << "Unesite podatke za jednu stavku, naziv artikla, jedinicnu cenu i kolicinu: ";
			string naziv; double cena, kol;
			cin >> naziv >> cena >> kol;

			r.dodajStavku(Stavka(naziv, cena, kol));

			cout << "Da li zelite da nastavite sa unosenjem, za Da unesite 1 a za NE 0: ";
			int unos;
			cin >> unos;
			if (unos == 0)
				kraj = false;
		}
		cout << endl << "Racun:" << endl << r << endl;
	}
	catch (G_Puna g) { cout << g << endl; }
	catch (G_Index g) { cout << g << endl; }
	catch (...) { cout << "***Neocekivana greska!***"; }

	return 0;
}

