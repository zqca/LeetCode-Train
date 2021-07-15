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
 *先构造镜像树，再比较
 */
var isSymmetric0 = function(root) {
    let mirrorTree = function(root) {
        if(root === null){
            return root;
        }
        let tmp1 = mirrorTree(root.right);
        let tmp2 = mirrorTree(root.left);

        let node = new TreeNode(root.val);

        node.left = tmp1;
        node.right = tmp2;

        return node;
    };
    let compare = function (root1, root2){
        if(root1 === null && root2 !== null || root2 === null && root1 !== null ){
            return false;
        }
        if(root1 === null && root2 === null){
            return true;
        }
        if(root1.val !== root2.val){
            return false;
        }
        return compare(root1.left, root2.left) && compare(root1.right, root2.right);
    }

    let tree = mirrorTree(root);
    return compare(root, tree);
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 * 直接比较
 */
var isSymmetric = function(root) {
    let compare = function(ltree, rtree){
        if(ltree === null && rtree !== null || ltree !== null && rtree === null){
            return false;
        }
        if(ltree === null && rtree === null){
            return true;
        }
        if(ltree.val !== rtree.val){
            return false;
        }
        return compare(ltree.left, rtree.right) && compare(ltree.right, rtree.left);
    }

    if(root === null){
        return true;
    }
    return compare(root.left, root.right);
};