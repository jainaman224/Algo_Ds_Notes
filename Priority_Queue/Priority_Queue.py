queue = []

def insert(data):           # To insert values into the Queue
    queue.append(data)

def delete():               # TO remove value from the Priority Queue
    try:                    # Here highest value will be deleted first
        max = 0
        for i in range(len(queue)): 
            if queue[i] > queue[max]: 
                max = i

        item = queue[max] 
        del queue[max] 
        
        return item 
    
    except IndexError:              # Instead of giving error for empty queue
        print("Queue is empty!!")   # Displays that 'Queue is empty'
                
while 1:
    
    print("\t1. Insert value in queue\n\t2. Delete value in queue\n\t3. Print Queue\n\t4. Exit")
    
    opt = int(input("Enter your option:"))
    
    if opt == 1:
        value = int(input("Enter the value:"))
        insert(value)
        
    elif opt == 2:
        del_value = delete()
        print("\n" + str(del_value) + " is deleted")
        
    elif opt == 3:
        print(queue)
        
    elif opt == 4:
        break

    else:
        print("\tInvalid option!\n\tTry Again!!")
        
# The program is made of user choice
'''
Example:
        1. Insert value in queue
        2. Delete value in queue
        3. Print Queue
        4. Exit
Enter your option: 1        # Here you have to give value to be inserted in the queue
Enter the value: 12
        1. Insert value in queue
        2. Delete value in queue
        3. Print Queue
        4. Exit
Enter your option:2          # To delete the value of highest priority(here highest value)
14 is deleted
Enter your option:3          #  display the queue
[12, 1, 7]
Enter your option:4           #to exit
If you enter any other value other than (1,2,3,4), You will be shown:
    Invalid option!
    Try Again!!
'''
