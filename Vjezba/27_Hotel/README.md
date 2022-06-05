# 27. Hotel (2. kolokvij)

Potrebno je napraviti objektni model za aplikaciju koja služi potpori poslovanju hotela. U aplikaciji se vodi evidencija o
rezervacijama prostora u hotelu. Prostori mogu biti javni prostor (primjerice, kongresna dvorana, restoran, klub, bazeni) ili sobe.
Za svaki prostor se pamti niz rezervacija (datum i vrijeme, te trajanje rezervacije). Za pojedini javni prostor se također vodi
evidencija o kategoriji (bazen, restoran,...) te kapacitet. Za pojedinu sobu se vodi evidencija je li jednokrevetna, dvokrevetna ili
trokrevetna.

- Ispravno modelirati nasljeđivanje i osmisliti cjelokupni objektni model zajedno sa svim potrbenim atributima. Očekuje se da model ima 5 klasa + main program. Dopušteno je dodavanje novih klasa u svrhu lakše implementacije.
- Odabrati jednu izvedenu klasu, i u njoj i baznoj klasi implementirati ispravne modifikatore pristupa za sve atribute (postaviti private, protected, public gdje treba).
- Definirati operator ispisa za neku klasu po izboru i demonstrirati upotrebu.
- Ostale klase trebaju imati ili operator ispisa ili funkciju "ispisi".
- Demonstrirati mehanizme polimorfizma ili preko te funkcije ili neke druge funkcije prema želji.
- U main programu statički napuniti objekte sa inicijalnim podacima i ispisati ih koristeći operator << ili funkciju "ispis".
- Baciti iznimku ako prostor nije moguće rezervirati u tom terminu i uhvatiti ju, te ispisati poruku korisniku.