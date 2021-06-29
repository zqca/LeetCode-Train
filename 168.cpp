#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "", tmp;
        while(columnNumber){
            --columnNumber;
            int r = columnNumber % 26;
            tmp = 'A' + r;
            ans = tmp + ans;
            columnNumber = columnNumber / 26;
        }
        return ans;
    }
};

int main()
{
   Solution solution;
   int columnNumber = 701;
   string ans = solution.convertToTitle(columnNumber);
   cout << ans << endl;
   return 0;
}
