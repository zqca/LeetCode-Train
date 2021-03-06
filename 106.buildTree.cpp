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


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
    //Step1:空、只有一个节点
    if(inorder.size() == 0) return NULL;
    if(inorder.size() == 1) {
        TreeNode*root = new TreeNode(inorder[0]);
        return root;
    }


    //Step2: 找后续数组的分割点；
    int indexDIVpost = postorder.size() - 1;

    TreeNode* root = new TreeNode(postorder[indexDIVpost]);//建立root

    //Step3: 找中序数组中分割点的位置
    int indexDIVin;//中序数组的分割点，
    for(indexDIVin = 0; indexDIVin < inorder.size(); ++indexDIVin) {
        if(inorder[indexDIVin] == postorder[indexDIVpost]) {
            break;
        }
    }
    
    //step4: 分割中序数组：[0,indexDIVin - 1]、[indexDIVin + 1, size() - 1]
    //TODO:统一，左闭右开区间
    vector<int> L_inorder(inorder.begin(), inorder.begin() + indexDIVin);
    vector<int> R_inorder(inorder.begin() + indexDIVin + 1, inorder.end());
    vector<int> L_postorder(postorder.begin(), postorder.begin() + indexDIVin);
    vector<int> R_postorder(postorder.begin() + indexDIVin, postorder.end() - 1);
    
    //Step5: 递归
    //某个子树为空的话，对应的vector也是空的
    TreeNode * leftTree = buildTree(L_inorder,L_postorder);
    TreeNode * rightTree = buildTree(R_inorder,R_postorder);

    //Step6：拼接
    
    root->left = leftTree;
    root->right = rightTree;

    return root;
}


int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* tree = buildTree(inorder, postorder);

    return 0;
}