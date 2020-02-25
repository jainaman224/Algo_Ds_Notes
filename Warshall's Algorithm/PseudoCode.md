ALGORITHM  
Waershall(A[1..n, 1...n])
//Implements Warshall’s Algorithm for computing the transitive closure
//Input: The adjancency matrix A of a diagraph with n vertices
//Output: The transitive closure of the diagraph
 n = no of vertices
A = matrix of dimension n*n
for k = 1 to n
    for i = 1 to n
        for j = 1 to n
            A(k)[i, j] = min (A(k-1)[i, j], A(k-1)[i, k] + A(k-1)[k, j])
return A

Time efficiency: (n3)
Space efficiency: Matrices can be written over their predecessors
