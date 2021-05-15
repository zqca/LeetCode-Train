#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<string, int> mp;
    mp["I"] = 1;
    mp["V"] = 5; mp["IV"] = 4;
    mp["X"] = 10; mp["IX"] = 9;
    mp["L"] = 50; mp["XL"] = 40;
    mp["C"] = 100; mp["XC"] = 90;
    mp["D"] = 500; mp["CD"] = 400;
    mp["M"] = 1000; mp["CM"] = 900;

    int ans = 0;
    string tmp;
    for(int i = 0; i < s.size(); i++){
        
        if(i + 1 < s.size()){
            tmp = s.substr(i,2);

            if(mp.find(tmp) != mp.end()){
                ans += mp[tmp];
                ++i;
                continue;
            }
        }
        tmp = s.substr(i,1);
        ans += mp[tmp];
    }
    return ans;

}

int main()
{
   string s = "IV";
   int ans = romanToInt(s);
   cout << ans << endl;
   return 0;
}
