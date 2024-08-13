#pragma once
using namespace std;
class G_Prazna {};
inline ostream& operator<< (ostream& it, const G_Prazna& g) {
	return it << "*** Lista je prazna! ***";
}