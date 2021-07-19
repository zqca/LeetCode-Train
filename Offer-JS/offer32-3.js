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
 * 层次遍历,每层放在一起，z字形
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
    let order = true;//默认正常顺序
    while(que.length){
        let len = que.length;
        let level = [];
        for(let i = 0; i < len; ++i){
            let node =que.shift();
            if(order){
                level.push(node.val);
            }
            else{
                level.unshift(node.val)
            }
            if(node.left){
                que.push(node.left);
            }
            if(node.right){
                que.push(node.right);
            }
        }
        order = !order;//改变顺序
        ans.push(level);
    }
    return ans;
};