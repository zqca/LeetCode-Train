/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 * 遍历poped中的元素.如果当前栈顶不是poped[i]，循环入栈
 */
var validateStackSequences0 = function(pushed, popped) {
    let myStack = [];
    if(pushed.length === 0){
        return popped.length === 0;
    }

    let len = pushed.length;
    let pos = 0;

    for(let i = 0; i < len; ++i){
        //i指向poped数组
        let t = myStack.length;
        if(pos === len && myStack[t - 1] !== popped[i]){
            return  false;
        }

        if(t === 0 || myStack[t - 1] !== popped[i]){
            while(pos < len){
                myStack.push(pushed[pos++]);
                if(pushed[pos - 1] === popped[i]){
                    myStack.pop();
                    break;
                }

            }
        }
        else if(myStack[t - 1] === popped[i]){
            myStack.pop();
        }
    }
    return  true;
};


/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 * 依次入栈；如果辅助栈顶元素等于poped[i]，循环出栈。合法的情况下，最终辅助栈为空
 */
var validateStackSequences = function(pushed, popped) {
    let myStack = [];
    if(pushed.length === 0){
        return  true;
    }
    let len = pushed.length;
    let j = 0;
    for(let pos = 0; pos < len; ++pos){
        myStack.push(pushed[pos]);
        while(myStack.length && myStack[myStack.length - 1] === popped[j]){
            myStack.pop();
            ++j;
        }
    }
    return myStack.length === 0;
};

//debug
let pushed = [1,2,3,4,5], popped = [4,3,5,1,2];
console.log(validateStackSequences(pushed, popped));