#include <iostream>
#include <vector>

using namespace std;
/*
输入：[[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出：11
解释：
员工 1 自身的重要度是 5 ，他有两个直系下属 2 和 3 ，而且 2 和 3 的重要度均为 3 。因此员工 1 的总重要度是 5 + 3 + 3 = 11 。
*/
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    //递归
    int i, sum = 0;
    Employee* item = nullptr;
    for(i = 0; i < employees.size(); i++){
        if(employees[i]->id == id){
            item = employees[i];
            break;
        }
    }

    sum += item->importance;

    if((item->subordinates).size() == 0) return sum;

    for(int k = 0; k < (item->subordinates).size(); ++k){
        sum += getImportance(employees, (item->subordinates)[k]);
    }

    return sum;    
}

int main()
{
   //输入构造复杂，就不搞了
   int ans = 0;
   cout << ans << endl;
   return 0;
}
