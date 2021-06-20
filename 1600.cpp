#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Person{
    string name;
    int isAlive;
    vector<Person*> children;
    Person(string name) : name(name), isAlive(1){}
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        root = new Person(kingName);
        memo[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        //可以保证parent是活着的
        Person* parent = memo[parentName];
        Person* child = new Person(childName);
        (parent->children).push_back(child); 
        memo[childName] = child;
    }
    
    void death(string name) {
        Person* cur = memo[name];
        cur->isAlive = 0;
    }
    
    vector<string> getInheritanceOrder() {
        order.clear();
        visit(root);
        return order;
    }

    void visit(Person* cur){
        //先序遍历cur的后代
        if(cur->isAlive){
            //当前节点活着
            order.push_back(cur->name);
        }
        int len = (cur->children).size();
        for(int i = 0; i < len; ++i){
            visit((cur->children)[i]);
        }
    }

private:
    Person* root;
    unordered_map<string, Person*> memo;
    vector<string> order;
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}


