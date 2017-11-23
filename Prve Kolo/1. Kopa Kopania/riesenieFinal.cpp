#include <iostream>
#include <chrono>

// Ja viem, ze deklarovanie globalnych premennych je zle. Ospravedlnte ma, jednoduchost nepusti.
int* mapa = nullptr;
int velkostMapy = 0;
int riesenie = 0;

int main() {

    // Kolko nerovnosti mame ocakavat
    std::cin >> velkostMapy;

    mapa = new int[velkostMapy];

    // Nacitaj "mapu" sveta
    std::string vstup;
    std::cin >> vstup;

    for(int i = 0; i < velkostMapy; ++i) {
        // Konvertuj char na cislo
        mapa[i] = (vstup.c_str()[i] - '0'); 
    }
    
   
    // Pocet jam a pocet kopcov
    int x=0, y=0;
    for(int i = 0; i < velkostMapy; ++i) {
        if(mapa[i] == 0) { // Jama
            x++;
        }
        else if (mapa[i] == 1) {
            y++;
        }
    }


    // Teraz staci len odpcitat x a y.
    // Aby sme sa vyhli zapornym odnotam, treba odpocitat mensie od vacsieho
    if(x > y)
        riesenie = x-y;
    else
        riesenie = y-x;

    std::cout << riesenie << std::endl;

    delete[] mapa;
    return 0;
}