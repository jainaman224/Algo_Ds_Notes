//Program to rotate array Arr[] of size n by d Elements
function Array_Rotation(arr, d, n) {
    var right_sub_array = [];
    var left_sub_array = [];
    right_sub_array = arr.slice(d, n);
    left_sub_array = arr.slice(0, d);
    var result = []
    return (result.concat(right_sub_array, left_sub_array));
}

var arr = [1, 2, 3, 4, 5, 6, 7];
var d = 2
console.log(arr);
console.log(Array_Rotation(arr, d, arr.length));

/*
Input array: {1, 2, 3, 4, 5, 6, 7 }
Expected Output
3 4 5 6 7 1 2 
*/
