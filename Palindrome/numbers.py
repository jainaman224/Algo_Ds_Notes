def pal(x):
    r=0
    while(x!=0):
        r = r*10 + x%10
        x = int(x/10)
    return r
a = int(input("Enter the number you want to check : "))
b = pal(a)
if b == a:
    print("It's a palindrome number.")
else:
    print("Not a palindrome number.")


""" Output

Enter the number you want to check : 1456541
It's a palindrome number.

Enter the number you want to check : 1234567
Not a palindrome number.

"""