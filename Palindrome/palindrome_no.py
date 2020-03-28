# Python program to find whether a number is a palindrome or not

# Function to reverse a number
def reverse(num):
    # Initialize variable
    rev = 0

    while ( num > 0 ) :
        dig = num % 10
        rev = rev * 10 + dig
        num = num // 10
    # Returning reversed number
    return rev    
    
# --- main --- 
num = int(input("Enter a number:"))
a  = reverse(num)

# Comparing the reversed number with original number
if(a == num):  
    print("Number entered is palindrome!")
else:
    print("Number entered is not a palindrome!")

'''
TEST CASES
INPUT
Enter a number:3445443
Number entered is palindrome!

OUTPUT
Enter a number:234
Number entered is not a palindrome!
'''
