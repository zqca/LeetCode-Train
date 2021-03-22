#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;

    while(n != 0) {
        //只要n不是0
        if(n & 1) count++;
        n = n >> 1;
    }

    return count;
        
}

int main() {
    uint32_t n = 0b11111111111111111111111111111101;//unsigned int

    int ans = hammingWeight(n);
    cout << ans << endl;

    return 0;
}