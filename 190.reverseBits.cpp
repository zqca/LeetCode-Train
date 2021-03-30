#include <iostream>


using namespace std;

uint32_t reverseBits(uint32_t n) {
    long ans = 2, tmp1, tmp2; // 要用long，int会溢出
    
    for(int i = 0; i < 32; i++) {
        /*way1
        ans = ans*2 + n % 2;//n & 1相当于mod 2,取下最后一位数字
        n = n / 2;
        */

        /*way2
        ans = ans << 1;
        tmp2 = n & 1;
        ans = ans + tmp2;
        n = n >> 1;
        */

       ///*way3
       ans = (ans << 1) + (n & 1);//&的优先级，必须加括号
       n = n >> 1;
       //*/
    }
    
    return ans;
   
}

int main() {
    uint32_t n = 0b00000010100101000001111010011100;
    /*
        输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
        因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。

    */
   uint32_t ans = reverseBits(n);
   cout << ans << endl;

   return 0;
}