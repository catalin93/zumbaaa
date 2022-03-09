# zumbaaa
Acest program este asemanator cu celebrul zoc Zumba. Ca date de intrare se da un sir de cifre separate prin spatiu, iar pentru a te opri in a mai introduce cifre trebui se tastezi o valoare negativa (ex -1).
Se va elimina cel mai maresir de cifre identice mai mare sau egal decat 3, daca avem 2 siruri egale ca marime se va elimina cel din stanga. Daca in urma eliminarii celui mai mare sir se vor alaturaalte cifre identicesi se va forma alt sir cu cifre identicesi va avea lungimea mai mare sau egala cu 3 se va elimina si noul sir format. 
ex.  1 1 5 2 2 8 8 8 8 2 5 5 5 7 7 7 6 devine 1 1 7 7 7 6
In finalul programului vom avea un sir cu maxim 2 cifre identice una dupa alta.
Pentru a realiza acest joc am creat doi vectori:
-	un vector de frecvente care inregistreaza de cate ori apare o cifra consecutiv in sirul initial.
-	un vector de cifre pentru a inregistra cifrele din sir
ex. sir de cifre: 1 1 1 3 3  5 7 7 vect. frecvente: 3 2 1 2 si vector de cifre: 1 3 5 7
Parcurgem vectorul de frecvente si cautam pozitia pe care se afla cel mai mare numar, este notat cu iMax in rogram.
Dupa ce am gasit iMax comparam cifrele din stanga si din dreapta pozitie lui , iar daca cifrele sunt egale si suma frecventelor lor este mai mare sau egala cu 3 se va creste valoarea lui n din program, care reprezinta latimea sirului eliminat.
ex. 1 1 2 2 3 4 4 4 4 3 3 2 5 5 6  n=2
Dupa ce am aflat latimea sirului de eliminat eliminam in vectorul de cifre si de frecvente elementele ce se afla intre pozitiile iMax –n si iMax+n
ex. frecv: 2 2 1 3 2 1 2 1 devine 2 2 1  unde iMax=3 si n=2
       cifre: 1 2 3 4 3 2 5 6 devine 1 5 6
Repetam aceste operatii pana cand nu mai avem niciun numarin vectorul de frecvente mai mare sau egal cu 3.
