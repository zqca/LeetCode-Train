#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> count;
    int maxTimes = 1;
    for(int i = 0; i < words.size(); i++){
        count[words[i]]++;
        if(count[words[i]] > maxTimes){
            maxTimes = count[words[i]];
        }
    }
    vector<map<string, int> > vec(maxTimes + 1);

    for(auto it: count){
        vec[it.second][it.first] = it.second;
    }

    vector<string> res(k, "");
    
    int cnt = 0;

    for(int i = maxTimes; k > 0; --i){
        if(vec[i].size() == 0) continue;

        auto it = vec[i].begin();
        while(it != vec[i].end() && k > 0){
            res[cnt++] = it->first;
            --k;
            ++it;
        }
        

    }
    return res;

}

int main()
{
   vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
   int k = 2;
   vector<string> ans = topKFrequent(words, k);
   //cout << ans << endl;
   return 0;
}
