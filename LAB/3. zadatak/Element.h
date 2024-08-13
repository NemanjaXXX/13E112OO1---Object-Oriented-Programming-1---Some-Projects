#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
using namespace std;

class Element {
public:
	virtual ~Element() {}
	virtual double velicina() const = 0;
	virtual Element* kopija() const = 0;
private:
	virtual void pisi(ostream& it) const = 0;
	friend ostream& operator<< (ostream& it, const Element& e) {
		e.pisi(it); return it;
	}
};
#endif