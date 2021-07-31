/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 * 记录path,两次遍历
 */
var lowestCommonAncestor0 = function (root, p, q) {
    let findPath = (root, target) => {
        //返回路径
        let ans = [];
        while (root.val !== target.val) {
            ans.push(root);
            if (root.val < target.val) {
                root = root.right;
            } else {
                root = root.left;
            }
        }
        ans.push(root);
        return ans;
    }

    let pathA = findPath(root, p);
    let pathB = findPath(root, q);
    let min = Math.min(pathA.length, pathB.length);

    for (let i = 0; i < min; ++i) {
        if (pathA[i].val !== pathB[i].val) {
            return pathA[i - 1];
        }
    }
    return pathA[min - 1];
};

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 * 一次遍历，如果当前节点的值位于p,q之间，那么当前节点就是ans
 */
var lowestCommonAncestor = function (root, p, q) {
    while (true) {
        if (root.val > p.val && root.val > q.val) {
            //都在左边
            root = root.left;
        } else if (root.val < p.val && root.val < q.val) {
            //都在右边
            root = root.right;
        } else {
            return root;
        }
    }

};