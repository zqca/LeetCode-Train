/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}

var deleteNode = function(head, val) {
    let dumb = new ListNode(-1);
    dumb.next = head;
    let cur = dumb, next = head;
    while(next.val !== val){
        cur = next;
        next = next.next;
    }
    cur.next = next.next;
    return dumb.next;
};