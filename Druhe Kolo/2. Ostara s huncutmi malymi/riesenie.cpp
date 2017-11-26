#include <iostream>

int main(int argc, char* argv[]) {
    int n, v; // Pocet omrviniek, expanzivnost
    std::cin >> n >> v;
    int l = n+1; // Dlzka
    int* mapa = new int[n+2];
    for (int i = 0; i < n+2; i++) {
        mapa[i] = 0;
    }
    mapa[l] = 1; // Na konci je akokeby cokolada

    int den = 0; // Momentalny den
    int hranica = 0; // Hranica mraveniska

    while(hranica < l) {
        int p, d; // Pozicia cokolady, den
        std::cin >> p >> d;

        // Ak dalsia cokolada padne neskor
        if(den < d) {
            for (int i = den; i < d; i++) {
                std::cout << hranica << "\n";
            }
        }
        den = d;

        mapa[p] = 1; // Zaznac na mape kde padla cokolada

        // A teraz expanzia
        bool expandovat = true;
        while(expandovat) {
            expandovat = false;
            // Ideme odzadu
            for (int i = hranica+v; i > hranica; i--) {
                if (i > l) 
                    continue;
                if (mapa[i] == 1) { // Mozme rosirit hranicu
                    hranica = i;
                    expandovat = true;
                    break;
                }
            }
        }

    }
    std::cout << hranica << "\n";

    delete[] mapa;
    return 0;
}