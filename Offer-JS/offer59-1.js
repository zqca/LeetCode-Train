/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 * 设计一个数据结构，始终确保窗口内的最大值在队头
 */
function myQue(){
    this.que = [];
}

myQue.prototype.myFront = function(){
    return this.que[0];
}

myQue.prototype.myPush = function(value){
    //从尾部比较，比value小的值都要去掉。因为这些值在value存在的条件下不可能是最大值
    let len = this.que.length;
    while(len && this.que[len - 1] < value){
        this.que.pop();
        --len;
    }
    this.que.push(value);
}

myQue.prototype.myPop = function(value){
    //去除指定的值，只去除1个
    if(this.que.length && this.que[0] === value){
        //只有当前窗口的最大值（队头）是需要去除的值时才操作
        this.que.shift();
    }
}

var maxSlidingWindow = function(nums, k) {
    if(nums.length === 0) return [];

    let Que = new myQue();
    let ans = [];
    for(let i = 0; i < k; ++i){
        Que.myPush(nums[i]);
    }
    ans.push(Que.myFront());

    for(let i = k; i < nums.length; ++i){
        Que.myPop(nums[i - k]);
        Que.myPush(nums[i]);
        ans.push(Que.myFront());
    }

    return ans;
};

//debug
let nums = [1,3,-1,-3,5,3,6,7], k = 3;
console.log(maxSlidingWindow(nums, k));