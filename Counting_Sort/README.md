# Counting Sort

[Counting Sort](https://en.wikipedia.org/wiki/Counting_sort) is one of those interesting Sorting methods that do not involve
comparisons.
When we talk about Comparision Based Sorting, we know one thing for sure that their time complexity is going to be
O(n*logn) at least.

> It should be used when the range of numbers is less than or comparable to size of list to be sorted.

Hence, the magic of counting sort lies in its linear time complexity O(n).

 Let us understand the algorithm with an example.

 1). Consider a simple array of integers which are associated with some items (say.. some colors).

   ![image](https://lh3.googleusercontent.com/-UOjPbN6P2Tw/V2w2jaLmMzI/AAAAAAAAU_o/HDCLJMWbn-A4zLFu_1OSnaJt4xN0PVUJgCCo/s437/input%2Barray.png)

   The maximum element is 7. We need a count array of size 8 (maximum element +1) which will store the number of times a value has appeared in the input array.

   ![image](https://lh3.googleusercontent.com/-esQ7hwWVmfM/V2w2hvQGHPI/AAAAAAAAU_g/DLwJ6zFbphUsb2TCLd6kgHlYQWKoftATQCCo/s458/count_initialisation.png)

   A Count array of size 8 is created and all of its elements are initialised to zero.

 2). Have a pass through the input array and increment the count in count array whenever associated value is encountered.

   ![image](https://lh3.googleusercontent.com/-HlwxGsBT5yU/V2w2f6YlBvI/AAAAAAAAU_Y/lB7SQSfMv3QOIoYutdM-fqLhd8_p2df6ACCo/s452/count.png)

 3). Now The count array will be modified to store the deserving positions of the INPUT values instead of their counts.

   The modification is done in following way:

   ![image](https://lh3.googleusercontent.com/-Nm22Ktsql5A/V2w2d0CDEeI/AAAAAAAAU_M/CeQ68a8AoZ0ZNVmGC_AGGER4QOqtri76gCCo/s450/position.png)

 4). The output array will have the size same as input array. Using position array, we can easily find the sorted output array.

   The position array along with the values associated is :

   ![image](https://lh3.googleusercontent.com/-FQIzOuPH_VI/V2w2bcZQe-I/AAAAAAAAVAA/jWJ9uXNSX50V16NI1anbGinB8UjpR55IgCCo/s460/positionvalues.png)

   And Input array is:

   ![image](https://lh3.googleusercontent.com/-UOjPbN6P2Tw/V2w2jaLmMzI/AAAAAAAAU_o/HDCLJMWbn-A4zLFu_1OSnaJt4xN0PVUJgCCo/s437/input%2Barray.png)

   Now have a pass through the input array from right to left and put each element along with its color in its position in output array using position array and simultaneously decrement its position value by one in position array before moving to the next element.

   The first element in input array from right is 5 and its associated position in position array is 8. Hence, place 5 at 8th position in output array and simultaneously decrement the position value by one in position array. Now, value 5 will be described by position 7 in position array.

   After passing through the whole Input Array, the output array will be:

   ![image](https://lh3.googleusercontent.com/-U67cnzyJV-M/V2w2Y5Nt0QI/AAAAAAAAVAA/vk1J2kPNFU8rYoar9mKBjuCOZYWvqhgLgCCo/s500/output_array.png)

## Complexity

Space Complexity: O(n+k)

Counting Sort has linear time complexity.

Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.

1. When we actually started the algorithm, we had to look on our input array to set our count array size. So, the Complexity of this step is O(n).

2. The complexity to create and intialize the count array of size k is O(k).

3. First counting pass through the input array to estimate the count of appearance of each value will require O(n) time.

4. While moving on from Count array to position array, An additional O(K) time is required.

5. Populating the output array using position array will take O(n) time.


Hence, The Time complexity of this algorithm is O(n+k).

Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10000 and the data is 10, 5, 10000, 5000.

### Counting Sort is a Stable sort

The Counting sort is a stable sort i.e., multiple keys with the same value are placed in the sorted array in the same order that they appear in the input array.

Let us understand this with the example shown above.

 In Input array, 4 and 5 both appeared twice but they have different colors associated with them. In input array, red 5 appeared earlier than the black 5
 and in output array also, The position of red 5 is before than the position of black 5.

 Same is the case with the two fours (four with orange color appeared first in order than the four with black color).In Output array also, their appearance is same as the input array.

This explains the stability of counting sort.


Submitted by : [Ayushi Negi](https://github.com/ayushin78)

## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Counting_Sort/Counting_Sort.c)
> :rocket: [Compile Online](https://repl.it/EKfI/2) :rocket:

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Counting_Sort/Counting_Sort.cpp)
> :rocket: [Compile Online](https://repl.it/C6jK) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Counting_Sort/Counting_Sort.java)
> :rocket: [Compile Online](https://repl.it/C6jF) :rocket:

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Counting_Sort/Counting_Sort.py)
> :rocket: [Compile Online](https://repl.it/C6jJ) :rocket:
