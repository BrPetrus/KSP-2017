#include <iostream>

using namespace std;

int nGladiatorov = 0;
int* silaMec = nullptr;
int* silaKopia = nullptr;

int main() {
    // Nacitanie vstupu
    cin >> nGladiatorov;
    silaMec = new int[nGladiatorov]; // Sila s mecom v poradi
    silaKopia = new int[nGladiatorov]; // Sila s kopiou v poradi
    for (int i = 0; i < nGladiatorov; i++) {
        cin >> silaMec[i] >> silaKopia[i];
    }

    // Algoritmus
    for (int i = 0; i < nGladiatorov; i++) {
        int bitkoiny = 1;
        
        // Najskor sa pozrieme na tych pred nim
        for (int j = 0; j < i; j++) {
            if (silaMec[i] > silaMec[j] || silaKopia[i] > silaKopia[j]) {
                bitkoiny++;
            }
        }
        // Potom na tych za nim
        for (int j = (i+1); j < nGladiatorov; j++) {
            if (silaMec[i] > silaMec[j] || silaKopia[i] > silaKopia[j]) {
                bitkoiny++;
            }
        }

        cout << bitkoiny << "\n";
    }

    delete[] silaMec;
    delete[] silaKopia;
    return 0;
}