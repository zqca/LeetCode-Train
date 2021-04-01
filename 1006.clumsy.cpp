#include <iostream>
#include <vector>

using namespace std;

int Fn(int n) { 
    //递归计算Fn=-n*(n-1)/(n-2) + n-3
    int temp;
    if(n == 0) return 0;
    if(n == 1) return -1;
    if(n == 2) return -2;
    if(n == 3) return -6;

    temp = -(n *(n - 1))/(n - 2) + n - 3;

    return  temp + Fn(n - 4);
}

int clumsy(int N) {
    if(N <= 2) return N;
    int tmp;
    tmp = 2 * (N * (N - 1)/ (N - 2)) ;//注意加括号，不然先×2再取整有误差

    return tmp + Fn(N);
}

int main() {
    int N = 5;
    int ans = clumsy(N);
    cout << ans << endl;

    return 0;
}