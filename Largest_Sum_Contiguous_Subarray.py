# Python program for Kadane's Algorithm  

# Function to find the maximum contiguous subarray 
def maxSubArraySum(array,size): 
 
    maximum =array[0] 
    max_pres = array[0] 
      
    for i in range(1,size): 
        max_pres = max(array[i], max_pres + array[i]) 
        maximum = max(maximum,max_pres) 
          
    return maximum
    
# Driver function 
array = list()
num = input("Enter how many elements you want:")
print ('Enter array elements: ')
for i in range(int(num)):
    n = input()
    array.append(int(n))
print ('Array: ',array)
print ("Maximum contiguous sum is", maxSubArraySum(array,len(array)) )