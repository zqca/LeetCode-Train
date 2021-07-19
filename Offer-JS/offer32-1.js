/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 * 层次遍历
 */
var levelOrder = function(root) {
    let ans = [];
    let que = [];
    if(root){
        que.push(root);
    }
    else {
        return ans;
    }
    while(que.length){
        let len = que.length;
        for(let i = 0; i < len; ++i){
            let node =que.shift();
            ans.push(node.val);
            if(node.left){
                que.push(node.left);
            }
            if(node.right){
                que.push(node.right);
            }
        }
    }
    return ans;
};