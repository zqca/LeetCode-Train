#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int a, int b) {
    if(abs(a) > abs(b)) {
        return true;
    } 
    return false;
}

int largestSumAfterKNegations(vector<int>& A, int K) {
    int sum = 0;
    sort(A.begin(), A.end(), cmp);
    //先消耗K把绝对值大的负数变成正数
    for(int i = 0; i < A.size(); i++) {
        if(A[i] < 0 && K > 0) {
            A[i] *= -1;
            K--;
        }
    }
    //如果K还有剩余，在绝对值最小的元素上，消耗完
    while(K--) {
        A[A.size() - 1] *= -1;
    }

    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    return sum;

}

int main() {
    int K1 = 4;
    vector<int> A1 = {-4,-6,9,-2,2};

    cout << largestSumAfterKNegations(A1, K1);

    return 0;
}