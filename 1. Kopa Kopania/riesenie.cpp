#include <iostream>
#include <chrono>

// Ja viem, ze deklarovanie globalnych premennych je zle. Ospravedlnte ma, jednoduchost nepusti.
int* mapa = nullptr;
int velkostMapy = 0;
int riesenie = 0;

// Ak sa da zahrabrat jama na indexe iJame, zahrabe ju. Vrati true ak zahrabal inak false.
bool zahrab(int iJama) {
    // Pozerame sa dolava
    for(int index = iJama - 1; index >= 0; --index) {
        if (mapa[index] == 0) { //Kopec
            // Nemozme zahrabat z tejto strany
            break;
        }
        // Jama
        else if(mapa[index] == 1) {
            // Zahrab jamu a znic kopec
            mapa[index] = -1;
            mapa[iJama] = -1;
            riesenie -= 2;
            return true;
        }
        // Rovina -> nic nerob
        else if(mapa[index] == -1) {
            continue;
        }
    }

    // Pozerame sa doprava
    for(int index = iJama + 1; index <= velkostMapy; ++index) {
        if (mapa[index] == 0) { //Jama
            // Nemozme zahrabat z tejto strany
            break;
        }
        // Kopec
        else if(mapa[index] == 1) {
            // Zahrab jamu a znic kopec
            mapa[index] = -1;
            mapa[iJama] = -1;
            riesenie -= 2;
            return true;
        }
        // Rovina -> nic nerob
        else if(mapa[index] == -1) {
            continue;
        }
    }

    return false;
}


int main() {

    // Kolko nerovnosti mame ocakavat
    std::cin >> velkostMapy;
    riesenie = velkostMapy;

    mapa = new int[velkostMapy];

    // Nacitaj "mapu" sveta
    std::string vstup;
    std::cin >> vstup;
    

    for(int i = 0; i < velkostMapy; ++i) {
        // Convertuj std::String->char a to premen na cislo
        mapa[i] = (vstup.c_str()[i] - '0'); 
    }
    
   
    
    auto start = std::chrono::high_resolution_clock::now();
    bool bez = true;
    while(bez) {
        std::cout << "WHILE\n";
        bez = false;
        // Iterujme cez jednotlive kopce a hladajme
        for(int i = 0; i < velkostMapy; ++i) {
            if(mapa[i] == 0) { // Jama
                if(zahrab(i)) { // Nieco sa zmenilo
                    bez = true;
                }
            }
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    // // Spocitaj nerovnosti
    // int riesenie = 0;
    // for(int i = 0; i < velkostMapy; ++i) {
    //     if(mapa[i] == 1 || mapa[i] == 0)
    //     riesenie++;
    // }

    // for(int i = 0; i < velkostMapy; i++) {
    //     std::cout << mapa[i];
    // }

    std::cout << riesenie << std::endl;

    delete[] mapa;

    
    return 0;
}