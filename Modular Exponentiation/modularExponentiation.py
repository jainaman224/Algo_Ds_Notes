# Modular Exponentiation Problem

def Modex(base,exponent,mod):
    if base == 0:
        return 0
    if exponent == 0:
        return 1
    if exponent%2 == 0:
        ans = Modex(base,exponent/2,mod)
        return (ans*ans)%mod
    return ((base%mod)*(Modex(base,exponent-1,mod)))%mod


base = 12
exponent = 7
mod = 17
print("(",base,"^",exponent,")%",mod,"=",Modex(base,exponent,mod))
