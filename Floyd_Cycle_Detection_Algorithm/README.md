# Flyod's_Cycle_Detection

The name already give idea about the algorithm , It determines if a singly linked list is circular and if it is,  It is going to return the node where the cycle begins
It was invented by **Robert W. Floyd** in late 1960s.
The algorithm is also popularly known as **The Tortoise and the Hare (Floyd’s Algorithm)**

## Complexity

Time Complexity - O(N) , N :- Length of List <br/>
Space Complexity - O(1)



## Pseudo code

1. Initialize two pointers (tortoise and hare) that both point to the head of the linked list
2. Loop as long as the hare does not reach null
3. Set tortoise to next node
4. Set hare to next, next node
5. If they are at the same node, reset the tortoise back to the head.
6. Have both tortoise and hare both move one node at a time until they meet again
7. Return the node in which they meet
8. Else, if the hare reaches null, then return null

![Gif-hare-tortoise](https://miro.medium.com/max/780/1*clbAFjEFicLYjsq4pVVP4g.gif)


