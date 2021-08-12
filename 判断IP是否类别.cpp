#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string ip){
    ip += '.';
    int pre = 0, cur = 0;
    for(;cur < ip.size(); ++cur){
        if(ip[cur] == '.'){
            if(pre == cur) return false;
            int num = stoi(ip.substr(pre, cur - pre));
            if(num < 0 || num > 255){
                return false;
            }
            pre = cur + 1;
        }
    }
    return true;
}

vector<int> getPart(string ip){
    //提取有效ip的各个部分
    ip += '.';
    vector<int> ans(4,0);
    int idx = 0;
    int pre = 0, cur = 0;
    for(; cur < ip.size(); ++cur){
        if(ip[cur] == '.'){
            ans[idx++] = stoi(ip.substr(pre, cur - pre));
            pre = cur + 1;
        }
    }
    return ans;
}

string binary_num(int num){
    //将数字转换为8位01
    string ans = "";
    for(int i = 0; i < 8; ++i){
        ans = to_string((num & 1)) + ans;
        num = num >> 1;
    }
    return ans;
}

bool checkMask(string str){
    //判断二进制的mask是否有效，32位的;全是0和全是1都非法
    if(str[0] == '0') return false;//必须要有一个1；
    
    //找到第一个0停下
    int pos = 1;
    while(pos < 32 && str[pos] == '1'){
        ++pos;
    }

    if(pos == 32) return false;//全是1

    while(pos < 32 && str[pos] == '0'){
        ++pos;
    }
    if(pos == 32){
        return true;
    }
    else{
        return false;
    }
}

void solve(string str, vector<int> &ans){
/*
10.70.44.68~255.254.255.0
1.0.0.1~255.0.0.0
192.168.0.2~255.255.255.0
19..0.~255.255.255.0

A类地址1.0.0.0~126.255.255.255;
B类地址128.0.0.0~191.255.255.255;
C类地址192.0.0.0~223.255.255.255;
D类地址224.0.0.0~239.255.255.255；
E类地址240.0.0.0~255.255.255.255

私网IP范围是：

10.0.0.0～10.255.255.255
172.16.0.0～172.31.255.255
192.168.0.0～192.168.255.255

1先看IP MASK是否都是在范围之内
    -否，错误+1，结束
    -是，2判断MASK是否有效
        -否，错误+1，结束
        -是，3判断IP类型ABCDE，4判断是不是私网
*/
    int pos = str.find('~');
    string IP = str.substr(0, pos);
    string MASK = str.substr(pos + 1, str.length() - pos);

    //1 先判断IP MASK是否都是在范围之内
    if(isValid(IP) && isValid(MASK)){
        //2 判断MASK是否符合要求
        vector<int> tmp1 = getPart(MASK);
        string binaryMask = "";
        for(int i = 0; i < 4; ++i){
            binaryMask = binaryMask + binary_num(tmp1[i]);
        }
        if(checkMask(binaryMask) == false){
            ans[5]++;
            return;//结束
        };
    
        //3判断IP类型ABCDE
        vector<int> tmp = getPart(IP);
        if(tmp[0] >= 1 && tmp[0] <= 126){
            ans[0]++;
        }
        else if(tmp[0] >= 128 && tmp[0] <= 191){
            ans[1]++;
        }
        else if(tmp[0] >= 192 && tmp[0] <= 223){
            ans[2]++;
        }
        else if(tmp[0] >= 224 && tmp[0] <= 239){
            ans[3]++;
        }
        else if(tmp[0] >= 240 && tmp[0] <= 255){
            ans[4]++;
        }

        //4判断是不是私网
        if(tmp[0] == 10){
            ans[6]++;
        }
        if(tmp[0] == 172 && (tmp[1] >= 16 && tmp[1] <= 31)){
            ans[6]++;
        }
        if(tmp[0] == 192 && tmp[1] == 168){
            ans[6]++;
        }
    }
    else{
        //无效的IP或MASK
        ans[5]++;
    }
        
}


int main()
{
   string str;
   vector<int> ans(7, 0);
   while(cin >> str){
       solve(str, ans);
   }
   
   for(int i = 0; i < 6; i++){
       cout << ans[i] << ' ';
   }
   cout << ans[6] << endl;
   return 0;
}
