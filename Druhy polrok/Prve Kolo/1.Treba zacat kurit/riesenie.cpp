#include <iostream>
#include <string.h>


long long vyries() {
    long long riesenie = 0;
    
    // Nacitaj vstup
    long long n, k;
    std::cin >> n >> k;

    // Najdi najmenej dolezite
    int pos = ffsll(k) - 1;

    riesenie = n - pos;

    return riesenie;
}

int main() {
    // Nacitaj vstup
    int t;
    std::cin >> t; // Pocet otazok
    
    for(int i = 0; i < t; i++) {
        std::cout << vyries() << std::endl;
    }


    return 0;
}