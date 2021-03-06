#include <iostream>
#include <string>

using namespace std;

int dayOfYear(string date) {
    //date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8, 2));

    bool isYap = 0;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) isYap = 1;

    int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    int ans = day;//计算当月天数
    
    for(int i = 0; i < month; ++i) {
        ans += mon[i];//计算之前的天数
    }

    if(isYap && month > 2) ans += 1;//补上闰年

    return ans;
}

int main() {
    string date = "2004-03-01";
    cout << dayOfYear(date) << endl;

    return 0;
}