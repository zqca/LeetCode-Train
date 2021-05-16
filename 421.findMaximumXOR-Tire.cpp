#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tire{
    //前缀树（字典树）的节点类
    private:
        Tire* next[2] = {nullptr};
    public:
        Tire(){};//构造函数

        void insert(int num){
            Tire* root = this;//root指向当前节点
            //构造前缀树（字典树）
            for(int i = 30; i >=0; i--){
                //从最高位开始构造,int类型的数字，第31位是最高位
                int x = ((num >> i) & 1);
                if(root->next[x] == nullptr){
                    //当前节点没有孩子x
                    root->next[x] = new Tire();
                }
                root = root->next[x];
            }
        }

        int xor_search(int x){  // 在前缀树中寻找 x 的最大异或值
            Tire *root = this;
            // res表示最大异或值，每次res*2表示左移一位，31循环后左移了31位了，+u表示加上当前的最低位数字
            int res = 0;
            for(int i = 30; i >= 0; i--){
                int u = ((x >> i) & 1);
                 // 若 x 的第 u 位存在，我们走到相反的方向去，因为异或总是|值|相反才取最大值的
                if(root->next[!u]){
                    root = root->next[!u];
                    res = res * 2 + !u;
                }
                // 相反方向的节点为空，只能顺着相同方向走了
                else {
                    root = root->next[u];
                    res = res * 2 + u;
                }
            }
            // 由于上面我们得到的异或另一个数组元素，此时我们需要将这个数组元素与x想异或得到 两个数的最大异或值
            res ^= x;
            return res;
        }
};

int findMaximumXOR(vector<int>& nums) {
    Tire* root = new Tire();
    for(int num : nums){
        //构造树
        root->insert(num);
    }
    int res = 0;
    for(int x : nums){
        res = max(res, root->xor_search(x));
    }
    return res;

}

int main()
{
   vector<int> nums = {3,10,5,25,2,8};
   int ans = findMaximumXOR(nums);
   cout << ans << endl;
   return 0;
}
