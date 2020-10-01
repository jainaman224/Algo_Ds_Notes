#Travelling Salesman Problem

A traveler needs to visit all the cities from a list, where distances between all the cities are known and each city should be visited just once. 
The salesman's goal is to keep both the travel costs and the distance traveled as low as possible.

##Solution

Travelling salesman problem is the most notorious computational problem.
It's NP-hard and our best algorithms for this problem take exponential time. Therefore we use dynamic programming to solve this proble. 

Let us consider a graph G = (V, E), where V is a set of cities and E is a set of weighted edges. An edge e(u, v) represents that vertices u and v are connected. Distance between vertex u and v is d(u, v), which should be non-negative.

For a subset of cities S Є {1, 2, 3, ... , n} that includes 1, and j Є S, let C(S, j) be the length of the shortest path visiting each node in S exactly once, starting at 1 and ending at j.

When |S| > 1, we define C(S, 1) = ∝ since the path cannot start and end at 1.

Now, let express C(S, j) in terms of smaller sub-problems. We need to start at 1 and end at j. We should select the next city in such a way that

**C(S,j)=minC(S−{j},i)+d(i,j)wherei∈Sandi≠j**

**Algorithm:**

C ({1}, 1) = 0 
for s = 2 to n do 
   for all subsets S Є {1, 2, 3, … , n} of size s and containing 1 
      C (S, 1) = ∞ 
   for all j Є S and j ≠ 1 
      C (S, j) = min {C (S – {j}, i) + d(i, j) for i Є S and i ≠ j} 
Return minj C ({1, 2, 3, …, n}, j) + d(j, i) 

##Complexity

There are at the most 2^n.n sub-problems and each one takes linear time to solve. Therefore, the total running time is  O(2^n.n^2)


