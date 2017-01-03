#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        unsigned int size = q.size();
        this->q.push(x);
        while (size--){
            q.push(q.front());
            q.pop();
            }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
       return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

    void printStack() {
        if (q.empty()) {
            cout << "stack is empty!\n";
            return;
        }
        queue<int> temp;
        temp = q;
        while (temp.size()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {
    Stack pop_efficient;

    pop_efficient.push(10);
    pop_efficient.push(20);
    pop_efficient.push(30);
    pop_efficient.push(40);
    pop_efficient.push(50);

    pop_efficient.pop();

    pop_efficient.push(60);
    pop_efficient.push(70);

    pop_efficient.pop();

    pop_efficient.push(80);
    pop_efficient.push(90);

    pop_efficient.printStack();

    return 0;
}
