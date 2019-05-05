# to perform float division in range .9999e49to .1000e-50
#axis 50 notation

def normalize(mantisaa,exponent):

	if(not(0<mantisaa and mantisaa<1)):
		i = 0
		while(not(0<mantisaa and mantisaa<1)):
			mantisaa = mantisaa/10
			i = i+1
				
		exponent = exponent+i
	return mantisaa,exponent

print("enter numbers to divide")
print("enter mantisaa and exponent of first number")
x1 = float(input())
e1 = int(input())
print("enter mantisaa and exponent of second number")
x2 = float(input())
e2 = int(input())

if (x1 or x2)<0:
	print("enter only positive number")
else:
	mantisaa = x1/x2
	exponent = e1-e2
	mantisaa_normalize , exponent_modified = normalize(mantisaa,exponent)
	exponent_modified = exponent_modified + 50

		
	if exponent_modified>=100:
		print("overflow error")
	else:
		if exponent_modified<0:
			print("underflow error")
		else:
		    print("result  = " ,mantisaa_normalize,"e",exponent_modified-50)
