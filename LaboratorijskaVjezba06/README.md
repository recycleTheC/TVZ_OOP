# 6. laboratorijska vježba

RGB boja se sastoji od crvene (Red), zelene (Green) i plave (Blue) komponente. Deklarirajte klasu `RGB` tako da je R, G i B dio u privatnom dijelu klase te se inicijaliziraju konstruktorom koji ima tri parametra.
Zatim, realizirajte sljedeće:

a) Ispišite koliko postoji RGB boja (objekata tipa RGB) čija vrijednost svake od tri R, G, B komponente tih objekata iznosi >= 128.
U funkciji main ispisati traženu količinu pozivom metode 'brojac' na sljedeći način:
`cout << RGB::brojac() << endl;`

b) U klasi RGB deklarirajte metodu `SetRGB` koja kao parametre ima tri prirodna broja (R, G i B).
Ukoliko bilo koji od ta tri broja nije u rasponu [0,255] metoda mora baciti iznimku tipa `RGBException`, a u protivnom potrebno je postaviti R, G, B dio boje na zadane vrijednosti.
Metodu SetRGB implementirajte van klase, a u funkciji main demonstrirajte njen poziv gdje se prilikom hvatanja iznimke treba izvršiti metoda
`ispis` klase `RGBException` koja će ispisati odgovarajuću poruku korisniku.

c) Implementirajte operaciju usporedbe dvije RGB boje kao nečlansku operatorsku funkciju te demonstrirajte njen poziv u funkciji main. R, G, B dijelovi boje moraju ostati privatni u klasi RGB.

d) Implementirajte prefiks i postfiks operatore unutar klase RGB. Oba operatora trebaju uvećati R, G i B dio boje za vrijednost 1. Ako je vrijednost pojedine komponente 255 uvećanje treba ignorirati za tu komponentu.

e) Preopteretite operatore `<<` i `>>` za ispis i unos objekata tipa RGB.

- Moguće je pisati sav programski kod u istoj (jednoj) datoteci!