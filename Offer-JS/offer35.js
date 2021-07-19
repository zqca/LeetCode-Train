/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 * 建立新旧node的映射
 */
var copyRandomList = function(head) {
    if(head === null){
        return head;
    }
    let dumb = new Node(-1, null, null);
    let cur = dumb;
    let mp = new Map();
    let bak = head;
    while(head !== null){
        let tmp = new Node(head.val, null, null);
        mp.set(head, tmp);

        cur.next = tmp;
        head = head.next;
        cur = cur.next;
    }

    while(bak !== null){
        let new_node = mp.get(bak);
        new_node.random = bak.random === null ? null : mp.get(bak.random) ;
        bak = bak.next;
    }

    return dumb.next;

};