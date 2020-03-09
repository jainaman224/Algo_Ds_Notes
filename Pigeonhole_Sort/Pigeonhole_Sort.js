//array to be sorted  
//no. of elements = 7
var arr = [ 19,9,2,3,8,12,10];

//function for pigeonsort
function pigeonsort(array)
{
  //finding maximum value of array 
  var max = Math.max.apply(null,array); //19
  
  //finding minimum value of array 
  var min = Math.min.apply(null,array); //2
  
  //finding the size of hole array to be created
  var holerange=max-min+1;
  
  //initialising hole array with value 0
  var hole = Array(holerange).fill(0);
  var i;
  //filling the hole array
  for(i=0;i<array.length;i++)
  {
    hole[array[i]-min]++;
  }
  count = 0;
  
  //finally putting the values in sorted manner
  for(var j = 0 ; j<holerange ; j++)
  {
    while(hole[j]!==0)
    {
      array[count]=j+min;
      hole[j]--;
      count++;
    }
  }
  return array;
}

console.log(pigeonsort(arr));


//output - [2,3,8,9,10,12,19]
