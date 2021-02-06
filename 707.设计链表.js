/*
 * @lc app=leetcode.cn id=707 lang=javascript
 *
 * [707] 设计链表
 */

// @lc code=start
/**
 * Initialize your data structure here.
 */
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
var MyLinkedList = function() {
    this.val = 0;
    this.next = null;
    //这是头节点，打算在val值存储链表的length,不是索引
};

/**
 * Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
    if (index < 0 || index >= this.val) {
        return -1;
    }
    //索引index如果是0，那么要myhead.next一次，依次类推
    let i = -1;//表示当前节点的索引
    let temp = this;
    do{
        temp = temp.next;
        i++;
    }while(i < index);
    return temp.val;

};

/**
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
    
    let temp = this.next;//旧的表头
    let newNode = new ListNode(val);
    this.next = newNode;//插入新节点
    newNode.next = temp;

    this.val++;//链表的长度增加
};

/**
 * Append a node of value val to the last element of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
    
    let num = this.val;//获取当前链表的长度
    if(num == 0) {
        //表的长度为0，可以看成在表头插入
        this.addAtHead(val);//已经包含了长度更新
    }
    else {
        let temp = this;//先指向表头节点
        let i = -1;//表示当前的索引
        do{
            temp = temp.next;
            i++;
        }while(i < num - 1);
        //现在，temp指向了最后一个节点
        let newNode = new ListNode(val);
        temp.next = newNode;

        this.val++;//链表的长度加一
    }

   
};

/**
 * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
    if(index == this.val) {
        //需要注意在空表中插入。要排除index=0,这种情况不能看成在尾巴插入
        //因为有个do-while，会访问null->next
        //可以看成在表头插入
        this.addAtTail(val);//已经包含了长度更新
    }
    else if(index <= 0) {
        this.addAtHead(val);//已经包含了长度更新
    }
    else if(index > 0 && index < this.val) {
        //在中间插入
        let temp = this;//先指向表头节点
        let i = -1;//表示当前的索引
        do{
             temp = temp.next;
             i++;
        }while(i < index - 1);
        //现在，temp指向了一个节点,即将在这个节点后面进行插入，后面还有节点
        let newNode = new ListNode(val);
        newNode.next = temp.next;
        temp.next = newNode;
        this.val++;//链表的长度增加
    }
    //剩下的一种情况，不插入


};

/**
 * Delete the index-th node in the linked list, if the index is valid. 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {

    if(index == 0) {
        //删除第一个节点
        let temp = this.next;
        this.next = temp.next;
        this.val--;
    }

    if(index > 0 && index < this.val) {
        //确保索引有效
        let temp = this;//先指向表头节点
        let i = -1;//表示当前的索引
        do{
             temp = temp.next;
             i++;
        }while(i < index - 1);
        //现在，temp指向了一个节点,即将在这个节点后面的节点
        temp.next = temp.next.next;//也适用于删除最后一个节点
        this.val--;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
// @lc code=end


// @after-stub-for-debug-begin
module.exports = MyLinkedList;
// @after-stub-for-debug-end