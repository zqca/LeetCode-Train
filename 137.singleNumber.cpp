#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//TODO:传统Hash表
int singleNumber1(vector<int>& nums) {
    unordered_map<int,int> count;//key-count
    for(int i = 0; i < nums.size(); i++){
        count[nums[i]]++;
    }
    for(auto item = count.begin(); item != count.end(); item++){
        if(item->second == 1){
            return item->first;
        }
    }
    return -1;

}
//TODO:异或操作
int singleNumber(vector<int>& nums) {
    int result = 0;
    int len = nums.size();
    for(int i = 0; i < 32; i++){
        //i表示32位数中的第i位数字
        int tmpsum = 0;
        for(int k = 0; k < len; k++){
            tmpsum += ((nums[k] >> i) & 1);
        }
        if(tmpsum % 3 == 1){
            result = result | (1 << i);
        }
    }
    return result;

}



int main()
{
    vector<int> nums = {0,1,0,1,0,1,99};
    int ans = singleNumber(nums);
    cout << ans << endl;

    
   return 0;
}
