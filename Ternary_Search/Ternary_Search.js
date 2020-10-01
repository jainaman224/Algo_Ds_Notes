// Function for Ternary Search
Ternary_Search = function(array, left, right, desired){
  if(right >= left){

       mid1 = left + (right - left) / 3;
       mid2 = mid1 + (right - left) / 3;

       // If x is present at the mid1
       if(array[mid1] == desired)
           return mid1;

       // If x is present at the mid2
       if(array[mid2] == desired)
           return mid2;

       // If x is present in left one-third
       if(array[mid1] > desired)
           return Ternary_Search(array, left, mid1 - 1, desired);

       // If x is present in right one-third
       if(array[mid2] < desired)
           return Ternary_Search(array, mid2 + 1, right, desired);

       // If x is present in middle one-third
       return Ternary_Search(array, mid1 + 1, mid2 - 1, desired);
  }

  // We reach here when element is not present in array
  return -1;
}

array = [1, 2, 3, 4, 5, 6, 7];

// Element 4 to be searched
if(Ternary_Search(array, 0, 6, 4) != -1)
    console.log('Found');
else
    console.log('Not Found');

//Element 9 to be searched
if(Ternary_Search(array, 0, 6, 9) != -1)
  console.log('Found');
else
  console.log('Not Found');
