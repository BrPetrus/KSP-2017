#include <iostream>
#include <string>

long long vypocitajMocninu(long long b,long long e) {
    const long long m = 1000000007;
    long long c = 1;
    long long e2 = 0;

    while(e2 < e) {
        e2++;
        c = (b*c) % m;
    }

    return c;
}

int main() {
    std::string instrukcia;
    std::cin >> instrukcia;

    long long sucet = 0;
    long long base = 0;
    long long nHviezdiciek = 0;

    for(int index = instrukcia.size() - 1, rad = 0; index >= 0; index--, rad++) {
        char i = instrukcia[index];
        if(i == 'L') {
            //
        }
        else if(i == 'P') {
            base += 1 << rad;
        }
        else if(i == '*') {
            sucet += 1 << rad;
            nHviezdiciek++;
        }
    }

    base = base % 1000000007;
    long long min = vypocitajMocninu(2, instrukcia.size());
    long long odpoved = (min + base)*vypocitajMocninu(2, nHviezdiciek);
    odpoved += sucet*vypocitajMocninu(2, nHviezdiciek-1);

    std::cout << odpoved % 1000000007 << std::endl;
    return 0;
}