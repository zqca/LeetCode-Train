/*
 * @lc app=leetcode.cn id=2 lang=javascript
 *
 * [2] 两数相加
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

var addTwoNumbers = function(l1, l2){

    let pos1=l1,pos2=l2;
    let pos3=new ListNode();//这是l3的头节点，空的
    const head=pos3;//这是最终的表头，返回时使用
    let add=0,cur=0,sum=0;//add是进位，cur是相加后对应位置的数字0-9

    do{
        //两个列表对应的位置都有数字
        sum=pos1.val+pos2.val+add;
        cur=sum%10;
        add=parseInt(sum/10);
        pos3.next=new ListNode(cur);
        pos1=pos1.next;
        pos2=pos2.next;
        pos3=pos3.next;
    }while(pos1 && pos2);//已经指向了下一个节点
   
    if(pos1==null && pos2==null){
        //两个列表同时走到头了
        if(add!=0){//有进位
            pos3.next=new ListNode(add);
        }
    }
    else if(pos1){
        //pos1没结束,pos2已结束
            do{
                sum=pos1.val+add;
                cur=sum%10;
                add=parseInt(sum/10);
                pos3.next=new ListNode(cur);
                pos1=pos1.next;
                pos3=pos3.next;
            }while(pos1);

            if(add!=0){
                pos3.next=new ListNode(add);
            }
        }

        else{
            //pos1已经结束,pos2没有结束
            do{
                sum=pos2.val+add;
                cur=sum%10;
                add=parseInt(sum/10);
                pos3.next=new ListNode(cur);
                pos2=pos2.next;
                pos3=pos3.next;
            }while(pos2);

            if(add!=0){
                pos3.next=new ListNode(add);
        }
    }
        
    return head.next;
};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = addTwoNumbers;
// @after-stub-for-debug-end