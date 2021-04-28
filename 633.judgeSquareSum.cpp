#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c) {
    long left = 0;
    long right = sqrt(c);
    long sum;
    while(left <= right){
        sum = left*left + right*right;
        if(sum == c) return true;
        if(sum > c){
            --right;
        }
        else{
            ++left;
        }
    }
    return false;

}


int main()
{
   
   int c = 25;
   cout << judgeSquareSum(c) << endl;
   return 0;
}
