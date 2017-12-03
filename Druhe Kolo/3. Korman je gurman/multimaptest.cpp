#include <map>
#include <iostream>

using namespace std;

int main() {
    multimap<int, int> cisla;
    // cisla.emplace(1,0);
    // cisla.emplace(3,1);
    // cisla.emplace(4,2);
    // cisla.emplace(6,3);
    // cisla.emplace(5,4);
    // cisla.emplace(2,5);
    // cisla.emplace(7,6);
    // cisla.emplace(8,7);
    // cisla.emplace(3,8);
    // cisla.emplace(3,8);

    int n;
    cin >> n;

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cisla.emplace(tmp, i); // co tak emplacehint
    }

    int krok = 0;

    multimap<int, int>::reverse_iterator prve;
    for (prve = cisla.rbegin(); prve != cisla.rend(); prve++) {
        multimap<int, int>::reverse_iterator druhe = prve;
        druhe++;
        int pocet = cisla.count(druhe->first);
        for (int i = 0; i < pocet; i++, druhe++) {
            if(prve->second < druhe->second) { // Ak je mensie dalej ako vacsie
                krok++;
                druhe->second = -krok;
            }
        }
        // cout << (*it).first << "\t" << (*it).second << "\n";
    }

    cout << "Pocet krokov: " << krok << endl;
    for (auto prvok: cisla) {
        cout << prvok.first << "\t" << prvok.second << endl;
    }

    return 0;
}