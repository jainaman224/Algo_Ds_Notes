class Node
    attr_accessor :data, :head, :left, :right

    def initialize(data)
        @data = data
        @head = 0
        @left = @right = nil
    end
end

# function should print the topView of the binary tree
def top_view(root)
    if root == nil then
        return nil
    end

    queue = Queue.new
    m = Hash.new
    head = 0
    root.head = head

    queue.push(root)
    while queue.length > 0 do
        root = queue.pop()
        head = root.head

        if m[head] == nil then
            m[head] = root.data
        end

        if root.left != nil then
            root.left.head = head - 1
            queue.push(root.left)
        end
        if root.right != nil then
            root.right.head = head + 1
            queue.push(root.right)
        end        
    end

    m.sort.to_h.each do |key, array|
        print array, ' '
    end
    puts ''
end

# testing program

node = Node.new(1)
node.left = Node.new(2)
node.right = Node.new(3)
node.left.right = Node.new(4)
node.left.right.right = Node.new(5)
node.left.right.right.right = Node.new(6)

puts "Top view of Binary Tree:"
top_view(node)


=begin Output

Top view of Binary Tree:
2 1 3 6

=end


