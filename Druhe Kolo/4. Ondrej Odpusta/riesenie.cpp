#include <iostream>
#include <cmath>

unsigned long long c = 0;

// Na kolkatej cifre obsahuje
long long obsahuje(long long n) {
    long long a = 0;
    while(n > 0) {
        long long cifra = n%10;
        if (cifra == 5) {
            c -= a;
            return a;
        }
            
        n /= 10;
        a++;
    }
    c += a;
    return -1;
}

int najdiCifru(long long n, int index) {
    for (int i = 0; i < index; i++) {
        n /= 10;
    }
    return n%10;
}

int main() {
    int nOtazok;
    std::cin >> nOtazok;
    int aOtazka = 1; // aktualna otazka

    long long a;
    std::cin >> a;

    long long i = 1;
    long long minC = 0;
    while (aOtazka <= nOtazok) {
        if (obsahuje(i) != -1) {
            i += pow(10, obsahuje(i));
            continue;
        }

        if (c >= a) {
            std::cout << najdiCifru(i, c-a) << std::endl;
            aOtazka++;
            if (!(aOtazka > nOtazok)) {
                std::cin >> a;
                // if (a < c) {
                //     i = -1;
                //     c = 0;
                //    // minC = 0;
                // }
            }
                
        }
        //minC = c;
        i++;
    }

    return 0;
}