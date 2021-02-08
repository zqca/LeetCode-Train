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

int findBottomLeftValue(TreeNode* root) {
    //不使用递归
    int leftValueofLevel;
    queue<TreeNode*> que;
    if(root) {
        que.push(root);
    }

    while(!que.empty()) {
        
        int curSize = que.size();
        leftValueofLevel = que.front()->val;//记录每一层的第一个节点的值

        for(int i = 0;i < curSize; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if(node->left) {
                que.push(node->left);//将下一层的元素加入
            }
            if(node->right) {
                que.push(node->right);
            }

        }
    }

    return leftValueofLevel;
}


int main() {

    vector<int> input = {2,1,3};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    int result = findBottomLeftValue(root);//本题的输出

    cout << result;

    system("pause");
    return 0;


}




