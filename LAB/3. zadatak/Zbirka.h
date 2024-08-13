#ifndef ZBIRKA_H
#define ZBIRKA_H

#include <iostream>
using namespace std;

class G_Puna {};
inline ostream& operator<< (ostream& it, const G_Puna& g) {
	return it << "*** Niz je pun!***";
}
class G_Index {};
inline ostream& operator<< (ostream& it, const G_Index& g) {
	return it << "*** Nedozvoljen indeks!***";
}


template <typename T>
class Zbirka {
	public :T** niz;//public for testing
	private:
	int duz, kap;
	void kopiraj(const Zbirka& z);
	void premesti(Zbirka&& z) {
		kap = z.kap; duz = z.duz;
		niz = z.niz; z.niz = nullptr;
	}
	void brisi();
public:
	explicit Zbirka(int k = 10) {
		niz = new T * [kap = k];
		duz = 0;
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

	Zbirka& dodaj(const T& t);

	T* operator[] (int i) {
		if (i < 0 || i >= duz) throw G_Index();
		return niz[i];
	}
	const T* operator[] (int i) const {
		if (i < 0 || i >= duz) throw G_Index();
		return niz[i];
	}
	int popunjeno() const { return duz; }

	template <typename T>
	friend std::ostream& operator<< (std::ostream& it, const Zbirka& z);
};

template <typename T>
void Zbirka<T>::kopiraj(const Zbirka& z) {
	niz = new T * [kap = z.kap];
	duz = z.duz;
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
Zbirka<T>& Zbirka<T>::dodaj(const T& t) {
	if (duz == kap) throw G_Puna();
	niz[duz++] = t.kopija();
	return *this;
}

template <typename T>
std::ostream& operator<< (std::ostream& it, const Zbirka<T>& z) {
	for (int i = 0; i < z.popunjeno(); i++)
		it << *z.niz[i] << endl;

	return it;
}
#endif

