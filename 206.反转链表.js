/*
 * @lc app=leetcode.cn id=206 lang=javascript
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

/*修改节点的值
var reverseList = function(head) {
    //创建一个队列保存节点的数值，再根据队列的数值修改原始节点的值

    //考虑到空链表?
    if (!head) return head;

    let pos = head;
    let list = [];

    while (pos) {
        list.push(pos.val);
        pos = pos.next;
    }

    let i = 0;
    pos = head;
    while(pos) {
        pos.val = list[list.length -1 - i];
        i++;
        pos = pos.next;
    }
    return head;
};
*/

//递归改变节点的指针
function swapListAndNode(list) {
    //目前list已经反转完成；
    //递归出口，list只有一个节点
    if (!list.next) {
        return list;
    }
      //首先获取list最后一个节点
    let temp=swapListAndNode(list.next);
    let head = temp;
    while (temp.next) {
        temp = temp.next;
    }

    temp.next = list
    list.next = null;
    return head;
    
}
var reverseList = function(head) {
    if (!head) {
        return head;
    }
    else {
        return swapListAndNode(head);
    }
    

}
// @lc code=end


// @after-stub-for-debug-begin
module.exports = reverseList;
// @after-stub-for-debug-end