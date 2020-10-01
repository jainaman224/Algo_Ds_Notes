# Bucket Sort

Bucket Sort is a sorting algorithm, that works by distributing the elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm.

Some characteristics of Bucket Sort include:

- Bucket sort assumes that the input is drawn from a uniform distribution.
- The computational complexity estimates involve the number of buckets.
- Bucket sort can be exceptionally fast because of the way elements are assigned to buckets, typically using an array where the index is the value.
- This means that more auxiliary memory is required for the buckets at the cost of running time than more comparison sorts.

## Algorithm

1. Create an empty array.
2. Loop through the original array and put each object in a “bucket”.
3. Sort each of the non-empty buckets.
4. Check the buckets in order and then put all objects back into the original array.

## Pseudocode

```
BucketSort(A)
n = A.length
Let B[0, . . . , n − 1] be a new array
for i = 0 to n - 1
B[i] ← 0
for i = 1 to n
B[bnA[i]c] ← A[i]
for i = 0 to n-1
sort list B[i] using insertion sort
concatenate the lists B[0], B[1], . . . , B[n − 1]
return B
```

## Example

Below given is an array, which needs to be sorted. We will use the Bucket Sort Algorithm to sort this array:

![Bucket_Sort_1](https://cdn-images-1.medium.com/max/800/1*QfuAg0ouokVxdvNUg3EfdQ.png)

Bucket sort moves elements to buckets, then sorts the buckets.

![Bucket_Sort_2](https://cdn-images-1.medium.com/max/800/1*HUGqf7zYmYKK798ziTEGRg.png)

## Complexity

The average **time complexity** for Bucket Sort is O(n + k). The worst time complexity is O(n²).

The **space complexity** for Bucket Sort is O(n+k).