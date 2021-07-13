/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd0 = function(head, k) {
    let lt = [];
    while(head){
        lt.push(head);
        head = head.next;
    }
    return lt[lt.length - k];
};

var getKthFromEnd = function(head, k) {
    let slow = head;
    let fast = head;
    for (let i = 0; i < k; ++i) {
        fast = fast.next;
    }

    while(fast){
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
};