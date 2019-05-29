# Function to find bitwise OR
def OR(array, num): 
    ans = array[0] 
    for i in range(num): 
        ans |= array[i] 		
    print(ans)

# Driver Code 
num = int(input())
array = []
for i in range(num):
    x = int(input())
    array.append(x)  
OR(array, num)

'''
Input: 
num = 3
array[] = {4, 5, 6}
Output:
7
Because 4 = 100, 5 = 101, 6 = 110 in binary .
OR of 4 and 5 is 101(5) in binary and
OR of 5(resultant of 4 and 5) and 6 is 111(7).
so, answer is 7.
'''
