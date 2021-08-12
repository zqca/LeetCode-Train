function solve(num){
    //从2开始寻找x，如果可以整除，除尽，可以保证寻找的数x都是素数（否则说明前面没有除尽）
    let ans = [];
    let half = Math.floor(Math.sqrt(num))
    for(let i = 2; i <= half; ++i){
        if(num % i === 0){
            //如果可以整除，除尽
            while(num % i === 0){
                ans.push(i);
                num = num / i;
            }
        }
    }
    if(num > 2){
        ans.push(num);
    }

    console.log(ans.join(' ') + ' ');
}

//debug
let input = 2000000014;
solve(input);
