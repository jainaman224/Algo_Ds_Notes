def SieveOfEratosthenes(n):
    prime = [True] * (n + 1)

    i = 2
    while i**2 <= n:
        if prime[i] == True:
            for j in range(2 * i, n, i):
                prime[j] = False

        i += 1

    for i in range(2, n):
        if prime[i] == True:
            print(i, end = " ")

    print()


n = 30
print("Following are the prime numbers smaller than or equal to " + str(n))
SieveOfEratosthenes(n)


''' Output

Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29

'''
