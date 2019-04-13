def cycleSort(array):
    writes = 0

    for start in range(0, len(array)-1): #Loop through array to find cycles to rotate
        item = array[start]

        #find position to put the item
        pos = start
        for i in range(start+1, len(array)):
            if array[i] < item:
                pos += 1
        
        #If item is already there, this is not a cycle
        if pos == start:
            continue
        
        #Else, put the item there on the right after any duplicates
        while item == array[pos]:
            pos += 1
        array[pos], item = item, array[pos]
        writes += 1

        #Rotate the rest of the cycle
        while pos != start:

            #find position to put the item
            pos = start
            for i in range(start+1, len(array)):
                if array[i] < item:
                    pos += 1
         
            #Put the item there on the right after any duplicates
            while item == array[pos]:
                pos += 1
            array[pos], item = item, array[pos]
            writes += 1

    return writes

#Main Code
a = [1, 8, 3, 9, 10, 10, 2, 4]
n = len(a)
cycleSort(a)

print("After sort : ")
for i in range(0,n):
    print(a[i], end=" ")

"""
Output:

After sort :
1 2 3 4 8 9 10 10
"""
