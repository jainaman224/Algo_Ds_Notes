
#Doubly Linked-List using XOR implementation


A memory efficient Doubly Linked-List using XOR of address pointers ( previous pointer of the present node and next pointer of the previous node ) .

It saves one address pointer memory for every node i.e it has only one address pointer with every node whereas in a doubly linked list there are two pointers with every node for forward and previous traversal .
In this implementation we use only one address pointer for both forward and backward traversal .

#:-

npx = 0 XOR add(B) // bitwise XOR of zero and address of B

Node B:
npx = add(A) XOR add(C) // bitwise XOR of address of A and address of C

Node C:
npx = add(B) XOR add(D) // bitwise XOR of address of B and address of D

Node D:
npx = add(C) XOR 0 // bitwise XOR of address of C and 0
