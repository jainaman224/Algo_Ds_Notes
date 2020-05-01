//Bubble Sort In Typescript

function bubble(array : number[]) : number[]
{
     // print original array
     console.log("Original Array : " + array);
     console.log("Steps in bubble sorting the array : ");
     
         //FOR LOOP to perform bubble sort(swapping)
         for (let i = 0; i < array.length ; i++)
         { 
              for (let j = 0; j < array.length - 1; j++ ) 
              {
                   if (array[j] > array[j + 1])
                   {
                        let swap = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = swap;
                       
                       /* prints arrray to check 
                        after every bubble sort step */
                        console.log(array); 
                   }    
              }    
         }
    
     // print bubble sorted array
     console.log(" Final Array : " + array); 
     return array;
}    
  
/* consider the array input of 
bubble sort (may choose any array) */
bubble([2, 1, 99, 8, 4, 0, 18]);

// OUTPUT
// Original Array : 2,1,99,8,4,0,18
// Steps in bubble sorting the array :
// [ 1, 2, 99, 8, 4, 0, 18 ]
// [ 1, 2, 8, 99, 4, 0, 18 ]
// [ 1, 2, 8, 4, 99, 0, 18 ]
// [ 1, 2, 8, 4, 0, 99, 18 ]
// [ 1, 2, 8, 4, 0, 18, 99 ]
// [ 1, 2, 4, 8, 0, 18, 99 ]
// [ 1, 2, 4, 0, 8, 18, 99 ]
// [ 1, 2, 0, 4, 8, 18, 99 ]
// [ 1, 0, 2, 4, 8, 18, 99 ]
// [ 0, 1, 2, 4, 8, 18, 99 ] 
// Final Array : 0,1,2,4,8,18,99
