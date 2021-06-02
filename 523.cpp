#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_map<int,int> mp;
    //存储每一个前缀和的余数，首次出现的索引位置；只保留第一次出现的位置；
    //如果子数组的和符合题意，那么子数组首位的前一位的前缀 和 子数组末位的前缀和 %k具有相同的余数；
    //初始化
    mp[0] = -1;//不是随便取的负值，例如【3,3】,k=6;规定空的前缀的结束下标为 -1，空的前缀的元素和为 0
    int yushu = 0;//前缀和的余数

    for(int i = 0; i < len; i++){
        yushu = (yushu + nums[i]) % k;
        if(mp.find(yushu) != mp.end()){
            //这个余数之前出现过了，检查首次出现的位置和现在的位置之间的差值是不是大于2
            int prepos = mp[yushu];
            if(i - prepos >= 2){
                return true;
            }
        }
        else{
            mp[yushu] = i;
        }
    }

    return false;

}

int main()
{
   vector<int> nums = {3,3};
   int k = 6;

   int ans = checkSubarraySum(nums, k);
   cout << ans << endl;
   return 0;
}
