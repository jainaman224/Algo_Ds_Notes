'''An integer x is said to be Noble given an array if the 
number of integers greater than x are equal to x. 
If there are many Noble integers, any of them is returned. 
If there is no noble integer, then return -1.'''

def Noble(A, n):
    if n == 0 : 
        return -1;

    A.sort();
    for i in range(n - 1) :
        if A[i] == A[i + 1] :
            continue;

        if A[i] == n - (i + 1) :
            return A[i];

    if A[n - 1] == 0 :
        return A[n - 1];

    return -1;

if __name__ == "__main__" :
    n = int(input("Enter the size of array : "))
    A = [int(x) for x in input().split(' ')]
    print("Noble Integer = ", Noble(A, n))

'''
Input :
Enter the size of array : 6
3 2 5 6 1 4
Output :
Noble Integer = 3

Input : 
Enter the size of array : 3
2 2 2
Output :
Noble Integer = -1
'''
