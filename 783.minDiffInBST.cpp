#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(vector<int>& nums){
    queue<TreeNode*> que;
    TreeNode* tmp, *cur, *root;
    root = new TreeNode();
    if(nums[0] == INT32_MAX) return root;
    else{
        root->val = nums[0];
        que.push(root);
    }

    for(int i = 1; i < nums.size(); ++i){
        cur = que.front();
        
        if(i < nums.size() && nums[i] != INT32_MAX){
            tmp = new TreeNode(nums[i]);
            cur->left = tmp;
            que.push(tmp);
        }

        i++;

        if(i < nums.size() && nums[i] != INT32_MAX){
            tmp = new TreeNode(nums[i]);
            cur->right = tmp;
            que.push(tmp);
        }

        que.pop();
    }
    return root;

}

int leftTravel(TreeNode* root){
    if(root == NULL) return INT32_MAX;
    //一路向左
    while(root->left){
        root = root->left;
    }
    return root->val;
}

int rightTravel(TreeNode* root){
    if(root == NULL) return INT32_MIN;
    //一路向右
    while(root->right){
        root = root->right;
    }
    return root->val;
}

void Travel(TreeNode* root, int & ans){
    if(root == NULL) return;
    //少于两个节点
    if(root->left == NULL && root->right == NULL) return;
    int less, more, tmp;
    less = root->val;
    more = less;

    if(root->left){
        less = rightTravel(root->left);
        ans = min(ans, root->val - less);
        Travel(root->left, ans);
    }
    if(root->right){
        more = leftTravel(root->right);
        ans = min(ans, more - root->val);
        Travel(root->right, ans);
    }

}

//直接在树上操作，费事
int minDiffInBST1(TreeNode* root) {
    int ans = INT32_MAX;
    Travel(root, ans);
    return ans;
}

//TODO:转换为数组，再操作



void toVec(TreeNode* root, vector<int>& vec){
    if(root == NULL) return;

    if(root->left){
        toVec(root->left, vec);
    }

    vec.push_back(root->val);

    if(root->right){
        toVec(root->right, vec);
    }
    
}

int minDiffInBST(TreeNode* root) {
    vector<int> vec;
    toVec(root, vec);
    int ans = INT32_MAX;
    for(int i = 1; i < vec.size(); i++){
        ans = min(ans, vec[i] - vec[i - 1]);
    }
    return ans;
}

int main(){
    vector<int> input = {90,69,INT32_MAX,49,89,INT32_MAX,52};
    TreeNode* root = constructTree(input);
    int ans = minDiffInBST(root);

    cout << ans;
    return 0;

}