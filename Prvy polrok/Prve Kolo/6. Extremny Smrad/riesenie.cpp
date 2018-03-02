#include <iostream>

using namespace std;

long** mapa = nullptr;
int n = 0, k = 0;

long najdiNajvacsie(int i, int j) {
    long najvacsie = -1;

    int q = (k-1)/2;

    for (int x = i-q; x <= i+q; x++) {
        if ( x < 0 || x > n-1 )
            continue;
        for (int y = j-q; y <= j+q; y++) {
            if ( y < 0 || y > n-1 )
                continue;
            if (mapa[x][y] > najvacsie)
                najvacsie = mapa[x][y];
        }
    }
    
    return najvacsie;
    
}

int main() {
    // Vstup
    cin >> n >> k;
    
    // Mapa
    mapa = new long*[n];
   // riesenie = new double*[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new long[n];
    }

    // Nacitaj mapu
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
            cin >> mapa[i][j];
        }
    }
    
    // Riesenie
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
            cout << najdiNajvacsie(i, j);
            if (j != n-1)
                cout << " ";
            // cout << mapa[i][j];
        }
        cout << "\n";
    }
    
    // Vymazanie mapy
    for (int i = 0; i < n; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;
    
    return 0;    
}
