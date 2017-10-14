#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int nAkcii = 0, nZavislosti = 0, nBojovnikov = 0;
//bool** pravidla = nullptr;


int main() {
    cin >> nAkcii >> nZavislosti >> nBojovnikov;

    map<int, vector<int>> pravidla;

    // Vytvorime pravidla
    int key = 0;
    int value = 0;
    for (int i = 0; i < nZavislosti; i++) {
        cin >> key >> value;
        pravidla[key].push_back(value);
    }

    ostringstream riesenie;

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
                if (!k.second)
                    continue;
                bool mozmeVymazat = true;

                // Pozri sa na pravidla
                //vector<int> momentalnePravidla = pravidla[k]; 
                for (auto pravidlo : pravidla[k.first]) {
                    // Ak by sme urobenim akcie zabranili urobeniu dalsich
                    if (bojovnik[pravidlo] == true) {
                        mozmeVymazat = false;
                        break;
                    }
                    // Nejako sa tohoto krkolomneho zbavit
                    // else {
                    //     bojovnik.erase(pravidlo);
                    // }
                }

                if (mozmeVymazat) {
                    // Zbytocna medzera na konci by mohla sposobit chybu
                    int tmp = k.first;
                    riesenie << tmp << " ";
                    bojovnik.erase(k.first);
                    akcneBody--;
                }
            }
        }
        riesenie << "\n";
    }

    cout << riesenie.str();
    return 0;
}