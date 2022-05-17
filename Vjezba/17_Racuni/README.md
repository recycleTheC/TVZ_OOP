# 17. Dokumenti

U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno definirati
barem jedno nasljeđivanje.

Nadograđujete sustav koji se bavi informatizacijom poduzeća. Zaduženi ste za informatizaciju dokumenata. Trenutno je poznato da postoji nekoliko vrsta
dokumenata. Za svaki dokument se zna da ima podatke o tome tko ga je napravio, datum i vrijeme nastanka dokumenta, te njegov jedinstveni broj (svaki
dokument ima jedinstveni broj - string koji može sadržavati brojke, crtice "-" i slasheve "/" ). Vi ste zaduženi da napravite dokument koji predstavlja
račun. Račun, uz osnovne podatke koje ima svaki dokument, ima također JIR i tip računa (R1 ili obični). Račun ima niz stavki. Svaka stavka sadrži
podatak o nazivu usluge koja je napravljena, količinu i jediničnu cijenu. Za račun se također mora znati kolika je ukupna suma njegovih stavki.
Račun mora imati mogućnost obračunavanja popusta, na način da se postotak popusta primijeni na svaku stavku. Također, račun se mora moći ispisati
(zajedno sa svim podacima i stavkama).