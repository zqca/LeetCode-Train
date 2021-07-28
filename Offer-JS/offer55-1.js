/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    let ans = 0;
    if(root === null) return ans;

    let dfs = (node, curLen) => {
        if(!node){
            ans = ans < curLen - 1 ? curLen - 1 : ans;
            return;
        }

        dfs(node.left, curLen + 1);
        dfs(node.right, curLen + 1);

    }
    dfs(root, 1);
    return ans;
};

/**
 * 优化
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    //计算树的深度
    if(root === null) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
};