#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//对于OJ来说，需要加static,不然sort()不知道从哪找cmp函数并调用
//static静态成员函数不用加对象名，就能直接访问函数（这也是静态成员函数的一大优点）所以加了static就不会报错
static bool cmp(int num1, int num2){
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    string t1 = s1 + s2;
    string t2 = s2 + s1;

    return t1 > t2;

}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    int i;
    for(i = 0; i < nums.size(); ++i){
        ans += to_string(nums[i]);
    }
    //去除开头多余的0

    if(ans[0] == '0'){
        return "0";
    }
    
    return ans;
}

int main(){
    vector<int> nums = {0,0};
    string ans = largestNumber(nums);
    cout << ans << endl;

    return 0;
}