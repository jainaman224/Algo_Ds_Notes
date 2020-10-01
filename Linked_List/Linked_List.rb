class Node
    attr_accessor :data, :next

    def initialize(data)
        @data = data
        @next = nil
    end
end


class LinkedList
    attr_accessor :head

    def initialize()
       @head = nil 
    end

    def is_list_empty()
        if @head == nil then
            return true
        end
        return false
    end

    def insert_at_beginning(value)
        temp = Node.new(value)
        temp.next = @head
        @head = temp
    end

    def insert_at_end(value)
        temp = Node.new(value)
        
        if is_list_empty() then
            @head = temp 
            return
        end

        current = @head
        while current.next != nil do
            current = current.next
        end

        current.next = temp
    end

    def insert_after_value(desired, value)
        current = @head

        while current != nil and current.data != desired do
            current = current.next
        end 

        if current == nil then
            print "Element %d not in list\n" % [desired]
        else
            temp = Node.new(value)
            temp.next = current.next
            current.next = temp
        end
    end

    def delete_at_beginning()
        if is_list_empty() then
            puts "List is empty"
        else
            temp = @head
            @head = @head.next
            temp.next = nil
        end
    end

    def delete_at_end()
        if is_list_empty() then
            puts "List is empty"
            return
        end
        
        temp = @head
        
        if @head.next == nil then
            @head = nil
            temp.next = nil 
            return
        end
        
        while temp.next != nil do
            
            prev = temp
            temp = temp.next
        end

        prev.next = nil
        temp.next = nil
    end

    def delete_with_value(desired)
        if is_list_empty() then
            puts "List is empty"
            return 
        end

        temp = @head

        if @head.data == desired then
            @head = @head.next
            temp.next = nil
            return
        end

        while temp != nil and temp.data != desired do
            prev = temp
            temp = temp.next
        end

        if temp == nil then
            print "Element %d not in list\n" % [desired]
        else
            prev.next = temp.next
            temp.next = nil
        end
    end

    def search(desired)
        temp = @head

        while temp != nil and temp.data != desired do
            temp = temp.next
        end

        if temp == nil then
            puts "Element %d is not found" % [desired]
        else
            puts "Element %d is present in list" % [desired]
        end
    end

    def print_linked_list()
        if is_list_empty() then
            puts "List is empty"
            return
        end

        current = @head

        while current.next != nil do
            print "%d -> " % [current.data]
            current = current.next
        end
        puts current.data
    end

    def get_length()
        current = @head
        length = 0

        while current != nil do
            length += 1
            current = current.next
        end

        return length
    end
end


linked_list = LinkedList.new
puts "List is created!"
linked_list.print_linked_list
puts "Current Length: %d" % linked_list.get_length

for i in 0..4
    linked_list.insert_at_beginning(i)
end
linked_list.print_linked_list
puts "Current Length: %d" % linked_list.get_length

for i in 5..9
    linked_list.insert_at_end(i)
end
linked_list.print_linked_list
puts "Current Length: %d" % linked_list.get_length

linked_list.insert_after_value(5, 9)
linked_list.insert_after_value(10, 9)
linked_list.print_linked_list
puts "Current length: %d" % linked_list.get_length

for i in 0..2
    linked_list.delete_at_end
end
linked_list.print_linked_list
puts "Current length: %d" % linked_list.get_length

for i in 0..2
    linked_list.delete_at_beginning
end
linked_list.print_linked_list
puts "Current length: %d" % linked_list.get_length

linked_list.delete_with_value(1)
linked_list.delete_with_value(5)
linked_list.print_linked_list
puts "Current length: %d" % linked_list.get_length

linked_list.search(6)
linked_list.search(8)


=begin Output

List Created!
List is Empty
Current Length: 0
4 -> 3 -> 2 -> 1 -> 0
Current Length: 5
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 6 -> 7 -> 8 -> 9
Current Length: 10
Element 10 not in list
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6 -> 7 -> 8 -> 9
Current Length: 11
4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6
Current Length: 8
1 -> 0 -> 5 -> 9 -> 6
Current Length: 5
0 -> 9 -> 6
Current Length: 3
Element 6 is present in list
Element 8 not found

=end