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

ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || !head) return head;

    //首先将首位连接，并统计节点个数
    int count =  1;
    ListNode *cur;
    cur = head;
    while(cur->next) {
        count++;
        cur = cur->next;
    }
    cur->next = head;

    int step = count - k % count;

    while(step) {
        cur = head;
        head = head->next;
        step--;
    }
    cur->next = NULL;

    return head;
}

int main () {
    vector<int> input = {0,1,2};
    int k = 4;

    ListNode* head = NULL;
    constructList(head, input);
    printlist(head);

    ListNode* ans = rotateRight(head, k);

    printlist(ans);

    return 0;

}