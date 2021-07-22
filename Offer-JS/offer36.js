/**
 * // Definition for a Node.
 * function Node(val,left,right) {
 *    this.val = val;
 *    this.left = left;
 *    this.right = right;
 * };
 */
function Node(val,left,right) {
   this.val = val;
   this.left = left;
   this.right = right;
};

/**
 * @param {Node} root
 * @return {Node}
 * 递归,分情况讨论
 */
var treeToDoublyList = function(root) {
    if(!root){
        return  root;
    }

    if(!root.left && !root.right){
        //叶子节点,左右孩子都没有
        root.left = root;
        root.right = root;
        return root;
    }

    if(root.left && !root.right){
        //只有左孩子
        let Lchild = treeToDoublyList(root.left);
        root.left = Lchild.left;
        root.right = Lchild;
        Lchild.left.right = root;
        Lchild.left = root;
        return Lchild;
    }

    if(!root.left && root.right){
        //只有右孩子
        let Rchild = treeToDoublyList(root.right);
        root.left = Rchild.left;
        root.right = Rchild;
        Rchild.left.right = root;
        Rchild.left = root;
        return root
    }

    //root的左右孩子都有
    let Lchild = treeToDoublyList(root.left);
    let Rchild = treeToDoublyList(root.right);

    //处理root
    root.left = Lchild.left;
    root.right = Rchild;
    //处理root左侧
    Lchild.left.right = root;
    Lchild.left = Rchild.left;
    //处理root右侧
    Rchild.left.right = Lchild;
    Rchild.left = root;

    return Lchild;
};

/**
 * @param {Node} root
 * @return {Node}
 * hard-中序遍历，head表示头，pre表示前一个访问的节点（对应中序遍历的右子树）.先构造双向链表再变成循环链表
 */
var treeToDoublyList = function(root){
    if(!root){
        return root;
    }

    let head = null, pre = null;
    let visit = function (root){
        //中序遍历
        if(!root){
            return;
        }

        visit(root.left);//处理左孩子

        if(pre === null){
            head = root;//第一个节点
        }
        else{
            pre.right = root;//修改上一个节点的右侧
        }

        root.left = pre;
        pre = root;

        visit(root.right);//处理右孩子

    }

    visit(root);
    head.left = pre;
    pre.right = head;
    return head;
}