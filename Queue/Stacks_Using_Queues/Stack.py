class Queue:
    def __init__(self):
        self.data = collections.deque()
        
    def push(self, x):
        self.data.append(x)
    
    def peek(self):
        return self.data[0]
    
    def pop(self):
        return self.data.popleft()
    
    def size(self):
        return len(self.data)
    
    def empty(self):
        return len(self.data) == 0


class Stack:
    def __init__(self):
        self.q_ = Queue()

    def push(self, x):
        self.q_.push(x)
        for _ in xrange(self.q_.size() - 1):
            self.q_.push(self.q_.pop())

    def pop(self):
        self.q_.pop()

    def top(self):
        return self.q_.peek()

    def empty(self):
        return self.q_.empty()


class Stack2:
    def __init__(self):
        self.q_ = Queue()
        self.top_ = None

    def push(self, x):
        self.q_.push(x)
        self.top_ = x

    def pop(self):
        for _ in xrange(self.q_.size() - 1):
            self.top_ = self.q_.pop()
            self.q_.push(self.top_)
        self.q_.pop()

    def top(self):
        return self.top_

    def empty(self):
        return self.q_.empty()

s1 = Stack()
s2 = Stack2()

print(s1.empty())
print(s2.empty())
s1.push(1)
s2.push(2)
print(s1.top())
print(s2.top())
s1.pop()
s2.pop()
