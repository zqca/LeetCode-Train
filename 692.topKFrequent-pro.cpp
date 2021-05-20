#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>//优先权队列定义在这个头文件中


using namespace std;

struct temp{
    //Q1:为什么重写‘()’这个操作符
    //Q2:下面这种写法，加不加const有何区别
    //Q3:下面这种写法，加了引用&，如果我不需要操作传入参数，不加&是不是也行
    //bool operator() (const pair<string, int>& a, const pair<string, int>& b){
    bool operator() (pair<string, int> a, pair<string, int> b){
        
        //排序，为优先权队列打基础
        if(a.second == b.second){
            return a.first < b.first;//字符串小的放在后面
        }
        else{
            return a.second > b.second;//出现次数多的放在队列后面
        }
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> count;

    for(int i = 0; i < words.size(); i++){
        count[words[i]]++;
    }
    
    vector<string> res(k, "");

    priority_queue<pair<string, int>, vector<pair<string, int>>, temp> priQue;
    for(auto it : count){
        priQue.push(it);
        if(priQue.size() > k){
            priQue.pop();
        }
    }
    
    for(int i = k - 1; i >= 0; --i){
        res[i] = priQue.top().first;
        priQue.pop();
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
