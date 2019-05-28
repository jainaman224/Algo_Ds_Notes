#Python program to find mean , variance and standard deviation

num = int(input("Enter number of elements in array: "))
arr = []
print("Enter your array: ")
for i in range(0, num):
    arr.insert(i, float(input()))

mean = 0.0

for i in range(0, num):
    # Calculating sum of the array
    mean = mean + arr[i]

# mean is the average of the numbers
mean = mean / num

sum = 0.0

for i in range(0, num):
    sum = sum + (arr[i] - mean) ** 2

# Variance is the average of the squared differences from the Mean
v = sum / num
# Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
sd = v ** (1 / 2)

print("Mean = ", mean)
print("Variance = ", v)
print("Standard Deviation = ", sd)

'''
Enter number of elements in array: 5
Enter your array:
1
2
3
4
5
Mean =  3.0
Variance =  2.0
Standard Deviation =  1.4142135623730951
'''
