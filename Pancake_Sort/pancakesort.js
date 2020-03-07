const pancakeSort = arr => {
    for (let i=arr.length-1; i>=1; i--) {
        // 1. find the index of the largest size in unsorted arr
        let maxIndex = 0;
        let max = arr[0];
        for(let j=1; j<=i; j++) {
            if(arr[j] > max) {
                max = arr[j];
                maxIndex = j;
            }
        }
 
        // 2. if the element is maxIndex, continue
        if (maxIndex == i) continue;
 
        // 3. otherwise, flip the largest element to index 0
        let newSlice;
 
        if (maxIndex > 0) {
            newSlice = arr.slice(0, maxIndex+1).reverse();
            for (let j= 0; j<= maxIndex; j++) 
                arr[j] = newSlice[j];
        }
 
        // 4. then flip the largest element to the sorted index
        newSlice = arr.slice(0, i+1).reverse();
        for (let j=0; j<=i; j++) 
            arr[j] = newSlice[j];
    }
    return arr;
}