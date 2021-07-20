/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} target
 * @return {number[][]}
 * 寻找从根节点到叶子节点的路径
 */

var pathSum = function(root, target) {
    let ans = [];
    let dfs = function (node, target, path){
        if(node === null){
            return;
        }
        //处理当前节点
        path.push(node.val);
        target = target - node.val;

        if(target === 0 && node.left === null && node.right === null){
            //递归出口
            ans.push(path);
            return;
        }

       //给dfs传的是一个副本，下一层的dfs不能直接修改当前层次的path！

        if(node.left){
            dfs(node.left, target, [...path]);
        }
        if(node.right){
            dfs(node.right, target, [...path]);
        }

        path.pop();
    }

    dfs(root, target,[]);
    return ans;
};

//debug
let left = new TreeNode(3,null, null);
let right = new TreeNode(3,null, null);
let root = new TreeNode(5, left, right);
let anss = pathSum(root,8);
console.log(anss);

//C++版本
/*

class Solution {
    private:
        vector<vector<int> > ans;
    vector<int> path;
    void dfs(TreeNode* node, int target, vector<int> path){
    //不能修改path!
    if(node == NULL){
    return;
}
target -= node->val;
path.emplace_back(node->val);
if(target == 0 && node->left == NULL && node->right == NULL){
    ans.emplace_back(path);
    return;
}
if(node->left){
    dfs(node->left, target, path);
}
if(node->right){
    dfs(node->right, target, path);
}
path.pop_back();
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
    if(root == NULL) return ans;
    dfs(root, target, path);
    return ans;
}
};

*/


