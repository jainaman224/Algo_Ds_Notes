# Stack Using Linked List
A stack is a linear data structure which is based on the principle that _the elements in a stack are added and removed only from one end_, which is called the **TOP**. Hence, a stack is called a **LIFO (Last-In-First-Out)** data structure, as the element that was inserted last is the first one to be taken out.
Stack supports two basic operations:  **push and pop.**

## Algorithm
### Push
A push operation is used to insert an element into the stack. The new element is added at the topmost position of the stack.

- Create a  **NEW_NODE**  with given value.
- Check whether stack is  **EMPTY**  (**TOP**  ==  **NULL**)
- If it is  **EMPTY**, then set  **NEW_NODE → NEXT**  =  **NULL**.
- If it is  **NOT  EMPTY**, then set  **NEW_NODE → NEXT**  =  **TOP**.
- Finally, set  **TOP**  =  **NEW_NODE**.

### Pop
The pop operation is used to delete the topmost element from the stack and returns the deleted element. But before deleting element we must check if **TOP=NULL**, because if this is the case, then it means that the stack is empty and no more deletions can be done and stack is **Underflow**.

- Check whether  **STACK**  is  **EMPTY**  (**TOP == NULL**).
- If it is  **EMPTY**, then display  **"Stack Underflow !**  and terminate the function
- If it is  **NOT EMPTY**, then define a  **NODE**  pointer '**TEMP**' and set it to '**TOP**'.
- Then set '**TOP**  =  **TOP → NEXT**'.
- Finally, delete '**TEMP**'. (**FREE(TEMP)**)

##  Pseudocodes
Structure of Stack
```c
typedef struct node
{
  int data;
  struct node *next;
}node;
```
Push Operation
```
Step 1: Allocate memory for the new node and name it as NEW_NODE
Step 2: SET NEW_NODE-->DATA = VAL
Step 3: IF TOP == NULL
            SET NEW_NODE--> NEXT = NULL
            SET TOP = NEW_NODE
        ELSE
            SET NEW_NODE-->NEXT = TOP
            SET TOP = NEW_NODE
        [END OF IF]
Step 4: END
```
Pop Operation
```
Step 1: IF TOP == NULL
            PRINT "UNDERFLOW !!"
            Goto Step 5
        [END OF IF]
Step 2: SET TEMP = TOP
Step 3: SET TOP = TOP-->NEXT
Step 4: FREE TEMP
Step 5: END
```

## Complexity
**Time Complexity:**

-   Push : O(1)
-   Pop : O(1)

**Space Complexity**  : O(n)
## Implementation
* [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Linked_Lists/Stacks.cpp)

	> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Stacks-Using-Linked-Lists) :rocket:

* [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Linked_Lists/Stacks.java)

	> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Stacks-Using-Linked-Lists-Java) :rocket:

* [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Stacks_Using_Linked_Lists/Stacks.py)

	> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Stacks-Using-Linked-Lists-Python) :rocket:
