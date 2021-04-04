#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int numRabbits(vector<int>& answers) {
    unordered_map<int,int> mySet;
    int ans = 0;
    int group;

    for(int i = 0; i < answers.size(); i++){
        mySet[answers[i]] ++;//second个人说自己之外的同类有first个
    }

    for(auto it = mySet.begin(); it != mySet.end(); it++){
        //如果second <= first + 1，以first作为标准计数
        if(it->second <= it->first + 1) ans += it->first + 1;
        //否则，需要拆分，比如5个人说自己的同类有3个，总人数最少的情况是：4,4
        else{
            group = ceil(it->second / (it->first + 1.0));
            ans += group * (it->first + 1);
        }
    }

    return ans;
}

int main(){
    vector<int> answers = {0,0,1,1,1};
    int ans = numRabbits(answers);
    cout << ans << endl;

    return 0;
}