class BTree:
    def __init__(self, data=None, parent=None):
        self.key = data
        self.children = []
        self.parent = parent
 
    def set_root(self, data):
        self.key = data
 
    def add(self, node):
        self.children.append(node)
 
    def search(self, key):
        if self.key == key:
            return self
        for child in self.children:
            temp = child.search(key)
            if temp is not None:
                return temp
        return None
 
    def remove(self):
        parent = self.parent
        index = parent.children.index(self)
        parent.children.remove(self)
        for child in reversed(self.children):
            parent.children.insert(index, child)
            child.parent = parent
 
    def bfs_display(self):
        queue = [self]
        while queue != []:
            popped = queue.pop(0)
            for child in popped.children:
                queue.append(child)
            print(popped.key, end=' ')
 
def main(): 
    tree = None
    
    print('Templates for commands are as follows:(this assumes no duplicate keys)')
    print('To add data at root enter:- add <data> at root')
    print('To add data below another data enter:- add <data> below <data>')
    print('To remove/delete data enter:- remove <data>')
    print('To display the Btree enter:- display')
    print('To end the process enter:- quit')
    
    while True:
        do = input('What would you like to do? ').split()
    
        operation = do[0].strip().lower()
        if operation == 'add':
            data = int(do[1])
            new_node = BTree(data)
            suboperation = do[2].strip().lower() 
            if suboperation == 'at':
                tree = new_node
            elif suboperation == 'below':
                position = do[3].strip().lower()
                key = int(position)
                ref_node = None
                if tree is not None:
                    ref_node = tree.search(key)
                if ref_node is None:
                    print('No such key.')
                    continue
                new_node.parent = ref_node
                ref_node.add(new_node)
    
        elif operation == 'remove':
            data = int(do[1])
            to_remove = tree.search(data)
            if tree == to_remove:
                if tree.children == []:
                    tree = None
                else:
                    leaf = tree.children[0]
                    while leaf.children != []:
                        leaf = leaf.children[0]
                    leaf.parent.children.remove(leaf)
                    leaf.parent = None
                    leaf.children = tree.children
                    tree = leaf
            else:
                to_remove.remove()
    
        elif operation == 'display':
            if tree is not None:
                print('BFS traversal display: ', end='')
                tree.bfs_display()
                print()
            else:
                print('Tree is empty.')
    
        elif operation == 'quit':
            break


main()
