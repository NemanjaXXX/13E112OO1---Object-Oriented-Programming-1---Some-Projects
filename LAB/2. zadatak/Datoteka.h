#ifndef DATOTEKA_H
#define DATOTEKA_H

#include <iostream>
#include <string>
using namespace std;

class Datoteka {
	string ime;
	double vel;
	Datoteka* pok;

	void kopiraj(const Datoteka& dat) {
		ime = dat.ime; vel = dat.vel;
		if (dat.pok != nullptr)
			pok = dat.pok->kopija();
		else
			pok = nullptr;
	}
public:
	Datoteka(string imee, double vell) :ime(imee) {
		vel = vell;
		pok = nullptr;
	}
	Datoteka(const Datoteka& dat) { kopiraj(dat); }
	Datoteka& operator= (const Datoteka& dat) {
		kopiraj(dat); return *this;
	}
	virtual ~Datoteka() {}

	string dohvatiIme()const { return ime; }
	double dohvatiVel()const { return vel; }

	void promeniVelicinu(double novaVel) { vel = novaVel; }

	Datoteka& postavi(Datoteka* pokk) {
		pok = pokk;
		return *this;
	}
	virtual Datoteka* kopija() const {
		return new Datoteka(*this);
	}

	friend ostream& operator<< (ostream& it, const Datoteka& d) {
		it << d.pok->ime << '/' << d.ime << '(' << d.vel << ')';
		return it;
	}
};
#endif