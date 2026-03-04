#include <iostream>

void insertionSort(int arr[], int size);

// Den sammenligner 

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

int main() {

    int array[] = {9,1,8,2,3,8,4,7,5,6};
    int size = 10;

    insertionSort(array, 10);

    for (const auto &i : array) {
        std::cout << i << " ";
    }


    return 0;
}