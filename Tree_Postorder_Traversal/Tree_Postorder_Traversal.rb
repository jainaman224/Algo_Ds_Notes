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

def PostOrder(root)
  if root
    PostOrder(root.left)
    PostOrder(root.right)
    print(root.val.to_s + " ")
  end
end

print("PostOrder traversal of tree is ")

root = Node.new(1)
root.left = Node.new(2)
root.right = Node.new(3)
root.left.left = Node.new(4)
root.left.right = Node.new(5)
root.right.left = Node.new(6)
root.right.right = Node.new(7)

PostOrder(root)

# => Output

# PostOrder traversal of tree is 4 5 2 6 3 7 1
