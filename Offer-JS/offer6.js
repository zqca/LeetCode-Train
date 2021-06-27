/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */

var reversePrint = function(head) {
    let stack = [];
    while(head !== null){
        stack.unshift(head.val);
        head = head.next;
    }
    return stack;
};