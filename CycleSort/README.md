#Cycle Sort

Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array.

1. It is optimal in terms of number of memory writes. It minimizes the number of memory writes to sort (Each value is either written zero times, if it’s already in its correct position, or written one time to its correct position.)

2. It is based on the idea that array to be sorted can be divided into cycles. Cycles can be visualized as a graph. We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array.

##Algorithm

An element a is given, index of a can be calculated by counting the number of elements that 
are smaller than a.

1. If the element is found to be at its correct position, simply leave it as it is.

2. Otherwise, find the correct position of a by counting the total number of elements that are 
less than a. where it must be present in the sorted array. The other element b which is replaced is 
to be moved to its correct position. This process continues until we got an element at the 
original position of a.

##Complexity

Best and Average case time complexity: O(n^2)

##Applications

This sorting algorithm is best suited for situations where memory write or swap operations are costly.