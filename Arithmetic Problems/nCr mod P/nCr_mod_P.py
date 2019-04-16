'''
    nCr % p.

    The task is to find the binomial coefficient nCr under modulo p. The normal approach would
    be to first find nCr and then do modulo p, which is highly efficient for large numbers,
    and may cause overflow.
    Thus, we use dynamic programming approach to solve this problem.

'''

def nCr(n,r,mod):
    if n<r:
        return -1
    # We create a pascal triangle.
    Pascal = []
    Pascal.append(1)
    for i in range(0,r):
        Pascal.append(0)
    # We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
    for i in range(0,n+1):
        k = ((i) if (i<r) else (r)) # We know, nCr = nC(n-r). Thus, at any point we only need min
        for j in range(k,0,-1):     # of the two, so as to improve our computation time.
            Pascal[j] = (Pascal[j]+Pascal[j-1])%mod;
    return Pascal[r]

n = 7
r = 5
mod = 6
ans = nCr(n,r,mod)
if ans == -1:
    print("Bad Input. N can never be less than R.")
else:
    print("The value of nCr("+str(n)+","+str(r)+")%"+str(mod)+" is "+str(ans))


'''
Input :  n = 7, r = 5, mod = 6.
Output: The value of nCr(7,5)%6 is 3
Verification : nCr(7,5) = 7!/((5!)(2!)) = 21
                21%6 = 3.

'''
