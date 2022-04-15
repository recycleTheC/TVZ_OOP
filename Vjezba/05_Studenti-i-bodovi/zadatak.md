# 5. Studenti i bodovi

Potrebno je napisati program za praæenje bodovnog stanja studenata na odreðenom kolegiju.
Slijedeæi programski odsjeèak u nastavku napišite sve potrebne klase i metode kojima se dobije oèekivano ponašanje programskog koda.

`
	vector<Bodovi> OOPBodovi{
		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
		Bodovi(Student("Marko Markic", "0246004234"), 32)
	};

	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

	/* Preko objekta OOP ispišite bodove svih studenata tog kolegija poèevši od
	   onih s najmanjim brojem bodova prema veæim. Npr.;

	   Objektno orijentirano programiranje bodovi:
	   Ivica Ivanovic  0246005654      20
	   Ivana Ivic      0246002475      25
	   Marko Markic    0246004234      32
	*/
`