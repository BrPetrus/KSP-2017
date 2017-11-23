#include <iostream>

typedef long long llong;

int main() {
    int q; // Pocet cokolad
    std::cin >> q;

    // Iterujme cez jednotlive cokolady
    for (int i = 0; i < q; i++) {
        llong cokolada; // Aktualna cokolada, ktoru riesime
        std::cin >> cokolada;

        int pocetRozdeleni = 0;
        while (cokolada % 2 == 0) {    // Ak mozme spravodlivo rozdelit
            pocetRozdeleni++;
            cokolada /= 2;
        }

        if (cokolada == 1) {
            std::cout << 1 << "\n";
            continue;
        }
        std::cout << cokolada << "\n";
    }


    return 0;
}