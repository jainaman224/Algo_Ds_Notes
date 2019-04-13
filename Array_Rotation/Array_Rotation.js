//Program to rotate array Arr[] of size n by d Elements
function Array_Rotation(arr, r, n) {
    var temp1 = [];
    var temp2 = [];
    temp1 = arr.slice(r, n);
    //console.log(temp1);
    temp2 = arr.slice(0, r);
    //console.log(temp2);
    var result = []
    return (result.concat(temp1, temp2));
}

var arr = [1, 2, 3, 4, 5, 6, 7];
var r = 2
console.log(arr);
console.log(Array_Rotation(arr, r, arr.length));

/*
Input array: {1, 2, 3, 4, 5, 6, 7 }
Expected Output
3 4 5 6 7 1 2 
*/