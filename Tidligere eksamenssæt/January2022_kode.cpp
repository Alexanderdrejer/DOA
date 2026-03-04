#include <iostream>
#include <cmath>

int sumDivisiblyBy3(int N);

int sumDivisiblyBy3(int N) {

    if (N < 3) return 0;

    if (N % 3 == 0) {
        return N + sumDivisiblyBy3(N-3);
    }
    else {
        return sumDivisiblyBy3(N-(N % 3));
    }

}

int produkt4tabel(int tal);
int produkt4tabel(int tal) {
    if (tal < 4) return 1;

    if (tal % 4 == 0) {
        return tal * produkt4tabel(tal - 4);
    } else {
        return produkt4tabel(tal - (tal % 4));
    }

}



int main() {

    std::cout << produkt4tabel(16) << "\n";

    return 0;
}