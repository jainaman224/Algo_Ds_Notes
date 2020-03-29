//Sorting an array using circle sort
/*
In short, compare the first element to the last element, then the second element to the second last element, etc.

Then split the array in two and recurse until there is only one single element in the array, like this:

Before:
6 7 8 9 2 5 3 4 1
After:
1 4 3 5 2 9 8 7 6
*/
const circlesort = (arr, lo, hi, swaps) => {
    let high;
    let low;
    let mid;
    let temp;
    if(lo === hi){
        return swaps;
    }

    high = hi;
    low = lo;
    mid = Math.floor((hi - lo) / 2);

    while(lo < hi){
        if(arr[lo] > arr[hi]){
            temp = arr[lo];
            arr[lo] = arr[hi];
            arr[hi] = temp;
            swaps++;
        }
        lo++;
        hi--;
    }
    if(lo === hi){
        if(arr[lo] > arr[hi + 1]){
            temp = arr[lo];
            arr[lo] = arr[hi + 1];
            arr[hi + 1] = temp;
            swaps++;
        }
    }

    swaps = circlesort(arr, low, low + mid, swaps);
    swaps = circlesort(arr, low + mid +1, high, swaps);
    return swaps;

};

const x = [12, 8, 6, 15, 7, 4, 14, 17, 2];
console.log("Input Array : ");
console.log(x);

console.log("After Circle Sort : ");
while(circlesort(x, 0, x.length - 1, 0)){
    console.log(x);
}

/*Sample Input-Output
Input Array : 
[ 12, 8, 6, 15, 7, 4, 14, 17, 2 ]
After Circle Sort : 
[ 2, 4, 6, 7, 8, 12, 14, 15, 17 ]
*/

