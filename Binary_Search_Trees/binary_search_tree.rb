# THESE METHODS RESEMBLE CORMEN(CLRS) TEXTBOOK PSEUDO CODE

# INDEX
#      inorder_tree_walk
#      preoder_tree_walk
#      postorder_tree_walk
#      tree_search
#      iterative_tree_search
#      tree_minimum
#      tree_maximum
#      tree_successor
#      tree_insert
#      tree_delete -> transplant

# Public: Analogous to a struct in C/C++ for building linked lists.
# This class only contains an initialize method which acts a constructor for
# setting and accessing the object properties
#
# There are multiple ways this can be defined, this is my personal favorite
# Other ways are listed at the bottom of the file
# Choose whatever is convenient for YOU.
#
# Examples
#   Tree.new(nil)
#   # => #<Tree:0x007ffeab2187a0 @root=nil>
class Tree
  attr_accessor :root

  def initialize(root)
    @root = root
  end
end

# Public: Analogous to a struct in C/C++ for building linked lists.
# This class only contains an initialize method which acts a constructor for
# setting and accessing the object properties
#
# NOTE: Two constructors, one with satellite data and another without. The later
#       one will be used predominantly
#
# Examples
#   Node.new(10, "HELLO", nil, nil, nil)
#   # => #<Node:0x007ffeab2187a0 @key=10, @satellite_data="HELLO", @p=nil, @left=nil, @right=nil>
class Node
  attr_accessor :key, :satellite_data, :p, :left, :right
  def initialize(key, satellite_data, p, left, right)
    @key, @satellite_data, @p, @left, @right = key, satellite_data, p, left, right
  end

  #   Node.new(10, nil, nil, nil)
  #   # => #<Node:0x007ffeab2187a0 @key=10, @p=nil, @left=nil, @right=nil>
  def initialize(key, p, left, right)
    @key, @p, @left, @right = key, p, left, right
  end
end

#             TREE structure
#                  F
#                /   \
#              B      G
#            /  \      \
#          A     D      I
#              /  \    /
#             C   E   H
#   tree = Tree.new(F)   NOTE: Whole tree is assumed to have been constructed alread

# Public: Prints the elements inside tree nodes in a LEFT - PARENT - RIGHT manner
#
# x - Node, Preferably a root node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   inorder_tree_walk(F)
#   => A B C D E F G H I
def inorder_tree_walk(x)
  unless x.nil?
    inorder_tree_walk(x.left)
    p x.key
    inorder_tree_walk(x.right)
  end
end

# Public: Prints the elements inside tree nodes in a PARENT - LEFT - RIGHT manner
#
# x - Node, Preferably a root node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   preoder_tree_walk(F)
#   => F B A D C E G I H
def preoder_tree_walk(x)
  unless x.nil?
    p x.key
    preoder_tree_walk(x.left)
    preoder_tree_walk(x.right)
  end
end

# Public: Prints the elements inside tree nodes in a LEFT - RIGHT - PARENT manner
#
# x - Node, Preferably a root node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   postorder_tree_walk(F)
#   => A C E D B H I G F
def postorder_tree_walk(x)
  unless x.nil?
    postorder_tree_walk(x.left)
    postorder_tree_walk(x.right)
    p x.key
  end
end

# Public: Traverses and finds the element if present by using the Binary tree
#         property - lesser elements on left and greater elements on right
#         Recursive strategy
#
# x - Node, Preferably a root node
# k - Key to be searched
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_search(F, 'I')
#   => I
def tree_search(x, k)
  return x if (x.nil? || k == x.key)
  return (k < x.key) ? tree_search(x.left, k) : tree_search(x.right, k)
end

# Public: Traverses and finds the element if present by using the Binary tree
#         property - lesser elements on left and greater elements on right
#         Iterative strategy
#
# x - Node, Preferably a root node
# k - Key to be searched
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_search(F, 'I')
#   => I
def iterative_tree_search(x, k)
  while !x.nil? && k != x.key
    x = (k < x.key) ? x.left : x.right
  end
  x
end

# Public: Traverses to LEFT and finds the minimum element using the Binary tree
#         property - lesser elements on left and greater elements on right
#
# Node, Root/Subtree node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_minimum(F)
#   => A
def tree_minimum(x)
  return if x.nil?
  while !x.left.nil?
    x = x.left
  end
  x
end

# Public: Traverses to RIGHT and finds the maximum element using the Binary tree
#         property - lesser elements on left and greater elements on right
#
# Node, Root/Subtree node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_maximum(F)
#   => H
def tree_maximum(x)
  return if x.nil?
  while !x.right.nil?
    x = x.right
  end
  x
end

