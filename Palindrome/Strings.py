
#function for finding reverse of the string.

def pal(a) :
    return a[::-1]
    return b

#for taking and storing input from the user.

x = input("Enter string : ")

#for storing reverse of the string.

y = pal(x)

#for checking if the string is palindrome or not.

if y == x :
    print("It's a palindrome.")
else :
    print("Not a palindrome.")


"""Output

Enter string : is this a palindrome
Not a palindrome.

Enter string : malayalam
It's a palindrome.


"""