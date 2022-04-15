# 10. Uèenik i razred

Neka u programu postoje sljedeæe klase:

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

Napišite sve potrebne metode unutar klase Razred kojima æete demonstrirati semantiku kopiranja u funkciji main.
Takoðer, u funkciji main demonstrirajte primjerima kako bi izgledala semantika prijenosa (nije potrebno pisati metode unutar klase Razred).