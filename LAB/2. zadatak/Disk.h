#ifndef DISK_H
#define DISK_H

#include"Imenik.h"

class Disk {
	Imenik im;
public:
	explicit Disk(int kap) :im(" ", kap) {}
	Disk(const Disk& d) :im(d.im) {}
	Disk& operator=(const Disk& d) {
		im.operator=(d.im); return *this;
	}
	Imenik dohvatiKoren()const { return im; }

	Disk& dodaj(Imenik& imm) {
		im.dodaj(imm);
		return *this;
	}
	friend ostream& operator<<(ostream& it, const Disk& d);
};
#endif