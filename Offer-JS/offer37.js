/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 * 不将null入队
 * TODO:创建的节点的val需要是数字，现在是字符串！！！
 */
var serialize0 = function(root) {
    //输出字符串形式：'1,2,3,#,#,4,5'
    let que = [];
    let arr = [];
    if(!root){
        return '#';
    }
    else{
        que.push(root);
        arr.push(root.val)
    }

    while(que.length){
        let len = que.length;
        for(let i = 0; i < len; ++i){
            let node = que.shift();

            if(node.left){
                que.push(node.left);
                arr.push(node.left.val);
            }
            else{
                arr.push('#');
            }

            if(node.right){
                que.push(node.right);
                arr.push(node.right.val);
            }
            else{
                arr.push('#');
            }
        }
    }
    return arr.join(',');

};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize0 = function(data) {
    if(data === '#'){
        return null;
    }

    let arr = data.split(',');
    let que = [];
    let root = new TreeNode(arr.shift());//取出第一个元素
    que.push(root);

    while(arr.length){
        let curNode = que.shift();
        let left_val = arr.shift();
        let right_val = arr.shift();
        let left, right;
        if(left_val === '#'){
            left = null;
        }
        else{
            left = new TreeNode(left_val);
        }

        if(right_val === '#'){
            right = null;
        }
        else{
            right = new TreeNode(right_val);
        }

        curNode.left = left;
        curNode.right = right;
        if(left){
            que.push(left);
        }
        if(right){
            que.push(right);
        }
    }
    return root;
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */




//TODO:分割线

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 * 精简代码
 */
var serialize = function(root) {
    if(!root) return "#";
    // 初始化字符串和节点数组
    let res = "", temp = [root];
    while(temp.length){
        // 挨个取出节点
        let node = temp.shift();
        if(node){
            res += `${node.val},`;
            // 遇到不为空的节点才继续推入其左右节点
            temp.push(node.left);
            temp.push(node.right);
        }else{
            // 节点为空则插入#，
            res += "#,"
        }
    }
    // 去掉最后一个逗号
    res = res.substr(0,res.length-1);
    return res;
};


/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    // 只有"#"的情况
    if (data === '#') {
        return null;
    }
    // 把值组成数组
    let valarr=data.split(',');
    // 创建根节点
    let root=new TreeNode(parseInt(valarr[0]));
    // 形成一个节点，值就弹走一个
    valarr.shift();

    let temp = [root];
    while(temp.length){
        // 获取当前操作节点
        let node = temp.shift();
        // 现在弹出的第一个值是左节点的值
        let leftval = valarr.shift();
        if(leftval!=="#"){
            // 不为空则附在根节点上，并把新节点推入temp
            node.left=new TreeNode(parseInt(leftval));
            temp.push(node.left);
        }
        // 现在弹出的第一个值是右节点的值
        let rightval = valarr.shift();
        if(rightval!=="#"){
            node.right=new TreeNode(parseInt(rightval));
            temp.push(node.right);
        }

    }
    return root;

};




//debug
let raw = '1,2,#,#,#';
let root = deserialize(raw);
let data = serialize(root);
debugger