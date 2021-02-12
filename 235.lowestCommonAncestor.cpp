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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //输入的是二叉搜索树，如果某一个节点的左树包含一个目标，右树包含一个目标，这个节点就是结果
    int min = p->val;
    int max = q->val;
    if(min > max) {
        min = q->val;
        max = p->val;
    }

    TreeNode* cur = root;
    while(cur!=NULL) {
        if(cur->val == min || cur->val == max) {
            break;//可能大的在上，小的为左子树；也可能小的在上，大的为右子树
        } 
        if(cur->val < min) {
            cur = cur->right;
            continue;
        }
        if(cur->val > max) {
            cur = cur->left;
            continue;
        }
       
        if(cur->val > min && cur->val < max) {
            break;
        }
    }

    return cur;
}

int main() {

    vector<int> input1 = {2,1,3};//使用999来代表null

    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    //本题较特殊，首先构造二叉树，然后找到指针p,q(需要根据已经改造的树来确定p,q)
    TreeNode* p = root1->right;//3
    TreeNode* q = root1->left;//1

    TreeNode* result = lowestCommonAncestor(root1, p, q);

    //system("pause");
    return 0;
}