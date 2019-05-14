def nCrModpDP(n, r, p):
    C = [0] * (r + 1)
    C[0] = 1
    for i in range(1, n + 1):
        for j in range(min(i, r), 0, -1):
            C[j] = (C[j] + C[j - 1])%p

    return C[r]

def nCrModpLucas(n, r, p):
    n, r = int(n), int(r)
    if r == 0:
        return 1

    ni = n % p
    ri = r % p
    return (nCrModpLucas(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p

def main():
    n = int(input())
    r = int(input())
    p = int(input())
    print("Value of nCr % p is ", nCrModpLucas(n, r, p))

if __name__ == '__main__':
    main()

'''     
	INPUT - OUTPUT
     sample input
	     n = 1000
	     r = 900
	     p = 13
     output
     	value of nCr % p is 8 
'''
