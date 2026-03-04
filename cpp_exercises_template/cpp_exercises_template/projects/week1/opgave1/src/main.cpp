
#include <iostream>
#include <ctime>
#include <vector>

int main() {
    srand(time(0));
    std::vector<int> vector1;

    int tilfaeldigt_tal = rand() % 101; 
    int counter = 0;

    for (int i = 0; i < tilfaeldigt_tal; ++i) {
        vector1.push_back(rand() % 101);
    }

    for (int i = 0; i < tilfaeldigt_tal; ++i) {
        int random_tal = rand() % 101; 

            for (auto itr = vector1.begin(); itr != vector1.end(); ++itr) {

                    if (*itr == random_tal) {
                   ++counter;
                   }  
                } 
            } 

    std::cout << "Antallet af matchende tal: " << counter <<  std::endl;

    return 0;
}
