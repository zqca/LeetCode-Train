#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n) {
	vector<int> f(n + 1, 0);//n+1大小，f[0]为0

	for(int i = 1; i <= n; i++) {//从f[1]开始计算
		int minVal = INT_MAX;
		for(int j = 1; j * j <= i; j++ ){
            //每次倒找，看i能不能表示为 j^2 + f[i - j * j],取最小值
            minVal = min(minVal, f[i - j * j]);
        }  
	    f[i] = minVal + 1;
	}
	
    return f[n];
}


int main() {
    int n = 12;
    int ans = numSquares(n);//3,12=4+4+4
    cout << ans << endl;

    return 0;

}