#include <iostream>
#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total ^= i;
        }
        //total = x0+...x_n-1 = 1+2...+n
        //odd = y1+y3+...y_n-1=(x1+x2)+(x3+x4)+...+x_n-1 + x_n 
        int odd = 0;
        for (int i = 1; i < n - 1; i += 2) {
            odd ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ odd;
        for (int i = 0; i < n - 1; i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }


int main()
{
   vector<int> encoded = {6,5,4,6};
   vector<int> ans = decode(encoded);
   //cout << ans << endl;
   return 0;
}
