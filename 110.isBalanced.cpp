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

//计算当前子数的层数
int count(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int left = count(node->left);
    int right = count(node->right);

    return max(left,right) + 1;
}

bool cheekTree(TreeNode* node) {
    if(!node) return true;//定义空树，符合

    //先计算左右子树的层数

    int left = count(node->left);
    int right = count(node->right);
    int diff = left - right;

    if(-2 < diff && diff < 2 ) {
        //层数符合要求，则检查这个节点的左右孩子所代表的子树是否平衡
        bool flagLeft = cheekTree(node->left);
        bool flagRight =cheekTree(node->right);
        return (flagLeft && flagRight);
    }
    else {
        return false;
    }

}


bool isBalanced(TreeNode* root) {

    return cheekTree(root);
}

int main() {

    vector<int> input = {1,2,2,3,3,999,999,4,4};//使用999来代表null
    //vector<int> input = {3,9,20,999,999,15,7};//使用999来代表null
    

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    bool result = isBalanced(root);//本题的输出
    cout << result << endl;
    
    system("pause");
    return 0;

}