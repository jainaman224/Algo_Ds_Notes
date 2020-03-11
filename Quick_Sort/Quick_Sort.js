// Description: Function to perform the Quick Sort algorithm on an array of numbers
// Expected Output: returns the sorted array

// Helper function used to swap values based on indices given
const swap = (arr, a, b)=>{
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Helper function to get the Pivoting Element Index
const pivotIndex=(arr, start = 0, end = arr.length - 1) => {
    let swapIndex = start;
    //considering start element is pivot for first run
    let pivot = arr[start];  
    for (let i = start + 1; i <= end; i++) {
        if (pivot > arr[i]) {
            swapIndex += 1;
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, start, swapIndex);
    return swapIndex;
}

// Function that uses recursive definition for quick sort implementation
const quickSort=(arr, left = 0, right = arr.length - 1) => {
    if (left < right) {
        //get the index for pivot element
        let pivot = pivotIndex(arr, left, right); 
        //run quickSort on all elements on left side of pivot index
        quickSort(arr, left, pivot - 1); 
        //run quickSort on all elements on right side of pivot index
        quickSort(arr, pivot + 1, right); 
    }
    return arr;
}

// I/P and O/P Examples

// Output:[-111,-10,-1,9,10,11,100]
console.log(quickSort([-1, 9, 10, -10, 11, -111, 100]));

// Output:[-11,-10,1,2,3,4,5]
console.log(quickSort([1,2,3,4,5,-10,-11])); 
