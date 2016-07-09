
// Function for Interpolation search
function Interpolation_Search(array , search_item)
{
  var low = 0;
  var high = array.length-1;
  var pos;

  while(low <= high && search_item >= array[low] && search_item <= array[high])
  {
    var rise = high - low;
    var run = array[high] - array[low];
    var x = search_item - array[low];

    pos = low + Math.floor(rise / run) * x;

    if(array[pos] === search_item)
    return pos;

    else if(search_item < array[pos])
    high = pos - 1;

    else if(search_item > array[pos])
    low = pos + 1;
  }

  return -1;
}

var array = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ];


var search_item = 5;

var index = Interpolation_Search(array, search_item);

if(index !== -1)
console.log("found at index " + index);
else
console.log("Not found");



/* Output

Found at index 4

*/
