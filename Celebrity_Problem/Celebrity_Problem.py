'''
CELEBRITY PROBLEM

In a group of N people, there is 1 person, who is known to everyone, but
he knows noone.
We need to find such a person, if present.

There will be a matrix input, such that M[i][j] = 1, if ith person
knows jth person, else 0.
'''

def Celebrity(Person, n):
    start = 0
    end = n - 1
    while(True):
        if (start == end):
            break
        if (Person[start][end] == 1):
            start = start + 1
        else:
            end = end - 1
    for i in range(0, n):
        if (i == start):
            continue
        if (Person[start][i] == 1 or Person[i][start] == 0):
            return -1
    return start

n = int(input())
Person = []
for i in range(0, n):
    temp = [int(x) for x in input().split()]
    Person.append(temp)
        
celeb = Celebrity(Person, n)
if (celeb >= 0):
    print("Celebrity Present at index", celeb)
else:
    print("Celebrity not present")

'''
INPUT : n = 5
Person = 0 1 0 0 1
         0 0 0 0 0
         1 1 1 0 0
         1 1 0 0 1
         0 1 1 1 0
OUTPUT :
Celebrity Present at index 1
'''
