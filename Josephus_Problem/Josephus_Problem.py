#Josephus Problem 

#Total number of people=N
#Number of people to be skipped=k

N=int(input("\nEnter the total number of people:"))
k=int(input("\nEnter the number of people to be skipped:"))

#Recursive Problem with time complexity O(n)
def josephus(n,m):
    if(n==1):
        return 0
    else:
        n1=int(n)-1
        return  (josephus(n1,m)+m)%n       

print("\nThe solution of the Problem is:",josephus(N,k)+1)
