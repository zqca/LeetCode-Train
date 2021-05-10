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

void dfs(TreeNode* root, vector<int>& vec){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        vec.push_back(root->val);
    }

    if(root->left){
        dfs(root->left, vec);
    }
    if(root->right){
        dfs(root->right, vec);
    }

}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> vec1, vec2;
    dfs(root1, vec1);
    dfs(root2, vec2);
    if(vec1.size() != vec2.size()) return false;

    for(int i = 0; i < vec1.size(); i++){
        if(vec1[i] != vec2[i]) return false;
    }
    return true;      
}

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
