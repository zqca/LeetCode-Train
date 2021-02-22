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

//由数组构造二叉树，非本题需要
void constructTree(TreeNode* root, vector<int> input) {
    queue<TreeNode*> que;//存放即将构造的节点
    int len = input.size();
    int i;
    TreeNode* cur;

    TreeNode* lchild;
    TreeNode* rchild;

    if(input[0] == 999) {
        return;
    }
    else {
        root->val = input[0];
    }

    que.push(root);

    for(i = 1; i < len; i++) {
        cur = que.front();
        //设置左节点
        if(i < len && input[i] != 999) {//不是null
            lchild = new TreeNode();
            lchild->val = input[i];
            cur->left = lchild;
            que.push(lchild);   
        }

        i++; 
    //设置右节点
        if(i < len && input[i] != 999) {//不是null
            rchild = new TreeNode();
            rchild->val = input[i];
            cur->right = rchild;
            que.push(rchild);  
        }
        que.pop();

    }


}
int result;

int traversal(TreeNode* cur) {

    // 空节点，该节点有覆盖
    if (cur == NULL) return 2;

    int left = traversal(cur->left);    // 左
    int right = traversal(cur->right);  // 右

    // 情况1
    // 左右节点都有覆盖@叶子节点
    if (left == 2 && right == 2) return 0;

    // 情况2
    // left == 0 && right == 0 左右节点无覆盖
    // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
    // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
    // left == 0 && right == 2 左节点无覆盖，右节点覆盖
    // left == 2 && right == 0 左节点覆盖，右节点无覆盖
    if (left == 0 || right == 0) {
        result++;
        return 1;
    }

    // 情况3
    // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
    // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
    // left == 1 && right == 1 左右节点都有摄像头
    // 其他情况前段代码均已覆盖
    if (left == 1 || right == 1) return 2;

    // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
    // 这个 return -1 逻辑不会走到这里。
    return -1;
}

int minCameraCover(TreeNode* root) {
    result = 0;
    // 情况4
    if (traversal(root) == 0) { // root 无覆盖
        result++;
    }
    return result;
}

int main() {
    vector<int> input1 = {0,0,0,999,999,999,0};//使用999来代表null
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    int ans = minCameraCover(root1);
    cout << ans << endl;
    return 0;
}