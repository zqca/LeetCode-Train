#include <iostream>
#include <vector>

using namespace std;

void deMerge(vector<int>& vec0, vector<int>& vec1, vector<int>& vec2){
    //将vec0拆散到vec1,vec2
    int n = vec0.size();
    vec1.clear();
    vec2.clear();

    for(int i = 0; i < n; i++) {
        if(i < n / 2) {
            vec1.push_back(vec0[i]);
        }
        else{
            vec2.push_back(vec0[i]);
        }
    }

    vec0.clear();
}

void Merge(vector<int>& vec0, vector<int>& vec1, vector<int>& vec2){
    //将vec1,vec2合并到vec0
    int n = vec1.size();
    vec0.clear();

    for(int i = 0; i < n; i++) {
        vec0.push_back(vec1[i]);
        vec0.push_back(vec2[i]);
    }
    vec1.clear();
    vec2.clear();
}

int reinitializePermutation(int n) {
    vector<int> vec0, vec1, vec2, init;
    int ans = 0;

    for(int i = 0; i < n; i++){
        init.push_back(i);
    }
    
    vec0 = init;

    do{
        deMerge(vec0, vec1, vec2);
        ans++;
        Merge(vec0, vec1, vec2);
    } while(vec0 != init);

    return ans;

}

int main() {
    int n = 6;
    cout << reinitializePermutation(n) << endl;

    return 0;
}
