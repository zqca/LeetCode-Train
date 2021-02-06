/*
 * @lc app=leetcode.cn id=142 lang=javascript
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */

//使用hash表
/*
var detectCycle = function(head) {
    if (!head) {
        //空列表
        return null;
    }
    let hashList = new Map();
    let count = 0;//这个值没意义

    if(head.next == head) {
        //考虑只有一个节点，并且有环
        return head;
    }
    else if (!head.next){
        ////考虑只有一个节点，并且没有环
        return null;
    }
    else {
        //至少有两个节点，先把第一个节点加入
        hashList.set(head, count);//
    }

    let temp = head;
    while(temp.next != null) {
        if(hashList.has(temp.next)) {
            //若已经存在，第一次发现时，表明现在是链尾，下一次就是环的入口
            return temp.next;
        }
        hashList.set(temp.next, count);
        temp = temp.next;//下一个！
    }

    //上面循环结束，表明没有环
    return null;
}
*/


//TODO:使用快慢指针，需要数学知识
var detectCycle = function(head) {
    let slow, fast, temp;
    //let len = head.length;错误，输入的是一个节点，不是数组

    if (!head) {
        return head;
    }
    slow = head;
    fast = head;
    //下面寻找环的入口，使用快慢指针
    //首先，找到相遇节点
    let count = 0;//计数,环的入口是从头开始，索引len-count是入口
    do {
        if(!slow.next || !fast.next || !fast.next.next) {
            //单个节点：无环；两个节点：无环；
            //如果没有环，最终会在这里结束
            return null;
        }
        slow = slow.next;
        fast = fast.next.next;
        count++;
    }while (slow != fast);
    //接着，从相遇节点和head各自派出一个指针，都每次走一步，他们相遇的是入口

    temp = head;
    while (slow != temp) {
        slow = slow.next;
        temp = temp.next;

    }


    return temp;

    
};

// @lc code=end


// @after-stub-for-debug-begin
module.exports = detectCycle;
// @after-stub-for-debug-end