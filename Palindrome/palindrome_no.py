# Python program to find whether a number is a palindrome or not

# Function to reverse a number
def reverse(num):

    # Initialize variable
    rev=0

    while ( num > 0 ) :
        dig = num % 10
        rev = rev * 10 + dig
        num = num // 10
    return rev    # Returning reversed number

    
# --- main --- 
num=int(input("Enter a number:"))
a  = reverse(num)

if(a == num):  #Comparing the reversed number with original number
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
