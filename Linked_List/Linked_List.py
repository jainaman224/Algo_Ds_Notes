class node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Linked_List:
    def __init__(self):
        self.head = None

    def Is_List_Empty(self):
        if self.head == None:
            return True

        return False

    def Insert_At_Beginning(self, value):
        temp = node(value)
        temp.next = self.head
        self.head = temp

    def Insert_At_End(self, value):
        temp = node(value)
        temp.next = None

        if self.Is_List_Empty():
            self.head = temp
            return

        current = self.head

        while current.next != None:
            current = current.next

        current.next = temp

    def Insert_After_Value(self, desired, value):
        current = self.head

        while current != None and current.data != desired:
            current = current.next

        if current == None:
            print("Element " + str(desired) + " not in list")
        else:
            temp = node(value)
            temp.next = current.next
            current.next = temp

    def Delete_At_Beginning(self):
        if self.Is_List_Empty():
            print("List is empty")
        else:
            temp = self.head
            self.head = self.head.next
            temp.next = None

    def Delete_At_End(self):
        if self.Is_List_Empty():
            print("List is empty")
            return

        temp = self.head

        if self.head.next == None:
            self.head = None
            temp.next = None
            return

        while temp.next != None:
            prev = temp
            temp = temp.next

        prev.next = temp.next
        temp.next = None

    def Delete_With_Value(self, desired):
        if self.Is_List_Empty():
            print("List is empty")
            return

        temp = self.head

        if self.head.data == desired:
            self.head = self.head.next
            temp.next = None
            return

        while temp != None and temp.data != desired:
            prev = temp
            temp = temp.next

        if temp == None:
            print("Element " + str(desired) + " is not in list")
        else:
            prev.next = temp.next
            temp.next = None


    def Search(self, desired):
        temp = self.head

        while temp != None and temp.data != desired:
            temp = temp.next

        if temp == None:
            print("Element " + str(desired) + " not found")
        else:
            print("Element " + str(desired) + " is present in list")

    def Print_Linked_List(self):
        if self.Is_List_Empty():
            print("List is Empty")
            return

        current = self.head

        while current.next != None:
            print(current.data, end = " -> ")
            current = current.next

        print(current.data)


LinkedList = Linked_List()

for i in range(0, 5):
    LinkedList.Insert_At_Beginning(i);

LinkedList.Print_Linked_List();

for i in range(5, 10):
    LinkedList.Insert_At_End(i);

LinkedList.Print_Linked_List();

LinkedList.Insert_After_Value(5, 9);
LinkedList.Insert_After_Value(10, 9);

LinkedList.Print_Linked_List();

for i in range(0, 3):
    LinkedList.Delete_At_End();

LinkedList.Print_Linked_List();

for i in range(0, 3):
    LinkedList.Delete_At_Beginning();

LinkedList.Print_Linked_List();

LinkedList.Delete_With_Value(1);
LinkedList.Delete_With_Value(5);

LinkedList.Print_Linked_List();

LinkedList.Search(6);
LinkedList.Search(8);


'''
Output

4 -> 3 -> 2 -> 1 -> 0
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 6 -> 7 -> 8 -> 9
Element 10 not in list
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6 -> 7 -> 8 -> 9
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6
1 -> 0 -> 5 -> 9 -> 6
0 -> 9 -> 6
Element 6 is present in list
Element 8 not found

'''