# Public: Finds the next biggest element to the given node in a Binary tree
#
# Node, Root/Subtree node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_successor(F)
#   => G
def tree_successor(x)
  return if x.nil?
  return tree_minimum(x.right) unless x.right.nil?
  y = x.p
  while !y.nil? && x == y.right
    x = y
    y = y.p
  end
  y
end

# Public: Finds the highest element that is just smaller than the provided node
#
# Node, Root/Subtree node
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_predecessor(F)
#   => E
def tree_predecessor(x)
  return if x.nil?
  return tree_maximum(x.left) unless x.left.nil?
  y = x.p
  while !y.nil? && x == y.left
    x = y
    y = y.p
  end
  y
end

# Public: Inserts a node at the appropriate location in the tree without not disturbing
#         Binary search tree property
#
# t - Tree structure
# z - Node to be INSERTED
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61
#   tree_insert(t, J)
#             TREE structure
#                  F
#                /   \
#              B      G
#            /  \      \
#          A     D      I
#              /  \   /  \
#             C   E  H    J(INSERTED NODE)
def tree_insert(t, z)
  return if (t.nil? || z.nil?)
  y = nil
  x = t.root
  while !x.nil?
    y = x
    (z.key < x.key) ? (x = x.left) : (x = x.right)
  end
  z.p = y

  if y.nil?
    t.root = z
  elsif z.key < y.key
    y.left = z
  else
    y.right = z
  end
end

# Public: Replaces the subtree of a node with subtree of another node
#
# t - Tree structure
# u - Node which gets replaced
# v - Node which replaces u
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61 with an inserted node J
#        transplant(t, G, I)
#                F
#              /   \
#             B     I
#            / \   / \
#           A   D H   J
#              / \
#             C   E
def transplant(t, u, v)
  return if (u.nil? || v.nil? || t.nil?)
  if u.p.nil?
    t.root = v
  elsif u == u.p.left
    u.p.left = v
  else
    u.p.right = v
  end
  v.p = u.p unless v.nil?
end

# Public: Deletes a node at the appropriate location in the tree without disturbing
#         Binary search tree property
# NOTE: Uses SUCCESSOR transplant i.e next largest element to the deletable node
#
# t - Tree structure
# z - Node to be DELETED
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61 with an inserted node J
#                        TREE structure
#                                F
#                              /   \
#                             B     G
#                            / \     \
#                           A   D     I
#                              / \   / \
#                             C   E H   J
# tree_delete(t, F)        tree_delete(t, B)           tree_delete(t, D)
#       G                        F                           F
#     /   \                    /   \                       /   \
#    B     I                  C     G                     B     G
#   / \   / \                / \     \                   / \     \
#  A   D H   J              A   D     I                 A   E     I
#     / \                        \   / \                   /     / \
#    C   E                        E H   J                 C     H   J
def tree_delete(t, z)
  return if z.nil?
  if z.left.nil?
    transplant(t, z, z.right)
  elsif z.right.nil?
    transplant(t, z, z.left)
  else
    y = tree_minimum(z.right)
    if y.p != z
      transplant(t, y, y.right)
      y.right = z.right
      y.right.p = y
    end
    transplant(t, z, y)
    y.left = z.left
    y.left.p = y
  end
end

# Public: Deletes a node at the appropriate location in the tree without disturbing
#         Binary search tree property
# NOTE: Uses PREDECESSOR transplant i.e next largest element to the deletable node
#
# t - Tree structure
# z - Node to be DELETED
#
# Examples
#   NOTE: Based on the mock tree structure at LINE:61 with an inserted node J
#                        TREE structure
#                                F
#                              /   \
#                             B     G
#                            / \     \
#                           A   D     I
#                              / \   / \
#                             C   E H   J
# tree_delete(t, F)        tree_delete(t, B)           tree_delete(t, D)
#       E                        F                           F
#     /   \                    /   \                       /   \
#    B     G                  A     G                     B     G
#   / \     \                  \     \                   / \     \
#  A   D     I                  D     I                 A   C     I
#     /     / \                / \   / \                     \   / \
#    C     H   J              C  E H   J                     E   H   J
def tree_delete_predecessor(t, z)
  if z.left.nil?
    transplant(t, z, z.right)
  elsif z.right.nil?
    transplant(t, z, z.left)
  else
    y = tree_maximum(z.left)
    if y.p != z
      transplant(t, y, y.left)
      y.left = z.left
      y.left.p = y
    end
    transplant(t, z, y)
    y.right = z.right
    y.right.p = y
  end
end

