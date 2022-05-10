# 7. laboratorijska vježba

## 1. Društvena mreža

U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno
definirati barem jedno nasljeđivanje.

Implementirate društvenu mrežu koja će nadmašiti Facebook, sasvim sigurno. Da bi stvar bila što brža, upravo C++ ste odabrali za razvoj
središnjeg dijela aplikacije. Krećete od izrade klasa. Prvo čime se bavite je objavljivanje sadržaja na mreži. Korisnici mogu objaviti
sadržaj na svoj profil. Svaki korisnik ima osnovne podatke (ime, prezime, mail...), te niz sadržaja koje je objavio. Ima nekoliko tipova
sadržaja koji se mogu objaviti - ono što im je zajedničko je da imaju datum i vrijeme objave, razinu privatnosti i korisnika koji je objavio sadržaj.
U ovoj fazi potrebno je napraviti funkcionalnost za sadržaj koji je link na neku stranicu, no treba imati na umu da će se u kasnijim fazama
projekta pojaviti ostali sadržaji. Uz podatke koji su zajednički svakom tipu sadržaja, ovaj sadržaj ima još url stranice, naslov koji će
se prikazati i kratki opis. Potrebno je omogućiti prikaz top N sadržaja koje je korisnik objavio, na način da je najsvježiji sadržaj na vrhu,
idući ispod, itd.

### Način bodovanja

Program koji se ne prevodi uspješno ne može ostvariti više od 2 boda!

- Barem 3 klase (smislene) - 1 bod
- Članovi ne smiju biti javni - 1 bod
- Barem jedan operator - 1 bod
- Barem jedno nasljeđivanje (smisleno) - 1 bod
- Demonstracija funkcionalnosti u main programu - 1 bod
- Za dodatnih 2 boda, potrebno je implementirati i funkcionalnost povezanosti - svaki korisnik može biti povezan s nizom ostalih korisnika. Omogućiti korisnicima da dobiju listu top 3 drugih korisnika koje bi mogli poznavati a još nisu povezani s njima. Predložiti način utvrđivanja vjerojatnosti poznanstva i implementirati predloženo rješenje.

## 2. Učionica i računala

U učionici se nalazi nekoliko prenosivih računala. Riječ je tablet i laptop računalima različitih proizvođača na kojima se nalaze različiti
operacijski sustavi. Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija `main`
radila kao što je to i predviđeno.

```cpp
int main(){
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);

    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */
    
    return 0;    
}
```

Napomena: Klasa `Racunalo` je apstraktna - demonstrirati polimorfizam unutar funkcije `AnalizaUcionice` prilikom provjere tipa računala (tablet ili laptop).

## 3. Dokumenti

U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno definirati
barem jedno nasljeđivanje.

Nadograđujete sustav koji se bavi informatizacijom poduzeća. Zaduženi ste za informatizaciju dokumenata. Trenutno je poznato da postoji nekoliko vrsta
dokumenata. Za svaki dokument se zna da ima podatke o tome tko ga je napravio, datum i vrijeme nastanka dokumenta, te njegov jedinstveni broj (svaki
dokument ima jedinstveni broj - string koji može sadržavati brojke, crtice "-" i slasheve "/" ). Vi ste zaduženi da napravite dokument koji predstavlja
račun. Račun, uz osnovne podatke koje ima svaki dokument, ima također JIR i tip računa (R1 ili obični). Račun ima niz stavki. Svaka stavka sadrži
podatak o nazivu usluge koja je napravljena, količinu i jediničnu cijenu. Za račun se također mora znati kolika je ukupna suma njegovih stavki.
Račun mora imati mogućnost obračunavanja popusta, na način da se postotak popusta primijeni na svaku stavku. Također, račun se mora moći ispisati
(zajedno sa svim podacima i stavkama).

### Način bodovanja

Program koji se ne prevodi uspješno ne može ostvariti više od 2 boda.

- Barem 3 klase (smislene) - 1 bod
- Članovi ne smiju biti javni - 1 bod
- Barem jedan operator - 1 bod
- Barem jedno nasljeđivanje (smisleno) - 1 bod
- Demonstracija funkcionalnosti u main programu - 1 bod

**Za dodatnih 2 boda**, potrebno je implementirati i obračunavanje PDV-a - gdje je za svaku stavku potrebno izraziti PDV.
Imati na umu problem zaokruživanja - naime, ukupna suma računa * 25% mora biti jednako sumi PDV-a za svaku stavku.
(primjer: ukupna suma = 9,90kn; PDV = 2,48kn. Međutim, račun ima 9 stavki po 1,10kn (PDV=0,28 za svaku stavku), što daje sumu od 2,52kn).
Predložiti i implementirati rješenje problema.

## 4. Filter

Definirajte potrebne dijelove da bi funkcija `main` radila kako je opisano.
Klase `Filter`, `FilterVeciOd` i `FilterManjiOd` trebaju "filtrirati" vrijednosti
prema zadanom parametru.


```cpp
class Filter {
public:
    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
};

int main() {
    vector<int> v = { 14, 3, 18, 5, 6, 10, 2, 8, 1, 7 };

    Filter* filter = new FilterVeciOd(5); // propusti samo vrijednosti vece od 5
    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat; // ispisuje 14 18 6 10 8 7
    delete filter;

    filter = new FilterManjiOd(5); // propusti samo vrijednosti manje od 5
    rezultat = filter->uvjet(v);
    cout << rezultat; // ispisuje 3 2 1
    delete filter;

    return 0;
}
```

## 5. Proizvodi

Potrebno je napisati sve klase kako bi donji programski odsječak radio, uz ispravno modeliranje nasljeđivanja i polimorfizma.
Dodatno, potrebno je u klasi proizvod napraviti čistu virtualnu funkciju getKoefKvalitete() i pomoću nje pronaći koji proizvod iz vektora ima
najveći koeficijent kvalitete.

Za automobil, koeficijent se računa kao: 1.0 / (2015 - GOD_PROIZVODNJE) * maxBrzina / 100.0 * cijena / 100000.0;
Za lego igračku, računa se kao: brKomada / cijena.

```cpp
int main()
{
vector<Proizvod*> vp = {
new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
new Automobil("Yugo 45", 14500, 1988, 127.88),
};

for (int i = 0; i < 4; i++){
vp[i]->print();
}

/*
Dodati kod za pronalazak proizvoda s najvećim koeficijentom i ispis tog proizvoda i odgovarajućeg koeficijenta.
*/

return 0;
}
```

## 6. Sortiranje

Definirajte potrebne dijelove da bi funkcija `main` radila kako je opisano.

```cpp
class Sortiranje {
public:
    virtual void sortiraj(vector<int>* vec) final {
        for (int i = 0; i < vec->size() - 1; ++i)
            for (int j = i + 1; j < vec->size(); ++j)
                if (!usporedba((*vec)[i], (*vec)[j])) {
                    swap((*vec)[i], (*vec)[j]);
                }
    }

    virtual bool usporedba(int e1, int e2) = 0;
};

int main() {
    vector<int> v = {8, 17, 1, 14, 5, 2, 19, 3, 15, 11};

    Sortiranje* sort1 = new SortVeciPremaManjem();
    sort1->sortiraj(&v);
    cout << v;        // ispisuje 19 17 15 14 11 8 5 3 2 1
    delete sort1;

    Sortiranje* sort2 = new SortManjiPremaVecem();
    sort2->sortiraj(&v);
    cout << v;        // ispisuje 1 2 3 5 8 11 14 15 17 19
    delete sort2;

    return 0;
}
```