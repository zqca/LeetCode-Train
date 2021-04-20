#include <iostream>
#include <vector>

using namespace std;
//暴力试试
int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;//表示存在
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
}

int main()
{
   string haystack = "mississippi";
   string needle = "issip";
   cout << strStr(haystack, needle) << endl;

   system("pause");
   return 0;
}
