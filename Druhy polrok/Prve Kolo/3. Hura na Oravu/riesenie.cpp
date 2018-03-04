#include <iostream>
#include <queue>
#include <string>

long long lavo(long long k) {
    return 2*k;
}

long long pravo(long long k) {
    return 2*k+1;
}

int main() {
    std::queue<long long> stanice;
    stanice.push(1);

    std::string prikaz;
    std::cin >> prikaz;

    for(int index = 0; index < prikaz.size(); index++) {
        char i = prikaz[index];
        int size = stanice.size();
        for(int s = 0; s < size; s++) {
            long long x = stanice.front();
            stanice.pop();

            if(i == 'L')
                stanice.push(lavo(x));
            else if(i == 'P')
                stanice.push(pravo(x));
            else if(i == '*') {
                stanice.push(lavo(x));
                stanice.push(pravo(x));
            }
        }
    } 

    long long riesenie = 0;
    int size = stanice.size();
    for(int i = 0; i < size; i++) {
        riesenie += stanice.front();
        stanice.pop();
    }

    std::cout << riesenie % 1000000007 << std::endl;
    return 0;
}