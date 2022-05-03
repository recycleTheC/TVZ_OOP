#include<iostream>

using namespace std;

class TimeSpan {
private:
	int sati, minute, sekunde;
public:
	TimeSpan(int h, int min, int s) throw(int) {
		setSati(h);
		setMinute(min);
		setSekunde(s);
	}

	TimeSpan& dodajSekunde(int s) throw(const char*) {

		if (s < 0) throw("Neispravne vrijednosti vremena!");

		for (int i = 0; i < s; i++)
		{
			if (++this->sekunde == 60) {
				this->sekunde = 0;

				if (++this->minute == 60) {
					this->minute = 0;
					this->sati++;
				}
			}
		}

		return *this;
	}

	TimeSpan& umanjiSekunde(int s) throw(const char*) {

		if (s < 0) throw("Neispravne vrijednosti vremena!");

		for (int i = 0; i < s; i++)
		{
			if (this->sekunde-- == 0) {
				this->sekunde = 59;

				if (this->minute-- == 0) {
					this->minute = 59;

					if (this->sati-- == 0) throw("Neispravan vremenski raspon!");
					// u tekstu zadatka nije definirano trebaju li se koristiti iznimke
				}
			}
		}

		return *this;
	}

	void setSati(int h) throw(int) {
		if (h < 0) throw h;
		else this->sati = h;
	}

	void setMinute(int min) throw(int) {
		if (min < 0 && min > 59) throw min;
		else this->minute = min;
	}

	void setSekunde(int s) throw(int) {
		if (s < 0 && s > 59) throw s;
		else this->sekunde = s;
	}

	int getSati() const { return this->sati; }
	int getMinute() const { return this->minute; }
	int getSekunde() const { return this->sekunde; }

	TimeSpan operator + (int s) {
		TimeSpan novi = *this;
		novi.dodajSekunde(s);
		return novi;
	}

	TimeSpan operator -- (int) {
		TimeSpan novi = *this;
		this->umanjiSekunde(1);
		return novi;
	}

	friend TimeSpan operator+ (int s, const TimeSpan& a);
	friend ostream& operator << (ostream& izlaz, const TimeSpan& a);
};

ostream& operator << (ostream& izlaz, const TimeSpan& a) {
	izlaz << a.sati << ":" << a.minute << ":" << a.sekunde << endl;
	return izlaz;
}

TimeSpan operator+ (int s, const TimeSpan& a) {
	TimeSpan novi = a;
	novi.dodajSekunde(s);
	return novi;
}

int main() {

	try {
		TimeSpan a(1, 0, 0);
		a = a + 10;
		cout << a;  //1:0:10
		a = 65 + a;
		cout << a; //1:1:15

		for (int i = 0; i < 60 * 60 + 74; i++) {
			a--;
		}

		cout << a; //0:0:1

		//a--;
		a--;

		cout << a; //0:0:0
	}
	catch (int ex) {
		cout << "Neispravna vrijednost: " << ex << endl;
	}
	catch (const char* ex) {
		cout << ex << endl;
	}

	return 0;
}