Chocolate distribution problem states that -

There exist M chocolate packets each packet can have variable number of chocolates. There are N students. 
Chocolate packets should be distributed  such that:
a: Each student gets 1 packet
b: Difference between number of chocolates in packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.

Solution

One efficient solution is based on the observation that, to minimize the difference, we must choose consecutive elements from  sorted packets. We first sort the array a[0..n-1], then find the subarray of size m with  the minimum difference between last and first elements.
