/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */

function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

var buildTree0 = function(preorder, inorder) {
    if(preorder.length === 0){
        return null;
    }
    if(preorder.length === 1){
        return new TreeNode(preorder[0]);
    }
    //step1:先确定分割点的位置
    let divPoint = preorder[0];
    let pos = inorder.findIndex((cur)=> cur === divPoint);
    //step2:切割子数组
    let inorder_left = inorder.slice(0, pos);
    let inorder_right = inorder.slice(pos + 1, inorder.length);
    let len_left = inorder_left.length;
    let len_right = inorder_right.length;

    let preorder_left = preorder.slice(1, len_left + 1);
    let preorder_right = preorder.slice(len_left + 1, preorder.length);

    let left = buildTree(preorder_left, inorder_left);
    let right = buildTree(preorder_right, inorder_right);

    let ans = new TreeNode(divPoint);
    ans.left = left;
    ans.right = right;
    return ans;
};

var buildTree = function(preorder, inorder) {
    if(!inorder.length) return null
    let tmp = preorder[0],mid = inorder.indexOf(tmp)
    let root = new TreeNode(tmp)
    root.left = buildTree(preorder.slice(1,mid+1),inorder.slice(0,mid))
    root.right = buildTree(preorder.slice(mid+1),inorder.slice(mid + 1))
    return root
};

///debug
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
let root = buildTree(preorder, inorder);
console.log(root)