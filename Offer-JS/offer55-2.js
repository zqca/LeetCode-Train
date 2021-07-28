/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {

    let getDepth = (root) => {
        //计算树的深度
        if(root === null) return 0;
        return Math.max(getDepth(root.left), getDepth(root.right)) + 1;
    }

    if(!root){
        return true;
    }

    if(isBalanced(root.left) && isBalanced(root.right)){
        let left = getDepth(root.left);
        let right = getDepth(root.right);

        return -1 <= left - right && left - right <= 1;
    }
    return false;
};