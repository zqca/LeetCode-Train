/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 * 记录path,两次遍历
 */
var lowestCommonAncestor0 = function (root, p, q) {

    let findPath = (root, target, path) => {
        if (!root) {
            //当前节点为空
            return 0;
        }
        if (root.val === target.val) {
            path.push(root);
            return 1;//找到了答案
        }

        path.push(root);
        let hasFound = findPath(root.left, target, path);

        if (hasFound === 0) {
            //左子树没有找到
            hasFound = findPath(root.right, target, path);
            if (hasFound === 0) {
                //右子树也没有
                path.pop();
                return 0;
            }
        }
        return 1;
    }


    let pathA = [], pathB = [];
    findPath(root, p, pathA);
    findPath(root, q, pathB);

    let min = Math.min(pathA.length, pathB.length);

    for (let i = 0; i < min; ++i) {
        if (pathA[i].val !== pathB[i].val) {
            return pathA[i - 1];
        }
    }
    return pathA[min - 1];
};

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 * 遍历，记录每一个节点的parent
 */
var lowestCommonAncestor1 = function (root, p, q) {
    let parent = new Map();//root没有父亲
    parent.set(root.val, null);

    let dfs = (root) => {
        if (root === null) {
            return;
        }
        if (root.left) {
            parent.set(root.left.val, root);
            dfs(root.left);
        }
        if (root.right) {
            parent.set(root.right.val, root);
            dfs(root.right);
        }
    }

    dfs(root);

    let pathA = [], pathB = [];
    while (p) {
        pathA.unshift(p);
        p = parent.get(p.val);
    }
    while (q) {
        pathB.unshift(q);
        q = parent.get(q.val);
    }

    let min = Math.min(pathA.length, pathB.length);

    for (let i = 0; i < min; ++i) {
        if (pathA[i].val !== pathB[i].val) {
            return pathA[i - 1];
        }
    }
    return pathA[min - 1];
};

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 * hard!!!!!!!
 * root左边有p或者q吗？没有的话返回null
 * root右边有p或者q吗？没有的话返回null
 */
var lowestCommonAncestor2 = function (root, p, q) {
    if (root === null || root === p || root === q) {
        return root;
    }

    let tryLeft = lowestCommonAncestor(root.left, p, q);
    let tryRight = lowestCommonAncestor(root.right, p, q);
    //如果root左边没有p也没有q，答案是tryRight。
    //如果root左边有p或q: 如果右边为null，答案是tryLeft
    //                   如果右边不是null，答案是root.

    return tryLeft === null ? tryRight : (tryRight === null ? tryLeft : root);
};


//debug
let l = {val: 2, left: null, right: null};
let r = {val: 3, left: null, right: null};
let root = {val: 1, left: l, right: r};
console.log(lowestCommonAncestor1(root, l, r));