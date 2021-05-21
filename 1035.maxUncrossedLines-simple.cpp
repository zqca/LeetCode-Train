#include <iostream>
#include <vector>

using namespace std;

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    //最长公共子序列
    int m = A.size();
    int n = B.size();
    if(m == 0 || n == 0) return 0;

    vector<int> pre(1 + m);
    vector<int> cur(1 + m);

    for(int i = 1; i <= n; i++) {//row
        for(int j = 1; j <= m; j++) {//col
            if(A[j - 1] == B[i - 1]) {
                cur[j] = pre[j - 1] + 1;
            }
            else {
                cur[j] = max(pre[j], cur[j - 1]);
            }
        }
        pre = cur;
    }

    return cur[m];
}

int main () {
    vector<int> A = {1,3,7,1,7,5};
    vector<int> B = {1,9,2,5,1};
    int ans = maxUncrossedLines(A, B);
    cout << ans << endl;

    return 0;
}