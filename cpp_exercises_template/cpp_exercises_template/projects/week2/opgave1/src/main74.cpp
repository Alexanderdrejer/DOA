// // Week 2 - Opgave 1: Klasser
// #include <iostream>
// #include "person.h"  // Fra shared/include/
// #include <cmath>
// #include <chrono>


// int minFunktion1(int n);
// int minFunktion2(int n);
// int minFunktion3(int n);
// int minFunktion4(int n);

// int minFunktion1(int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         ++sum;
//     }
//     return sum;
// }

// int minFunktion2(int n) {
//     int sum = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             sum++;
//         }
//     }
//     return sum;
// }

// int minFunktion3(int n) {
//     int sum = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n * n; ++j) {
//             sum++;
//         }
//     }
//     return sum;
// }

// int minFunktion4(int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < i; ++j)
//         ++sum;
//     }
//     return sum;
// }

// int main() {


//     // Spørgsmål 1.
//     // Estimate the worst-case complexity of your program and justify with a 
//     // line-by-line explanation of the steps taken in the program.

//     // Worst case er O(N) og dermed lineær tid.
//     // Da hver vektor bliver gennemløbet én gang, afhænger tids-kompleksiteten udelukkende af,
//     // hvor mange elementer der skal ind på vektorerne.

//     // Spørgsmål 2.
//     // What is the time-complexity (Big-Oh) of myMethod? Argue for your answer.
//     // Jeg tæller først antallet af løkker med betingelsen N. Der findes 3.
//     // Udgangspunktet er altså en time-complexity på N*N*N. Jeg ignorerer den sidste løkke,
//     // da den er mindre end de andre og dermed ikke den der trækker time-complexity højere.
//     // Regnestykket bliver altså:
//     // N*N*sqrt(N) = N^2 * N^0.5.
//     // Time-complexity = N^2.5.
//     // Antallet af operationer er altså N^2.5. Jo større N jo mange, mange flere operationer.
//     // Jeg kan undersøge hvor mange operationer programmet laver, hvis N fordobles.
//     // N = 10 = 10^2.5 = 316.
//     // N = 2= = 20^2.5 = 1788
//     // 1788/316 = 5.66 gange så mange operationer, når N fordobles.

// // int myMethod(int N);

// //     int myMethod(int N) {
// //         int x = 0;
// //         int y = 0;
// //         for (int j = 0; j < N; j++) {
// //             for (int k = 0; k < N * sqrt(N); k++) {
// //                 x++;
// //             }
// //         }
// //     }
// //     for (int i = 0; i < N; i++) {
// //         y++;
// //     }


// // Spørgsmål 3.
// // ::For each of the following our program fragments::
// // Give an analysis of the running time in Big-oh notation.
// // Spørgsmål 3.a:
// // Kode(1): = O(N). Lineær tid
// // Kode(2): = n*n = O(N^2). Kvadratisk tid.
// // Kode(3): = n*n*n = O(N^3). Kubisk tid.
// // Kode(4): i*j = O(N^2). Kvadratisk tid.

// // Spørgsmål 3.b:
//     //::::Kode 1::::://

//             // auto start = std::chrono::high_resolution_clock::now();

//             // int sum = minFunktion1(1000000000);

//             // auto stop = std::chrono::high_resolution_clock::now();
//             // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            
//             // std::cout << "N = " << sum << " -> " << duration.count() << " μs" << std::endl;

//             // N = 1000 = 0 mikrosekunder.
//             // N = 10000 = 4 mikrosekunder.

//     //::::Kode 2::::://
//             // auto start = std::chrono::high_resolution_clock::now();

//             // int sum = minFunktion2(20000);

//             // auto stop = std::chrono::high_resolution_clock::now();
//             // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            
//             // std::cout << "N = " << sum << " -> " << duration.count() << " μs" << std::endl;

//     // n = 100*100 = 10000 operationer = 4 mikrosekunder.
//     // n = 200 * 200 = 40000 operationer = 13 mikrosekunder.
//     // Når n fordobles, stiger antallet af operationer med 13/4 = 4,6x 
//     // Varierer ret meget per run??

//     //::::Kode 3::::://
//                 // auto start = std::chrono::high_resolution_clock::now();

//                 // int sum = minFunktion3(800);

//                 // auto stop = std::chrono::high_resolution_clock::now();
//                 // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                
//                 // std::cout << "N = " << sum << " -> " << duration.count() << " μs" << std::endl;

//     // 400*400*400 = 64000000 operationer = 4 mikrosekunder.
//     // 800*800*800 = 512000000 operationer = 20 mikrosekunder.
//     // Når n fordobles, stiger antallet af operationer cirka med 8x.

//     //::::Kode 4::::://
//     auto start = std::chrono::high_resolution_clock::now();

//     int sum = minFunktion4(40000);

//     auto stop = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
//     std::cout << "N = " << sum << " -> " << duration.count() << " μs" << std::endl;

//     //49995000 operationer = 15263 mikrosekunder.
//     //199990000 operationer = 60301 mikrosekunder. 
//     //60301/15263 = 3,9x så mange operationer når n fordobles.

//     return 0;
// }
