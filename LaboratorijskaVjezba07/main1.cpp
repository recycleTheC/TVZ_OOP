#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Korisnik {
protected:
	string ime, prezime, email;
public:
	Korisnik(string ime, string prezime, string email) {
		this->ime = ime;
		this->prezime = prezime;
		this->email = email;
	}

	string getIme() const { return this->ime; }
	string getPrezime() const { return this->prezime; }
	string getEmail() const { return this->email; }
};

class Sadrzaj {
protected:
	Korisnik* korisnik;
	string datum, vrijeme;
	int razina_privatnosti = 0;
public:
	Sadrzaj(Korisnik* korisnik, string datum, string vrijeme, int privatnost) {
		this->korisnik = korisnik;
		this->datum = datum;
		this->vrijeme = vrijeme;
		setRazinaPrivatnosti(privatnost);
	}

	string getDatum() const { return this->datum; }
	string getVrijeme() const { return this->vrijeme; }
	int getRazinaPrivatnosti() const { return this->razina_privatnosti; }
	const Korisnik* getKorisnik() const { return this->korisnik; }

	void setRazinaPrivatnosti(int razina) {
		this->razina_privatnosti = razina;
	}

	virtual string getNaslov() const = 0;
	virtual string getKratkiOpis() const = 0;
	virtual string kratkiIspis() const = 0;
	virtual string ispis() const = 0;
};

class Link : public Sadrzaj {
private:
	string naslov, kratki_opis, url;
public:
	Link(Korisnik* korisnik, string datum, string vrijeme,
		int privatnost, string naslov, string opis, string url) : Sadrzaj(korisnik, datum, vrijeme, privatnost) {
		this->naslov = naslov;
		this->kratki_opis = opis;
		this->url = url;
	}

	string getNaslov() const { return this->naslov; }
	string getKratkiOpis() const { return this->kratki_opis; }
	string getURL() const { return this->url; }
	string kratkiIspis() const { return this->naslov + ", " + this->kratki_opis; }
	string ispis() const { return this->naslov + ", " + this->kratki_opis + ": " + this->url; }
};

class Slika : public Sadrzaj {
private:
	string naslov, prikaz, kratki_opis;
public:
	Slika(Korisnik* korisnik, string datum, string vrijeme,
		int privatnost, string naslov, string opis, string prikaz) : Sadrzaj(korisnik, datum, vrijeme, privatnost) {
		this->prikaz = prikaz;
		this->naslov = naslov;
		this->kratki_opis = opis;
	}

	string getNaslov() const { return this->naslov; }
	string getKratkiOpis() const { return this->kratki_opis; }
	string getPrikaz() const { return this->prikaz; }
	string kratkiIspis() const { return this->naslov + ", " + this->kratki_opis; }
	string ispis() const { return this->naslov + ", " + this->kratki_opis + ": " + this->prikaz; }
};

ostream& operator << (ostream& izlaz, const Sadrzaj* objava) {
	izlaz << objava->ispis();
	return izlaz;
}

class Profil : public Korisnik {
private:
	vector<Sadrzaj*> objave;

	static bool usporedba(const Sadrzaj* a, const Sadrzaj* b) {
		return a->getDatum() > b->getDatum();
	}

	void sortiraj() {
		sort(this->objave.begin(), this->objave.end(), usporedba);
	}

public:
	Profil(string ime, string prezime, string email) : Korisnik(ime, prezime, email) {}

	Profil& dodajObjavu(Sadrzaj* objava) {
		this->objave.push_back(objava);
		return *this;
	}

	Profil& dodajObjave(vector<Sadrzaj*>& objave) {
		for (int i = 0; i < objave.size(); i++)
			this->objave.push_back(objave[i]);

		return *this;
	}

	Sadrzaj* dohvatiObjavu(int id) { return this->objave[id]; }

	static void ispisObjavaKorisnika(Profil& profil, int n) {
		profil.sortiraj();

		for (int i = 0; i < n && i < profil.objave.size(); i++)
		{
			cout << profil.objave[i] << endl;
		}

		cout << endl;
	}
};


int main() {
	Profil profil1("Nikola", "Tesla", "nikola.tesla@wiki.local");

	// format datuma: YYYYMMDD

	Link objava1(&profil1, "20210710", "14:50", 1, "Nikola Tesla", "O meni", "https://hr.wikipedia.org/wiki/Nikola_Tesla");
	Link objava2(&profil1, "20220206", "12:05", 2, "Trofazna struja", "Moj izum", "https://www.enciklopedija.hr/Natuknica.aspx?ID=62398");
	Link objava3(&profil1, "20220307", "10:15", 3, "Teslin transformator", "Jos mojih izuma", "https://hr.wikipedia.org/wiki/Teslin_transformator");

	vector<Sadrzaj*> objave = { &objava1, &objava2, &objava3 };
	profil1.dodajObjave(objave);

	Slika objava4(&profil1, "20900101", "00:00", 1, "Future Vision", "Moja vizija", "|~~~>");
	profil1.dodajObjavu(&objava4);

	Profil::ispisObjavaKorisnika(profil1, 3);
}