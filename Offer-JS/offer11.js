/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    //二分，原数组是非减的
    let left = 0;
    let right = numbers.length - 1;
    let mid;
    while(left < right){
        mid = Math.floor(left + (right - left) / 2);
        if(numbers[mid] > numbers[right]){
            //说明最低点在mid右侧
            left= mid + 1;
        }
        else if(numbers[mid] < numbers[right]){
            //说明最低点在mid左侧
            right = mid;
        }
        else{
            --right;//缩减范围
        }
    }
    return numbers[left];
};