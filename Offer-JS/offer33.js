/**
 * @param {number[]} postorder
 * @return {boolean}
 * /找(比最后一个数大的部分)，(比最后一个数小的部分)即可划分为子问题。
 */
var verifyPostorder = function(postorder) {
    let len = postorder.length;
    if(len === 0 || len === 1){
        return true;
    }
    let mid = postorder[len - 1];
    let left = [];//左子树
    let right = [];//右子树
    let i = 0, j = len - 2, count = 0;
    while(i < len - 1 && postorder[i] < mid){
        ++count;
        left.push(postorder[i]);
        ++i;
    }
    while(j >= 0 && postorder[j] > mid){
        ++count;
        right.unshift(postorder[j]);
        --j;
    }
    if(count !== len - 1){
        return false;
    }

    return verifyPostorder(left) && verifyPostorder(right);

};