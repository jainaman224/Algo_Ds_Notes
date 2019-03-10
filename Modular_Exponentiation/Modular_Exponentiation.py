def exponentMod(A, B, C):
	if (A == 0):
		return 0
	if (B == 0):
		return 1

	y = 0
	if (B % 2 == 0):
		y = exponentMod(A, B / 2, C)
		y = (y * y) % C

	else: 
		y = A % C
		y = (y * exponentMod(A, B - 1,
							C) % C) % C
	return ((y + C) % C)

# Driver Code
A = 2
B = 5
C = 13
print("Power is", exponentMod(A, B, C))
