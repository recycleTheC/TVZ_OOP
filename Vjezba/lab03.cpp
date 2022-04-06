#include<iostream>

#include"lab03/Ekipa.h"
#include"lab03/Igrac.h"

using namespace std;

/*
Potrebno je napisati program za evidenciju igraèa u ekipi.
Ekipa se sastoji od igraèa, a za svakog igraèa se evidentira broj na dresu, ime, prezime i trzisna cijena.
Potrebno je omoguæiti ispis svih igraèa u ekipi (naziv ekipe, te popis svih igraèa poredano po broju na dresu).
Takoðer, potrebno je omoguæiti jednostavno dohvaæanje informacija u ukupnoj cijeni svih igraèa, najskupljem igraèu, te prosjeènoj cijeni svih igraèa.
Napišite sve potrebne klase i metode kojima se dobije oèekivano ponašanje programskog koda.
*/

int main() {

    Ekipa ekipa;
    ekipa.setNaziv("Tim raketa");

    Igrac i1("Luka", "Modric");
    i1.setBrojDresa(10);
    i1.setTrzisnaCijena(50000000);
    ekipa.dodajIgraca(i1);

    Igrac i2("Mario", "Mandzukic");
    i2.setBrojDresa(9);
    i2.setTrzisnaCijena(27000000);
    ekipa.dodajIgraca(i2);

    Igrac i3("Darijo", "Srna");
    i3.setBrojDresa(11);
    i3.setTrzisnaCijena(14500000);
    ekipa.dodajIgraca(i3);

    ekipa.ispisi();

    //Igrac najskuplji = ekipa.getNajskuplji();
    //najskuplji.ispisi();

    cout << "Najskuplji igrac: " << ekipa.getNajskuplji().ispisi() << endl;

    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

    return 0;
}