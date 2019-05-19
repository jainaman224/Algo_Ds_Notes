'''
        GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two 
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
'''

def sumOfGP(a, r, n) : 
    sum = 0
    i = 0
    while i < n : 
        sum = sum + a 
        a = a * r 
        i = i + 1
    return sum

print("Enter the First Term of G.P.")
a = int(input())
print("Enter the common ratio")
r = int(input())
print("Enter N (The index of term to find)")
n = int(input())
print("The term at index" , n , "is" , (a * pow(r, n - 1)))
print("Sum is: ", sumOfGP(a, r, n))

'''
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
             Sum is: 635
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
'''
