
// Function for binary search
function Binary_Search(array , search_item)
{
  var left = 0, right = array.length-1, middle;

  while(left<=right)
  {
    middle = ((left + right) >> 1);

    if(array[middle] == search_item)
    return middle;

    else if(search_item < array[middle])
    right = middle - 1;

    else if(search_item > array[middle])
    left = middle + 1;
  }
  return -1;
}

var array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

var desired = 4;

var index = Binary_Search(array, search_item);

if(index !== -1)
console.log("found at index " + index);
else
console.log("Not found");



/* Output

Found at index 3

*/
