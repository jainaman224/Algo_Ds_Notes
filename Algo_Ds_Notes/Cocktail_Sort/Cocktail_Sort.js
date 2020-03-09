function Cocktail_Sort(Array) 
{

    // the starting index of the array is s and ending index is l
    var s = 0;
    var l = Array.length;

    // a flag to check if in an iteration, any swaps were made
    // i.e. if the array was not already sorted
    var flag = true; 

	while(flag) {

        // resetting the flag
        flag = false;

        // iterate through every element from left to right 
		for(var i = s; i < l - 1; i++) {

            // Move the bigger element to the right most position as in bubble sort
			if(Array[i] > Array[i+1]) {

				var t = Array[i];
				Array[i] = Array[i+1];
                Array[i+1] = t;
                
                // setting flag to true if even one element changed its order 
				flag = true;
			}
        }
        
        // if nothing moved, then array is sorted.
		if(!flag) {
			break;
        }
        
        flag = false; 
        l = l - 1;
        
        // moving the smaller elements to left part of the array which is modification over bubble sort
		for(var i = l - 1; i > s; i--) {

			if(Array[i-1] > Array[i]) {

				var t = Array[i];
				Array[i] = Array[i-1];
                Array[i-1] = t;
                
                flag = true;
                
			}
        }

    s = s + 1;
    } 
    
  return Array;
}

// input array
var arr = [10, 1, 5, 2, 4, 0, 2, 8 ];  

console.log('Sorted Array is: ' + Cocktail_Sort(arr));

/*
    OUTPUT :

    Sorted Array is: 0,1,2,2,4,5,8,10

*/
