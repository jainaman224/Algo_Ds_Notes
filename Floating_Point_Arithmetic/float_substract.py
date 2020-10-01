# to perform float substraction in range .9999e49to .1000e-50
#axis 50 notation


def add(x1,e1,x2,e2):
	if(e1>e2):
		z1 = abs(e1-e2)
		e2=e1
		x2 = x2/pow(10,z1)
	
	if(e2>e1):
			z2 = abs(e1-e2)
			e1=e2
			
			x1 = x1/pow(10,z2)
			
	k = max(x1,x2)-min(x1,x2)
	return  k,e1
	
def normalize(mantisaa,exponent):

	if(not(0<mantisaa and mantisaa<1)):
		i = 0
		while(not(0<mantisaa and mantisaa<1)):
			mantisaa = mantisaa/10
			i = i+1
				
		exponent = exponent+i
	return mantisaa,exponent
print("enter numbers to substract")
print("enter mantisaa and exponent of first number")
x1 = float(input())
e1 = int(input())
print("enter mantisaa and exponent of second number")
x2 = float(input())
e2 = int(input())

if (x1 or x2)<0:
	print("enter only positive number")
else:
	mantisaa , exponent = add(x1,e1,x2,e2)
	mantisaa_normalize , exponent_modified = normalize(mantisaa , exponent)

	exponent_modified = exponent_modified + 50

		
	if exponent_modified>=100:
		print("overflow error")
	else:
		if exponent_modified<0:
			print("underflow error")
		else:
		    print("result  = " ,mantisaa_normalize,"e",exponent_modified-50)
