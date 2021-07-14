/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
let judge = function (tree1, tree2){
    //判断tree1的开头部分是否和tree2相同
    if(tree2 === null) {
        return true;
    }
    if(tree1 === null || tree1.val !== tree2.val){
        return false;
    }

    return judge(tree1.left, tree2.left) && judge(tree1.right, tree2.right);
}

var isSubStructure = function(A, B) {
    if(A === null || B === null){
        return false;
    }

    if(A.val === B.val && judge(A, B)){
        return true;
    }

    return isSubStructure(A.left, B) || isSubStructure(A.right, B);
};