#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>


using namespace std;

int getNum(int num){
    if(num >= 1000) return 1000;
    if(num >= 900) return 900;
    if(num >= 500) return 500;
    if(num >= 400) return 400;
    if(num >= 100) return 100;
    if(num >= 90) return 90;
    if(num >= 50) return 50;
    if(num >= 40) return 40;
    if(num >= 10) return 10;
    if(num >= 9) return 9;
    if(num >= 5) return 5;
    if(num >= 4) return 4;
    if(num >= 1) return 1;

    return -1;
}

string intToRoman(int num) {
    set<int> nums = {1,5,10,50,100,500,1000,4,9,40,90,400,900};
    unordered_map<int,string> mp;
    mp[1] = "I";
    mp[5] = "V"; mp[4] = "IV";
    mp[10] = "X"; mp[9] = "IX";
    mp[50] = "L"; mp[40] = "XL";
    mp[100] = "C"; mp[90] = "XC";
    mp[500] = "D"; mp[400] = "CD";
    mp[1000] = "M"; mp[900] = "CM";
    
    string ans = "";
    int tmp;
    while(num != 0){
        tmp = getNum(num);
        ans += mp[tmp];
        num -= tmp;
    }

    return ans;
}

int main()
{
   int num = 12;
   string ans = intToRoman(num);
   cout << ans << endl;
   return 0;
}
