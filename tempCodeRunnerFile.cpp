#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Group{
    int val;//需要包含的数字
    int cnt;//本组内的成员数量
    vector<int> detail;//所有例子的 【索引，值】
};

Group findGroup(vector<int> L, int val){
    Group group;
    group.val = val;
    group.cnt = 0;

    string target = to_string(val);
    for(int i = 0; i < L.size(); ++i){
        string tmp = to_string(L[i]);
        if(tmp.find(target) != string::npos){
            group.cnt = group.cnt + 1;
            group.detail.emplace_back(i);
            group.detail.emplace_back(L[i]);
        }
    }
    return group;
}

void solve(vector<int> L, vector<int> R){
    //首先，给R排序，去重
    set<int> RR;
    for(int x : R){
        RR.insert(x);
    }
    R = vector<int>(RR.begin(), RR.end());
    sort(R.begin(), R.end());

    vector<Group> groups;
    int TotalNum = 0;
    for(int i = 0; i < R.size(); ++i){
        Group tmp = findGroup(L, R[i]);
        if(tmp.cnt == 0) continue;
        groups.emplace_back(tmp);
        TotalNum += (tmp.cnt)*2 + 2;
    }

    //输出
    vector<int> output;
    output.emplace_back(TotalNum);
    
    int len = groups.size();
    for(int i = 0; i < len; ++i){
        //先合并所有的输出到一个output数组中；
        output.emplace_back(groups[i].val);
        output.emplace_back(groups[i].cnt);
        output.emplace_back(groups[i].detail.begin(), groups[i].detail.end());
    } 

    for(int i = 0; i < output.size(); ++i){
        cout << output[i];
        if(i != output.size() - 1){
            cout << " ";
        }
    }
}

int main()
{
   int L_num, R_num;
   while(cin >> L_num){
       vector<int> L(L_num, 0);
       for(int i = 0; i < L_num; ++i){
           cin >> L[i];
       }
       cin >> R_num;
       vector<int> R(R_num, 0);
       for(int i = 0; i < R_num; ++i){
           cin >> R[i];
       }

       solve(L, R);
   }

   return 0;
}
