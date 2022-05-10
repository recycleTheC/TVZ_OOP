# MojVektor

Deklarirajte klasu `MojVektor` koja predstavlja vektor realnih brojeva čiji su elementi smješteni u privatnom dijelu klase. Zatim realizirajte sljedeće:

1. U funkciji `main` ispišite koliko postoji "živih" instanci objekata tip `MojVektor` pozivom metode `brojac` na sljedeći način:
`cout << MojVektor::brojac() << endl;`.

2. U klasi `MojVektor` deklarirajte metodu `GetElement` koja kao parametar ima indeks, tj. cijeli broj. Ukoliko je indeks negativan broj, metoda
mora baciti iznimku tipa `MojVektorException`, a u protivnom potrebno je vratiti vrijednost koja se nalazi u traženom elementu vektora. Metodu
`GetElement` implementirajte van klase, a u funkciji `main` demonstrirajte njen poziv gdje se prilikom hvatanja iznimke treba izvršiti metoda `ispis`
klase `MojVektorException` koja će ispisati odgovarajuću poruku korisniku.

3. Implementirajte operaciju zbrajanja dva objekta tipa `MojVektor` kao nečlansku operatorsku funkciju koja kao rezultat vraća novi vektor sa svim
elementima prvog i drugog vektora. Demonstrirajte poziv operatora u funkciji `main`. Elementi vektora klase `MojVektor` moraju ostati privatni.

4. Implementirajte prefiks i postfiks operatore unutar klase `MojVektor`. Oba operatora trebaju uvećati sve elemente vektora za vrijednost 1.

5. Preopteretite operator `<<` za ispis svih elemenata objekta tipa `MojVektor`, te operator `>>` kojim se nova (učitana) vrijednost dodaje tom vektoru.