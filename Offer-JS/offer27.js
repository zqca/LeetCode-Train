/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if(root === null){
        return root;
    }

    let tmp1 = mirrorTree(root.right);
    let tmp2 = mirrorTree(root.left);

    root.left = tmp1;
    root.right = tmp2;

    return root;
};