# This function is for when -> 
# 1. The input number is not palindrome. 
# 2. number is palindrome but not all digits as nine
def helper(number, n) : 
  
    # find the mid digit of the input number
    middle = int(n/2) 
    i = middle - 1
  
    # Handling odd and even length numbers
    j = middle + 1 if (n % 2) else middle  
    while(i >= 0 and number[i] == number[j]) : 
        i = i - 1
        j = j + 1
  
    isLeftSmaller = False
    if(i < 0 or number[i] < number[j]):  
        isLeftSmaller = True
    
    # copy same left to right 
    while (i >= 0) :       
        number[j] = number[i]  
        j+=1
        i-=1
    
    if (isLeftSmaller == True) :      
        cflag = 1
        i = middle - 1

        if (n % 2 == 1) :      
            number[middle] += cflag  
            cflag = int(number[middle] / 10 ) 
            number[middle] %= 10
            j = middle + 1         
        else: 
            j = middle  

        # copy same left to right    
        while (i >= 0) :           
            number[i] += cflag  
            cflag = number[i] / 10
            number[i] %= 10
            number[j] = number[i]
            j+=1
            i-=1
          
def next_smallest_palindrome(num, n) : 
  
    # if All the digits are 9, o/p 1 followed by n-1 0's followed by 1. 
    b = 1
    for i in range(1, n): 
        if( num[i] != 9 ) : 
            b = 0

    if (b == 1):  
        print("1")  
        for i in range(0, n - 1):  
            print("0")  
        print("1")  
      
  
    # Handling other input cases
    else: 
      
        helper (num, n)  
  
        # print the result  
        for i in range(0, n):  
            print(int(arr[i]), end=" ")  

    print()   

# Sample input
num = [9, 4, 1, 8, 7, 9, 7] 
n = len(num) 
next_smallest_palindrome(num, n)  

# Sample Output
# 9 4 1 9 1 4 9 
