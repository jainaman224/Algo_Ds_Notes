#Chocolate Distribution
#this chocolate function will return the minimum required difference
def chocolate(l, no_of_packets, no_of_students) :
    if no_of_packets < no_of_students :
        return -1
    if no_of_packets == 0 or no_of_students == 0 :
        return 0
    l.sort();
    p = len(l)
    p = p - 1  #last index of list
    last = 0
    first = 0
    i = 0
    diff = 0
    required_diff = l[p] + 1  #assigning maximum no.+1    
    i = 0
    while ( i + no_of_students - 1) < no_of_packets :
        diff = l[i + no_of_students - 1] - l[i]
        if diff < required_diff :
            required_diff = diff
            last = i + no_of_students - 1
            first = i
        i = i + 1
    return required_diff

no_of_students = int(input("enter the number of students"))
no_of_packets = int(input("Enter the number of packets"))

#print("enter the numbet contained by each packet repectively")
b = 0
list_of_chocolate = []
for i in range( no_of_packets ) :
   b = int(input("enter the no."))
   list_of_chocolate.append(b)

print("the minimum difference in chocolate distributed between two people is : " ,end=" ")
print(chocolate(list_of_chocolate,no_of_packets,no_of_students))

#input:
#enter the number of students3
#Enter the number of packets7
#enter the no.7
#enter the no.3
#enter the no.2
#enter the no.4
#enter the no.9
#enter the no.12
#enter the no.56
#the minimum difference in chocolate distributed between two people is : 2
