'''
Quickhull Algorithm for Convex Hull

Given a set of points, a Convex hull is the smallest convex polygon containing 
all the given points.

Input is an array of points specified by their x and y coordinates.
Output is a convex hull of this set of points in ascending order of x coordinates.

'''

finallist = []


def distance(p1, p2, p):

    return abs(((p[1] - p1[1]) * (p2[0] - p1[0])) -
               ((p2[1] - p1[1]) * (p[0] - p1[0])))

def findside(p1, p2, p):

    val = int(((p2[0] - p1[0]) * (p[1] - p1[1])) -
              ((p2[1] - p1[1]) * (p[0] - p1[0])))

    if (val > 0):
        return 1

    if (val < 0):
        return -1

    return 0

def findhull(a, n, p1, p2, side):

    ind = -1
    max_dist = 0

    for i in range(0, n):
        temp = distance(p1, p2, a[i])

        if (findside(p1, p2, a[i]) == side and temp > max_dist):
            ind = i
            max_dist = temp

    if (ind == -1):
        finallist.append(p1)
        finallist.append(p2)
        return;

    findhull(a, n, a[ind], p1, -findside(a[ind], p1, p2))
    findhull(a, n, a[ind], p2, -findside(a[ind], p2, p1))

def printhull(a, n):

    if (n < 3):
        print("Convex hull not possible")
        return

    t1 = list2.index(max(list2))
    t2 = list2.index(min(list2))

    findhull(a, n, a[t2], a[t1], 1)
    findhull(a, n, a[t2], a[t1], -1)

    list3 = []

    for i in finallist:
        if i not in list3:
            list3.append(i)

    print("List of coordinates are: ")
    for i in list3:
        print(i)

if __name__ == "__main__":

    t = int(input("Enter the number of points "))
    list1 = []

    for i in range(0, t):
        x, y = [int(i) for i in input().split()]
        list1.append([x, y])

    list2 = []
    for i in list1:
        if i not in list2:
            list2.append(i)

    printhull(list2, t)

'''
Input : points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                    {0, 0}, {1, 2}, {3, 1}, {3, 3}};
Output :  The points on the Hull are:
          (0, 0) (0, 3) (3, 1) (4, 4)
'''

