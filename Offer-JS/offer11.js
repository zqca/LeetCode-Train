var minArray = function(numbers) {
    //二分，原数组是非减的,右边的一定不是最小值
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
            --right;//缩减范围，这个时候可以缩小right,缩小right不会丢失最小值
        }
    }
    return numbers[left];
};