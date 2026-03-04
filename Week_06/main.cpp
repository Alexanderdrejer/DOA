#include <iostream>


bool search(int a[], int size, int tal);
bool search(int a[], int size, int tal) {
// Worst case time complexity er O(n) da hele listen løbes igennem hver gang. 

    if (size == 0) { // Base case. 
        return false;
    } 
    
    else if (a[size - 1] == tal) { 
        // Er base-casen ikke nået, tjek fra [size - 1] om tallet er der.
        return true;
    }

    else {
        return search(a, size - 1, tal); 
        // Hvis hverken base-case eller tallet er fundet, kald igen.
        // Antag funktionen er kaldt én gang: Anden gang kommer der en ny stackframe på, som 
        // kigger fra size - 1, altså 9. Næste gang size - 1 igen, så 8 osv.
    }
}

struct MinMax {
    int min;
    int max;
};

MinMax min_max_(int array[], int size);

MinMax min_max_(int array[], int size) {
// Time complexity for denne funktion er O(n).
// Det skyldes, at listen bliver løbet hele vejen igennem hver gang.

        if (size == 1) {
            return MinMax{array[0], array[0]};
        } 

        else {

        MinMax result = min_max_(array, size - 1);

        if (result.min > array[size - 1]) {
            result.min = array[size - 1];
        }

        if (result.max < array[size - 1]) {
            result.max = array[size - 1];
        }

        return result;

        }
    
}


void triangle(int m, int n);
void triangle(int m, int n) {

    if (m > n) return; 
    // Base case. Vi skal over n, da det jo er grænsen for antallet af stjerner.

    for (int i = 0; i < m; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";
    // Her printes stjernerne på vej "ned" i stacken. 
    // Denne del af koden lægger altså en masse stackframe på callstacken,
    // der hver især har en værdi af m.

    triangle(m+1, n);
    // Rekursionen sker her, da vi vil tilføje stackframes indtil base-casen er opfyldt.
    // Vi har tilføjet en masse stackframes på callstacken med sin egen værdi af m. 

    for (int i = 0; i < m; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";

}


const int RAEKKE = 5;
const int KOLONNE = 5;


bool maze(char arrayet[RAEKKE][KOLONNE], int raekke, int kolonne);
bool maze(char arrayet[RAEKKE][KOLONNE], int raekke, int kolonne) {
    // Base-case 1: Er jeg stadig i mazen?
    if (raekke < 0 || kolonne < 0 || raekke >= RAEKKE || kolonne >= KOLONNE) return false;
    // Base case 2: Har jeg ramt et 'X' eller har jeg været her?
    if (arrayet[raekke][kolonne] == 'X' || arrayet[raekke][kolonne] == '.') return false;
    // Base case 3: Har jeg ramt udgangen?
    if (arrayet[raekke][kolonne] == 'E') return true;
    arrayet[raekke][kolonne] = '.';

    // Hvis jeg laver et rekursivt kald nu med raekke + 1, 
    // og base cases ikke er opfyldt, betyder det at jeg kan gå
    // derhen.
    if (maze(arrayet, raekke + 1, kolonne)) {
        return true;
    }
    if (maze(arrayet, raekke - 1, kolonne)) {
        return true;
    }
    if (maze(arrayet, raekke, kolonne - 1)) {
        return true;
    }
    if (maze(arrayet, raekke, kolonne + 1)) {
        return true;
    }

    return false;
}


// bool labyrint(char arrayet[KOLONNE][RAEKKE], int kolonne, int raekke);
// bool labyrint(char arrayet[KOLONNE][RAEKKE], int kolonne, int raekke) {

//     if (raekke < 0 || raekke >= RAEKKE || kolonne < 0 || kolonne >= KOLONNE) return false;
//     if (arrayet[kolonne][raekke] == 'X' ||arrayet[kolonne][raekke] == '.') return false;
//     if (arrayet[kolonne][raekke] == 'E') return true;
//     arrayet[kolonne][raekke] = '.';

//     if (labyrint(arrayet, kolonne - 1, raekke)) 
//     {
//         return true;
//     }
//     if (labyrint(arrayet, kolonne + 1, raekke)) 
//     {
//         return true;
//     }
//     if (labyrint(arrayet, kolonne, raekke - 1)) 
//     {
//         return true;
//     }
//     if (labyrint(arrayet, kolonne, raekke + 1)) 
//     {
//         return true;
//     }

//     return false;
// }


int main() {

    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "OPGAVE 1\n";
    std::cout << search(array, 10, 4) << "\n";
    std::cout << "-----------\n";
    
    std::cout << "OPGAVE 2\n";
    MinMax resultatet{0,0};
    resultatet = min_max_(array, 10);
    std::cout << "Mindste tal: " << resultatet.min << " \nStoerste tal: " << resultatet.max << "\n";
    std::cout << "-----------\n";

    std::cout << "OPGAVE 3\n";
    triangle(4,6);
    std::cout << "-----------\n";

    std::cout << "OPGAVE 4\n";
    char arrayet[RAEKKE][KOLONNE] = {
        {'X', 'X', ' ', 'X', ' '},
        {'X', ' ', ' ', 'X', ' '},
        {'X', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'X', 'X'},
        {' ', ' ', ' ', ' ', 'E'}
    };

    std::cout << maze(arrayet, 1, 1);
    std::cout << "-----------\n";


    return 0;
}