#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Knjiga {
private:
	string autor, naslov, isbn;
public:
	Knjiga(string autor, string naslov, string isbn) : autor(autor), naslov(naslov), isbn(isbn) {
		cout << "Knjiga constructor called" << endl;
	}
	~Knjiga() {
		cout << "Knjiga destructor called" << endl;
	}

	string getAutor() const {
		return autor;
	}

	void setAutor(string autor) {
		this->autor = autor;
	}

	string getNaslov() const {
		return naslov;
	}

	void setNaslov(string naslov) {
		this->naslov = naslov;
	}

	string getISBN() const {
		return isbn;
	}

	void setISBN(string isbn) {
		this->isbn = isbn;
	}
};

class Knjiznica {
private:
	string adresa, naziv, kategorija;
	vector<Knjiga> knjige;

	void normaliziraj(string& tekst) {
		tekst[0] = toupper(tekst[0]);

		for (int i = 1; i < tekst.size(); i++)
			tekst[i] = tolower(tekst[i]);
	}
public:
	Knjiznica(string naziv, string adresa, string kategorija) {
		setAdresa(adresa);
		setNaziv(naziv);
		setKategorija(kategorija);
	}
	~Knjiznica() {}

	string getAdresa() const {
		return adresa;
	}

	void setAdresa(string adresa) {
		this->adresa = adresa;
	}

	string getNaziv() const {
		return naziv;
	}

	void setNaziv(string naziv) {
		normaliziraj(naziv);
		this->naziv = naziv;
	}

	string getKategorija() const {
		return kategorija;
	}

	void setKategorija(string kategorija) {
		if (kategorija == "djecja" || kategorija == "znanstvena" || kategorija == "citaonica" || kategorija == "opcenito") {
			this->kategorija = kategorija;
		}
		else {
			cout << "Kategorija nije ispravna!" << endl;
		}
	}

	void dodajKnjigu1(Knjiga z) {
		knjige.push_back(z);
	}

	void dodajKnjigu2(Knjiga& z) {
		knjige.push_back(z);
	}

	void dodajKnjigu3(Knjiga* z) {
		knjige.push_back(Knjiga(*z));
	}

	void ispisSvihKnjiga() const {
		for (int i = 0; i < knjige.size(); i++)
		{
			cout << knjige[i].getNaslov() << ", ";
			cout << knjige[i].getAutor();
			cout << " (" << knjige[i].getISBN() << ")" << endl;
		}
	}

	Knjiga nadjiKnjigu1(string isbn) {
		for (int i = 0; i < knjige.size(); i++)
		{
			if (knjige[i].getISBN() == isbn) return knjige[i];
		}
	}

	Knjiga* nadjiKnjigu2(string isbn) {
		for (int i = 0; i < knjige.size(); i++)
		{
			if (knjige[i].getISBN() == isbn) return &knjige[i];
		}
	}

	Knjiga& nadjiKnjigu3(string isbn) {
		for (int i = 0; i < knjige.size(); i++)
		{
			if (knjige[i].getISBN() == isbn) return knjige[i];
		}
	}
};

int main() {
	Knjiga knjiga1("Ivana Brlek Mazuranek", "Segrt Hlapic", "1234");
	Knjiga knjiga2("Tena Steeve", "Fragile", "5678");
	Knjiga knjiga3("Marko Markovic", "Judita", "9101");

	Knjiznica knjiznica("Djecja Knjiznica", "Avenija Marina Drzica", "djecja");

	knjiznica.dodajKnjigu1(knjiga1);
	knjiznica.dodajKnjigu2(knjiga2);
	knjiznica.dodajKnjigu3(&knjiga3);

	cout << "\nKnjiznica prije promjene: " << endl;
	knjiznica.ispisSvihKnjiga();

	Knjiga pronadjena1 = knjiznica.nadjiKnjigu1("1234");
	pronadjena1.setAutor("Ivana Brlic Mazuranic"); // neispravno - mijenja se autor u varijabli

	Knjiga* pronadjena2 = knjiznica.nadjiKnjigu2("5678");
	pronadjena2->setAutor("Tena Stivicic"); // ispravno, koristi se pokazivac

	Knjiga& pronadjena3 = knjiznica.nadjiKnjigu3("9101");
	pronadjena3.setAutor("Marko Marulic"); // ispravno, koristi se referenca

	cout << "\nKnjiznica nakon promjene:" << endl;
	knjiznica.ispisSvihKnjiga();
	cout << endl;

	return 0;
}