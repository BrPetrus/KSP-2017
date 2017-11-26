#include <iostream>
#include <set>

int main(int argc, char* argv[]) {
    int n, v; // Pocet omrviniek, expanzivnost
    std::cin >> n >> v;
    int l = n+1; // Dlzka

    int den = 0; // Momentalny den
    int hranica = 0; // Hranica mraveniska

    std::set<int> cokolady;
    cokolady.insert(0);
    cokolady.insert(l);

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

        cokolady.insert(p);
        std::set<int>::iterator i;
        for(i = cokolady.find(hranica); i != cokolady.end(); i++) {
            if (*i <= hranica+v) {
                hranica = *i;
            }
        }
    }
    std::cout << hranica << "\n";

    return 0;
}