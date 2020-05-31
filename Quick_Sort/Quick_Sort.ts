// Description: Function to perform the Quick Sort algorithm on an array of numbers
// Expected Output: returns the sorted array

// Helper function to get the Pivoting Element Index
function partition(array: number[], left: number = 0, right: number = array.length - 1) 
{
    const pivot = array[Math.floor((right + left) / 2)];
    let i = left;
    let j = right;

    while (i <= j) 
    {
        while (array[i] < pivot) 
        {
            i++;
        }

        while (array[j] > pivot)
        {
            j--;
        }

        // Swap values based on indices
        if (i <= j) 
        {
            [array[i], array[j]] = [array[j], array[i]];
            i++;
            j--;
        }
    }

    return i;
}


// Function that uses recursive definition for quick sort implementation
function quickSort(array: number[], left: number = 0, right: number = array.length - 1) 
{
    let index;

    if (array.length > 1)
    {
        index = partition(array, left, right);

        if (left < index - 1) 
        {
            quickSort(array, left, index - 1);
        }

        if (index < right) 
        {
            quickSort(array, index, right);
        }
    }

    return array;
}

// I/P
var arr = [6, 5, 4, 3, 2, 1];

console.log("Before sorting ",arr)
var res = quickSort(arr)

console.log("After sorting ",res) 
// O/P
// 1,2,3,4,5,6
