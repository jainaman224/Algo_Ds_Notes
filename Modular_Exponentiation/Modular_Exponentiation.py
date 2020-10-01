# Modular Exponentiation Problem

def Modex(base,exponent,mod):
    if base == 0:                       # 0^x = 0
        return 0
    if exponent == 0:
        return 1                        # x^0 = 1
    if exponent%2 == 0:
        ans = Modex(base,exponent/2,mod)    # a^b = (a^(b/2)*(a^(b/2)). This effectively reduces the no. of computations required.
        return (ans*ans)%mod
    return ((base%mod)*(Modex(base,exponent-1,mod)))%mod    # when exponent is odd, we reduce it by 1 to make it even and go in recursion.


base = 12
exponent = 7
mod = 17
print("(",base,"^",exponent,")%",mod,"=",Modex(base,exponent,mod))
