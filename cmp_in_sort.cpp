#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp1(int a, int b){
    //实际上a是后面的数，b是前一个数
    if(a < b){
        return true;
    }
    return false;
}

int cmp2(int a, int b){
    //记录：返回你想要的排序后的规则（将错就错）
    return a > b;
}

int main()
{
   
   vector<int> ans = {1,33};
   sort(ans.begin(), ans.end(), cmp1);//第三个参数只返回true\false,false不交换
   for(auto x : ans){
       cout << x << "->";
   }
   
   return 0;
}
