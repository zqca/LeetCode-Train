#include <iostream>
#include <vector>

using namespace std;

 vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        int count = 0;
        for(int i = 0; i < n; i++){
            ans[count++] = nums[i];
            ans[count++] = nums[i + n];
        }

        return ans;

}

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
