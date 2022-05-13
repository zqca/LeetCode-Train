#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string M = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string C = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";

void encode(string m){
    string ans = "";
    for(int i = 0; i < m.size(); ++i){
        ans += C[M.find(m[i])];
    }
    cout << ans << endl;
}

void decode(string c){
    string ans = "";
    for(int i = 0; i < c.size(); ++i){
        ans += M[C.find(c[i])];
    }
    cout << ans << endl;
}

int main()
{
   string m, c;
   while(cin >> m >> c){
       encode(m);
       decode(c);
   }
   return 0;
}
