#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Osoba {
private: 
    string ime, prezime;
    int godina;

    void ispravnost(string& text) {
        // ovaj kod smo ponavljaji u setIme() i setPrezime - mozemo koristiti private funkciju za to
        // koristi se referenca za izmjenu vrijednosti varijable

        if (text[0] >= 'a' && text[0] <= 'z') {
            text[0] = toupper(text[0]);
        }

        for (int i = 1; i < text.length(); i++)
        {
            text[i] = tolower(text[i]);
        }
    }

public:
    void setIme(string novoIme) {
        ispravnost(novoIme);
        ime = novoIme;
    }

    string getIme() const {
        return ime;
    }

    void setPrezime(string novoPrezime) {
        ispravnost(novoPrezime);
        prezime = novoPrezime;
    }

    string getPrezime() const {
        return prezime;
    }

    void setGod(int god) {
        if (god >= 1900) godina = god;
    }

    int getGod() const {
        return godina;
    }
};

int main() {

    vector<Osoba> studenti;

    for (int i = 0; i < 2; i++)
    {
        string tmpIme, tmpPrez;
        int tmpGod;

        cout << "Osoba " << i + 1 << " ime: ";
        cin >> tmpIme;
        cout << "Osoba " << i + 1 << " prezime: ";
        cin >> tmpPrez;
        cout << "Osoba " << i + 1 << " godina: ";
        cin >> tmpGod;

        Osoba tmp;

        tmp.setIme(tmpIme);
        tmp.setPrezime(tmpPrez);
        tmp.setGod(tmpGod);

        studenti.push_back(tmp);
    }

    int najstariji = 0;

    for (int i = 1; i < studenti.size(); i++)
    {
        if (studenti[i].getGod() < studenti[najstariji].getGod()) {
            najstariji = i;
        }
    }

    cout << "Najstariji student: " << studenti[najstariji].getIme() << " " << studenti[najstariji].getPrezime() << endl;
}