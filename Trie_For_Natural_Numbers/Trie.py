class node:
    def __init__(self):
        self.children = dict()

class trie:
    def __init__(self):
        self.root = node()

    def add_word(self, word):
        current = self.root
        for letter in _listify(word):
            if letter not in current.children:
                current.children[letter] = node()
            current = current.children[letter]
        return self

    def remove_word(self, word):
        current = self.root
        for letter in _listify(word):
            if letter in current.children and len(current.children)==1:
                del current.children[letter]
        return self

    def search(self, word):
        current = self.root
        for letter in _listify(word):
            if letter not in current.children:
                return False
            current = current.children[letter]
        return True

    def _listify(self, word):
        assert type(word) is int and word > 0
        return map(int, list(str(word)))

def main():
    t = trie()
    t.add_word(123)
    t.add_word(1234)
    t.add_word(1211111111)
    t.add_word(1243)
    t.remove_word(1243)
    assert t.search(123)
    assert t.search(1211111)
    assert not t.search(2)
    assert not t.search(1243)
    assert not t.search(12345)
