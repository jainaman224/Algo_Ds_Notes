                                # Kadane’s Algorithm

Kadane  Algorithm is used to find the sum of contiguous subarray  within a one-dimensional array of numbers which has the largest sum.
                         
 # Example  
![download](https://user-images.githubusercontent.com/49182690/80751350-3d8fe200-8b47-11ea-83bc-c16bca71d21d.png)
 
       
 # Pseudo code
 
_Initialise_:

	current_sum=0
	best_sum=0
  
  loop for each element of the array
  
    1.current_sum=current_sum + a[i]
    
    2.if(best_sum < current_sum)
            best_sum= current_sum
            
    3.if(current_sum < 0)
            current_sum=0
            
    4.return best_sum

# Explanation
			
Lets take the example:
    {-2, -3, 4, -1, -2, 1, 5, -3}

    best_sum = current_sum = 0

    for i=0,  a[0] =  -2
    current_sum = current_sum + (-2)
    Set current_sum = 0 because current_sum < 0

    for i=1,  a[1] =  -3
    current_sum = current_sum + (-3)
    Set current_sum = 0 because current_sum < 0

    for i=2,  a[2] =  4
    current_sum = current_sum + (4)
    current_sum = 4
    best_sum is updated to 4 because current_sum greater 
    than best_sum which was 0 till now

    for i=3,  a[3] =  -1
    current_sum = current_sum + (-1)
    current_sum = 3

    for i=4,  a[4] =  -2
    current_sum = current_sum + (-2)
    current_sum = 1

    for i=5,  a[5] =  1
    current_sum = current_sum + (1)
    current_sum = 2

    for i=6,  a[6] =  5
    current_sum = current_sum + (5)
    current_sum = 7
    best_sum is updated to 7 because current_sum is 
    greater than best_sum

    for i=7,  a[7] =  -3
    current_sum = current_sum + (-3)
    current_sum = 4
               
# Time Complexity

Kadane’s  algorithm is able to find the maximum sum of a contiguous  subarray  in an array with a runtime of O(n).

