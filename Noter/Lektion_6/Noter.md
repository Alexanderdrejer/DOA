# Lecture 6 – Sortering af Arrays

## 1. Sorteringsproblemet
Givet et array med N elementer, find en permutation af elementerne så:
A'₀ ≤ A'₁ ≤ … ≤ A'ₙ₋₁

## 2. Insertion Sort
Samme princip som at sortere spillekort i hånden: tag ét kort ad gangen og sæt det på den rigtige plads i den allerede sorterede del.

### Algoritmen trin for trin

•	Start ved index p = 1

•	Gem A[p] i en midlertidig variabel tmp

•	Skyd elementer til højre (A[j] = A[j-1]) så længe tmp < A[j-1]

•	Indsæt tmp på den ledige plads


```cpp
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) { // Vi sammenligner til venstre, så i = 1 som start!
        int temp = arr[i]; // 
        int j = i - 1; 
            // Hvilken værdi er det vi sammenligner emd til venstre for i? 
            // Det er altså værdien til venstre for den vi har fat i.
        while (j >= 0 && arr[j] > temp) {
            // j større end 0 sikrer at vi ikke går ud af array.
            // arr[j] > temp er selve sorteringen. 
                // Så længe elementet til ventre for temp, så det rykket til højre. 
            arr[j+1] = arr[j];
                // Her rykker vi til højre. 
            j--;
        }
        arr[j+1] = temp;
    }
}
```
### Kompleksitet
    Best case = O(n) hvis arrayet allerede er sorteret.

    Worst case = O(n²) Array er omvendt sorteret.

Insertion Sort er kun god til små arrays eller næsten-sorterede data. Quadratic er ikke skalerbart og kommer til at tage 1000 år.

## 3. Merge Sort
Idé — Divide & Conquer AKA det foregår typisk rekursivt.

For at bryde den kvadratiske grænse: opdel problemet i mindre dele.

    •	Del arrayet i to halvdele
    •	Sortér hver halvdel rekursivt
    •	Flet de to sorterede halvdele sammen i den rigtige rækkefølge

### Fletning (merge)
Nøglen til merge Sort er et effektivt merge-trin: sammenlign det mindste element fra hver halvdel og læg dem i den rigtige rækkefølge i et nyt array. Dette kræver O(n) ekstra hukommelse.

Kode (C++)
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmp,
               int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmp, left, center);       // Sortér venstre
        mergeSort(a, tmp, center+1, right);    // Sortér højre
        merge(a, tmp, left, center+1, right);  // Flet
    }
}

### Kompleksitet

Mergesort() er number of elements placed in the sorted array. MErge() operationen har O(n)

Rekursionstræet har O(log n) niveauer. På hvert niveau udføres O(n) arbejde (merge). Derfor:
T(n) = O(n log n)  —  alle cases!
•	Best, Average og Worst case er alle O(n log n)
•	Hukommelse: O(n) — kræver et hjælpearray af samme størrelse
•	Merge Sort er stabil (bevarer rækkefølgen af ens elementer)

4. Quick Sort
Idé — In-place Divide & Conquer
Quick Sort sorterer 'på stedet' uden ekstra array. Nøgleidéen er partitionering:
•	Vælg et pivot-element
•	Omarranger arrayet: alt < pivot til venstre, alt > pivot til højre
•	Pivot er nu på sin endelige plads
•	Sortér rekursivt de to dele til venstre og højre for pivot

Pivot-valg — vigtigt!
Pivot-valget er kritisk for performance:
Strategi	Problem	Resultat
Første element	Dårlig ved sorterede arrays	O(n²) worst case
Tilfældigt element	Overhead ved tilfældighedsgenerering	O(n log n) average
Median-af-tre ✓	Overhead ved beregning (lille)	O(n log n) average — bedst i praksis

Median-af-tre: eksempel
Array: [5, 1, 8, 2, 5, 7]
Left = 5 (index 0), Center = 8 (index 2), Right = 7 (index 5)
Median af [5, 8, 7] = 7  →  pivot = 7

Kompleksitet — DETTE SKAL DU KENDE
Case	Tid	Hukommelse	Hvornår?
Best case	O(n log n)	O(log n)	Altid perfekt opdeling
Average case	O(n log n)	O(log n)	Tilfældig rækkefølge
Worst case	O(n²)	O(n)	Altid dårlig opdeling (sjælden m. median-af-tre)

Hvorfor bruges Quick Sort overalt? Average-case er O(n log n), det er in-place (O(log n) stak), og konstant-faktoren er lav i praksis.

5. Sammenligning af alle tre algoritmer
Algorithm	Best	Average	Worst	Space
Insertion Sort	O(n)	O(n²)	O(n²)	O(1)
Merge Sort	O(n log n)	O(n log n)	O(n log n)	O(n)
Quick Sort	O(n log n)	O(n log n)	O(n²)	O(log n)

Tommelfingerregel:
•	Insertion Sort: Kun til meget små arrays (n < 20) eller næsten-sorterede data
•	Merge Sort: Når worst-case garanti er vigtig, eller data ikke er i RAM
•	Quick Sort: Standard valg — hurtigst i praksis til generelle formål

6. Nedre grænse for sammenligningsbaseret sortering
Spørgsmålet
Kan vi gøre det bedre end O(n log n)? For algoritmer der sorterer ved sammenligninger: NEJ.

Beslutningstre-argumentet
Forestil dig et beslutningstre, hvor:
•	Interne knuder = sammenligninger algoritmen foretager
•	Blade = mulige svar (permutationer af input)

For n elementer er der n! mulige permutationer, altså n! blade. For et binært træ med L blade er minimumshøjden ⌈log₂(L)⌉. Dermed:
Minimum antal sammenligninger = ⌈log₂(n!)⌉ = Ω(n log n)
Bevis for log(n!) = Ω(n log n):
lg(n!) ≥ n/4 · lg(n)  for n ≥ 16

Intuition: de øverste n/2 faktorer i n! er alle ≥ n/2,
  så  lg(n!) ≥ (n/2) · lg(n/2) ≥ (n/2) · (lg(n) - 1) = Ω(n log n)

Konklusion
Enhver algoritme der sorterer n elementer vha. sammenligninger
bruger mindst Ω(n log n) sammenligninger i worst case.

Merge Sort og Quick Sort (average) er dermed asymptotisk optimale!

7. C++ STL — std::sort
I praksis bruger du std::sort fra <algorithm>:
// Simpel sortering
std::sort(v.begin(), v.end());

// Med custom comparator
std::sort(v.begin(), v.end(), [](int a, int b){ return a < b; });

•	std::sort kræver random-access iteratorer
•	Implementeret som Introsort: Quick Sort + Heap Sort fallback (garanterer O(n log n) worst case)
•	En custom comparator kan gives for brugerdefinerede typer

8. Hvad er vigtigst til eksamen?
✓	Forstå Insertion Sort — hvorfor er den O(n²), og hvornår er den OK at bruge?
✓	Forstå Merge Sort-rekursionen og flet-steget — og at den er O(n log n) i alle cases
✓	Forstå Quick Sort med median-af-tre pivot — best/avg = O(n log n), worst = O(n²)
✓	Kunne forklare beslutningstre-argumentet: n! blade → ⌈log(n!)⌉ = Ω(n log n)
✓	Vide at Ω(n log n) er en nedre grænse — ingen sammenligningssortering kan gøre det bedre
✓	Kende space complexity: Insertion O(1), Merge O(n), Quick O(log n) stak
→	Nice-to-know: std::sort og Introsort-strategien

Algoritmer & Datastrukturer · AU Engineering · Forår 2025  |  Lecture 6
