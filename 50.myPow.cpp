#include <iostream>

using namespace std;

double compute(double x, int n) {
    //这是递归,输入的n>0
    if (n == 1) return x; 
    int half_n = n / 2;
    double half = compute(x, half_n);

    if(n % 2) {
        return x * half * half;
    }
    else  {
        return half * half;
    }
        
}


double myPow(double x, int n) {
    
    if(x == 1) return 1;
    if (n == INT32_MIN) return 1 / compute(x , INT32_MAX) / x;
    if(n < 0) {
        if(x == 0) return 0;//?
        return 1 / compute(x, - n);
    }

    if (n == 0) return 1;//? 0^0=1?


    return compute(x, n);
}

int main() {
    double x = 2;
    int n = -2;
    double ans = myPow(x, n);
    cout << ans << endl;

    return 0;
}
