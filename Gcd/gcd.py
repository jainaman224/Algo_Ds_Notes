# Python Implementation of GCD Program using Euclidean Algorithm
def gcd(m, n):
    # Assume m >= n
    if m < n:
        (m, n)=(n, m) # in case n>m then we will swap and create m>n
    if(m % n) == 0:
        return n
    else:
        return(gcd(n, m % n))

# Main Program
if __name__ == '__main__':
    n1 = int(input("Enter Number 1 "))
    n2 = int(input("Enter Number 2 "))
    print(f"Gcd of {n1}, {n2} = {gcd(n1, n2)}")

# Output
# Enter number 1 14
# Enter number 2 63
# Gcd of 14, 63 = 7
