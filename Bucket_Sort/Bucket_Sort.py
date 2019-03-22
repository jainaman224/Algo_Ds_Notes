# Bucket sort is a comparison sort algorithm that operates on elements by dividing them into different buckets and then sorting these buckets individually.
# Time Complexity:
# Best and Average Case: O(n + k), where k= number of buckets
# Worst-case: O(n²).
import math

# get the bucket number to which the present element of array is to be added
def getBucket(num, divider):
    # defining hash value as floor of num/divider
    index = math.floor(num/divider)
    return index

# input list
arr = [22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14]
n = len(arr)
# initialising number of buckets
nbucket = 10
# taking a divider value to create hash for bucket index to which an element is to added
# Here, divider = ceil( (81+1)  /10) = ceil( 8.2 ) = 9
divider = math.ceil((max(arr)+1) / nbucket)
# Creating bucket as a list of list
bucket = []
for i in range(nbucket):
    bucket.append([])

for num in arr:
    # fetching bucket number for element
    index = getBucket(num, divider)
    # append the element in bucket
    bucket[index].append(num)

# Sort each buckets individually
for i in range(nbucket):
    bucket[i].sort()

# Merging the elements present in bucket into one list
k=0
for i in range(nbucket):
    for j in range(len(bucket[i])):
        arr[k] = bucket[i][j]
        k= k+1

# displaying result
print("Sorted array:")
print(arr)

# Input:
# [22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14]

# We get the buckets created as:
# bucket[0] = [8, 6]
# bucket[1] = [12, 10, 14]
# bucket[2] = [22, 18]
# bucket[3] = [33]
# bucket[4] = []
# bucket[5] = [45, 50]
# bucket[6] = []
# bucket[7] = []
# bucket [8] = [72]
# bucket[9] = [81]

# Output
# Sorted array:
# [6, 8, 10, 12, 14, 18, 22, 33, 45, 50, 72, 81]    
