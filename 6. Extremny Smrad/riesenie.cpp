#include <iostream>
using namespace std;
double** mapa = nullptr;double** riesenie = nullptr;int n = 0, k = 0;
double najdiNajvacsie(int i, int j) {
    double najvacsie = -1;   
    // Vrchny rad
    if (mapa[i-1][j-1] > najvacsie) najvacsie = mapa[i-1][j-1];
    if (mapa[i-1][j] > najvacsie) najvacsie = mapa[i-1][j];
    if (mapa[i-1][j+1] > najvacsie) najvacsie = mapa[i-1][j+1];
    // Stredny rad
    if (mapa[i][j-1] > najvacsie) najvacsie = mapa[i][j-1];
    if (mapa[i][j] > najvacsie) najvacsie = mapa[i][j];
    if (mapa[i][j+1] > najvacsie) najvacsie = mapa[i][j+1]; 
    // Spodny rad 
    if (mapa[i+1][j-1] > najvacsie) najvacsie = mapa[i+1][j-1];
    if (mapa[i+1][j] > najvacsie) najvacsie = mapa[i+1][j];
    if (mapa[i+1][j+1] > najvacsie) najvacsie = mapa[i+1][j+1];
    return najvacsie; 
}

int main() {   
    // Vstup
    cin >> n >> k;
    // Mapa
    mapa = new double*[n];
    riesenie = new double*[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new double[n];
        riesenie[i] = new double[n];
    }
    // Nacitaj mapu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             cin >> mapa[i][j];
        }
    }                
    // Vymazanie mapy    
    for (int i = 0; i < n; i++) {
        delete[] mapa[i];
        delete[] riesenie[i];
    }    
    delete[] mapa;    
    delete[] riesenie;        
    return 0;    
}
