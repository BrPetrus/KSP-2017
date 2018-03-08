#include <iostream>
#include <map>

int index(int x, int y, int n) {
    return y*n+x;
}

int main() {
    int n = 0;
    std::cin >> n;

    /*  Pole    */
    int * pole = new int[n*n]; // Alokacia
    // Nacitanie vstupu
    for(int ria = 0; ria < n; ria++) { // Riadok
        for(int stl = 0; stl < n; stl++) { // Stlpec
            int vstup;
            std::cin >> vstup;
            pole[ria*n+stl] = vstup;
        }
    }

    /*  Analyza */
    std::map<int, int> parne, neparne;
    int parnych = 0;
    // Pozrieme na uhlopriecky.
    bool parnaDiagonala = true;
    for(int c = 0; c <= 2*(n-1); c++) {
        int maxY = std::min(n-1, c);
        int minY = std::max(0, c-n+1);
        for(int y = minY; y <= maxY; y++) {
            int x = c-y;
            //std::cout << "x:" << x << " y:" << y << std::endl;
            //std::cout << pole[index(x, y, n)] << " ";
            int cislo = pole[index(x, y, n)];
            if(parnaDiagonala) {
                parnych++;
                parne[cislo] = parne[cislo] + 1;
            }
            else{
                neparne[cislo] = neparne[cislo] + 1;
            }
        }
        parnaDiagonala = !parnaDiagonala;
    }

    /* for(std::pair<int, int> a : parne) {
        std::cout << a.first << ":" << a.second << std::endl;
    }
    std::cout << "\n\n";
    for(std::pair<int, int> a : neparne) {
        std::cout << a.first << ":" << a.second << std::endl;
    } */

    // Najdi najvacsie
    std::pair<int,int> maxParne(-1,-1);
    std::pair<int,int> maxParneDruhe(-1,-1);
    for(std::pair<int, int> a : parne) {
        if(maxParne.second < a.second) {
            maxParneDruhe = maxParne;
            maxParne = a;
        }
        else if(maxParneDruhe.second < a.second) {
            maxParneDruhe = a;
        }
            
    }

    std::pair<int,int> maxNeparne(-1,-1);
    std::pair<int,int> maxNeparneDruhe(-1,-1);
    for(std::pair<int, int> a : neparne) {
        if(maxNeparne.second < a.second) {
            maxNeparneDruhe = maxNeparne;
            maxNeparne = a;
        }
        else if(maxNeparneDruhe.second < a.second) {
            maxNeparneDruhe = a;
        }
            
    }
    
    //std::cout << parnych-maxParne.second << " " << (n*n-parnych) - maxNeparne.second;
    if(maxNeparne.first != maxParne.first)
        std::cout << (parnych-maxParne.second) + ((n*n-parnych) - maxNeparne.second) << std::endl;
    else {
        if(maxParne.second > maxNeparne.second) {
            std::cout << (parnych-maxParne.second) + ((n*n-parnych) - maxNeparneDruhe.second) << std::endl;
        }
        else {
            std::cout << (parnych-maxParneDruhe.second) + ((n*n-parnych) - maxNeparne.second) << std::endl;
        }
    }

    delete[] pole;
    return 0;
}