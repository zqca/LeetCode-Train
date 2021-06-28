#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //回溯+前缀和
private:
    unordered_map<int, int> prefix;//前缀和,出现的次数

public:
    void visit(TreeNode* cur, int targetSum, int cur_sum, int& ans){
        if(cur == nullptr) return;
        cur_sum += cur->val;//更新前缀和
        if(prefix.count(cur_sum - targetSum)){
            ans += prefix[cur_sum - targetSum];
        }
        prefix[cur_sum]++;//加入当前路径
        visit(cur->left, targetSum, cur_sum, ans);
        visit(cur->right, targetSum, cur_sum, ans);
        //回溯
        prefix[cur_sum]--; 
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        prefix[0] = 1;//前缀和为0的路径只有一条，谁也不选！！
        visit(root, targetSum, 0, ans);
        return ans;
    }
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
