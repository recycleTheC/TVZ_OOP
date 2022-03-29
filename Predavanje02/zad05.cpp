#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Osoba {
private: 
    string ime, prezime;
    int godina;
public:
    void setIme(string novoIme) {
        if (novoIme[0] >= 'a' && novoIme[0] <= 'z') {
            novoIme[0] = toupper(novoIme[0]);
        }

        for (int i = 1; i < novoIme.length(); i++)
        {
            novoIme[i] = tolower(novoIme[i]);
        }

        ime = novoIme;
    }

    string getIme() const {
        return ime;
    }

    void setPrezime(string novoPrezime) {
        if (novoPrezime[0] >= 'a' && novoPrezime[0] <= 'z') {
            novoPrezime[0] = toupper(novoPrezime[0]);
        }

        for (int i = 1; i < novoPrezime.length(); i++)
        {
            novoPrezime[i] = tolower(novoPrezime[i]);
        }

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

    for (int i = 0; i < 5; i++)
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