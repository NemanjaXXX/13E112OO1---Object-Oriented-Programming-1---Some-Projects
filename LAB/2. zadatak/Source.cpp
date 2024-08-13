#include "Imenik.h"
#include "Disk.h"

int main() {
	Datoteka dat1("Fajl1", 10), dat2("Fajl2", 20), dat3("Fajl3", 30), dat4("Fajl4", 40);
	Imenik im1("Folder1"), im2("Folder2");
	Disk disk(2);
	try {
		im1.dodaj(dat1).dodaj(dat2);
		im2.dodaj(dat3).dodaj(dat4);
		disk.dodaj(im1).dodaj(im2);
		cout << disk;
	}
	catch (G_Ima g) { cout << g << endl; }
	catch (G_Index g) { cout << g << endl; }
	catch (...) { cout << "***Neocekivana greska!***"; }
	return 0;
}
