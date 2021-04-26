#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> vec, int size, int D){
    int count = 1;//至少打包一次
    int tmpsum = 0;
    int pos = 0;

    for(pos = 0; pos < vec.size(); ++pos){
        if(vec[pos] > size) return false;//当前超重
        if(count > D) return false;//已经超过次数

        tmpsum += vec[pos];
        if(tmpsum > size){
            //当前已经超标
            ++count;
            tmpsum = 0;
            --pos;
        }
    }
    return count <= D;

}


int shipWithinDays(vector<int>& weights, int D) {
    int minsize = weights[0], maxsize = 0;
    for(int item : weights){
        maxsize += item;
        if(item > maxsize){
            minsize = item;
        }
    }
    //找到最大值，然后二分法,每次区间去除不能完成的部分
    int low = minsize, high = maxsize; //
    int cur;
    bool flag;

    while(low < high){
        cur = low + (high - low) / 2;
        flag = check(weights, cur, D);//true能完成
        if(flag){
            high = cur;//避免出现low>high的情况
        }
        else{
            low = cur + 1;
        }
    }
    return high;

}

int main()
{
   vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
   int D = 5;
   int ans = shipWithinDays(weights, D);
   cout << ans << endl;
   
   return 0;
}
