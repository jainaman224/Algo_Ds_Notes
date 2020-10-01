# Function to print nth fibonacci number  
def FibonacciNumber (num): 
    if (num <= 1): 
        return num
    else: 
        return FibonacciNumber(num - 1) + FibonacciNumber(num - 2)

# Function to print fibonacci series          
def FibonacciSeries(num): 
    a = 0
    b = 1
    if (num < 1): 
        return
        
    for i in range(0, num): 
        print(b , end = " ") 
        c = a + b;  
        a = b;  
        b = c;

# Driver Program 
num = int(input())
print("The fibonacci number at position ", num, "is ", FibonacciNumber(num))
print("Fibonacci series:")
FibonacciSeries(num)

'''
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
'''
