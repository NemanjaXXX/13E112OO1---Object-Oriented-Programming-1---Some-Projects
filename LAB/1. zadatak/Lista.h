#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "G_Prazna.h"
using namespace std;

template <typename T>
class Lista {
	struct Elem {
		T* pok;
		Elem* sled;
		Elem(T* pokk, Elem* sledd = nullptr) {
			pok = pokk; sled = sledd;
		}
		~Elem() { delete pok; }
	};

	Elem* prvi, * posl;
	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		prvi = l.prvi; l.prvi = nullptr;
		posl = l.posl; l.posl = nullptr;
	}
	void brisi();
public:
	Lista() { prvi = posl = nullptr; }
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator= (const Lista& l) {
		if (this != &l) { brisi(); kopiraj(l); }
		return *this;
	}
	Lista& operator= (Lista&& l) {
		if (this != &l) { brisi(); premesti(l); }
		return *this;
	}
	~Lista() { brisi(); }

	Lista& dodajNaKraj(T* t);

	T* uzmiSaPocetka();


	friend ostream& operator<< (ostream& it, const Lista& l);
};

template <typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = nullptr;
	for (Elem* tek = l.prvi; tek; tek = tek->sled) {
		Elem* novi = new Elem(tek->pok->kopija());

		if (prvi == nullptr)
			prvi = novi;
		else
			posl->sled = novi;

		posl = novi;
	}
}

template <typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr;
}

template <typename T>
Lista<T>& Lista<T>::dodajNaKraj(T* t) {
	Elem* novi = new Elem(t);

	if (prvi == nullptr)
		prvi = novi;
	else
		posl->sled = novi;

	posl = novi;
	return *this;
}

template <typename T>
T* Lista<T>::uzmiSaPocetka() {
	if (prvi == nullptr) throw G_Prazna();
	T* pom = prvi->pok->kopija();
	Elem* stari = prvi;
	prvi = prvi->sled;
	delete stari;
	return pom;
}

template <typename T>
ostream& operator<< (ostream& it, const Lista<T>& l) {
	it << "{";
	Lista<T>::Elem* tek;
	for (tek = l.prvi; tek->sled; tek = tek->sled)
		it << *tek->pok << ", ";
	it << *tek->pok << "}";
	return it;
}
#endif
