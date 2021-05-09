#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> bloomDay, int day, int num, int size){
    int curlen = 0, count = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        if(count == num) return true;

        if(bloomDay[i] <= day){
            curlen++;
        }
        else{
            curlen = 0;
        }

        if(curlen == size){
            curlen = 0;
            count++;
        }

    }

    return num == count;

}

//TODO:为啥要用双指针，一个for明明就能解决问题
bool check1(vector<int> bloomDay, int day, int num, int size){
    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= day){
            bloomDay[i] = 1;//开花了
        }
        else{
            bloomDay[i] = 0;
        }
    }
    int count = 0, tmp;

    int i, j;
    for(i = 0; i < bloomDay.size(); i++){
        if(count == num) return true;

        if(bloomDay[i] == 1){
            tmp = 0;
            for(j = i; j < bloomDay.size(); j++){
                if(tmp == size){
                    count++;
                    i = j - 1;
                    break;
                }
                if(bloomDay[j] == 1){
                    tmp++;
                }
                else{
                    i = j;
                    break;
                }
            }
            if(j == bloomDay.size() && tmp == size){
                //退出for的时候，j已经为数组长度
                count++;
            }
            
        }
    }

    return count == num; 
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if(bloomDay.size() < m * k) return -1;
    int left = *(min_element(bloomDay.begin(), bloomDay.end()));
    int right = *(max_element(bloomDay.begin(), bloomDay.end()));

    if(check(bloomDay, right, m, k) == false)
        return -1;
    if(check(bloomDay, left, m, k) == true) 
        return left;

    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(check(bloomDay, mid, m, k)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if(check(bloomDay, right, m, k)){
        return right;
    }
    else{
        return -1;
    }

}

int main()
{
   vector<int> bloomDay ={7,7,7,7,12,7,7};

   int m = 2;
   int k = 3;
   int ans = minDays(bloomDay, m, k);
   cout << ans << endl;
   return 0;
}
