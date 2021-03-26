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

void printlist(ListNode* head) {
    //从head开始打印
    if(head) cout << head->val;
    head = head->next;

    while(head != NULL) {
        cout <<  "->" << head->val ;
        head = head->next;
    }
    cout << endl;
}

void constructList(ListNode* &head, vector<int> input) {
    ListNode* dumpNode = new ListNode();
    ListNode* tail = dumpNode;
    for(int i = 0; i < input.size(); i++) {
        tail->next = new ListNode(input[i]);
        tail = tail->next;
    }
    head = dumpNode->next;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;
    
    ListNode *pre, *tail,*tmp;
    pre = head;
    tail = head->next;
    while(tail) {
        while(tail && tail->val == pre->val) {
            tmp = tail->next;
            pre->next = tmp;
            delete tail;
            tail = tmp;
        }
        pre = tail;
        if(tail) {
            //如果tail不是null
            tail = tail->next;
        }
    }
    return head;

}

int main () {
    vector<int> input = {1,1,2,3,3};
    ListNode* head = NULL;
    constructList(head, input);

    printlist(head);

    ListNode* ans = deleteDuplicates(head);

    printlist(ans);

    return 0;

}