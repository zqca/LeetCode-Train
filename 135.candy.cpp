#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
}

/* 超时
int candy(vector<int>& ratings) {
    if(ratings.size() < 2) return ratings.size();

    vector<int> nums(ratings.size(), 0);//记录数量
    vector<int> inc = ratings;
    sort(inc.begin(), inc.end());

    for(int i = 0; i < inc.size(); i++) {
        if(i > 0 && inc[i] == inc[i - 1]) {
            continue;//去除重复的最小值
        }
        for(int j = 0; j < ratings.size(); j++) {
            if(ratings[j] == inc[i]) {
                //最左边
                if(j == 0) {
                    if(ratings[j] > ratings[j + 1]) {
                        nums[j] = nums[j + 1] + 1;
                    }
                    else {
                        nums[j] = 1;
                    }
                }
                //最右边
                else if(j == ratings.size() - 1) {
                    if(ratings[j] > ratings[j - 1]) {
                        nums[j] = nums[j - 1] + 1;
                    }
                    else {
                        nums[j] = 1;
                    }
                }
                //中间:比两边都大，比左大，比右大，比左右都小+和左右相等
                else {
                    if(ratings[j] > ratings[j - 1] && ratings[j] > ratings[j + 1]) {
                        nums[j] = max(nums[j - 1], nums[j + 1]) + 1;
                    } 
                    else if(ratings[j] > ratings[j - 1] && ratings[j] <= ratings[j + 1]) {
                        nums[j] = nums[j - 1] + 1;
                    }
                    else if(ratings[j] <= ratings[j - 1] && ratings[j] > ratings[j + 1]){
                        nums[j] = nums[j + 1] + 1;
                    }
                    else if(ratings[j] <= ratings[j - 1] && ratings[j] <= ratings[j + 1]) {
                        nums[j] = 1;
                    }

                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;


}
*/
int main() {
    vector<int> ratings = {1,3,2,2,1};
    int ans = candy(ratings);
    cout << ans << endl;

    return 0;
}