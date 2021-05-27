#include <iostream>
#include <vector>

using namespace std;

int hammingDistance(int x, int y) {
    int z = (x ^ y);
    int count = 0;
    while(z){
        if(z & 1){
            ++count;
        }
        z = z >> 1;
    }
    return count;

}

int main()
{
   int x = 1, y = 4;
   int ans = hammingDistance(x, y);
   cout << ans << endl;
   return 0;
}
