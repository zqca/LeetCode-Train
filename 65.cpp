#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    enum StateType{
        STATE_START,//初始状态
        STATE_SIGN,//符号
        STATE_INTEGER,//整数部分
        STATE_POINT,//左边有数字
        STATE_POINT_NO_LEFT,//左边无数字
        STATE_FLOAT,//小数部分
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INTEGER,
        STATE_END//终止状态，用不到
    };
    enum CharType{
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL//其他输入，非法
    };

    CharType toCharType(char ch){
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        //建立状态机
        unordered_map<StateType, unordered_map<CharType, StateType>> transfer{
            {
                STATE_START, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_SIGN, STATE_SIGN},
                    {CHAR_POINT, STATE_POINT_NO_LEFT}
                }
            },
            {
                STATE_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_NO_LEFT}
                }
            },
            {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FLOAT},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_POINT_NO_LEFT, {
                    {CHAR_NUMBER, STATE_FLOAT}
                }
            },
            {
                STATE_FLOAT, {
                    {CHAR_NUMBER, STATE_FLOAT},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_EXP, {
                    {CHAR_NUMBER, STATE_EXP_INTEGER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            },
            {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_INTEGER}
                }
            },
            {
                STATE_EXP_INTEGER, {
                    {CHAR_NUMBER, STATE_EXP_INTEGER}
                }
            }
        };
        int len = s.size();
        StateType st = STATE_START;
        for(int i = 0; i < len; ++i){
            CharType curtype = toCharType(s[i]);
            if(transfer[st].find(curtype) == transfer[st].end()){
                return false;
            }
            else{
                st = transfer[st][curtype];
            }
        }
        //检查状态机，最后停止的状态是不是合法, 合法的有：3. , 
        return st == STATE_INTEGER || st == STATE_FLOAT || st == STATE_EXP_INTEGER || st == STATE_POINT || st == STATE_END;
    }
};

int main()
{
   string s = "-123.456e789";
   Solution solution;
   bool ans = solution.isNumber(s);
   cout << ans << endl;
   return 0;
}
