import math

def RMQ(seglist, segStart, segEnd, start, end, index):
    if start <= segStart and end >= segEnd:
        return seglist[index]

    if segEnd < start or segStart > end:
        return math.inf

    mid = segStart + (segEnd - segStart) // 2

    left = RMQ(seglist, segStart, mid, start, end, 2*index + 1)
    right = RMQ(seglist, mid + 1, segEnd, start, end, 2*index + 2)

    if left <= right:
        return left
    else:
        return right

def buildSegmentTree(list, start, end, seglist, index):
    if start == end:
        seglist[index] = list[start]
        return seglist[index]

    mid = start + (end - start) // 2
    left = buildSegmentTree(list, start, mid, seglist, index*2 + 1)
    right = buildSegmentTree(list, mid + 1, end, seglist, index*2 + 2)

    if left <= right:
        seglist[index] = left
    else:
        seglist[index] = right

    return seglist[index]

if __name__ == '__main__':
    list = [1, 3, 2, 7, 9, 11, 8, 4, 20, 15]
    size = len(list)

    height = math.ceil( math.log2(size) )
    segtree_size = int(2 * (math.pow(2, height) - 1))
    seglist = [0] * segtree_size

    buildSegmentTree(list, 0, size - 1, seglist, 0)

    start = 1
    end = 5

    print("Minimum value in index range " +  str(start) + " to " + str(end) + " is")
    print(RMQ(seglist, 0, size - 1, start, end, 0))


''' Output

Minimum value in index range 1 to 5 is
2

'''
