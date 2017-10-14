#include <iostream>

using namespace std;

int nAkcii = 0, nZavislosti = 0, nBojovnikov = 0;
bool** pravidla = nullptr;

int main() {
    cin >> nAkcii >> nZavislosti >> nBojovnikov;

    // Vytvorit tabulku s pravidlami
    pravidla = new bool* [nAkcii];
    for(int i = 0; i < nAkcii; i++) {
        pravidla[i] = new bool[nAkcii];
        for (int j = 0; j < nAkcii; j++) {
            pravidla[i][j] = false;
        }
    } 


    // Vymaz tabulku s pravidlami
    for(int i = 0; i < nAkcii; i++) {
        delete[] pravidla[i];
    } 
    delete[] pravidla;

    return 0;
}