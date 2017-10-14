#include <iostream>
#include <map>
#include <vector>


using namespace std;

int nAkcii = 0, nZavislosti = 0, nBojovnikov = 0;
bool** pravidla = nullptr;

int main() {
    cin >> nAkcii >> nZavislosti >> nBojovnikov;

    map<int, vector<int>> pravidla;

    // Vytvorime pravidla
    int key = 0;
    int value = 0;
    for (int i = 0; i < nZavislosti; i++) {
        cin >> key >> value;
        pravidla[i].push_back(value);
    }

    // Iterujeme cez jednotlivych bojovnikov
    for (int i = 0; i < nBojovnikov; i++) {
        int akcneBody = 0;
        cin >> akcneBody;
        map<int, bool> bojovnik;
        for (int j = 0; j < akcneBody; j++) {
            int a = 0;
            cin >> a;
            bojovnik[a] = true;
        }

        while (akcneBody > 0) {
            for (auto k : bojovnik) {
                bool mozmeVymazat = true;

                // Pozri sa na pravidla
                //vector<int> momentalnePravidla = pravidla[k]; 
                for (auto pravidlo : pravidla[k.first]) {
                    // Ak by sme urobenim akcie zabranili urobeniu dalsich
                    if (bojovnik[pravidlo] == true) {
                        mozmeVymazat = false;
                        break;
                    }
                }

                if (mozmeVymazat) {
                    // Zbytocna medzera na konci by mohla sposobit chybu
                    cout << k.first << " ";
                    bojovnik.erase(k.first);
                    akcneBody--;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}