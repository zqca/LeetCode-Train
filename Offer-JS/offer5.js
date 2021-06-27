var replaceSpace = function(s) {
    let arr = s.split("");
    let oldLen = arr.length;
    let spaceCount = 0;
    for (let i = 0; i < oldLen; i++) {
        if (arr[i] === ' ') spaceCount++;
    }
    arr.length += spaceCount * 2;

    for (let i = oldLen - 1, j = arr.length - 1; i >= 0; i--, j--) {
        if (arr[i] !== ' ') arr[j] = arr[i];
        else {
            arr[j - 2] = '%';
            arr[j - 1] = '2';
            arr[j] = '0';
            j -= 2;
        }
    }
    return arr.join('');
};

let ans = replaceSpace('ha s');
console.log(ans);

