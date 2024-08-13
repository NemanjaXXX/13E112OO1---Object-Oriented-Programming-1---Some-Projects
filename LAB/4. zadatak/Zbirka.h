#ifndef ZBIRKA_H
#define ZBIRKA_H

#include <iostream>
using namespace std;

class G_Index {};
inline ostream& operator<< (ostream& it, const G_Index& g) {
	return it << "*** Pogresan indeks!***";
}

template<class T>
class Zbirka {
	T** niz;
	int kap, duz, korak;
	void kopiraj(const Zbirka& z);
	void premesti(Zbirka&& z) {
		kap = z.kap; duz = z.duz; korak = z.korak;
		niz = z.niz; z.niz = nullptr;
	}
	void brisi();
public:
	explicit Zbirka(int kapp = 10, int korakk = 3) {
		niz = new T * [kap = kapp];
		duz = 0; korak = korakk;
	}
	Zbirka(const Zbirka& z) { kopiraj(z); }
	Zbirka(Zbirka&& z) { premesti(z); }
	Zbirka& operator= (const Zbirka& z) {
		if (this != &z) { brisi(); kopiraj(z); }
		return *this;
	}
	Zbirka& operator= (Zbirka&& z) {
		if (this != &z) { brisi(); premesti(z); }
		return *this;
	}
	~Zbirka() { brisi(); }

	Zbirka& operator+= (T* t);

	int dohvatiDuz()const { return duz; }

	T* operator[] (int ind) {
		if (ind < 0 || ind >= duz) throw G_Index();
		return niz[ind];
	}

	const T* operator[] (int ind) const {
		if (ind < 0 || ind >= duz) throw G_Index();
		return niz[ind];
	}

	T* izvadi(int ind);
	Zbirka& isprazni() { duz = 0; return *this; }
};

template <typename T>
void Zbirka<T>::kopiraj(const Zbirka& z) {
	niz = new T * [kap = z.kap];
	duz = z.duz;
	korak = z.korak;
	for (int i = 0; i < duz; i++)
		niz[i] = z.niz[i]->kopija();
}
template <typename T>
void Zbirka<T>::brisi() {
	for (int i = 0; i < duz; i++)
		delete niz[i];
	delete[] niz;
}

template <typename T>
T* Zbirka<T>::izvadi(int ind) {
	if (ind < 0 || ind >= duz) throw G_Index();
	T* temp = niz[ind];
	for (int i = ind; i < duz - 1; i++)
		niz[i] = niz[i + 1];
	duz--;
	return temp;
}

template <typename T>
Zbirka<T>& Zbirka<T>:: operator+= (T* t) {
	if (duz == kap) {
		T** pom = new T * [kap += korak];
		for (int i = 0; i < duz; i++) pom[i] = niz[i];
		delete[] niz;
		niz = pom;
	}
	niz[duz++] = t;
	return *this;
}
#endif