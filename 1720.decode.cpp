#include <iostream>
#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    ans.push_back(first);
    int pre = first;
    for(int item : encoded){
        pre = item ^ pre;
        ans.push_back(pre);
    }
    return ans;
}

int main()
{
   vector<int> encoded = {6,2,7,3};
   int first = 4;

   vector<int> ans = decode(encoded, first);
   //cout << ans << endl;
   return 0;
}
