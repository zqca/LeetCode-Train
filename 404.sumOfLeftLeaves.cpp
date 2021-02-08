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

void getSum(TreeNode* node, int* sum) {
    //递归出口：某个节点为null或者它没有孩子
    if(node == NULL) {
        return;
    }
    if(node->left == NULL && node->right == NULL) {
        return;
    }

    if(node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
        *sum += node->left->val;
    } 

    getSum(node->left,sum);
    getSum(node->right,sum);
}


int sumOfLeftLeaves(TreeNode* root) {
    
    int sum = 0;
    getSum(root, &sum);
    return sum;

}



int main() {

    vector<int> input = {1,2};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    int result = sumOfLeftLeaves(root);//本题的输出

    cout << result;

    system("pause");
    return 0;


}




