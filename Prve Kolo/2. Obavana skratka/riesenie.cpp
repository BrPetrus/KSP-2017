#include <iostream>

long long nZahradiek = 0;
long long tLektvar = 0;
long long dlzka = 0;
long long tMax = 0;

using namespace std;

int main() {
    // Prvy riadok vstupov
    cin >> nZahradiek >> tLektvar;

    // Dlzka zahradok dokopy
    long long vstup;
    long long dlzky[nZahradiek];
    for(long long i = 0; i < nZahradiek; i++) {
        cin >> vstup;
        dlzky[i] = vstup;
        dlzka += vstup;
    }

    // Cas dokopy
    for(long long i = 0; i < nZahradiek; i++) {
        cin >> vstup;
        // Ak je nemozne prejst danu zahradku(ani s lektvarom), lebo nemame dostatok casu.
        if(vstup < dlzky[i]) {
            cout << "-1\n";
            return 0;
        }
        tMax += vstup;
    }

    long long tBezLektvarov = dlzka*2; // Lebo ide 1/2 ms^-1

    // Prejde aj bez lektvaru
    if (tBezLektvarov <= tMax) {
        cout << "0\n";
        return 0;
    }

    // Kolko lektvarov mozem pouzit? -> zaokruhli nahor
    long long maxLektvar = (tMax + tLektvar - 1)/tLektvar;

    long long cas = tBezLektvarov;
    for (long long i = 1; i <= maxLektvar; i++) {
        cas -= tLektvar;
        if (cas <= tMax) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}