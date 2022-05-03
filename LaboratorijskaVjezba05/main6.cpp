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

	TimeSpan operator + (const TimeSpan a) {
		TimeSpan novi = *this;
		novi.dodajSekunde((int)a);
		return novi;
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

	operator int() const {
		return this->getSati() * 3600 + this->getMinute() * 60 + this->getSekunde();
	}
};

ostream& operator << (ostream& izlaz, const TimeSpan& a) {
	izlaz << a.getSati() << ":" << a.getMinute() << ":" << a.getSekunde() << endl;
	return izlaz;
}

bool operator == (const TimeSpan& a, const TimeSpan& b) {
	return ((int)a) == ((int)b);
}

bool operator < (const TimeSpan& a, const TimeSpan& b) {
	return ((int)a) < ((int)b);
}

bool operator > (const TimeSpan& a, const TimeSpan& b) {
	return ((int)a) > ((int)b);
}

int main() {
	TimeSpan a(1, 0, 0);
	TimeSpan x(24, 0, 0);

	while (a < x)
	{
		if (a == TimeSpan(1, 0, 0))
			a = a + TimeSpan(10, 6, 7);
		else if (a < TimeSpan(12, 0, 0))
			a = a + TimeSpan(0, 37, 14);
		else
			a = a + TimeSpan(9, 11, 57);

		cout << a;
	}

	cout << "Ukupno sekundi: " << (int)a << endl;

	return 0;
}