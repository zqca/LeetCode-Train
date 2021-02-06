/*
 * @lc app=leetcode.cn id=203 lang=javascript
 *
 * [203] 移除链表元素
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
 * @param {number} val
 * @return {ListNode}
 */
//TODO:创建一个空节点，有利于解决问题
var removeElements = function(head, val) {
    let myHead = new ListNode(0, head);//创建一个头节点
    let pos1 = myHead;
    let pos2 = head;//哨兵
    while(pos1.next) {
        while(pos2 && pos2.val == val ) {
            //哨兵去寻找需要第一个保存的节点，可能没找到pos2=null
            pos2 = pos2.next;
        }
        if (pos2) {
            //找到啦！
            pos1.next = pos2;
            pos1 = pos2;
            pos2 = pos2.next;
        }
        else {
            //没有找到:( 程序就此结束
            pos1.next = pos2;
            break;   
        }
    }
    return myHead.next;
    
}




//TODO:不使用头节点，较复杂
/*
var removeElements = function(head, val) {
    let i, j;
    //输入为空

    //以要删除的节点开头
    while(head && head.val == val) {
        //先判断head是否为空
        //找到第一个不是val的节点，防止一开头就是需要删除的节点
        head = head.next;
    }

    if(!head) {
        //链表全部都要删除
        return null;
    }

    i = head;
    j = i.next;
    
    while(j){
        
        if(j.val == val) {
            //找到下一个需要保留的节点
            while(j && j.val == val) {
                //先判断j是否为空
                //找到第一个不是val的节点，防止一开头就是需要删除的节点
                j = j.next;
            }

            i.next = j;
            i = i.next;
            if(!j) {
                //到达了结尾
                break;
            }
            else {
                j = j.next;
                continue;
            }

        }

        
        i = j;
        j = j.next;

    }
    return head;

};
*/
// @lc code=end


// @after-stub-for-debug-begin
module.exports = removeElements;
// @after-stub-for-debug-end