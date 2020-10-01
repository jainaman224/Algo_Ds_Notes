from random import randint

# Theoretically based on system can be max upto 2**31.
# Keeping it low for readability
MAX_RANDOM_LIMIT = 100


class emptyNode():

    def __init__(self):
        self.priority = None
        self.key = None
        self.left = self.right = self.parent = None

    def __bool__(self):
        return False


NIL = emptyNode()


class treapNode:
    def __init__(self, key, priority=None, left=NIL, right=NIL, parent=NIL):

        self.key = key
        self.priority = priority
        self.left = left
        self.right = right
        self.parent = parent

        if priority is None:
            random_priority = randint(0, MAX_RANDOM_LIMIT)
            self.priority = random_priority

    def __str__(self):
        return '(k=' + str(self.key) + ':p=' + str(self.priority) + ')'

    def __repr__(self):
        return '(k=' + str(self.key) + ':p=' + str(self.priority) + ')'


class treap:
    def __init__(self):
        self.root = NIL

    def treap_insert(self, key, priority=None):
        # Perform regular binary tree insert

        inode = treapNode(key, priority)
        self.insert(self.root, inode)

        # Rebalance the treap using the priority values - min heap
        self.rebalance_priority(inode)

    # Regular Binary Tree Insert
    def insert(self, root, inode):

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
            print('Left node is NIL - Cannot rotate right')

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

    # Rebalance the treap based on min heap priority
    def rebalance_priority(self, node):

        if node.parent is NIL:
            return

        if node.parent != NIL and node.priority >= node.parent.priority:
            return

        if node == node.parent.left:
            self.rotate_right(node.parent)
        else:
            self.rotate_left(node.parent)

        self.rebalance_priority(node)

    def lookup(self, key):
        curr_node = self.root

        while curr_node != NIL and key != curr_node.key:
            if key < curr_node.key:
                curr_node = curr_node.left
            else:
                curr_node = curr_node.right

        if curr_node != NIL:
            return curr_node
        return None

    # To Delete - find node to delete, make it a leaf node and delete it
    def treap_delete(self, key):

        # Regular binary tree search
        dnode = self.lookup(key)

        # Make the node to be deleted a leaf node
        self.make_leafnode(dnode)

        if dnode == dnode.parent.left:
            dnode.parent.left = NIL
        else:
            dnode.parent.right = NIL

    # Making the node to be deleted a leaf node - min heap priority
    def make_leafnode(self, dnode):
        if dnode.left == NIL and dnode.right == NIL:
            return

        if dnode.left != NIL and dnode.right != NIL:

            if dnode.left.priority < dnode.right.priority:
                self.rotate_right(dnode)
            else:
                self.rotate_left(dnode)
        else:
            if dnode.left != NIL:
                self.rotate_right(dnode)
            else:
                self.rotate_left(dnode)

        self.make_leafnode(dnode)

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

        if node.right != NIL:
            self.pretty_print(node.right, level + 1)
            print(('\t' * level), ('    /'))

        print(('\t' * level), node.key, ':', node.priority)

        if node.left != NIL:
            print(('\t' * level), ('    \\'))
            self.pretty_print(node.left, level + 1)


if __name__ == "__main__":

    # Create treap with random priority
    tree_random = treap()

    tree_random.treap_insert(10)
    tree_random.treap_insert(6)
    tree_random.treap_insert(18)
    tree_random.treap_insert(4)
    tree_random.treap_insert(8)
    tree_random.treap_insert(15)
    tree_random.treap_insert(21)

    # The treap structure will be based based on both key and priority
    print('\n---- Treap with random priority ----\n')
    tree_random.pretty_print()

    print('\n')

    print('----------------------------')
    # Expected value 21
    print('Maximum value is ', tree_random.find_max_value())

    # Expected value 4
    print('Minimum value is ', tree_random.find_min_value())

    # Expected '2 not in treap'
    print('2 not in treap ') if not tree_random.lookup(
        2) else print('2 in treap')

    # Expected '15 in treap'
    print('15 not in treap ') if not tree_random.lookup(
        15) else print('15 in treap')

    print('Inorder traverse ', tree_random.inorder_traverse(tree_random.root))

    print('----------------------------\n')

    # Create treap using defined priority values
    tree = treap()
    data = [(7, 4), (2, 7), (8, 5), (11, 65), (1, 10), (5, 23), (9, 73)]
    for key, priority in data:
        tree.treap_insert(key, priority)

    # Root of treap is 7 : 4
    print('---- Treap Insertion and Rotation ----\n')
    print('---- Treap with root 7 : 4 ----\n')

    print('In order traverse ', tree.inorder_traverse(tree.root))

    print('\n')
    tree.pretty_print()

    # Rotations with insertions and change in root
    tree.treap_insert(3, 25)
    tree.treap_insert(4, 9)
    tree.treap_insert(6, 2)

    print('\n')
    print('After insertions and rotations  - Treap has 6 : 2 as root \n')
    tree.pretty_print()

    print('\nIn order traverse after insertions ',
          tree.inorder_traverse(tree.root))

    print('\n----------------------------')
    # Expected value 11
    print('Maximum value is ', tree.find_max_value())

    # Expected value 1
    print('Minimum value is ', tree.find_min_value())

    # Expected '99 not in treap'
    print('99 not in treap ') if not tree.lookup(99) else print('99 in treap')

    # Expected '7 in treap'
    print('7 not in treap ') if not tree.lookup(7) else print('7 in treap')
    print('----------------------------')

    # Create treap using defined priority values
    tree_del = treap()
    data_del = [(3, 1), (1, 6), (5, 11), (0, 9), (2, 99),
                (4, 14), (9, 17), (7, 22), (6, 42), (8, 49)]
    for key, priority in data_del:
        tree_del.treap_insert(key, priority)

    # Root of treap is 3 : 1
    print('\n---- Treap Deletion and Rotation ----\n')
    print('---- Treap with root 3 : 1 ----\n')

    print('In order traverse ', tree_del.inorder_traverse(tree_del.root))
    print('\n')
    tree_del.pretty_print()

    print('\n----------------------------')
    # Expected value 9
    print('Maximum value before deletion is ', tree_del.find_max_value())

    # Deletion of 9
    tree_del.treap_delete(9)

    print('\n')
    print('After deletion  \n')
    tree_del.pretty_print()

    print('\nIn order traverse after deletion ',
          tree_del.inorder_traverse(tree_del.root))

    print('\n----------------------------')
    # Expected value 8
    print('Maximum value after deletion is ', tree_del.find_max_value())

    # Expected value 0
    print('Minimum value is ', tree_del.find_min_value())

    # Expected '45 not in treap'
    print('45 not in treap ') if not tree_del.lookup(
        45) else print('45 in treap')

    # Expected '0 in treap'
    print('0 not in treap ') if not tree_del.lookup(0) else print('0 in treap')
    print('----------------------------')
