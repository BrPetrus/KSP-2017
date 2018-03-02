#include <map>
#include <iostream>

using namespace std;

int main() {
    multimap<int, int> cisla;

    int n;
    cin >> n;

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cisla.emplace(tmp, i); // co tak emplacehint
    }

    int krok = 0;

    multimap<int, int>::reverse_iterator prve = cisla.rbegin();
    for (; prve != cisla.rend();) {
        multimap<int, int>::reverse_iterator druhe = prve;
        advance(druhe, 1);
        if (druhe == cisla.rend()) {
            break;    
        }
        int pocet = cisla.count(druhe->first);
        for (int i = 0; i < pocet; i++, druhe++) {
            if(prve->second < druhe->second) { // Ak je mensie dalej ako vacsie
                krok++;
                druhe->second = -krok;
            }
        }
        advance(prve, pocet);
    }

    cout << krok << "\n";
    return 0;
}