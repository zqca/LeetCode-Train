/*
 * @lc app=leetcode.cn id=59 lang=javascript
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number[][]}
 */

var generateMatrix = function(n) {
    //初始化数组
    let nums = new Array(n);
    let i, loopTime, num, startIndex, curWidth;
    let count = 1;//等待填充的数字

    for(i = 0; i < n; i++) {
        nums[i] = new Array(n);
    }
    loopTime = Math.floor(n / 2);//无论奇数偶数，奇数需要最后填充中心元素
    if(n % 2) {
        //奇数
        nums[loopTime][loopTime] = n * n;
    }

    startIndex = 0;
    curWidth = n;

    while(loopTime--) {
        //UP
        for (i = startIndex; i < startIndex + curWidth - 1; i++) {
            nums[startIndex][i] = count++;
        }
        //RIGHT
        for (i = startIndex; i < startIndex + curWidth - 1; i++) {
            nums[i][startIndex + curWidth - 1] = count++;
        }
        //DOWN
        for (i = startIndex + curWidth - 1; i > startIndex; i--) {
            nums[startIndex + curWidth - 1][i] = count++;
        }
        //LEFT
        for (i = startIndex + curWidth - 1; i > startIndex; i--) {
            nums[i][startIndex] = count++;
        }
        startIndex++;
        curWidth -= 2;

    }


    return nums;

}






//TODO:AC,但是频繁调用函数，效率太低
/*
//填充边框，边框的左上角有规律；需要将n分奇偶数
function fill(width, startPos, startVal, nums) {
    //输入边框的宽度，开始的位置，初始值，填充结果
    let endPos = startPos + width;//边框索引范围是[startPos, endPos)
    let i;
    //上边框
    for(i = startPos; i <= endPos - 2; i++) {
        nums[startPos][i] = startVal++;
    }
    //右
    for(i = startPos; i <= endPos - 2; i++) {
        nums[i][endPos - 1] = startVal++;
    }
    //下
    for(i = endPos - 1; i >= startPos + 1; i--) {
        nums[endPos - 1][i] = startVal++;
    }
    //左
    for(i = endPos - 1; i >= startPos + 1; i--) {
        nums[i][startPos] = startVal++;
    }

    return nums;
}

var generateMatrix = function(n) {
    //初始化数组
    let nums = new Array(n);
    let i;
    for(i = 0; i < n; i++) {
        nums[i] = new Array(n);
    }

    let fillTimes;//需要执行填充的次数,
    let startPos;
    let width;//初始边框宽度
    let addVal;
    let startVal;

    // 第一次填充的参数
    width = n;
    startPos = 0;
    startVal = 1;
    nums = fill(width, startPos, startVal, nums);//填充最外层

    if (n % 2) {
        //n奇数
        //填充最内层
        nums[(n - 1) / 2][(n - 1) / 2] = n * n;

        fillTimes = (n + 1) / 2;//总的填充次数

        for(i = 2; i < fillTimes; i++) {
            //i是当前填充的次数，由于中心单独填充，所以实际填充之间的夹层
            startPos = i - 1;//开始索引
            width = width - 2;
            addVal = 4 * (n - 2 * i + 3); 
            startVal = startVal + addVal;
            nums = fill(width, startPos, startVal, nums);//填充
        }
    }
    else {
        //偶数n
        fillTimes = n / 2;
        for(i = 2; i <= fillTimes; i++) {
            //i是当前填充的次数，由于中心不用单独填充，所以实际填充 除最外层
            startPos = i - 1;//开始索引
            width = width - 2;
            addVal = 4 * (n - 2 * i + 3); 
            startVal = startVal + addVal;
            nums = fill(width, startPos, startVal, nums);//填充
        }
    }
    return nums;

};
*/
// @lc code=end

