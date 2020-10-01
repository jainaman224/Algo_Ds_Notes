def decToOctal(num):       
    octal = [0] * 100
    
    i = 0
    while (num != 0):   
        octal[i] = num % 8 
        num = int(num / 8)
        i += 1  
    
    for j in range(i - 1, -1, -1): 
        print(octal[j], end = "")
 
num = int(input())  
decToOctal(num)

'''
Input:
20
Output:
24
'''
