
#Putting it all in try except

try:
	num = int(input("Enter the number of integers you want in the list "))
	list = [] 
	#taking the number of elements wanted in the list
	


	for i in range(0, num):
		print("Enter value of element ",i+1)
		list.append(int(input()))

	#taking the elements

	

	Ele=int(input("Enter the element you whose position you want to find "))

	#Searching the element

	if Ele not in list:
		print("The element ",Ele," is not in the list ")
	else:
		desired = list.index(Ele)
		print("The position of ",Ele, "is ",i+1)

except ValueError:
	print("Enter integer only ")


"""
Output

Enter the number of integers you want in the list 3
Enter value of element  1
1
Enter value of element  2
2
Enter value of element  3
3
Enter the element you whose position you want to find 4
The element  4  is not in the list
"""