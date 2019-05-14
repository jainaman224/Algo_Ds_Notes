'''
    Modular Inverse

    The task is to find the mod inverse of a number x, under the modulo of a given prime number.

    Modular inverse of a number x under modulo m, is defined as a number a(0<a<m), where 
    (a*x)%m = 1.
    When m is a prime number, according to Fermat's Little Theorem, (a^(m-1))%m = 1.
    On multiplying with a^(m-2) on both sides, (a^(-1))%m = (a^(m-2)).

'''
import math

def modex(base, exponent, mod):
    if base == 0:                       # As, 0^x = 0, return 0;
        return 0
    if exponent == 0:
        return 1                        # As, x^0 = 1, return 1.
    if exponent % 2 == 0:
        ans = modex(base, exponent / 2, mod)    # We use the concept of (a^x)=((a^(x/2))*(a^(x/2)) when x is even, to reduce computation time effectively.
        return (ans * ans) % mod
    return ((base % mod) * (modex(base, exponent - 1, mod))) % mod # In case of Odd exponent, we just decrement it by 1, so that it becomes even.


def modInverse(base, mod):
    if math.gcd(base, mod) != 1: # When gcd of the number and mod is not 1, The modular inverse doesn't exist.
        return -1
    return modex(base, mod - 2, mod)   # modular inverse of base under mod = base^(mod-2)%mod.

base = int(input())
mod = int(input())
ans = modInverse(base, mod)
if ans == -1:
    print("Modular Inverse of " + str(base) + " under " + str(mod) + " does not exist")
else:
    print("Modular Inverse of " + str(base) + " under " + str(mod) + " is " + str(ans))

'''
Input :  base = 10, mod = 7.
Output: Modular Inverse of 10 under 7 is 5
Verification : (modinverse * base)%mod = 1.
               (5*10)%7 = 50%7 = 1.

'''
