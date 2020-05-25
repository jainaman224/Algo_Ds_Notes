export function mergeSort(array: number[]): number[] {
    if (array.length <= 1) {
        return array;
    }
    const middle = Math.floor(array.length / 2);
    const left = array.slice(0, middle);
    const right = array.slice(middle);
    return merge(mergeSort(left), mergeSort(right));
}

function merge(left: number[], right: number[]): number[] {
    const array: number[] = [];
    let lIndex = 0;
    let rIndex = 0;
    while (lIndex + rIndex < left.length + right.length) {
        const lItem = left[lIndex];
        const rItem = right[rIndex];
        if (lItem == null) {
            array.push(rItem); 
            rIndex++;
        }
        else if (rItem == null) {
            array.push(lItem); 
            lIndex++;
        }
        else if (lItem < rItem) {
            array.push(lItem); 
            lIndex++;
        }
        else {
            array.push(rItem); 
            rIndex++;
        }
    }
    return array;
}
console.log(mergeSort([8, 7, 4, 30, 21, 12]));


/*

    Input : [8, 7, 4, 30, 21, 12]
    Output : [ 4, 7, 8, 12, 21, 30 ]
	
*/

