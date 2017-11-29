#include <iostream>
#include <cmath>

long long c = 0;

// Na kolkatej cifre obsahuje
long long obsahuje(long long n) {
    long long a = 0;
    while(n > 0) {
        long long cifra = n%10;
        if (cifra == 5) {
            return a;
        }
            
        n /= 10;
        a++;
    }
    c += a;
    return -1;
}

int main() {
    for(int i = 1; i < 1000; i++) {
        if (obsahuje(i) != -1) {
            i += pow(10, obsahuje(i));
            i--;
            continue;
        }
        std::cout << i << "\t" << c << "\n";
    }
}