def decToHexa(num):     
    hexa = ['0'] * 100 
     
    i = 0 
    while(num != 0): 
        temp = 0
         
        temp = num % 16 
          
        # Checking if temp < 10; if it then it is a letter
        if(temp < 10): 
            hexa[i] = chr(temp + 48) 
            i = i + 1
        else: 
            hexa[i] = chr(temp + 55) 
            i = i + 1
        num = int(num / 16)
     
    j = i - 1 
    while(j >= 0): 
        print((hexa[j]), end = "")
        j = j - 1
  
# Driver Code 
num = int(input())
decToHexa(num)

'''Input:
1234
Output:
4D2
'''
