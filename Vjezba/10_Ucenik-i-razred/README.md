# 10. Učenik i razred

Neka u programu postoje sljedeće klase:

```cpp
struct Ucenik {
	string ime, prezime;
};

class Razred {
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena;
};
```

Napišite sve potrebne metode unutar klase Razred kojima ćete demonstrirati semantiku kopiranja u funkciji main.
Također, u funkciji main demonstrirajte primjerima kako bi izgledala semantika prijenosa (nije potrebno pisati metode unutar klase Razred).
