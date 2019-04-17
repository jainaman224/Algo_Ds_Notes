/*
PREFIX SUM

The task is to find the prefix sum of every element of a given array.
Prefix sum equals to the sum of all element from start to the current element of the array.

*/

function prefixSum(array) {
    const prefix_array = [];
    let sum = 0;
    /*
    We maintain a prefix array where prefix_array[i] = prefix_array[i - 1] + array[i].
    As, prefix sum of element i = prefix sum of element i - 1 + element i.
    */
    for (const i in array) {
        sum = sum + array[i];
        prefix_array.push(sum);
    }
    return prefix_array;
}

const array = [3, 2, 4, 6, 7];
const prefix_array = prefixSum(array);
console.log(prefix_array);
/*
Input: array = { 3, 2, 4, 6, 7}
Output: The prefix sum array is:
3 5 9 15 22
*/
