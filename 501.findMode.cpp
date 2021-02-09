#include <iostream>
#include <vector>
#include <queue>//构造二叉树

#include <unordered_map>

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

void Travel(TreeNode* root, unordered_map<int,int>& times) {

    if(!root) {
        return;
    }

    if(root->left) {
        Travel(root->left, times);
    }

    times[root->val]++;

    if(root->right) {
        Travel(root->right, times);
    }

    return;
}


vector<int> findMode(TreeNode* root) {
    //先把所有节点存在map里面，再寻找最大的出现次数count，再寻找出现次数=count对应的元素
    vector<int> result;

    unordered_map<int,int> times;//<val,count>
    Travel(root, times);

    //cout << times.begin()->first << endl;

    int maxTimes = 0;//
    for(auto  item : times) {
        if(item.second > maxTimes) {
            maxTimes = item.second;
        }
    }
    for(auto  item : times) {
        if(item.second == maxTimes) {
            result.push_back(item.first);
        }
    }

    return result;


}

int main() {

    vector<int> input1 = {1,999,3,2};//使用999来代表null
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);


    vector<int> result = findMode(root1);

    system("pause");
    return 0;
}