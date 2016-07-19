
// Function For Counting Sort  
function Counting_Sort (a, largest  , arrsize) 
{

            var size = largest +1,
                val;
            var b = Array(size).fill(0);
            for(var i=0 ; i<arrsize;i++)
            {
                 val = a[i];
                b[val] +=1;
            }
            var l = 0, r=0;
            var c =  Array(arrsize).fill(0);

            for (var j = 0; l < size; j++)
            {


                while (b[l] !== 0)
                {
                    c[r] = l;
                    r++;
                    b[l]--;

                }
                l++;
            }
            
            for (var k = 0; k < arrsize; k++)
                
                {
                console.log(c[k]);
                }
}
var a = [1, 7, 3, 4, 2, 6, 8, 5, 9, 11];            //array to be sorted 
//calling sort function 
Counting_Sort(a, 11,10);