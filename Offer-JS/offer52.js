/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 * 先比较两个链表的长度，双指针
 */
var getIntersectionNode = function(headA, headB) {
    let lenA = 0, lenB = 0;
    let bak_A = headA, bak_B = headB;
    while(headA){
        ++lenA;
        headA = headA.next;
    }
    while(headB){
        ++lenB;
        headB = headB.next;
    }
    let i = bak_A, j = bak_B;
    if(lenA < lenB){
        for(let tmp = 0; tmp < lenB - lenA; ++tmp){
            j = j.next;
        }
    }
    if(lenA > lenB){
        for(let tmp = 0; tmp < lenA - lenB; ++tmp){
            i = i.next;
        }
    }

    //一起走
    while(i !== null && j !== null){
        if(i === j){
            return i;
        }
        i = i.next;
        j = j.next;
    }
    return null;
};

//debug
let t1 = new ListNode(0);
let t2 = new ListNode(9);
let t3 = new ListNode(1);

let t6 = new ListNode(3);

let t4 = new ListNode(2);
let t5 = new ListNode(4);



t1.next = t2;
t2.next = t3
t3.next = t4;

t6.next = t4;

t4.next = t5;

let ans = getIntersectionNode(t1, t6);
console.log(22)