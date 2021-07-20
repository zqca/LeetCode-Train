#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int ans = 0;
   cout << ans << endl;
   return 0;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
        vector<vector<int> > ans;
        vector<int> path;
        void dfs(TreeNode* node, int target, vector<int> path){
            //不能修改path!
            if(node == NULL){
                return;
            }
            target -= node->val;
            path.emplace_back(node->val);
            if(target == 0 && node->left == NULL && node->right == NULL){
                ans.emplace_back(path);
                return;
            }
            if(node->left){
                dfs(node->left, target, path);
            }
            if(node->right){
                dfs(node->right, target, path);
            }
            path.pop_back();
        }
    public:
        vector<vector<int>> pathSum(TreeNode* root, int target) {
            if(root == NULL) return ans;
            dfs(root, target, path);
            return ans;
        }
};