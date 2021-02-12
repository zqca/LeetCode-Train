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

TreeNode* constructTree(vector<int>& nums, int start, int end) {//左闭右开
    int len = end - start;
    int mid = len/2 + start;

    TreeNode* root = new TreeNode(nums[mid]);
    if(len == 1) return root;

    if(len == 2) {
        root->left = constructTree(nums,start,end - 1);
        root->right = NULL;
        return root;
    }

    root->left = constructTree(nums, start, mid);
    root->right = constructTree(nums, mid + 1, end);


    return root;

}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    return constructTree(nums,0,nums.size());
}

int main() {

    vector<int> input1 = {-10};

    TreeNode* result = sortedArrayToBST(input1);

    system("pause");
    return 0;
}