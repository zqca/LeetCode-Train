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


TreeNode* findParent(TreeNode* in, int val) {
    //给定查找的入口，返回parent
    TreeNode *cur = in, *parent = NULL;
    while(cur) {
        if(cur->val == val) {
            return parent;
        }
        if(cur->val > val) {
            parent = cur;
            cur = cur->left;
        }
        else {
            parent = cur;
            cur = cur->right;
        }
    }
    return NULL;//没有找到，

}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    //情况：
    //叶子结点；只有左孩子；只有右孩子；两个孩子
    TreeNode* virtualNode = new TreeNode(-1);//创建一个虚拟节点
    virtualNode->left = root;
    virtualNode->right = root;
    bool isLeft = 1;

    TreeNode* parent = findParent(virtualNode,key);

    if(parent == NULL) return root;//BST没有相应的元素

    TreeNode* target = NULL;
    
    if(parent->left && parent->left->val == key) {
        //被删除的节点在parent的左侧
        target = parent->left;
    }
    else {
        target = parent->right;
        isLeft = 0;
    }

    //1. 删除的节点是叶子节点
    if(target->left == NULL && target->right == NULL) {
        if(isLeft) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }

        return virtualNode->left;
    }

    //2. 被删除的节点只有左孩子
    if(target->right == NULL) {
        if(isLeft) {
            parent->left = target->left;
            if(parent->val == -1) parent->right = parent->left;
            //如果parent是虚节点，维护另一边。这里其实不需要，因为最后return的是左侧
        }
        else {
            parent->right = target->left;
        }

        return virtualNode->left;//隐含删除root节点的特例
    }

    //3. 被删除的节点只有右孩子
    if(target->left == NULL) {
        if(isLeft) {
            parent->left = target->right;
            if(parent->val == -1) parent->right = parent->left;
            //如果parent是虚节点，维护另一边。
        }
        else {
            parent->right = target->right;
        }

        return virtualNode->right;//隐含删除root节点的特例
    }

    //4. 被删除的节点有两个孩子，将左边的孩子节点提前，重新放置右子树(放在左子树的最右边)
    if(isLeft) {
        parent->left = target->left;  
    }
    else {
        parent->right = target->left;
    }

    TreeNode* newPos = target->left;
    while(newPos->right) {
        newPos = newPos->right;
    }
    newPos->right = target->right;

    return virtualNode->left;
    
        
}

int main() {

    vector<int> input1 = {2,1,999};//使用999来代表null
    int input2 = 2;

    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);


    TreeNode* result = deleteNode(root1, input2);

    system("pause");
    return 0;
}