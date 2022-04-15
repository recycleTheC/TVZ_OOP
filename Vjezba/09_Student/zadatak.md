# 9. Student

Napi�ite klasu Student koja u privatnom dijelu sadr�i pokaziva� JMBAG koji pokazuje na znakovni niz duljine 11.
U javnom dijelu klase smjestite metode

```cpp
Student(){}
Student(char* jmbag); // konstruktor (alocira JMBAG duljine 11 znakova)
~Student(); // destruktor (dealocira JMBAG)
char* GetJMBAG() const;
void SetJMBAG(char* noviJMBAG);
```

Nakon �to napi�ete tijela metoda klase Student napi�ite funkciju main sa sljede�im sadr�ajem.

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

Nakon �to pokrenete program potrebno je primijetiti problemati�ne ispise koji su nazna�eni u komentarima.
Oni su se dogodili kao rezultat plitkog kopiranja (eng. *shallow copy*) prilikom pozivanja podrazumijevanog
kopirnog konstruktora i operatora pridru�ivanja. Za oba ova slu�aja potrebno je realizirati duboko kopiranje tako da kona�ni ispis bude:

```
6677889900
1122334455
1234567890
6677889900
```

Dodatak: Napi�ite prijenosni konstruktor i operator pridru�ivanja sa semantikom prijenosa za klasu Student.