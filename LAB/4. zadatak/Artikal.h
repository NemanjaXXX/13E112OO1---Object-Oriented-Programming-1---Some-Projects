#ifndef ARTIKAL_H
#define ARTIKAL_H

#include "Roba.h"

class Artikal : public Roba {
	char oznaka;
	double vred;
public:
	Artikal(char oznakaa = '?', double vredd = 0) {
		oznaka = oznakaa; vred = vredd;
	}

	double vrednost() const override { return vred; }
	Artikal* kopija() const override {
		return new Artikal(*this);
	}

	char dohvatiOZ()const { return oznaka; }

protected:
	void pisi(ostream& it) const override { it << oznaka; }
};
#endif
