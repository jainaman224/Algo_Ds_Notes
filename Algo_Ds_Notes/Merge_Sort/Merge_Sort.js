
function Merge(array,left,right,middle){
    /*dividing in to array of n1,n2 length */
    n1 = middle - left +1;
    n2 = right - middle;
   var  L = [];
   var R = [];
   /*loops for filling sub arrays*/
    for(var i =0;i<n1;i++){
        L[i] = array[left + i ];
    }
    for(var j=0;j<n2;j++){
        R[j]=array[middle+j+1];
    }
    
    i = 0;    
    j = 0 ;   
    var k = left;
    /*loop for Merging values from 2 sub arrays to one*/
	        while (i < n1 && j < n2)
	        {
	            if (L[i] <= R[j])
	            {
	                array[k] = L[i];
	                i++;
	            }
	            else
	            {
	                array[k] = R[j];
	                j++;
	            }
	            k++;
	        }
	/*loops for adding remaing values*/ 
	        while (i < n1)
	        {
	            array[k] = L[i];
	            i++;
	            k++;
	        }
	 
    	   while (j < n2)
	        {
	            array[k] = R[j];
	            j++;
	            k++;
	        }
	    }
 function MergeSort(array,left,right){
     if(left < right){
         /*finding middle of sub array*/
        var middle = Math.floor((left +right)/2);
        /*division in 2 sub arrays*/ 
        MergeSort(array,left,middle);
        MergeSort(array,middle+1,right);
        Merge(array,left,right,middle);

    }
}
/* test */

a=[1,3,6,54,56,78,78,6754,643,5,4];
MergeSort(a,0,a.length-1);
console.log(a);
/*output 1,3,4,5,6,54,56,78,78,643,6754 */
