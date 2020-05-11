var n = prompt("enter the size of an array required");
var arr = new Array();
//taking input for array
for (let i = 0; i < n; i++) {
    arr[i] = prompt("element" + (i + 1) + ":");
    arr[i] = parseInt(arr[i]);
}
var count = 0;
for (let i = 0; i < n - 1; i++) {
    let max = arr[0];
    let m = 0,
        t = m;
    //finding maximum element from unsorted array
    for (let j = 1; j < n - count; j++) {
        if (arr[j] > max) {
            max = arr[j];
            t = j;
        }
    }
    if (t != m) {
        let newarr;
        //reversing the array until the maximum element position
        newarr = arr.slice(0, t + 1).reverse();
        for (let i = 0; i < t + 1; i++) {
            arr[i] = newarr[i];
        }
    }
    let neww;
    //reversing the whole unsorted array
    neww = arr.slice(0, n - count).reverse();
    for (let i = 0; i < n - count; i++) {
        arr[i] = neww[i];
    }
    count++;
}
console.log("the sorted array is " + arr);

/* sample input-output
enter the size of an array required: 5
element 1:56
element 2:23
element 3:78
element 4:18
element 5:9
the sorted array is 9,18,23,56,78 */
