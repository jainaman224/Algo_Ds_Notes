def pal(a):
    return a[::-1]
    return b
x = input("Enter string : ")
y = pal(x)
if y == x:
    print("It's a palindrome.")
else:
    print("Not a palindrome.")


"""Output

Enter string : is this a palindrome
Not a palindrome.

Enter string : malayalam
It's a palindrome.


"""