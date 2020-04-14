# Ford-Fulkerson Algorithm

The Ford-Fulkerson algorithm is an algorithm that tackles the max-flow min-cut problem. That is, given a network with vertices and edges between those vertices that have certain weights, how much "flow" can the network process at a time? Flow can mean anything, but typically it means data through a computer network.

It was discovered in 1956 by Ford and Fulkerson. This algorithm is sometimes referred to as a method because parts of its protocol are not fully specified and can vary from implementation to implementation. An algorithm typically refers to a specific protocol for solving a problem, whereas a method is a more general approach to a problem.

The Ford-Fulkerson algorithm assumes that the input will be a graph, GG, along with a source vertex, ss, and a sink vertex, tt. The graph is any representation of a weighted graph where vertices are connected by edges of specified weights. There must also be a source vertex and sink vertex to understand the beginning and end of the flow network.

Ford-Fulkerson has a complexity of O\big(|E| \cdot f^{*}\big),O(∣E∣⋅f 
∗
 ), where f^{*}f 
∗
  is the maximum flow of the network. The Ford-Fulkerson algorithm was eventually improved upon by the Edmonds-Karp algorithm, which does the same thing in O\big(V^2 \cdot E\big)O(V 
2
 ⋅E) time, independent of the maximum flow value.

## ALGORITHM
Follow 3 basic steps:
1. Find augmented path
2. Complete the bottle neck capacity
3. Augment each edge and total flow
Repeat these steps until the augmented path is reached

### Example:
![step1](https://github.com/syedareehaquasar/hello-world/blob/master/e.PNG)
here only 2 spaces are there in DT so taking 2
![step2](https://github.com/syedareehaquasar/hello-world/blob/master/ee.PNG)
Similarly another path
![step3](https://github.com/syedareehaquasar/hello-world/blob/master/eee.PNG)
Similarly another path
![step5](https://github.com/syedareehaquasar/hello-world/blob/master/eeeee.PNG)
Similarly another path
![step6](https://github.com/syedareehaquasar/hello-world/blob/master/eeeeeeeeeee.PNG)
Here paths SA and CD are full but we require 2 in AC but place of only 1 in CD so we have reached our answer ->19
![final answer](https://github.com/syedareehaquasar/hello-world/blob/master/eeeeeeeeeeeeeee.PNG)

## PSEUDOCODE

The pseudo-code for this method is quite short; however, there are some functions that bear further discussion. The simple pseudo-code is below.
This pseudo-code is not written in any specific computer language. Instead, it is an informal, high-level description of the algorithm.

Ford-Fulkerson Algorithm ((Graph GG, source ss, sink t):t):
```
initialize flow to 0
path = findAugmentingPath(G, s, t)
while path exists:
    augment flow along path                 #This is purposefully ambiguous for now
    G_f = createResidualGraph()
    path = findAugmentingPath(G_f, s, t)
return flow
```

# Time Complexity
O(max_flow * E)
Time complexity of the above algorithm is O(max_flow * E). We run a loop while there is an augmenting path. In worst case, we may add 1 unit flow in every iteration. Therefore the time complexity becomes O(max_flow * E)
![tc](https://github.com/syedareehaquasar/hello-world/blob/master/h.PNG)

# Implementation

 - [c code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.c)
 - [coffee code]
 - [cpp code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford-Fulkerson.cpp)
 - [c# code]
 - [go code]
 - [java code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.java)
 - [javaScript code]
 - [kotlin code]
 - [python code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.py)
 - [ruby code]
 - [dart code]
