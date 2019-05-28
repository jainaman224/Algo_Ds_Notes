# Function to find bitwise AND  
def AND(array, num): 
    ans = array[0] 
    for i in range(num): 
        ans &= array[i] 		
    print(ans)

# Driver Code 
num = int(input())
array = []
for i in range(num):
    x = int(input())
    array.append(x)  
AND(array, num) 

'''
Input: 
num = 3
array[] = {4, 5, 6}
Output:
4
Because 4 = 100, 5 = 101, 6 = 110 in binary .
AND of 4 and 5 is 100(4) in binary and
AND of 4(resultant of 4 and 5) and 6 is 100(4).
so, answer is 4.
'''

