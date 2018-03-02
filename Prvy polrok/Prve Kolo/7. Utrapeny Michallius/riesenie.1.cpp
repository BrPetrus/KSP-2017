#include <iostream>

using namespace std;

int nGladiatorov = 0;
int* silaMec = nullptr;
int* silaKopija = nullptr;

int main() {
    // Nacitanie vstupu
    cin >> nGladiatorov;
    silaMec = new int[nGladiatorov]; // Sila s mecom v poradi
    silaKopija = new int[nGladiatorov]; // Sila s kopiou v poradi
    for (int i = 0; i < nGladiatorov; i++) {
        cin >> silaMec[i] >> silaKopija[i];
    }

    // Algoritmus
    for (int i = 0; i < nGladiatorov; i++) {
        int sMec = silaMec[i], sKopija = silaKopija[i]; // Efektivna sila s mecom a kopiou
        for (int j = 0; j < nGladiatorov; j++) {
            if (sMec > silaMec[j] && sKopija < silaKopija[j]) {
                sKopija = silaKopija[j];
                j = -1; // Iterujme odznova s novymi silami
                continue; // Au ... takto by sa to nemalo robit
            }
            else if(sKopija > silaKopija[j] && sMec < silaMec[j]) {
                sMec = silaMec[j];
                j = -1; // Iterujme odznova s novymi silami
                continue;
            }
        }
        (sMec > sKopija) ? cout << sMec : cout << sKopija;
        cout << "\n";
    }

    delete[] silaMec;
    delete[] silaKopija;
    return 0;
}