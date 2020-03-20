/*
 Bucket sort is a comparison sort algorithm that operates on elements by dividing 
 them into different buckets and then sorting these buckets individually.
*/

const insertionSort = arr => {
    let i, j;
    for (i = 1; i < arr.length; i++) {
        let currentVal = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (currentVal > arr[j]) {
                break;
            }
            else {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = currentVal;
    }
    return arr;
}

const bucketSort = arr => {

    if (arr.length === 0) {
        return arr;
    }

    // finding minimum and maximum value and setting bucket size
    let minValue = Math.min(...arr);
    let maxValue = Math.max(...arr);
    let bucketSize = 10;

    let bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;

    let buckets = Array.from({ length: bucketCount }, () => []);

    // Pushing values to buckets
    for (let i = 0; i < arr.length; i++) {
        let index = Math.floor((arr[i] - minValue) / bucketSize);
        buckets[index].push(arr[i]);
    }

    // reset the input array to store sorted result
    arr.length = 0;

    // sort individual buckets and put the elements onto the array
    buckets.forEach(function (bucket) {
        insertionSort(bucket);
        bucket.forEach(function (value) {
            arr.push(value)
        });
    });

    return arr;
}

// I/P and O/P examples

// [ -11, -10, -1, 2, 4 ]
console.log(bucketSort([-1, 2, 4, -10, -11]));

// [ -11, -10, 4, 100, 200 ]
console.log(bucketSort([100, 200, 4, -10, -11]));