# Opgave 1
### (Week 4) Let $T$ by a hash-table of size 7 with the hash function $h(x) = x \bmod 7$. Write down the entries of $T$ after the keys 5, 28, 19, 15, 20, 33, 12, 17, 33 and 10 have been inserted using(a) chaining(b) linear probing(c) quadratic probingRehash if nescessary. What is the load-factor($\lambda$) in the three cases?

Jeg ved at hash-funktionen er % 7. Jeg lægger altså hver variabel ind i min hash-funktion og undersøger hvad indekset bliver og hvordan det håndteres af de forskellige metoder når der opstår collision.

Først ser jeg, at der min liste har 7 pladser, men der er 10 objekter. Loadfaktoren, $\lambda$, er altså: 10/7 = 1.42.
Det betyder, at for:
#### Chaining bliver listerne på hvert indeks bare længere.
#### Lineær probing skal jeg rehashe da $\lambda$ > 0.7.
#### Quadratic probing skal jeg rehashe da $\lambda$ > 0.5.

Jeg ligger nu hvert element ind i min hash-funktion og tildeler dem et plads på listen. Det ser forskelligt ud for hver metode.

## Chaining
| Key ($x$) | $h(x) = x \bmod 7$ | Indeks |
| :--- | :---: | :---: | 
| **5** | 0 |0 |
| **28** | 4 |4 |
| **19** | 5 | 5|
| **15** | 1 | 1|
| **20** |6 | 6|
| **33** |5 |5->next |
| **12** |5 |5->next->next |
| **17** |3 |3 |
| **33** |5 |5->next->next->next |
| **10** |3 |3->next |

Hvert indeks er en liste i sig selv, så ->next repræsentere det næste element på indekset i listen.

## Linear probing
Her bliver det relevant at rehashe, da listen er for lille. Jeg skal vælge et primtal efter 7, og da det gerne må være dobbelt så stort, vælger jeg primtallet 17, da det er det tætteste tal på 14 efter 14. Det gør jeg for at holde load-faktoren nede. 
--> betyder efter rehashing.
| Key ($x$) | $h(x) = x \bmod 7$ | Indeks |
| :--- | :---: | :---: | 
| **5** | 0 | [5] --> [5] |
| **28** | 4 |[4] --> [11] |
| **19** | 5 |[5] --> [2] |
| **15** | 1 |[1] --> [15] |
| **20** |6 |[6] --> [3]|
| **33** |5 | [7] -> REHASHING --> [16] |
| **12** |5 | [5] --> [12] |
| **17** |3 | -->[0] |
| **33** |5 |-->[16] Kollision, derfor wrap-around* [16]=[0] --> Pladsmangel, så  den får indeks [1]|
| **10** |3 | -->[10]|

Wrap-around bruges her da load-faktor stadig er under de magiske 0.7 for lineær probing $\lambda$ 7/17 = 0.41.

## Quadratic probing
Da en load-factor på 0.5 betyder rehashing for quadratic probing kan det hurtigt ses, at det er nødvendigt at rehashe 2 gange undervejs grundet listens størrelse. Loadfaktor overstiges første gang når key 15 skal ind ($\lambda$ = 0.57) og igen efter første rehash ved key 9 ($\lambda$ = 9/17 = 0.52). Der rehashes to gange med det samme og hele listen udregnes herfra.

Ved rehashing vælger jeg altid primtal og gerne nogle der er dobbelt så store som det nuværende. 
7 bliver til primtal 17. Primtal 17 bliver til primtal 37. Derfor bliver hashfunktionen key % 37.

| Key ($x$) | $h(x) = x \bmod 37$ | Indeks |
| :--- | :---: | :---: | 
| **5** | 5 | [5] |
| **28** | 28 | [28] |
| **19** | 19 | [19] |
| **15** | 15 |[15] |
| **20** |20 | [20]|
| **33** |33 |[33] |
| **12** |12 |[12] |
| **17** |17 |[17]|
| **33** |33 |[33] -- Kollision. $33+1^2 = [34]$ |
| **10** |10 |[3] |

### Uden 2x rehashing til at starte med:

| Key ($x$) | $h(x) = x \bmod 7$ | Indeks |
| :--- | :---: | :---: | 
| **5** | 5 | [5] --> [5] --> [5] |
| **28** | 28 | [7] --> [0] --> [28] |
| **19** | 19 | [5] Kollision: 5+1^2 = [6]. Vi overstiger loadfactor herefter. $\lambda$ = 4/7 = 0.57 Vi rehasher til nærmeste dobbelte primtal hvilket er 17 --> [2] --> [19]|
| **15** | 15 | -->[15] --> [15] |
| **20** |20 | -->[3] --> [20]|
| **33** |33 |[33] --> [16] --> [33] |
| **12** |12 |[12] --> [12] --> [12] |
| **17** |17 |[17] --> [0] Kollision: 0+1^2 = [1] --> [17]|
| **33** |33 |[33] $\lambda$ $= 9/17 = 0.52$. Vi rehasher igen-igen. Nærmeste dobbelte primtal er 37. --> [33]. Kollision: $33+1^2 = [34]$ |
| **10** |10 |[3] --> [10] |