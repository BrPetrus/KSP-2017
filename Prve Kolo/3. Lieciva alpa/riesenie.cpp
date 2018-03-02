#include <iostream>

// Kolko je celkovo zranenych a kolko kvapiek je v jednej ampulke
long nZranenych = 0, nKvapiek = 0;
// Tu ulozime rad zranenych bojovnikov
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
    long riesenie = 0;

    for (long i = 0; i < nZranenych; i++) {
        long sucet = spocitaj(i, nZranenych);

        // Ak je sucet zraneni mensi ako nKvapiek nema zmysel ani pokracovat v iterovani.
        if (sucet < nKvapiek) {
            break;
        }

        // Ak je pocet bojovnikov mensi ako riesenie nema cenu pokracovat v iterovanii.
        if (riesenie > (nZranenych-i)) {
            break;
        }

        // Ak je cely rad liecitelny bez mrhania
        if ((sucet % nKvapiek) == 0) {
            riesenie = nZranenych-i; // vzdy bude najvacsie riesenie
            continue;
        }

        // Tu budeme postupne odoberat po bojovnikovi od konca a snazit sa najst kolko najviac ich vyliecime
        long medziSucet = sucet;
        long iteraciaJ = 1; // Kolkata iteracia to je (od 1)
        for (long j = nZranenych; j >= i; j--) {
            medziSucet -= zranenia[j-1];

            // Ak je sucet mensi ako pocet kvapiek nema zmysel -> mrhali by sme alpou
            if (medziSucet < nKvapiek) {
                break;
            }

            if (medziSucet % nKvapiek == 0) {
                // Ak je to doteraz najvacsie riesenie
                if (nZranenych-i-iteraciaJ > riesenie) {
                    riesenie = nZranenych-i-iteraciaJ;
                }
                break;
            }
            iteraciaJ++;
        }
    }

    cout << riesenie << "\n";

    delete[] zranenia;
    return 0;
}
