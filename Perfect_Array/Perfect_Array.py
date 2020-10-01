'''
    PERFECT ARRAY

    An array which is strictly increasing and then constant, and then strictly 
    decreasing is called a perfect array.
    There should be no variations in between.

'''

def perfect(a, num):
    count = 1
    while (count < num and a[count] > a[count - 1]):
        count = count + 1
    while (count < num and a[count] == a[count - 1]):
        count = count + 1
    while (count < num and a[count] < a[count - 1]):
        count = count + 1
    if (count == num):
        return 1
    return 0

print("Enter length of array")
num = int(input())
print("Enter array elements :")
a = []
for i in range(0, num):
    a.append(int(input()))
if (perfect(a, num) == 1):
    print("It is a perfect array")
else:
    print("It is not a perfect array")

'''
    Input : num = 5
            Array : [1, 2, 3, 3, 6]
    Output : It is not a perfect array
'''
