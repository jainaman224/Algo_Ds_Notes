"""Each node can be colored RED or BLACK."""

RED = "RED"
BLACK = "BLACK"


class emptyNode():
    def __init__(self):
        self.color = BLACK
        self.key = None
        self.left = self.right = self.parent = None

    def __bool__(self):
        return False


NIL = emptyNode()


class rbnode():

    def __init__(self, key, color=RED, left=NIL, right=NIL, parent=NIL):
        self.color = color
        self.key = key
        self.left = left
        self.right = right
        self.parent = parent

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)


class rbtree():
    def __init__(self):
        self.root = NIL

    def rb_insert(self, key):
        inode = rbnode(key)
        self.insert(inode)

    def insert(self, inode):

        curr_node = NIL

        root = self.root
        while root:
            curr_node = root
            if inode.key < root.key:
                root = root.left
            else:
                root = root.right

        inode.parent = curr_node
        if not curr_node:
            self.root = inode
        else:
            if inode.key < curr_node.key:
                curr_node.left = inode
            else:
                curr_node.right = inode

        # balance the red and black flags in the tree
        self.fixflags(inode)

    def fixflags(self, node):

        node.color = RED
        while node != self.root and node.parent.color == RED:

            if node.parent == node.parent.parent.left:
                aunt = node.parent.parent.right
                if aunt and aunt.color == RED:
                    # Color flip
                    node.parent.color = BLACK
                    aunt.color = BLACK
                    node.parent.parent.color = RED
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        # Rotate Left - pivot is parent
                        node = node.parent
                        self.rotate_left(node)
                    # Rotate Right - pivot is grandparent
                    node.parent.color = BLACK
                    node.parent.parent.color = RED
                    self.rotate_right(node.parent.parent)
            else:
                aunt = node.parent.parent.left
                if aunt and aunt.color == RED:
                    # Color flip
                    node.parent.color = BLACK
                    aunt.color = BLACK
                    node.parent.parent.color = RED
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        # Rotate Right - pivot is parent
                        node = node.parent
                        self.rotate_right(node)
                    # Rotate Left - pivot is grandparent
                    node.parent.color = BLACK
                    node.parent.parent.color = RED
                    self.rotate_left(node.parent.parent)

        self.root.color = BLACK

    def rotate_left(self, node):

        if not node.right:
            print('Right node is NIL - Cannot rotate left')

        old_root = node
        new_root = old_root.right
        new_right_to_old_root = new_root.left
        old_root.right = new_right_to_old_root

        if new_root.left != NIL:
            new_root.left.parent = old_root
        new_root.parent = old_root.parent

        # Tree will get a new root
        if old_root.parent == NIL:
            self.root = new_root

        # Parent's left will point to new root
        elif old_root == old_root.parent.left:
            old_root.parent.left = new_root

        # Parent's right will point to new root
        else:
            old_root.parent.right = new_root

        new_root.left = old_root
        old_root.parent = new_root

    def rotate_right(self, node):

        if not node.left:
            print('Left node is NIL - Cannot rotate left')

        old_root = node
        new_root = old_root.left
        new_left_to_old_root = new_root.right
        old_root.left = new_left_to_old_root

        if new_root.right != NIL:
            new_root.right.parent = old_root
        new_root.parent = old_root.parent

        # Tree will get a new root
        if old_root.parent == NIL:
            self.root = new_root

        # Parent's right will point to new root
        elif old_root == old_root.parent.right:
            old_root.parent.right = new_root

        # Parent's left will point to new root
        else:
            old_root.parent.left = new_root

        new_root.right = old_root
        old_root.parent = new_root

    def lookup(self, key):
        curr_node = self.root

        while curr_node != NIL and key != curr_node.key:
            if key < curr_node.key:
                curr_node = curr_node.left
            else:
                curr_node = curr_node.right

        if curr_node != NIL:
            return curr_node.key == key
        return False

    def inorder_traverse(self, root):
        """
        Left tree nodes , root , right tree nodes 
        """

        if not root:
            return []

        curr_node = root

        result = []

        if curr_node:
            if curr_node.left != NIL:
                left_nodes = self.inorder_traverse(curr_node.left)
                for lnode in left_nodes:
                    result.append(lnode)

            result.append(curr_node.key)
            if curr_node.right != NIL:
                right_nodes = self.inorder_traverse(curr_node.right)
                for rnode in right_nodes:
                    result.append(rnode)

        return result

    def find_min_value(self):

        if self.root != NIL and self.root.left != NIL:
            root = self.root.left

            while root.left != NIL:
                root = root.left
            return root.key

    def find_max_value(self):

        if self.root != NIL and self.root.right != NIL:
            root = self.root.right

            while root.right != NIL:
                root = root.right
            return root.key

    def pretty_print(self, node=None, level=0):

        if not node:
            node = self.root
            # print('pretty print node ', node)

        if node.right != NIL:
            self.pretty_print(node.right, level + 1)
            print(('\t' * level), ('    /'))

        print(('\t' * level), node.key, node.color)

        if node.left != NIL:
            print(('\t' * level), ('    \\'))
            self.pretty_print(node.left, level + 1)


if __name__ == "__main__":

    tree = rbtree()

    data = [11, 2, 14, 1, 7, 5, 8, 15]
    for key in data:
        tree.rb_insert(key)

    print('\n')

    tree.pretty_print()

    print('\n')

    # Expected value 15
    print('Maximum value is ', tree.find_max_value())

    # Expected value 1
    print('Minimum value is ', tree.find_min_value())

    print('\n')
    # Expected to be true
    print('Red Black tree contains 7 ?', tree.lookup(7))
    print('Red Black tree contains 8 ?', tree.lookup(8))

    # Expected to be false
    print('Red Black tree contains 30 ?', tree.lookup(30))
    print('Red Black tree contains 97 ?', tree.lookup(97))

    print('\n')

    tree.rb_insert(4)

    print('Inorder traverse ', tree.inorder_traverse(tree.root))

    print('\n')
    tree.pretty_print()
