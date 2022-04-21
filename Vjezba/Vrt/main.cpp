#include<iostream>
#include "Vrt.h"

using namespace std;
using namespace Hortikultura;

int main() {
	Vrt vrt1("Marko Markic", "Vrtni put 1", 10, 10);
	Cvijet cvijet1("tulipan", "crvena", 10);

	vrt1.dodajCvijet(cvijet1);
	vrt1.dodajCvijet(Cvijet("sunovrat", "zuta", 5)); 
	vrt1.dodajCvijet(new Cvijet("macuhica", "ljubicasta", 2));

	vrt1.ispisSvihCvijetova();

	Vrt vrt2 = vrt1;
	vrt2.dodajCvijet(new Cvijet("ljubicica", "ljubicasta", 10));

	vrt2.ispisSvihCvijetova();

	Vrt vrt3;
	vrt3 = vrt2;
	vrt3.dodajCvijet(new Cvijet("suncokret", "zuta", 1));

	vrt3.ispisSvihCvijetova();

	Vrt vrt4 = move(Vrt("Marina Markic", "Vrtni put 2", 20, 10));
	vrt4.dodajCvijet(new Cvijet("suncokret", "zuta", 1));

	vrt4.ispisSvihCvijetova();

	return 0;	
}