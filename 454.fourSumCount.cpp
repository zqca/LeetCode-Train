#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    //输入是引用
    unordered_map<int, int> part1;
    int result = 0;
    for (const int a : A) {
        for(const int b : B) {
            part1[a + b]++;
            //记录A中元素＋B中元素出现的情况，即某个值=A[i]+B[j]有多少种情况
        }
    }

    for (const int c : C) {
        for(const int d : D) {
            if(part1[-(c + d)]) {
                //如果存在互补的A+B
                result += part1[-(c + d)];
            }   
            
        }
    }

    return result;

}




int main() {

	vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

	int result = fourSumCount(A, B, C, D);
	
	cout << result << endl;

    system("pause");
    return 0;
}