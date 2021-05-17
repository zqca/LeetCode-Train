#include <iostream>
#include <vector>
#include <unordered_map>
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


vector<int> vec;
unordered_map<int, vector<int> > mp;

void dfs(TreeNode* root){
    if(root == NULL) return;

    vec.push_back(root->val);
    mp[root->val] = vec;

    if(root->left){
        dfs(root->left);
    }

    if(root->right){
        dfs(root->right);
    }

    vec.pop_back();

}

bool isCousins(TreeNode* root, int x, int y) {

    dfs(root);
    int m = mp[x].size();
    int n = mp[y].size();

    if( m != n) return false;

    if(mp[x][m - 2] == mp[y][m - 2]) return false;
    return true;  
}

//TODO: 直接使用bfs来做
bool isCousins_BFS(TreeNode* root, int x, int y) {
    queue<pair<TreeNode*, TreeNode*> > que;
    que.push({root, nullptr});
    vector<TreeNode*> parent;

    while(que.size()){
        int n = que.size();
        for(int i = 0; i < n; i++){
            auto tmp = que.front();
            auto cur = tmp.first, pre = tmp.second;
            que.pop();
            if(cur->val == x || cur->val == y){
                parent.push_back(pre);
            }

            if(cur->left){
                que.push({cur->left, cur});
            }
            if(cur->right){
                que.push({cur->right, cur});
            }
        }
        //某一层结束，判断该层是否存在
        if(parent.size() == 1) return false;//两个数不再同一层
        if(parent.size() == 2){
            if(parent[0] == parent[1]){
                return false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}

int main()
{
   vector<int> input1 = {1,2,999,3,4,999,999,5};
   TreeNode* root1 = new TreeNode();
   constructTree(root1, input1);

   bool ans = isCousins_BFS(root1, 2, 4);
   cout << ans << endl;
   return 0;
}