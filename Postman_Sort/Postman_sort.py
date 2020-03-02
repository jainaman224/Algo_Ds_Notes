'''Size of the array : 5
Enter the elements : 
50
40
20
10
5
Input Array without Sorting : 
[50, 40, 20, 10, 5]
Sorted Array (Postman Sort)
[5, 10, 20, 40, 50]
'''


array = []
array1 = []

def swapPositions(list, pos1, pos2):

    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list

def swapPositionsMOD(list, pos1, pos2): 

    list[pos1], list[pos2] = list[pos2]%10, list[pos1]%10
    return list


count = int(input("Size of the array : "))
print("Enter the elements : ")
for i in range(0, count):
    ele = int(input())
    array.append(ele) # adding the element
    array1.append(ele) # adding the element

print("Input Array without Sorting : ")
print(array)

maxdigits=0
n=1

for i in range(len(array)):
    t = int(array[i])
    c=0
    while(t>0):
        c += 1
        t = int(t/10)  # Find MSB 

    if maxdigits < c :
        maxdigits = c   # number of digits of a each number 


while maxdigits>1 :
   n = n * 10
   maxdigits -=1

temp=0
for i in range(0,count):

    maxi = int(array[i]/n)         # MSB - Dividing by particular base 
    t = i
    for j in range(i+1,count):

        if maxi > int(array[j]/n) :

             maxi = int(array[j]/n)   # greatest MSB 
             t = j

    swapPositions(array,t,i)
    swapPositions(array1,t,i)



while n >= 1 :
    i=0
    while i<count :
        t1 = int(array[i] / n)
        j=i+1
        while j<count and t1==int(array[j]/n) :
            j = j+1

        k=i
        z=j

        for a in range(k,z-1) :

            for b in range(a+1,z) :

                if array1[a] > array1[b] :

                    swapPositions(array1,a,b)
                    swapPositionsMOD(array,a,b)
        i = j

    n = n/10

print("Sorted Array (Postman Sort)")
print(array1)
