#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
// 1) One by one dequeue everything except the last element from q1 and enqueue to q2.
//   2) Dequeue the last item of q1, the dequeued item is result, store it.
//   3) Swap the names of q1 and q2
//   4) Return the item stored in step 2.
// Swapping of names is done to avoid one more movement of all elements
// from q2 to q1.
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!";
            return INT_MIN;
        }
        int last;
        if (q1.size() != 1) {
            int size = q1.size();
            for (int i = 0; i < size-1; i++) {
                q2.push(q1.front());
                q1.pop();
            }
            last = q1.front();
            q1.pop();
            swap(q1, q2);
        }
        return last;
    }

    // Get the top element.
    int top() {
       return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }

    void printStack() {
        if (q1.empty()) {
            cout << "stack is empty!\n";
            return;
        }
        queue<int> temp;
        temp = q1;
        while (temp.size()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {
    Stack push_efficient;
    push_efficient.push(10);
    push_efficient.push(20);
    push_efficient.push(30);
    push_efficient.push(40);
    push_efficient.push(50);
    push_efficient.pop();
    push_efficient.push(60);
    push_efficient.push(70);
    push_efficient.pop();
    push_efficient.push(80);
    push_efficient.printStack();
    return 0;
}
