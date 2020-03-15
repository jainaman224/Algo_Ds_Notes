# Python program to find whether a string is a palindrome or not

# Function to reverse a String
def reverse(str):

    # Initialize variable
    rev = ""

    for i in range (len(str)-1, -1, -1):
        rev = rev + str[i]
    return rev

    
# --- main --- 
string = raw_input(("Enter a string: "))  #User Input

a  = reverse(string) #Function call

if(a == string):  #Comparing the reversed String with original String
    print("String entered is palindrome!")
else:
    print("String entered is not a palindrome!")

'''
TEST CASES

Enter a string: affcffa
String entered is palindrome!

Enter a string: abbcd
String entered is not a palindrome!
'''
