#include <iostream>
#include <vector>//从输入构建链表

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* constructList(vector<int> vec) {
    if (vec.size() == 0) return NULL;

    ListNode * head = new ListNode(vec[0]);
    ListNode* tail = head;
    
    for(int i = 1; i < vec.size(); i++) {
        tail->next = new ListNode(vec[i]);
        tail = tail->next;
    }

    return head;
}

void showList(ListNode* list) {
    while(list) {
        cout << list->val << "->";
        list = list->next;
    }
}


ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right) return head;

    int count = 0;//题目保证链表长度至少为1
    ListNode* head1, *head2, *tail1, *tail2, *tmp, *cur;
    ListNode* pre;
    ListNode* ans = new ListNode(INT32_MAX);//空表头节点
    ans->next = head;

    cur = ans;//先指向头节点
    while(count < left - 1) {
        count++;
        cur = cur->next;
    }
    head1 = cur;//指向需要反转节点的前面，此时count = left - 1

    head2 = head1->next;
    cur = head2->next;
    pre = head2;
    count += 2;//始终和cur节点的编号相同，从1 开始编号

    for(; count <= right; ) {
        if(count == right) {
            tail2 = cur;
            tail1 = tail2->next;
        }
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
        count++;
    }
    //最后处理一头一尾
    head1->next = tail2;
    head2->next = tail1;

    return ans->next;
}


int main() {
    vector<int> input = {1,2,3,4,5,6};
    ListNode* list = constructList(input);
    //showList(list);

    int left = 1, right = 6;
    ListNode* ans = reverseBetween(list, left, right);
    showList(ans);

    return 0;

}