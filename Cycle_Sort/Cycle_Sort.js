// Cycle Sort Algorithm implementation

const cycleSort = (arr, n) => {
    // To count number of memory writes
    let writes = 0;

    // consider each index as the start of a cycle
    for (let cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        // initialize item as starting point
        let item = arr[cycle_start];

        // Correct position: All smaller elements on right side of item
        // + current_index
        let pos = cycle_start;
        for (let i = cycle_start + 1; i < n; i++)
            if (arr[i] < item) pos++;

            // If item is already in correct position
        if (pos == cycle_start) continue;

        // ignore all duplicates
        while (item == arr[pos]) pos += 1;

        // put the item to its correct position
        if (pos != cycle_start) {
            //swap
            let x = item;
            item = arr[pos];
            arr[pos] = x;
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find position where we put the element
            for (let i = cycle_start + 1; i < n; i++)
                if (arr[i] < item) pos += 1;

                // ignore all duplicate  elements
            while (item == arr[pos]) pos += 1;

            // put the item to it's right position
            if (item != arr[pos]) {
                //swap
                let x = item;
                item = arr[pos];
                arr[pos] = x;
                writes++;
            }
        }
    }
};

let arr = [1, 2, 8, 9, 7, 5, 5, 4, 6];
let n = arr.length;
console.log("Unsorted Array: ", arr);

cycleSort(arr, n);
console.log("Sorted Array: ", arr);

// Output:
// Unsorted Array: [1, 2, 8, 9, 7, 5, 5, 4, 6]
// Sorted Array: [1, 2, 4, 5, 5, 6, 7, 8, 9]
