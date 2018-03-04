#include <iostream>
#include <string>
#include <queue>
#include <cmath>

std::queue<long long> stanice;

void vygenerujStanice(std::string instrukcia) {
    stanice.push(0);
    for(int pos = instrukcia.size()-1, rad = 0; pos >= 0; pos--, rad++) {
        char i = instrukcia[pos];

        int size = stanice.size();
        for(int s = 0; s < size; s++) {
            long long x = stanice.front();
            //stanice.pop();
            if(i == 'L') {
                //stanice.push
            }
            else if(i == 'P') {
                stanice.pop();
                stanice.push(x + (1 << rad));
            }
            else if(i == '*') {
                stanice.pop();
                stanice.push(x);
                stanice.push(x + (1 << rad));
            }
        }
        
    }
}

long long vypocitajMin(long long e) {
    const long long m = 1000000007;
    long long c = 1, b = 2;
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
    vygenerujStanice(instrukcia);
    
    long long min = vypocitajMin(instrukcia.size());

    // Spocitaj
    int size = stanice.size();
    long long odpoved = 0;
    for(int i = 0; i < size; i++) {
        odpoved += (min + stanice.front());
        stanice.pop();
    }

    std::cout << odpoved % 1000000007 << "\n";
    return 0;
}