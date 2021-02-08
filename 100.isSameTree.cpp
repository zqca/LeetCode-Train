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


bool compare(TreeNode* tree1, TreeNode* tree2) {
    //输入参数代表两个树的root
    if(tree1 != nullptr && tree2 == nullptr) return false;
    if(tree1 == nullptr && tree2 != nullptr) return false;
    if(tree1 == nullptr && tree2 == nullptr) return true;

    if(tree1->val != tree2->val) return false;

    bool leftIsOk = compare(tree1->left, tree2->left);//比较二叉树的zuo侧
    bool rightIsOk = compare(tree1->right, tree2->right);//比较二叉树的you测

    return (leftIsOk && rightIsOk);

}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return compare(p,q);

}



int main() {

    //vector<int> input = {1,2,2,3,4,4,3};//使用999来代表null
    vector<int> input1 = {1,2,2,999,3,999,3};//使用999来代表null
    vector<int> input2 = {1,2,2,999,3,999,3};//使用999来代表null

    TreeNode* p = new TreeNode();
    constructTree(p, input1);

    TreeNode* q = new TreeNode();
    constructTree(q, input2);

    bool result = isSameTree(p,q);//本题的输出
    cout << result << endl;
    
    system("pause");
    return 0;

}






