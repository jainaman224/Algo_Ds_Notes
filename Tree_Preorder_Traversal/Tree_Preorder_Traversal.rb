class Node
  def initialize(key)
    @left
    @right
    @val = key
  end
  attr_accessor :left
  attr_accessor :right
  attr_accessor :val
end

def PreOrder(root)
  if root
    print(root.val.to_s + " ")
    PreOrder(root.left)
    PreOrder(root.right)
  end
end

print("PreOrder traversal of tree is ")

root = Node.new(1)
root.left = Node.new(2)
root.right = Node.new(3)
root.left.left = Node.new(4)
root.left.right = Node.new(5)
root.right.left = Node.new(6)
root.right.right = Node.new(7)

PreOrder(root)

# => Output

# PreOrder traversal of tree is 1 2 4 5 3 6 7
