#ifndef ROBA_H
#define ROBA_H

#include <iostream>
using namespace std;

class Roba {
public:
	virtual ~Roba() {}
	virtual double vrednost() const = 0;
	virtual Roba* kopija()const = 0;
protected:
	virtual void pisi(ostream& it) const = 0;
	friend ostream& operator<< (ostream& it, const Roba& r) {
		r.pisi(it);
		return it;
	}
};
#endif
