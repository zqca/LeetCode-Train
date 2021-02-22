#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int monotoneIncreasingDigits(int N) {

    bool flag = true;//判断当前是否需要进行检查
    string s;
    int tmp;

    while(flag) {
        if(N < 10) return N;//特例
        s = to_string(N);
        flag = false;
        for (int i = 0; i + 1 < s.length(); i++) {
            if(s[i] > s[i + 1]) {
                //从i-1开始全部变成9
                for(int j = i + 1 ; j < s.length(); j++) {
                    s[j] = '9';
                }
                tmp = pow(10.0, s.size() - i -1);//332->399-10^2=299
                N = stoi(s) - tmp;

                flag = true;
                break;//当前检查结束
            }
        }
    }
    
    //检出无误，输入就符合要求
    return N;

}

int main() {
    int N = 110;
    int ans = monotoneIncreasingDigits(N);
    cout << ans << endl;
    return 0;
}