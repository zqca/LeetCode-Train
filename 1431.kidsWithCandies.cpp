#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxele = candies[0];
    for(int i : candies){
        if(i > maxele) maxele = i;
    }

    int len = candies.size();
    vector<bool> ans(len, false);

    for(int i = 0; i < len; i++){
        if(candies[i] + extraCandies >= maxele) ans[i] = true;

    }

    return ans;

}


int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
