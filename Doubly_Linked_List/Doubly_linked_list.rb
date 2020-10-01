# class to make a node
class Node
    attr_accessor :prev, :val, :next
    def initialize(val, prev_node = nil, next_node = nil)
        @prev = prev_node
        @val  = val
        @next = next_node
    end
end

# class for the doubly linked list
class Doubly_list
    def initialize(head_node = nil)
        @head = head_node
    end

    # to insert a node at the end of the list
    def append(val)
        new_node = Node.new(val)
        if @head == nil
            @head = new_node
        else
            current_node = @head
            while current_node.next != nil
                current_node = current_node.next
            end
            new_node.prev = current_node
            current_node.next = new_node
        end
    end

    # to insert a node at the beginning of the list
    def prepend(val)
        new_node = Node.new(val)
        if @head == nil
            @head = new_node
        else
            current_node = @head
            @head = new_node
            new_node.next = current_node
            current_node.prev = @head
        end
    end

    # to print the elements of the list
    def print
        current_node = @head
        while current_node.next != nil
            puts current_node.val
            current_node = current_node.next
        end
        puts current_node.val
    end

    # Insert after a specific node in a doubly linked list
    def insert_after(val, after_val)
        new_node = Node.new(val)
        current_node = @head
        while current_node.val != after_val
            current_node = current_node.next
        end
        new_node.prev = current_node
        new_node.next = current_node.next
        current_node.next.prev = new_node
        current_node.next = new_node
    end

    # Insert node before a specific node in a doubly linked list
    def insert_before(val, before_val)
        new_node = Node.new(val)
        current_node = @head
        while current_node.val != before_val
            current_node = current_node.next
        end
        new_node.prev = current_node.prev
        new_node.next = current_node
        current_node.prev.next = new_node
        current_node.prev = new_node
    end

    # delete a specific node from the linked DoublyList
    def delete_node(delete_val)
        current_node = @head
        while current_node.val != delete_val
            current_node = current_node.next
        end
        # if the node is head node and the only node in the list
        if current_node == @head && current_node.next == nil
            @head = nil
            current_node = nil
        # if the node is the last node
        elsif current_node.next == nil && current_node.prev != nil
            current_node.prev.next = nil
            current_node.prev = nil
            current_node = nil
        # if the node is the head node but not the only node in the list
        elsif current_node == @head && current_node.next != nil
            @head = current_node.next
            current_node.next = nil
            current_node = nil
        # if the node is in between the nodes
        elsif current_node.next != nil && current_node.prev != nil
            current_node.prev.next = current_node.next
            current_node.next.prev = current_node.prev
            current_node.next = nil
            current_node.prev = nil
            current_node = nil
        end
    end
end
# CASE1
# to insert thr node at the end of the list.
db = Doubly_list.new
for i in 0..3
    db.append(i)
end
db.print
print("----------------------------------------------------------------------" + "\n")
# CASE2
# to insert the node at the beginning of the list
db1 = Doubly_list.new
for i in 0..3
    db1.prepend(i)
end
db1.print
print("----------------------------------------------------------------------" + "\n")
# CASE3
#to insert the node after a specific value
db2 = Doubly_list.new
for i in 0..3
    db2.append(i)
end
db2.insert_after(5 , 1)
db2.print
print("----------------------------------------------------------------------" + "\n")
# CASE4
#to insert a node before a specific value
db3 = Doubly_list.new
for i in 0..3
    db3.append(i)
end
db3.insert_before(5 , 1)
db3.print
print("----------------------------------------------------------------------" + "\n")
# CASE5
# deleting a specific node
db3.delete_node(0) #when the node is the head node but not the only node in the list
db3.delete_node(3) #when the node is the last node
db3.delete_node(1) #when the node is in between the nodes.
db3.print

=begin
 OUTPUTS
 CASE1
 0
 1
 2
 3
 CASE2
 3
 2
 1
 0
 CASE3
 0
 1
 5
 2
 3
 CASE4
 0
 5
 1
 2
 3
 CASE5
 5
 2
=end
