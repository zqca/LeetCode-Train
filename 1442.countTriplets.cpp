#include <iostream>
#include <vector>

using namespace std;

int countTriplets(vector<int>& arr) {
    //前缀和
    int n = arr.size();
    vector<int> presum(n, 0);
    presum[0] = arr[0];
    for(int i = 1; i < n; i++){
        presum[i] = (presum[i - 1] ^ arr[i]);
    }

    int ans = 0;
    int a, b;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; ++j){
            for(int k = j; k < n; k++){
                a = (presum[j - 1] ^ presum[i] ^ arr[i]);
                b = (presum[k] ^ presum[j] ^ arr[j]);
                if(a == b) ++ans;
            }
        }
    }

    return ans;

}

int main()
{
   vector<int> arr = {2,3,1,6,7};
   int ans = countTriplets(arr);
   cout << ans << endl;
   return 0;
}
