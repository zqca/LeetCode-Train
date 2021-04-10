#include <iostream>

using namespace std;


bool fn(int n){
    //
    if(n == 1) return true;

    if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0){
        return false;
    }

    bool test1 = true, test2 = true, test3 = true;//默认是丑数

    if(n % 2 == 0){
        test1 = fn(n / 2);
    }
    if(n % 3 == 0){
        test2 = fn(n / 3);
    }
    if(n % 5 == 0){
        test3 = fn(n / 5);
    }

    return test1 && test2 && test3;
}

bool isUgly(int n) {
    return fn(n);
}

int main() {
    int n;
    bool ans;
    while(cin >> n){
        ans = isUgly(n);
        cout << ans << endl;
    }
    return 0;
}