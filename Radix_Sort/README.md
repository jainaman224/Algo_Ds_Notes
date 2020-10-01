# RADIX SORT

**Radix Sort** is an efficient non-comparison based sorting algorithm which can sort a dataset in linear **O(N)** time complexity & hence, can be better than other competitive algorithm like ``Quick Sort``.

It uses another algorithm namely ``Counting Sort`` as a subroutine.

Radix sort was developed to **sort large integers**. It considers integer as a string of digits so we can use Radix Sort to sort strings as well.   

# Algorithm
      1. Do following for each digit i where i varies from least significant digit to most significant digit.
              Sort input array using Counting Sort (or any stable sort) according to the i'th digit.

# Example 1
Assume the input array is:
`[326, 453, 608, 835, 751, 435, 704, 690]`

Based on the algorithm , we will sort the input array according to **one's digit**(least significant digit).

The original array is sorted based on `[6, 3, 8, 5, 1, 5, 4, 0]` using **Counting Sort**.

So, the array becomes `[690, 751, 453, 704, 835, 435, 326, 608]`.

Now, we'll sort according to **ten's place** :

The above partially sorted array is sorted based on `[9, 5, 5, 0, 3, 3, 2, 0]` using counting sort .

Now array becomes : `[704, 608, 326, 835, 435, 751, 453, 690]`

Finally, we sort according to **hundred's place**(most significant digit) :

the above partially sorted array is sorted based on `[7, 6, 3, 8, 4, 7, 4, 6]` using Counting Sort

The array becomes : `[326, 435, 453, 608, 690, 704, 751, 835]` which is now sorted .

# Example 2
![Radix Sort Process example 2](https://gfycat.com/questionablehauntingflatfish.gif)

# Example 3
![Radix sort Process example 3](https://www.cs.usfca.edu/~galles/visualization/RadixSort.html)

# Complexity Analysis
Best case time complexity : `Ω(nk)`

Average case time complexity : `Θ(nk)`

Worst case time complexity : `O(nk)`

Space complexity : `O(n + k)`

where **n** = number of input data ,
      **k** = maximum element in input data.

Let there be `d` digits in input integers. Radix sort takes `O(d(n+b))` time where **b** is the base for representing numbers, for example for decimal system b is 10. What is the value of d ? If K is maximum possible value , then d would be **O(logb(k))**. So, overall time complexity is `O((n + b) * logb(k))` . which looks more than the time complexity of comparison based sorting algorithm for large K.

Let use first limit K. Let **k <= nc** where c is constant . In that case, complexity becomes **O(nlogb(n))**. But it still doesn't beat comparison based sorting algorithms. What if we make value of b larger ? . what should be the value of b to make time complexity linear ? If we set b as n, we get the time complexity as **O(n)**. In other words , we can sort an array of integers with range from 1 to nc if the numbers are represented in base n (or every digit takes log2(n) bits ).

# Advantages
1. Fast when the keys are short i.e. when the range of the array elements is less.
2. Used in suffix array construction algorithms like Manber's algorithm & DC3 algorithm.
3. Radix sort is stable sort as relative order of elements with equal values is maintained .

# Disadvantages
1. Since Radix Sort depends on digits or letters, Radix Sort is much less flexible than other sorts . Hence, for every different type of data it needs to be rewritten.
2. The constant for Radix sort is greater compared to other sorting algorithms .
3. It takes more space compared to Quick Sort which is inplace Sorting .
4. It can be slower than other sorting algorithms like merge or quick sort , if the operations are not efficient enough. These operations include insert & delete functions of the sub-list & the process of isolating the digits we want.
