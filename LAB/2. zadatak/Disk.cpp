#include"Disk.h"

ostream& operator<<(ostream& it, const Disk& d) {
	for (int i = 0; i < d.im.broj(); i++)
		it << *d.im[i];
	return it;
}
