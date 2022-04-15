# 9. Student

Napišite klasu Student koja u privatnom dijelu sadrži pokazivaè JMBAG koji pokazuje na znakovni niz duljine 11.
U javnom dijelu klase smjestite metode

```cpp
Student(){}
Student(char* jmbag); // konstruktor (alocira JMBAG duljine 11 znakova)
~Student(); // destruktor (dealocira JMBAG)
char* GetJMBAG() const;
void SetJMBAG(char* noviJMBAG);
```

Nakon što napišete tijela metoda klase Student napišite funkciju main sa sljedeæim sadržajem.

```cpp
Student Ante("1122334455");
Student Ivica = Ante;

Ante.SetJMBAG("6677889900");

cout << Ante.GetJMBAG() << endl; // 6677889900
cout << Ivica.GetJMBAG() << endl; // 6677889900 ?!?!

Student Marko;
Marko = Ante;

Marko.SetJMBAG("1234567890");

cout << Marko.GetJMBAG() << endl; // 1234567890
cout << Ante.GetJMBAG() << endl; // 1234567890 ?!?!
```

Nakon što pokrenete program potrebno je primijetiti problematiène ispise koji su naznaèeni u komentarima.
Oni su se dogodili kao rezultat plitkog kopiranja (eng. *shallow copy*) prilikom pozivanja podrazumijevanog
kopirnog konstruktora i operatora pridruživanja. Za oba ova sluèaja potrebno je realizirati duboko kopiranje tako da konaèni ispis bude:

```
6677889900
1122334455
1234567890
6677889900
```

Dodatak: Napišite prijenosni konstruktor i operator pridruživanja sa semantikom prijenosa za klasu Student.