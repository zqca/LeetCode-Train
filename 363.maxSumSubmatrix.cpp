#include <iostream>
#include <vector>
#include <set>

using namespace std;

//TODO:暴力超时，本题行远多于列
int maxSumSubmatrix1(vector<vector<int>>& matrix, int k) {
    int M = matrix.size();
    int N = matrix[0].size();
    vector<vector<int> > sum(M, vector<int>(N, 0));//int会不会溢出

    int res = INT32_MIN;
    int tmp;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            sum[i][j] = matrix[i][j];
            if(i > 0){
                sum[i][j] += sum[i - 1][j];
            }
            if(j > 0){
                sum[i][j] += sum[i][j - 1];
            }
            if(i > 0 && j > 0){
                sum[i][j] -= sum[i - 1][j - 1];
            }
            if(sum[i][j] == k) return k;//TODO:优化
            
        }
    }

//枚举(r,c)到(i,j)之间的子矩阵和
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            for(int r = 0; r <= i; ++r){
                for(int c = 0; c <= j; ++c){
                    tmp = sum[i][j];
                    if(r > 0){
                        tmp -= sum[r - 1][j];
                    }
                    if(c > 0){
                        tmp -= sum[i][c - 1];
                    }
                    if(r > 0 && c > 0){
                        tmp += sum[r - 1][c - 1];
                    }

                    if(tmp == k) return k;//TODO:优化

                    if(tmp < k){
                        res = max(res, tmp);
                    }

                }
            }
        }
    }

    return res;

}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    //确定上下行，然后对他们之间的列进行筛选
    int top, bottom;
    int M = matrix.size();
    int N = matrix[0].size();
    int ans = INT32_MIN;
   
    for(top = 0; top < M; ++top){ 
        vector<int> sumCol(N,0);
        for(bottom = top; bottom < M; ++bottom){
            for (int c = 0; c < N; ++c) {
                sumCol[c] += matrix[bottom][c]; // 更新每列的元素和
            }
            set<int> sumSet{0};//累计和
            int s = 0;
            for (int v : sumCol) {
                s += v;
                auto lb = sumSet.lower_bound(s - k);//要求Sr-Sl<=k，Sr-Sl尽可能大，也就是要求Sl尽可能小。这里的s对应Sr
                if (lb != sumSet.end()) {
                    ans = max(ans, s - *lb);
                }
                sumSet.insert(s);
            }
            
        }

    }
    return ans;


}


int main()
{
   vector<vector<int> > matrix = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};
   int k = 10;
   cout << maxSumSubmatrix(matrix, k) << endl;

   //system("pause");
   return 0;
}
