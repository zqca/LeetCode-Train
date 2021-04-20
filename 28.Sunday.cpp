#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
//Sunday算法
int strStr(string haystack, string needle) {
    //构造偏移表
    int h = haystack.size();
    int n = needle.size();
    unordered_map<char, int> pianyi;
    for(int i = 0; i < n; i++) {
        pianyi[needle[i]] = n - i;//TODO:存在最后一个元素距离结尾的距离+1，aab对应a:2,b:1,其他：4
    }

    int i = 0;
    string tmp;
    while(i + n <= h){
        tmp = haystack.substr(i, n);
        if(tmp == needle){
            return i;
        } 
        else{
            //查找下一个元素在偏移表中是否存在
            if(i + n + 1 > h) return -1;
            if(pianyi.find(haystack[i + n]) != pianyi.end()){
                i += pianyi[haystack[i + n]];
            }
            else{
                i += n + 1;//TODO:如果不在，下一个位置是length+1
            }
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
