
# Python program to illustrate Ackermann function 
  
def A(m, n, s ="% s"): 
    print(s % ("A(% d, % d)" % (m, n))) 
    if m == 0: 
        return n + 1
    if n == 0: 
        return A(m - 1, 1, s) 
    n2 = A(m, n - 1, s % ("A(% d, %% s)" % (m - 1))) 
    return A(m - 1, n2, s) 
  
print(A(1, 2)) 
  

