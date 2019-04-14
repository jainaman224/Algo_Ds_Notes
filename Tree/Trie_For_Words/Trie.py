class node:
    def __init__(self):
        self.children = dict()

class trie:
    def __init__(self):
        self.root = node()

    def add_word(self, word):
        current = self.root
        for letter in word:
            if letter not in current.children:
                current.children[letter] = node()
            current = current.children[letter]
        return self

    def remove_word(self, word):
        current = self.root
        for letter in word:
            if letter in current.children and len(current.children)==1:
                del current.children[letter]
        return self

    def search(self, word):
        current = self.root
        for letter in word:
            if letter not in current.children:
                return False
            current = current.children[letter]
        return True

def main():
    t = trie()
    t.add_word('mississippi')
    t.add_word('miss')
    t.add_word('michigan')
    t.add_word('missouri')
    t.remove_word('missouri')
    assert t.search('mississippi')
    assert t.search('missi')
    assert not t.search('mint')
    assert not t.search('missouri')
    assert not t.search('mississippi!')
