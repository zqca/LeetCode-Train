/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    // 状态枚举
    const STATE_START = 0;              //空格开始
    const STATE_SIGN_BEFORE = 1;        //exp前的符号
    const STATE_NUM_BEFORE = 2;         //exp前的整数
    const STATE_DOT_WITH_LEFT = 3;      //左侧有数字的小数点
    const STATE_DOT_WITHOUT_LEFT = 4;   //左侧无数字的小数点
    const STATE_FLOAT_BEFORE = 5;       //exp前的小数
    const STATE_EXP = 6;                //exp
    const STATE_SIGN_AFTER = 7;         //exp后的符号
    const STATE_NUM_AFTER = 8;          //exp后的整数
    const STATE_END = 9;                //空格结束

    // 字符枚举
    const CHAR_NUMBER = 0               // 0-9
    const CHAR_EXP = 1                  // E e
    const CHAR_DOT = 2                  // .
    const CHAR_SIGN = 3                 // + -
    const CHAR_SPACE = 4                // ' '
    const CHAR_ILLEGAL = 5              // 除上面字符外都是非法字符

    let getChar = (ch)=>{
        if(ch >= '0' && ch <= '9'){
            return CHAR_NUMBER;
        }
        switch (ch) {
            case 'E': case 'e':
                return CHAR_EXP;
            case '.':
                return CHAR_DOT;
            case '+': case '-':
                return CHAR_SIGN;
            case ' ':
                return CHAR_SPACE;
            default:
                return CHAR_ILLEGAL;
        }
    }
    //状态转移表,如果想用变量的值作为属性名，用中括号[]扩起来
    const transfer = {
        [STATE_START] : {
            [CHAR_SPACE] : STATE_START,
            [CHAR_NUMBER] : STATE_NUM_BEFORE,
            [CHAR_SIGN ]: STATE_SIGN_BEFORE,
            [CHAR_DOT] : STATE_DOT_WITHOUT_LEFT
        },
        [STATE_SIGN_BEFORE] : {
            [CHAR_NUMBER] : STATE_NUM_BEFORE,
            [CHAR_DOT] : STATE_DOT_WITHOUT_LEFT
        },
        [STATE_NUM_BEFORE] : {
            [CHAR_NUMBER] : STATE_NUM_BEFORE,
            [CHAR_SPACE] : STATE_END,
            [CHAR_EXP] : STATE_EXP,
            [CHAR_DOT] : STATE_DOT_WITH_LEFT
        },
        [STATE_DOT_WITH_LEFT] : {
            [CHAR_EXP] : STATE_EXP,
            [CHAR_NUMBER] : STATE_FLOAT_BEFORE,
            [CHAR_SPACE] : STATE_END,
        },
        [STATE_DOT_WITHOUT_LEFT] : {
            [CHAR_NUMBER] : STATE_FLOAT_BEFORE,
        },
        [STATE_FLOAT_BEFORE] : {
            [CHAR_NUMBER] : STATE_FLOAT_BEFORE,
            [CHAR_EXP] : STATE_EXP,
            [CHAR_SPACE] : STATE_END,
        },
        [STATE_EXP] : {
            [CHAR_NUMBER] : STATE_NUM_AFTER,
            [CHAR_SIGN] : STATE_SIGN_AFTER
        },
        [STATE_SIGN_AFTER] : {
            [CHAR_NUMBER] : STATE_NUM_AFTER,
        },
        [STATE_NUM_AFTER] : {
            [CHAR_NUMBER] : STATE_NUM_AFTER,
            [CHAR_SPACE] : STATE_END,
        },
        [STATE_END] : {
            [CHAR_SPACE] : STATE_END
        }
    }

    let CUR_STATE = STATE_START;
    for(let i  = 0; i < s.length; ++i){
        let ch = getChar(s[i]);
        let NEXT_STATE = transfer[CUR_STATE][ch];
        if(NEXT_STATE === undefined){
            return false;
        }
        else{
            CUR_STATE = NEXT_STATE;
        }
    }

    return  CUR_STATE === STATE_NUM_BEFORE ||
            CUR_STATE === STATE_DOT_WITH_LEFT ||
            CUR_STATE === STATE_FLOAT_BEFORE ||
            CUR_STATE === STATE_NUM_AFTER ||
            CUR_STATE === STATE_END;

};

//debug
let s = "0";
console.log(isNumber(s));