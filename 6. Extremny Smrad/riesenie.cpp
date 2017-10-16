#include <iostream>

using namespace std;

long** mapa = nullptr;
int n = 0, k = 0;

long najdiNajvacsie(int i, int j) {
    long najvacsie = -1;
    // // Vrchny rad
    // if (mapa[i-1][j-1] > najvacsie) najvacsie = mapa[i-1][j-1];
    // if (mapa[i-1][j] > najvacsie) najvacsie = mapa[i-1][j];
    // if (mapa[i-1][j+1] > najvacsie) najvacsie = mapa[i-1][j+1];
    
    // // Stredny rad
    // if (mapa[i][j-1] > najvacsie) najvacsie = mapa[i][j-1];
    // if (mapa[i][j] > najvacsie) najvacsie = mapa[i][j];
    // if (mapa[i][j+1] > najvacsie) najvacsie = mapa[i][j+1];
    
    // // Spodny rad
    // if (mapa[i+1][j-1] > najvacsie) najvacsie = mapa[i+1][j-1];
    // if (mapa[i+1][j] > najvacsie) najvacsie = mapa[i+1][j];
    // if (mapa[i+1][j+1] > najvacsie) najvacsie = mapa[i+1][j+1];
    
    for (int x = i-1; x <= i+1; x++) {
        if ( x <= 0 || x > n-1 )
            continue;
        for (int y = j-1; y <= j+1 ; y++) {
            if ( y <= 0 || y > n-1 )
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
