#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaximumXOR(vector<int>& nums) {
    //可能是nums中的大元素X和另一个元素Y进行异或；
    //大元素具有一个范围，我们需要尽可能保留X的最高位！！！
    //nums中的最大元素是25=11001,因此X的下界为 15=1111，X不能取到15;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int high = (nums[n - 1] >> 1);
    int count = 0;//最高位的位置
    int low = 0;//不能取到的下界
    while(high){
        low += (1 << count);
        ++count;
        high = (high >> 1);
    }

    int res = (nums[n - 1] ^ nums[0]);
    for(int j = n - 1; j >= 0; j--){
        if(nums[j] <= low) break;

        int it = nums[j];

        for(int i = 0; i < j; i++){
            //如果Y已经大于low,数字X的最高位就保不住了
            res = max(res, (nums[i] ^ it));
        }
    }
    
    return res;

}

int main()
{
   vector<int> nums = {3,10,5,25,2,8};
   int ans = findMaximumXOR(nums);
   cout << ans << endl;
   return 0;
}
