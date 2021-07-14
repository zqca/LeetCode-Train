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
 * 迭代法
 */

var mergeTwoLists0 = function(l1, l2) {
    let ans = new ListNode(-1), cur = ans;
    while(l1 !== null && l2 !== null){
        let tmp;
        if(l1.val < l2.val){
            tmp = l1;
            l1 = l1.next;
        }
        else{
            tmp = l2;
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

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 * 递归法
 */

var mergeTwoLists = function(l1, l2) {

    if(l2 === null){
        return l1;
    }
    if(l1 === null) {
        return l2;
    }

    if(l1.val < l2.val){
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    }
    else{
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};