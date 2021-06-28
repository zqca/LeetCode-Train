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
private:
    unordered_map<TreeNode *, unordered_map<long, long> > mp;//节点p开始，和为sum的路径数目

public:
    void visit(TreeNode* cur){
        if(cur == nullptr) return;

        visit(cur->left);
        visit(cur->right);
        //处理当前节点
        mp[cur][cur->val] += 1;

        unordered_map<long, long>* tmp;

        if(cur->left){
            tmp = &(mp[cur->left]);
            for(auto item : (*tmp)){
                mp[cur][item.first + cur->val] += item.second;
            }
        }

        if(cur->right){
            tmp = &(mp[cur->right]);
            for(auto item : (*tmp)){
                mp[cur][item.first + cur->val] += item.second;
            }
        }
        
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        visit(root);
        for(auto iter : mp){
            auto item = iter.second;//hash map:和，路径数量
            ans += item[targetSum];
        }
        return ans;
    }
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
