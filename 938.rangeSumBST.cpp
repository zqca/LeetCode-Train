#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void visit(TreeNode *root, int low, int high, vector<int>&vec){
    if(root == nullptr) return;
    if(root->val < low){
        if(root->right){
            visit(root->right, low, high, vec);
        }
    }
    else if(root->val > high){
        if(root->left){
            visit(root->left, low, high, vec);
        }
    }
    else{
        if(root->left){
            visit(root->left, low, high, vec);
        }
        vec.push_back(root->val);
        if(root->right){
            visit(root->right, low, high, vec);
        }
    }
}



int rangeSumBST(TreeNode* root, int low, int high) {
    vector<int> res;
    visit(root, low, high, res);
    int sum = 0;
    for(int i:res){
        sum += i;
    }
    return sum;

}



int main()
{
   
   system("pause");
   return 0;
}
