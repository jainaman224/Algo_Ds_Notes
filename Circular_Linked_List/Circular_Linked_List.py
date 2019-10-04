class node:
    def __init__(self, key, next=None):
        self.key = key
        self.next = next

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)


class circular_linked_list:
    def __init__(self, head=None):
        self.head = head

    def pretty_print(self):

        cir_list_str = ''

        current_node = self.head

        while current_node:
            cir_list_str += '-({0:1d})-'.format(current_node.key)
            current_node = current_node.next
            if current_node == self.head:
                break

        return cir_list_str

    # Insert node at the end of the circular linked list
    def append(self, key):
        new_node = node(key)
        # If there are no elements in the circular linked list
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
        else:
            current_node = self.head
            # Traverse the circular linked list to find last node
            while current_node.next != self.head:
                current_node = current_node.next

            current_node.next = new_node
            new_node.next = self.head

    # Insert node at the beginning of the circular linked list
    def prepend(self, key):
        new_node = node(key)

        # This will handle an empty list too
        current_node = self.head
        new_node.next = self.head

        # If there are no elements in the circular linked list
        if self.head is None:
            new_node.next = new_node
        else:
            # If not an empty circular linked list - the last node needs to be
            # updated with new self.head which is the new node
            while current_node.next != self.head:
                current_node = current_node.next

            current_node.next = new_node

        self.head = new_node

    # Insert after a specific node in the circular linked list
    def insert_after_node(self, afterkey, key):
        current_node = self.head
        while current_node:

            if current_node.next == self.head and current_node.key == afterkey:
                # New node is to be appended to the list
                self.append(key)
                return
            elif current_node.key == afterkey:
                new_node = node(key)
                next_node = current_node.next

                # Update next pointers
                current_node.next = new_node
                new_node.next = next_node

                return
            else:
                if current_node.next == self.head:
                    break
            current_node = current_node.next

    def delete(self, deletekey):
        current_node = self.head
        prev_node = None
        while current_node:

            # The node to be deleted is the head node
            if current_node.key == deletekey and current_node == self.head:

                # Case 1 - The head is the only element in circular linked list
                if current_node.next == self.head:
                    current_node = None
                    self.head = None
                    return

                # Case 2 - There are more elements in the circular linked list
                else:
                    # Traverse to end of list, update self.head, delete head
                    while current_node.next != self.head:
                        current_node = current_node.next
                    current_node.next = self.head.next
                    self.head = self.head.next
                    current_node = None
                    return

            # Case 3 & 4 - Node to be deleted in between nodes or last node
            elif current_node.key == deletekey:
                prev_node.next = current_node.next
                current_node = None
                return

            else:
                if current_node.next == self.head:
                    break

            prev_node = current_node
            current_node = current_node.next


if __name__ == "__main__":

    # Create circular linked list
    cir_list = circular_linked_list()

    data = [5, 8, 10, 12]

    for value in data:
        cir_list.append(value)

    print('\n----- Insert Operations ----- ')

    # Expected -(5)--(8)--(10)--(12)-
    print('\nCircular linked list elements using append --->',
          cir_list.pretty_print())

    # Prepend when the list is empty
    cir_list1 = circular_linked_list()

    cir_list1.prepend(4)

    # Expected -(4)-
    print('\nPrepend on empty list  ---> ', cir_list1.pretty_print())

    # Prepend into an existing linked list
    cir_list1.prepend(0)

    # Expected -(0)--(4)-
    print('\nPrepend on an existing list  ---> ', cir_list1.pretty_print())

    cir_list2 = circular_linked_list()
    cir_list2.append(17)

    # Expected -(17)-
    print('\nAppend on empty list  ---> ', cir_list2.pretty_print())

    # Append operation called when inserted into a single element list
    cir_list2.insert_after_node(17, 20)

    # Expected -(17)--(20)-
    print('\nInserting 20 after 17 - Append   ---> ', cir_list2.pretty_print())

    # Inserting node in between nodes
    cir_list2.insert_after_node(17, 18)

    # Inserting node in between nodes
    # Expected -(17)--(18)--(19)--(20)-
    cir_list2.insert_after_node(18, 19)
    print('\nInserting 19 after 18  ---> ', cir_list2.pretty_print())

    print('\n----- Delete Operations ----- ')

    del_cir_list0 = circular_linked_list()
    del_cir_list0.append(77)

    print('\nSingle element circular linked list before deletion --->',
          del_cir_list0.pretty_print())

    # Case 1 - Node to be deleted is head and there is only a single element
    # in the circular linked list
    # Expected - To see nothing printed
    del_cir_list0.delete(77)

    print('\nNo linked list present after deleting only node  --->',
          del_cir_list0.pretty_print())

    del_cir_list = circular_linked_list()
    del_cir_list.append(16)
    del_cir_list.prepend(11)
    del_cir_list.insert_after_node(11, 19)
    del_cir_list.prepend(9)
    del_cir_list.append(22)
    del_cir_list.prepend(5)

    # Expected -(5)--(9)--(11)--(19)--(16)--(22)-
    print('\nCircular linked list before deletion --->',
          del_cir_list.pretty_print())

    del_cir_list.delete(5)

    # Case 2 - Node to be deleted is head and there are more elements in list
    # Expected -(9)--(11)--(19)--(16)--(22)-
    print('\nCircular linked list after deletion of head--->',
          del_cir_list.pretty_print())

    # Case 3 - Node to be deleted is in between nodes
    # Expected -(9)--(11)--(16)--(22)-
    del_cir_list.delete(19)
    print('\nList after deletion of in between node 19 --->',
          del_cir_list.pretty_print())

    # Case 4 - Node to be deleted is the last node
    # Expected -(9)--(11)--(16)-
    del_cir_list.delete(22)
    print('\nList after deletion of last node 22 --->',
          del_cir_list.pretty_print())

    # Try to delete a non-existing node from the circular linked list
    # Expected -(9)--(11)--(16)-
    del_cir_list.delete(88)
    print('\nNo change in circular linked list when trying to delete non existing key',
          del_cir_list.pretty_print())
