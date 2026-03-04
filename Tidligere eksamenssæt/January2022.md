# Opgave 1 - Big Oh
# Kun gennemførtopgave 1 og 2 per 25/2 2026.

Hvad er Big Oh tidskompleksiteten af func1? Begrund dit svar.

```cpp
int func2 (int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = res + 1;
    }
    return res;
}

int func1 (int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = x + func2(n);
    }
    return x;
}
```

I func1 kaldes func2, der indeholder en løkke. Det betyder, at der er tale om en slags "nested" for-loop, da jeg for hver iteration af løkken i func1 skal løbe igennem for-løkken i func2. Der er altså tale om $n*n = O(n^2)$


# Opgave 2 - Rekursiv funktion.

Skriv en rekursiv funktion med følgende signatur:

```cpp 
int sumDivisiblyBy3(int N);
```

    Algoritmen returnerer summen af positive heltal større end 0 og mindre end eller lig med N, som er dividerbare med 3. Du kan antage at N >= 0.

    Kaldt med N = 12 er den korrekte returværdi 30 (3+6+9+12). Kaldt med N = 14 er den korrekte returværdi også 30.

    Du bedes optimere din metode/algoritme, således at overflødige rekursive kald undgås.

Jeg vurderer base case er når N < 3, da det jo skal være deleligt med 3. Jeg laver algoritmen således, at den kun vurderer tal der er delelige med 3.

Jeg kunne tilføje et else if til min base-case der tjekker om N er deleligt med 3. Hvis ikke, skal jeg sikre mig den er det og sende det tal videre. Så kunne jeg i princippet udfase N % 3 == 0, da jeg sikrer mig tallet altid er deleligt med 3.

```cpp
int sumDivisiblyBy3(int N) {

    if (N < 3) return 0;

    if (N % 3 == 0) {
        return N + sumDivisiblyBy3(N-3);

    }
    else {
        return sumDivisiblyBy3(N - (N % 3));
    }
    
}
```