def cycleSort(array, size):
    for start in range(0, n-1): #Put array element in the correct place
        key = array[start]
        location = start
        for i in range(start+1, n): #Count smaller element in the right side of key
            if array[i] < key:
                location += 1
        
        if location == start: #Ignore lower part and go for next iteration
            continue
        
        while key == array[location]: #If same data is found, increase location by 1
            location += 1
        
        if location != start:
            array[location], key = key, array[location]
        
        while location != start:
            location = start
            for i in range(start+1, n): #Location to put element
                if array[i] < key:
                    location += 1
            
            while key == array[location]: #If same data is found, increase location
                location += 1
            
            if key != array[location]:
                array[location], key = key, array[location]

#Main program
a = [23, 63, 98, 74, 20, 14, 36, 45, 99, 78, 98]
n = len(a)
cycleSort(a, n)

print("After sort : ")
for i in range(0, n):
    print(a[i], end = " ")

"""
Output:

After sort :
14 20 23 36 45 63 74 98 98 99
"""
