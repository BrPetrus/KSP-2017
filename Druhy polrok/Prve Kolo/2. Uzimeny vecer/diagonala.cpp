#include <iostream>
#include <algorithm>

int main() {
    const int n = 3;
    int pole[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    /* for(int j = 0; j < 3; j++) {
        for(int i = 0; i <= j; i++) {
            std::cout << "j:" << j-i << " i:" << i << std::endl;
        }
    }  */
    for(int c = 0; c <= 2*(n-1); c++) {
        int maxY = std::min(n-1, c);
        int minY = std::max(0, c-n+1);
        for(int y = minY; y <= maxY; y++) {
            int x = c-y;
            std::cout << "x:" << x << " y:" << y << std::endl;
        }
    }
    return 0;
}