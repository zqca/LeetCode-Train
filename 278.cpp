#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(isBadVersion(mid)){
                //true
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;//1 2 3 4 5
        
    }
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
