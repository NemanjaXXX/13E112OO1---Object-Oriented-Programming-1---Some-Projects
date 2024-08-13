#include "Skladiste.h"
#include "Cigla.h"
#include "Proizvod.h"
#include "G_Prazna.h"
using namespace std;

int main() {
	bool kraj = false;
	Skladiste s;
	while (kraj == false) {
		cout << "1.Ubaci proizvod u skladiste" << endl;
		cout << "2.Izvadi proizvod iz skladista" << endl;
		cout << "3.Ispisi skladiste" << endl;
		cout << "4.Zavrsi program" << endl;

		int izbor;
		cin >> izbor;
		Proizvod* p;
		try {
			switch (izbor) {
			case 1:
				cout << "Unesi cenu proizvoda: ";
				double cena;
				cin >> cena;
				cout << "Unesi dimenzije cigle: ";
				double a, b, c;
				cin >> a >> b >> c; ;
				s.dodaj(new Cigla(cena, a, b, c));
				break;
			case 2:
				cout << "Proizvod je: ";
				p = s.uzmi();
				cout << *p << endl;
				delete p;
				break;
			case 3:
				cout << "Trenutni izgled skladista:" << endl;
				cout << s << endl;
				break;

			case 4: kraj = true;
			}
		}
		catch (G_Prazna g) { cout << g << endl; }
		catch (...) { cout << "Ne predvidjana greska!"; }
	}
	return 0;
}