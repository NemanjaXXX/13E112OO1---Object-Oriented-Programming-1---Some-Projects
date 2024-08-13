#ifndef IMENIK_H
#define IMENIK_H

#include "Datoteka.h"
#include "Niz.h"

class G_Ima {};
inline ostream& operator<< (ostream& it, const G_Ima& g) {
	return it << "*** Datoteka vec postoji!***";
}

class Imenik : public Datoteka {
	Niz<Datoteka*> imenik;
	void kopiraj(const Imenik& im);
	void brisi();
public:
	Imenik(string imee, int kapp = 5) :Datoteka(imee, 100), imenik(kapp) {}
	Imenik(const Imenik& im) :Datoteka(im) { kopiraj(im); }
	Imenik& operator=(const Imenik& im) {
		if (this != &im) { brisi(); Datoteka::operator=(im); kopiraj(im); }
		return *this;
	}
	~Imenik() { brisi(); }
	Imenik& dodaj(Datoteka& dat);

	int broj() const { return imenik.dohvatiDuz(); }
	Datoteka* operator[](int i) {
		return imenik[i];
	}
	const Datoteka* operator[](int i) const {
		return imenik[i];
	}
	double ukupnaVel()const;
	bool postoji(const Datoteka& d);

	Imenik* kopija() const override {
		return new Imenik(*this);
	}
	friend ostream& operator<<(ostream& it, const Imenik& im);

};
#endif