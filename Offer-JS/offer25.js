/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var mergeTwoLists = function(l1, l2) {
    let ans = new ListNode(-1), cur = ans;
    while(l1 !== null && l2 !== null){
        let tmp;
        if(l1.val < l2.val){
            tmp = new ListNode(l1.val);
            l1 = l1.next;
        }
        else{
            tmp = new ListNode(l2.val);
            l2 = l2.next;
        }
        cur.next = tmp;
        cur = tmp;
    }

    if(l1 === null){
        cur.next = l2;
    }
    else{
        cur.next = l1;
    }
    return ans.next;

};