#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //将A链中所有节点地址保存在map中，然后从B的开头开始检查
    unordered_map<ListNode*,ListNode*> mp;
    if(!headA) return NULL;

    while(headA){
        mp[headA] = headA;
        headA = headA->next;
    }
    //mp不是空的
    while(headB){
        if(mp.count(headB)){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
