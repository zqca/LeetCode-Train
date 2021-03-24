#include <iostream>
#include <map>

using namespace std;

struct Node{
    //双向链表
    int key;
    int value;
    int cnt = 1;//使用频率
    Node* prev = NULL;
    Node* next = NULL;

    Node(int key, int value, int cnt):key(key),value(value),cnt(cnt) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        //初始化，两端直接增加dump节点
        dumpHead = new Node(INT32_MAX,INT32_MAX,INT32_MAX);
        dumpTail = new Node(INT32_MIN,INT32_MIN,INT32_MIN);
        myList = dumpHead;
        dumpHead->next = dumpTail;
        dumpTail->prev = dumpHead;
    }
    
    int get(int key) {
        //如果不存在，返回-1
        if(key2pos.find(key) == key2pos.end()) return -1;

        //存在，从map中获取list中的索引，修改当前节点的cnt,将当前节点移到合适的位置，返回当前节点的值
        Node* it = key2pos[key];
        it->cnt = it->cnt + 1;

        move(myList, it, it->cnt);
        return it->value;
    }
    
    void put(int key, int value) {
        //已经存在，做修改当前节点的value,cnt，移到合适的位置
        if(key2pos.find(key) != key2pos.end()) {
            Node* it = key2pos[key];
            it->cnt = it->cnt + 1;
            it->value = value;
            move(myList, it, it->cnt);
            return ;
        }

        //不存在，插入，没有达到规定容量，创建新节点，做修改当前节点的value,cnt，移到合适的位置
        //记得操作map
        if(key2pos.size() < maxCapacity) {
            Node* tmp = new Node(key, value, 1);//默认cnt为1
            //先插在最后，再移动
            
            tmp->prev = dumpTail->prev;
            dumpTail->prev->next = tmp;
            tmp->next = dumpTail;
            dumpTail->prev = tmp;
            move(myList, tmp, 1);//把当前新节点放在合适的位置

            key2pos[key] = tmp;
        }

        //不存在，插入，需要删除一个元素再插入
        else{
            deleteAndput(key, value);
        }

    }

    void move(Node* myList, Node* curpos, int targetCNT) {

        Node *prepos = curpos->prev;//指向第一个cnt>targetCNT的节点
        while(prepos->cnt <= targetCNT) {
            prepos = prepos->prev;
        }
        curpos->next->prev = curpos->prev;//修改旧节点的后面
        curpos->prev->next = curpos->next;//修改旧节点的前面

        curpos->next = prepos->next;//修改旧节点
        curpos->prev = prepos;

        prepos->next->prev = curpos;//修改插入位置的后面
        prepos->next = curpos;//修改插入位置的前面
    }

    void deleteAndput(int key, int value) {
        //如果本来就是一个空的，不能删除
        if(key2pos.size() == 0) return;

        //一方面是对链表的操作，另一方面是对map的操作
        //1.直接删除链表的尾巴
        Node* tail = dumpTail->prev;
        Node* prevOfTail = tail->prev;
        prevOfTail->next = dumpTail;
        dumpTail->prev = prevOfTail;
        
        //2.删除map中的元素
        key2pos.erase(tail->key);

        delete tail;//最后删除尾巴节点

        //3.插入
        put(key, value);
    }



private: 
    map<int, Node*> key2pos;//建立某个值到链表迭代器的映射
    Node * myList, *dumpTail, *dumpHead;

    int maxCapacity;
};



int main() {
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


    int capacity = 2;
    LFUCache* lFUCache = new LFUCache(capacity);

    lFUCache->put(1, 1);   // cache=[1,_], cnt(1)=1
    lFUCache->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout<< lFUCache->get(1) << endl;      // 返回 1
                        // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache->put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                        // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout<< lFUCache->get(2) << endl;      // 返回 -1（未找到）
    cout<< lFUCache->get(3) << endl;      // 返回 3
                        // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache->put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                        // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout<< lFUCache->get(1) << endl;      // 返回 -1（未找到）
    cout<< lFUCache->get(3) << endl;      // 返回 3
                        // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout<< lFUCache->get(4) << endl;      // 返回 4
                        // cache=[3,4], cnt(4)=2, cnt(3)=3

    return 0;

}