/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 * 先中序遍历,保存数组结果
 */
var kthLargest = function(root, k) {
    let visit = [];
    let dfs = (node) => {
        if(!node){
            return;
        }
        dfs(node.left);
        visit.push(node.val);
        dfs(node.right);
    }
    dfs(root);
    return visit[visit.length - k];
};

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 * “右中左”遍历
 */
var kthLargest = function(root, k) {
    let ans, cnt = 0;
    let dfs = (node, k) => {
        if(!node || cnt > k){
            return;
        }

        dfs(node.right, k);
        ++cnt;
        if(k === cnt){
            ans = node.val;
            return;
        }
        dfs(node.left, k);
    }
    dfs(root, k);
    return ans;
};