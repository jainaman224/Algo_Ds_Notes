def fib(n):  
      
    # Taking 1st two fibonacci nubers as 0 and 1  
    Fib = [0, 1]  
    while len(Fib) < n + 1:  
        Fib.append(0)  
    if n <= 1:  
        return n  
    else:  
        if Fib[n - 1] == 0:  
            Fib[n - 1] = fib(n - 1)  
  
        if Fib[n - 2] == 0:  
            Fib[n - 2] = fib(n - 2)  
              
    Fib[n] = Fib[n - 2] + Fib[n - 1]  
    return Fib[n]  
      
p=int(input("Enter the nth number of sequence: "))
print("\\")
print("The nth number is: ", fib(p))  


'''
TestCase-1: 
Sample Input: 6
Sample Output: 8
TestCase-2:
Sample Input: 10
Sample Output: 55
'''
