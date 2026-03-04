## Opgave 7

#### Nedenstående tabel er en hashtabel, hvor der anvendes quadratic probing i tilfælde af kollisioner (collision resolution). Hashfunktionen er $h(x) = x \bmod 11$. Følgende værdier er indsat: 22, 5, 16 og 27 (i denne rækkefølge).
Opgave: Verificer at hashtabellen er korrekt og ret eventuelle fejl. Vis tabellens udseende efter at elementerne 1, 12, [alder] samt [studienummer] er indsat, og begrund hvorfor det indsættes, hvor det indsættes, samt forklar hvad det derudover sker.

Først undersøger jeg om værdierne er indsat korrekt.

22 % 11 = 0 --> Korrekt.
1 % 11 = 1 --> Korrekt.
5 % 11 = 5 --> Korrekt.
16 & 11 = 5. Kollision. 5+1^2 = 6. Korrekt.
27 % 11 = 5. Kollision: 5+1^2 = 6. Kollision. 5+2^2 = 9. Korrekt.

| Index | | Key |
| :--- | :--- | ---: |
| 0 | | 22  |
| 1 | | 1|
| 2 | | |
| 3 | | |
| 4 | | |
| 5 | | 5 |
| 6 | | 16 |
| 7 | | |
| 8 | | |
| 9 | | 27 |
| 10 | | |

Udgangspunktet er altså korrekt.
Da listen kun er 10 pladser stor og der bruges quadratic probing skal vi rehashe hver gang vi overstiger $\lambda$ = 0.5. Vi indsætter elementerne i den givne rækkefølge, 1, 12, 32, 555707.

Før da rehasher vi, da $\lambda$ = 5/10 = 0.5. Vi vælger det primtal der er tættest på at være dobbelt så stort, altså 23. Vi genberegner alle de keys også med udgangspunktet i at listen nu er tom.

22 % 23 = [22].
5 % 23 = [5]. 
16 % 23 = [16]
27 % 23 = [4]

Og de givne værdier fra opgaven:
1 % 23 = [1]
12 % 23 = [12]
32 % 23 = [9]
555707 % 23 = [4] Kollision: 4+1^2 = [5] Kollision: $4+2^2 = [8]$

| Index | | Key |
| :--- | :--- | ---: |
| 0 | |   |
| 1 | | 1|
| 2 | | |
| 3 | | |
| 4 | | 27|
| 5 | | 5 |
| 6 | | |
| 7 | | |
| 8 | |555707 |
| 9 | |32 |
| 10 | | |
| 11 | | |
| 12 | |12 |
| 13 | | |
| 14 | | |
| 15 | | |
| 16 | |16 |
| 17 | | |
| 18 | | |
| 19 | | |
| 20 | | |
| 21 | | |
| 22 | |22 |

