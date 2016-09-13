import math

def RMQ(segArray, segStart, segEnd, start, end, index):
    if start <= segStart and end >= segEnd:
        return segArray[index]

    if segEnd < start or segStart > end:
        return math.inf

    mid = segStart + (segEnd - segStart) // 2

    left = RMQ(segArray, segStart, mid, start, end, 2*index + 1)
    right = RMQ(segArray, mid + 1, segEnd, start, end, 2*index + 2)

    if left <= right:
        return left
    else:
        return right

def buildSegmentTree(array, start, end, segArray, index):
    if start == end:
        segArray[index] = array[start]
        return segArray[index]

    mid = start + (end - start) // 2
    left = buildSegmentTree(array, start, mid, segArray, index*2 + 1)
    right = buildSegmentTree(array, mid + 1, end, segArray, index*2 + 2)

    if left <= right:
        segArray[index] = left
    else:
        segArray[index] = right

    return segArray[index]

if __name__ == '__main__':
    array = [1, 3, 2, 7, 9, 11, 8, 4, 20, 15]
    size = len(array)

    height = math.ceil( math.log2(size) )
    segtree_size = int(2 * (math.pow(2, height) - 1))
    segArray = [0] * segtree_size

    buildSegmentTree(array, 0, size - 1, segArray, 0)

    start = 1
    end = 5

    print("Minimum value in index range " +  str(start) + " to " + str(end) + " is")
    print(RMQ(segArray, 0, size - 1, start, end, 0))


''' Output

Minimum value in index range 1 to 5 is
2

'''