# TEST inorder_tree_walk
#      preoder_tree_walk
#      postorder_tree_walk
#      tree_search
#      iterative_tree_search
#      tree_minimum
#      tree_maximum
#      tree_successor
#      tree_predecessor
#      tree_insert
#      tree_delete
#      tree_delete_predecessor
def unit_test_binary_tree
  node_a = Node.new('A', nil, nil, nil)
  node_b = Node.new('B', nil, nil, nil)
  node_c = Node.new('C', nil, nil, nil)
  node_d = Node.new('D', nil, nil, nil)
  node_e = Node.new('E', nil, nil, nil)
  node_f = Node.new('F', nil, nil, nil)
  node_g = Node.new('G', nil, nil, nil)
  node_h = Node.new('H', nil, nil, nil)
  node_i = Node.new('I', nil, nil, nil)
  node_j = Node.new('J', nil, nil, nil)

  tree = Tree.new(nil)

  p "--------------------  BEGIN CONSTRUCTING TREE -------------------- "
  [node_f, node_b, node_g, node_a, node_d, node_c, node_e, node_i, node_h].each_with_index do |x, i|
    tree_insert(tree, x)
  end
  p "                              F                      "
  p "                            // \\                    "
  p "                           B     G                   "
  p "                         // \\    \\                 "
  p "                         A   D     I                 "
  p "                           // \\ //                  "
  p "                           C   E H                   "

  p "--------------------  END CONSTRUCTING TREE -------------------- "

  print "\n"

  p "--------------------  BEGIN INRODER TREE WALK -------------------- "
  p inorder_tree_walk(tree.root)
  p "--------------------  END INRODER TREE WALK -------------------- "

  print "\n"

  p "--------------------  BEGIN PREORDER TREE WALK -------------------- "
  p preoder_tree_walk(tree.root)
  p "--------------------  END PREORDER TREE WALK -------------------- "

  print "\n"

  p "--------------------  BEGIN POSTORDER TREE WALK -------------------- "
  p postorder_tree_walk(tree.root)
  p "--------------------  END PREORDER TREE WALK -------------------- "

  print "\n"

  p "--------------------  BEGIN RECURSIVE TREE SEARCH -------------------- "
  p tree_search(tree.root, 'I')
  p "--------------------  END RECURSIVE TREE SEARCH -------------------- "

  print "\n"

  p "--------------------  BEGIN ITERATIVE TREE SEARCH -------------------- "
  p iterative_tree_search(tree.root, 'I')
  p "--------------------  END ITERATIVETREE SEARCH -------------------- "

  print "\n"

  p "--------------------  BEGIN SEARCHING FOR TREE MIN -------------------- "
  p tree_minimum(tree.root)
  p "--------------------  END SEARCHING FOR TREE MIN -------------------- "

  print "\n"

  p "--------------------  BEGIN SEARCHING TREE MAX -------------------- "
  p tree_maximum(tree.root)
  p "--------------------  END SEARCHING TREE MAX -------------------- "

  print "\n"

  p "--------------------  BEGIN SEARCHING FOR SUCCESSOR -------------------- "
  p tree_successor(node_g)
  p "--------------------  END SEARCHING FOR SUCCESSOR -------------------- "

  print "\n"

  p "--------------------  BEGIN SEARCHING FOR PREDECESSOR -------------------- "
  p tree_predecessor(node_g)
  p "--------------------  END SEARCHING FOR PREDECESSOR -------------------- "

  print "\n"

  p "--------------------  BEGIN NODE INSERTION -------------------- "
  tree_insert(tree, node_j)
  p "                              F                      "
  p "                            // \\                    "
  p "                           B     G                   "
  p "                         // \\    \\                 "
  p "                         A   D     I                 "
  p "                           // \\ // \\               "
  p "                           C   E H   J               "
  p "--------------------  END NODE INSERTION -------------------- "

  print "\n"

  p "--------------------  BEGIN NODE DELETION (SUCCESSOR) -------------------- "
  tree_delete(tree, node_d)
  p "                              F                      "
  p "                            // \\                    "
  p "                           B     G                   "
  p "                         // \\    \\                 "
  p "                         A   E     I                 "
  p "                           //    // \\               "
  p "                           C     H   J               "
  p "--------------------  END NODE DELETION (SUCCESSOR) -------------------- "
  preoder_tree_walk(tree.root)

  print "\n"

  p "--------------------  BEGIN NODE DELETION (PREDECESSOR) -------------------- "
  tree_delete_predecessor(tree, node_b)
  p "                              F                      "
  p "                            // \\                    "
  p "                           A     G                   "
  p "                            \\    \\                 "
  p "                             E     I                 "
  p "                           //    // \\               "
  p "                           C     H   J               "
  p "--------------------  END NODE DELETION (PREDECESSOR) -------------------- "
  preoder_tree_walk(tree.root)
end

# Uncomment the lines below to run the minimal unit tests
unit_test_binary_tree
