#ifndef NIZ_H
#define NIZ_H

#include <iostream>
using namespace std;

class G_Index {};
inline ostream& operator<< (ostream& it, const G_Index& g) {
	return it << "*** Nedozvoljen indeks!***";
}

template <typename T>
class Niz {
	T* niz;
	int kap, duz;
	void kopiraj(const Niz& n);
	void premesti(Niz&& n) {
		kap = n.kap; duz = n.duz;
		niz = n.niz; n.niz = nullptr;
	}
	void brisi() { delete[] niz; }
public:
	explicit Niz(int k = 5) {
		niz = new T[kap = k];
		duz = 0;
	}
	Niz(const Niz& n) { kopiraj(n); }
	Niz(Niz&& n) { premesti(n); }
	Niz& operator= (const Niz& n) {
		if (this != &n) { brisi(); kopiraj(n); }
		return *this;
	}
	Niz& operator= (Niz&& n) {
		if (this != &n) { brisi(); premesti(n); }
		return *this;
	}
	~Niz() { brisi(); }

	Niz& dodaj(const T& t);
	int dohvatiDuz() const { return duz; }

	T& operator[] (int i) {
		if (i < 0 || i >= duz) throw G_Index();
		return niz[i];
	}
	const T& operator[] (int i) const {
		if (i < 0 || i >= duz) throw G_Index();
		return niz[i];
	}
};

template <typename T>
void Niz<T>::kopiraj(const Niz& n) {
	niz = new T[kap = n.kap];
	duz = n.duz;
	for (int i = 0; i < duz; i++)
		niz[i] = n.niz[i]->kopija();
}
template <typename T>
Niz<T>& Niz<T>::dodaj(const T& t) {
	if (duz == kap) {
		T* pom = new T[kap += 5];
		for (int i = 0; i < duz; i++) pom[i] = niz[i]->kopija();
		delete[] niz;
		niz = pom;
	}
	niz[duz++] = t;
	return *this;
}
#endif