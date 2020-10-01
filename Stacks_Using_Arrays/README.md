# Stacks Using Array
A Stack is an ADT (abstract data type) that serves as a collection of elements, with two principal operations:

* push, which adds an element to the collection, and

* pop, which removes the most recently added element that was not yet removed

## Algorithm

Push :

* Checks if the stack is full.
* If the stack is full, produces an error and exit.
* If the stack is not full, increments top to point next empty space.
* Adds data element to the stack location, where top is pointing.

Pop :

* Checks if the stack is empty.
* If the stack is empty, produces an error and exit.
* If the stack is not empty, accesses the data element at which top is pointing.
* Decreases the value of top by 1.

## Pseudocodes

Structure of Stack
```
structure stack:
    maxsize : integer
    top : integer
    items : array of item
```

Push Operation
```
push( stk, x):
    if stk.top = stk.maxsize:
        report overflow error
    else:
        stk.items[stk.top] ← x
        stk.top ← stk.top + 1
```

Pop Operation
```
pop(stk):
    if stk.top = 0:
        report underflow error
    else:
        stk.top ← stk.top − 1
        r ← stk.items[stk.top]
```

## Complexity
**Time complexity**

* Push : O(1)
* Pop : O(1)

**Space complexity** : O(n)

## Implementation
* [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Arrays/Stacks.cpp)

	> :rocket: [Compile Online](https://repl.it/EC29/0) :rocket:

* [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Arrays/Stacks.java)

	> :rocket: [Compile Online](https://repl.it/EC27/0) :rocket:

* [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Arrays/Stacks.py)

	> :rocket: [Compile Online](https://repl.it/EC21/0) :rocket:
