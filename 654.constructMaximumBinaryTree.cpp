#include <iostream>
#include <vector>
#include <queue>//构造二叉树

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


pair<int,int> findMax(vector<int> nums) {
    pair<int,int> result;//返回最大值、index
    //nums不会为null,长度不会为1
    int max = nums[0], index = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == max) {
            index = i;
            break;
        }
    }

    result.first = max;
    result.second = index;

    return result;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    
    TreeNode* node = new TreeNode(nums[0]);

    if(nums.size() == 1) {   
        return node;
    }

    pair<int,int> curmax = findMax(nums);

    TreeNode* root = new TreeNode(curmax.first);

    vector<int> L_nums(nums.begin(), nums.begin() + curmax.second);
    vector<int> R_nums(nums.begin() + curmax.second + 1, nums.end());

    TreeNode* L_Tree = constructMaximumBinaryTree(L_nums);
    TreeNode* R_Tree = constructMaximumBinaryTree(R_nums);

    root->left = L_Tree;
    root->right = R_Tree;

    return root;

}

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    
    TreeNode* tree = constructMaximumBinaryTree(nums);

    return 0;
}