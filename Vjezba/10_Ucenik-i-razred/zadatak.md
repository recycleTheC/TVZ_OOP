# 10. U�enik i razred

Neka u programu postoje sljede�e klase:

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

Napi�ite sve potrebne metode unutar klase Razred kojima �ete demonstrirati semantiku kopiranja u funkciji main.
Tako�er, u funkciji main demonstrirajte primjerima kako bi izgledala semantika prijenosa (nije potrebno pisati metode unutar klase Razred).