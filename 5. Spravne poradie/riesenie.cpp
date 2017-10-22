#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int nAkcii = 0, nZavislosti = 0, nBojovnikov = 0;


int main() {
    cin >> nAkcii >> nZavislosti >> nBojovnikov;

    unordered_map<int, vector<int>> pravidla;

    // Vytvorime pravidla. Kluc je akcia X a value je vector, ktory drzi vsetky nepovolene akcie po vykonani X.
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

        // Sem ulozime vsetky akcie, ktore chce vykonat ako kluc. Value je v podstate zbytocny. 
        unordered_map<int, bool> bojovnik;
        for (int j = 0; j < akcneBody; j++) {
            int a = 0;
            cin >> a;
            bojovnik[a] = true;
        }

        
        // Zakial su volne akcne body
        while (akcneBody > 0) {
            // Pozrime sa na kazdu akciu ktoru chce spravit.
            for (auto k : bojovnik) {
                // Kvoli tomu ze operator[] v map vytvori novu instanciu -> musime ingorovat tie ktore nas nezajimaju
                if (!k.second)
                    continue;
                bool mozmeVymazat = true;

                // Pozri sa na pravidla
                for (auto pravidlo : pravidla[k.first]) {
                    // Ak by sme urobenim akcie zabranili urobeniu dalsich
                    if (bojovnik[pravidlo] == true) {
                        mozmeVymazat = false;
                        break;
                    }
                }


                // Ak mozme vykonat tuto akciu, napiseme ju do riesene a vymazeme z mapy (alebo nastavime na false)
                if (mozmeVymazat) {
                    // Zbytocna medzera na konci by mohla sposobit chybu
                    int tmp = k.first;
                    riesenie << tmp << " ";
                    // bojovnik.erase(k.first);
                    bojovnik[k.first] = false;
                    akcneBody--;
                }
            }
        }
        riesenie << "\n";
    }
    cout << riesenie.str();
    return 0;
}