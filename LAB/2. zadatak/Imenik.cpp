#include"Imenik.h"

void Imenik::kopiraj(const Imenik& im) {
	for (int i = 0; i < im.imenik.dohvatiDuz(); i++)
		imenik.dodaj(im.imenik[i]->kopija());
}
void Imenik::brisi() {
	for (int i = 0; i < imenik.dohvatiDuz(); i++)
		delete imenik[i];
}
Imenik& Imenik::dodaj(Datoteka& dat) {
	if (postoji(dat)) throw G_Ima();
	dat.postavi(this);
	imenik.dodaj(dat.kopija());
	promeniVelicinu(dohvatiVel() + 10);
	return *this;
}

double Imenik::ukupnaVel()const {
	double suma = 0;
	for (int i = 0; i < imenik.dohvatiDuz(); i++)
		suma += imenik[i]->dohvatiVel();
	return suma;
}

bool Imenik::postoji(const Datoteka& d) {
	for (int i = 0; i < imenik.dohvatiDuz(); i++)
		if (d.dohvatiIme() == (*imenik[i]).dohvatiIme()) return true;
	return false;
}

ostream& operator<<(ostream& it, const Imenik& im) {
	for (int i = 0; i < im.broj(); i++)
		it << *im[i] << endl;
	it << endl << endl;
	return it;
}

