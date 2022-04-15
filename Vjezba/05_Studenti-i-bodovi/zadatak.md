# 5. Studenti i bodovi

Potrebno je napisati program za pra�enje bodovnog stanja studenata na odre�enom kolegiju.
Slijede�i programski odsje�ak u nastavku napi�ite sve potrebne klase i metode kojima se dobije o�ekivano pona�anje programskog koda.

`
	vector<Bodovi> OOPBodovi{
		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
		Bodovi(Student("Marko Markic", "0246004234"), 32)
	};

	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

	/* Preko objekta OOP ispi�ite bodove svih studenata tog kolegija po�ev�i od
	   onih s najmanjim brojem bodova prema ve�im. Npr.;

	   Objektno orijentirano programiranje bodovi:
	   Ivica Ivanovic  0246005654      20
	   Ivana Ivic      0246002475      25
	   Marko Markic    0246004234      32
	*/
`