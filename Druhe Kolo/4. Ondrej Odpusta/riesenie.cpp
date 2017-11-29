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

int main() {
    long long i = 0;
    for (i = 0; i < 1000;) {
        if (obsahuje(i) != -1) {
            i += pow(10, obsahuje(i));
            continue;
        }
        std::cout << i << "\t" << c <<"\n";
        i++;
        
    }
    return 0;
}