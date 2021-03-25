#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TODO:中规中矩,AC
ListNode* deleteDuplicates_1(ListNode* head) {
    if(head == nullptr) {
        return head;
    }
        
    //可以保证head不是null
    ListNode * dumpNode = new ListNode(0, head);

    ListNode * pre, *st, *ed;
    //分别指向最后一个正确的节点，需要删除的第一个节点，以及最后一个节点后面那个节点
    pre = dumpNode;
    st = head;
    ed = head->next;//初始化,可以保证head不是null

    while(ed) {
        if(ed->val != st->val) {
            pre = pre->next;
            st = st->next;
            ed = ed->next;
            continue;
        }

        while(ed && ed->val == st->val) {
            ed = ed->next;
        }
    //开始删除重复的链表
        ListNode* tmp;
        while(st != ed) {
            tmp = st->next;
            pre->next = tmp;
            delete st;
            st = tmp;
        }
    //准备下一次删除,如果有的话
        st = ed;
        //ed如果已经是null了，不要再更新ed
        if(ed) {
            ed = ed->next;
        }
    }

    return dumpNode->next;

}

ListNode* deleteDuplicates(ListNode* head) {
//TODO:投机取巧,考虑到是一个有序链表，先把链表中的数字全部取下来存入map，（去重），然后利用数组重新构造链表
    if(head == nullptr) return head;
    map<int,int> nums;
    ListNode* ans, *tail, *tmp;
    while(head) {
        nums[head->val]++;
        head = head->next;
    }
    ans = new ListNode();
    tail = ans;
    ans->next = NULL;

    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        if(iter->second == 1) {
            tmp = new ListNode(iter->first);
            tail->next = tmp;
            tail = tail->next;
        } 
    }
    return ans->next;
}


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

int main () {
    vector<int> input = {1,1};
    ListNode* head = NULL;
    constructList(head, input);

    printlist(head);

    ListNode* ans = deleteDuplicates(head);

    printlist(ans);

    return 0;

}