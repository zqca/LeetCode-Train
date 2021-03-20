#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node() : value(0), next(NULL) {}
    Node(int x): value(x), next(NULL) {}
    Node(int x, Node* next) : value(x), next(next) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dump_head = new Node();
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= len || index < 0) return -1;
        Node* cur = dump_head;
        int count = -1;
        while(count != index) {
            cur = cur->next;
            count ++;
        }
        return cur->value;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        return addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        return addAtIndex(len, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0) return addAtHead(val);
        if(index > len) return;

        len++;
        Node* tmp = new Node(val);
        int count = -1;
        Node* cur = dump_head;
        while(count != index - 1) {
            cur = cur->next;
            count++;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len) return;//无效位置
        len--;
        Node* tmp;
        int count = -1;
        Node* cur = dump_head;
        while(count != index - 1) {
            cur = cur->next;
            count++;
        }
        tmp = cur->next;//tmp指向被删除的节点
        cur->next = tmp->next;
        delete tmp;
    }

    void printList() {
        Node* cur = dump_head;
        while(cur->next) {
            cur = cur->next;
            cout << cur->value << " ";
        }
        cout << endl;
    }

private:
    Node* dump_head;
    int len;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main() {
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->printList();

    linkedList->addAtTail(3);
    linkedList->printList();

    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList->printList();

    cout << linkedList->get(1) << endl;            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->printList();

    cout << linkedList->get(1) << endl;            //返回3

    return 0;

}
