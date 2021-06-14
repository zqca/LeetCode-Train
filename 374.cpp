#include <iostream>
#include <vector>

using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low < high){
            int mid = low + (high - low) / 2;
            int cur = guess(mid);
            if(cur == 0) return mid;
            if(cur == -1){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;//无用的返回
        
    }
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
