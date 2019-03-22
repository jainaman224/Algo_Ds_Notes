#python3
#program to calculate roots of a polynomial with error of .0001 

def f(x):
	return x*x - x - 1
	
print("Enter values of a and b on separate line ")
a = float(input())
b = float(input())
e = .0001

if f(a)*f(b)>0:
	print("Invalid internal, Root does not exist in it")
else:
		m = (a+b)/2
		i=1
		print (a,b,m,f(m),f(a)*f(m),i)
		while abs(f(m))>e :
			
			if f(a)*f(m)>0:
				a = m
			else:
				b = m
			m = (a+b)/2
			i= i+1
			print (a,b,m,f(m),f(a)*f(m),i)
		print ("Root of polynomial :",m)
