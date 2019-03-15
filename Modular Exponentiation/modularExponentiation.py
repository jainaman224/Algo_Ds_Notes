# Modular Exponentiation Problem

def Modex(x,y,p):
    if x == 0:
        return 0
    if y == 0:
        return 1
    if y%2 == 0:
        ans = Modex(x,y/2,p)
        return (ans*ans)%p
    return ((x%p)*(Modex(x,y-1,p)))%p


x = 12
y = 7
p = 17
print("(",x,"^",y,")%",p,"=",Modex(x,y,p))
