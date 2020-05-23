# AhoNode class
class AhoNode:
    def __init__(self):
        self.goto = {}
        self.out = []
        self.fail = None


# creating aho forest
def aho_create_forest(patterns):
    root = AhoNode()

    for path in patterns:
        node = root
        for symbol in path:
            node = node.goto.setdefault(symbol, AhoNode())
        node.out.append(path)
    return root


# Creating aho automata
def aho_create_statemachine(patterns):
    root = aho_create_forest(patterns)
    queue = []
    for node in root.goto.values():
        queue.append(node)
        node.fail = root

    while len(queue) > 0:
        rnode = queue.pop(0)

        for key, unode in rnode.goto.items():
            queue.append(unode)
            fnode = rnode.fail
            while fnode is not None and key not in fnode.goto:
                fnode = fnode.fail
            unode.fail = fnode.goto[key] if fnode else root
            unode.out += unode.fail.out

    return root


def aho_find_all(s, root, callback):
    node = root

    for i in range(len(s)):
        while node is not None and s[i] not in node.goto:
            node = node.fail
        if node is None:
            node = root
            continue
        node = node.goto[s[i]]
        for pattern in node.out:
            callback(i - len(pattern) + 1, pattern)


# Printing the position of pattern found
def print_pattern(pos, patterns):
    print("At pos %s found pattern: %s" % (pos, patterns))


if __name__ == "__main__":
    patterns = []

    # taking inputs
    n = int(input("Enter no. of elements :- "))
    for i in range(0, n):
        ele = input("Enter element :- ")
        patterns.append(ele)
    s = input("Enter text :- ")

    root = aho_create_statemachine(patterns)
    aho_find_all(s, root, print_pattern)

 
"""
INPUT:
n=6
patterns = ['a', 'ab', 'abc', 'bc', 'c', 'cba']
s = "abcba"

OUTPUT:
At pos 0 found pattern: a
At pos 0 found pattern: ab
At pos 0 found pattern: abc
At pos 1 found pattern: bc
At pos 2 found pattern: c
At pos 2 found pattern: cba
"""