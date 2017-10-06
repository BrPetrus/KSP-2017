#include <iostream>
#include <chrono>

// Ja viem, ze deklarovanie globalnych premennych je zle. Ospravedlnte ma, jednoduchost nepusti.
int* mapa = nullptr;
int velkostMapy = 0;
int riesenie = 0;

// Ak sa da zahrabrat jama na indexe iJame, zahrabe ju. Vrati true ak zahrabal inak false.
bool zahrab(int iJama) {
    bool l = true;
    bool p = true;
    int i = 1;
    while(l || p) {
        if(l) {
            //Nasli sme kopec
            if(mapa[iJama-i] == 1) {
                mapa[iJama] = -1;
                mapa[iJama-i] = -1;
                riesenie -= 2;
                return true;
            }
            else if (mapa[iJama-i] == 0) { //Jama
                // Nemozme zahrabat z tejto strany
                l = false;
            }
                   
        }
        if(p) {
            //Nasli sme kopec
            if(mapa[iJama+i] == 1) {
                mapa[iJama] = -1;
                mapa[iJama+i] = -1;
                riesenie -= 2;
                return true;
            }
            else if (mapa[iJama+i] == 0) { //Jama
                // Nemozme zahrabat z tejto strany
                p = false;
            }
        }
        i++;
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
    //const char* vstups = vstup.c_str();

    for(int i = 0; i < velkostMapy; ++i) {
        //mapa[i] = vstups[i] - '0';
        mapa[i] = (vstup.c_str()[i] - '0'); 
    }
    
   
    
    // bool bez = true;
    // while(bez) {
    //     bez = false;
    //     // Iterujme cez jednotlive kopce a hladajme
    //     for(int i = 0; i < velkostMapy; ++i) {
    //         if(mapa[i] == 0) { // Jama
    //             if(zahrab(i)) { // Nieco sa zmenilo
    //                 bez = true;
    //                 break;
    //             }                
    //         }
    //     }
    // }
    // for(int i = 0; i < velkostMapy; ++i) {
    //     if(mapa[i] == 0) { // Jama
    //         if (zahrab(i)) {
    //             i = -1;
    //         }         
    //     }
    // }
    int x=0, y=0;
    for(int i = 0; i < velkostMapy; ++i) {
        if(mapa[i] == 0) { // Jama
            x++;
        }
        else if (mapa[i] == 1) {
            y++;
        }
    }

    if(x > y)
        riesenie = x-y;
    else
        riesenie = y-x;

    std::cout << riesenie << std::endl;

    delete[] mapa;

    
    return 0;
}