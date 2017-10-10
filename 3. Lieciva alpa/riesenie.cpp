#include <iostream>

long nZranenych = 0, nKvapiek = 0;
long* zranenia = nullptr;

using namespace std;

// Od po (vratane) index spocitaj
long spocitaj(long od, long po) {
    long sucet = 0;
    for (long i = od; i < po; i++) {
        sucet += zranenia[i];
    }
    return sucet;
}

int main() {
    // Input
    cin >> nZranenych >> nKvapiek;
    zranenia = new long[nZranenych];
    for(long i = 0; i < nZranenych; i++) {
        cin >> zranenia[i];
    }

    // Algoritmus

    // long sucet = spocitaj(0);
    // // Ak je vo flaske viacek kvapiek ako bojovnikov, nema cenu ani pokracovat
    // if (nZranenych < nKvapiek) {
    //     cout << "0\n";
    //     return 0;
    // }

    long riesenie = 0;

    for (long i = 0; i < nZranenych; i++) {
        long sucet = spocitaj(i, nZranenych);

        // Ak je sucet zraneni mensi ako nKvapiek nema zmysel ani pokracovat v iterovani.
        if (sucet < nKvapiek) {
            break;
        }

        // Ak je pocet bojovnikov mensi ako riesenie nema cenu pokracovat v iterovanii.
        // co tak <= ?
        if (riesenie > (nZranenych-i)) {
            break;
        }

        // Ak je cely rad liecitelny bez mrhania
        if (sucet % nKvapiek == 0) {
            riesenie = nZranenych-i;
            continue;
        }

        long medziSucet = sucet;
        // ma to byt > a nie >= ze?
        long iteraciaJ = 1;
        for (long j = nZranenych; j > i; j--) {
            medziSucet -= zranenia[j-1];

            // Ak je sucet mensi ako pocet kvapiek nema zmysel -> mrhali by sme alpou
            if (medziSucet < nKvapiek) {
                break;
            }

            if (medziSucet % nKvapiek == 0) {
                //riesenie = nZranenych-j;
                riesenie = nZranenych-i-iteraciaJ;
                break;
            }
            iteraciaJ++;
        }
    }

    cout << riesenie << "\n";

    delete[] zranenia;
    return 0;
}
