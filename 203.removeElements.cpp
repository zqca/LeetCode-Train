#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dumb = new ListNode();
        dumb->next = head;
        ListNode *pre, *cur, *nxt;
        pre = dumb; cur = head;
        while (cur){
            nxt = cur->next;
            if(cur->val == val){
                pre->next = nxt;
                delete cur;
            }
            else{
                pre = cur;
            }
            cur = nxt;
            
        }
        return dumb->next;

    }
};

int main()
{
   ListNode* head = new ListNode(1);
   head->next = new ListNode(2);
   int val = 1;
   Solution tr;


   ListNode* ans = tr.removeElements(head, val);
   cout << ans << endl;
   return 0;
}
