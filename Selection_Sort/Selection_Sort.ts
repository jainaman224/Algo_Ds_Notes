// function for selection sort logic
function Selection_Sort(numbers: number[]) : number[]{

    let i: number;
    let j: number;
    let min: number;
    let temp: number;

    // outer loop to traverse through each element
    for(i = 0; i < numbers.length - 1; i++){
        min = i;

        // inner loop finds the minimum element and puts it in the beginning.
        for(j = i + 1; j < numbers.length; j++){
            if(numbers[j] < numbers[min]){
                min = j;
            }
        } // inner loop ends

        if(i !== min){
            temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
    } // outer loop ends

    return numbers;
}

const numbers: number[] = [10, 9, 8, 1, 5, 2, 4, 7, 3];

console.log(Selection_Sort(numbers));

// INPUT [10, 9, 8, 1, 5, 2, 4, 7, 3]
// OUTPUT [ 1, 2, 3, 4, 5, 7, 8, 9, 10 ]
