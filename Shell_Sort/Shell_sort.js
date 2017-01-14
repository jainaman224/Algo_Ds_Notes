//shellSortfunction
function shellSort(array) {
var gap;
//gap is taken of size half of array length
/*loop for reducing  gap size one bye one to with minimum value of 1*/
for (gap =Math.floor(array.length/2); gap >0; gap=Math.floor(gap/2)) {
/*loops for changing the swaping values with gap size*/
for (var i = gap; i < array.length; i++) {
  /*checks if elements needed to be swapped*/
  
/*swaps the digits using temproray variable*/
  temp = array[i];
                  /*loop for swaping number with gap length in between */
                  for (j = i; j >= gap && array[j - gap] > temp; j = j - gap)
                      array[j] = array[j - gap];

                  array[j] = temp;
  
}
}
/*prints the sorted  array*/
console.log('the sorted array is '+array);
}
/* psuedo data for array */
var arr=[ 2, 10, 8, 1, 4, 1];
/*calls to  shell sort function*/
shellSort(arr);
  /*1 1 2 4 8 10*/
