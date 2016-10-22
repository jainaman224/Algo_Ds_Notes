=begin

Author: Jennifer Tran
Last Updated: 21/10/2016

=end

def main

list = LinkedList.new()

puts("Before sorting:")
list.add(13)
list.add(4)
list.add(10)
list.add(1)
list.add(20)
list.add(7)
list.printList

puts("\nAfter sorting:")
list.selectionSort
list.printList

end

class LinkedList
  def initialize
    @top = nil
  end

  # Inserts the items at the end of the list
  def add(newItem)
    curr = @top

    # Top is empty insert at the front
    if(curr == nil)
      @top = Node.new(newItem,nil)
    else
      # Traverse through the list until it reaches the end
      while curr.getNext != nil do
        curr = curr.getNext
      end

      # Now set the new node
      curr.setNext(Node.new(newItem,nil))

    end
  end

  def printList
    curr = @top
    while(curr != nil)
      print (curr.getItem)
      print " "
      curr = curr.getNext
    end
    puts()
  end

  def selectionSort
    beg = @top
    min = @top

    # Iterate through the list
    while(beg.getNext != nil)
			min = beg
			curr = beg.getNext

			while(curr != nil)
				# Check to see if its the smallest
				if(curr.getItem < min.getItem)
					min = curr
				end

				curr = curr.getNext
			end

			# Swap the values
			temp = beg.getItem
			beg.setItem(min.getItem)
			min.setItem(temp)

			beg = beg.getNext
		end

  end
end

class Node
  # Constructor
  def initialize(newItem,newLink)
    @item = newItem
    @link = newLink
  end

  # Gets the item
  def getItem
    @item
  end

  # Gets the next node
  def getNext
    @link
  end

  # Sets the next node
  def setNext(newLink)
    @link = newLink
  end

  # Sets the next item
  def setItem(newItem)
    @item = newItem
  end

end

# Calls the main method
main

=begin
OUTPUT:

Before sorting:
13 4 10 1 20 7

After sorting:
1 4 7 10 13 20
=end
