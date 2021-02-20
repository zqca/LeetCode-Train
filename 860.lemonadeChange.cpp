#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    bool ans = true;
    int len = bills.size();
    vector<int> count(3,0);//各个面值的数量
    for(int i = 0; i < len; i++) {
        if(bills[i] == 5) {
            count[0]++;
        }
        if(bills[i] == 10) {
            if(count[0] < 1) {
                ans = false;
                break;
            }
            else {
                count[0]--;
                count[1]++;
            } 
        }
        if(bills[i] == 20) {
            //需要找15:10+5或者5 *3
            if(count[1] > 0 && count[0] > 0) {
                count[0]--;
                count[1]--;
                count[2]++;
            }
            else if(count[1] == 0 && count[0] > 2) {
                count[0] -= 3;
            }
            else {
                ans = false;
                break;
            }
            
        }
    }

    return ans;
}

int main() {
    vector<int> bills = {5,5,10,10,20};
    cout << lemonadeChange(bills);
    return 0;
}